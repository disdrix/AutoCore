# Dual A/B report — W20-N OWN-ONLY (`0x004ba770`, `0x006170b0`)

**Date:** 2026-07-29  
**Agent:** W20-N  
**Scope:** OWN VAs only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. No `disassemble_bytes`.  
**Program:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | VA | Canonical | Verdict |
|------|-----|-----------|---------|
| `aa_004ba770` | `0x004ba770` | `StdMap_FreeSubtree_Isnil15_Inferred` | **accept-with-gaps** — left-walk free sealed by bytes |
| `aa_006170b0` | `0x006170b0` | `Skill_HB_SpawnEntities_Precheck_Inferred` | **accept-with-gaps** — precheck returns + vtbl+0x1c sealed |

---

## `0x004ba770` — StdMap_FreeSubtree_Isnil15_Inferred

### Sealed facts

1. Stack `node*`, **`ret 4`**; ECX threaded unused.  
2. **isnil @ `+0x15`**; right `@+8`; left `@+0`.  
3. Algorithm: recurse free right → `operator_delete` self → walk left until isnil.  
4. Decompiler omits left-walk and falsely marks delete noreturn — **bytes override**.  
5. Callers: `StdMap_EraseRange_Inferred` (`0x004bacf0`), `NDSpecialFX_ClearChildLists_Inferred` (`0x004b85d0`), self.

### Gaps

- Product STL mangled name.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004ba770_StdMap_FreeSubtree_Isnil15_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004ba770_StdMap_FreeSubtree_Isnil15_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004ba770_FUN_004ba770.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FreeSubtree_Isnil15_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004ba770.cpp` |
| Raw | `docs/reconstruction/raw/aa_004ba770_FUN_004ba770.md` |
| Annotated | `docs/reconstruction/raw/aa_004ba770_FUN_004ba770.annotated.md` |

---

## `0x006170b0` — Skill_HB_SpawnEntities_Precheck_Inferred

### Sealed facts

1. Two stack args, **`ret 8`**; virtual at **`PTR_FUN_009d0ec4 + 0x1c`** (`0x009d0ee0`).  
2. Sibling Execute: **vtbl+0x2c** `Skill_HB_SpawnEntities_Execute_Inferred` (`0x00615020`).  
3. Returns **0 / 2 / 8 / 0x10** (bytes seal epilogues; decompiler noreturn residual false).  
4. Gates: RTTI creature; skill float `+0x16c` = **100.0f** skip / **0.0f** total-cap via `FUN_004c2e60` vs `FUN_004c3f10(0)`.  
5. Histogram of summon keys; fail **8** when key `skill+0x14c` count ≥ `u8 skill+0xda` — FormatFailure “too many of that summon.”  
6. Constants: `DAT_00aaa7ac` = 100.0f; `g_flZero` = 0.0f.

### Gaps

- Product class English name (`PTR_FUN_009d0ec4`).  
- Product name of histogram key field.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_006170b0_Skill_HB_SpawnEntities_Precheck_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006170b0_Skill_HB_SpawnEntities_Precheck_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_006170b0_FUN_006170b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_SpawnEntities_Precheck_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_006170b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_006170b0_FUN_006170b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006170b0_FUN_006170b0.annotated.md` |

---

## AutoCore impact

- **Map teardown:** full clear paths must free both right and left spines (`004ba770`); do not trust decompiler single-child free.  
- **HB spawn precheck:** cast UI must honor return **8** (per-type summon limit) and **0x10** (total cap) separately from Execute; skill float `+0x16c` = 100 skips precheck math.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`004ba770`, `006170b0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` (no `disassemble_bytes`) | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
