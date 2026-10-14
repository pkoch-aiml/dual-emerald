#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Simple Beam replaces target's ability with Simple")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_SIMPLE_BEAM) == ABILITY_SIMPLE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
    }WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SIMPLE_BEAM, player);
        ABILITY_POPUP(opponent, ABILITY_BLAZE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_SIMPLE);
    }
}

// Dual Emerald: a target that already has Simple gets it as its learned ability instead.
DOUBLE_BATTLE_TEST("Simple Beam gives a learned Simple to a target that already has Simple")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_SIMPLE_BEAM) == ABILITY_SIMPLE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SIMPLE_BEAM, target: opponentLeft); MOVE(playerRight, MOVE_SIMPLE_BEAM, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SIMPLE_BEAM, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_OVERGROW);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SIMPLE_BEAM, playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_SIMPLE);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_SIMPLE);
    }
}

// Dual Emerald: the ability that can't be overwritten stays, and the target gets a learned Simple.
SINGLE_BATTLE_TEST("Simple Beam gives a learned Simple to a target whose ability can't be overwritten")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SIMPLE_BEAM) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_SIMPLE_BEAM) == ABILITY_SIMPLE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SIMPLE_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SIMPLE_BEAM, player);
        NOT MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->ability, ability);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_SIMPLE);
    }
}

SINGLE_BATTLE_TEST("Worry Seed replaces target's ability with Insomnia")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_WORRY_SEED) == ABILITY_INSOMNIA);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
    }WHEN {
        TURN { MOVE(player, MOVE_WORRY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        ABILITY_POPUP(opponent, ABILITY_BLAZE);
    } THEN {
        EXPECT_EQ(opponent->ability, ABILITY_INSOMNIA);
    }
}

// Dual Emerald: a target that already has Insomnia gets it as its learned ability instead.
DOUBLE_BATTLE_TEST("Worry Seed gives a learned Insomnia to a target that already has Insomnia")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_WORRY_SEED) == ABILITY_INSOMNIA);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        PLAYER(SPECIES_CHARMANDER) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_BULBASAUR) { Ability(ABILITY_OVERGROW); }
        OPPONENT(SPECIES_SQUIRTLE) { Ability(ABILITY_TORRENT); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WORRY_SEED, target: opponentLeft); MOVE(playerRight, MOVE_WORRY_SEED, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_OVERGROW);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, playerRight);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_INSOMNIA);
        EXPECT_EQ(opponentLeft->learnedAbility, ABILITY_INSOMNIA);
    }
}

// Dual Emerald: the ability that can't be overwritten stays, and the target gets a learned Insomnia.
SINGLE_BATTLE_TEST("Worry Seed gives a learned Insomnia to a target whose ability can't be overwritten")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WORRY_SEED) == EFFECT_OVERWRITE_ABILITY);
        ASSUME(GetMoveOverwriteAbility(MOVE_WORRY_SEED) == ABILITY_INSOMNIA);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_WORRY_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WORRY_SEED, player);
        NOT MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(opponent->ability, ability);
        EXPECT_EQ(opponent->learnedAbility, ABILITY_INSOMNIA);
    }
}
