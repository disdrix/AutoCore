# Function record: CVOGHBAIDriver_AxisPark_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d73a0` |
| **Canonical name** | `CVOGHBAIDriver_AxisPark_Inferred` (**Inferred** — product method English open) |
| **Ghidra name** | `FUN_005d73a0` |
| **Prior scaffold** | `FUN_005d73a0` only (no Named_CalleeOf plate to retire) |
| **Rejected misnames** | vehicle-this; player DriveControlTick; mission-UI park; SetSteer-only `00636ba0`; FireWeapons itself; DoLogic |
| **Address** | `0x005d73a0`–`0x005d73e7` inclusive (**72 B** / `0x48`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control / HB AI driver |
| **Parent dual / context** | MEGA residual partition MEGA-015; HB AI follow; dualed axis pipeline + FireWeapons |
| **Agent** | MEGA-015 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Virtual **axis park** on **`CVOGHBAIDriver`** (`vtbl+0x10`):

```text
vehicle = this[+0xbc]
SetSteerInput(vehicle, 0)            // +0x618
SetLongitudinalInput(vehicle, 0)     // +0x614
SetHandbrake(vehicle, 1)             // +0x61c
FireWeapons(this, mayFire=0, 0)      // clear mask (RET 8)
PushDriveAxesToController(vehicle)
tail FUN_005cc560(this)              // residual counters
```

## Signature

```c
// __thiscall: ECX = CVOGHBAIDriver* this; no stack args; void; tail JMP FUN_005cc560
void __thiscall CVOGHBAIDriver_AxisPark_Inferred(void *self);
```

## Layout (fields touched)

| Offset | Width | Role in this VA |
|---|---|---|
| **this+0xbc** | ptr | **read** — vehicle entity* for axis/Push calls |
| vehicle+0x618 | f32 | via SetSteerInput(0) |
| vehicle+0x614 | f32 | via SetLongitudinalInput(0) |
| vehicle+0x61c | u8 | via SetHandbrake(1) |

## Class / dispatch

| Item | Value |
|---|---|
| RTTI | `.?AVCVOGHBAIDriver@@` @ `0x00af8d30` |
| Vtable | `PTR_FUN_009db02c` (ctor `FUN_005d7bb0`) |
| Slot | `+0x10` → `0x005d73a0` |
| Direct CALL xrefs | **0** |
| DATA xrefs | **1** @ `0x009db03c` |

## Call graph

| Role | Target |
|---|---|
| Direct callers | **none** (virtual) |
| Callees | `VehicleEntity_SetSteerInput` `0x004f5620`; `VehicleEntity_SetLongitudinalInput` `0x004f5650`; `VehicleEntity_SetHandbrake` `0x004f3620`; `CVOGHBAIFollowVehicle_FireWeapons` `0x005d7100`; `VehicleEntity_PushDriveAxesToController` `0x004fbc10`; `FUN_005cc560` `0x005cc560` |

## Chain context (not dualled; evidence only)

```text
CVOGHBAIDriver  vtbl 009db02c
  [+0x00] scalar dtor 005d6dc0
  [+0x0c] OnHeartBeat path 005d0310 (CreatureBase plate)
  [+0x10] FUN_005d73a0  CVOGHBAIDriver_AxisPark_Inferred  [OWN MEGA-015]
  …
  [DoLogic slot] CVOGHBAIDriver_DoLogic 005d7750  [dualed residual peer]
       └─ CVOGHBAIFollowVehicle_FireWeapons 005d7100  [dualed; also callee of AxisPark]

Axis pipeline (dualed writers used here):
  SetSteer 004f5620 / SetLong 004f5650 / SetHB 004f3620 / Push 004fbc10
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_AxisPark_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005d73a0.cpp`
- Raw: `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.md`
- Annotated: `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_005d73a0_FUN_005d73a0.md`
- Report: `docs/agents/task-dual-ab-005d73a0-mega-015-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + body size | **Confirmed** |
| Class CVOGHBAIDriver + vtbl+0x10 | **Confirmed** |
| Axis park + clear fire + Push order | **Confirmed** |
| Product method English | **Inferred** |
| Virtual caller roles | **Inferred** |
| Runtime Confirmed | **Open** |
