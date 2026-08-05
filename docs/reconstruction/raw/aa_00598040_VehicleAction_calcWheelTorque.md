# Raw capture: VehicleAction_calcWheelTorque

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598040` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00598040` |
| **Canonical name** | `VehicleAction_calcWheelTorque` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* VehicleAction::calcWheelTorque — per-wheel engine/drive torque into the friction solver.
   
   CORRECTED (RE v2, 2026-07-05): output goes to hkDefaultWheels+0x28[i] (per-wheel engine torque
   array), which hkVehicleFramework_postTickApplyForces (0x64bc70) aggregates per axle (×
   wheel+0x88 ÷ axleWheelCount) as the DRIVE IMPULSE input to hkVehicleFrictionSolver_solve
   (0x6c4450). There is no hkDefaultEngine — this is AA's engine replacement.
   
   Per wheel (only if inContact(+0x80), else 0; gate: entity anim/power flag +0xe4f8):
     t  = VehicleEngine_torqueCurve2D(wheel+0x20, wheel+0x28)    // 2D LUT factor
     driver modifier (entity..+0xb0 → vtbl+0x214 → +0x118 float, default 0):
        >0: t = 1 − (1−mod)(1−t)   (blend toward 1)
        <0: rear wheels ×2.0 (DAT_00a10e74) then t ×= (1+mod)
     upright = 1.0, unless |dot(bodyUp, worldUp)| < 0.8 (DAT_00a0f698): pow() falloff
     μ  = wheelsetFriction[i] (FUN_004f5550 — same per-wheel friction as wheels desc)
     lowSpeedBoost: |v| < 15.0 (DAT_00aaa7a4) → μ ×= (15−|v|)×0.2 (DAT_00a0f70c) + 1
     torque = μ × upright × t
     if (entity byte+0x61c && rear wheel): torque ×= 0.5 (DAT_00a0f298)
        ← 0.5 is NOT RearWheelFrictionScalar (prior claim wrong); it's a rear traction
          cut under a state flag (+0x61c — handbrake/burnout suspect). The real
          RearWheelFrictionScalar (vehicleData+0x740) scales the wheels-descriptor
          friction table entries for rear wheels at setup.
     clamp [0, 1000.0 (DAT_00a0f520)] → wheels+0x28[i]
   this+0x2c = all-wheels-airborne flag (1 if no wheel in contact). */

void __fastcall VehicleAction_calcWheelTorque(int param_1)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  undefined1 local_41;
  float local_40;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  cVar3 = FUN_004f5560();
  iVar7 = 0;
  local_41 = 1;
  if (0 < cVar3) {
    iVar6 = 0;
    do {
      if (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x44) + 4) + 4) + 0xa8 +
                           *(int *)(param_1 + 0x44)) + 0xe4f8) != 0) {
        iVar5 = *(int *)(*(int *)(param_1 + 0x40) + 0xc);
        iVar4 = *(int *)(iVar5 + 0x80) + iVar6;
        if (*(char *)(iVar4 + 0x80) == '\0') {
          *(undefined4 *)(*(int *)(iVar5 + 0x28) + iVar7 * 4) = 0;
        }
        else {
                    /* WI-MOV-003b: wheel+0x20 / +0x28 loaded as torqueCurve2D args; writers =
                       preUpdate contact kinematics (not ctrl throttle). */
          local_41 = 0;
          fVar8 = (float10)VehicleEngine_torqueCurve2D
                                     (*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x28));
          local_40 = (float)fVar8;
          piVar1 = *(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x44) + 4) + 4) + 0xb0 +
                            *(int *)(param_1 + 0x44));
          if (piVar1 != (int *)0x0) {
            iVar5 = (**(code **)(*piVar1 + 0x214))();
            fVar9 = *(float *)(iVar5 + 0x118);
            if (fVar9 <= 0.0) {
              if (fVar9 < 0.0) {
                iVar5 = *(int *)(*(int *)(param_1 + 0x44) + 600);
                if ((int)(uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac
                                                          + iVar5) + 0x3c) + 0x4cc) < iVar7) {
                  fVar9 = fVar9 * g_flLevelUpUiBase_Inferred;
                }
                local_40 = (fVar9 + g_flOne) * local_40;
              }
            }
            else {
              local_40 = g_flOne - (g_flOne - fVar9) * (g_flOne - local_40);
            }
          }
          iVar5 = *(int *)(param_1 + 0x44);
          if (*(int *)(iVar5 + 8) == 0) {
            iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 0x94 + iVar5;
          }
          else {
            iVar5 = *(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0x30;
          }
          FUN_004e8b60(iVar5,&fStack_20);
          fVar9 = g_flOne;
          if (ABS(fStack_20 * DAT_00af3390 + fStack_1c * DAT_00af3394 + fStack_18 * DAT_00af3398) <
              DAT_00a0f698) {
            fVar8 = (float10)_CIpow();
            fVar9 = (float)fVar8;
          }
          fVar8 = (float10)FUN_004f5550(iVar7);
          fVar10 = (float)fVar8;
          iVar5 = *(int *)(param_1 + 0x44);
          iVar4 = *(int *)(*(int *)(iVar5 + 8) + 0x3c);
          fVar2 = SQRT(*(float *)(iVar4 + 0x48) * *(float *)(iVar4 + 0x48) +
                       *(float *)(iVar4 + 0x44) * *(float *)(iVar4 + 0x44) +
                       *(float *)(iVar4 + 0x40) * *(float *)(iVar4 + 0x40));
          if (fVar2 < DAT_00aaa7a4) {
            fVar10 = ((DAT_00aaa7a4 - fVar2) * DAT_00a0f70c + g_flOne) * fVar10;
          }
                    /* WI-MOV-002: +0x61c handbrake rear traction cut x0.5 */
          fVar10 = fVar10 * fVar9 * local_40;
          if ((*(char *)(iVar5 + 0x61c) != '\0') &&
             ((int)(uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 600) + 4) +
                                                             4) + 0xac + *(int *)(iVar5 + 600)) +
                                           0x3c) + 0x4cc) < iVar7)) {
            fVar10 = fVar10 * DAT_00a0f298;
          }
          fVar9 = 0.0;
          if ((fVar10 < 0.0) || (fVar9 = DAT_00a0f520, DAT_00a0f520 < fVar10)) {
            fVar10 = fVar9;
          }
          *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40) + 0xc) + 0x28) + iVar7 * 4) = fVar10
          ;
        }
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0xc0;
    } while (iVar7 < cVar3);
    *(undefined1 *)(param_1 + 0x2c) = local_41;
    return;
  }
  *(undefined1 *)(param_1 + 0x2c) = 1;
  return;
}
```
