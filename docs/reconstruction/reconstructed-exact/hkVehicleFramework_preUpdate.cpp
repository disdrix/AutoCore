// =============================================================================
// hkVehicleFramework_preUpdate
// -----------------------------------------------------------------------------
// Stable ID: aa_0064cf20
// Address:   0x0064cf20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WI-MOV-003b: writes per-wheel contact hardpoint vec at wheel+0x20..+0x2c (stride 0xC0, base
   wheels+0x80). +0x20/+0x28 = contact X/Z used later by calcWheelTorque→torqueCurve2D args —
   NOT throttle/RPM writers. Spin speed written at wheel+0x8c. Order: tickSubsystems calls this (fw
   vtbl+0x14) before component updates. */

void __thiscall hkVehicleFramework_preUpdate(int *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  uint32_t /* width from decompiler */ *puVar6;
  float *pfVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int iStack_e4;
  float fStack_e0;
  int local_dc;
  float local_d8;
  float local_d4;
  int local_d0;
  float local_cc;
  float local_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float local_a0;
  float fStack_9c;
  uint32_t /* width from decompiler */ uStack_98;
  float fStack_94;
  uint32_t /* width from decompiler */ uStack_90;
  uint32_t /* width from decompiler */ uStack_8c;
  int iStack_88;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_68;
  uint8_t auStack_58 [4];
  int iStack_54;
  uint32_t /* width from decompiler */ uStack_4c;
  int iStack_44;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  uint32_t /* width from decompiler */ uStack_28;
  float fStack_24;
  uint32_t /* width from decompiler */ uStack_20;
  uint32_t /* width from decompiler */ uStack_1c;
  int iStack_18;
  
  local_d0 = param_1[3];
  local_c8 = (float)param_1[10];
  local_cc = (float)(*(int *)(param_1[0xc] + 0x3c) + 0x80);
  local_dc = 0;
  if (0 < *(int *)(local_d0 + 0xc)) {
    local_d4 = 0.0;
    local_d8 = 0.0;
    do {
      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1[3] + 0x80) + (int)local_d8);
      FUN_005d6ae0(local_cc,*(int *)((int)local_c8 + 0x1c) + (int)local_d4);
      FUN_005d68f0(local_cc,*(int *)((int)local_c8 + 0x10) + (int)local_d4);
      fVar10 = *(float *)(*(int *)((int)local_c8 + 0x28) + local_dc * 4);
      fVar9 = *(float *)(*(int *)(local_d0 + 0x10) + local_dc * 4);
      puVar6[4] = *puVar6;
      local_d8 = (float)((int)local_d8 + 0xc0);
      local_d4 = (float)((int)local_d4 + 0x10);
      puVar6[5] = puVar6[1];
      fVar9 = fVar9 + fVar10;
      puVar6[6] = puVar6[2];
      puVar6[7] = puVar6[3];
      puVar6[4] = fVar9 * (float)puVar6[0x14] + (float)puVar6[4];
      puVar6[5] = (float)puVar6[0x15] * fVar9 + (float)puVar6[5];
      puVar6[6] = (float)puVar6[0x16] * fVar9 + (float)puVar6[6];
      local_dc = local_dc + 1;
      puVar6[7] = (float)puVar6[0x17] * fVar9 + (float)puVar6[7];
    } while (local_dc < *(int *)(local_d0 + 0xc));
  }
  fVar10 = local_cc;
  pfVar3 = &local_a0;
  (**(code **)(*param_1 + 0x1c))();
  if (param_1[0xe] == 0) {
    FUN_0058e0b0();
    iStack_54 = param_1[0x7e];
    fStack_34 = fStack_a4;
    fStack_30 = local_a0;
    fStack_2c = fStack_9c;
    uStack_28 = uStack_98;
    fStack_24 = fStack_94;
    uStack_20 = uStack_90;
    uStack_1c = uStack_8c;
    iStack_18 = iStack_88;
    iVar4 = (**(code **)(*DAT_00b05060 + 0x10))(0x90,0x2c);
    *(uint16_t *)(iVar4 + 4) = 0x90;
    iVar4 = FUN_00581220(auStack_58);
    param_1[0xe] = iVar4;
    param_1[0x7d] = param_1[0xc] + 0xc;
    FUN_006343a0(param_1 + 0x7c);
    FUN_0055ff20(param_1[0xe]);
    if (-1 < iStack_44) {
      (**(code **)(*DAT_00b05060 + 0x14))(uStack_4c,iStack_44 * 8,0x12);
    }
  }
  else {
    FUN_00580dd0(&fStack_a4);
  }
  local_dc = 0;
  if (0 < *(int *)((int)local_d8 + 0xc)) {
    iStack_e4 = 0;
    do {
      pfVar7 = (float *)(*(int *)(param_1[3] + 0x80) + iStack_e4);
      fStack_94 = g_flOne;
      iStack_88 = 0;
      (**(code **)(*param_1 + 0x20))(local_dc,&fStack_a8);
      fVar10 = *(float *)(*(int *)(local_d0 + 0x28) + local_dc * 4);
      fVar9 = *(float *)(*(int *)((int)local_d8 + 0x10) + local_dc * 4);
      if (iStack_88 == 0) {
        pfVar7[0x2d] = 0.0;
        *(uint8_t *)(pfVar7 + 0x20) = 0;
        *(uint8_t *)(pfVar7 + 0x2a) = 1;
        pfVar7[0x29] = 0.0;
        pfVar7[0x2c] = fVar10;
        pfVar7[8] = pfVar7[4];
        pfVar7[9] = pfVar7[5];
        pfVar7[10] = pfVar7[6];
        pfVar7[0xb] = pfVar7[7];
        pfVar7[0xc] = 0.0 - pfVar7[0x14];
        pfVar7[0xd] = 0.0 - pfVar7[0x15];
        pfVar7[0xe] = 0.0 - pfVar7[0x16];
        pfVar7[0xf] = 0.0 - pfVar7[0x17];
        pfVar7[0x22] = 0.0;
        fVar10 = g_flOne;
LAB_0064d486:
        pfVar7[0x2b] = fVar10;
      }
      else {
        pfVar7[0xc] = fStack_a8;
        pfVar7[0xd] = fStack_a4;
        pfVar7[0xe] = local_a0;
        pfVar7[0xf] = fStack_9c;
        if (*(int *)(iStack_88 + 0x18) == 1) {
          fStack_e0 = *(float *)(iStack_88 + 0x20);
        }
        else {
          fStack_e0 = 0.0;
        }
        pfVar7[0x29] = fStack_e0;
        *(uint8_t *)(pfVar7 + 0x2a) = *(uint8_t *)((int)fStack_e0 + 0x40);
        *(uint8_t *)(pfVar7 + 0x20) = 1;
        pfVar1 = pfVar7 + 8;
        fVar10 = (fVar9 + fVar10) * fStack_94;
        pfVar7[0x2c] = fVar10 - fVar9;
        *pfVar1 = *pfVar7;
        pfVar7[9] = pfVar7[1];
        pfVar7[10] = pfVar7[2];
        pfVar7[0xb] = pfVar7[3];
        *pfVar1 = pfVar7[0x14] * fVar10 + *pfVar1;
        pfVar7[9] = pfVar7[0x15] * fVar10 + pfVar7[9];
        pfVar7[10] = pfVar7[0x16] * fVar10 + pfVar7[10];
        pfVar7[0xb] = pfVar7[0x17] * fVar10 + pfVar7[0xb];
        local_cc = *(float *)((int)pfVar7[0x29] + 0x4c);
        (**(code **)(*param_1 + 0x24))(pfVar7,&fStack_a8,&local_cc);
        pfVar7[0x22] = local_d8;
        fStack_b8 = pfVar7[0x16] * pfVar7[0xe] + pfVar7[0x15] * pfVar7[0xd] +
                    pfVar7[0xc] * pfVar7[0x14];
        (**(code **)(**(int **)(param_1[0xc] + 0x3c) + 0x58))(pfVar1,&local_d4);
        (**(code **)(*(int *)pfVar3[0xf] + 0x58))(pfVar1,&uStack_8c);
        fVar10 = g_flOne;
        if (0.0 - (float)param_1[0xc1] <= fStack_ac) {
          pfVar7[0x2d] = 0.0;
          fVar10 = fVar10 / (float)param_1[0xc1];
          goto LAB_0064d486;
        }
        fVar10 = DAT_00aaa668 / fStack_ac;
        pfVar7[0x2d] = fVar10 * (pfVar7[0xe] * (fStack_c0 - fStack_70) +
                                 pfVar7[0xd] * (fStack_c4 - fStack_74) +
                                pfVar7[0xc] * (local_c8 - fStack_78));
        pfVar7[0x2b] = fVar10;
      }
      iStack_e4 = iStack_e4 + 0xc0;
      local_dc = local_dc + 1;
      fVar10 = local_d4;
    } while (local_dc < *(int *)((int)local_d8 + 0xc));
  }
  FUN_005d6ae0(fVar10,param_1[4] + 0x10);
  iVar4 = *(int *)(param_1[0xc] + 0x3c);
  iVar5 = 0;
  iVar8 = 0;
  fStack_ac = *(float *)(iVar4 + 0x48) * fStack_70 + *(float *)(iVar4 + 0x44) * fStack_74 +
              fStack_78 * *(float *)(iVar4 + 0x40);
  if (0 < *(int *)((int)local_d8 + 0xc)) {
    iStack_e4 = 0;
    do {
      iVar4 = *(int *)(param_1[3] + 0x80) + iStack_e4;
      fVar10 = 0.0;
      if (*(char *)(iVar8 + *(int *)(param_1[9] + 0x1c)) == '\0') {
        fVar9 = (*(float *)(iVar4 + 0x9c) + fStack_ac) /
                *(float *)(*(int *)((int)local_d8 + 0x10) + iVar8 * 4);
        *(float *)(iVar4 + 0x8c) = fVar9;
        *(float *)(iVar4 + 0x90) = *param_2 * fVar9 + *(float *)(iVar4 + 0x90);
      }
      else {
        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x8c) = 0;
      }
      fVar9 = g_flOne;
      iVar2 = *(int *)(local_d0 + 0x1c);
      fStack_68 = *(float *)(*(int *)(param_1[6] + 0x14) + iVar8 * 4) * DAT_00a0f298;
      fVar13 = *(float *)(iVar2 + 4 + iVar5) * fStack_68;
      fVar14 = *(float *)(iVar2 + 8 + iVar5) * fStack_68;
      fStack_68 = *(float *)(iVar2 + iVar5) * fStack_68;
      local_cc = fStack_68 * fStack_68 + fVar14 * fVar14 + fVar13 * fVar13 + g_flOne;
      if (local_cc != 0.0) {
        fVar10 = g_flOne / SQRT(local_cc);
      }
      *(float *)(iVar4 + 0x7c) = fVar10;
      fVar12 = g_flLevelUpUiBase_Inferred;
      fVar13 = fVar13 * fVar10;
      *(float *)(iVar4 + 0x74) = fVar13;
      fVar14 = fVar14 * fVar10;
      *(float *)(iVar4 + 0x78) = fVar14;
      fStack_68 = fVar10 * fStack_68;
      *(float *)(iVar4 + 0x70) = fStack_68;
      iVar2 = param_1[4];
      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30);
      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34);
      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38);
      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);
      iVar4 = param_1[4];
      pfVar3 = (float *)(iVar4 + 0x30);
      fVar11 = (fStack_68 * *pfVar3 + fVar14 * *(float *)(iVar4 + 0x38) +
               fVar13 * *(float *)(iVar4 + 0x34)) * fVar12;
      fVar9 = fVar10 * fVar10 * fVar12 - fVar9;
      fVar12 = fVar10 * fVar12;
      fStack_a8 = fVar13 * *(float *)(iVar4 + 0x38) - fVar14 * *(float *)(iVar4 + 0x34);
      fStack_a4 = fVar14 * *pfVar3 - fStack_68 * *(float *)(iVar4 + 0x38);
      local_c8 = fStack_a8 * fVar12 + fVar11 * fStack_68 + fVar9 * *pfVar3;
      fStack_c4 = fStack_a4 * fVar12 + fVar13 * fVar11 + fVar9 * *(float *)(iVar4 + 0x34);
      fStack_c0 = (fStack_68 * *(float *)(iVar4 + 0x34) - fVar13 * *pfVar3) * fVar12 +
                  fVar14 * fVar11 + fVar9 * *(float *)(iVar4 + 0x38);
      fStack_bc = fVar12 * g_flZero + fVar10 * fVar11 + *(float *)(iVar4 + 0x3c) * fVar9;
      FUN_005d6ae0(local_d4,&local_c8);
      iStack_e4 = iStack_e4 + 0xc0;
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar8 < *(int *)((int)local_d8 + 0xc));
  }
  return;
}
