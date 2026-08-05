# Dual A/B review batch — VehicleAction_applyAction + VehicleNet remaining + VehicleDb + hk companions (cap 20)

**Date:** 2026-07-23  
**Scope:** Primary holdouts from the vehicle-thin/skill-uses batch: **`VehicleAction_applyAction`**, remaining **`VehicleNet_*`** (`PostCorrectionEvent`, `UnpackGhostVehicle`), **`VehicleDb_LoadCloneBase`** (clean stub exists; decomp failed), filled to 20 with **hk vehicle framework / friction** companions on the applyAction tick path plus load/ghost siblings.  
**Prefer:** applyAction orchestration, ghost unpack/correction, DB bind honesty, postTick drive source (WI-MOV-004).  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).

## Selection

Pre-batch dual count: **411** modern A_/B_ pairs.  
Prior vehicle-thin batch left explicit dual-missing samples:

| Name | Notes |
|---|---|
| `VehicleAction_applyAction` | large (~900 lines) apply path |
| `VehicleNet_PostCorrectionEvent` / `UnpackGhostVehicle` | large net |
| `VehicleDb_LoadCloneBase` | decomp failed in clean |

Also dual-missing on the same physics graph: framework preUpdate/postTick, suspension/steer/aero/transmission children, friction solver, `setSteeringAngle`, plus `CloneBase_LoadWadFile` / `GhostCreature_UnpackUpdate` companions.

## Pairs written

| # | Stable ID | Name | System | A verdict | B notes |
|---|---|---|---|---|---|
| 1 | `aa_00598650` | VehicleAction_applyAction | input-drive-control | accept-with-gaps | Order: tick→anti-sink→stage-1→mode→torque→airStab; VA+0x24=steer |
| 2 | `aa_005f7360` | VehicleNet_PostCorrectionEvent | input-drive-control | accept-with-gaps | Deferred **0x203C/0x203E**; not sync equip |
| 3 | `aa_005f7720` | VehicleNet_UnpackGhostVehicle | input-drive-control | accept-with-gaps | Initial vs delta hardpoints; combat masks |
| 4 | `aa_007efb40` | VehicleDb_LoadCloneBase | input-drive-control | accept-with-gaps | **Decomp failed**; bind-site only |
| 5 | `aa_00636410` | hkpVehicleSteering_setSteeringAngle | input-drive-control | **accept** | Trivial `+0x50` store; VA+0x28 |
| 6 | `aa_00636940` | hkVehicleFramework_wireComponents | input-drive-control | accept-with-gaps | Slot map; no engine |
| 7 | `aa_0064b2b0` | hkVehicleFramework_initFromDescriptor | input-drive-control | accept-with-gaps | Inertia precompute; +0x1fc contacts |
| 8 | `aa_0064bc70` | hkVehicleFramework_postTickApplyForces | input-drive-control | accept-with-gaps | Drive from **wheel+0x28** not transm |
| 9 | `aa_0064cd30` | hkVehicleFramework_ctor | input-drive-control | accept-with-gaps | → initFromDescriptor |
| 10 | `aa_0064cf20` | hkVehicleFramework_preUpdate | input-drive-control | accept-with-gaps | Hardpoints +0x20..; not throttle |
| 11 | `aa_0064dae0` | hkDefaultAerodynamics_update | input-drive-control | accept-with-gaps | Child aero; not applyAction inline |
| 12 | `aa_0064de50` | hkDefaultSuspension_update | input-drive-control | accept-with-gaps | Forces only; anti-sink is applyAction |
| 13 | `aa_0064efb0` | hkDefaultTransmission_calcRPM | input-drive-control | accept-with-gaps | RPM only; AA torque separate |
| 14 | `aa_0064f510` | hkDefaultTransmission_update | input-drive-control | accept-with-gaps | +0x1c orphaned vs drive |
| 15 | `aa_0064f610` | hkDefaultTransmission_ctor | input-drive-control | accept-with-gaps | Thin ctor |
| 16 | `aa_0064f840` | hkDefaultSteering_update | input-drive-control | accept-with-gaps | doesWheelSteer fan-out |
| 17 | `aa_006c3f90` | hkVehicleFrictionSolver_circleProjection | input-drive-control | accept-with-gaps | Unit-circle force clamp |
| 18 | `aa_006c4450` | hkVehicleFrictionSolver_solve | input-drive-control | accept-with-gaps | Large friction core |
| 19 | `aa_00541410` | CloneBase_LoadWadFile | inventory-transfer | accept-with-gaps | WAD dispatch; not LoadCloneBase body |
| 20 | `aa_005d2e40` | GhostCreature_UnpackUpdate | input-drive-control | accept-with-gaps | Position as-is; creature sibling |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **`applyAction` orchestration sealed for port order:**
   - early-outs → **`tickSubsystems(VA+0x40)` first** → anti-sink (min **wheel+0xB0**) → stage-1 steer **`entity+0x618` → VA+0x24 → wheelsDesc+0x1c`** → mode **0x02** `setSteeringAngle(VA+0x28)` with speedFactor **|v|/20** OR upright impulse (up·world < **0.7**) → `calcWheelTorque` → `airStabilization` → grounded/anim/dead tail.
   - **VA+0x24 is steer ramp, not brake.** No service-brake torque in this function.
2. **Drive force source (WI-MOV-004):** `postTickApplyForces` consumes **wheel+0x28[i]** from AA `calcWheelTorque`. Transmission **+0x1c** is **not** the drive path (no hkDefaultEngine).
3. **Anti-sink vs suspension:** Suspension **update** writes forces only; **chassis Y lift** on penetration is **applyAction** scan of **+0xB0**, not `hkDefaultSuspension_update`.
4. **Ghost net split:**
   - `UnpackGhostVehicle`: initial hardpoints may equip; **delta** → `PostCorrectionEvent` (**0x203C** 0x40 / **0x203E** 0x30) deferred queue — **not** same-call `SetWheelset`.
   - Wire handbrake bit0 → **entity+0x61c** ≠ setup **`sinVehicleFlags` / VehSpec+0x5f0**.
5. **`VehicleDb_LoadCloneBase` honesty:** clean is decomp-failed stub; dual accepts bind-site evidence only (`sinVehicleFlags` → **+0x5f0**, rl* columns). Do not treat stub as CF-complete.
6. **`setSteeringAngle`:** trivial **`*(+0x50)=angle`** from applyAction mode-0x02; not AbsoluteTopSpeed math.

## Breakdown by family

| Group | Count |
|---|---:|
| VehicleAction_applyAction | 1 |
| VehicleNet_* remaining | 2 |
| VehicleDb_LoadCloneBase | 1 |
| hkVehicleFramework_* / setSteeringAngle | 6 |
| hkDefault* children (aero/susp/trans/steer) | 6 |
| hkVehicleFrictionSolver_* | 2 |
| Load / ghost companions | 2 |

(Counts: 20 total.)

## Not done (still dual-missing samples)

| Name | Notes |
|---|---|
| Full VehicleDb bind-block asm recovery | decomp still failed; needs Ghidra re-pass |
| Bit-exact applyAction / UnpackGhost | deferred runtime/diff |
| Remaining bulk string-dump renames | low dual value |
| Other large Ghost* / Pack* if any | outside this cap |

Related vehicle dual backlog from prior waves is largely closed for named Vehicle*/VehicleNet*/VehicleAction*/VehicleDb* clean units.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files)
- Writer: `tmp/write_dual_reviews_vehicle_apply_net_db.py`
- Report: `docs/agents/task-dual-ab-vehicle-apply-net-db-report.md`
- Post-batch dual count: **431** (was 411)
- No Launcher touched; no servers started.
