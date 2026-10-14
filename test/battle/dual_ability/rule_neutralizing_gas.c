#include "global.h"
#include "test/battle.h"

// Design doc: Neutralizing Gas affects all ability slots, works from either slot, and suppresses its
// holder's other slot. Held twice, or by two battlers, it doesn't do anything extra.

SINGLE_BATTLE_TEST("Natural Neutralizing Gas suppresses both of the foe's slots")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_DROUGHT); LearnedAbility(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_DROUGHT);
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        }
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas suppresses its holder's other slot")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas held in both slots ends when its holder leaves")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); LearnedAbility(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
    }
}

DOUBLE_BATTLE_TEST("Neutralizing Gas persists while a second holder remains, whichever slot it's in")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        NONE_OF {
            MESSAGE("The effects of the neutralizing gas wore off!");
            ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        }
    }
}
