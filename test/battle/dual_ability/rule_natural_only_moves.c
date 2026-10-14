#include "global.h"
#include "test/battle.h"

// Design doc: Doodle, Entrainment, Role Play and Skill Swap always affect natural abilities only.

SINGLE_BATTLE_TEST("Skill Swap swaps natural abilities and leaves learned abilities alone")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); LearnedAbility(ABILITY_LIMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_BLAZE);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
        EXPECT_EQ(opponent->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_LIMBER);
    }
}

SINGLE_BATTLE_TEST("Skill Swap ignores learned abilities: a swappable natural ability is swapped even if the learned one isn't")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(gAbilitiesInfo[ABILITY_WONDER_GUARD].cantBeSwapped);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); LearnedAbility(ABILITY_WONDER_GUARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKILL_SWAP); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_BLAZE);
        EXPECT_EQ(opponent->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_WONDER_GUARD);
    }
}

SINGLE_BATTLE_TEST("Role Play copies the target's natural ability into the user's natural slot only")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ROLE_PLAY) == EFFECT_ROLE_PLAY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); LearnedAbility(ABILITY_LIMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROLE_PLAY); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_BLAZE);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_LIMBER);
    }
}

SINGLE_BATTLE_TEST("Entrainment gives the user's natural ability to the target's natural slot only")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); LearnedAbility(ABILITY_LIMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENTRAINMENT); }
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_LIMBER);
    }
}

DOUBLE_BATTLE_TEST("Doodle copies the target's natural ability into the natural slots of the user and ally only")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DOODLE) == EFFECT_DOODLE);
        PLAYER(SPECIES_WYNAUT) { LearnedAbility(ABILITY_SPEED_BOOST); }
        PLAYER(SPECIES_WYNAUT) { LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DOODLE, target: opponentLeft); }
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_BLAZE);
        EXPECT_EQ(playerLeft->learnedAbility, ABILITY_SPEED_BOOST);
        EXPECT_EQ(playerRight->ability, ABILITY_BLAZE);
        EXPECT_EQ(playerRight->learnedAbility, ABILITY_LIMBER);
    }
}
