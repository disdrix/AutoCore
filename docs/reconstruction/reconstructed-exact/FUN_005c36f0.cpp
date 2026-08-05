// =============================================================================
// FUN_005c36f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c36f0
// Address:   0x005c36f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c36f0 @ 0x005c36f0
// Stable ID: aa_005c36f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~222 non-empty decompiler lines.
//  - Control keywords: if×24, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×9, FUN_0076f5f0×2, SQRT×2, FUN_00567ce0, FUN_005c36f0, FUN_0076e240, FUN_00788be0.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_005c36f0(float *param_1,float *param_2,int param_3,float *param_4,char param_5,

                 float *param_6,float *param_7,float *param_8,float param_9)



{

  float *pfVar1;

  float fVar2;

  ushort uVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float local_60;

  float local_5c;

  float local_58;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  

  if (param_5 != '\0') {

    *param_4 = *(float *)(param_3 + 0x9c);

    if ((*(byte *)(param_3 + 0x1e7) & 0x20) != 0) {

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      *param_4 = (float)uVar3 * *(float *)(param_3 + 0xa0) * DAT_00aaa638 + *param_4;

    }

    if (((((*(byte *)(param_3 + 0x1e4) & 8) == 0) || (*(float *)(param_3 + 0x74) != 0.0)) ||

        (*(float *)(param_3 + 0x7c) != 0.0)) || (*(float *)(param_3 + 0x9c) != 0.0)) {

      param_4[2] = 0.0;

      param_4[1] = 0.0;

      if ((*(byte *)(param_3 + 0x1e7) & 0x10) == 0) {

        pfVar1 = param_4 + 3;

        *pfVar1 = *(float *)(param_3 + 0x84);

        param_4[4] = *(float *)(param_3 + 0x88);

        param_4[5] = *(float *)(param_3 + 0x8c);

        if ((*(byte *)(param_3 + 0x1e7) & 2) != 0) {

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          *pfVar1 = (float)uVar3 * *(float *)(param_3 + 0x90) * DAT_00aaa638 + *pfVar1;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          param_4[4] = (float)uVar3 * *(float *)(param_3 + 0x94) * DAT_00aaa638 + param_4[4];

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          param_4[5] = (float)uVar3 * *(float *)(param_3 + 0x98) * DAT_00aaa638 + param_4[5];

        }

        if ((*(byte *)(param_3 + 0x1e7) & 8) != 0) {

          *pfVar1 = *pfVar1 + *param_6;

          param_4[4] = param_6[1] + param_4[4];

          param_4[5] = param_6[2] + param_4[5];

        }

      }

      else {

        fVar7 = *(float *)(param_3 + 0x8c);

        fVar6 = param_6[2];

        fVar5 = *(float *)(param_3 + 0x84);

        fVar8 = *(float *)(param_3 + 0x88);

        local_48 = param_7[1] * fVar8;

        fVar2 = param_8[2];

        local_44 = param_7[2] * fVar8;

        local_60 = *param_8 * fVar5 + *param_7 * fVar8 + *param_6 * fVar7;

        pfVar1 = param_4 + 3;

        local_5c = param_8[1] * fVar5 + local_48 + param_6[1] * fVar7;

        *pfVar1 = local_60;

        local_58 = fVar2 * fVar5 + local_44 + fVar6 * fVar7;

        param_4[4] = local_5c;

        param_4[5] = local_58;

        if ((*(byte *)(param_3 + 0x1e7) & 2) != 0) {

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          local_44 = (float)uVar3 * *(float *)(param_3 + 0x98) * DAT_00aaa638;

          local_4c = *param_6 * local_44;

          local_48 = param_6[1] * local_44;

          local_44 = param_6[2] * local_44;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          local_58 = (float)uVar3 * *(float *)(param_3 + 0x94) * DAT_00aaa638;

          local_60 = *param_7 * local_58;

          local_5c = param_7[1] * local_58;

          local_58 = param_7[2] * local_58;

          iVar4 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar4 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

          *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

          fVar5 = (float)uVar3 * *(float *)(param_3 + 0x90) * DAT_00aaa638;

          fVar7 = param_8[1];

          fVar6 = param_8[2];

          *pfVar1 = fVar5 * *param_8 + local_60 + local_4c + *pfVar1;

          param_4[4] = param_4[4] + fVar5 * fVar7 + local_5c + local_48;

          param_4[5] = param_4[5] + fVar5 * fVar6 + local_58 + local_44;

        }

      }

      if ((*(byte *)(param_3 + 0x1e7) & 4) != 0) {

        FUN_0076f5f0(param_4 + 3,param_4 + 3);

      }

      param_4[2] = *(float *)(param_3 + 0x74) + param_4[2];

      if ((*(byte *)(param_3 + 0x1e6) & 0x80) != 0) {

        iVar4 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar4 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

        param_4[2] = (float)uVar3 * *(float *)(param_3 + 0x78) * DAT_00aaa638 + param_4[2];

      }

      param_4[1] = *(float *)(param_3 + 0x7c) + param_4[1];

      if ((*(byte *)(param_3 + 0x1e7) & 1) != 0) {

        iVar4 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar4 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

        param_4[1] = (float)uVar3 * *(float *)(param_3 + 0x80) * DAT_00aaa638 + param_4[1];

      }

    }

  }

  local_38 = param_4[5];

  local_3c = param_4[4];

  fVar7 = param_4[3];

  local_60 = *param_1;

  local_5c = param_1[1];

  local_58 = param_1[2];

  local_34 = 0.0;

  if (SQRT(fVar7 * fVar7 + local_3c * local_3c + local_38 * local_38) <= _DAT_009d9e4c) {

    local_38 = DAT_00af40a8;

    local_3c = DAT_00af40a4;

    local_34 = DAT_00af40ac;

    fVar7 = DAT_00af40a0;

  }

  fVar6 = local_38 * local_38 + local_3c * local_3c + fVar7 * fVar7;

  if (fVar6 == 0.0) {

    local_40 = 0.0;

  }

  else {

    local_40 = g_flOne / SQRT(fVar6);

  }

  local_3c = local_3c * local_40;

  local_38 = local_38 * local_40;

  local_34 = local_34 * local_40;

  local_40 = local_40 * fVar7;

  FUN_00567ce0(&local_40,*param_4 * param_9 * DAT_00aaa7dc);

  local_20 = *param_2;

  local_18 = param_2[2];

  local_1c = param_2[1];

  fVar5 = local_5c - local_1c;

  local_58 = local_58 - local_18;

  fVar8 = local_60 - local_20;

  fVar6 = local_24 * local_24 * g_flLevelUpUiBase_Inferred - g_flOne;

  local_24 = local_24 * g_flLevelUpUiBase_Inferred;

  fVar7 = (local_28 * local_58 + local_2c * fVar5 + local_30 * fVar8) * g_flLevelUpUiBase_Inferred;

  *param_1 = local_20 +

             (local_2c * local_58 - local_28 * fVar5) * local_24 + local_30 * fVar7 + fVar6 * fVar8;

  param_1[1] = local_1c +

               (local_28 * fVar8 - local_58 * local_30) * local_24 +

               local_2c * fVar7 + fVar5 * fVar6;

  param_1[2] = local_18 +

               (fVar5 * local_30 - local_2c * fVar8) * local_24 +

               local_28 * fVar7 + local_58 * fVar6;

  if (param_4[1] != 0.0) {

    param_4[2] = param_4[1] * param_9 + param_4[2];

  }

  if ((param_4[2] != 0.0) &&

     ((0.0 <= param_4[2] ||

      (g_flMultiKillCountBlend <=

       (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +

       (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +

       (*param_1 - *param_2) * (*param_1 - *param_2))))) {

    local_4c = *param_1 - *param_2;

    local_48 = param_1[1] - param_2[1];

    local_44 = param_1[2] - param_2[2];

    FUN_00788be0(&local_60,&local_4c,param_4 + 3);

    if (local_58 * local_58 + local_5c * local_5c + local_60 * local_60 < DAT_009d9e48) {

      local_4c = g_flOne;

      local_48 = g_flOne;

      local_44 = g_flOne;

      FUN_0076e240(&local_60,param_4 + 3,&local_4c);

      FUN_0076f5f0(&local_60,&local_60);

    }

    fVar7 = param_4[2];

    *param_1 = local_60 * fVar7 * param_9 + *param_1;

    param_1[1] = local_5c * fVar7 * param_9 + param_1[1];

    param_1[2] = param_1[2] + local_58 * fVar7 * param_9;

  }

  return;

}
