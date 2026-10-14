#include "global.h"
#include "test/battle.h"

// Design doc: Lingering Aroma and Mummy always affect the foe's same ability slot. User's ruling: in
// the learned slot, they fill an attacker's empty learned slot.

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_TACKLE));
}

SINGLE_BATTLE_TEST("Natural Mummy replaces only the attacker's natural ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_MUMMY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MUMMY);
        MESSAGE("Wobbuffet acquired Mummy!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_MUMMY);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Learned Mummy and Lingering Aroma replace only the attacker's learned ability")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MUMMY; }
    PARAMETRIZE { ability = ABILITY_LINGERING_AROMA; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_MUMMY)
            MESSAGE("Wobbuffet acquired Mummy!");
        else
            MESSAGE("Wobbuffet acquired Lingering Aroma!");
        NOT ABILITY_POPUP(player, ABILITY_SPEED_BOOST); // no Speed Boost at the end of the turn
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, ability);
    }
}

SINGLE_BATTLE_TEST("Learned Mummy fills an attacker's empty learned slot")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_MUMMY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MUMMY);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, ABILITY_MUMMY);
    }
}

SINGLE_BATTLE_TEST("Learned Mummy doesn't affect an attacker whose learned slot already has Mummy or a signature ability")
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_MUMMY; }
    PARAMETRIZE { learned = ABILITY_STANCE_CHANGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_MUMMY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ABILITY_MUMMY);
    } THEN {
        EXPECT_EQ(player->learnedAbility, learned);
    }
}

SINGLE_BATTLE_TEST("A learned ability replaced by Mummy returns after switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_MUMMY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Natural and learned Mummy each replace the attacker's matching slot")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_MUMMY); LearnedAbility(ABILITY_LINGERING_AROMA); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MUMMY);
        MESSAGE("Wobbuffet acquired Mummy!");
        ABILITY_POPUP(opponent, ABILITY_LINGERING_AROMA);
        MESSAGE("Wobbuffet acquired Lingering Aroma!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_MUMMY);
        EXPECT_EQ(player->learnedAbility, ABILITY_LINGERING_AROMA);
    }
}
