# Function record: VehicleEntity_PushDriveAxesToController

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbc10` |
| **Canonical name** | `VehicleEntity_PushDriveAxesToController` |
| **Address** | `0x004fbc10` |
| **Body span** | `0x004fbc10` – `0x004fbeb2` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__fastcall` / `__thiscall` — entity in `ECX` |
| **Return type** | `void` |
| **System** | input-drive-control |
| **Completion status** | **Human-refined + dual residual sealed (static + live re-decompile)** — thr/HB bridge, reverse ceiling, speed-cap polarity, controller layout, **`FUN_004c4e20` body** High; runtime/diff/`fStack_40` live open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004fbc10_*` / `B_aa_004fbc10_*` — **accept-with-gaps** (strengthened 2026-07-29 pass 2) |
| **Verified physics** | `physics/verified/fn_004fbc10_pushDriveAxes.md` |
| **Live RE this seal** | Ghidra `decompile_function` `0x004fbc10` / `0x004c4e20` / `0x00404a20` / `0x004e8a40`; `read_memory` constants |

## Purpose

Copy entity **throttle** (`+0x614`) and **handbrake** (`+0x61c`) into the **input controller** at `*(entity+0x1a0)+8`, with hard-stop, optional positive thr ceiling (0.9), and overspeed thr-zero when thr would continue travel. **Does not** copy steer (`+0x618`).

## Signature (decompiler-derived)

```c
void __fastcall VehicleEntity_PushDriveAxesToController(VehicleEntity* thisEntity);
// Plate: WI-MOV-002
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` / `param_1` | `ECX` | `VehicleEntity*` / entity | Vehicle whose axes are pushed |

## Behavior (exact outline)

```
if entity+0x101 != 0 OR entity+0x1a0 == 0: return

ctrl = *(entity+0x1a0) + 8
ctrl+0x25 = 0

if entity+0x109 != 0:
  ctrl+0x20 = 0; ctrl+0x24 = 1; return

ctrl+0x20 = entity+0x614
if ctrl+0x19 and thr >= 0.9: ctrl+0x20 = 0.9

// baseMax:
//   0 if wobj null / vfunc 0x1d8 fails
//   else FUN_004c4e20 → *(entity+0x1f4) [+ *(driver+0xd48) if DAT_00b037d4]
// bonus (port init 0): +driver+0xd48 if DAT_00af1854; −0.3 / +0.5 flag paths
// local_3c = (bonus+1)*baseMax; AbsoluteTopSpeed clamp unless −1
// if local_3c < entity+0x10c: maybe zero ctrl thr by travel polarity

ctrl+0x24 = entity+0x61c
```

## Memory map

| Location | Access | Type | Notes |
|---|---|---|---|
| `entity+0x101` | R | u8 | must be 0 |
| `entity+0x109` | R | u8 | hard-stop |
| `entity+0x10c` | R | f32 | requested speed vs derived max |
| `entity+0x1a0` | R | ptr | controller host |
| `entity+0x1f4` | R | f32 | base max-speed (`FUN_004c4e20`; +500) |
| `entity+0x614` | R | f32 | thr source |
| `entity+0x618` | — | f32 | **not accessed** |
| `entity+0x61c` | R | u8 | HB source (normal path) |
| `ctrl+0x19` | R | u8 | enable 0.9 ceiling |
| `ctrl+0x20` | W | f32 | thr |
| `ctrl+0x24` | W | u8 | HB |
| `ctrl+0x25` | W | u8 | clear 0 |
| `driver+0xd48` | R | f32 | speed-bonus float (two independent consumers) |

**Layout note:** input controller is **not** Havok `VehicleAction` (VA `+0x24` is f32 steer stage-1).

## Callers (sample)

| Symbol / label | Address | Context |
|---|---|---|
| `CVOGVehicle::MoveToTarget3DPoint` | `0x004fc650` | AI axes then push |
| `Vehicle_setDrivingInputs` | `0x00504c70` | network/ghost |
| `VehicleEntity_SetDriveAxes` | `0x004fbec0` | set/clear all three then push |
| `Client_Input_DriveControlTick` | `0x009223b0` area | local player |
| `Client_Input_PollBoundActions` | `0x009260da` area | local binds |
| `Vehicle_TryActivatePhysics` | `0x005014d8` | activation |

## Callees

| Addr | Name | Role | Seal |
|---|---|---|---|
| `0x004c4e20` | `FUN_004c4e20` | base max-speed: `*(entity+0x1f4)` [+ `driver+0xd48` if `DAT_00b037d4`] | **Body sealed this pass** |
| `0x00404a20` | `FUN_00404a20` | chassis quat ptr (`phys+0x3c+0x30` or entity `+0x94`) | Body sealed |
| `0x004e8a40` | `FUN_004e8a40` | forward unit from unit quat (scale 2.0) | Cross-doc High |

### `FUN_004c4e20` (authoritative outline)

```c
float10 __fastcall FUN_004c4e20(int entity) {
  int driver = vfunc_0x210(component_chain(entity), 0);
  if (driver != 0 && DAT_00b037d4 != 0)
    return *(float*)(driver + 0xd48) + *(float*)(entity + 0x1f4);
  return *(float*)(entity + 0x1f4);  // +500 decimal
}
```

Image default: `DAT_00b037d4 = 0` → pure `entity+0x1f4`. Outer PushDrive bonus still may add `driver+0xd48` under **`DAT_00af1854`** (image default **1**) into the **multiplier** `(bonus+1)`.

## Constants

| Symbol | Value | Role |
|---|---:|---|
| `DAT_00a0f734` | 0.9 | thr ceiling |
| `DAT_00aaa668` | −1.0 | AbsoluteTopSpeed sentinel |
| `g_flOne` | 1.0 | bonus scale |
| `g_flOverheatCoolFrac` | 0.3 | bonus penalty |
| `DAT_009cd0d8` | 0.5 | bonus add |
| `DAT_00af1854` | 1 (image u8) | outer `+0xd48` bonus enable |
| `DAT_00b037d4` | 0 (image u8) | `FUN_004c4e20` base add of `+0xd48` |
| `0x00a10e74` | 2.0 | quat→forward scale (`FUN_004e8a40`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004fbc10_VehicleEntity_PushDriveAxesToController.md`
- Annotated: `docs/reconstruction/raw/aa_004fbc10_VehicleEntity_PushDriveAxesToController.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleEntity_PushDriveAxesToController.cpp`
- Duals: `reviews/A_aa_004fbc10_*`, `reviews/B_aa_004fbc10_*`
- Verified: `physics/verified/fn_004fbc10_pushDriveAxes.md`
- Scratch: `tmp/a_004fbc10.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler / raw / live | **High** |
| Thr/HB/controller offsets | **High** |
| Steer not written | **High** |
| Reverse ceiling constant 0.9 | **High** |
| Speed-cap polarity | **High CF** |
| `FUN_004c4e20` field map (`+0x1f4`, optional `+0xd48`) | **High** |
| Dual-flag product interaction | **High CF structure** |
| `fStack_40` live init | **Tentative / open** |
| Runtime | **Open** |
