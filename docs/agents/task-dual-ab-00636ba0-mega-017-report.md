# Dual A/B report — MEGA-017 OWN-ONLY (`0x00636ba0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-017**  
**Scope:** VA `0x00636ba0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` (body/vtbl/RTTI). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-017 residual dual seal — input-drive-control axis-park: SetSteer(0)+PushDriveAxes; RTTI **CVOGHBMoveVehicle** OnEnd.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00636ba0` CVOGHBMoveVehicle_OnEnd | **accept-with-gaps** — CF/ABI/RTTI/vtbl OnEnd/entity+0x24/steer-only park/callees sealed; runtime + full class dual open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): full-stop-pack / entity-this / code-callers / Push-steer / EmptyVFunc-tail / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00636ba0` — sealed facts

1. **Body:** `0x00636ba0`–`0x00636bbf` inclusive (**32 B** / `0x20`); pad `CC` before ctor `0x00636bd0`.
2. **ABI:** **ECX** = `CVOGHBMoveVehicle* this`; no stack args; ends **`JMP 0x005081e0`** (empty `C3`); not `RET N`.
3. **Semantics:** virtual **OnEnd** (`vtbl+0x10`):
   - `entity = *(this+0x24)`; if non-null → `VehicleEntity_SetSteerInput(entity, 0)` then `VehicleEntity_PushDriveAxesToController(entity)`.
   - **Steer-only** park — no longitudinal zero, no handbrake force.
4. **RTTI:** `.?AVCVOGHBMoveVehicle@@` @ `0x00af33c0`; subclass `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0` shares OnEnd pointer.
5. **DATA xrefs:** `0x009e3b80` (`PTR_FUN_009e3b70+0x10`), `0x009d55a0` (`PTR_FUN_009d5590+0x10`).
6. **Code callers:** **none** — dispatch via `CVOGHBBase_Stop` → `jmp [vtbl+0x10]`.
7. **Callees:** `0x004f5620` SetSteerInput; `0x004fbc10` PushDriveAxes; tail empty `0x005081e0` (≠ EmptyVFunc `0x005081f0`).
8. **Entity bind:** ctor `FUN_00636bd0` stores vehicle arg at `param_1[9]` → **`this+0x24`**.
9. **Name:** `CVOGHBMoveVehicle_OnEnd` (Ghidra `FUN_00636ba0`). Product class RTTI-sealed; OnEnd = Stop-slot convention.
10. **Decompile ≡ raw** for if/call CF; **decompiler omits** empty-ret tail — sealed by disasm + `read_memory`.

### Gaps

- Runtime / bit-exact / differential.  
- Full class dual (ctor `00636bd0`, fire `00636cc0`) residual.  
- Empty leaf `005081e0` formal English.  
- PDB method symbol beyond RTTI + OnEnd convention.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnEnd.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636ba0.cpp` |
| Function | `docs/reconstruction/functions/aa_00636ba0_FUN_00636ba0.md` |
| Function named | `docs/reconstruction/functions/aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBBase_Stop  0x005081d0  [dualed]
  └─ jmp [vtbl+0x10]
        └─ CVOGHBMoveVehicle_OnEnd  0x00636ba0  [OWN MEGA-017]
              ├─ VehicleEntity_SetSteerInput(0)     0x004f5620  [dualed]
              └─ VehicleEntity_PushDriveAxes…       0x004fbc10  [dualed]

FUN_00636bd0  CVOGHBMoveVehicle ctor  [residual]
  ├─ vtbl PTR_FUN_009e3b70
  └─ this+0x24 = vehicle entity

FUN_00636cc0  fire / MoveToTarget  [residual]
  └─ on fail → CVOGHBBase_Stop → OnEnd [OWN]

FUN_00599550  CVOGHBMoveVehicleToMouse ctor  [residual]
  └─ base ctor then vtbl PTR_FUN_009d5590 (same OnEnd)

Contrast (do not merge):
  FUN_005d73a0  AI full axis park thr0/steer0/HB1  [MEGA-015 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00636ba0-mega-017-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00636ba0` | Port as **`CVOGHBMoveVehicle::OnEnd`**. **thiscall**, entity at **`this+0x24`**. If non-null: gated **SetSteer(0)** + **PushDriveAxes**. Do **not** zero thr or force HB here. Virtual only (`vtbl+0x10`). Shared by **MoveVehicleToMouse**. |
| Pair with | dualed Stop `005081d0`; dualed SetSteer `004f5620`; dualed Push `004fbc10`; residual ctor/fire `00636bd0` / `00636cc0`. |
| Do not merge | AI follow full park `005d73a0`; EmptyVFunc tail `005081f0` (actual tail `005081e0`). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming / system maps as applicable  
- residual ctor/fire duals if scheduled
