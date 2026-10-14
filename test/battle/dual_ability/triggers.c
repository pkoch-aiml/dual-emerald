#include "global.h"
#include "test/battle.h"

// Dual Emerald: abilities that activate (switch-in, contact, end of turn, ...) fire from either slot,
// natural slot first.

SINGLE_BATTLE_TEST("Learned Intimidate activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_SHED_SKIN); LearnedAbility(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Attack fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Natural Drizzle and learned Intimidate both activate on switch-in, natural first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PELIPPER) { Ability(ABILITY_DRIZZLE); LearnedAbility(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DRIZZLE);
        MESSAGE("It started to rain!");
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        MESSAGE("Wobbuffet's Attack fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT(gBattleWeather & B_WEATHER_RAIN);
    }
}

SINGLE_BATTLE_TEST("Both switch-in abilities activate at the start of battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PELIPPER) { Ability(ABILITY_DRIZZLE); LearnedAbility(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DRIZZLE);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Learned Neutralizing Gas activates on switch-in and suppresses the foe")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_LEVITATE); LearnedAbility(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
    } THEN {
        EXPECT_EQ(GetBattlerAbility(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)), ABILITY_NONE);
    }
}
