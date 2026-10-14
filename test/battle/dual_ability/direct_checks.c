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

SINGLE_BATTLE_TEST("Learned Shield Dust blocks secondary effects")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_NUZZLE, MOVE_EFFECT_PARALYSIS, 100) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, MOVE_NUZZLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
    } THEN {
        EXPECT(!(opponent->status1 & STATUS1_PARALYSIS));
    }
}

SINGLE_BATTLE_TEST("Learned Sheer Force removes secondary effects")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_NUZZLE, MOVE_EFFECT_PARALYSIS, 100) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NUZZLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NUZZLE, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT(!(opponent->status1 & STATUS1_PARALYSIS));
    }
}

SINGLE_BATTLE_TEST("Heal Bell does not cure a benched Pokémon with learned Soundproof (Gen4)")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HEAL_BELL));
        WITH_CONFIG(B_HEAL_BELL_SOUNDPROOF, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_EXPLOUD) { Ability(ABILITY_SCRAPPY); LearnedAbility(ABILITY_SOUNDPROOF); Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_HEAL_BELL, target: player); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BELL, player);
        SEND_IN_MESSAGE("Exploud");
        MESSAGE("Exploud was hurt by its poisoning!");
    }
}

SINGLE_BATTLE_TEST("Learned Levitate makes the battler immune to Ground-type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        NOT HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_LEVITATE);
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects the learned slot against Neutralizing Gas")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_WHITE_SMOKE); LearnedAbility(ABILITY_DROUGHT); Item(item); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        if (item == ITEM_ABILITY_SHIELD) {
            ABILITY_POPUP(player, ABILITY_DROUGHT);
        } else {
            NOT ABILITY_POPUP(player, ABILITY_DROUGHT);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects the learned slot against Mold Breaker")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
        ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LEVITATE); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD)
            NOT HP_BAR(opponent);
        else
            HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("A learned status-blocking ability names itself when it blocks the status")
{
    enum Ability learned;
    enum Move move;

    PARAMETRIZE { learned = ABILITY_LIMBER;     move = MOVE_THUNDER_WAVE; }
    PARAMETRIZE { learned = ABILITY_INSOMNIA;   move = MOVE_SPORE; }
    PARAMETRIZE { learned = ABILITY_WATER_VEIL; move = MOVE_WILL_O_WISP; }
    PARAMETRIZE { learned = ABILITY_IMMUNITY;   move = MOVE_TOXIC; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(opponent, learned);
    } THEN {
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Learned Klutz stops the holder's item from working")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_KLUTZ); Item(ITEM_LEFTOVERS); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NOT MESSAGE("Wobbuffet restored a little HP using its Leftovers!");
    } THEN {
        EXPECT_EQ(player->hp, 100);
    }
}
