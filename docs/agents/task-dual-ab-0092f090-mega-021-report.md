# Dual A/B report — MEGA-021 OWN-ONLY (`0x0092f090`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-021**  
**Scope:** VA `0x0092f090` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-021**.  
**Work item:** residual dual seal — **Mission-UI axis park thr0/steer0/HB1** (parent `Client_ShowNpcMissionDialogUI` `0x009438f0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092f090` MissionUI_ParkDriveAxes_Inferred | **accept-with-gaps** — CF/ABI/ESI-host/+0xe98/+0x250/thr0·steer0·HB1/3 dualed callees/5 call sites sealed; product host/`FUN_0093e450` English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / thr-only / HB-clear / PushDriveAxes / single-parent / always-park / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092f090` — sealed facts

1. **Body:** `0x0092f090`–`0x0092f0d1` inclusive (**66 B** / `0x42`); pad `CC` after RET.
2. **ABI:** **ESI** = client host (callers `MOV ESI,EBP`); no stack formals; void; bare **`RET`** (`C3`).
3. **Semantics:** Mission-UI **drive-axis park**:
   - Gate: `*(ESI+0xe98) != 0` (character) **and** `*(*(ESI+0xe98)+0x250) != 0` (vehicle entity).
   - `VehicleEntity_SetLongitudinalInput(vehicle, 0)` @ `0x004f5650`.
   - `VehicleEntity_SetSteerInput(vehicle, 0)` @ `0x004f5620`.
   - `VehicleEntity_SetHandbrake(vehicle, 1)` @ `0x004f3620`.
   - Reloads vehicle from ESI chain before each setter; no re-null after gate.
4. **Static callees:** 3 dualed vehicle setters (no PushDriveAxes).
5. **Callers (2 funcs / 5 sites):**
   - `Client_ShowNpcMissionDialogUI` (`0x009438f0`) @ `0x00943989`, `0x00943b72`.
   - `FUN_0093e450` (`0x0093e450`–`0x0093e7cc`) @ `0x0093e6ce`, `0x0093e745`, `0x0093e76f`.
6. **Xrefs:** 5× UNCONDITIONAL_CALL.
7. **Name:** `MissionUI_ParkDriveAxes_Inferred` (Ghidra `FUN_0092f090`). Scaffold `Named_CalleeOf_Client_ShowNpcMissionDialogUI_0092f090` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `input-drive-control` (partition + dualed setter family).

### Gaps

- Product English for ESI client-host class.  
- Product English for residual parent `FUN_0093e450`.  
- thr/steer may no-op under dualed 0xC7 gate while HB still writes 1.  
- Sibling axis-park units residual (e.g. `0x009373e0`, `0x005d73a0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.md` |
| Annotated | `docs/reconstruction/raw/aa_0092f090_FUN_0092f090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionUI_ParkDriveAxes_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092f090.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowNpcMissionDialogUI_0092f090.cpp` |
| Function | `docs/reconstruction/functions/aa_0092f090_FUN_0092f090.md` |
| Function named | `docs/reconstruction/functions/aa_0092f090_MissionUI_ParkDriveAxes_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowNpcMissionDialogUI  (0x009438f0)  [parent dual / residual]
  ├─ multi-mission / single-mission UI setup
  ├─ FUN_008ab550 / FUN_008aa4b0 / journal / response helpers  [other residual]
  └─ FUN_0092f090  MissionUI_ParkDriveAxes_Inferred  [OWN MEGA-021]  ×2

FUN_0093e450  dialog-case dispatcher (TFID target)  [residual]
  ├─ case 0: no-choices / choice-loop UI → FUN_0092f090  [OWN]  ×2
  ├─ case 1: FUN_007fdfb0 → FUN_0092f090  [OWN]  ×1
  └─ case 2/3: other UI paths (no park)

FUN_0092f090  [OWN MEGA-021]
  ├─ VehicleEntity_SetLongitudinalInput(0)  [dualed aa_004f5650]
  ├─ VehicleEntity_SetSteerInput(0)         [dualed aa_004f5620]
  └─ VehicleEntity_SetHandbrake(1)          [dualed aa_004f3620]
        (PushDriveAxes is separate consumer — not called here)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092f090-mega-021-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092f090` | Port as **mission-UI drive-axis park**: if client has character+vehicle, set thr **0**, steer **0**, HB **1** via existing VehicleEntity setters. ABI: **ESI=client host**, bare RET, no stack args. Call from mission dialog open/case paths. Do **not** model as ECX-thiscall, thr-only, HB-clear, or PushDriveAxes. |
| Pair with | dualed `VehicleEntity_SetLongitudinalInput` `004f5650`; dualed `SetSteerInput` `004f5620`; dualed `SetHandbrake` `004f3620`; parent `Client_ShowNpcMissionDialogUI` `009438f0`; residual `FUN_0093e450`; sibling axis-park units (dialog/AI). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / inventory / NAMING_REGISTRY as applicable  
- Do **not** claim runtime Confirmed without Launcher evidence.

**Terminal:** **false**
