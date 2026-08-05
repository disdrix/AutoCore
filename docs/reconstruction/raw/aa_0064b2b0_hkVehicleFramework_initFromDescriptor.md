# Raw capture: hkVehicleFramework_initFromDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064b2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064b2b0` |
| **Canonical name** | `hkVehicleFramework_initFromDescriptor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* hkVehicleFramework::initFromDescriptor — precomputes inertia/geometry constants from the setup
   descriptor. Called from hkVehicleFramework_ctor (0x64cd30).
   
   Key findings:
   - fw+0x310/0x314/0x318 = per-axis REAL inverse inertia: 1/((|R|·RVInertia)·mass), scalars from
   desc[0x11..0x13] (vehicleData +0x5dc..0x5e4), stored raw at fw+0x350/0x354/0x358.
   - fw+0x320..0x32c = SOLVER-FACING inverse inertia from per-axis ratios RVSpinTorque/RVInertia
   (desc[0xb..0xd] = vehicleData +0x5c8..0x5d0 over desc[0x11..0x13]). postTick (0x64bc70) hands
   THIS set to hkVehicleFrictionSolver_solve — the solver never sees real inertia. **This is the
   game's ANTI-ROLLOVER mechanism**: fleet data has RVSpinTorqueRoll≈0.2, Pitch≈0.05,
   Yaw≈0.37, so tire forces have almost no roll/pitch authority while yaw stays responsive. Cars
   cannot be rolled by cornering.
   - fw+0x35c = desc[0xa] = RVFrictionEqualizer (vehicleData+0x5c4); fw+0x348 = desc[0xe] =
   RVExtraTorqueFactor (+0x5d8, =0 for all retail vehicles); fw+0x304 = desc[0x10] = DAT_00af4614
   (normal-clip threshold const).
   - Per-wheel loop: aggregates per-AXLE rest contact geometry (suspension hardpoint + dir×length,
   chassis-local) into fw+0x1fc via FUN_006c4150 — the two-pseudo-contact-point setup for the
   friction solver. */

void __thiscall hkVehicleFramework_initFromDescriptor(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  float unaff_ESI;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int iStack_100;
  int iStack_fc;
  float fStack_f8;
  float fStack_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8 [8];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_38;
  float afStack_34 [4];
  int iStack_24;
  
  *(int *)(param_1 + 0x33c) = param_2[0xb];
  *(int *)(param_1 + 0x340) = param_2[0xc];
  *(int *)(param_1 + 0x344) = param_2[0xd];
  *(int *)(param_1 + 0x350) = param_2[0x11];
  *(int *)(param_1 + 0x354) = param_2[0x12];
  *(int *)(param_1 + 0x358) = param_2[0x13];
  *(int *)(param_1 + 0x304) = param_2[0x10];
  fVar7 = g_flOne;
  iVar13 = *param_2;
  fVar3 = (float)param_2[0x11];
  fVar4 = *(float *)(iVar13 + 0xc);
  fVar5 = (float)param_2[0x12];
  fVar6 = (float)param_2[0x13];
  local_f0 = (fVar6 * ABS(*(float *)(iVar13 + 0x30)) +
             fVar5 * ABS(*(float *)(iVar13 + 0x10)) + fVar3 * ABS(*(float *)(iVar13 + 0x20))) *
             fVar4;
  local_dc = (ABS(*(float *)(iVar13 + 0x34)) * fVar6 +
             ABS(*(float *)(iVar13 + 0x14)) * fVar5 + ABS(*(float *)(iVar13 + 0x24)) * fVar3) *
             fVar4;
  local_c8[0] = (ABS(*(float *)(iVar13 + 0x38)) * fVar6 +
                ABS(*(float *)(iVar13 + 0x18)) * fVar5 + ABS(*(float *)(iVar13 + 0x28)) * fVar3) *
                fVar4;
  *(float *)(param_1 + 0x310) = g_flOne / local_f0;
  *(float *)(param_1 + 0x318) = fVar7 / local_c8[0];
  *(undefined4 *)(param_1 + 0x31c) = 0;
  *(float *)(param_1 + 0x314) = fVar7 / local_dc;
  local_e4 = 0.0;
  local_e8 = 0.0;
  local_ec = 0.0;
  local_d4 = 0.0;
  local_d8 = 0.0;
  local_e0 = 0.0;
  local_c8[1] = 0.0;
  local_cc = 0.0;
  local_d0 = 0.0;
  (**(code **)(**(int **)(*(int *)(param_1 + 0x30) + 0x3c) + 0x1c))(fVar4);
  (**(code **)(**(int **)(*(int *)(param_1 + 0x30) + 0x3c) + 0x2c))(&fStack_f4);
  iVar13 = *param_2;
  fVar3 = *(float *)(iVar13 + 0x20);
  fVar4 = *(float *)(iVar13 + 0x24);
  fVar5 = *(float *)(iVar13 + 0x28);
  fVar6 = *(float *)(iVar13 + 0x10);
  fVar7 = *(float *)(iVar13 + 0x14);
  fVar8 = *(float *)(iVar13 + 0x18);
  fVar9 = *(float *)(iVar13 + 0x30);
  fVar10 = *(float *)(iVar13 + 0x34);
  fVar11 = *(float *)(iVar13 + 0x38);
  fVar17 = (float)param_2[0xd] / (float)param_2[0x11];
  fVar18 = (float)param_2[0xb] / (float)param_2[0x12];
  fVar19 = (float)param_2[0xc] / (float)param_2[0x13];
  local_ec = g_flOne / unaff_ESI;
  *(float *)(param_1 + 0x32c) = local_ec;
  *(float *)(param_1 + 0x324) =
       (ABS(fVar10) * fVar19 + ABS(fVar7) * fVar18 + ABS(fVar4) * fVar17) * local_ec;
  *(float *)(param_1 + 0x328) =
       (ABS(fVar11) * fVar19 + ABS(fVar8) * fVar18 + ABS(fVar5) * fVar17) * local_ec;
  local_ec = local_ec * (fVar19 * ABS(fVar9) + fVar18 * ABS(fVar6) + fVar17 * ABS(fVar3));
  *(float *)(param_1 + 800) = local_ec;
  iVar13 = *(int *)(param_1 + 0x30);
  iVar16 = *(int *)(iVar13 + 0x3c);
  uStack_a8 = *(undefined4 *)(iVar16 + 0x20);
  uStack_a4 = *(undefined4 *)(iVar16 + 0x24);
  uStack_a0 = *(undefined4 *)(iVar16 + 0x28);
  uStack_9c = *(undefined4 *)(iVar16 + 0x2c);
  iVar16 = *(int *)(iVar13 + 0x3c);
  fStack_f8 = *(float *)(iVar16 + 0x80) * local_ec;
  fStack_f4 = *(float *)(iVar16 + 0x84) * local_ec;
  local_f0 = *(float *)(iVar16 + 0x88) * local_ec;
  local_ec = *(float *)(iVar16 + 0x8c) * local_ec;
  local_dc = *(float *)(param_1 + 0x324);
  local_e8 = local_dc * *(float *)(iVar16 + 0x90);
  local_e4 = *(float *)(iVar16 + 0x94) * local_dc;
  local_e0 = *(float *)(iVar16 + 0x98) * local_dc;
  local_dc = *(float *)(iVar16 + 0x9c) * local_dc;
  local_cc = *(float *)(param_1 + 0x328);
  local_d8 = *(float *)(iVar16 + 0xa0) * local_cc;
  local_d4 = *(float *)(iVar16 + 0xa4) * local_cc;
  local_d0 = *(float *)(iVar16 + 0xa8) * local_cc;
  local_cc = *(float *)(iVar16 + 0xac) * local_cc;
  FUN_00645c90(&fStack_f8,iVar16 + 0x80);
  iVar16 = *param_2;
  uStack_38 = *(undefined4 *)(*(int *)(iVar13 + 0x3c) + 0x2c);
  uStack_88 = *(undefined4 *)(iVar16 + 0x10);
  uStack_84 = *(undefined4 *)(iVar16 + 0x14);
  uStack_80 = *(undefined4 *)(iVar16 + 0x18);
  uStack_7c = *(undefined4 *)(iVar16 + 0x1c);
  uStack_98 = *(undefined4 *)(iVar16 + 0x30);
  uStack_94 = *(undefined4 *)(iVar16 + 0x34);
  uStack_90 = *(undefined4 *)(iVar16 + 0x38);
  uStack_8c = *(undefined4 *)(iVar16 + 0x3c);
  uStack_78 = *(undefined4 *)(iVar16 + 0x20);
  uStack_74 = *(undefined4 *)(iVar16 + 0x24);
  uStack_70 = *(undefined4 *)(iVar16 + 0x28);
  uStack_6c = *(undefined4 *)(iVar16 + 0x2c);
  *(int *)(param_1 + 0x348) = param_2[0xe];
  iVar13 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0x34c) = param_2[0xf];
  iStack_24 = param_2[10];
  *(int *)(param_1 + 0x35c) = param_2[10];
  afStack_34[0] = 0.0;
  afStack_34[1] = 0.0;
  iVar16 = 0;
  if (0 < *(int *)(iVar13 + 0xc)) {
    iStack_fc = 0;
    iStack_100 = 0;
    do {
      iVar12 = *(int *)(*(int *)(iVar13 + 0x58) + iVar16 * 4);
      afStack_34[iVar12 + 2] = *(float *)(*(int *)(iVar13 + 0x10) + iVar16 * 4);
      iVar13 = *(int *)(param_1 + 0x28);
      fVar3 = *(float *)(*(int *)(iVar13 + 0x28) + iVar16 * 4);
      pfVar14 = (float *)(*(int *)(iVar13 + 0x1c) + iStack_100);
      pfVar15 = (float *)(*(int *)(iVar13 + 0x10) + iStack_100);
      local_c8[iVar12 * 4] = *pfVar15;
      local_c8[iVar12 * 4 + 1] = pfVar15[1];
      local_c8[iVar12 * 4 + 2] = pfVar15[2];
      local_c8[iVar12 * 4 + 3] = pfVar15[3];
      local_c8[iVar12 * 4] = *pfVar14 * fVar3 + local_c8[iVar12 * 4];
      local_c8[iVar12 * 4 + 1] = pfVar14[1] * fVar3 + local_c8[iVar12 * 4 + 1];
      local_c8[iVar12 * 4 + 2] = pfVar14[2] * fVar3 + local_c8[iVar12 * 4 + 2];
      local_c8[iVar12 * 4 + 3] = pfVar14[3] * fVar3 + local_c8[iVar12 * 4 + 3];
      iVar13 = *(int *)(param_1 + 0xc);
      iVar1 = iVar16 * 4;
      iVar2 = iStack_fc + 0x84;
      iVar16 = iVar16 + 1;
      iStack_100 = iStack_100 + 0x10;
      iStack_fc = iStack_fc + 0xc0;
      afStack_34[iVar12] =
           *(float *)(*(int *)(iVar13 + 0x10) + iVar1) * *(float *)(iVar2 + *(int *)(iVar13 + 0x80))
           + afStack_34[iVar12];
    } while (iVar16 < *(int *)(iVar13 + 0xc));
  }
  FUN_006c4150(local_c8,param_1 + 0x1fc);
  return;
}
```
