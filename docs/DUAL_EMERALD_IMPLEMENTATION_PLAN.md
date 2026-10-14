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

**Placeholder content.** (Update, 2.4: the placeholder `fixedLearnedAbility` is **Honey Gather** for every Mega/Primal form. It has no battle effect, so placeholder data doesn't change battles or break upstream tests that use Mega forms. Real values come with content work.) Write a one-time script (in `tools/` or `dev_scripts/`) that generates the lists and adds the `.learnableAbilities` and `.fixedLearnedAbility` lines. Content doesn't matter for this milestone, but the structure does, so the script:
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

## Milestone 2: Battle engine core (learned abilities take effect) ✅ Complete, tagged `v0.2-learned-abilities-in-battle`

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

### 2.4 Direct comparisons ✅
- `GetBattlerAbility(b) == ABILITY_X` → `BattlerHasAbility` (38 sites).
- Cached-array comparisons (`ctx->abilities[b] == ABILITY_X`, etc.) → `AbilityOrLearned` (79 sites).
- Ability variables and parameters paired with their battler → `AbilityOrLearned` (94 sites in 46 functions). Excluded: `AbilityBattleEffects` and the weather-setting helpers, which receive *the ability that fired* and belong to 2.5; and `IsMoldBreakerTypeAbility`, which is already called once per slot.
- `IsAbilityAndRecord` checks the learned slot, which covers Magic Guard and similar checks everywhere.
- Added a battler parameter to `IsSheerForceAffected`, `GetAttackerWeather` and `CanMoveThawTarget`. Shield Dust uses `gBattlerTarget`.
- Heal Bell/Aromatherapy: a benched mon's stored learned Soundproof counts.
- **Performance:** `AbilityOrLearned` is inline, and the common case is one comparison against the raw learned slot. The AI thinking-time tests failed on the first attempt and pass now.
- **Safety:** learned slots are never read outside battle (`gBattleStruct == NULL`), nor while evaluating a party or overworld mon through a placeholder battler (`gIgnoreLearnedAbilities`, set by `CalcPartyMonTypeEffectivenessMultiplier` and `GetDynamicMoveType` for mons not in battle).
- `else if` chains (e.g. `GetBattlerTotalSpeedStat`) currently apply the first matching slot. 2.6 restructures them so effects stack.
- Tests in `test/battle/dual_ability/direct_checks.c` (10).

### 2.5 Trigger dispatch ✅
- **Helpers** (`battle_util.c`): `TryAbilityEffectsBySlot` and `TryEachAbilitySlot` fire one slot per call, natural first. They keep a cursor per state machine in `eventState` (switch-in, move end, end of turn), so the caller returns to the same step for the next slot after the first slot's script runs. They only wait for another slot if that slot holds an ability, so behavior with an empty learned slot is unchanged. `TryAbilityEffectsAnySlot` is for events the caller re-polls anyway (status immunity cures).
- **Script commands** use `TryScriptAbilitySlots`. The fired ability's script returns to the command, which resumes at the next slot. Pending commands are keyed by address, battler and battle-script stack depth (`gBattleStruct->pendingScriptAbilitySlots`), so nested commands of the same kind don't interfere.
- Converted: switch-in events, move end (contact abilities, form change on hit, attacker effects, Moxie-style, Color Change, Opportunist, immunity), end of turn (weather abilities, first and third ability blocks, Opportunist), the weather/terrain/Wind Rider/switch-in/form-change script commands, Defiant/Competitive/Rattled, Cloud Nine/Air Lock, Unnerve, the Dazzling-type priority blockers, and stat-drop prevention (which names the blocking slot).
- Removed `AbilityBattleEffects`' natural-ability re-reads in the weather and terrain cases.
- **Two absorbing abilities** (e.g. Water Absorb + Storm Drain vs. Water Gun): both effects run, natural first, via `BattleScript_DualAbilityAbsorb` and the `trydualabsorbslot` native. Each slot's effect is prepared just before its script runs.
- Fixed a 2.4 conversion inside `BS_TryDefiantRattled`'s ability switch that could raise the wrong stat.
- **Performance:** `AI_FRAME_CEILING_DOUBLES_NO_FLAGS` in `test/battle/ai/ai_thinking_time.c` raised from 14 to 15. Upstream's ceilings equal the measured values with no headroom; the cumulative learned-slot checks add about one frame there. The other ceilings still hold.
- Not converted, because they only matter for signature form-change abilities that can't be learned: `HandleEndTurnFormChange`, `Cmd_tryselfconfusiondmgformchange`. Two -ate abilities in both slots (`TrySetAteType`) use the first match.
- **Popups name the ability that fired.** Trigger sites outside `AbilityBattleEffects` set `gLastUsedAbility` explicitly: Emergency Exit/Wimp Out, Truant, Steadfast, Protean/Libero, Liquid Ooze, Magic Bounce, Sticky Hold, Suction Cups, Pickpocket, Cheek Pouch, Ripen, Booster Energy, Aroma Veil, Mirror Armor, and `jumpifabilitypresent`. Otherwise a learned ability that fired earlier could leave a stale `gLastUsedAbility` behind and mislabel a later natural popup.
- Design doc, *Foreseen Interactions*: an ability that switches its holder out doesn't stop the learned ability from triggering on the same attack (Emergency Exit + learned Flame Body), and there's a test for it.
- Tests in `test/battle/dual_ability/triggers.c` (18).

### 2.6 Damage, speed, accuracy and crit modifiers ✅
- **Modifiers that multiply stack, including doubled abilities.** Each `switch (ability)` modifier block became a per-slot helper that runs for the natural slot, then the learned slot: base power (attacker, attacker's partner, target), attack and defense stats (attacker, target, partners), final damage (Sniper/Tinted Lens/Neuroforce, Multiscale/Filter/Fluffy and so on, Friend Guard), speed, and accuracy (Compound Eyes, Hustle, Sand Veil and so on, ally Victory Star). For example, Huge Power + Hustle is 3x, Huge Power twice is 4x and Swift Swim twice is 4x.
- **Abilities that set or negate something apply once** (user's ruling): Adaptability sets STAB to 2x, so two copies still give 2x. Guts twice gives two 1.5x boosts but cancels the burn drop only once. These were already single checks (`AbilityOrLearned`).
- **Counted per slot:** Super Luck (+1 crit stage each, or x4 each under Gen 1 rules), Serene Grace (x2 each), Heavy Metal/Light Metal (x2 or /2 each).
- **Priority bonuses don't stack** (user's ruling: moves are designed around priority brackets). A move gets the largest bonus that applies from Gale Wings, Prankster, Triage or Grassy Glide, so Prankster + Gale Wings Tailwind is +1. Prankster's Dark-type immunity still applies to the holder's status moves even when another ability gives the same or a larger boost (user's ruling: players think of it as "Prankster status moves fail on Dark types"), e.g. Prankster + Gale Wings Feather Dance fails on a Dark type. The ability checks come first in `GetBattleMovePriority`, which is hot in AI thinking time.
- **Fixed:** Dark Aura/Fairy Aura/Aura Break in a learned slot weren't seen (`DmgCalc_IsAbilityOnField`). Plus/Minus now see the partner's learned slot.
- Booster Energy still boosts a mon whose paradox ability is gone, as upstream does.
- Deferred to 2.7: Simple and Contrary (stat-change modifiers), and the switch-out, `RemoveAbilityFlags` and immunity-cure switches.
- **AI records:** `RecordAbilityBattle` can record a learned ability as if it were the natural one. Revisit in Milestone 5.
- **Performance.**
  - `gBattleHasLearnedAbilities` is set wherever a learned ability is written to `gBattleMons` and cleared when battle resources are allocated. While it's FALSE, `AbilityOrLearned` and `GetLearnedAbilityForCalc` return at once.
  - The Makefile raises GCC's `max-inline-insns-single` for `battle_util.o` only. The added code had pushed hot inline helpers in that file over the default limit, so they were called out of line. That cost about 1.5% of AI thinking time (measured in CPU cycles), enough to break upstream's zero-headroom frame ceilings.
  - With the setting, the AI thinking-time tests run slightly faster than before 2.6 (doubles, smart: 8.27M cycles vs 8.28M), and all ceilings hold, including `AI_FRAME_CEILING_DOUBLES_NO_FLAGS` at 15 from 2.5.
- Tests in `test/battle/dual_ability/modifiers.c` (18): Huge Power + Hustle, Huge Power twice, Technician + Sheer Force, Adaptability + Tough Claws, Adaptability twice, Guts twice while burned, Multiscale + Shadow Shield, learned Thick Fat, Swift Swim twice, Chlorophyll + Unburden, Super Luck twice, Prankster + Gale Wings (no stacking; Dark-type immunity kept), Prankster + Triage, Battery + Power Spot on a partner, Friend Guard twice on a partner, learned Dark Aura, and Plus with a partner's learned Minus.

### 2.7 Remaining sites and duplicates ✅
- **Contrary and Simple** (user's rulings): Contrary in both slots cancels out (an odd number of Contrary slots inverts). This could be a counter to a strong Contrary foe. Simple doubles the change once per slot, so 4x with two (may be reined in later for balance). `CompareStat` counts Contrary across both live slots; callers pass `ABILITY_NONE` to ignore Contrary, as upstream does.
- **Status cures:** learned Immunity, Limber, Insomnia, Own Tempo, Oblivious and so on now cure their status. `TryImmunityAbilityHealStatus` read only the natural slot.
- **Switch-out:** Natural Cure and Regenerator apply from each slot, natural first. Regenerator twice heals 1/3 twice. `switchoutabilities` waits for the controller between slots (`BattleScript_SwitchOutAbilityWait`, using the 2.5 pending-slot mechanism).
- **Intimidate blockers** (Inner Focus, Own Tempo, Oblivious, Scrappy, Guard Dog) check each slot, natural first.
- **Lightning Rod / Storm Drain redirection** in doubles now sees learned slots.
- **Neutralizing Gas leaving:** a battler is skipped only if neither slot can be reactivated. Otherwise only the slot that can be reactivated runs, so natural Imposter + learned Intimidate gives Intimidate but not Imposter.
- Smaller sites: Quick Draw, Oblivious vs. Attract, the Gorilla Tactics choice lock, paradox stat resets, post-battle Pickup/Honey Gather, the Sky Battle Levitate check, and popups for Symbiosis, Sticky Hold and Quick Draw.
- **Messages** that print a battler's ability name (`{B_ATK_ABILITY}` and so on) use `GetBattlerPopupAbility`, the same rule as popups.
- **Battle debug menu:** a "Learned Ab." entry views and edits the learned slot. Battle TV needed no changes.
- **`cantBeDoubled`** added to `struct AbilityInfo` and set on the 31 abilities with `cantBeSwapped` or `cantBeSuppressed` (Zen Mode follows its config expression). Nothing enforces it yet; Milestone 4's acquisition rules will. A doubled Stance Change runs a battle without problems.
- Ability-*writing* effects (Skill Swap, Trace, Mummy, Transform and so on) still write the natural slot until Milestone 3 gives each its rule. `RemoveAbilityFlags` also stays natural-only for now: if both slots hold Flash Fire and the natural one is overwritten, the boost is cleared.
- Tests in `test/battle/dual_ability/remaining_sites.c` (13).

### 2.8 Tests and wrap-up ✅
- Basic tests: learned Intimidate, stacking, natural-first order and Mega/Primal overwrite were already covered by earlier stages. Added: learned Levitate, learned Klutz, and Ability Shield protecting the learned slot against Neutralizing Gas and Mold Breaker (`direct_checks.c`).
- **Robustness sweep** (`robustness.c`): every ability (318) as the learned ability of every battler, in a singles and a doubles AI battle (smart AI) of three turns. Behavior isn't checked, only that the battle runs. The player's side uses Celebrate because scripted attacks can become illegal choices under abilities such as Gorilla Tactics or Cursed Body. The sweep found:
  - **Crash: learned Klutz** caused infinite recursion. `GetBattlerHoldEffectIgnoreAbility` passed `ABILITY_NONE` to mean "ignore Klutz", but the learned-slot Klutz check reads the learned slot, which checks for an Ability Shield through that same function. Ignoring the ability now skips Klutz explicitly.
- **Popups naming the natural ability instead of the learned one that acted.** Fixed for Levitate/Eelevate, Wonder Guard/Telepathy, Overcoat (powder moves), the status blockers in `CanSetNonVolatileStatus` (Immunity, Limber, Water Veil/Water Bubble, Thermal Exchange, Vital Spirit/Insomnia, Magma Armor, Comatose/Purifying Salt, Leaf Guard, Shields Down), and end-of-turn Emergency Exit/Wimp Out. A parametrized test covers four status blockers.
- The AI still reads the natural slot until Milestone 5; the robustness sweep runs the smart AI against every learned ability without problems.

## Milestone 3: Ability-interaction rules ✅ Complete, tagged `v0.3-ability-interactions`

**Decisions beyond the design doc** (user, 2026-10-14):
- Mummy/Lingering Aroma in the learned slot fills an attacker's *empty* learned slot.
- Power of Alchemy/Receiver copies exactly, empty slots included (like Imposter); a slot holding an uncopyable ability keeps the holder's own ability.
- Gastro Acid, Core Enforcer, Simple Beam and Worry Seed affect the learned slot when the natural ability is a signature (unsuppressable or unoverwritable) ability, instead of failing.
- Simple Beam and Worry Seed fill an empty learned slot, even on single-ability Pokémon.
- Learned Trace picks uniformly from every non-empty, traceable ability in any foe's slots.
- Transform and Imposter already copy the learned slot: `learnedAbility` sits before `pp` in `struct BattlePokemon`, and Transform copies everything up to `pp`.
- In-battle changes to either slot are never written back to the party, so they end on switch-out or at the end of battle.

**Stages:**
- 3.1 ✅ Tests for rules that already hold (`rule_mold_breaker.c`, `rule_neutralizing_gas.c`, `rule_transform.c`, `rule_natural_only_moves.c`; 17 tests): the Mold Breaker family ignores both slots (Mold Breaker/Teravolt/Turboblaze, Mycelium Might on status moves, Propeller Tail/Stalwart vs. redirection); Neutralizing Gas suppresses all foe slots and its holder's other slot, ends when a double holder leaves, and persists while another holder remains; Transform and Imposter (natural or learned) copy both slots, empty included, and the original slots return on switch-out; Skill Swap, Role Play, Entrainment and Doodle touch natural slots only. Signature immunity and Illusion are tested with the stages that change those effects. Test files live at `test/battle/dual_ability/rule_*.c` because the Makefile only collects tests up to three directories deep.
- 3.2 ✅ Gastro Acid / Core Enforcer (`rule_gastro_acid.c`, 5 tests). Both go through `setgastroacid`, which now fails only if neither slot can be suppressed. With a signature natural ability, the learned slot is suppressed and the signature ability keeps working. Baton Pass likewise keeps a passed Gastro Acid while either slot can be suppressed.
- 3.3 ✅ Simple Beam / Worry Seed (`rule_simple_beam.c`, 7 tests). They overwrite the natural slot; if it already holds the new ability or is a signature ability, they overwrite the learned slot instead. An empty learned slot gains the new ability (user's ruling), so they work where vanilla's fail: e.g. Simple Beam gives a wild Mimikyu (Disguise) a learned Simple. Upstream tests in `overwrite_ability.c` and `zero_to_hero.c` were rewritten to expect this, marked "Dual Emerald". They fail only if the learned slot already holds the new ability or a signature ability. Supporting changes:
  - `RemoveAbilityFlags` keeps flags the learned slot still needs. The new `RemoveLearnedAbilityFlags` does the same for the learned slot, and `RemoveRuinAbilityFlags` covers both slots.
  - The new `SetBattlerLearnedAbility` writes the in-battle learned slot.
  - When a learned Neutralizing Gas is overwritten, the gas-exit sequence restores the learned slot rather than the natural one (`battlerState.learnedNeutralizingGasRemoved`, `learnedAbilityReplacement`).
- 3.4 ✅ Mummy / Lingering Aroma (`rule_mummy.c`, 6 tests). They replace the attacker's ability in the same slot as the target's, and a learned one fills an empty learned slot. As before, they don't replace Mummy, Lingering Aroma or a signature ability. Natural and learned copies each act on their own slot.
- 3.5 ✅ Wandering Spirit (`rule_wandering_spirit.c`, 4 tests). It swaps the abilities in the same slot as the target's, and fails if the attacker's slot is empty or holds an ability that can't be swapped.
- Supporting changes:
  - The slot dispatchers record the slot whose ability is running in `gBattleStruct->firingAbilitySlot` (natural otherwise).
  - Learned-slot variants of the Mummy and Wandering Spirit scripts use the new `setlastusedabilitytolearned` command, so popups and messages name the learned slots.
- 3.6 ✅ Power of Alchemy / Receiver (`rule_receiver.c`, 5 tests). They copy both slots of the fainted ally exactly, and an empty learned slot copies as empty. A slot whose ally ability can't be copied keeps the receiver's own ability. They activate only if there's a non-empty ability to copy. `settracedability` now writes the slots chosen in `gBattleStruct->tracedSlots`, with the learned value in `tracedLearnedAbility`. Illusion test included: neither Receiver nor Role Play can copy it.
- 3.7 ✅ Trace (`rule_trace.c`, 6 tests). Natural Trace is unchanged: it copies a foe's natural ability into the natural slot. Learned Trace (`TryLearnedTrace`) picks uniformly from every non-empty, traceable ability in all foes' slots and copies it into the learned slot. It has its own `learnedTraceActivated` volatile, so natural and learned Trace both activate.
- 3.8 ✅ Truant twice (`rule_truant.c`). With Truant in both slots, only one slot toggles the shared `truantCounter`; before, the two toggles cancelled and the holder never loafed.
- Signature-ability immunity is tested within each rule's file: Gastro Acid, Simple Beam, Mummy, Wandering Spirit (cantBeSwapped) and Receiver (cantBeCopied).

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
- Known gap from Option A: when the AI predicts damage or immunities, it reads the target's **live** learned slot. It doesn't apply its own Mold Breaker sanitizing (`AI_GetMoldBreakerSanitizedAbility`) to that slot, and it knows learned abilities it hasn't seen yet.
- `test/battle/ai/` still passes, plus a few dual-ability sanity tests, e.g. the AI doesn't use Ground moves into a learned Levitate.
- **Revisit performance here, or in a dedicated optimization pass if that comes first** (user's request):
  - The Makefile's `--param max-inline-insns-single=1000` for `battle_util.o` (added in 2.6): decide whether to keep it, tune it, or replace it with targeted changes.
  - Any raised `AI_FRAME_CEILING_*` values in `test/battle/ai/ai_thinking_time.c`; `AI_FRAME_CEILING_DOUBLES_NO_FLAGS` is 15, raised from 14 in 2.5.
  - `RecordAbilityBattle` can record a learned ability as the natural one (2.6).

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
