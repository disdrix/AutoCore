# Raw capture: VehicleEntity_PushDriveAxesToController

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbc10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fbc10` |
| **Canonical name** | `VehicleEntity_PushDriveAxesToController` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WI-MOV-002: Push entity drive axes into VehicleAction controller.
   
   Requires entity+0x101==0 and entity+0x1a0!=0.
   ctrl = *(entity+0x1a0)+8
   
   Writes:
     ctrl+0x20 = entity+0x614 (longitudinal/throttle float; Accel=-1, Reverse=+1 from
   DriveControlTick)
     if ctrl+0x19: clamp throttle to DAT_00a0f734 (0.9)
     if entity+0x109: force ctrl+0x20=0 and ctrl+0x24=1 (stop)
     ctrl+0x24 = entity+0x61c (handbrake byte from SetHandbrake/Brake held)
     ctrl+0x25 = 0
   
   Also speed-cap gate: if speed > max (driver/vehicle derived), zero throttle when opposing
   forward.
   
   entity+0x618 is NOT written here — consumed in VehicleAction_applyAction as steer ramp target.
   entity+0x61c ALSO read in VehicleAction_calcWheelTorque (rear torque *0.5).
   
   Callers: DriveControlTick, PollBoundActions, Vehicle_setDrivingInputs, SetDriveAxes, etc. */

void __fastcall VehicleEntity_PushDriveAxesToController(int param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  float fVar9;
  float fStack_40;
  float local_3c;
  float local_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  if ((*(char *)(param_1 + 0x101) == '\0') && (*(int *)(param_1 + 0x1a0) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x1a0) + 8);
    *(undefined1 *)(iVar2 + 0x25) = 0;
    if (*(char *)(param_1 + 0x109) != '\0') {
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined1 *)(iVar2 + 0x24) = 1;
      return;
    }
    fVar9 = *(float *)(param_1 + 0x614);
    *(float *)(iVar2 + 0x20) = fVar9;
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x1a0) + 8) + 0x19) != '\0') {
      if (DAT_00a0f734 <= fVar9) {
        fVar9 = DAT_00a0f734;
      }
      *(float *)(iVar2 + 0x20) = fVar9;
    }
    if (*(int *)(param_1 + 8) == 0) {
      pfVar5 = (float *)&DAT_00b041b0;
    }
    else {
      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
    }
    fVar9 = *(float *)(param_1 + 0x10c);
    piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    local_34 = SQRT(pfVar5[2] * pfVar5[2] + pfVar5[1] * pfVar5[1] + *pfVar5 * *pfVar5);
    if ((piVar3 == (int *)0x0) || (iVar6 = (**(code **)(*piVar3 + 0x1d8))(), iVar6 == 0)) {
      local_3c = 0.0;
    }
    else {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d8))();
      fVar8 = (float10)FUN_004c4e20();
      local_3c = (float)fVar8;
    }
    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
    if ((iVar6 != 0) && (DAT_00af1854 != '\0')) {
      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
      fStack_40 = *(float *)(iVar6 + 0xd48) + fStack_40;
    }
    iVar6 = *(int *)(*(int *)(param_1 + 4) + 4);
    uVar4 = *(uint *)(iVar6 + 0xb8 + param_1);
    iVar6 = iVar6 + param_1;
    if (((uVar4 & 0x1000) != 0) ||
       ((*(int *)(iVar6 + 0xb0) != 0 && ((*(byte *)(*(int *)(iVar6 + 0xb0) + 0xb5) & 0x10) != 0))))
    {
      fStack_40 = fStack_40 - g_flOverheatCoolFrac;
    }
    if (((uVar4 & 0x4000) != 0) ||
       ((*(int *)(iVar6 + 0xb0) != 0 && ((*(byte *)(*(int *)(iVar6 + 0xb0) + 0xb5) & 0x40) != 0))))
    {
      fStack_40 = fStack_40 + DAT_009cd0d8;
    }
    fVar1 = *(float *)(*(int *)(*(int *)(iVar6 + 0xac) + 0x3c) + 0x634);
    local_3c = (fStack_40 + g_flOne) * local_3c;
    if ((fVar1 != DAT_00aaa668) && (fVar1 < local_3c)) {
      local_3c = fVar1;
    }
    if (local_3c < fVar9) {
      pfVar5 = (float *)FUN_00404a20();
      local_34 = *pfVar5;
      fStack_30 = pfVar5[1];
      fStack_2c = pfVar5[2];
      fStack_28 = pfVar5[3];
      FUN_004e8a40(&local_34,&fStack_24);
      if (*(int *)(param_1 + 8) == 0) {
        pfVar5 = (float *)&DAT_00b041b0;
      }
      else {
        pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
      }
      if (pfVar5[2] * fStack_1c + pfVar5[1] * fStack_20 + *pfVar5 * fStack_24 <= 0.0) {
        fVar9 = *(float *)(iVar2 + 0x20);
        bVar7 = fVar9 < 0.0;
      }
      else {
        fVar9 = *(float *)(iVar2 + 0x20);
        bVar7 = 0.0 < *(float *)(iVar2 + 0x20);
      }
      if (!bVar7 && fVar9 != 0.0) {
        *(undefined4 *)(iVar2 + 0x20) = 0;
      }
    }
    *(undefined1 *)(iVar2 + 0x24) = *(undefined1 *)(param_1 + 0x61c);
  }
  return;
}
```
