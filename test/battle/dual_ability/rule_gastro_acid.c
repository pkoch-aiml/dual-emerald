#include "global.h"
#include "test/battle.h"

// Design doc: Core Enforcer and Gastro Acid affect all ability slots. Signature abilities stay immune;
// when the natural ability is a signature one, the learned slot is still suppressed (user's ruling).

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
    ASSUME(GetMoveType(MOVE_MUD_SLAP) == TYPE_GROUND);
}

SINGLE_BATTLE_TEST("Gastro Acid suppresses both slots")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SPEED_BOOST); LearnedAbility(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SLAP, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_SPEED_BOOST);
    }
}

SINGLE_BATTLE_TEST("Gastro Acid suppresses the learned slot when the natural ability is a signature ability")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_DISGUISE].cantBeSuppressed);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); LearnedAbility(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, player);
        MESSAGE("The opposing Mimikyu's Ability was suppressed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SLAP, player);
        NOT ABILITY_POPUP(opponent, ABILITY_LEVITATE);
        ABILITY_POPUP(opponent, ABILITY_DISGUISE); // the signature ability still works
    } THEN {
        EXPECT(opponent->volatiles.gastroAcid);
    }
}

SINGLE_BATTLE_TEST("Gastro Acid fails if neither slot can be suppressed")
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_STANCE_CHANGE; }

    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_DISGUISE].cantBeSuppressed);
        ASSUME(gAbilitiesInfo[ABILITY_STANCE_CHANGE].cantBeSuppressed);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(player, MOVE_GASTRO_ACID); }
    } SCENE {
        NOT MESSAGE("The opposing Mimikyu's Ability was suppressed!");
    } THEN {
        EXPECT(!opponent->volatiles.gastroAcid);
    }
}

SINGLE_BATTLE_TEST("Core Enforcer suppresses the learned slot of a target that has already acted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CORE_ENFORCER); }
        TURN { MOVE(player, MOVE_MUD_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SLAP, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Baton Pass keeps Gastro Acid on a receiver whose learned slot can be suppressed")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); LearnedAbility(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(opponent, MOVE_MUD_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MUD_SLAP, opponent);
        NOT ABILITY_POPUP(player, ABILITY_LEVITATE);
    } THEN {
        EXPECT(player->volatiles.gastroAcid);
    }
}
