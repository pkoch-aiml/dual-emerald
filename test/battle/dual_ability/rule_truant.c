#include "global.h"
#include "test/battle.h"

// Design doc: Truant held twice uses one "loafed last turn" state, so it acts exactly like a single
// Truant.

SINGLE_BATTLE_TEST("Truant loafs every other turn, whether held once or in both slots")
{
    enum Ability natural, learned;

    PARAMETRIZE { natural = ABILITY_TRUANT;    learned = ABILITY_NONE; }
    PARAMETRIZE { natural = ABILITY_TELEPATHY; learned = ABILITY_TRUANT; }
    PARAMETRIZE { natural = ABILITY_TRUANT;    learned = ABILITY_TRUANT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(natural); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        MESSAGE("Wobbuffet is loafing around!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        MESSAGE("Wobbuffet is loafing around!");
    }
}
