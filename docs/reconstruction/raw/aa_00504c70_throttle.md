# Raw capture: Vehicle_setDrivingInputs (throttle / network drive inputs)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00504c70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00504c70` |
| **Canonical name** | `Vehicle_setDrivingInputs` |
| **Ghidra name** | `Vehicle_setDrivingInputs` |
| **System** | `input-drive-control` (network / ghost producer of drive axes) |
| **Capture timestamp** | `2026-07-29` (live re-decompile; supersedes 2026-07-23 scaffold body notes) |
| **Tool** | Ghidra MCP `decompile_function` @ `0x00504c70`; `read_memory` len 128 @ entry; `get_function_callers` / `get_function_callees` / `get_xrefs_to` |
| **Integrity** | Do not overwrite frozen bodies; append versioned sections only |

---

## Raw pseudocode (authoritative decompile — 2026-07-29 live)

```c
/* Vehicle::setDrivingInputs — network/ghost + local entry that writes entity drive axes then
   PushDriveAxesToController.
   
   Writes (thiscall entity):
     +0x614 float throttle (param_6)
     +0x618 float steer (param_7)
     +0x61c byte handbrake (param_8) — WI-MOV-001 Brake held → SetHandbrake; NOT a separate
   \"sharp-turn\" channel
   Then VehicleEntity_PushDriveAxesToController (004fbc10).
   
   Consume (WI-MOV-002):
     +0x618 → VehicleAction_applyAction ramp → steering (hkpVehicleSteering_setSteeringAngle)
     +0x614 → Push → controller(+0x1a0→+8)+0x20 (not read in applyAction/calcWheelTorque)
     +0x61c → Push → controller+0x24 AND calcWheelTorque rear torque *0.5
   
   Also may ActivateEnterWorld if controller missing. */

void __thiscall
Vehicle_setDrivingInputs
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined1 param_8,char param_9,undefined4 param_10)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x3c) + 0x18))();
    if (iVar2 == 6) {
      FUN_0053d970(0);
    }
    *(undefined4 *)(param_1 + 0x614) = param_6;
    *(undefined4 *)(param_1 + 0x618) = param_7;
    *(undefined1 *)(param_1 + 0x61c) = param_8;
    VehicleEntity_PushDriveAxesToController();
    if ((param_9 == '\0') && (*(int *)(param_1 + 0x1a0) == 0)) {
      piVar1 = *(int **)(param_1 + 0xb0 + *(int *)(*(int *)(param_1 + 4) + 4));
      if (piVar1 != (int *)0x0) {
        iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
        iVar3 = (**(code **)(*piVar1 + 0x19c))();
        iVar2 = (**(code **)(*(int *)(param_1 + 4 + iVar2) + 0x1c8))();
        if (iVar3 == iVar2) {
          Vehicle_ActivateEnterWorld();
        }
      }
    }
    FUN_0053eec0(param_2,param_3,param_4,param_5,param_10);
  }
  return;
}
```

### Machine notes (this pass — not full disasm)

`read_memory` @ `0x00504c70` (first 0x53 bytes of body, hex prefix):

```text
56 8b f1 8b 46 08 85 c0 0f 84 b0 00 00 00   ; push esi; mov esi,ecx; load/test [esi+8]; jz out
8b 40 3c 8b 10 8b c8 ff 52 18                 ; phys+0x3c vtbl call +0x18
83 f8 06 75 09 6a 00 8b ce e8 da 8c 03 00     ; cmp eax,6; if eq: push 0; mov ecx,esi; call 0x0053d970
f3 0f 10 44 24 18                             ; movss xmm0, [esp+0x18]  ; thr (param_6)
8a 44 24 20                                   ; mov al, [esp+0x20]      ; hb  (param_8)
f3 0f 11 86 14 06 00 00                       ; movss [esi+0x614], xmm0
f3 0f 10 44 24 1c                             ; movss xmm0, [esp+0x1c]  ; steer (param_7)
8b ce                                         ; mov ecx, esi
f3 0f 11 86 18 06 00 00                       ; movss [esi+0x618], xmm0
88 86 1c 06 00 00                             ; mov [esi+0x61c], al
e8 4d 6f ff ff                                 ; call 0x004fbc10  (PushDriveAxesToController)
```

**Decompiler caveat:** `FUN_0053d970(0)` in pseudocode is **misleading** — machine passes **entity `this` in ECX** (`mov ecx,esi`) after `push 0`. Callee `FUN_0053d970` uses `param_1+8` as entity phys host. Leave callee body as `FUN_*` (no RTTI/string seal here).

### Call graph (this pass)

| Direction | Symbol | VA |
|-----------|--------|----|
| Caller | `VehicleNet_UnpackGhostVehicle` | `0x005f7720` (site `0x005f99aa`) |
| Caller | `VehicleNet_ReconcilePrediction` | `0x005f9f10` (site `0x005fa245`) |
| Callee | `FUN_0053d970` | `0x0053d970` |
| Callee | `VehicleEntity_PushDriveAxesToController` | `0x004fbc10` |
| Callee | `Vehicle_ActivateEnterWorld` | `0x00503f30` |
| Callee | `FUN_0053eec0` | `0x0053eec0` |

---

## Prior scaffold capture (2026-07-23) — retained for history

Same decompiler body as live (no CF delta). Tool: `batch_decompile`. Canonical scaffold name was `throttle`.
