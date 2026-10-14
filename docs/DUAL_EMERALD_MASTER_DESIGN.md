# Dual Emerald: An ability-focused ROM hack
## Overview & Design Philosophy
Pokemon Dual Emerald is a rework of Pokemon Emerald with two core conceits: Pokemon should be able to hold *two* abilities, not just one; and *double* battles should be the default way to battle. Generation III added both double battles and abilities to the franchise, so it only makes sense to set this remake in Hoenn.

The franchise has done a great job of exploring the design space of moves. Signature moves, TMs, HMs, tutors, relearning, and the level-up system all lend massive amounts of flavor to each Pokemon's design, as well as richness to the strategic landscape of a run through the game. By contrast, abilities have seen only a few innovations through the generations. In light of Calyrex's As One ability and Mega Eelektross's Eelevate ability, though, Game Freak has begun to entertain a very interesting idea: What if limiting Pokemon to a single ability is holding back good design?

## Core Mechanic Changes
### Pokemon Abilities
I want a Pokemon's abilities to reflect both its natural characteristics and its training, the way its stats and moves already do. To this end, each Pokemon has two ability slots: their **natural** ability and their **learned** ability. Most wild Pokemon have only a natural ability, with an empty learned ability slot, and trainers can change the learned ability of their caught Pokemon through the use of Ability Machines (AMs) or cross-training: transferring learned abilities from one caught Pokemon to another.

This separation serves several purposes:
* Natural abilities continue to function the way abilities currently do. When a Pokemon evolves, its natural ability may change--but its learned ability won't. The Ability Capsule and Ability Patch items should work as expected as well.
* Learned abilities should be intuitive to players due to the parallels to learned moves and TMs.
* It limits the inter-ability interactions we need to cover for while developing the game.

### Wild Pokemon
Wild Pokemon each have an empty learned ability slot. This is a norm, not a rule--it should be *possible* to begin a wild Pokemon battle against a Pokemon with two abilities, as I foresee that happening as a story beat.

### Signature and Form-Changing Abilities
Some extant abilities are so fundamental to their holder's design that they are immune to ability-swapping, -neutralizing, or -overwriting effects. These abilities, like Stance Change, Hunger Switch, and Wonder Guard, can only be natural abilities, and continue to be immune to the aforementioned effects.

### Abilities That Affect Other Abilities
- **Lingering Aroma** and **Mummy**: Always affects the foe's same ability slot.
- **Mold Breaker**, **Mycelium Might**, **Propeller Tail**, **Stalwart**, **Teravolt**, and **Turboblaze**: Ignores abilities in all slots.
- **Neutralizing Gas**: Affects all ability slots.
- **Power of Alchemy** and **Receiver**: Copies all ability slots of the fallen ally.
- **Trace**: As a natural ability, always copies a random foe's natural ability. As a learned ability, copies a random ability of a random foe.
- **Imposter**: Overwrites both of the holder's ability slots, even if the copied foe has no learned ability.
- **Wandering Spirit**: Always exchanges the same ability slot as the foe. Fails if the slot is empty, like learned abilities on wild Pokemon.

### Moves That Affect Abilities
- **Doodle**, **Entrainment**, **Role Play**, and **Skill Swap**: Always affects natural abilities only.
- **Simple Beam** and **Worry Seed**: If the target already has Simple/Insomnia as their natural ability, affects their learned ability. Otherwise always affects the natural ability.
- **Core Enforcer** and **Gastro Acid**: Affects all ability slots.
- **Transform**: Overwrites both of the holder's ability slots, even if the copied foe has no learned ability.

### Cross-Training
A mechanic I found charming in generation IX was the ability of a Pokemon to learn an egg move by holding a Mirror Herb and picnicking with a Pokemon that knows the move. In that spirit, one way players can teach their Pokemon a learned ability is by cross-training it with a Pokemon who has (or has previously had) that ability. This incentivizes players to catch many Pokemon, and affords us the opportunity to introduce ability-flavored counterparts to move-related NPCs.

Cross-training is free to perform on your own Pokemon, and available from the Pokemon Center PC.

#### Ability Tutors
Similar to move tutors, ability tutors are NPCs who will facilitate granting your Pokemon new abilities. They do this by owning rare Pokemon, with whom your team can cross-train for a price. Additionally, I'd like to allow players to rematch certain story NPCs, like gym leaders, for the opportunity to cross-train a powerful ability from one of their Pokemon.

#### Ability Relearner
Each Pokemon remembers which learned abilities it has previously held, and this NPC will happily help them return to one of them if the moment calls for it.

### Ability Machines and Compatibility
Each Pokemon has a small pool of compatible learned abilities, similar to its move pool. Any AMs that teach an ability in that abilty pool is therefore compatible with that Pokemon--but note that not all learnable abilities are AMs. To obtain a learned ability that is not on the AM list, players must use cross-training or a tutor.

Note that owning a Pokemon with a learned ability in its memory is tantamount to having that ability's AM, so it is possible that when players reach story beats that grant them an AM, they already have full access to that ability. Thus, those AMs should be coordinated carefully with the list of catchable Pokemon and their achievable learned abilities to minimize feels-bad situations.

### Breeding
All current rules regarding the passing down of abilities still apply to Pokemon's natural abilities: offspring have a 60% chance of inheriting a hidden ability from either parent, and in the absence of that, have an 80% chance of inheriting their mother's (or father's, if their other parent is a Ditto) natural ability. Learned abilities, on the other hand, are never inherited, and all Pokemon hatched from an Egg have an empty second ability slot.

### Evolution
Evolution can never cause a learned ability to become illegal. This is a design rule, not an in-game check; each evolved form's learnable list should be a superset of its pre-evolution's.

### Mega Evolution
Mega evolved forms have a single possible natural ability and a single learned ability, which may not exist on the corresponding species' learnable list. Mega evolving overwrites both slots, and often gives players access to powerful ability combinations that are otherwise unachievable.

## Story
I want to rewrite the entire story to center around Latios, Latias, and Jirachi instead of Groudon, Kyogre, and Rayquaza. In the tradition of Pokemon Run & Bun and other classic ROM hacks, the player will unlock the power of Mega Evolution along the way. I do not intend to enable Z-moves, Dynamax, or Terastalization.