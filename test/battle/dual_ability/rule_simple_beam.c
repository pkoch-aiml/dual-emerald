#include "global.h"
#include "test/battle.h"

// Design doc: Simple Beam and Worry Seed affect the learned ability if the target already has Simple
// (or Insomnia) as its natural ability, and the natural ability otherwise. User's ruling: they also
// affect the learned slot when the natural ability is a signature ability. They fail on an empty
// learned slot, as they do on single-ability Pokémon.

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
    ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
}

SINGLE_BATTLE_TEST("Simple Beam overwrites the natural ability and leaves the learned one alone")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_SIMPLE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Simple Beam and Worry Seed overwrite the learned ability if the natural ability already matches")
{
    enum Move move;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_SIMPLE_BEAM; ability = ABILITY_SIMPLE; }
    PARAMETRIZE { move = MOVE_WORRY_SEED;  ability = ABILITY_INSOMNIA; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ABILITY_POPUP(opponent, ABILITY_SPEED_BOOST); // the overwritten learned ability
        NOT ABILITY_POPUP(opponent, ABILITY_SPEED_BOOST); // no Speed Boost at the end of the turn
    } THEN {
        EXPECT_EQ(opponent->ability, ability);
        EXPECT_EQ(opponent->learnedAbility, ability);
    }
}

SINGLE_BATTLE_TEST("Simple Beam doesn't fill an empty learned slot")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; ability = ABILITY_SIMPLE; }
    PARAMETRIZE { species = SPECIES_MIMIKYU;   ability = ABILITY_DISGUISE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->learnedAbility, ABILITY_NONE);
    }
}

SINGLE_BATTLE_TEST("Simple Beam fails if both slots already hold Simple")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SIMPLE); LearnedAbility(ABILITY_SIMPLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Simple Beam overwrites the learned ability when the natural ability is a signature ability")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_DISGUISE].cantBeOverwritten);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); LearnedAbility(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_DISGUISE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_SIMPLE);
    }
}

SINGLE_BATTLE_TEST("Simple Beam fails on a signature natural ability with a signature or Simple learned ability")
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { learned = ABILITY_SIMPLE; }

    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_STANCE_CHANGE].cantBeOverwritten);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->learnedAbility, learned);
    }
}

SINGLE_BATTLE_TEST("Overwriting a learned Neutralizing Gas ends the gas")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_SIMPLE); LearnedAbility(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SIMPLE_BEAM, player);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_SIMPLE);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_SIMPLE);
    }
}
