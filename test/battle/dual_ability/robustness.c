#include "global.h"
#include "test/battle.h"

// Dual Emerald: every ability, legal for the species or not, can sit in the learned slot without
// breaking a battle. Behavior isn't checked, only that the battle runs its turns to the end. The
// opponents use the smart AI, which still reads only the natural slot (until Milestone 5).

AI_SINGLE_BATTLE_TEST("Robustness: any learned ability on both battlers doesn't break a singles battle")
{
    enum Ability ability = ABILITY_NONE;

    for (enum Ability j = ABILITY_NONE + 1; j < ABILITIES_COUNT; j++)
        PARAMETRIZE { ability = j; }

    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_WOBBUFFET) { LearnedAbility(ability); Moves(MOVE_CELEBRATE, MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET) { LearnedAbility(ability); Moves(MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL, MOVE_PROTECT); }
    } WHEN {
        // The player's side uses Celebrate (TURN's default) and the AI attacks: a scripted attack
        // could become an illegal choice under abilities like Gorilla Tactics or Cursed Body.
        TURN {}
        TURN {}
        TURN {}
    }
}

AI_DOUBLE_BATTLE_TEST("Robustness: any learned ability on all battlers doesn't break a doubles battle")
{
    enum Ability ability = ABILITY_NONE;

    for (enum Ability j = ABILITY_NONE + 1; j < ABILITIES_COUNT; j++)
        PARAMETRIZE { ability = j; }

    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_WOBBUFFET) { LearnedAbility(ability); Moves(MOVE_CELEBRATE, MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL); }
        PLAYER(SPECIES_WYNAUT) { LearnedAbility(ability); Moves(MOVE_CELEBRATE, MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET) { LearnedAbility(ability); Moves(MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL, MOVE_PROTECT); }
        OPPONENT(SPECIES_WYNAUT) { LearnedAbility(ability); Moves(MOVE_TACKLE, MOVE_EMBER, MOVE_GROWL, MOVE_PROTECT); }
    } WHEN {
        // The player's side uses Celebrate (TURN's default) and the AI attacks: a scripted attack
        // could become an illegal choice under abilities like Gorilla Tactics or Cursed Body.
        TURN {}
        TURN {}
        TURN {}
    }
}
