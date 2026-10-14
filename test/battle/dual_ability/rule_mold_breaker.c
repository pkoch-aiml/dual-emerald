#include "global.h"
#include "test/battle.h"

// Design doc: Mold Breaker, Mycelium Might, Propeller Tail, Stalwart, Teravolt and Turboblaze ignore
// abilities in all slots.

SINGLE_BATTLE_TEST("Mold Breaker family ignores the target's learned breakable ability")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_TERAVOLT; }
    PARAMETRIZE { ability = ABILITY_TURBOBLAZE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        ASSUME(gAbilitiesInfo[ABILITY_LEVITATE].breakable);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SLAP, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Mold Breaker ignores breakable abilities in both of the target's slots", s16 damage)
{
    enum Ability attackerAbility;

    PARAMETRIZE { attackerAbility = ABILITY_TELEPATHY; }
    PARAMETRIZE { attackerAbility = ABILITY_MOLD_BREAKER; }

    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_MULTISCALE].breakable);
        ASSUME(gAbilitiesInfo[ABILITY_FUR_COAT].breakable);
        PLAYER(SPECIES_WOBBUFFET) { Ability(attackerAbility); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_MULTISCALE); LearnedAbility(ABILITY_FUR_COAT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // Multiscale halves damage and Fur Coat doubles Defense: about 4x less damage without Mold Breaker.
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Learned Mycelium Might ignores the target's learned ability for status moves")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_CLEAR_BODY].breakable);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_MYCELIUM_MIGHT); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCREECH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        NOT ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}

DOUBLE_BATTLE_TEST("Propeller Tail and Stalwart ignore a learned Storm Drain's redirection")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_PROPELLER_TAIL; }
    PARAMETRIZE { ability = ABILITY_STALWART; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_STORM_DRAIN); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft);
        NOT ABILITY_POPUP(opponentRight, ABILITY_STORM_DRAIN);
    }
}
