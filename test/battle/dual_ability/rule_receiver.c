#include "global.h"
#include "test/battle.h"

// Design doc: Power of Alchemy and Receiver copy all ability slots of the fallen ally. User's ruling:
// the copy is exact, an empty learned slot included; a slot holding an uncopyable ability keeps the
// receiver's own ability.

DOUBLE_BATTLE_TEST("Receiver and Power of Alchemy copy both of the fainted ally's slots")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_RECEIVER; }
    PARAMETRIZE { ability = ABILITY_POWER_OF_ALCHEMY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); LearnedAbility(ABILITY_INTIMIDATE); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        ABILITY_POPUP(opponentLeft, ability);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE); // the copied learned ability activates
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_SPEED_BOOST);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_INTIMIDATE);
    }
}

DOUBLE_BATTLE_TEST("Learned Receiver copies both slots, emptying the learned slot if the ally's was empty")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_RECEIVER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_SPEED_BOOST);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_NONE);
    }
}

DOUBLE_BATTLE_TEST("Receiver keeps its own ability in a slot whose ally ability can't be copied")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_WONDER_GUARD].cantBeCopied);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_RECEIVER); LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_WONDER_GUARD); LearnedAbility(ABILITY_SPEED_BOOST); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BITE, target: opponentRight); } // super effective, so Wonder Guard lets it hit
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_RECEIVER);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

DOUBLE_BATTLE_TEST("Receiver doesn't activate if the ally has nothing it can copy")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_WONDER_GUARD].cantBeCopied);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_RECEIVER); LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_WONDER_GUARD); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BITE, target: opponentRight); } // super effective, so Wonder Guard lets it hit
    } SCENE {
        NOT ABILITY_POPUP(opponentLeft, ABILITY_RECEIVER);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_RECEIVER);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_LIMBER);
    }
}

// Illusion can't be learned, and its cantBeCopied flag keeps copy effects from moving it into a slot.
DOUBLE_BATTLE_TEST("Receiver and Role Play can't copy Illusion into either slot")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_ILLUSION].cantBeCopied);
        ASSUME(GetMoveEffect(MOVE_ROLE_PLAY) == EFFECT_ROLE_PLAY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LIMBER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_RECEIVER); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_ZORUA) { Ability(ABILITY_ILLUSION); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROLE_PLAY, target: opponentRight); MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); SEND_OUT(opponentRight, 2); }
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(playerLeft->learnedAbility, ABILITY_LIMBER);
        EXPECT_EQ(opponentLeft->ability, ABILITY_RECEIVER);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_SPEED_BOOST);
    }
}
