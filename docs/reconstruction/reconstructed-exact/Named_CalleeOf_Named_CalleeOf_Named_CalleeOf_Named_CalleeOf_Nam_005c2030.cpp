// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c2030
// -----------------------------------------------------------------------------
// Stable ID: aa_005c2030
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005c2030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~359 non-empty decompiler lines.
//  - Control keywords: if×39, return×4, goto×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×16, ABS×2, FUN_004e88e0×2, FUN_0076f5f0×2, SQRT×2, FUN_004cd220, FUN_004e87d0, FUN_004e8dc0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x005c284b) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c2030(int param_1,float *param_2,uint32_t /* width from decompiler */ *param_3,float *param_4,float *param_5,

            char param_6,float *param_7,float *param_8,float *param_9,float param_10)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  ushort uVar6;

  float10 fVar7;

  float fVar8;

  float fVar9;

  uint8_t uStack_75;

  float local_74;

  float local_70;

  float fStack_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t auStack_20 [28];

  

  if (param_6 != '\0') {

    if ((((uint)param_4[0x79] & 0x40) == 0) ||

       (param_4[0x29] * param_4[0x29] + param_4[0x2a] * param_4[0x2a] +

        param_4[0x2b] * param_4[0x2b] != g_flZero)) {

      *param_5 = 0.0;

      param_5[1] = 0.0;

      param_5[2] = 0.0;

    }

    if ((*(byte *)((int)param_4 + 0x1e6) & 0x40) == 0) {

      local_68 = param_4[0x29];

      local_64 = param_4[0x2a];

      local_60 = param_4[0x2b];

      if ((*(byte *)((int)param_4 + 0x1e6) & 2) != 0) {

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        local_68 = (float)uVar6 * param_4[0x2c] * DAT_00aaa638 + local_68;

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        local_64 = (float)uVar6 * param_4[0x2d] * DAT_00aaa638 + local_64;

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        local_60 = (float)uVar6 * param_4[0x2e] * DAT_00aaa638 + local_60;

      }

      if ((*(byte *)((int)param_4 + 0x1e6) & 0x20) != 0) {

        local_68 = *param_7 + local_68;

        local_64 = param_7[1] + local_64;

        local_60 = param_7[2] + local_60;

        param_4[0x3c] = param_4[0x3c] + *param_7;

        param_4[0x3d] = param_4[0x3d] + param_7[1];

        param_4[0x3e] = param_4[0x3e] + param_7[2];

      }

    }

    else {

      fVar8 = param_4[0x2b];

      fVar9 = param_4[0x2a];

      local_4c = fVar9 * param_8[1];

      local_48 = fVar9 * param_8[2];

      fVar1 = param_4[0x29];

      local_68 = *param_9 * fVar1 + *param_8 * fVar9 + *param_7 * fVar8;

      local_64 = param_9[1] * fVar1 + local_4c + param_7[1] * fVar8;

      local_60 = param_9[2] * fVar1 + local_48 + param_7[2] * fVar8;

      local_5c = local_68;

      local_58 = local_64;

      local_54 = local_60;

      if ((*(byte *)((int)param_4 + 0x1e6) & 2) != 0) {

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        local_48 = (float)uVar6 * param_4[0x2e] * DAT_00aaa638;

        local_50 = *param_7 * local_48;

        local_4c = param_7[1] * local_48;

        local_48 = param_7[2] * local_48;

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        local_54 = (float)uVar6 * param_4[0x2d] * DAT_00aaa638;

        local_5c = *param_8 * local_54;

        local_58 = local_54 * param_8[1];

        local_54 = local_54 * param_8[2];

        iVar2 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar2 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

        }

        uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

        fVar8 = (float)uVar6 * param_4[0x2c] * DAT_00aaa638;

        local_68 = fVar8 * *param_9 + local_5c + local_50 + local_68;

        local_64 = fVar8 * param_9[1] + local_58 + local_4c + local_64;

        local_60 = fVar8 * param_9[2] + local_54 + local_48 + local_60;

      }

      fVar8 = param_4[0x3e];

      fVar9 = param_4[0x3d];

      fVar1 = param_4[0x3c];

      local_50 = fVar1 * *param_9 + *param_8 * fVar9 + *param_7 * fVar8;

      local_4c = fVar1 * param_9[1] + fVar9 * param_8[1] + param_7[1] * fVar8;

      local_48 = fVar1 * param_9[2] + fVar9 * param_8[2] + param_7[2] * fVar8;

      param_4[0x3c] = local_50;

      param_4[0x3d] = local_4c;

      param_4[0x3e] = local_48;

    }

    if ((*(byte *)((int)param_4 + 0x1e6) & 8) != 0) {

      FUN_0076f5f0(&local_68,&local_68);

    }

    if ((*(byte *)((int)param_4 + 0x1e6) & 1) == 0) {

      fVar8 = param_4[0x37];

      local_60 = fVar8 * local_60;

    }

    else {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      fVar8 = (float)uVar6 * param_4[0x38] * DAT_00aaa638 + param_4[0x37];

      local_60 = fVar8 * local_60;

    }

    local_68 = fVar8 * local_68;

    local_64 = fVar8 * local_64;

    *param_5 = *param_5 + local_68;

    param_5[2] = local_60 + param_5[2];

    param_5[1] = param_5[1] + local_64;

    pfVar3 = param_5 + 3;

    *pfVar3 = param_4[0x2f];

    param_5[4] = param_4[0x30];

    param_5[5] = param_4[0x31];

    if ((*(byte *)((int)param_4 + 0x1e6) & 4) != 0) {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      *pfVar3 = (float)uVar6 * param_4[0x32] * DAT_00aaa638 + *pfVar3;

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      param_5[4] = (float)uVar6 * param_4[0x33] * DAT_00aaa638 + param_5[4];

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      param_5[5] = (float)uVar6 * param_4[0x34] * DAT_00aaa638 + param_5[5];

    }

    if ((*(byte *)((int)param_4 + 0x1e6) & 0x10) != 0) {

      FUN_0076f5f0(pfVar3,pfVar3);

    }

    param_5[0xb] = 0.0;

    param_5[7] = 0.0;

    if (param_4[0x36] == 0.0) {

      param_5[6] = param_4[0x35];

    }

    else {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      param_5[6] = (float)uVar6 * param_4[0x36] * DAT_00aaa638 + param_4[0x35];

    }

    if (param_4[0x3b] == g_flZero) {

      local_74 = param_4[0x3a];

    }

    else {

      iVar2 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar2 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

      }

      uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

      local_74 = (float)uVar6 * param_4[0x3b] * DAT_00aaa638 + param_4[0x3a];

    }

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    local_70 = (float)uVar6 * local_74 * _DAT_009cc4a8 - local_74;

    param_5[8] = local_70;

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    fVar8 = ABS(local_70);

    uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    param_5[9] = 0.0;

    local_70 = (float)((-(uint)((uVar6 & 1) != 0) & 0xfffffffe) + 1);

    param_5[10] = local_74 - fVar8 * (float)(int)local_70;

    param_4[0x39] = ABS(local_74) + param_4[0x39];

  }

  local_74 = param_5[0xb] / *param_4;

  fVar8 = param_5[1];

  param_5[0xb] = param_5[0xb] + param_10;

  fVar9 = param_5[2];

  *param_2 = *param_5 * param_10 + *param_2;

  param_2[1] = fVar8 * param_10 + param_2[1];

  param_2[2] = param_10 * fVar9 + param_2[2];

  *param_5 = *param_5 + param_5[3] * param_10;

  param_5[1] = param_5[4] * param_10 + param_5[1];

  param_5[2] = param_5[5] * param_10 + param_5[2];

  local_30 = 0;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  if (param_1 == 0) {

    return 1;

  }

  if (*(int **)(param_1 + 0x10) == (int *)0x0) {

    return 1;

  }

  (**(code **)(**(int **)(param_1 + 0x10) + 0x144))();

  iVar2 = *(int *)(param_1 + 0x10);

  local_30 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

  local_2c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x84);

  local_28 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x88);

  local_24 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x8c);

  fVar7 = (float10)FUN_004cd220(*param_2,param_2[2]);

  local_70 = (float)fVar7;

  fVar8 = local_70 + g_flOverheatCoolFrac;

  if (param_2[1] <= fVar8 && fVar8 != param_2[1]) {

    param_2[1] = fVar8;

  }

  FUN_004e88e0(&local_50,&local_30);

  local_50 = param_5[8] + param_4[0x3c];

  local_4c = param_5[9] + param_4[0x3d];

  local_48 = param_5[10] + param_4[0x3e];

  pfVar3 = (float *)FUN_004e88e0(&local_5c,&local_30);

  local_68 = (*pfVar3 + local_50) - *param_2;

  local_60 = (pfVar3[2] + local_48) - param_2[2];

  local_64 = (pfVar3[1] + local_4c) - param_2[1];

  fVar8 = local_74 * DAT_00aaa690;

  local_70 = local_64 * fVar8 * param_10 + param_5[1];

  fStack_6c = local_60 * fVar8 * param_10 + param_5[2];

  param_5[2] = fStack_6c;

  fVar9 = local_74 * g_flLevelUpUiBase_Inferred;

  fVar8 = *param_5 + local_68 * fVar8 * param_10;

  local_74 = g_flOne - local_74;

  param_5[1] = local_70;

  local_50 = local_74 * fVar8 + local_68 * fVar9;

  *param_5 = fVar8;

  local_4c = local_74 * local_70 + local_64 * fVar9;

  *param_5 = local_50;

  local_48 = local_74 * fStack_6c + local_60 * fVar9;

  param_5[1] = local_4c;

  param_5[2] = local_48;

  local_74 = SQRT(*param_5 * *param_5 + param_5[1] * param_5[1] + param_5[2] * param_5[2]);

  if (local_74 <= param_5[7]) {

    fVar8 = param_5[7] / local_74;

    *param_5 = *param_5 * fVar8;

    param_5[1] = fVar8 * param_5[1];

    param_5[2] = fVar8 * param_5[2];

  }

  else {

    param_5[7] = local_74;

  }

  if (param_5[6] != g_flZero) {

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    if (uVar6 % 3 == 2) {

      param_5[4] = param_5[4] + param_5[6];

    }

    iVar2 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar2 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

    }

    uVar6 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

    uVar6 = uVar6 % 3;

    if (uVar6 == 2) {

      param_5[3] = param_5[3] + param_5[6];

      fVar8 = param_5[6] + param_5[5];

    }

    else {

      if (uVar6 != 1) goto LAB_005c2c7e;

      param_5[3] = param_5[3] - param_5[6];

      fVar8 = param_5[5] - param_5[6];

    }

    param_5[5] = fVar8;

  }

LAB_005c2c7e:

  if (local_68 * local_68 + local_60 * local_60 + local_64 * local_64 <

      param_4[0x39] * param_4[0x39]) {

    return 1;

  }

  FUN_004e9530(&fStack_40,param_5);

  pcVar4 = (char *)FUN_005d6870(&uStack_75);

  if (*pcVar4 == '\0') {

    fStack_38 = DAT_00af40b8;

    fStack_3c = DAT_00af40b4;

    fStack_40 = DAT_00af40b0;

    fStack_34 = DAT_00af40bc;

  }

  fStack_6c = fStack_40 * fStack_40 + fStack_38 * fStack_38 + fStack_3c * fStack_3c;

  if (fStack_6c == 0.0) {

    fVar8 = 0.0;

  }

  else {

    fVar8 = g_flOne / SQRT(fStack_6c);

    fStack_6c = fVar8;

  }

  fStack_40 = fVar8 * fStack_40;

  fStack_3c = fStack_3c * fVar8;

  fStack_38 = fStack_38 * fVar8;

  fStack_34 = fStack_34 * fVar8;

  FUN_004e8dc0(&fStack_40,auStack_20);

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e87d0(&local_50,auStack_20);

  *param_3 = *puVar5;

  param_3[1] = puVar5[1];

  param_3[2] = puVar5[2];

  param_3[3] = puVar5[3];

  return 0;

}
