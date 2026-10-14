#include "global.h"
#include "test/battle.h"

// Dual Emerald: abilities checked directly on a battler work from the learned slot.

SINGLE_BATTLE_TEST("Learned Magic Guard prevents Life Orb recoil")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_MAGIC_GUARD); Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet lost some of its HP!");
        }
    }
}

SINGLE_BATTLE_TEST("Learned Pressure causes opponent's moves to use up 1 additional PP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MovesWithPP({MOVE_POUND, 35}); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_PRESSURE); }
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } THEN {
        EXPECT_EQ(player->pp[0], 33);
    }
}

SINGLE_BATTLE_TEST("Learned Oblivious prevents Taunt (Gen6+)")
{
    GIVEN {
        WITH_CONFIG(B_OBLIVIOUS_TAUNT, GEN_6);
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_OBLIVIOUS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
    }
}

SINGLE_BATTLE_TEST("Learned Sturdy prevents OHKO moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_STURDY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Fissure!");
        ABILITY_POPUP(player, ABILITY_STURDY);
        MESSAGE("It doesn't affect Wobbuffet…");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Learned Shell Armor blocks critical hits")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SHELL_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Learned No Guard makes opposing status moves hit")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_SCREECH) < 100);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Learned Skill Link makes multi-hit moves hit five times")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SKILL_LINK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLET_SEED); }
    } SCENE {
        MESSAGE("The Pokémon was hit 5 times!");
    }
}
