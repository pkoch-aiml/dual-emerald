#include "global.h"
#include "malloc.h"
#include "daycare.h"
#include "egg_hatch.h"
#include "event_data.h"
#include "item.h"
#include "item_use.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "script_menu.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/characters.h"
#include "constants/form_change_types.h"

// Dual Emerald: tests for the learned ability slot in BoxPokemon.

TEST("Learned ability round-trips through every 9-bit value")
{
    u32 i, learnedAbility = 0;
    struct Pokemon mon;
    for (i = 0; i < (1 << 9); i++)
        PARAMETRIZE { learnedAbility = i; }
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &learnedAbility);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), learnedAbility);
}

TEST("Learned ability does not disturb neighboring BoxPokemon fields")
{
    u32 learnedAbility = 0;
    PARAMETRIZE { learnedAbility = ABILITY_NONE; }
    PARAMETRIZE { learnedAbility = ABILITIES_COUNT - 1; }
    PARAMETRIZE { learnedAbility = (1 << 9) - 1; }

    struct Pokemon mon;
    enum Item heldItem = ITEMS_COUNT - 1;
    u32 experience = gExperienceTables[gSpeciesInfo[SPECIES_WOBBUFFET].growthRate][MAX_LEVEL];
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 nicknameOut[POKEMON_NAME_LENGTH + 1];
    u32 i;
    for (i = 0; i < POKEMON_NAME_LENGTH; i++)
        nickname[i] = CHAR_A + i;
    nickname[POKEMON_NAME_LENGTH] = EOS;

    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_HELD_ITEM, &heldItem);
    SetMonData(&mon, MON_DATA_EXP, &experience);
    SetMonData(&mon, MON_DATA_NICKNAME, nickname);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &learnedAbility);

    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), learnedAbility);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), heldItem);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_EXP), experience);
    GetMonData(&mon, MON_DATA_NICKNAME, nicknameOut);
    for (i = 0; i < POKEMON_NAME_LENGTH; i++)
        EXPECT_EQ(nicknameOut[i], nickname[i]);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
}

TEST("Newly created Pokémon have no learned ability")
{
    struct Pokemon mon;
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), ABILITY_NONE);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 100, abilityNum=2;
        givemon SPECIES_WYNAUT, 5, isEgg=TRUE;
        createmon 1, 0, SPECIES_WOBBUFFET, 100;
    );
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
}

TEST("BoxPokemon saved before the learned ability slot existed load with no learned ability")
{
    // Same vanilla-layout data as "BoxPokemon encryption works" in test/pokemon.c.
    u32 raw[20] =
    {
        990384375, 2948624514, 3907508686, 14410461, 35316705,
        3907508686, 64742109, 718729, 3102307966, 2160206402,
        49956971, 2495766612, 1424318580, 273408756, 2371630199,
        2708871082, 3059937332, 2529190026, 2290634828, 2870614922
    };
    struct Pokemon mon;
    BoxMonToMon((struct BoxPokemon *)&raw, &mon);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPECIES), SPECIES_TORCHIC);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
}

TEST("Learned ability survives being stored in and withdrawn from the PC")
{
    struct Pokemon mon, withdrawn;
    enum Ability learnedAbility = ABILITY_INTIMIDATE;
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &learnedAbility);

    SetBoxMonAt(0, 0, &mon.box);
    EXPECT_EQ(GetBoxMonDataAt(0, 0, MON_DATA_LEARNED_ABILITY), learnedAbility);
    BoxMonAtToMon(0, 0, &withdrawn);
    EXPECT_EQ(GetMonData(&withdrawn, MON_DATA_LEARNED_ABILITY), learnedAbility);
}

TEST("Learned ability is unchanged by evolution")
{
    struct Pokemon mon;
    enum Ability learnedAbility = ABILITY_INTIMIDATE;
    enum Species evolvedSpecies = SPECIES_WOBBUFFET;
    CreateMon(&mon, SPECIES_WYNAUT, 15, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &learnedAbility);

    // Evolution only changes the species and recalculates stats.
    SetMonData(&mon, MON_DATA_SPECIES, &evolvedSpecies);
    CalculateMonStats(&mon);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), learnedAbility);
}

TEST("(Daycare) Eggs hatch with no learned ability even if both parents have one")
{
    enum Ability learnedAbility = ABILITY_INTIMIDATE;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 100, gender=MON_MALE;
        givemon SPECIES_WOBBUFFET, 100, gender=MON_FEMALE;
    );
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEARNED_ABILITY, &learnedAbility);
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_LEARNED_ABILITY, &learnedAbility);

    // Same as STORE_IN_DAYCARE_AND_GET_EGG in test/daycare.c.
    StorePokemonInDaycare(&gParties[B_TRAINER_PLAYER][0], &gSaveBlock1Ptr->daycare.mons[0]);
    StorePokemonInDaycare(&gParties[B_TRAINER_PLAYER][0], &gSaveBlock1Ptr->daycare.mons[1]);
    EXPECT_EQ(GetBoxMonData(&gSaveBlock1Ptr->daycare.mons[0].mon, MON_DATA_LEARNED_ABILITY), learnedAbility);
    EXPECT_EQ(GetBoxMonData(&gSaveBlock1Ptr->daycare.mons[1].mon, MON_DATA_LEARNED_ABILITY), learnedAbility);
    RUN_OVERWORLD_SCRIPT( special GiveEggFromDaycare; );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_IS_EGG), TRUE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);

    gSpecialVar_0x8004 = 0;
    ScriptHatchMon();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_IS_EGG), FALSE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
}

static bool32 LearnableAbilityListsEqual(const u16 *a, const u16 *b)
{
    u32 i;
    for (i = 0; a[i] != ABILITY_NONE || b[i] != ABILITY_NONE; i++)
    {
        if (a[i] != b[i])
            return FALSE;
    }
    return TRUE;
}

TEST("Every species has a valid learnable ability list")
{
    enum Species species = SPECIES_NONE;
    for (enum Species i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    const u16 *learnableAbilities = gSpeciesInfo[species].learnableAbilities;
    u32 i, j;
    EXPECT(learnableAbilities != NULL);
    EXPECT_NE(learnableAbilities[0], ABILITY_NONE);
    for (i = 0; learnableAbilities[i] != ABILITY_NONE; i++)
    {
        EXPECT_LT(i, DE_MAX_LEARNABLE_ABILITIES);
        EXPECT_LT(learnableAbilities[i], ABILITIES_COUNT);
        EXPECT(!gAbilitiesInfo[learnableAbilities[i]].cantBeSwapped);
        for (j = 0; j < i; j++)
            EXPECT_NE(learnableAbilities[i], learnableAbilities[j]);
    }
}

TEST("Evolutions' learnable ability lists start with their pre-evolution's list")
{
    enum Species species = SPECIES_NONE;
    for (enum Species i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i) && GetSpeciesEvolutions(i) != NULL)
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    const struct Evolution *evolutions = GetSpeciesEvolutions(species);
    const u16 *preEvoList = GetSpeciesLearnableAbilities(species);
    for (u32 i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        enum Species target = evolutions[i].targetSpecies;
        if (!IsSpeciesEnabled(target))
            continue;
        const u16 *evoList = GetSpeciesLearnableAbilities(target);
        for (u32 j = 0; preEvoList[j] != ABILITY_NONE; j++)
            EXPECT_EQ(evoList[j], preEvoList[j]);
    }
}

TEST("Species linked by a form change share the same learnable ability list")
{
    enum Species species = SPECIES_NONE;
    for (enum Species i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i) && gSpeciesInfo[i].formChangeTable != NULL)
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    const struct FormChange *formChangeTable = gSpeciesInfo[species].formChangeTable;
    for (u32 i = 0; formChangeTable[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        enum Species target = formChangeTable[i].targetSpecies;
        if (target == SPECIES_NONE || !IsSpeciesEnabled(target))
            continue;
        EXPECT(LearnableAbilityListsEqual(GetSpeciesLearnableAbilities(species), GetSpeciesLearnableAbilities(target)));
    }
}

TEST("Exactly the Mega and Primal forms have a fixed learned ability")
{
    enum Species species = SPECIES_NONE;
    for (enum Species i = 1; i < NUM_SPECIES; i++)
    {
        if (IsSpeciesEnabled(i))
            PARAMETRIZE_LABEL("ID:%d - %S", i, GetSpeciesName(i)) { species = i; }
    }

    enum Ability fixedLearnedAbility = GetSpeciesFixedLearnedAbility(species);
    if (gSpeciesInfo[species].isMegaEvolution || gSpeciesInfo[species].isPrimalReversion)
    {
        EXPECT_NE(fixedLearnedAbility, ABILITY_NONE);
        EXPECT_LT(fixedLearnedAbility, ABILITIES_COUNT);
    }
    else
    {
        EXPECT_EQ(fixedLearnedAbility, ABILITY_NONE);
    }
}

TEST("Mew is compatible with all AMs")
{
    EXPECT(SpeciesLearnsAllAMs(SPECIES_MEW));
    EXPECT(!SpeciesLearnsAllAMs(SPECIES_MEWTWO));
}

void DebugNative_PushLearnedAbilityChoices(void);
void DebugNative_SetLearnedAbility(void);

TEST("Debug: Set Learned Ability offers None plus the species' learnable abilities")
{
    const u16 *learnableAbilities = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    u32 i, count = 0;
    while (learnableAbilities[count] != ABILITY_NONE)
        count++;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_WOBBUFFET, 100;);
    gSpecialVar_0x8004 = 0;
    DebugNative_PushLearnedAbilityChoices();

    EXPECT_EQ(MultichoiceDynamic_StackSize(), count + 1);
    EXPECT_EQ(MultichoiceDynamic_PeekElementAt(0)->id, 0);
    for (i = 0; i < count; i++)
        EXPECT_EQ(MultichoiceDynamic_PeekElementAt(i + 1)->id, i + 1);

    while (!MultichoiceDynamic_StackEmpty())
        Free((void *)MultichoiceDynamic_PopElement()->name);
    MultichoiceDynamic_DestroyStack();
}

TEST("Debug: Set Learned Ability sets the chosen ability, or clears it for None")
{
    const u16 *learnableAbilities = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_WOBBUFFET, 100; givemon SPECIES_WOBBUFFET, 100;);
    gSpecialVar_0x8004 = 1;

    gSpecialVar_Result = 1;
    DebugNative_SetLearnedAbility();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_LEARNED_ABILITY), learnableAbilities[0]);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);

    gSpecialVar_Result = 0;
    DebugNative_SetLearnedAbility();
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_LEARNED_ABILITY), ABILITY_NONE);
}

// Dual Emerald: ability memory (Milestone 4).

TEST("Ability memory round-trips every 8-bit value without disturbing neighboring fields")
{
    u32 i, memory = 0;
    struct Pokemon mon;
    enum Move move3 = MOVES_COUNT - 1, move4 = MOVES_COUNT - 2;
    bool32 hyperTrained = TRUE;
    for (i = 0; i < (1 << 8); i++)
        PARAMETRIZE { memory = i; }
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_MOVE3, &move3);
    SetMonData(&mon, MON_DATA_MOVE4, &move4);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_HP, &hyperTrained);
    SetMonData(&mon, MON_DATA_ABILITY_MEMORY, &memory);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), memory);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_MOVE3), move3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_MOVE4), move4);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HYPER_TRAINED_HP), hyperTrained);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
}

TEST("Newly created Pokémon have an empty ability memory")
{
    struct Pokemon mon;
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), 0);
}

TEST("Setting a learnable ability as the learned ability records it in the ability memory")
{
    struct Pokemon mon;
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    u32 none = ABILITY_NONE, first, second;
    ASSUME(learnable[0] != ABILITY_NONE && learnable[1] != ABILITY_NONE);
    first = learnable[0];
    second = learnable[1];

    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &second);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), 1u << 1);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &first);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), (1u << 0) | (1u << 1));
    // Clearing the learned ability doesn't forget anything.
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &none);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), (1u << 0) | (1u << 1));
}

TEST("An ability not on the species' learnable list isn't recorded in the ability memory")
{
    struct Pokemon mon;
    u32 illegal = ABILITY_STANCE_CHANGE;
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    for (u32 i = 0; learnable[i] != ABILITY_NONE; i++)
        ASSUME(learnable[i] != ABILITY_STANCE_CHANGE);

    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &illegal);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_LEARNED_ABILITY), ABILITY_STANCE_CHANGE);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), 0);
}

TEST("Ability memory survives evolution and PC storage")
{
    struct Pokemon mon, withdrawn;
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WYNAUT);
    u32 ability;
    enum Species evolvedSpecies = SPECIES_WOBBUFFET;
    ASSUME(learnable[0] != ABILITY_NONE);
    ability = learnable[0];

    CreateMon(&mon, SPECIES_WYNAUT, 15, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &ability);
    SetMonData(&mon, MON_DATA_SPECIES, &evolvedSpecies);
    CalculateMonStats(&mon);
    // Right-superset rule: entry 0 of the pre-evolution's list is entry 0 of the evolution's list.
    EXPECT_EQ(GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET)[0], ability);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ABILITY_MEMORY), 1u << 0);

    SetBoxMonAt(0, 0, &mon.box);
    BoxMonAtToMon(0, 0, &withdrawn);
    EXPECT_EQ(GetMonData(&withdrawn, MON_DATA_ABILITY_MEMORY), 1u << 0);
}

// Dual Emerald: Ability Machines and teaching (Milestone 4).

TEST("Every AM is a reusable TM-pocket item that teaches a distinct ability")
{
    for (enum Item item = ITEM_AM01; item <= ITEM_AM_LAST; item++)
    {
        enum Ability ability = GetItemAMAbility(item);
        EXPECT(IsItemAM(item));
        EXPECT_NE(ability, ABILITY_NONE);
        EXPECT(!gAbilitiesInfo[ability].cantBeDoubled);
        EXPECT_EQ(GetItemPocket(item), POCKET_TM_HM);
        EXPECT_EQ(GetItemImportance(item), 1);
        EXPECT_EQ(CheckIfItemIsTMHMOrEvolutionStone(item), ITEM_IS_AM);
        for (enum Item other = ITEM_AM01; other < item; other++)
            EXPECT_NE(GetItemAMAbility(other), ability);
    }
    EXPECT(!IsItemAM(ITEM_TM01));
    EXPECT_EQ(GetItemAMAbility(ITEM_TM01), ABILITY_NONE);
}

TEST("The TM/HM pocket has room for every TM, HM and AM")
{
    EXPECT_GE(BAG_TMHM_COUNT, NUM_ALL_MACHINES + NUM_ABILITY_MACHINES);
}

TEST("CanMonLearnAbility accepts abilities on the species' list and rejects others")
{
    struct Pokemon mon;
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    EXPECT_EQ(CanMonLearnAbility(&mon, learnable[0]), ABILITY_LEARN_OK);
    EXPECT_EQ(CanMonLearnAbility(&mon, ABILITY_STANCE_CHANGE), ABILITY_LEARN_INCOMPATIBLE);
    EXPECT_EQ(CanMonLearnAbility(&mon, ABILITY_NONE), ABILITY_LEARN_INCOMPATIBLE);
}

TEST("CanMonLearnAbility rejects the current learned ability and eggs")
{
    struct Pokemon mon;
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    u32 ability = learnable[0];
    bool32 isEgg = TRUE;
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &ability);
    EXPECT_EQ(CanMonLearnAbility(&mon, ability), ABILITY_LEARN_ALREADY_LEARNED);
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);
    EXPECT_EQ(CanMonLearnAbility(&mon, ability), ABILITY_LEARN_EGG);
}

TEST("CanMonLearnAbility blocks learning a cantBeDoubled ability that is already the natural ability")
{
    struct Pokemon mon;
    u32 abilityNum = 0;

    CreateMon(&mon, SPECIES_AEGISLASH_SHIELD, 50, 0, OTID_STRUCT_PLAYER_ID);
    ASSUME(GetMonAbility(&mon) == ABILITY_STANCE_CHANGE);
    ASSUME(gAbilitiesInfo[ABILITY_STANCE_CHANGE].cantBeDoubled);
    EXPECT_EQ(CanMonLearnAbility(&mon, ABILITY_STANCE_CHANGE), ABILITY_LEARN_CANT_BE_DOUBLED);

    // Only flagged abilities are blocked: an unflagged AM ability is learnable (Mew learns every AM).
    CreateMon(&mon, SPECIES_MEW, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    ASSUME(!gAbilitiesInfo[ABILITY_INTIMIDATE].cantBeDoubled);
    EXPECT_EQ(CanMonLearnAbility(&mon, ABILITY_INTIMIDATE), ABILITY_LEARN_OK);
}

TEST("A learnsAllAMs species can learn every AM ability and remembers its whole list plus every AM")
{
    struct Pokemon mon;
    u16 remembered[MAX_REMEMBERED_ABILITIES];
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_MEW);
    u32 count, i, j;
    CreateMon(&mon, SPECIES_MEW, 100, 0, OTID_STRUCT_PLAYER_ID);

    count = GetMonRememberedAbilities(&mon.box, remembered);
    for (i = 0; learnable[i] != ABILITY_NONE; i++)
    {
        bool32 found = FALSE;
        for (j = 0; j < count; j++)
            found |= (remembered[j] == learnable[i]);
        EXPECT(found);
    }
    for (i = 0; i < NUM_ABILITY_MACHINES; i++)
    {
        bool32 found = FALSE;
        EXPECT(CanSpeciesLearnAbility(SPECIES_MEW, gAbilityMachineAbilities[i]));
        for (j = 0; j < count; j++)
            found |= (remembered[j] == gAbilityMachineAbilities[i]);
        EXPECT(found);
    }
}

TEST("Remembered abilities come from the ability memory; cross-trainable ones add the natural ability")
{
    struct Pokemon mon;
    u16 abilities[MAX_CROSS_TRAINABLE_ABILITIES];
    const u16 *learnable = GetSpeciesLearnableAbilities(SPECIES_WOBBUFFET);
    u32 learned, abilityNum = 0;
    ASSUME(learnable[1] != ABILITY_NONE);
    learned = learnable[1];

    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    EXPECT_EQ(GetMonRememberedAbilities(&mon.box, abilities), 0);

    SetMonData(&mon, MON_DATA_LEARNED_ABILITY, &learned);
    EXPECT_EQ(GetMonRememberedAbilities(&mon.box, abilities), 1);
    EXPECT_EQ(abilities[0], learned);

    EXPECT_EQ(GetMonCrossTrainableAbilities(&mon.box, abilities), 2);
    EXPECT_EQ(abilities[0], learned);
    EXPECT_EQ(abilities[1], GetMonAbility(&mon));
}

TEST("Changing the natural ability changes the cross-trainable set")
{
    struct Pokemon mon;
    u16 abilities[MAX_CROSS_TRAINABLE_ABILITIES];
    u32 abilityNum;
    ASSUME(GetSpeciesAbility(SPECIES_WOBBUFFET, 0) != GetSpeciesAbility(SPECIES_WOBBUFFET, 2));
    ASSUME(GetSpeciesAbility(SPECIES_WOBBUFFET, 2) != ABILITY_NONE);
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, OTID_STRUCT_PLAYER_ID);

    abilityNum = 0;
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    EXPECT_EQ(GetMonCrossTrainableAbilities(&mon.box, abilities), 1);
    EXPECT_EQ(abilities[0], GetSpeciesAbility(SPECIES_WOBBUFFET, 0));

    abilityNum = 2; // like an Ability Patch
    SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    EXPECT_EQ(GetMonCrossTrainableAbilities(&mon.box, abilities), 1);
    EXPECT_EQ(abilities[0], GetSpeciesAbility(SPECIES_WOBBUFFET, 2));
}
