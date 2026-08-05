# Annotated low-level: Vehicle_setDrivingInputs

| Field | Value |
|---|---|
| Stable ID | `aa_00504c70` |
| VA | `0x00504c70` |
| System | `input-drive-control` (network/ghost path) |
| Date | `2026-07-29` (live re-annotate; supersedes 2026-07-23 scaffold) |

## Machine-level notes

- Source: live Ghidra `decompile_function` + `read_memory` @ `0x00504c70`.
- Prefer assembly when decompiler conflicts: **`FUN_0053d970(0)` is wrong** — ECX = entity, not literal 0.
- Integer widths: thr/steer are **f32** (`movss`); handbrake is **u8** (`mov al` / byte store).
- Side-effect order: preserve store and call order from raw:
  1. Gate on `entity+0x08 != 0`
  2. Optional type-6 → `FUN_0053d970(entity)`
  3. Store thr / steer / HB
  4. `PushDriveAxesToController`
  5. Optional `ActivateEnterWorld` when `param_9==0` and controller host null
  6. Always (on gated path) `FUN_0053eec0(pos,rot,vel,angVel,integrateDt)`
- Uncertainty: product names for pose args; vfunc `+0x18` return enum beyond “6”; full semantics of `param_9` skip-activate flag.

## Parameter map (decompiler + stack after `push esi`)

| Decomp name | Role (Probable / High) | Stack after `push esi` | Confidence |
|---|---|---|---|
| `param_1` / `this` | Vehicle entity (`ECX`) | — | **High** |
| `param_2` | Net position xyzw ptr | `[esp+0x08]` | **High** (forwarded to `FUN_0053eec0`) |
| `param_3` | Net rotation quat ptr | `[esp+0x0c]` | **High** |
| `param_4` | Net linear velocity ptr | `[esp+0x10]` | **High** |
| `param_5` | Net angular velocity ptr | `[esp+0x14]` | **High** |
| `param_6` | Throttle f32 → `+0x614` | `[esp+0x18]` | **High** (`movss`) |
| `param_7` | Steer f32 → `+0x618` | `[esp+0x1c]` | **High** (`movss`) |
| `param_8` | Handbrake u8 → `+0x61c` | `[esp+0x20]` | **High** (byte) |
| `param_9` | Skip-activate flag (char); activate only when **0** | `[esp+0x24]` | **High CF** / product name open |
| `param_10` | integrateDt f32 for soft pose path | after hb/flag | **High** (forwarded as last arg) |

## Pseudocode (annotated copy of raw)

```c
/* Vehicle::setDrivingInputs — network/ghost entry.
   Writes entity drive axes then PushDriveAxesToController, then network pose apply.

   Entity stores (thiscall):
     +0x614 f32 thr   (param_6)   — Accel polarity typically −1, Reverse +1 at producers
     +0x618 f32 steer (param_7)   — left +1 / right −1 at local input; wire may differ
     +0x61c u8  HB    (param_8)   — handbrake / sharp; NOT a separate steer channel

   Then VehicleEntity_PushDriveAxesToController (0x004fbc10):
     thr → ctrl+0x20, HB → ctrl+0x24; steer NOT copied (applyAction ramps +0x618)

   Optional ActivateEnterWorld when param_9==0 and entity+0x1a0==0 and owner vfunc match.

   Always FUN_0053eec0(pos,rot,vel,angVel,dt) for pose/velocity apply (leave FUN_*).
*/

void __thiscall
Vehicle_setDrivingInputs
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined1 param_8,char param_9,undefined4 param_10)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  // Gate: require physics object host at entity+0x08
  if (*(int *)(param_1 + 8) != 0) {

    // Query body / motion type via (*(*(phys+0x3c))+0x18)(); if == 6, motion cleanup
    iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x18))();
    if (iVar2 == 6) {
      // MACHINE: ECX = entity (not literal 0). Decompiler FUN_0053d970(0) is wrong.
      FUN_0053d970(/* this */);
    }

    // Ungated axis stores (no 0xC7 suppress gate — contrast SetLongitudinal/SetSteer)
    *(undefined4 *)(param_1 + 0x614) = param_6;   // thr f32
    *(undefined4 *)(param_1 + 0x618) = param_7;   // steer f32
    *(undefined1 *)(param_1 + 0x61c) = param_8;   // HB u8

    VehicleEntity_PushDriveAxesToController();    // thiscall ECX=entity; thr/HB bridge

    // Lazy activate: only if flag clear AND no controller host yet
    if ((param_9 == '\0') && (*(int *)(param_1 + 0x1a0) == 0)) {
      // MI-style component at entity+0xb0 + *(vtbl_or_link+4)
      piVar1 = *(int **)(param_1 + 0xb0 + *(int *)(*(int *)(param_1 + 4) + 4));
      if (piVar1 != (int *)0x0) {
        iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
        iVar3 = (**(code **)(*piVar1 + 0x19c))();                 // owner id/token A
        iVar2 = (**(code **)(*(int *)(param_1 + 4 + iVar2) + 0x1c8))(); // owner id/token B
        if (iVar3 == iVar2) {
          Vehicle_ActivateEnterWorld();           // thiscall entity
        }
      }
    }

    // Network pose / velocity apply (soft or hard path inside callee)
    FUN_0053eec0(param_2,param_3,param_4,param_5,param_10);
  }
  return;
}
```

## Control-flow diagram

```
entry (this = entity @ ECX)
  |
  +-- if entity+0x08 == 0 → return (complete no-op: no axes, no pose)
  |
  +-- type = vfunc(*( *(entity+0x08)+0x3c ), +0x18)
  |     if type == 6 → FUN_0053d970(entity)
  |
  +-- entity+0x614 = thr
  +-- entity+0x618 = steer
  +-- entity+0x61c = hb
  +-- PushDriveAxesToController(entity)
  |
  +-- if param_9==0 AND entity+0x1a0==0:
  |     resolve component @ +0xb0+adj
  |     if non-null and vfunc0x19c == vfunc0x1c8 → ActivateEnterWorld
  |
  +-- FUN_0053eec0(pos, rot, linVel, angVel, integrateDt)
  return
```

## Open questions

- Product enum name for vfunc `+0x18` return value **6**.
- Exact product name of `param_9` (skip-enter-world / already-active flag).
- Wire packing of thr/steer/HB and pose blobs in `VehicleNet_UnpackGhostVehicle` / `ReconcilePrediction` (out of this unit body).
- Whether any non-net static callers exist beyond the two VehicleNet sites (static xrefs: 2).
