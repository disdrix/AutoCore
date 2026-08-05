// =============================================================================
// Vehicle_setDrivingInputs  (scaffold filename: throttle.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00504c70
// Address:   0x00504c70  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (network / ghost drive-axis + pose entry)
// Generated: 2026-07-29 from live Ghidra decompile (exact CF; not modernization)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* identifiers are unresolved pending type recovery (leave-FUN).
 * - Decompiler showed FUN_0053d970(0); machine passes entity this in ECX.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Writes (thiscall entity):
 *   +0x614 float throttle (param_6)
 *   +0x618 float steer    (param_7)
 *   +0x61c byte handbrake (param_8)
 * Then VehicleEntity_PushDriveAxesToController (0x004fbc10).
 * Then optional Vehicle_ActivateEnterWorld; always FUN_0053eec0 pose apply.
 */

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
      /* machine: ECX = param_1 (entity); push 0 is stack-only — not this-arg */
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
