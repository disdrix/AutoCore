# Dual A/B report — MEGA-015 OWN-ONLY (`0x005d73a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-015**  
**Scope:** VA `0x005d73a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + `analyze_control_flow` + `search_strings` + `batch_decompile` (callees) + ctor `FUN_005d7bb0`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — input-drive-control AI axis park (SetSteer/Long/HB+Push) under HB AI follow context.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d73a0` CVOGHBAIDriver_AxisPark_Inferred | **accept-with-gaps** — CF/ABI/body/RTTI/vtbl+0x10/vehicle@+0xbc/axis sequence/FireWeapons clear/Push/tail sealed; product method English + virtual callers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): vehicle-this / player DriveControlTick / mission-UI park / SetSteer-only merge / FireWeapons-engage / stdcall-RET4 / direct-caller / product-name sealed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005d73a0` — sealed facts

1. **Body:** `0x005d73a0`–`0x005d73e7` inclusive (**72 B** / `0x48`); pad `CC` after.
2. **ABI:** **ECX** = `CVOGHBAIDriver* this`; **no stack args**; void; exit via **tail `JMP FUN_005cc560`**.
3. **Semantics:** AI axis park on bound vehicle `this+0xbc`:
   - `VehicleEntity_SetSteerInput(vehicle, 0)` → `+0x618`
   - `VehicleEntity_SetLongitudinalInput(vehicle, 0)` → `+0x614`
   - `VehicleEntity_SetHandbrake(vehicle, 1)` → `+0x61c`
   - `CVOGHBAIFollowVehicle_FireWeapons(this, 0, 0)` — **may-fire false** clears weapon mask (`RET 8` callee)
   - `VehicleEntity_PushDriveAxesToController(vehicle)`
   - tail `FUN_005cc560(this)` residual owner-counter cleanup
4. **Class:** RTTI `.?AVCVOGHBAIDriver@@` @ `0x00af8d30`; ctor `FUN_005d7bb0` installs vtbl `009db02c`; this method = slot **`+0x10`**.
5. **Callees (6):** SetSteer `004f5620`; SetLong `004f5650`; SetHB `004f3620`; FireWeapons `005d7100`; Push `004fbc10`; `FUN_005cc560`.
6. **Callers:** **0** direct CALL; **1** DATA xref @ `0x009db03c` (vtable).
7. **Name:** `CVOGHBAIDriver_AxisPark_Inferred` (Ghidra `FUN_005d73a0`). Product method English open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + RTTI/ctor.
9. **Named_CalleeOf scaffolds:** none present for this VA (nothing to retire).

### Gaps

- Product English method name (no scoped string in body).  
- Inventory of virtual callers of `vtbl+0x10`.  
- Residual dual of `FUN_005cc560`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_AxisPark_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d73a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d73a0_FUN_005d73a0.md` |
| Function named | `docs/reconstruction/functions/aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBAIDriver  vtbl 009db02c  (ctor FUN_005d7bb0)
  [+0x10] FUN_005d73a0  CVOGHBAIDriver_AxisPark_Inferred  [OWN MEGA-015]
       ├─ VehicleEntity_SetSteerInput            004f5620  [dualed]
       ├─ VehicleEntity_SetLongitudinalInput     004f5650  [dualed]
       ├─ VehicleEntity_SetHandbrake             004f3620  [dualed]
       ├─ CVOGHBAIFollowVehicle_FireWeapons      005d7100  [dualed; mayFire=0 clear]
       ├─ VehicleEntity_PushDriveAxesToController 004fbc10 [dualed]
       └─ FUN_005cc560                           005cc560  [residual tail]

Peer parks (distinct; not dualled here):
  FUN_00636ba0  SetSteer(0)+Push only          [MEGA-017 OWN residual]
  FUN_0092f090  thr0/steer0/HB1 mission-UI     [MEGA-021 OWN residual]
  FUN_009373e0  dialog thr0+steer0+HB          [MEGA-024 OWN residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005d73a0-mega-015-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d73a0` | Port as **`CVOGHBAIDriver` virtual axis park** (`vtbl+0x10`). **thiscall**, no stack args, void. Vehicle at **`this+0xbc`**. Order: steer0 → long0 → HB1 → FireWeapons(mayFire=0) → Push → residual cleanup. |
| Pair with | dualed SetSteer/SetLong/SetHB/Push; dualed FireWeapons `005d7100`; residual `FUN_005cc560`; peer parks `00636ba0` / UI thr-steer parks. |
| Do not merge | player DriveControlTick; mission-UI park helpers; FireWeapons body; DoLogic; treat ECX as vehicle. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- **not** touched by MEGA-015
