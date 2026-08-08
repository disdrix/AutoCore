# Dual A/B report — R11-039 OWN-ONLY (`0x0092af80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-039**  
**Scope:** VA `0x0092af80` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x0092adf0` edits; neighbor `0x0092bf60` (R11-040).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — undualed dispatcher calling dualed CBID nearest arm; partition system inventory-transfer; parent dual `0x0092adf0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092af80` TargetFilter_DispatchMatchArms_Inferred | **accept-with-gaps** — CF/ABI/arm gates/sticky AL/sole caller/dualed Resolve+CBID arm sealed; product filter-ctx English + residual arm duals + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / thiscall-only / hit-found-return / short-circuit / multi-caller / `(lo\|\|hi)==-1` empty / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092af80` — sealed facts

1. **Body:** `0x0092af80`–`0x0092b011` inclusive (**146 B** / `0x92`); pad `CC` @ `0x0092b012+`.
2. **ABI:** **EAX** = `TargetFilterCtx*` (`*ctx` = `Client*`); **ESI** = `void **bestOut`; stack **`float *origin`**, **`float *bestDistSq`**; **`ret 8`**; returns **AL** bool (any arm executed).
3. **Semantics:** multi-arm target-filter dispatcher:
   - Direct COID when `(ctx+0x20 & ctx+0x24) != 0xFFFFFFFF` → `CVOGReaction_ResolveObjectTarget(0, lo, hi)` with **ECX** = `*(client+0xD34)`; store `*bestOut`.
   - `ctx+0x28 > 0` → dualed **`TargetFilter_FindNearestWorldObjByCbidList_Inferred`** (`0x0092adf0`).
   - `ctx+0x80 > 0` → residual `FUN_0092abc0`.
   - `ctx+0x54 > 0` → residual `FUN_0092a980` (**EBX** = ctx).
   - `ctx+0xAC > 0` → residual `FUN_0092a760`; if returns 0 → residual `FUN_00929cd0(ctx, …)`.
   - Sticky `AL=1` per fired arm (not non-null hit).
4. **Callees:** `CVOGReaction_ResolveObjectTarget`, `FUN_0092adf0`, `FUN_0092abc0`, `FUN_0092a980`, `FUN_0092a760`, `FUN_00929cd0`.
5. **Callers:** **1** — `FUN_0092bf60` @ `0x0092bff5` (char pos vtbl `+0x1A0`; max dist `DAT_00aaaaf8` = `0x4E6E6B28`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `TargetFilter_DispatchMatchArms_Inferred` (Ghidra `FUN_0092af80`). Scaffold twin kept as `FUN_0092af80.cpp`.
8. **Decompile ≡ raw CF**; ABI + epilogue + call site sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product/PDB filter-context class English.  
- Residual arm interiors (`0092abc0` / `0092a980` / `0092a760` / `00929cd0`) not dual-owned.  
- Grandcaller `0092bf60` residual (R11-040).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R11 re-verify append) | `docs/reconstruction/raw/aa_0092af80_FUN_0092af80.md` |
| Annotated | `docs/reconstruction/raw/aa_0092af80_FUN_0092af80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/TargetFilter_DispatchMatchArms_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092af80.cpp` |
| Function | `docs/reconstruction/functions/aa_0092af80_FUN_0092af80.md` |
| Function named | `docs/reconstruction/functions/aa_0092af80_TargetFilter_DispatchMatchArms_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0092bf60  filter tick / apply  [residual R11-040]
  char this-adjust → vtbl+0x1A0 → origin float*
  bestOut=0; bestDistSq = DAT_00aaaaf8
  CALL 0x0092af80  TargetFilter_DispatchMatchArms_Inferred  [OWN R11-039]
  if AL && FUN_0092b2a0(...): return 1

TargetFilter_DispatchMatchArms_Inferred  0x0092af80  [OWN]
  ├─ CVOGReaction_ResolveObjectTarget     0x004bae70  [dualed]
  ├─ TargetFilter_FindNearestWorldObjByCbidList_Inferred  0x0092adf0  [dualed parent]
  │     └─ InventoryGrid_FindItemByCoid on locker *(char+0xCBC)
  ├─ FUN_0092abc0  [residual]
  ├─ FUN_0092a980  [residual]
  ├─ FUN_0092a760  [residual]
  └─ FUN_00929cd0  [residual fallback]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092af80-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092af80` | Port as **target-filter multi-arm dispatcher**. **EAX ctx** + **ESI bestOut\*\*** + stack origin/bestDistSq, **`ret 8`**, **AL** = any arm ran. Order: direct COID → CBID nearest → three residual arms. Do **not** treat AL as hit-found. Pair with dualed Resolve + CBID nearest; residual arms remain open. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
