# Dual A/B report — MEGA-094 OWN-ONLY (`0x00790020`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-094**  
**Scope:** VA `0x00790020` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-094**.  
**Work item:** residual dual seal — input-drive-control **key normalize / UI gate** (`aa_00790020`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00790020` Client_Input_KeyDown_UiGateAndForward_Inferred | **accept-with-gaps** — CF/ABI/RET8/offsets/ESC/callers/DATA-vtbl sealed; product English for focus object + vtbl slots open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): DIK-normalize / stdcall / primary-id-at-0x49C / leaf / OnKeyDown-only claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00790020` — sealed facts

1. **Body:** `0x00790020`–`0x00790098` inclusive (**121 B** / `0x79`); pad `CC` after.
2. **ABI:** **ECX** = this (`MOV ESI,ECX`); stack `key`, `lParam`; return **AL**; **`RET 8`** ×4 exits.
3. **Semantics:** virtual key-down UI gate + forward + ESC:
   - Gate: `this->vtbl+0x3D8()`; if false → return **0**.
   - If `this+0x4BC` non-null → `(*focus)->vtbl+0x358(key, lParam)`.
   - If `key == 0x1B` (ESC):
     - UI present → `this->vtbl+0x3BC(0)`; return **1**.
     - Else if `this+0x49C >= 0` → return `this->vtbl+0x338(8, secondary_code)`.
   - Else return **1**.
4. **Offsets:** `param_1[0x12f]` → `+0x4BC`; `param_1[0x127]` → `+0x49C` (secondary modal; UF-009 / `aa_007fdfb0`).
5. **Callees:** vcalls only (analyze "leaf" is misleading).
6. **Callers (code):** `Client_Input_OnKeyDown_MatchAction` @ `0x009113c9`; `FUN_00866220` @ `0x00866374`; `FUN_008cc420` @ `0x008cc4e4` (+ mids).
7. **Xrefs:** ~150 **DATA** vtbl installs (shared virtual method).
8. **Name:** `Client_Input_KeyDown_UiGateAndForward_Inferred` (Ghidra `FUN_00790020`). Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.
10. **Not** a DIK remapper — return is continue/gate byte for parent.

### Gaps

- Product English for `+0x4BC` focused UI type.  
- Product names for vtbl `+0x3D8` / `+0x3BC` / `+0x358` / `+0x338`.  
- Primary owning RTTI class among multi-vtbl installs.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00790020_FUN_00790020.md` |
| Annotated | `docs/reconstruction/raw/aa_00790020_FUN_00790020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_KeyDown_UiGateAndForward_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00790020.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020.cpp` |
| Function | `docs/reconstruction/functions/aa_00790020_FUN_00790020.md` |
| Function named | `docs/reconstruction/functions/aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_Input_OnKeyDown_MatchAction  0x00911030  [dualed parent]
  ├─ ESC special when vtbl+0x3D8 && key==0x1B  (separate branch)
  └─ else FUN_00790020 / Client_Input_KeyDown_UiGateAndForward_Inferred  [OWN MEGA-094]
       └─ return byte → continue ActionMap table scan

FUN_00866220  [residual UI list key]
FUN_008cc420  [residual slot-nav key]
  └─ fall-through / early → same base method

Modal dual-id (UF-009): host +0x498 primary / +0x49C secondary
  └─ ESC no-UI path uses +0x49C with vtbl+0x338(action=8)  [sealed prior]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00790020-mega-094-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00790020` | Port as virtual **key-down UI gate + focus forward + ESC**. **thiscall RET 8**. Return **0** blocks further input handling; **1** continues. Do **not** treat as DIK normalize. Pair ESC secondary path with modal host `+0x49C` and action code **8**. Keep distinct from parent pure-ESC cancel branch in `Client_Input_OnKeyDown_MatchAction`. |
| Pair with | dualed `Client_Input_OnKeyDown_MatchAction` `00911030`; residual `FUN_00866220` / `FUN_008cc420`; modal dual-id `aa_007fdfb0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- system map `input-drive-control.md` (optional cross-link)
- coverage / COVERAGE_LEDGER as needed

**Terminal:** false.
