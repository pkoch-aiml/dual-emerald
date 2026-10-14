# Dual Emerald: Implementation Plan

Companion to [DUAL_EMERALD_MASTER_DESIGN.md](DUAL_EMERALD_MASTER_DESIGN.md). Base: pokeemerald-expansion 1.17.2 (unreleased master).

## Guiding principles

- **Keep vanilla behavior when the learned slot is empty.** The ~300 existing ability tests in `test/battle/ability/` then work as a regression suite. `make check` must stay green at the end of every milestone.
- **Put changes behind one config header** ([include/config/dual_emerald.h](../include/config/dual_emerald.h)) where that's practical. This keeps upstream merges manageable and makes the diff easy to find.
- **Leave story content for later.** The plot will be rewritten, so trainer teams, wild-encounter tuning and doubles-by-default all come after the mechanics exist.

---

## Milestone 1: "Dual Slot Foundation" (first release)

**Goal:** every Pokémon has a learned-ability slot that is stored, saved and shown, but has no effect on gameplay. Every species and form has a non-empty learnable-ability pool in its dex data.

**Acceptance criteria**
- The ROM builds, boots and plays through the introduction (new game → Birch rescue → first battle → Oldale).
- Every Pokémon (wild, trainer, scripted, gift, egg) starts with an empty learned slot.
- The learned slot has no effect on battles or anything else in the game.
- On the summary page that shows the ability, **R** swaps between the natural and learned ability. After the learned ability is set through the debug menu, its name and description appear there.
- Every `SPECIES_*` entry, including forms, points to a non-empty learnable-ability list, and a test enforces this.
- Every evolution's list is a right-superset of its pre-evolution's list, and every Mega and Primal form has a fixed learned ability. Tests enforce both.
- `make check` passes.

### 1.1 Groundwork
1. ✅ Create a `dual-emerald` working branch. Forked from upstream `8fb02c6f2b` (2026-10-12).
2. ✅ Add `include/config/dual_emerald.h` and include it from `include/constants/global.h`.
3. ✅ Baseline (2026-10-13): `make` takes ~26 s; the ROM uses 79.7% of 32 MB. `make check -j16` takes ~5 min and has 0 failures: 5,417 pass, 18 known-failing, 9 expect-failing and 421 to-do, out of 5,865 tests.

### 1.2 Box data: the learned slot
**Storage budget.** There are 320 abilities, so the learned ability needs 9 bits. Currently unused bits:

| Location | Free bits |
|---|---|
| `PokemonSubstruct0`: `unused_02:6`, `unused_04:3`, `unused_0A:2` | 11 |
| `PokemonSubstruct1`: `unused_04:5`, `unused_06:3`, `unused_0B:1` | 9 |
| `BoxPokemon`: `unused_13:1`, `unused_1E:1` | 2 |
| **Total** | **22** |

Since the design rules out Terastalization and Dynamax, `teraType:5`, `dynamaxLevel:4` and `gigantamaxFactor:1` (10 more bits) could also be reclaimed later. Leave them alone for now so the diff against upstream stays small.

**Plan:** store the learned ability in `PokemonSubstruct0` as `learnedAbilityLo:6` (in place of `unused_02`) plus `learnedAbilityHi:3` (in place of `unused_04`). This uses the same split-field pattern as `nickname11` and `nickname12`. `BoxPokemon` stays 80 bytes, so saves made before the change load with the slot empty (0 = `ABILITY_NONE`).

**Reserved for Milestone 4:** `PokemonSubstruct1`'s 9 bits hold the ability memory used by the relearner and cross-training, as a bitmask over the species' learnable pool. This puts a hard cap of **8 entries** on each pool. Milestone 1 doesn't fill these bits, but the cap is enforced from the start so the pool data never has to be cut down later. Because of the right-superset rule (1.3), bit *i* means the same ability before and after evolution, so the memory never needs remapping.

**Why not grow `BoxPokemon` instead?** PC storage (`struct PokemonStorage`, 420 mons) fills 9 save sectors with only about 2 KB to spare. Adding 4 bytes per mon would just fit, and then there would be no room left. We're keeping the 80-byte size and the 8-entry cap. Species that need more, like Mew, use the "all AMs" flag described in 1.3.

Tasks:
1. ✅ Add the fields and a `MON_DATA_LEARNED_ABILITY` entry to `enum MonData` in `include/pokemon.h`. Handle it in `GetBoxMonData` and `SetBoxMonData` (`src/pokemon.c`), joining and splitting the two parts. A `STATIC_ASSERT` stops the build if `ABILITIES_COUNT` grows past 512.
2. ✅ Confirm that every way a Pokémon gets created leaves the slot at zero. `CreateBoxMon` zeroes the struct, so this holds for wild, trainer, `givemon`, `createmon` and egg mons. The only copy-from-another-mon path is Shedinja, which keeps Nincada's learned ability. That's legal, because Shedinja is listed as one of Nincada's evolutions.
3. ✅ **Do not** add the slot to `struct BattlePokemon` yet. Leaving it out guarantees the battle engine can't see it, which is the "no effect" requirement. Battles only write HP, PP, status and similar fields back to the party, so the learned ability survives a battle.
4. ✅ Tests in `test/learned_ability.c`, a separate file so upstream test files stay untouched:
   - the slot round-trips through every 9-bit value
   - neighboring fields aren't disturbed
   - new mons (`CreateMon`, `givemon`, eggs, `createmon`) start empty
   - data in the vanilla layout loads empty
   - the slot survives PC storage and evolution
   - an egg from two parents that both have learned abilities hatches empty (design doc, *Breeding*)

### 1.3 Dex data: learnable-ability pools
**Shape.** Use the same pattern as the existing move learnsets:
- In `struct SpeciesInfo` (`include/pokemon.h`, next to `teachableLearnset` at line 506), add `const u16 *learnableAbilities;`. It's an `ABILITY_NONE`-terminated list, like `teachableLearnset`.
- Each species entry in `src/data/pokemon/species_info/gen_*_families.h` gets `.learnableAbilities = s<Species>LearnableAbilities`. There are 1,473 entries.
- Keep the lists themselves in a new file, `src/data/pokemon/learnable_abilities.h`, included from `species_info.h`. Splitting it into one file per generation later is fine.

**Evolution: right-superset rule.** The design says evolution must never make a learned ability illegal. We enforce something stronger: if `S` evolves into `T` (any entry in `S.evolutions`), then `T`'s list starts with `S`'s list, entry for entry and in the same order. Any new abilities go at the end. Two consequences:
- A learned ability is always legal after evolution.
- The ability memory bitmask (1.2) carries over unchanged, with no remapping.

With the 8-entry cap, a whole evolution line, including branches like Eevee's, shares one budget of 8, and earlier stages use up the start of it.

**Out-of-battle form changes.** Rotom, Shaymin, Hoopa, Oricorio and similar species change form outside battle through `formChangeTable`. These changes can be reversed, so applying the superset rule in both directions means the forms' lists must be **identical**. These forms share one list pointer, and a test checks that the lists are equal. In-battle-only forms (Zen Mode, Mega, etc.) don't need this.

**Mega Evolution and Primal Reversion: fixed learned ability.** The design says Mega Evolution overwrites both slots, and Primal Reversion works the same way. The natural slot already comes from the form's `.abilities[]`. For the learned slot, add `enum Ability fixedLearnedAbility:9` to `struct SpeciesInfo`, set only on Mega and Primal forms (`isMegaEvolution || isPrimalReversion`). Any ability is allowed here, including ones outside the base list and ones with `cantBeSwapped`. This is read-only ROM data, about 2 bytes for each of the 1,473 species (~3 KB). It doesn't touch save data or PC storage. Mega and Primal forms share their base form's `learnableAbilities` pointer so the "every species has a list" rule still holds. Milestone 1 only adds the data; the overwrite happens in Milestone 2.

**Placeholder content.** Write a one-time script (in `tools/` or `dev_scripts/`) that generates the lists and adds the `.learnableAbilities` and `.fixedLearnedAbility` lines. Content doesn't matter for this milestone, but the structure does, so the script:
- walks each evolution tree from its root. The root's list is its own deduplicated `.abilities[]` minus any ability with `cantBeSwapped`, with a fallback such as `ABILITY_RUN_AWAY` if that leaves nothing. Each evolution copies its parent's list and then adds its own new abilities, stopping at 8 entries;
- gives form-change groups and Mega/Primal forms the shared pointers described above;
- gives each Mega and Primal form any placeholder `fixedLearnedAbility`, e.g. its base form's first natural ability.

After that the file is edited by hand, and the script isn't part of the build.

**Signature abilities.** The design says signature and form-changing abilities can only be natural. There's no new flag for this. It's enforced through the data: no learnable list contains an ability with `cantBeSwapped` set (29 abilities, including Wonder Guard and Illusion), and the existing `cantBeSwapped`/`cantBeOverwritten` checks still stop battle effects from putting one into a slot. The test below checks the data side. The only exception is `fixedLearnedAbility`, which is fixed data and not a list.

**"All AMs" species flag.** Add `u32 learnsAllAMs:1` to `struct SpeciesInfo`, taking one bit of the existing `padding4:8` so the struct doesn't change size. Set it for `SPECIES_MEW` only for now. A flagged species:
- can use **every** AM, as well as everything in its own `learnableAbilities` list;
- **always has its whole ability memory unlocked.** The memory bits are ignored, and its "remembered" set is always its own list plus every AM ability, whether or not the player owns those machines.

A flagged species still has its own non-empty list of at most 8 entries. That list is for abilities that don't come from AMs, and the usual test still applies. Milestone 1 only adds the flag and a getter, `SpeciesLearnsAllAMs(species)`; the behavior arrives in Milestone 4.

Tasks:
1. ✅ Add the struct fields (`learnableAbilities`, `fixedLearnedAbility:9`, and `learnsAllAMs:1` taken from `padding4`) to `struct SpeciesInfo` in `include/pokemon.h`. Generate the lists into `src/data/pokemon/learnable_abilities.h` and add the fields to every species entry, using `dev_scripts/dual_emerald/generate_learnable_abilities.py`. Set `learnsAllAMs` on Mew.
   - 1,571 entries share 1,189 lists. 99 Mega/Primal forms have a `fixedLearnedAbility`. 38 groups whose only abilities are unswappable (Arceus, Silvally, the Paradox Pokémon, Zorua and others) use the fallback `ABILITY_RUN_AWAY`.
   - Grouping: species share a list when they share a `formChangeTable`, appear as targets in each other's tables, or come from the same species-info macro. A species with several pre-evolutions merges those groups too, as with Gholdengo, where both Gimmighoul forms share a list.
   - An ability counts as unswappable when its `cantBeSwapped` is anything other than `FALSE`, including config expressions such as Zen Mode's `B_UPDATED_ABILITY_DATA >= GEN_7`. That makes 31 abilities.
   - Each list sits inside the same `#if` conditions as its group's main species. A check confirmed that every entry using a list is covered by those conditions.
2. ✅ Add the getters `GetSpeciesLearnableAbilities(species)`, `GetSpeciesFixedLearnedAbility(species)` and `SpeciesLearnsAllAMs(species)` in `src/pokemon.c`, next to the other learnset getters.
3. ✅ Tests in `test/learned_ability.c` (not `test/species.c`), covering every enabled species:
   - the pointer isn't NULL, the list is non-empty, it has at most `DE_MAX_LEARNABLE_ABILITIES` entries, no entry repeats, none has `cantBeSwapped`, and every entry is `< ABILITIES_COUNT`
   - **right-superset:** for each evolution `S → T`, `T`'s list starts with `S`'s list in the same order
   - **form groups:** each form-change table target has the same list as its source
   - **Mega/Primal:** `fixedLearnedAbility` is set if and only if `isMegaEvolution` or `isPrimalReversion` is set
   - Mew has `learnsAllAMs`
4. ✅ ROM size: 79.73% → 79.78% of 32 MB (about +17.7 KB).

### 1.4 Summary screen: R swaps the displayed ability ✅
- `src/pokemon_summary_screen.c`: the summary struct gets `learnedAbility`, filled next to `abilityNum`. The screen data gets a `showLearnedAbility` toggle. It's zeroed when the screen opens, so it starts on Natural.
- `PrintMonAbilityName` and `PrintMonAbilityDescription` print whichever slot is selected. An empty learned slot shows "None", with the description "No learned ability."
- A small right-aligned label (`FONT_SMALL`) on the name line shows which slot is displayed: "Natural" or "Learned".
- Input: `DE_SUMMARY_ABILITY_TOGGLE_BUTTON` (R) works on the Info page when it isn't showing an egg, and redraws only the ability window. `Task_HandleInput` never reads L or R otherwise. R is free in every button mode: the "L=A" option only remaps L. So there's no conflict with Start or Select.
- The toggle **keeps its value** when the player scrolls to another Pokémon or changes pages. It only resets when the summary screen opens.
- Still to check by hand: the screen in battle and from the PC, and that the label doesn't overlap long ability names.

### 1.5 Debug menu: Set Learned Ability ✅
- R+Start → Party… → Edit Pokemon → **Set Learned Ability**. Choose a party mon, then choose "None" or an ability from the species' learnable list, and it sets `MON_DATA_LEARNED_ABILITY`. Added in `src/debug.c` (`DebugNative_PushLearnedAbilityChoices`, `DebugNative_SetLearnedAbility`) and `data/scripts/debug.inc` (`Debug_EventScript_SetLearnedAbility`).
- Menu choice IDs are list indices plus one, not ability IDs, because an ability ID could equal `MULTI_B_PRESSED` (127).
- Tests in `test/learned_ability.c` cover both functions.
- **Set Learned (Any)**, in the same submenu: choose a party mon, then enter any ability ID from 0 (None) to `ABILITIES_COUNT - 1` with the number selector. The ability's name updates as you scroll. It ignores the species' list, so it's for testing interactions while designing. Added as `DebugNative_Party_SetAnyLearnedAbility` and `Debug_EventScript_SetAnyLearnedAbility`, modeled on Set Friendship.

### 1.6 Release check
- `make check` passes, and a clean build boots.
- Manual pass: start a new game, play through the introduction, open the summary for the starter, press R and see the empty learned slot. Set a learned ability through debug and see the name and description appear. Save, reload and check that it's still set. Win a battle and check that it's still set. Box the mon and withdraw it. Evolve it (rare candy through debug) and check that it's still set.
- Tag the commit (e.g. `v0.1-dual-slot`).

---

## Milestone 2: Battle engine core (learned abilities take effect)

Most of the engine assumes one ability per battler:

| Pattern | Approx. count |
|---|---|
| `GetBattlerAbility(...)` calls | ~220 |
| `case ABILITY_*:` in `battle_util.c` alone | ~250 |
| `gBattleMons[b].ability` direct accesses | ~100 |
| `== / != ABILITY_` comparisons across `battle_*.c` | ~460 |

1. Add `enum Ability learnedAbility` to `struct BattlePokemon` and copy it in wherever `ability` is copied (e.g. `src/pokemon.c:3405`).
2. **Slot-aware core.** Generalize `GetBattlerAbilityInternal` (`src/battle_util.c:4928`) to `GetBattlerAbilityInSlot(battler, slot, ...)`, so suppression, Mold Breaker and Ability Shield are checked separately for each slot. **Ability Shield protects both slots.**
3. **Query API.** Add `BattlerHasAbility(battler, ability)` and convert "does X have Y?" checks to it file by file. `IsAbilityOnSide` and `IsAbilityOnField` then work automatically.
4. **Trigger dispatch.** Callers of `AbilityBattleEffects` loop over both slots, **natural slot first**.
5. **Modifiers.** Rewrite the `switch (ability)` blocks in damage, speed, accuracy, crit and type-effectiveness code to apply both slots.
6. **Duplicates.** The same ability in both slots is **allowed by default**, and the effects stack where the code naturally stacks them. Add `u8 cantBeDoubled:1` to `struct AbilityInfo`, initially set for every ability with `cantBeSwapped` or `cantBeSuppressed`. Milestone 2 only adds the flag and makes sure a doubled ability doesn't crash. AMs, cross-training and the relearner refuse to create a forbidden duplicate (Milestone 4).
7. **Popups.** Check that `gLastUsedAbility` and `CreateAbilityPopUp` name the slot that actually fired.
8. **Mega Evolution and Primal Reversion** overwrite both slots: the natural slot from the form's `.abilities[]`, and the learned slot from `fixedLearnedAbility`. The party mon's real learned ability is untouched and comes back after battle.
9. **Test DSL.** Add `LearnedAbility(x)` beside `Ability(x)` in `include/test/battle.h`, then add basic tests in `test/battle/dual_ability/`: learned Intimidate, learned Levitate, stacking, natural-first order, Mega and Primal overwrite, and Ability Shield covering both slots.
10. **Robustness test:** give a battler an illegal learned ability through the test DSL, e.g. Stance Change on a non-Aegislash, run a few turns, and check that the battle finishes without crashing or asserting. The actual behavior doesn't matter.

## Milestone 3: Ability-interaction rules

There's one test file for each rule in the design doc:
- Mummy / Lingering Aroma: same slot as the foe's.
- Mold Breaker family: ignores all slots.
- Neutralizing Gas: works from either slot. It doesn't stack when held twice by one battler or by two battlers.
- Power of Alchemy / Receiver: copy all slots.
- Trace: natural vs. learned behavior.
- Imposter and Transform: overwrite both slots, even when the target's learned slot is empty.
- Wandering Spirit: swaps the same slot, and fails if it's empty.
- Doodle, Entrainment, Role Play, Skill Swap: natural only.
- Simple Beam / Worry Seed: the fallback rule.
- Core Enforcer / Gastro Acid: all slots.
- Signature abilities: immune to all of the above, as they are today.
- **Truant twice:** both copies share one "loafed last turn" state, so it acts exactly like a single Truant.
- **Illusion:** no new work. It already has `cantBeCopied`, `cantBeSwapped` and `cantBeTraced`, so copy effects fail, and it's on no learnable list. Add one test confirming that Role Play/Receiver can't move it into a slot.

## Milestone 4: Getting learned abilities
1. **Ability memory:** fill the reserved 9 bits with a bitmask of the pool entries the mon has ever held **as its learned ability**. Natural abilities are never recorded. The right-superset rule means evolution needs no remapping.
2. **AM table:** a constant table mapping each AM item to its ability, which code can loop over. Compatibility checks, and the remembered set for `learnsAllAMs` species, both read from it.
3. **AMs:** add AM items to the **TM/HM pocket** (`POCKET_TM_HM`), listed after the TMs and HMs. Add a party-menu flow modeled on TMs and `ItemUseCB_AbilityCapsule` (`src/party_menu.c:5031`), and a compatibility check. An AM is compatible if its ability is in `learnableAbilities` or the species has `learnsAllAMs`.
4. **Shared helpers:**
   - `GetMonRememberedAbilities(mon, out)` returns the memory bitmask entries, or the whole list plus every AM ability for `learnsAllAMs` species. The relearner uses it.
   - `GetMonCrossTrainableAbilities(mon, out)` returns the remembered abilities plus the mon's **current natural ability**. Changing the natural ability with a Capsule or Patch removes the old one from this set. Cross-training and tutors use it.
5. **Cross-training from the PC:** a source mon from the helper above → a compatible target. Free for the player's own mons, and the **source isn't changed**.
6. **Ability tutors:** NPCs who own the source mon, with a price. Gym-leader rematch cross-training is part of this.
7. **Ability relearner:** an NPC that lists `GetMonRememberedAbilities`. For Mew, that's its whole list plus every AM ability.
8. **Scripted learned abilities:** a `givemon`/wild-battle script option for story encounters with a learned ability, and a `Learned Ability:` key in `tools/trainerproc` for trainer parties.
9. Every teaching path enforces `cantBeDoubled`.

## Milestone 5: AI (first pass)
A first integration of the dual-ability system into the battle AI. The goal is that the AI understands a battler can have two abilities, not that it plays well with them. Tuning the AI's behavior comes later, alongside the story work.
- Add learned-ability fields to `AI_SavedBattleMon`, `AiPartyMon` and the ability history in `battle_ai_record.c`.
- Update ability prediction and "known ability" tracking to cover two slots.
- Switch the score modifiers that check abilities to the slot-aware helpers.
- `test/battle/ai/` still passes, plus a few dual-ability sanity tests, e.g. the AI doesn't use Ground moves into a learned Levitate.

## Milestone 6: Story and content (after the plot rewrite)
Doubles by default (trainers, wild encounters, the one-mon edge case), trainer teams with learned abilities, real ability lists and Mega/Primal learned abilities, AM placement coordinated with which abilities can be obtained, the Latios/Latias/Jirachi story, unlocking Mega Evolution, further AI tuning, and turning off Z-moves, Dynamax and Tera in config.

---

## Open design questions

**Decided:**
- Each species' list holds at most 8 entries, to fit the memory bitmask in the free save bits. `BoxPokemon` stays 80 bytes to protect PC storage space. Mew, and any species added to it later, uses `learnsAllAMs` instead.
- A `learnsAllAMs` species can act as a cross-training source for every AM ability. That's fine, because these species aren't available until after the main story.
- Signature abilities are kept out by the data, not by a flag (see 1.3).
- An empty learned slot shows "None" on the summary screen.
- Evolved forms' lists are right-supersets of their pre-evolution's list.
- Mega Evolution and Primal Reversion overwrite both slots, and each such form has a fixed `fixedLearnedAbility`.
- Forms linked by out-of-battle form changes (Rotom, Shaymin, Hoopa, ...) share identical lists.
- The same ability in both slots is allowed. A `cantBeDoubled` flag on each ability, initially set for unswappable and unsuppressable abilities, forbids it case by case.
- When both slots trigger on the same event, the natural slot goes first.
- Cross-training leaves the source unchanged. The memory only records learned abilities. A mon can pass on its memory plus its current natural ability.
- Illusion: already can't be copied, and it isn't on any list. Ability Shield protects both slots. Truant twice acts like one Truant. Neutralizing Gas works from either slot and never stacks.
- AMs live in the TM/HM pocket.

**Open:**
- Nothing for Milestone 1. New questions will be added here as later milestones come up.
