# Raw capture: hkVehicleFramework_postTickApplyForces

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064bc70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064bc70` |
| **Canonical name** | `hkVehicleFramework_postTickApplyForces` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WI-MOV-004 High: postTickApplyForces — DRIVE impulse from wheels+0x28[i] (calcWheelTorque out),
   not transm+0x1c.
   
   this=hkVehicleFramework; arg = dt vec.
   Per wheel (fw+0xc wheels, structs @ +0x80 stride 0xC0):
     1) force along contact normal: (fw+0x28)+0x34[i] * dt * wheel+0x30.. → chassis RB vtbl+0x60
   (suspension/normal — NOT engine drive)
     2) DRIVE: axle pack += wheels+0x28[i] * wheel+0x88 / axleWheelCount  (asm 0064c17e..c263 →
   axle field +0x38)
   Then hkVehicleFrictionSolver_solve (006c4450) @ fw+0x1fc / +0x2cc.
   
   NO read of transmission +0x1c / axle array (AA has no hkDefaultEngine; transm torque is
   residual).
   ctrl+0x20 throttle not read here — still open for pedal→torque gate (likely brake/coast
   elsewhere).
   Also aero/chassis pre-forces, friction solve, writeback wheel+0x94..0xa0. */

void __thiscall hkVehicleFramework_postTickApplyForces(float param_1,float *param_2)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int *piVar11;
  int iVar12;
  float *pfVar13;
  char *pcVar14;
  int iVar15;
  char cVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  float fVar24;
  int iStack_430;
  float fStack_42c;
  float fStack_428;
  float fStack_424;
  float local_420;
  float local_41c;
  float local_418;
  float local_414;
  float afStack_410 [4];
  undefined1 uStack_3fe;
  undefined1 uStack_3fd;
  int iStack_3fc;
  float fStack_3f8;
  float fStack_3f4;
  float local_3f0;
  float local_3ec;
  float local_3e8;
  float local_3e4;
  float local_3e0;
  float local_3dc;
  float local_3d8;
  float local_3d4;
  float fStack_3d0;
  undefined1 auStack_3cc [16];
  undefined4 auStack_3bc [57];
  undefined1 auStack_2d8 [12];
  float afStack_2cc [6];
  float afStack_2b4 [4];
  float afStack_2a4 [9];
  char acStack_280 [84];
  undefined4 uStack_22c;
  undefined1 auStack_21c [4];
  float fStack_218;
  float fStack_214;
  float fStack_210;
  float fStack_208;
  float fStack_204;
  float fStack_200;
  float fStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  float fStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  undefined4 uStack_17c;
  undefined1 auStack_11c [16];
  int aiStack_10c [66];
  
  iVar17 = *(int *)((int)param_1 + 0x2c);
  fVar20 = *param_2;
  fVar24 = *(float *)((int)param_1 + 0xc);
  local_3e0 = *(float *)(iVar17 + 0x20) * fVar20;
  local_3dc = *(float *)(iVar17 + 0x24) * fVar20;
  local_3d8 = *(float *)(iVar17 + 0x28) * fVar20;
  local_3d4 = *(float *)(iVar17 + 0x2c) * fVar20;
  piVar11 = *(int **)(*(int *)((int)param_1 + 0x30) + 0x3c);
  if ((float)piVar11[0xb] == 0.0) {
    fVar23 = 0.0;
  }
  else {
    fVar23 = g_flOne / (float)piVar11[0xb];
  }
  iVar18 = *(int *)((int)param_1 + 0x34);
  fVar23 = fVar23 * fVar20;
  local_420 = *(float *)(iVar18 + 0xe0) * fVar23 + *(float *)(iVar17 + 0x10) * fVar20;
  local_41c = *(float *)(iVar18 + 0xe4) * fVar23 + *(float *)(iVar17 + 0x14) * fVar20;
  local_418 = *(float *)(iVar18 + 0xe8) * fVar23 + *(float *)(iVar17 + 0x18) * fVar20;
  local_414 = *(float *)(iVar18 + 0xec) * fVar23 + *(float *)(iVar17 + 0x1c) * fVar20;
  if ((float)piVar11[0xb] == 0.0) {
    local_3e4 = 0.0;
  }
  else {
    local_3e4 = g_flOne / (float)piVar11[0xb];
  }
  local_3e4 = 0.0 - local_3e4;
  local_3f0 = local_3e4 * *(float *)(iVar18 + 0xe0);
  local_3ec = *(float *)(iVar18 + 0xe4) * local_3e4;
  local_3e8 = *(float *)(iVar18 + 0xe8) * local_3e4;
  local_3e4 = *(float *)(iVar18 + 0xec) * local_3e4;
  afStack_410[2] = param_1;
  afStack_410[3] = fVar24;
  (**(code **)(*piVar11 + 0x6c))(&local_3f0);
  (**(code **)(*piVar11 + 0x5c))(&fStack_424);
  (**(code **)(*piVar11 + 100))();
  iVar17 = 0;
  if (0 < *(int *)((int)param_1 + 0x334)) {
    do {
      (**(code **)(**(int **)(*(int *)((int)param_1 + 0x330) + iVar17 * 4) + 0x14))(param_2,param_1)
      ;
      iVar17 = iVar17 + 1;
    } while (iVar17 < *(int *)((int)param_1 + 0x334));
  }
  iVar18 = 0;
  pfVar13 = afStack_2cc + 6;
  iVar17 = 2;
  do {
    pfVar13[-3] = 0.0;
    pfVar13[-4] = 0.0;
    pfVar13[-5] = 0.0;
    pfVar13[-6] = 0.0;
    pfVar13[1] = 0.0;
    *pfVar13 = 0.0;
    pfVar13[-1] = 0.0;
    pfVar13[-2] = 0.0;
    pfVar13[5] = 0.0;
    pfVar13[4] = 0.0;
    pfVar13[3] = 0.0;
    pfVar13[2] = 0.0;
    pfVar13[8] = 0.0;
    pfVar13[9] = 0.0;
    pfVar13[10] = 0.0;
    pfVar13[0xb] = 0.0;
    pfVar13[0xc] = 0.0;
    *(undefined1 *)(pfVar13 + 0xd) = 0;
    pfVar13[6] = 0.0;
    pfVar13[7] = 0.0;
    pfVar13 = pfVar13 + 0x14;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iStack_3fc = 0;
  fStack_3f8 = 0.0;
  if (0 < *(int *)((int)fVar24 + 0xc)) {
    afStack_410[3] = 0.0;
    do {
      iVar17 = *(int *)(*(int *)((int)fVar24 + 0x58) + iVar18 * 4);
      iVar19 = *(int *)((int)fVar24 + 0x80) + (int)afStack_410[3];
      afStack_410[1] = *(float *)(*(int *)(*(int *)((int)param_1 + 0x28) + 0x34) + iVar18 * 4);
      iVar15 = *(int *)((int)param_1 + 0x30);
      local_420 = *param_2 * afStack_410[1];
      fStack_42c = *(float *)(iVar19 + 0x30) * local_420;
      fStack_428 = *(float *)(iVar19 + 0x34) * local_420;
      fStack_424 = *(float *)(iVar19 + 0x38) * local_420;
      local_420 = *(float *)(iVar19 + 0x3c) * local_420;
      pcVar14 = (char *)FUN_005070b0(&uStack_3fe);
      if ((*pcVar14 == '\0') && (*(int *)(iVar15 + 0x44) != 0)) {
        FUN_005070d0();
      }
      (**(code **)(**(int **)(iVar15 + 0x3c) + 0x60))(&fStack_42c,iVar19);
      iVar15 = *(int *)(iVar19 + 0xa4);
      if ((((iVar15 != 0) && ((int *)(iVar15 + 0xc) != (int *)0x0)) &&
          (iVar12 = *(int *)(iVar15 + 0xc), iVar12 != 0)) && (*(int *)(iVar12 + 8) == 2)) {
        fVar20 = 0.0 - *(float *)(*(int *)((int)afStack_410[0] + 0x4c) + iVar18 * 4);
        fStack_42c = fVar20 * fStack_42c;
        fStack_428 = fStack_428 * fVar20;
        fStack_424 = fStack_424 * fVar20;
        local_420 = local_420 * fVar20;
        pcVar14 = (char *)FUN_005070b0(&uStack_3fd);
        if ((*pcVar14 == '\0') && (*(int *)(iVar15 + 0x44) != 0)) {
          FUN_005070d0();
        }
        (**(code **)(**(int **)(iVar15 + 0x3c) + 0x60))(&fStack_42c,iVar19);
        if (((&iStack_3fc)[iVar17] == 0) ||
           (fVar20 = *(float *)(*(int *)((&iStack_3fc)[iVar17] + 0x3c) + 0x2c),
           pfVar13 = (float *)(*(int *)(iVar15 + 0x3c) + 0x2c),
           *pfVar13 <= fVar20 && fVar20 != *pfVar13)) {
          (&iStack_3fc)[iVar17] = iVar15;
        }
      }
      local_3ec = (*(float *)(*(int *)(*(int *)((int)param_1 + 0x24) + 0x10) + iVar18 * 4) +
                  *(float *)(*(int *)(*(int *)((int)param_1 + 0x20) + 0x20) + iVar18 * 4)) /
                  *(float *)(*(int *)((int)afStack_410[0] + 0x10) + iVar18 * 4);
      fVar20 = *(float *)(iVar19 + 0x34) * *(float *)(iVar19 + 0x68) -
               *(float *)(iVar19 + 100) * *(float *)(iVar19 + 0x38);
      fVar24 = *(float *)(iVar19 + 0x60) * *(float *)(iVar19 + 0x38) -
               *(float *)(iVar19 + 0x30) * *(float *)(iVar19 + 0x68);
      local_3d4 = *(float *)(iVar19 + 100) * *(float *)(iVar19 + 0x30) -
                  *(float *)(iVar19 + 0x34) * *(float *)(iVar19 + 0x60);
      afStack_410[2] = local_3d4 * local_3d4 + fVar24 * fVar24 + fVar20 * fVar20;
      if (afStack_410[2] == 0.0) {
        fVar23 = 0.0;
      }
      else {
        fVar23 = g_flOne / SQRT(afStack_410[2]);
      }
      local_3d4 = local_3d4 * fVar23;
      fVar24 = fVar24 * fVar23;
      fStack_3d0 = fVar23 * 0.0;
      fVar3 = *(float *)(iVar19 + 0x30);
      fVar4 = *(float *)(iVar19 + 0x34);
      fVar20 = fVar23 * fVar20;
      fVar5 = *(float *)(iVar19 + 0x38);
      fVar6 = *(float *)(iVar19 + 0x38);
      fVar7 = *(float *)(iVar19 + 0x30);
      fVar8 = *(float *)(iVar19 + 0x34);
      fVar21 = g_flOne / (float)*(int *)(*(int *)((int)afStack_410[0] + 0x68) + iVar17 * 4);
      fVar9 = *(float *)(*(int *)((int)afStack_410[0] + 0x28) + iVar18 * 4);
                    /* WI-MOV-004: wheels+0x28[i] * wheel+0x88 (drive torque scale into friction
                       axle pack) */
      fVar10 = *(float *)(iVar19 + 0x88);
      iVar15 = iVar17 * 0x50;
      afStack_2cc[iVar17 * 0x14] = *(float *)(iVar19 + 0x20) * fVar21 + afStack_2cc[iVar17 * 0x14];
      afStack_2cc[iVar17 * 0x14 + 1] =
           *(float *)(iVar19 + 0x24) * fVar21 + afStack_2cc[iVar17 * 0x14 + 1];
      afStack_2cc[iVar17 * 0x14 + 2] =
           *(float *)(iVar19 + 0x28) * fVar21 + afStack_2cc[iVar17 * 0x14 + 2];
      afStack_2cc[iVar17 * 0x14 + 3] =
           *(float *)(iVar19 + 0x2c) * fVar21 + afStack_2cc[iVar17 * 0x14 + 3];
      afStack_2cc[iVar17 * 0x14 + 5] =
           (local_3d4 * fVar3 - fVar20 * fVar6) + afStack_2cc[iVar17 * 0x14 + 5];
      afStack_2cc[iVar17 * 0x14 + 6] =
           (fVar20 * fVar8 - fVar24 * fVar7) + afStack_2cc[iVar17 * 0x14 + 6];
      afStack_2cc[iVar17 * 0x14 + 7] = afStack_2cc[iVar17 * 0x14 + 7];
      afStack_2cc[iVar17 * 0x14 + 4] =
           afStack_2cc[iVar17 * 0x14 + 4] + (fVar24 * fVar5 - local_3d4 * fVar4);
      fVar3 = afStack_2cc[iVar17 * 0x14 + 9];
      afStack_2cc[iVar17 * 0x14 + 8] = afStack_2cc[iVar17 * 0x14 + 8] + fVar20;
      *(float *)(acStack_280 + iVar15 + -0x24) =
           local_3d4 + *(float *)(acStack_280 + iVar15 + -0x24);
      *(float *)(acStack_280 + iVar15 + -0x20) =
           fVar23 * 0.0 + *(float *)(acStack_280 + iVar15 + -0x20);
      afStack_2cc[iVar17 * 0x14 + 9] = fVar24 + fVar3;
      *(float *)(acStack_280 + iVar15 + -0x14) =
           fVar9 * fVar10 * fVar21 + *(float *)(acStack_280 + iVar15 + -0x14);
      *(float *)(acStack_280 + iVar15 + -0x10) =
           *(float *)(*(int *)((int)afStack_410[0] + 0x34) + iVar18 * 4) * fVar21 +
           *(float *)(acStack_280 + iVar15 + -0x10);
      *(float *)(acStack_280 + iVar15 + -0xc) =
           *(float *)(*(int *)((int)afStack_410[0] + 0x40) + iVar18 * 4) * fVar21 +
           *(float *)(acStack_280 + iVar15 + -0xc);
      *(float *)(acStack_280 + iVar15 + -8) = afStack_410[1] + *(float *)(acStack_280 + iVar15 + -8)
      ;
      *(float *)(acStack_280 + iVar15 + -4) = local_3ec + *(float *)(acStack_280 + iVar15 + -4);
      if ((acStack_280[iVar15] == '\0') &&
         (*(char *)(iVar18 + *(int *)(*(int *)((int)param_1 + 0x24) + 0x1c)) == '\0')) {
        cVar16 = '\0';
      }
      else {
        cVar16 = '\x01';
      }
      afStack_410[3] = (float)((int)afStack_410[3] + 0xc0);
      iVar18 = iVar18 + 1;
      acStack_280[iVar15] = cVar16;
      fVar24 = afStack_410[0];
    } while (iVar18 < *(int *)((int)afStack_410[0] + 0xc));
  }
  uStack_22c = *(undefined4 *)((int)param_1 + 0x34c);
  iStack_430 = 0;
  if (0 < *(int *)((int)fVar24 + 100)) {
    pfVar13 = afStack_2cc + 6;
    iVar17 = 0;
    do {
      local_3ec = *pfVar13 * *pfVar13 + pfVar13[-2] * pfVar13[-2] + pfVar13[-1] * pfVar13[-1];
      if (local_3ec == 0.0) {
        fVar20 = 0.0;
      }
      else {
        fVar20 = g_flOne / SQRT(local_3ec);
        afStack_410[1] = fVar20;
      }
      pfVar13[-2] = pfVar13[-2] * fVar20;
      pfVar13[-1] = fVar20 * pfVar13[-1];
      *pfVar13 = fVar20 * *pfVar13;
      pfVar13[1] = pfVar13[1] * fVar20;
      afStack_410[2] = pfVar13[2] * pfVar13[2] + pfVar13[4] * pfVar13[4] + pfVar13[3] * pfVar13[3];
      if (afStack_410[2] == 0.0) {
        fVar20 = 0.0;
      }
      else {
        fVar20 = g_flOne / SQRT(afStack_410[2]);
        afStack_410[1] = fVar20;
      }
      iVar18 = (&iStack_3fc)[iStack_430];
      pfVar13[2] = fVar20 * pfVar13[2];
      pfVar13[3] = fVar20 * pfVar13[3];
      puVar1 = auStack_3cc + iVar17;
      pfVar13[4] = fVar20 * pfVar13[4];
      pfVar13[5] = fVar20 * pfVar13[5];
      pfVar13[6] = (float)puVar1;
      pfVar13[7] = (float)puVar1;
      if ((iVar18 == 0) || (*(char *)(iVar18 + 0x40) != '\0')) {
        *puVar1 = 2;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x2c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x28) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x24) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x20) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0xc) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 8) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 4) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x1c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x18) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x14) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x10) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x3c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x38) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x34) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x30) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x4c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x48) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x44) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x40) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x5c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x58) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x54) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x50) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x6c) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x68) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 100) = 0;
        *(undefined4 *)((int)auStack_3bc + iVar17 + 0x60) = 0;
      }
      else if ((iVar17 < 1) || (iVar18 != iStack_3fc)) {
        piVar11 = *(int **)(iVar18 + 0x3c);
        local_420 = 0.0;
        fStack_424 = 0.0;
        fStack_428 = 0.0;
        fStack_42c = 0.0;
        if (piVar11[2] != 0) {
          piVar11[2] = 0;
        }
        (**(code **)(*piVar11 + 0xc))(param_2,&fStack_42c,puVar1);
        iVar18 = (**(code **)(*piVar11 + 0x18))();
        if (iVar18 == 2) {
          FUN_0064b0b0(auStack_3cc + iVar17);
          *(int *)((int)aiStack_10c + iVar17 + 0x10) = piVar11[0x3c];
          *(int *)((int)aiStack_10c + iVar17 + 0x14) = piVar11[0x3d];
          *(int *)((int)aiStack_10c + iVar17 + 0x18) = piVar11[0x3e];
          *(int *)((int)aiStack_10c + iVar17 + 0x1c) = piVar11[0x3f];
          *(int *)((int)aiStack_10c + iVar17) = piVar11[0x38];
          *(int *)((int)aiStack_10c + iVar17 + 4) = piVar11[0x39];
          *(int *)((int)aiStack_10c + iVar17 + 8) = piVar11[0x3a];
          *(int *)((int)aiStack_10c + iVar17 + 0xc) = piVar11[0x3b];
        }
        else {
          param_1 = local_414;
          if (iVar18 != 4) goto LAB_0064c542;
          FUN_0064b0b0(auStack_3cc + iVar17);
          *(int *)((int)aiStack_10c + iVar17 + 0x10) = piVar11[0x34];
          *(int *)((int)aiStack_10c + iVar17 + 0x14) = piVar11[0x35];
          *(int *)((int)aiStack_10c + iVar17 + 0x18) = piVar11[0x36];
          *(int *)((int)aiStack_10c + iVar17 + 0x1c) = piVar11[0x37];
          *(int *)((int)aiStack_10c + iVar17) = piVar11[0x30];
          *(int *)((int)aiStack_10c + iVar17 + 4) = piVar11[0x31];
          *(int *)((int)aiStack_10c + iVar17 + 8) = piVar11[0x32];
          *(int *)((int)aiStack_10c + iVar17 + 0xc) = piVar11[0x33];
        }
        pfVar13[7] = (float)(auStack_11c + iVar17);
        param_1 = local_414;
      }
      else {
        pfVar13[6] = afStack_2a4[2];
        pfVar13[7] = afStack_2a4[3];
      }
LAB_0064c542:
      iStack_430 = iStack_430 + 1;
      pfVar13 = pfVar13 + 0x14;
      iVar17 = iVar17 + 0x80;
      fVar24 = afStack_410[0];
    } while (iStack_430 < *(int *)((int)afStack_410[0] + 100));
  }
  iVar17 = *(int *)((int)param_1 + 0x30);
  local_420 = 0.0;
  fStack_424 = 0.0;
  fStack_428 = 0.0;
  fStack_42c = 0.0;
  piVar11 = *(int **)(iVar17 + 0x3c);
  if (piVar11[2] != 0) {
    piVar11[2] = 0;
  }
  (**(code **)(*piVar11 + 0xc))(param_2,&fStack_42c,auStack_21c);
  uStack_1f8 = *(undefined4 *)((int)param_1 + 800);
  uStack_1f4 = *(undefined4 *)((int)param_1 + 0x324);
  uStack_1f0 = *(undefined4 *)((int)param_1 + 0x328);
  uStack_1ec = *(undefined4 *)((int)param_1 + 0x32c);
  iVar17 = *(int *)(iVar17 + 0x3c);
  FUN_0064b0b0();
  fVar20 = *(float *)(iVar17 + 0xd4);
  fVar23 = *(float *)(iVar17 + 0xd8);
  fVar3 = *(float *)(iVar17 + 0xd0);
  fStack_188 = fStack_1b8 * fVar23 + fStack_1c8 * fVar20 + fStack_1d8 * fVar3;
  fStack_184 = fStack_1b4 * fVar23 + fStack_1c4 * fVar20 + fStack_1d4 * fVar3;
  fStack_180 = fStack_1c0 * fVar20 + fStack_1d0 * fVar3 + fStack_1b0 * fVar23;
  uStack_17c = 0;
  uStack_198 = *(undefined4 *)(iVar17 + 0xc0);
  uStack_194 = *(undefined4 *)(iVar17 + 0xc4);
  uStack_190 = *(undefined4 *)(iVar17 + 200);
  uStack_18c = *(undefined4 *)(iVar17 + 0xcc);
  if (*(float *)((int)param_1 + 0x348) != 0.0) {
    iVar17 = *(int *)((int)param_1 + 0x10);
    fVar20 = *(float *)(*(int *)((int)param_1 + 0x18) + 0x10) * *(float *)((int)param_1 + 0x348) *
             *param_2;
    fStack_208 = fStack_208 + *(float *)((int)param_1 + 800) * *(float *)(iVar17 + 0x20) * fVar20;
    fStack_204 = fStack_204 + *(float *)((int)param_1 + 0x324) * *(float *)(iVar17 + 0x24) * fVar20;
    fStack_200 = fStack_200 + *(float *)((int)param_1 + 0x328) * *(float *)(iVar17 + 0x28) * fVar20;
    fStack_1fc = fStack_1fc + *(float *)((int)param_1 + 0x32c) * *(float *)(iVar17 + 0x2c) * fVar20;
  }
  fStack_3f8 = *param_2;
  fStack_3f4 = param_2[1];
  hkVehicleFrictionSolver_solve(&fStack_3f8,(int)param_1 + 0x1fc,auStack_2d8,(int)param_1 + 0x2cc);
  iVar17 = _finite((double)fStack_208);
  if ((((iVar17 != 0) && (iVar17 = _finite((double)fStack_204), iVar17 != 0)) &&
      (iVar17 = _finite((double)fStack_200), iVar17 != 0)) &&
     ((iVar17 = _finite((double)fStack_218), iVar17 != 0 &&
      (iVar17 = _finite((double)fStack_214), iVar17 != 0)))) {
    _finite((double)fStack_210);
  }
  FUN_0064b200();
  piVar11 = *(int **)(*(int *)((int)param_1 + 0x30) + 0x3c);
  fStack_42c = 0.0;
  (**(code **)(*piVar11 + 0x54))();
  (**(code **)(*piVar11 + 0x50))(auStack_21c);
  iVar17 = 0;
  if (0 < *(int *)((int)fVar24 + 100)) {
    do {
      fVar20 = afStack_410[iVar17];
      if (((fVar20 != 0.0) && (*(char *)((int)fVar20 + 0x40) == '\0')) &&
         ((iVar17 == 0 || (afStack_410[0] != afStack_410[1])))) {
        piVar11 = *(int **)((int)fVar20 + 0x3c);
        (**(code **)(*piVar11 + 0x54))(&stack0xfffffbc0);
        (**(code **)(*piVar11 + 0x50))((int)local_3e8 + 0x10);
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < *(int *)((int)fVar24 + 100));
  }
  iVar17 = 0;
  if (0 < *(int *)((int)fVar24 + 0xc)) {
    fStack_428 = 0.0;
    do {
      iVar18 = *(int *)(*(int *)((int)param_1 + 0xc) + 0x80) + (int)fStack_428;
      puVar2 = (undefined4 *)
               ((int)param_1 + 0x2cc + *(int *)(*(int *)((int)fVar24 + 0x58) + iVar17 * 4) * 0x1c);
      if ((*(char *)(iVar18 + 0x80) == '\0') || (*(char *)(iVar18 + 0xa8) == '\0')) {
        uVar22 = 0;
      }
      else {
        uVar22 = puVar2[2];
      }
      fStack_428 = (float)((int)fStack_428 + 0xc0);
      *(undefined4 *)(iVar18 + 0x94) = uVar22;
      *(undefined4 *)(iVar18 + 0x98) = puVar2[3];
      *(undefined4 *)(iVar18 + 0xa0) = puVar2[1];
      iVar17 = iVar17 + 1;
      *(undefined4 *)(iVar18 + 0x9c) = *puVar2;
    } while (iVar17 < *(int *)((int)fVar24 + 0xc));
  }
  return;
}
```
