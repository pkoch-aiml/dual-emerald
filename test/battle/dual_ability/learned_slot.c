#include "global.h"
#include "test/battle.h"

// Dual Emerald: the learned ability slot is copied into battle and kept up to date.

SINGLE_BATTLE_TEST("Battlers have no learned ability by default")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_NONE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_NONE);
    }
}

SINGLE_BATTLE_TEST("Battlers start the battle with their learned ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET) { LearnedAbility(ABILITY_STANCE_CHANGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_SHADOW_TAG);
        EXPECT_EQ(player->learnedAbility, ABILITY_INTIMIDATE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_STANCE_CHANGE);
    }
}

SINGLE_BATTLE_TEST("Battlers keep their learned ability after switching out and back in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { LearnedAbility(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WYNAUT) { LearnedAbility(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
        EXPECT_EQ(player->learnedAbility, ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Switching in sets the incoming battler's learned ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { LearnedAbility(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WYNAUT) { LearnedAbility(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->learnedAbility, ABILITY_DAMP);
    }
}

SINGLE_BATTLE_TEST("Mega Evolution replaces the learned ability with the Mega form's fixed learned ability")
{
    GIVEN {
        ASSUME(GetSpeciesFixedLearnedAbility(SPECIES_VENUSAUR_MEGA) != ABILITY_NONE);
        ASSUME(GetSpeciesFixedLearnedAbility(SPECIES_VENUSAUR_MEGA) != ABILITY_INTIMIDATE);
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR_MEGA);
        EXPECT_EQ(player->learnedAbility, GetSpeciesFixedLearnedAbility(SPECIES_VENUSAUR_MEGA));
        // The stored learned ability is untouched and returns after battle.
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_LEARNED_ABILITY), ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Primal Reversion replaces the learned ability with the Primal form's fixed learned ability")
{
    GIVEN {
        ASSUME(GetSpeciesFixedLearnedAbility(SPECIES_KYOGRE_PRIMAL) != ABILITY_NONE);
        PLAYER(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KYOGRE_PRIMAL);
        EXPECT_EQ(player->learnedAbility, GetSpeciesFixedLearnedAbility(SPECIES_KYOGRE_PRIMAL));
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_LEARNED_ABILITY), ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Other battle form changes keep the stored learned ability")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_SHIELD) { LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_AEGISLASH_BLADE);
        EXPECT_EQ(player->learnedAbility, ABILITY_INTIMIDATE);
    }
}
