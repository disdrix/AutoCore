// READABILITY (auto CF):
//  - Body size: ~296 non-empty decompiler lines.
//  - Control keywords: if×22, return×11, goto×1.
//  - Notable callees: SQRT×7, FUN_0074e700×4, FUN_004e88e0×2, FUN_004e9530×2, FUN_00567ce0×2, FUN_005a6e00×2, FUN_0074e6c0×2, FUN_0079a110×2.
//  - Return sites: 11.

// =============================================================================
// CVOGPlayerVehicle_UpdateTurretAiming
// -----------------------------------------------------------------------------
// Stable ID: aa_004f9570
// Address:   0x004f9570  (autoassault.exe, image base 0x400000)
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

void __fastcall CVOGPlayerVehicle_UpdateTurretAiming(int param_1)



{

  char cVar1;

  int iVar2;

  float *pfVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  float10 fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  float local_110;

  float local_10c;

  float local_108;

  float local_100;

  float local_fc;

  float local_f8;

  float local_f4;

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

  float local_c8;

  float fStack_c4;

  float fStack_c0;

  float local_bc;

  uint32_t /* width from decompiler */ uStack_b8;

  uint32_t /* width from decompiler */ uStack_b4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  uint8_t auStack_70 [4];

  uint8_t local_6c [8];

  uint8_t auStack_64 [20];

  uint8_t auStack_50 [16];

  uint8_t local_40 [16];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [28];

  

  iVar2 = *(int *)(param_1 + 600);

  if (iVar2 == 0) {

    return;

  }

  cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c) +

                   0x4ce);

  if (cVar1 != '\x02') {

    if (cVar1 != '\x04') {

      return;

    }

    if (*(int *)(param_1 + 0x340) == 0) {

      return;

    }

    if (*(int *)(param_1 + 0x344) == 0) {

      return;

    }

    iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

    local_bc = *(float *)(iVar2 + 0x90);

    uStack_b8 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94);

    uStack_b4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98);

    iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

    local_e0 = *(float *)(iVar2 + 0x80);

    local_dc = *(float *)(iVar2 + 0x84);

    local_d8 = *(float *)(iVar2 + 0x88);

    local_d4 = *(float *)(iVar2 + 0x8c);

    (**(code **)(**(int **)(param_1 + 0x340) + 0x18))(&local_bc);

    (**(code **)(**(int **)(param_1 + 0x344) + 0x18))(&fStack_c0);

    (**(code **)(**(int **)(param_1 + 0x340) + 0x14))(&local_e8);

    (**(code **)(**(int **)(param_1 + 0x344) + 0x14))(&local_ec);

    if ((*(int *)(param_1 + 0x36c) != 0) && (*(int *)(param_1 + 0x1a0) != 0)) {

      fVar6 = (float10)FUN_0079a110();

      FUN_0074e700(0,(float)fVar6);

      fVar7 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1a0) + 4) + 0xc) + 0x80) +

                        0x8c) * g_flMultiKillCountBlend;

      fVar8 = g_flOne;

      if ((g_flOne < fVar7) ||

         ((fVar8 = DAT_00aaa668, fVar7 < DAT_00aaa668 || (fVar8 = fVar7, fVar7 != g_flZero)))) {

        FUN_0074e6c0(fVar8);

      }

      else {

        FUN_0074e700(1,(float)fVar6);

      }

    }

    if (*(int *)(param_1 + 0x378) == 0) {

      return;

    }

    if (*(int *)(param_1 + 0x1a0) == 0) {

      return;

    }

    fVar6 = (float10)FUN_0079a110();

    FUN_0074e700(0,(float)fVar6);

    fVar7 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1a0) + 4) + 0xc) + 0x80) +

                      0x14c) * g_flMultiKillCountBlend;

    fVar8 = g_flOne;

    if (((fVar7 <= g_flOne) && (fVar8 = DAT_00aaa668, DAT_00aaa668 <= fVar7)) &&

       (fVar8 = fVar7, fVar7 == g_flZero)) {

      FUN_0074e700(1,(float)fVar6);

      return;

    }

    FUN_0074e6c0(fVar8);

    return;

  }

  if (*(int *)(param_1 + 0x340) == 0) {

    return;

  }

  if (*(int *)(param_1 + 0x344) == 0) {

    return;

  }

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  local_f8 = *(float *)(iVar2 + 0x5fc);

  local_fc = *(float *)(iVar2 + 0x5f8);

  local_100 = *(float *)(iVar2 + 0x5f4);

  local_f4 = 0.0;

  if (*(int *)(param_1 + 8) == 0) {

    if (*(int **)(param_1 + 0x48) == (int *)0x0) goto LAB_004f991b;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

    pfVar3 = (float *)FUN_004e96e0(auStack_50,iVar2 + 0x80);

    local_120 = *pfVar3;

    local_11c = pfVar3[1];

    local_118 = pfVar3[2];

    local_114 = pfVar3[3];

    iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

    pfVar3 = (float *)FUN_004e9530(auStack_30,iVar2 + 0x90);

  }

  else {

    pfVar3 = (float *)FUN_00404a20();

    local_120 = *pfVar3;

    local_11c = pfVar3[1];

    local_118 = pfVar3[2];

    local_114 = pfVar3[3];

    pfVar3 = (float *)FUN_00404c90();

  }

  local_130 = *pfVar3;

  local_12c = pfVar3[1];

  local_128 = pfVar3[2];

  local_124 = pfVar3[3];

LAB_004f991b:

  FUN_004249f0(&local_120,&local_100);

  local_100 = local_130 + local_100;

  local_fc = local_12c + local_fc;

  local_f8 = local_128 + local_f8;

  local_f4 = local_124 + local_f4;

  local_134 = 0.0;

  local_f0 = 0.0;

  local_ec = DAT_00aaa668;

  local_e8 = 0.0;

  local_e4 = 0.0;

  if (*(int *)(param_1 + 0x1a0) == 0) {

    if ((*(int *)(param_1 + 600) != 0) && (iVar2 = FUN_005a6e00(0), iVar2 != 0)) {

      piVar4 = (int *)FUN_005a6e00(0);

      uVar5 = (**(code **)(*piVar4 + 0x28))();

      pfVar3 = (float *)FUN_004e9530(auStack_20,uVar5);

      local_d0 = *pfVar3;

      local_cc = pfVar3[1];

      local_c8 = pfVar3[2];

      fStack_c4 = pfVar3[3];

    }

  }

  else {

    iVar2 = *(int *)(*(int *)(param_1 + 0x1a0) + 4);

    CVOGVehicle_GetWeaponSlotTransform

              (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x30),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x28),0,&local_d0,local_40);

    iVar2 = *(int *)(*(int *)(param_1 + 0x1a0) + 4);

    pfVar3 = *(float **)(*(int *)(iVar2 + 0x28) + 0x1c);

    local_134 = **(float **)(*(int *)(iVar2 + 0x18) + 0x14);

    local_f0 = *pfVar3;

    local_ec = pfVar3[1];

    local_e8 = pfVar3[2];

    local_e4 = pfVar3[3];

  }

  local_f0 = 0.0 - local_f0;

  local_e8 = 0.0 - local_e8;

  local_ec = 0.0 - local_ec;

  fVar8 = local_f0 * local_f0 + local_e8 * local_e8 + local_ec * local_ec;

  if (fVar8 == 0.0) {

    fVar8 = 0.0;

  }

  else {

    fVar8 = g_flOne / SQRT(fVar8);

  }

  local_f0 = fVar8 * local_f0;

  local_ec = local_ec * fVar8;

  local_e8 = local_e8 * fVar8;

  local_e4 = (0.0 - local_e4) * fVar8;

  FUN_00567ce0(&local_f0,0.0 - local_134);

  local_110 = local_100;

  local_10c = local_fc;

  local_108 = local_f8;

  FUN_004e8b60(&local_120,&local_a0);

  FUN_004e8ad0(&local_120,&local_b0);

  fVar8 = local_b0 * local_b0 + local_a8 * local_a8 + local_ac * local_ac;

  if (fVar8 == 0.0) {

    fVar8 = 0.0;

  }

  else {

    fVar8 = g_flOne / SQRT(fVar8);

  }

  local_a8 = local_a8 * fVar8;

  local_ac = local_ac * fVar8;

  local_a4 = local_a4 * fVar8;

  local_b0 = fVar8 * local_b0;

  fVar8 = local_a0 * local_a0 + local_98 * local_98 + local_9c * local_9c;

  if (fVar8 == 0.0) {

    fVar8 = 0.0;

  }

  else {

    fVar8 = g_flOne / SQRT(fVar8);

  }

  local_a0 = fVar8 * local_a0;

  local_9c = local_9c * fVar8;

  local_98 = local_98 * fVar8;

  local_94 = local_94 * fVar8;

  if ((SQRT(local_cc * local_cc + local_c8 * local_c8 + local_d0 * local_d0) <= DAT_00a0f718) ||

     (SQRT(local_10c * local_10c + local_108 * local_108 + local_110 * local_110) <= DAT_00a0f718))

  {

    local_134 = 0.0;

  }

  else {

    fVar11 = local_110 - local_d0;

    fVar7 = local_108 - local_c8;

    fVar8 = local_10c - local_cc;

    fVar9 = fVar11 * fVar11 + fVar7 * fVar7 + fVar8 * fVar8;

    if (SQRT(fVar9) <= DAT_00a0f718) {

      local_134 = 0.0;

    }

    else {

      fVar10 = 0.0;

      if (fVar9 != 0.0) {

        fVar10 = g_flOne / SQRT(fVar9);

      }

      fVar6 = (float10)FUN_0040d0a0(local_a0 * fVar10 * fVar11 + local_98 * fVar7 * fVar10 +

                                    local_9c * fVar8 * fVar10);

      local_134 = (float)((float10)DAT_00aaa7dc - fVar6);

    }

  }

  FUN_00567ce0(&local_b0,local_134);

  fVar8 = local_8c * local_e0;

  fVar7 = local_88 * local_e0;

  fVar9 = local_dc * local_90;

  fVar10 = local_e0 * local_90;

  local_e0 = local_84 * local_e0 + local_d4 * local_90 + (local_dc * local_88 - local_d8 * local_8c)

  ;

  fVar11 = local_dc * local_8c;

  local_dc = local_dc * local_84 + local_d4 * local_8c + (local_d8 * local_90 - fVar7);

  fVar7 = local_d8 * local_88;

  local_d8 = local_d8 * local_84 + local_d4 * local_88 + (fVar8 - fVar9);

  local_d4 = local_d4 * local_84 - (fVar7 + fVar11 + fVar10);

  local_108 = local_11c * local_e0 - local_dc * local_120;

  local_110 = local_114 * local_e0 +

              local_d4 * local_120 + (local_dc * local_118 - local_d8 * local_11c);

  local_7c = local_dc * local_114 +

             local_d4 * local_11c + (local_d8 * local_120 - local_118 * local_e0);

  local_74 = local_d4 * local_114 -

             (local_d8 * local_118 + local_dc * local_11c + local_e0 * local_120);

  local_78 = local_d8 * local_114 + local_d4 * local_118 + local_108;

  local_80 = local_110;

  FUN_004e8830(&local_80,local_6c);

  FUN_004e88e0(&local_bc,&local_100);

  (**(code **)(**(int **)(param_1 + 0x340) + 0x18))(&local_bc);

  (**(code **)(**(int **)(param_1 + 0x340) + 0x14))(auStack_70);

  pfVar3 = (float *)FUN_004e88e0(auStack_64,&local_d8);

  fStack_c4 = *pfVar3;

  fStack_c0 = pfVar3[1];

  local_bc = pfVar3[2];

  (**(code **)(**(int **)(param_1 + 0x344) + 0x18))(&fStack_c4);

  (**(code **)(**(int **)(param_1 + 0x344) + 0x14))(&local_78);

  return;

}
