#include "global.h"
#include "test/battle.h"

// Design doc: Transform and Imposter overwrite both of the holder's ability slots, even if the copied
// foe has no learned ability.

SINGLE_BATTLE_TEST("Transform copies both slots, including an empty learned slot")
{
    enum Ability targetLearned;

    PARAMETRIZE { targetLearned = ABILITY_NONE; }
    PARAMETRIZE { targetLearned = ABILITY_INTIMIDATE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(targetLearned); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, targetLearned);
    }
}

SINGLE_BATTLE_TEST("Imposter copies both slots of the foe")
{
    enum Ability targetLearned;

    PARAMETRIZE { targetLearned = ABILITY_NONE; }
    PARAMETRIZE { targetLearned = ABILITY_SPEED_BOOST; }

    GIVEN {
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_IMPOSTER); LearnedAbility(ABILITY_LIMBER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(targetLearned); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_IMPOSTER);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, targetLearned);
    }
}

SINGLE_BATTLE_TEST("Learned Imposter transforms on switch-in and copies both slots")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_IMPOSTER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_IMPOSTER);
    } THEN {
        EXPECT(player->volatiles.transformed);
        EXPECT_EQ(player->ability, ABILITY_TELEPATHY);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("A transformed battler's original learned ability returns after it switches out")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { Ability(ABILITY_LIMBER); LearnedAbility(ABILITY_SPEED_BOOST); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_LIMBER);
        EXPECT_EQ(player->learnedAbility, ABILITY_SPEED_BOOST);
    }
}
