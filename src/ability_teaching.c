#include "global.h"
#include "event_data.h"
#include "list_menu.h"
#include "malloc.h"
#include "party_menu.h"
#include "pokemon.h"
#include "script_menu.h"
#include "string_util.h"
#include "constants/abilities.h"

// Dual Emerald: script natives for teaching learned abilities by cross-training, from tutors and from
// the relearner. The teaching itself goes through ChooseMonForAbilityTutor (party_menu.c).

static void PushAbilityChoices(const u16 *abilities, u32 count)
{
    // Choice IDs are list indices plus one: ability IDs could collide with MULTI_B_PRESSED.
    for (u32 i = 0; i < count; i++)
    {
        struct ListMenuItem item;
        u8 *name = Alloc(ABILITY_NAME_LENGTH + 1);
        StringCopy(name, gAbilitiesInfo[abilities[i]].name);
        item.name = name;
        item.id = i + 1;
        MultichoiceDynamic_PushElement(item);
    }
}

static u32 GetCrossTrainableAbilitiesOfChosenMon(u16 *abilities)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    if (gSpecialVar_0x8004 >= PARTY_SIZE || GetMonData(mon, MON_DATA_IS_EGG))
        return 0;
    return GetMonCrossTrainableAbilities(&mon->box, abilities);
}

static u32 GetRememberedAbilitiesOfChosenMon(u16 *abilities)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    if (gSpecialVar_0x8004 >= PARTY_SIZE || GetMonData(mon, MON_DATA_IS_EGG))
        return 0;
    return GetMonRememberedAbilities(&mon->box, abilities);
}

// Cross-training. VAR_0x8004 is the source party slot. Pushes the abilities it can pass on (its
// remembered learned abilities and its current natural ability) and sets VAR_RESULT to how many.
void Native_PushCrossTrainableAbilities(void)
{
    u16 abilities[MAX_CROSS_TRAINABLE_ABILITIES];
    u32 count = GetCrossTrainableAbilitiesOfChosenMon(abilities);
    PushAbilityChoices(abilities, count);
    gSpecialVar_Result = count;
}

// After the choice: sets VAR_0x8005 to the chosen ability and buffers its name in STR_VAR_1.
void Native_SetChosenCrossTrainAbility(void)
{
    u16 abilities[MAX_CROSS_TRAINABLE_ABILITIES];
    u32 count = GetCrossTrainableAbilitiesOfChosenMon(abilities);
    gSpecialVar_0x8005 = (gSpecialVar_Result >= 1 && gSpecialVar_Result <= count) ? abilities[gSpecialVar_Result - 1] : ABILITY_NONE;
    StringCopy(gStringVar1, gAbilitiesInfo[gSpecialVar_0x8005].name);
}

// Relearner. VAR_0x8004 is the party slot. Pushes the learned abilities it remembers, sets VAR_RESULT
// to how many, and buffers the mon's nickname in STR_VAR_2.
void Native_PushRememberedAbilities(void)
{
    u16 abilities[MAX_REMEMBERED_ABILITIES];
    u32 count = GetRememberedAbilitiesOfChosenMon(abilities);
    if (gSpecialVar_0x8004 < PARTY_SIZE)
        GetMonNickname(&gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004], gStringVar2);
    PushAbilityChoices(abilities, count);
    gSpecialVar_Result = count;
}

// After the choice: sets VAR_0x8005 to the chosen ability and buffers its name in STR_VAR_1.
void Native_SetChosenRememberedAbility(void)
{
    u16 abilities[MAX_REMEMBERED_ABILITIES];
    u32 count = GetRememberedAbilitiesOfChosenMon(abilities);
    gSpecialVar_0x8005 = (gSpecialVar_Result >= 1 && gSpecialVar_Result <= count) ? abilities[gSpecialVar_Result - 1] : ABILITY_NONE;
    StringCopy(gStringVar1, gAbilitiesInfo[gSpecialVar_0x8005].name);
}

// Relearner: makes VAR_0x8005 the learned ability of the mon in VAR_0x8004. VAR_RESULT is 0 if it did,
// 1 if the mon already has the ability, and 2 if it can't learn it.
void Native_RelearnChosenAbility(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    u32 ability = gSpecialVar_0x8005;

    GetMonNickname(mon, gStringVar2);
    switch (CanMonLearnAbility(mon, ability))
    {
    case ABILITY_LEARN_OK:
        SetMonData(mon, MON_DATA_LEARNED_ABILITY, &ability);
        gSpecialVar_Result = 0;
        break;
    case ABILITY_LEARN_ALREADY_LEARNED:
    case ABILITY_LEARN_CANT_BE_DOUBLED:
        gSpecialVar_Result = 1;
        break;
    default:
        gSpecialVar_Result = 2;
        break;
    }
}
