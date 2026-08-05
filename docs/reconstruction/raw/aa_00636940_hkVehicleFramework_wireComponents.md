# Raw capture: hkVehicleFramework_wireComponents

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636940` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00636940` |
| **Canonical name** | `hkVehicleFramework_wireComponents` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* hkVehicleFramework::wireComponents — copies component pointers from the setup descriptor into
   the framework and sets each ticked component's backpointer (+8) to the framework.
   
   Slot map (fw+X = desc[i]):
     +0x0c = desc[1]  (hkDefaultWheels — has +0xc wheelCount, +0x58 axle array, +0x80 per-wheel
   0xc0-byte structs)
     +0x10 = desc[0]
     +0x14 = desc[2]  ← ticked 1st (receives throttle at +0x1c from VehicleAction_applyAction)
     +0x18 = desc[3]  ← ticked 2nd
     +0x1c = desc[4]  ← ticked 3rd
     +0x20 = desc[5]  ← ticked 4th
     +0x24 = desc[6]  ← ticked 5th
     +0x28 = desc[8]  ← ticked 6th (hkDefaultSuspension per initFromDescriptor usage: +0x10
   hardpoints, +0x1c directions, +0x28 lengths)
     +0x2c = desc[7]  ← ticked 7th
     +0x30 = desc[9]  (hkDefaultChassis — hkRigidBody at chassis+0x3c; NOT ticked by
   tickSubsystems)
   Only the 7 at +0x14..+0x2c get the backpointer and are ticked via vtable slot +0x14 by
   VehicleAction_tickSubsystems (0x636a60); self slot +0x18 runs after as post-tick finalize
   (friction solve suspect). */

void __thiscall hkVehicleFramework_wireComponents(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0xc) = param_2[1];
  *(undefined4 *)(param_1 + 0x14) = param_2[2];
  *(undefined4 *)(param_1 + 0x18) = param_2[3];
  *(undefined4 *)(param_1 + 0x1c) = param_2[4];
  *(undefined4 *)(param_1 + 0x20) = param_2[5];
  *(undefined4 *)(param_1 + 0x24) = param_2[6];
  *(undefined4 *)(param_1 + 0x28) = param_2[8];
  *(undefined4 *)(param_1 + 0x2c) = param_2[7];
  *(undefined4 *)(param_1 + 0x30) = param_2[9];
  *(int *)(*(int *)(param_1 + 0x14) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x18) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x1c) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x20) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x24) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x28) + 8) = param_1;
  *(int *)(*(int *)(param_1 + 0x2c) + 8) = param_1;
  return;
}
```
