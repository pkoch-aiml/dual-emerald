# Dual Emerald: Implementation Plan

Companion to [DUAL_EMERALD_MASTER_DESIGN.md](DUAL_EMERALD_MASTER_DESIGN.md). Base: pokeemerald-expansion 1.17.2 (unreleased master).

## Guiding principles

- **Keep vanilla behavior when the learned slot is empty.** The ~300 existing ability tests in `test/battle/ability/` then work as a regression suite. `make check` must stay green at the end of every milestone.
- **Put changes behind one config header** ([include/config/dual_emerald.h](../include/config/dual_emerald.h)) where that's practical. This keeps upstream merges manageable and makes the diff easy to find.
- **Leave story content for later.** The plot will be rewritten, so trainer teams, wild-encounter tuning and doubles-by-default all come after the mechanics exist.

---

## Milestone 1: "Dual Slot Foundation" (first release) ✅ Complete, tagged `v0.1-dual-slot`

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

### 1.6 Release check ✅
- ✅ `make check` passes (5,431 passed; known-failing, expect-failing and to-do counts unchanged from the baseline), and a clean build boots.
- ✅ Manual pass, confirmed in the game: start a new game, play through the introduction, open the summary for the starter, press R and see the empty learned slot. Set a learned ability through debug and see the name and description appear. Save, reload and check that it's still set. Win a battle and check that it's still set. Box the mon and withdraw it. Evolve it (rare candy through debug) and check that it's still set.
- ✅ Tagged `v0.1-dual-slot`.

---

## Milestone 2: Battle engine core (learned abilities take effect)

Most of the engine assumes one ability per battler. Measured on 2026-10-13:

| Pattern | Count |
|---|---|
| `GetBattlerAbility*(...)` calls in `src/battle_*.c` | ~230 (most in `battle_script_commands.c`, `battle_util.c`, `battle_hold_effects.c`, `battle_end_turn.c`) |
| Reads of cached ability arrays (`ctx->abilities[...]`, `gAiLogicData->abilities[...]`, etc.) | ~620 |
| `.ability` direct accesses in `src/battle_*.c` | ~100 |
| `AbilityBattleEffects(...)` call sites | ~40 |
| Places that write a battler's ability (Skill Swap, Trace, Transform, form changes, ...) | ~25 |

The work is split into stages. Each stage builds, passes the full `make check`, and gets its own commit. Until a call site is converted, it keeps reading the natural slot only, so the game always works, just with partial learned-ability support.

### 2.1 Learned slot in battle ✅
- `struct BattlePokemon` gets `enum Ability learnedAbility`. It's filled from the party mon in `PokemonToBattleMon`, the controllers' `REQUEST_ALL_BATTLE`, and `CopyMonAbilityAndTypesToBattleMon` (used by form changes). All other paths copy those results.
- `GetBattleLearnedAbility(species, stored)`: Mega and Primal forms use their `fixedLearnedAbility`; everything else uses the stored learned ability. Battle code never writes the party mon's learned ability, so it comes back after battle.
- Test DSL: `LearnedAbility(x)` sets the party mon's learned ability. Any ability is allowed, even illegal ones.
- Tests in `test/battle/dual_ability/learned_slot.c`: the default is empty, the slot is set at battle start, it survives switching, switch-in uses the incoming mon's slot, Mega and Primal overwrite it, and other form changes keep it.

### 2.2 Slot-aware core ✅
- `enum BattlerAbilitySlot { BATTLER_ABILITY_NATURAL, BATTLER_ABILITY_LEARNED }`.
- `GetBattlerAbilityInSlot(battler, slot)` applies the existing suppression rules (`notOnField`, Gastro Acid, Neutralizing Gas, Mold Breaker, Ability Shield) to one slot, judged on that slot's own ability flags.
- `BattlerHasAbility(battler, ability)` (+ `...IgnoreMoldBreaker`): true if either slot has the ability.
- `GetBattlerAbility(battler)` keeps meaning "natural slot" during the migration, so unconverted call sites behave exactly as before.
- **Neutralizing Gas:** the slot holding Neutralizing Gas stays active, and every other slot on the field, including the holder's other slot, is suppressed (design doc, *Foreseen Interactions*). Abilities with `cantBeSuppressed` stay active as usual. Copy effects still see the raw slot.

### 2.3 Field-wide queries and Mold Breaker ✅
- `IsAbilityOnSide`, `IsAbilityOnField` and escape prevention (Shadow Tag, Arena Trap, Magnet Pull, plus the Run Away check) use `BattlerHasAbility`. `GetAbilityPreventingEscape(battler, &ability)` also reports *which* ability traps, so the message names the right one.
- Mold Breaker activation at move start checks both of the attacker's slots (`IsMoldBreakerTypeAbilityInEitherSlot`).
- Ability popups: `GetBattlerPopupAbility` names the learned ability when it is the one that just fired (`gLastUsedAbility`). Otherwise it names the natural ability, as before.
- Tests in `test/battle/dual_ability/field_queries.c`: learned Damp, a partner's learned Sweet Veil, learned Arena Trap (with the right ability name), learned Run Away, and learned Mold Breaker vs. Levitate.

**Approach for 2.4–2.6 (decided: Option A).** Function signatures and cached ability arrays stay single-ability. Wherever code compares a battler's ability to a specific ability, it also checks that battler's **current in-battle learned slot** through `GetBattlerAbilityInSlot` (after suppression, and including changes made during battle). Helpers:
- `BattlerHasAbility(battler, X)` where the code asks about a battler directly;
- `AbilityOrLearned(battler, ability, X)`, true if the passed-in ability is X or the battler's learned slot is X, where the code receives the ability as a parameter or reads a cached array.

The AI therefore sees real learned slots until Milestone 5. Pokémon not on the field (switch-in evaluation, party displays) use the party mon's stored learned ability, or the fixed one for Mega/Primal forms. This keeps the diff, and future upstream merges, small.

### 2.4 Direct comparisons
- Convert `GetBattlerAbility(b) == ABILITY_X` and `ability = GetBattlerAbility(b); ... ability == ABILITY_X` to `BattlerHasAbility`, file by file: hold effects, end of turn, move resolution, script commands, util.

### 2.5 Trigger dispatch
- `AbilityBattleEffects` callers loop over both slots, **natural first**.
- Events that track "already triggered", such as the switch-in ability, need state for each slot so both slots can fire, as with Intimidate + Drizzle.
- **Two immunities to one move** (e.g. Dry Skin + Storm Drain vs. Water Gun): both abilities' extra effects trigger (design doc, *Foreseen Interactions*).
- `gLastUsedAbility` and the popups name the slot that actually fired.

### 2.6 Damage, speed, accuracy and crit modifiers
- The `switch (ability)` modifier blocks run once per slot, using `AbilityOrLearned` or a per-slot loop. **Boosts from both slots stack by default**, including doubled abilities (design doc, *Foreseen Interactions*).
- Dedicated tests for multiplicative power-boost pairs (e.g. Huge Power + Hustle, Technician + Sheer Force, Adaptability + Tough Claws), and for doubles-specific combinations (auras, Battery/Power Spot, Friend Guard).

### 2.7 Remaining sites and duplicates
- Remaining `.ability` reads (messages, battle debug menu, battle TV).
- Add the `cantBeDoubled` flag to `struct AbilityInfo` (set for every ability with `cantBeSwapped` or `cantBeSuppressed`) and make sure a doubled ability doesn't crash.
- Ability-*writing* effects (Skill Swap, Trace, Transform and so on) keep writing the natural slot until Milestone 3 gives each one its rule.

### 2.8 Tests and wrap-up
- `test/battle/dual_ability/` gets basic tests: learned Intimidate, learned Levitate, stacking, natural-first order, Ability Shield covering both slots, and Mega/Primal overwrite (done in 2.1).
- **Robustness test:** give a battler an illegal learned ability, e.g. Stance Change on a non-Aegislash, run a few turns, and check that the battle finishes without crashing or asserting. The actual behavior doesn't matter.
- The AI keeps reading the natural slot until Milestone 5. The robustness tests make sure that doesn't crash.

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

- Neutralizing Gas: the holder's other slot is suppressed while it battles, but can still be copied or swapped, and keeps its overworld effects (design doc, *Foreseen Interactions*).
- Milestone 2 uses Option A: single-ability signatures plus checks of the current in-battle learned slot (see the approach before 2.4).
- Effects from both slots stack by default; two immunities to one move trigger both abilities' extra effects.

**Open:**
- Nothing right now.
