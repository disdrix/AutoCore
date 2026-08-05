# Function: Skill_SiblingCastClearPredicate_Inferred

| Field | Value |
|-------|-------|
| Stable ID | `aa_00512bb0` |
| VA | `0x00512bb0` |
| Canonical name | `Skill_SiblingCastClearPredicate` (**Inferred**) |
| Ghidra name | `Skill_SiblingCastClearPredicate_INFERRED` |
| Status | **full** (dual A/B sealed 2026-07-29) |
| System | `skills-abilities` |
| Verdict | **accept-with-gaps** |
| ABI | `__stdcall` `ret 0x0C`; `(pHb, pCtx, pStopUnused) → int 0\|1` |

## Role

Predicate callback for host HB list remove: match type-1 `CVOGHBSkillBase` by skillId + partial source TFID, or (flag≠0) type-8 `CVOGHBOKToCastAgain` by skillId; on match Stop via `vtbl+0x18(1,0)` and return remove.

## Body summary

| Arm | Gate | Match | Action |
|-----|------|-------|--------|
| `HB+0x1c==1` | always | `+0x620` skillId; TFID `@+0x658` partial (2 dwords + 1 byte) | Stop; return 1 |
| `HB+0x1c==8` | `ctx+0x18≠0` | `*(+0x24)+0x5fc` skillId | Stop; return 1 |

## Consumers (DATA xrefs)

- `0x00514e20` `Skill_SiblingCastClear` @ push `0x00514e5b`
- `FUN_00517400` @ push `0x00517520` (inlined list invoke, flag 0)

## Artifacts

- Dual: `reviews/A_aa_00512bb0_Skill_SiblingCastClearPredicate.md`, `B_aa_00512bb0_Skill_SiblingCastClearPredicate.md`
- Scratch: `reviews/a_00512bb0.md`
- Raw / annotated: `raw/aa_00512bb0_Skill_SiblingCastClearPredicate_Inferred(.annotated).md`
- Clean: `reconstructed-exact/Skill_SiblingCastClearPredicate_Inferred.cpp`
- Parent: `aa_00514e20` Skill_SiblingCastClear

## Gaps

1. Product demangled symbol.
2. Partial TFID English / unused tfid3.
3. `vtbl+0x18` product name.
4. Runtime / bit-exact.
