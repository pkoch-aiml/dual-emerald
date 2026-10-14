#include "global.h"
#include "test/battle.h"

// Dual Emerald: field-wide ability checks and Mold Breaker see the learned slot.

SINGLE_BATTLE_TEST("Learned Damp prevents Explosion")
{
    GIVEN {
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); LearnedAbility(ABILITY_DAMP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DAMP);
        NONE_OF { HP_BAR(player); HP_BAR(opponent); }
    }
}

DOUBLE_BATTLE_TEST("A partner's learned Sweet Veil prevents sleep")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); LearnedAbility(ABILITY_SWEET_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SPORE, target: playerLeft); }
    } SCENE {
        NOT STATUS_ICON(playerLeft, sleep: TRUE);
    } THEN {
        EXPECT(!(playerLeft->status1 & STATUS1_SLEEP));
    }
}

WILD_BATTLE_TEST("Learned Arena Trap prevents escape and names the learned ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_ZIGZAGOON) { Ability(ABILITY_PICKUP); LearnedAbility(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId trapper = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        enum Ability trappingAbility = ABILITY_NONE;
        EXPECT_EQ(GetAbilityPreventingEscape(battler, &trappingAbility), trapper + 1);
        EXPECT_EQ(trappingAbility, ABILITY_ARENA_TRAP);
        EXPECT_EQ(IsRunningFromBattleImpossible(battler), BATTLE_RUN_FAILURE);
    }
}

WILD_BATTLE_TEST("Learned Run Away allows fleeing from a trapping ability")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_RUN_AWAY); }
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        EXPECT_NE(IsAbilityPreventingEscape(battler), 0);
        EXPECT_EQ(IsRunningFromBattleImpossible(battler), BATTLE_RUN_SUCCESS);
    }
}

SINGLE_BATTLE_TEST("Learned Mold Breaker lets Ground moves hit a Levitate target")
{
    enum Ability learnedAbility;
    PARAMETRIZE { learnedAbility = ABILITY_NONE; }
    PARAMETRIZE { learnedAbility = ABILITY_MOLD_BREAKER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(learnedAbility); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        if (learnedAbility == ABILITY_MOLD_BREAKER)
            HP_BAR(opponent);
        else
            NOT HP_BAR(opponent);
    }
}
