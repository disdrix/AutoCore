# Dual A/B report — MEGA-140 OWN-ONLY (`0x004280d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-140**  
**Scope:** VA `0x004280d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_xrefs_to` / `get_function_xrefs` + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000` (AA-decode).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-140**.  
**Work item:** Mega residual dual seal — scalar peer of dualed **CNDUIDialog_CompleteDtor** (`0x00792c20`).  
**Hint:** `CNDUIDialog_ScalarDeletingDtor`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004280d0` CNDUIDialog_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI CNDUIDialog/`RET 4`/false-noreturn sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-body / vector-dtor / always-free / cdecl-this / wrong-host / truncated-noreturn claims all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004280d0` — sealed facts

1. **Body:** `0x004280d0`–`0x004280ee` exclusive (**30 B** / `0x1E`); pad `CC CC` then next SEH prologue @ `0x004280f0`.
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for **CNDUIDialog**:
   - Always call complete dtor **`FUN_00792c20`** / `CNDUIDialog_CompleteDtor` (thiscall).
   - If `(flags & 1)`: `operator_delete(this)` @ `0x00489822`.
   - Return `this`.
4. **Classification:** worker (`analyze_function_complete`).
5. **Callers:** DATA only — dword @ `0x00a98f44` = `0x004280d0` (`PTR_FUN_00a98f44[0]`). No code CALL sites.
6. **Callees:** `FUN_00792c20`, `operator_delete`.
7. **RTTI:** dword @ `0x00a98f40` = COL `0x00ab7e6c` → type_info `0x00afe1c8` → **`.?AVCNDUIDialog@@`**.
8. **Name:** `CNDUIDialog_ScalarDeletingDtor` (Ghidra `FUN_004280d0`). Product demangle **sealed** (no `_Inferred`).
9. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: raw MEGA-140 append (30 B).

### Gaps

- Complete dtor body / owned-slot English not owned (`FUN_00792c20` dualed WQ9K-G).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004280d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004280d0_FUN_004280d0.md` |
| Function named | `docs/reconstruction/functions/aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` |

---

## Chain context (not dualled here; evidence only)

```text
PTR_FUN_00a98f44  CNDUIDialog primary vtbl
  [0] FUN_004280d0  CNDUIDialog_ScalarDeletingDtor  [OWN MEGA-140]
        └─ FUN_00792c20  CNDUIDialog_CompleteDtor  [dualed WQ9K-G]
              ├─ FUN_007917c0  child-hash teardown
              ├─ scalar-delete owned +0x4c0, +0x4c8..+0x4d8
              ├─ FUN_00415e90  list shell @ +0x4dc
              ├─ operator_delete member +0x4e0  (returns)
              └─ FUN_007b5be0  deeper window complete

FUN_00792d20  ctor peer installs same vtbl
FUN_0082d540  CVOGMenu complete → chains 00792c20
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004280d0-mega-140-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004280d0` | Port as **MSVC scalar-deleting dtor** for **CNDUIDialog**. **thiscall RET 4**. Always call complete `00792c20`; free host only if `flags & 1`. Return `this`. |
| Pair with | dualed complete `00792c20` / `CNDUIDialog_CompleteDtor`; vtbl `PTR_FUN_00a98f44`; RTTI `.?AVCNDUIDialog@@`. |
| Do not | Inline complete body into this VA; treat as vector-deleting; free host inside complete; invent skills-only product type for this address. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry entries when batch-merging MEGA duals  
- Link scalar `004280d0` ↔ complete `00792c20` as paired dtor units  
- Terminal remains **false** until runtime Confirmed policy is applied
