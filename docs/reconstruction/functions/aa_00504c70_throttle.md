# Function record: Vehicle_setDrivingInputs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504c70` |
| **Canonical name** | `Vehicle_setDrivingInputs` |
| **Scaffold / file stem** | `throttle` (historical) |
| **Address** | `0x00504c70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` (network/ghost producer; not local DriveControlTick) |
| **Completion status** | **Dual complete (A/B)** — live decompile + machine thr/steer/HB stores + call graph; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_00504c70_Vehicle_setDrivingInputs.md`, `reviews/B_aa_00504c70_Vehicle_setDrivingInputs.md` |

## Purpose

Network / ghost entry that, when the entity owns a physics object (`entity+0x08 != 0`):

1. Optionally runs motion cleanup `FUN_0053d970` when body type vfunc returns **6**.
2. Writes the three drive axes: thr `+0x614`, steer `+0x618`, handbrake `+0x61c`.
3. Calls `VehicleEntity_PushDriveAxesToController` (thr/HB → input controller; steer not copied).
4. Optionally `Vehicle_ActivateEnterWorld` when skip-flag is clear and controller host is null.
5. Applies network pose/velocity via `FUN_0053eec0`.

If `entity+0x08 == 0`, the function is a complete no-op (no axis stores, no pose apply).

## Signature (decompiler-derived)

```c
void __thiscall Vehicle_setDrivingInputs(
    int   this,           // entity (ECX)
    void *pos,            // param_2  → FUN_0053eec0
    void *rot,            // param_3
    void *linVel,         // param_4
    void *angVel,         // param_5
    float thr,            // param_6  → entity+0x614 (f32)
    float steer,          // param_7  → entity+0x618 (f32)
    uint8_t handbrake,    // param_8  → entity+0x61c (u8)
    char  skipActivate,   // param_9  — activate path only when 0
    float integrateDt);   // param_10 → FUN_0053eec0 last arg
```

Machine: thr/steer `movss`; HB byte; `this` in ECX.

## Behavioral summary

| Stage | Behavior | Confidence |
|---|---|---|
| Gate | Require `entity+0x08 != 0` | **High** |
| Type-6 | `vfunc(*(phys+0x3c), +0x18)==6` → `FUN_0053d970` with **entity ECX** | **High CF** / product enum **Probable** |
| Axis stores | Ungated thr/steer/HB (no 0xC7 gate) | **High** |
| Push | Always on gated path → `0x004fbc10` | **High** |
| Activate | `param_9==0` ∧ `+0x1a0==0` ∧ owner vfunc match | **High CF** |
| Pose | `FUN_0053eec0(pos,rot,vel,angVel,dt)` | **High** (callee sealed in verified notes) |
| Callers | `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction` | **High** (static xrefs) |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** (Ghidra + xrefs) |
| Signature (arg count / thr/steer/HB widths) | **High** (machine) |
| Pose arg semantics | **High** (forwarded; see `fn_0053eec0_networkApply`) |
| Control flow | **High** (live decompile ≡ machine prefix) |
| Naming (`Vehicle_setDrivingInputs`) | **High** (Ghidra symbol + plate; no RTTI contradiction) |
| Type-6 product meaning | **Probable** |
| `param_9` product name | **Probable** (skip-activate CF sealed) |
| Side effects | **High** structure / **Open** runtime |
| Overall | **accept-with-gaps** (dual sealed static CF) |

## Open questions

- Product name for body-type enum value **6**.
- Wire layout of args at VehicleNet call sites (owned by those units).
- Runtime / differential equivalence.
- Whether decompiler `FUN_0053d970(0)` ever misled ports (machine: entity this).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00504c70_throttle.md` |
| Annotated | `raw/aa_00504c70_throttle.annotated.md` |
| Clean | `reconstructed-exact/throttle.cpp` |
| Review A | `reviews/A_aa_00504c70_Vehicle_setDrivingInputs.md` |
| Review B | `reviews/B_aa_00504c70_Vehicle_setDrivingInputs.md` |
| Push dual | `aa_004fbc10` |
| Pose apply | `physics/verified/fn_0053eec0_networkApply.md` |
| Axis layout | `types/VehicleEntity_drive_axes.md` |
| System map | `systems/input-drive-control.md` |
