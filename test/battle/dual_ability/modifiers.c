#include "global.h"
#include "test/battle.h"

// Dual Emerald: damage, speed, crit and priority modifiers apply once per slot, so modifiers from
// the natural and learned slots stack, including when the same ability is in both slots. Abilities
// that set or negate something (Adaptability's STAB, Guts ignoring burn) apply only once.

SINGLE_BATTLE_TEST("Natural Huge Power and learned Hustle multiply attack together", s16 damage)
{
    enum Ability ability, learned;

    PARAMETRIZE { ability = ABILITY_TELEPATHY;   learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER;  learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER;  learned = ABILITY_HUSTLE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_AERIAL_ACE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveAccuracy(MOVE_AERIAL_ACE) == 0);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(3.0), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Huge Power in both slots quadruples attack", s16 damage)
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_HUGE_POWER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HUGE_POWER); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Natural Technician and learned Sheer Force multiply power together", s16 damage)
{
    enum Ability ability, learned;

    PARAMETRIZE { ability = ABILITY_TELEPATHY;  learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_TECHNICIAN; learned = ABILITY_SHEER_FORCE; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_EMBER) <= 60);
        ASSUME(MoveIsAffectedBySheerForce(MOVE_EMBER));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.95), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Natural Adaptability and learned Tough Claws multiply together", s16 damage)
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_TOUGH_CLAWS; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_HEADBUTT) == TYPE_NORMAL);
        ASSUME(MoveMakesContact(MOVE_HEADBUTT));
        PLAYER(SPECIES_SNORLAX) { Ability(ABILITY_ADAPTABILITY); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HEADBUTT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Adaptability in both slots sets STAB to 2x only once", s16 damage)
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_ADAPTABILITY; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_ZIGZAGOON) { Ability(ABILITY_ADAPTABILITY); LearnedAbility(learned); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Guts in both slots boosts a burned attacker twice and ignores the burn drop once", s16 damage)
{
    enum Ability ability, learned;
    u32 status;

    PARAMETRIZE { ability = ABILITY_TELEPATHY; learned = ABILITY_NONE; status = STATUS1_NONE; }
    PARAMETRIZE { ability = ABILITY_GUTS;      learned = ABILITY_NONE; status = STATUS1_BURN; }
    PARAMETRIZE { ability = ABILITY_GUTS;      learned = ABILITY_GUTS; status = STATUS1_BURN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.25), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Natural Multiscale and learned Shadow Shield multiply together", s16 damage)
{
    enum Ability ability, learned;

    PARAMETRIZE { ability = ABILITY_TELEPATHY;  learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_MULTISCALE; learned = ABILITY_SHADOW_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Learned Thick Fat halves the attacker's Fire-type attack", s16 damage)
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_THICK_FAT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Swift Swim in both slots quadruples speed in rain")
{
    u32 opponentSpeed;

    PARAMETRIZE { opponentSpeed = 399; }
    PARAMETRIZE { opponentSpeed = 401; }

    GIVEN {
        PLAYER(SPECIES_LUDICOLO) { Ability(ABILITY_SWIFT_SWIM); LearnedAbility(ABILITY_SWIFT_SWIM); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(opponentSpeed); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        if (opponentSpeed < 400) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Learned Unburden and natural Chlorophyll multiply speed together")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_CHLOROPHYLL); LearnedAbility(ABILITY_UNBURDEN); Item(ITEM_SITRUS_BERRY); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(399); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_BELLY_DRUM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Super Luck in both slots raises the critical hit ratio by 2 stages")
{
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_7);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SUPER_LUCK); LearnedAbility(ABILITY_SUPER_LUCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Natural Prankster and learned Gale Wings don't stack: Tailwind gets +1 priority, not +2")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_TAILWIND) == TYPE_FLYING);
        ASSUME(GetMoveCategory(MOVE_TAILWIND) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PRANKSTER); LearnedAbility(ABILITY_GALE_WINGS); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_QUICK_ATTACK); MOVE(player, MOVE_TAILWIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAILWIND, player);
    }
}

SINGLE_BATTLE_TEST("Natural Prankster and learned Gale Wings: a Flying-type status move isn't Prankster-boosted, so it affects Dark types")
{
    bool32 learnedGaleWings;

    PARAMETRIZE { learnedGaleWings = FALSE; }
    PARAMETRIZE { learnedGaleWings = TRUE; }

    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, GEN_7);
        ASSUME(GetMoveType(MOVE_FEATHER_DANCE) == TYPE_FLYING);
        ASSUME(GetMoveCategory(MOVE_FEATHER_DANCE) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetSpeciesType(SPECIES_UMBREON, 0) == TYPE_DARK);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PRANKSTER); LearnedAbility(learnedGaleWings ? ABILITY_GALE_WINGS : ABILITY_NONE); }
        OPPONENT(SPECIES_UMBREON);
    } WHEN {
        TURN { MOVE(player, MOVE_FEATHER_DANCE); }
    } SCENE {
        if (learnedGaleWings) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Natural Prankster and learned Triage: Roost gets Triage's +3 priority, not +4")
{
    GIVEN {
        ASSUME(IsHealingMove(MOVE_ROOST));
        ASSUME(GetMovePriority(MOVE_EXTREME_SPEED) == 2);
        ASSUME(GetMovePriority(MOVE_FAKE_OUT) == 3);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PRANKSTER); LearnedAbility(ABILITY_TRIAGE); Speed(1); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_ROOST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
    }
}

DOUBLE_BATTLE_TEST("Partner's natural Battery and learned Power Spot multiply together", s16 damage)
{
    enum Ability ability, learned;

    PARAMETRIZE { ability = ABILITY_TELEPATHY; learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_BATTERY;   learned = ABILITY_POWER_SPOT; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SHOCK_WAVE) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SHOCK_WAVE, target: opponentLeft); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.69), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Partner's Friend Guard in both slots reduces damage twice", s16 damage)
{
    enum Ability ability, learned;

    PARAMETRIZE { ability = ABILITY_TELEPATHY;    learned = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_FRIEND_GUARD; learned = ABILITY_FRIEND_GUARD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AERIAL_ACE, target: opponentLeft); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5625), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Learned Dark Aura boosts Dark-type moves on the field", s16 damage)
{
    enum Ability learned;

    PARAMETRIZE { learned = ABILITY_NONE; }
    PARAMETRIZE { learned = ABILITY_DARK_AURA; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(learned); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BITE, target: opponentLeft); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.33), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Learned Minus on a partner activates natural Plus", s16 damage)
{
    enum Ability partnerLearned;

    PARAMETRIZE { partnerLearned = ABILITY_NONE; }
    PARAMETRIZE { partnerLearned = ABILITY_MINUS; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_PLUS); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); LearnedAbility(partnerLearned); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHOCK_WAVE, target: opponentLeft); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}
