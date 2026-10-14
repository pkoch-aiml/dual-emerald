#include "global.h"
#include "test/battle.h"

// Dual Emerald: stage 2.7 sites that read a battler's ability outside the main dispatch paths.

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GROWL) == EFFECT_STAT_CHANGE);
}

SINGLE_BATTLE_TEST("Learned Contrary inverts stat changes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Contrary in both slots cancels out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_CONTRARY); LearnedAbility(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Simple in both slots quadruples stat changes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SIMPLE); LearnedAbility(ABILITY_SIMPLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 4);
    }
}

SINGLE_BATTLE_TEST("Learned Immunity cures existing poison on turn 0")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_IMMUNITY); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_IMMUNITY);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Natural Regenerator and learned Natural Cure both apply on switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REGENERATOR); LearnedAbility(ABILITY_NATURAL_CURE); HP(1); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP / 3 + 1);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Regenerator in both slots heals 1/3 of max HP twice on switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_REGENERATOR); LearnedAbility(ABILITY_REGENERATOR); HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->hp, 2 * (player->maxHP / 3) + 1);
    }
}

SINGLE_BATTLE_TEST("Learned Inner Focus prevents Intimidate (Gen8+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_INNER_FOCUS); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ABILITY_INNER_FOCUS);
        MESSAGE("Wobbuffet's Attack was not lowered!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Learned Lightning Rod redirects Electric-type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDER_SHOCK, target: opponentLeft); }
    } SCENE {
        NOT HP_BAR(opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_LIGHTNING_ROD);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Learned Oblivious prevents infatuation")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_OBLIVIOUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT); }
    } THEN {
        EXPECT(!opponent->volatiles.infatuation);
    }
}

SINGLE_BATTLE_TEST("Learned Sticky Hold names itself when it stops Thief")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_STICKY_HOLD); Item(ITEM_LEFTOVERS); }
    } WHEN {
        TURN { MOVE(player, MOVE_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THIEF, player);
        ABILITY_POPUP(opponent, ABILITY_STICKY_HOLD);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_LEFTOVERS);
    }
}

SINGLE_BATTLE_TEST("Neutralizing Gas exiting reactivates a learned switch-in ability but not natural Imposter")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); LearnedAbility(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NOT ABILITY_POPUP(player, ABILITY_IMPOSTER);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    }
}

TEST("Every ability that can't be swapped or suppressed can't be doubled")
{
    for (enum Ability ability = ABILITY_NONE + 1; ability < ABILITIES_COUNT; ability++)
    {
        if (gAbilitiesInfo[ability].cantBeSwapped || gAbilitiesInfo[ability].cantBeSuppressed)
            EXPECT(gAbilitiesInfo[ability].cantBeDoubled);
    }
}

SINGLE_BATTLE_TEST("A battler holding a can't-be-doubled ability in both slots doesn't break the battle")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_STANCE_CHANGE].cantBeDoubled);
        PLAYER(SPECIES_AEGISLASH_SHIELD) { Ability(ABILITY_STANCE_CHANGE); LearnedAbility(ABILITY_STANCE_CHANGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_HEAD); }
        TURN { MOVE(player, MOVE_KINGS_SHIELD); MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_IRON_HEAD); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_AEGISLASH_BLADE);
    }
}
