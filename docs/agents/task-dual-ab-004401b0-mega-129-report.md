# Dual A/B report — MEGA-129 OWN-ONLY (`0x004401b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-129**  
**Scope:** VA `0x004401b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callees/xrefs + multi-span `read_memory` + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-129**.  
**Work item:** residual dual seal — scalar peer of dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`).  
**Hint:** `gfxUIWindow_ScalarDeletingDtor`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004401b0` gfxUIWindow_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI gfxUIWindow/`RET 4`/false-noreturn sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-body / vector-dtor / always-free / cdecl-this / wrong-host / noreturn-truncate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004401b0` — sealed facts

1. **Body:** `0x004401b0`–`0x004401cd` inclusive (**30 B** / `0x1E`); pad `CC CC`; next @ `0x004401ce`.
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for **gfxUIWindow**:
   - Always call complete dtor **`FUN_00759de0`** / `gfxUIWindow_CompleteDtor` (thiscall).
   - If `(flags & 1)`: `operator_delete(this)` @ `0x00489822`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x00a9f304` = `0x004401b0` (`PTR_FUN_00a9f304[0]`). No code CALL sites.
6. **Callees:** `FUN_00759de0`, `operator_delete`.
7. **RTTI:** COL ptr @ `0x00a9f300` → COL `0x00ab96a4` → type_info `0x00afe190` → **`.?AVgfxUIWindow@@`**.
8. **Name:** `gfxUIWindow_ScalarDeletingDtor` (Ghidra `FUN_004401b0`). Product demangle **sealed** (no `_Inferred`).
9. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: `568bf1e8289c3100f644240801740956e85d96040083c4048bc65ec20400`.

### Gaps

- Complete dtor body / member map not owned (`FUN_00759de0` dualed WQ9L-F **accept-with-gaps**).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004401b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004401b0_FUN_004401b0.md` |
| Function named | `docs/reconstruction/functions/aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md` |

---

## Chain context (not dualled here; evidence only)

```text
PTR_FUN_00a9f304  gfxUIWindow primary vtbl
  [0] FUN_004401b0  gfxUIWindow_ScalarDeletingDtor   [OWN MEGA-129]
        ├─ FUN_00759de0  gfxUIWindow_CompleteDtor    [dualed WQ9L-F accept-with-gaps]
        └─ operator_delete @ 0x00489822              (flags&1)

FUN_007b5be0  CNDUIWindow_CompleteDtor               [derived; chains into complete]
  └─ FUN_00759de0

RTTI: .?AVgfxUIWindow@@ @ type_info 0x00afe190
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004401b0-mega-129-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004401b0` | Port as **MSVC scalar-deleting dtor** for **gfxUIWindow**. **ECX thiscall**, flags stack, **`RET 4`**, return this. Always call complete `00759de0`; free only if `flags&1`. Do **not** inline complete body. |
| Pair with | dualed complete `gfxUIWindow_CompleteDtor` `00759de0`; derived `CNDUIWindow_CompleteDtor` `007b5be0`; vtbl `PTR_FUN_00a9f304`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (UI / gfxUIWindow — not skill-specific despite partition bucket)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004401b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callees/xrefs + RTTI. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful product name; twin `FUN_004401b0.cpp` retained.  
- No Named_CalleeOf scaffold present for this VA (nothing to retire).  
- Odd behavior preserved: false-noreturn ignored; complete peer does not free this.  
- Product demangle sealed via RTTI. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
