#include "global.h"
#include "daycare.h"
#include "egg_hatch.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
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
