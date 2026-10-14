#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Zero to Hero transforms Palafin when it switches out")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Palafin");
        SEND_IN_MESSAGE("Wobbuffet");
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Palafin");
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Zero to Hero can't be suppressed by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Zero to Hero transforms both player and opponent")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(player, 0); SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
        MESSAGE("The opposing Palafin underwent a heroic transformation!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO);
        EXPECT_EQ(opponent->species, SPECIES_PALAFIN_HERO);
        }
}

SINGLE_BATTLE_TEST("Zero to Hero will activate if a switch move is used")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLIP_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLIP_TURN); SEND_OUT(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLIP_TURN, player);
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Gastro Acid fails if the target has the Ability Zero to Hero")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        MESSAGE("But it failed!");
    }
}

// Dual Emerald: Zero to Hero can't be overwritten, so Worry Seed and Simple Beam give a learned ability instead.
SINGLE_BATTLE_TEST("Worry Seed and Simple Beam give a learned ability to a target with Zero to Hero")
{
    enum Move move;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_WORRY_SEED; ability = ABILITY_INSOMNIA; }
    PARAMETRIZE { move = MOVE_SIMPLE_BEAM; ability = ABILITY_SIMPLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_ZERO_TO_HERO);
        EXPECT_EQ(player->learnedAbility, ability);
    }
}

SINGLE_BATTLE_TEST("Transform doesn't apply the heroic transformation message when copying Palafin")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        MESSAGE("The opposing Wobbuffet transformed into Palafin!");
        NOT ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Imposter doesn't apply the heroic transformation message when copying Palafin")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
        TURN { SWITCH(player, 0); SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
        ABILITY_POPUP(opponent, ABILITY_IMPOSTER);
        MESSAGE("The opposing Ditto transformed into Palafin!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
            MESSAGE("The opposing Ditto underwent a heroic transformation!");
        }
    } THEN { EXPECT_EQ(player->species, SPECIES_PALAFIN_HERO); }
}

SINGLE_BATTLE_TEST("Zero to Hero's message displays correctly after all battlers fainted - Player")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_PALAFIN_ZERO);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLIP_TURN); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_EXPLOSION); SEND_OUT(player, 0); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        // Everyone faints.
        SEND_IN_MESSAGE("Palafin");
        MESSAGE("2 sent out Wobbuffet!");
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    }
}

SINGLE_BATTLE_TEST("Zero to Hero's message displays correctly after all battlers fainted - Opponent")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PALAFIN_ZERO);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLIP_TURN); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 0); }
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("2 sent out Palafin!");
        ABILITY_POPUP(opponent, ABILITY_ZERO_TO_HERO);
        MESSAGE("The opposing Palafin underwent a heroic transformation!");
    }
}

// Write Trace test and move this one to that file (including every other ability that can't be copied)
SINGLE_BATTLE_TEST("Zero to Hero cannot be copied by Trace")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_TRACE);
            MESSAGE("The opposing Ralts Traced Palafin's Zero to Hero!");
        }
    }
}
