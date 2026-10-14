#!/usr/bin/env python3
"""
One-time generator for Dual Emerald's placeholder learnable-ability data.

Writes src/data/pokemon/learnable_abilities.h and adds `.learnableAbilities` (every species)
and `.fixedLearnedAbility` (Mega and Primal forms) to src/data/pokemon/species_info/gen_*_families.h.

The placeholder lists follow the structural rules in docs/DUAL_EMERALD_IMPLEMENTATION_PLAN.md (1.3):
- Species that share a formChangeTable, or are built by the same species-info macro, share one list.
  This covers out-of-battle form changes and gives Mega/Primal forms their base form's list.
- An evolution's list starts with its pre-evolution's list, entry for entry (right-superset rule).
- At most DE_MAX_LEARNABLE_ABILITIES entries, no duplicates, nothing with cantBeSwapped.

This is not part of the build. After it runs once, the generated data is maintained by hand.

Usage: python3 dev_scripts/dual_emerald/generate_learnable_abilities.py [--dry-run]
"""

import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SPECIES_DIR = ROOT / "src/data/pokemon/species_info"
GEN_FILES = [SPECIES_DIR / f"gen_{n}_families.h" for n in range(1, 10)]
ABILITIES_FILE = ROOT / "src/data/abilities.h"
FORM_CHANGE_FILE = ROOT / "src/data/pokemon/form_change_tables.h"
ALL_AMS_SPECIES = ["SPECIES_MEW"]
OUTPUT_FILE = ROOT / "src/data/pokemon/learnable_abilities.h"
MAX_ENTRIES = 8
FALLBACK_ABILITY = "ABILITY_RUN_AWAY"

ENTRY_RE = re.compile(r"^    \[(SPECIES_\w+)\]\s*=\s*(.*?)\s*$")
DEFINE_RE = re.compile(r"^\s*#\s*define\s+(\w+)(\(([^)]*)\))?")
ABILITIES_RE = re.compile(r"\.abilities\s*=\s*\{([^}]*)\}")
FORM_CHANGE_RE = re.compile(r"\.formChangeTable\s*=\s*(\w+)")


def parse_unswappable_abilities():
    unswappable = set()
    current = None
    for line in ABILITIES_FILE.read_text().splitlines():
        m = re.match(r"^    \[(ABILITY_\w+)\]\s*=", line)
        if m:
            current = m.group(1)
        elif current and re.search(r"\.cantBeSwapped\s*=\s*(?!FALSE\b)", line):
            # Counts config-dependent values (e.g. B_UPDATED_ABILITY_DATA >= GEN_7) as unswappable.
            unswappable.add(current)
    return unswappable


class CondStack:
    """Tracks the preprocessor condition that applies to each line."""

    def __init__(self):
        self.frames = []  # each: [previous branch exprs, current expr]

    def feed(self, line):
        s = line.strip()
        m = re.match(r"#\s*(ifdef|ifndef|if|elif|else|endif)\b\s*(.*)", s)
        if not m:
            return False
        kind, expr = m.group(1), re.sub(r"\s*//.*$", "", m.group(2)).strip()
        if kind == "ifdef":
            self.frames.append([[], f"defined({expr})"])
        elif kind == "ifndef":
            self.frames.append([[], f"!defined({expr})"])
        elif kind == "if":
            self.frames.append([[], expr])
        elif kind == "elif":
            frame = self.frames[-1]
            frame[0].append(frame[1])
            frame[1] = expr
        elif kind == "else":
            frame = self.frames[-1]
            frame[0].append(frame[1])
            frame[1] = None
        elif kind == "endif":
            self.frames.pop()
        return True

    def current(self):
        parts = []
        for previous, expr in self.frames:
            if expr is not None and "__INTELLISENSE__" in expr:
                continue
            parts += [f"!({p})" for p in previous]
            if expr is not None:
                parts.append(f"({expr})")
        return tuple(parts)


def split_top_level(text, sep=","):
    parts, depth, cur = [], 0, ""
    for ch in text:
        if ch in "({":
            depth += 1
        elif ch in ")}":
            depth -= 1
        if ch == sep and depth == 0:
            parts.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        parts.append(cur)
    return [p.strip() for p in parts]


def parse_form_change_targets():
    """Maps each form change table to the species it can change into."""
    targets = defaultdict(set)
    current = None
    for line in FORM_CHANGE_FILE.read_text().splitlines():
        m = re.match(r"^static const struct FormChange (\w+)\[\]", line)
        if m:
            current = m.group(1)
        elif current:
            mm = re.match(r"^\s*\{\s*FORM_CHANGE_\w+\s*,\s*(SPECIES_\w+)", line)
            if mm:
                targets[current].add(mm.group(1))
    return targets


def strip_preprocessor(body):
    return "\n".join(l for l in body.splitlines() if not l.strip().startswith("#"))


def evolution_targets(body):
    body = strip_preprocessor(body)
    targets = []
    for m in re.finditer(r"\.evolutions\s*=\s*EVOLUTION\(", body):
        depth, i = 1, m.end()
        while depth:
            depth += {"(": 1, ")": -1}.get(body[i], 0)
            i += 1
        inner = body[m.end():i - 1]
        for group in split_top_level(inner):
            group = group.strip()
            if group.startswith("{") and group.endswith("}"):
                fields = split_top_level(group[1:-1])
                if len(fields) >= 3 and fields[2].startswith("SPECIES_"):
                    targets.append(fields[2])
    return targets


def abilities_in(body):
    found = []
    for m in ABILITIES_RE.finditer(body):
        for tok in re.findall(r"ABILITY_\w+", m.group(1)):
            if tok != "ABILITY_NONE" and tok not in found:
                found.append(tok)
    return found


def substitute(body, params, args):
    for p, a in zip(params, args):
        body = re.sub(rf"\b{re.escape(p)}\b", a, body)
    return re.sub(r"\s*##\s*", "", body)  # token pasting, e.g. SPECIES_SPEWPA_##evolution


class Entry:
    def __init__(self, species, path, cond):
        self.species = species
        self.path = path
        self.cond = cond
        self.macro = None
        self.args = []
        self.open_line = None   # index of "    {" for literal entries
        self.close_line = None  # index of "    }," for literal entries
        self.body = ""


def parse_species_files():
    entries = {}
    macros = {}
    order = []
    for path in GEN_FILES:
        lines = path.read_text().splitlines()
        conds = CondStack()
        i = 0
        while i < len(lines):
            line = lines[i]
            if conds.feed(line):
                i += 1
                continue
            m = DEFINE_RE.match(line)
            if m:
                name = m.group(1)
                params = [p.strip() for p in (m.group(3) or "").split(",") if p.strip()]
                start = i
                while lines[i].rstrip().endswith("\\"):
                    i += 1
                body = "\n".join(lines[start:i + 1])
                body = body[m.end():] if start == i else body
                if name in macros:
                    # Alternative definition under another #if branch; keep the first.
                    i += 1
                    continue
                macros[name] = {"path": path, "params": params, "start": start, "end": i,
                                "body": body, "function_like": m.group(2) is not None}
                i += 1
                continue
            m = ENTRY_RE.match(line)
            if m:
                species, rest = m.group(1), m.group(2)
                entry = Entry(species, path, conds.current())
                if rest == "":
                    assert lines[i + 1].rstrip() == "    {", (path, i)
                    entry.open_line = i + 1
                    j = i + 2
                    while not re.match(r"^    \},?\s*$", lines[j]):
                        j += 1
                    entry.close_line = j
                    entry.body = "\n".join(lines[i + 2:j])
                    i = j
                else:
                    mm = re.match(r"(\w+)\s*(\((.*)\))?\s*,?$", rest)
                    assert mm, (path, i, rest)
                    entry.macro = mm.group(1)
                    entry.args = split_top_level(mm.group(3)) if mm.group(3) else []
                if species in entries:
                    # Alternative definitions under different #if branches; keep the first.
                    i += 1
                    continue
                entries[species] = entry
                order.append(species)
            i += 1
    for entry in entries.values():
        if entry.macro:
            macro = macros[entry.macro]
            entry.body = substitute(macro["body"], macro["params"], entry.args)
        entry.body = expand_macros(entry.body, macros)
    return entries, macros, order


def expand_macros(body, macros):
    """Expands macros defined in the species files (e.g. *_MISC_INFO(...), MEOWTH_ABILITIES)."""
    for _ in range(4):
        changed = False
        for name, macro in macros.items():
            if not re.search(rf"\b{name}\b", body):
                continue
            if macro["function_like"]:
                out, pos = "", 0
                for mm in re.finditer(rf"\b{name}\s*\(", body):
                    if mm.start() < pos:
                        continue
                    depth, i = 1, mm.end()
                    while depth and i < len(body):
                        depth += {"(": 1, ")": -1}.get(body[i], 0)
                        i += 1
                    args = split_top_level(body[mm.end():i - 1])
                    out += body[pos:mm.start()] + substitute(macro["body"], macro["params"], args)
                    pos = i
                    changed = True
                body = out + body[pos:]
            else:
                body = re.sub(rf"\b{name}\b", lambda _: macro["body"], body)
                changed = True
        if not changed:
            break
    return body


class UnionFind:
    def __init__(self):
        self.parent = {}

    def find(self, x):
        self.parent.setdefault(x, x)
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra != rb:
            self.parent[rb] = ra


def camel(species):
    return "".join(w.capitalize() for w in species[len("SPECIES_"):].split("_"))


def main():
    dry_run = "--dry-run" in sys.argv
    unswappable = parse_unswappable_abilities()
    entries, macros, order = parse_species_files()

    def is_flag(entry, flag):
        return re.search(rf"\.{flag}\s*=\s*TRUE", entry.body) is not None

    # Group species that must share one list.
    uf = UnionFind()
    by_table = defaultdict(list)
    by_macro = defaultdict(list)
    for sp in order:
        uf.find(sp)
        entry = entries[sp]
        for table in set(FORM_CHANGE_RE.findall(entry.body)):
            by_table[table].append(sp)
        if entry.macro:
            by_macro[entry.macro].append(sp)
    for members in list(by_table.values()) + list(by_macro.values()):
        for sp in members[1:]:
            uf.union(members[0], sp)
    form_change_targets = parse_form_change_targets()
    for table, members in by_table.items():
        for target in form_change_targets.get(table, ()):
            if target in entries and target != "SPECIES_NONE":
                uf.union(members[0], target)

    # Evolution edges between groups. A species with several pre-evolution groups
    # (e.g. Gholdengo from both Gimmighoul forms) needs those groups to share one list.
    while True:
        parents = defaultdict(set)
        for sp in order:
            for target in evolution_targets(entries[sp].body):
                if target in entries:
                    pg, cg = uf.find(sp), uf.find(target)
                    if pg != cg:
                        parents[cg].add(pg)
        conflicts = [ps for ps in parents.values() if len(ps) > 1]
        if not conflicts:
            break
        for ps in conflicts:
            ps = sorted(ps)
            for other in ps[1:]:
                uf.union(ps[0], other)

    groups = defaultdict(list)
    for sp in order:
        groups[uf.find(sp)].append(sp)

    # Representative: first non-Mega/Primal member in file order.
    def special(sp):
        e = entries[sp]
        return is_flag(e, "isMegaEvolution") or is_flag(e, "isPrimalReversion") or is_flag(e, "isGigantamax")
    rep_of = {}
    for root, members in groups.items():
        normal = [sp for sp in members if not special(sp)]
        rep_of[root] = (normal or members)[0]


    # Build lists parents-first.
    lists = {}
    visiting = set()

    def own_abilities(group):
        result = []
        for sp in groups[group]:
            if special(sp):
                continue
            for ab in abilities_in(entries[sp].body):
                if ab not in unswappable and ab not in result:
                    result.append(ab)
        return result

    def build(group):
        if group in lists:
            return lists[group]
        assert group not in visiting, f"evolution cycle at {group}"
        visiting.add(group)
        ps = sorted(parents.get(group, []), key=order.index)
        base = list(build(ps[0])) if ps else []
        for ab in own_abilities(group):
            if len(base) >= MAX_ENTRIES:
                break
            if ab not in base:
                base.append(ab)
        if not base:
            base = [FALLBACK_ABILITY]
        lists[group] = base
        visiting.discard(group)
        return base

    for group in groups:
        build(group)

    # Mega/Primal fixed learned ability: the group's first list entry.
    fixed = {}
    for sp in order:
        e = entries[sp]
        if is_flag(e, "isMegaEvolution") or is_flag(e, "isPrimalReversion"):
            fixed[sp] = lists[uf.find(sp)][0]

    print(f"species entries: {len(order)} ({sum(1 for e in entries.values() if e.macro)} via macros)")
    print(f"list groups: {len(groups)}; evolution edges between groups: {sum(len(p) for p in parents.values())}")
    print(f"Mega/Primal forms with fixed learned ability: {len(fixed)}")
    print(f"unswappable abilities excluded: {len(unswappable)}")
    print(f"groups using fallback: {sum(1 for l in lists.values() if l == [FALLBACK_ABILITY])}")
    if dry_run:
        return

    # Write the list file.
    name_of = {g: f"s{camel(rep_of[g])}LearnableAbilities" for g in groups}
    out = [
        "// Dual Emerald: learnable (AM-compatible) ability lists for each species.",
        "// Each list is ABILITY_NONE-terminated and holds at most DE_MAX_LEARNABLE_ABILITIES entries.",
        "// Rules (enforced by test/learned_ability.c):",
        "// - An evolution's list starts with its pre-evolution's list, entry for entry; new abilities go at the end.",
        "// - Species linked by a form change share one list.",
        "// - No ability with cantBeSwapped set may appear in a list.",
        "// Generated once by dev_scripts/dual_emerald/generate_learnable_abilities.py; edit by hand from now on.",
        "",
    ]
    for g in sorted(groups, key=lambda g: order.index(rep_of[g])):
        cond = entries[rep_of[g]].cond
        if cond:
            out.append(f"#if {' && '.join(cond)}")
        out.append(f"static const u16 {name_of[g]}[] = {{")
        for ab in lists[g]:
            out.append(f"    {ab},")
        out.append("    ABILITY_NONE,")
        out.append("};")
        if cond:
            out.append("#endif")
        out.append("")
    OUTPUT_FILE.write_text("\n".join(out))

    # Insert fields into literal entries (bottom-up per file so indices stay valid)
    # and into macro bodies.
    inserts = defaultdict(list)  # path -> [(line index, text)]
    needs_comma = defaultdict(set)  # path -> {closing line index}
    done_macros = set()
    for sp in order:
        e = entries[sp]
        g = uf.find(sp)
        if e.macro:
            if e.macro in done_macros:
                continue
            done_macros.add(e.macro)
            macro = macros[e.macro]
            # Find the macro (possibly nested) that holds the closing brace of the initializer.
            target = macro
            text = f"        .learnableAbilities = {name_of[g]},"
            close = target["end"]
            lines = target["path"].read_text().splitlines()
            while not re.match(r"^\s*\}\s*\\?\s*$", lines[close]) and close > target["start"]:
                close -= 1
            if close == target["start"]:
                # Body ends by expanding another macro; insert just after the opening brace instead.
                close = target["start"] + 1
                while not re.match(r"^\s*\{\s*\\\s*$", lines[close]):
                    close += 1
                close += 1
            width = len(lines[close - 1].rstrip()) if lines[close - 1].rstrip().endswith("\\") else 80
            inserts[target["path"]].append((close, text.ljust(max(width - 1, len(text) + 1)) + "\\"))
        else:
            text = [f"        .learnableAbilities = {name_of[g]},"]
            if sp in fixed:
                text.append(f"        .fixedLearnedAbility = {fixed[sp]},")
            if sp in ALL_AMS_SPECIES:
                text.append("        .learnsAllAMs = TRUE,")
            for t in reversed(text):
                inserts[e.path].append((e.close_line, t))
            needs_comma[e.path].add(e.close_line)
    for path, items in inserts.items():
        lines = path.read_text().splitlines()
        # The last field of an entry may lack a trailing comma (e.g. a multi-line EVOLUTION(...)).
        for close in needs_comma[path]:
            prev = close - 1
            while not lines[prev].strip() or lines[prev].strip().startswith("#"):
                prev -= 1
            if not re.search(r"[,{]\s*(//.*)?$", lines[prev]):
                lines[prev] = lines[prev].rstrip() + ","
        for idx, text in sorted(items, key=lambda x: x[0], reverse=True):
            lines.insert(idx, text)
        path.write_text("\n".join(lines) + "\n")
    print(f"wrote {OUTPUT_FILE.relative_to(ROOT)} and updated {len(inserts)} species files")
    for sp, ab in fixed.items():
        if entries[sp].macro:
            print(f"NOTE: macro-built Mega/Primal {sp} needs .fixedLearnedAbility = {ab} by hand")


if __name__ == "__main__":
    main()
