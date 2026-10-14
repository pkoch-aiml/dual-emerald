#include "global.h"
#include "test/battle.h"

// Design doc: as a natural ability, Trace copies a random foe's natural ability. As a learned ability,
// it copies a random ability of a random foe; user's ruling: picked uniformly from every non-empty,
// traceable ability in any foe's slots. The copy goes into the Trace holder's own slot.

SINGLE_BATTLE_TEST("Natural Trace copies the foe's natural ability into the natural slot")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); LearnedAbility(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Wobbuffet's Speed Boost!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_SPEED_BOOST);
        EXPECT_EQ(player->learnedAbility, ABILITY_LIMBER);
    }
}

SINGLE_BATTLE_TEST("Learned Trace copies into the learned slot and can copy a foe's learned ability")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_TRACE].cantBeTraced);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_TRACE); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); LearnedAbility(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Ralts's Shed Skin!");
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_LIMBER);
        EXPECT_EQ(player->learnedAbility, ABILITY_SHED_SKIN);
    }
}

SINGLE_BATTLE_TEST("Learned Trace picks evenly among the foe's abilities")
{
    PASSES_RANDOMLY(1, 2, RNG_TRACE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_TRACE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); LearnedAbility(ABILITY_SHED_SKIN); }
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_SHED_SKIN);
    }
}

DOUBLE_BATTLE_TEST("Learned Trace picks evenly among all foes' abilities")
{
    PASSES_RANDOMLY(1, 3, RNG_TRACE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_TRACE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); LearnedAbility(ABILITY_SHED_SKIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_STURDY); }
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(playerLeft->learnedAbility, ABILITY_STURDY);
    }
}

SINGLE_BATTLE_TEST("Natural and learned Trace both activate, each into its own slot")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); LearnedAbility(ABILITY_TRACE); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        ABILITY_POPUP(player, ABILITY_TRACE);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_SPEED_BOOST);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Learned Trace doesn't activate if the foe has nothing traceable")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_TRACE].cantBeTraced);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_TRACE); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->learnedAbility, ABILITY_TRACE);
    }
}
