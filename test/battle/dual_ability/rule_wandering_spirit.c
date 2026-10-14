#include "global.h"
#include "test/battle.h"

// Design doc: Wandering Spirit always exchanges the same ability slot as the foe, and fails if that
// slot is empty.

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_TACKLE));
}

SINGLE_BATTLE_TEST("Natural Wandering Spirit swaps natural abilities only")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_WANDERING_SPIRIT); LearnedAbility(ABILITY_LIMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet swapped Abilities with its target!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_WANDERING_SPIRIT);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
        EXPECT_EQ(opponent->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_LIMBER);
    }
}

SINGLE_BATTLE_TEST("Learned Wandering Spirit swaps learned abilities only")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet swapped Abilities with its target!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, ABILITY_WANDERING_SPIRIT);
        EXPECT_EQ(opponent->ability, ABILITY_LIMBER);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Learned Wandering Spirit fails if the attacker's learned slot is empty")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet swapped Abilities with its target!");
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_NONE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_WANDERING_SPIRIT);
    }
}

SINGLE_BATTLE_TEST("Learned Wandering Spirit fails if the attacker's learned ability can't be swapped")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_WONDER_GUARD].cantBeSwapped);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet swapped Abilities with its target!");
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_WONDER_GUARD);
    }
}
