# Annotated low-level: Skill_FilterTargetForResolveList_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0054ff00` |
| VA | `0x0054ff00` |
| Canonical name | `Skill_FilterTargetForResolveList_Inferred` |
| Prior | `FUN_0054ff00` |
| System | skills-abilities |
| Date | 2026-07-29 |
| Residual | `tmp/a_0054ff00.md` (OR sites machine-sealed) |

## Machine-level notes

- **Sole caller:** `Skill_ResolveTargetList` (`0x00550300`) — first candidate filter after `CVOGReaction_ResolveObjectTarget`.
- Formals (thiscall): `this` = skill runtime; `param_2` = candidate target (may be null); `param_3` = caster; `param_4` = `uint* outFlags` (stack slot `[ESP+0x30]` at OR sites).
- Epilogue: **`RET 0x0C`** (`C2 0C 00`) after reject paths — Confirmed.
- **outFlags writers sealed here** (answers skills open Q "who ORs bits 4 and 8"; also seals **0x10**):

| Bit | OR insn VA | Bytes | Gate |
|----:|-----------:|-------|------|
| **8** | `0x0054ff72` | `83 08 08` | `vtbl+0x198` true while skill `+0x615` bit2 (Remains) clear |
| **0x10** | `0x0055007c` | `83 08 10` | type ∉ `{0xe, 0x12, 0x14}` (SUB 0xe / 4 / 2 chain @ `0x00550065`+) |
| **4** | `0x005502c1` | `83 08 04` | `LAB_005502bd` fallthrough + early gotos |

- Exactly **three** outFlags OR stores (pcode INT_OR = 3). No bits 1/2.
- Returns accepted target pointer or null; ResolveTargetList then range-checks via `Skill_RangeCheckTargetForResolveList_Inferred` and may OR bit **2** for range.

## outFlags bit map (this unit)

| Value | When set | ResolveCastTarget UX (caller) |
|------:|----------|-------------------------------|
| 4 | filter reject fallthrough | invalid TFID / format fail 0xe / self-target fallback / hardpoint branch |
| 8 | remains/dead-like reject (Remains flag clear) | format fail code 3 |
| 0x10 | type not creature-like `{0xe,0x12,0x14}` | (not directly named in ResolveCastTarget sample) |

## Open questions

- Product names of `vtbl+0x198` / `+0x1d4` / `+0x298`.
- Whether `0x10` is consumed by any player UX path.
- Full English of every `skill+0x614` / `+0x615` targeting flag bit (tooltip pairing High for bits used here).
