// =============================================================================
// FUN_005b9ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b9ac0
// Address:   0x005b9ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b9ac0 @ 0x005b9ac0
// Stable ID: aa_005b9ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~252 non-empty decompiler lines.
//  - Control keywords: if×20, do×4, while×4, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×8, FUN_0076f5f0×6, FUN_0076e240×3, FUN_005b9740×2, ABS, FUN_005b9ac0, FUN_006a3db0.
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

void __thiscall FUN_005b9ac0(int param_1,char param_2)



{

  float *pfVar1;

  float *pfVar2;

  ushort uVar3;

  int *piVar4;

  uint8_t uVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  uint uVar9;

  float fVar10;

  float fVar11;

  float local_50;

  int local_4c;

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

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (param_2 != '\0') {

    if ((*(uint *)(param_1 + 0x178) & 2) == 0) {

      local_48 = *(float *)(param_1 + 0x144);

      local_44 = *(float *)(param_1 + 0x148);

      local_40 = *(float *)(param_1 + 0x14c);

    }

    else {

      local_48 = *(float *)(param_1 + 0x144) - *(float *)(param_1 + 0x134);

      local_44 = *(float *)(param_1 + 0x148) - *(float *)(param_1 + 0x138);

      local_40 = *(float *)(param_1 + 0x14c) - *(float *)(param_1 + 0x13c);

    }

    if ((*(uint *)(param_1 + 0x178) & 1) != 0) {

      local_8 = *(float *)(param_1 + 0xfc) * local_44;

      local_4 = *(float *)(param_1 + 0x100) * local_44;

      fVar10 = *(float *)(param_1 + 0xf0) * local_48;

      fVar11 = *(float *)(param_1 + 0xf4) * local_48;

      local_48 = *(float *)(param_1 + 0xec) * local_48 + *(float *)(param_1 + 0xf8) * local_44 +

                 *(float *)(param_1 + 0xe0) * local_40;

      local_44 = fVar10 + local_8 + *(float *)(param_1 + 0xe4) * local_40;

      local_40 = fVar11 + local_4 + *(float *)(param_1 + 0xe8) * local_40;

    }

    local_24 = local_48 + *(float *)(param_1 + 0x104);

    piVar8 = *(int **)(param_1 + 0x90);

    local_20 = *(float *)(param_1 + 0x108) + local_44;

    local_1c = *(float *)(param_1 + 0x10c) + local_40;

    *(float *)(param_1 + 0x98) = local_24;

    *(float *)(param_1 + 0x9c) = local_20;

    *(float *)(param_1 + 0xa0) = local_1c;

    iVar7 = 0;

    if (piVar8 != (int *)(param_1 + 0x90)) {

      do {

        iVar7 = iVar7 + 1;

        fVar10 = (float)iVar7 / (float)(*(int *)(param_1 + 0x88) + 1);

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        local_24 = ((float)uVar3 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        local_20 = ((float)uVar3 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

        iVar6 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar6 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

        local_1c = ((float)uVar3 * DAT_00aaa638 - DAT_00a0f298) * g_flLevelUpUiBase_Inferred;

        FUN_0076f5f0(&local_24,&local_24);

        local_50 = DAT_00a0f298 / ABS(fVar10 - DAT_00a0f298);

        if (((DAT_00a0f70c < local_50) && (fVar11 = g_flOne, g_flOne <= local_50)) ||

           (fVar11 = DAT_00a0f70c, local_50 <= DAT_00a0f70c)) {

          local_50 = fVar11;

        }

        DAT_00b054d0 = DAT_00b054d0 + 1;

        if (DAT_00b054d0 % *(int *)(param_1 + 0x158) == 0) {

          iVar6 = CVOGReaction_RandomUnitScalar();

          if (0xfffff < *(int *)(iVar6 + 0xc)) {

            *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = 0;

          }

          uVar3 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);

          *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;

          piVar8[0xc] = (int)((float)uVar3 * *(float *)(param_1 + 0x154) * DAT_00aaa638 +

                             *(float *)(param_1 + 0x150));

        }

        local_50 = (float)piVar8[0xc] * local_50;

        fVar11 = *(float *)(param_1 + 0x10c);

        local_24 = local_50 * local_24;

        local_20 = local_50 * local_20;

        local_1c = local_50 * local_1c;

        local_18 = fVar10 * local_48 + *(float *)(param_1 + 0x104) + local_24;

        piVar4 = (int *)*piVar8;

        local_14 = fVar10 * local_44 + *(float *)(param_1 + 0x108) + local_20;

        piVar8[2] = (int)local_18;

        piVar8[3] = (int)local_14;

        local_10 = fVar10 * local_40 + fVar11 + local_1c;

        piVar8[4] = (int)local_10;

        piVar8 = piVar4;

      } while (piVar4 != (int *)(param_1 + 0x90));

    }

  }

  piVar8 = *(int **)(param_1 + 0xc4);

  iVar7 = *piVar8;

  local_3c = (float)piVar8[2] - *(float *)(iVar7 + 8);

  local_38 = (float)piVar8[3] - *(float *)(iVar7 + 0xc);

  local_34 = (float)piVar8[4] - *(float *)(iVar7 + 0x10);

  pfVar2 = (float *)(param_1 + 0x110);

  local_30 = local_3c;

  local_2c = local_38;

  local_28 = local_34;

  local_18 = local_3c;

  local_14 = local_38;

  local_10 = local_34;

  FUN_0076e240(pfVar2,DAT_00b04c70 + 0x294,&local_3c);

  FUN_0076f5f0(pfVar2,pfVar2);

  iVar7 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar7 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

  }

  uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

  *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

  fVar10 = (float)uVar3 * *(float *)(param_1 + 0x3c) * DAT_00aaa638 + *(float *)(param_1 + 0x38);

  *pfVar2 = *pfVar2 * fVar10;

  *(float *)(param_1 + 0x114) = *(float *)(param_1 + 0x114) * fVar10;

  *(float *)(param_1 + 0x118) = *(float *)(param_1 + 0x118) * fVar10;

  FUN_0076f5f0(&local_30,&local_30);

  uVar9 = *(uint *)(param_1 + 0x178) >> 6 & 1;

  if (uVar9 == 0) {

    uVar5 = FUN_006a3db0();

    *(uint8_t *)(param_1 + 0x2f) = uVar5;

  }

  if (((*(uint *)(param_1 + 0x178) & 0x20) != 0) &&

     ((((uVar9 != 0 && (param_2 != '\0')) || ((*(uint *)(param_1 + 0x178) & 0x800) != 0)) &&

      (g_flZero < *(float *)(param_1 + 0x15c))))) {

    iVar7 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar7 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

    }

    uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

    *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

    if (((float)uVar3 * DAT_00aaa638 < *(float *)(param_1 + 0x15c)) &&

       (iVar7 = 0, 0 < *(int *)(param_1 + 0x168))) {

      do {

        FUN_005b9740(param_1 + 0x104);

        iVar7 = iVar7 + 1;

      } while (iVar7 < *(int *)(param_1 + 0x168));

    }

  }

  local_4c = 0;

  if (*(int *)(param_1 + 0x8c) != 1 && -1 < *(int *)(param_1 + 0x8c) + -1) {

    do {

      iVar7 = *piVar8;

      local_3c = (float)piVar8[2] - *(float *)(iVar7 + 8);

      pfVar2 = (float *)(piVar8 + 2);

      local_38 = (float)piVar8[3] - *(float *)(iVar7 + 0xc);

      local_34 = (float)piVar8[4] - *(float *)(iVar7 + 0x10);

      local_18 = local_3c;

      local_14 = local_38;

      local_10 = local_34;

      FUN_0076f5f0(&local_3c,&local_3c);

      local_24 = local_3c + local_30;

      local_20 = local_2c + local_38;

      local_1c = local_28 + local_34;

      pfVar1 = (float *)(piVar8 + 5);

      *pfVar1 = local_24;

      piVar8[6] = (int)local_20;

      piVar8[7] = (int)local_1c;

      local_30 = local_3c;

      local_2c = local_38;

      local_28 = local_34;

      FUN_0076e240(pfVar1,DAT_00b04c70 + 0x294,pfVar1);

      FUN_0076f5f0(pfVar1,pfVar1);

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      fVar11 = (float)uVar3 * *(float *)(param_1 + 0x3c) * DAT_00aaa638 + *(float *)(param_1 + 0x38)

      ;

      *pfVar1 = fVar11 * *pfVar1;

      piVar8[6] = (int)((float)piVar8[6] * fVar11);

      fVar10 = (float)piVar8[7];

      piVar8[7] = (int)(fVar10 * fVar11);

      piVar8[8] = (int)(*pfVar2 - *pfVar1);

      piVar8[9] = (int)((float)piVar8[3] - (float)piVar8[6]);

      piVar8[10] = (int)((float)piVar8[4] - fVar10 * fVar11);

      local_c = *pfVar2 + *pfVar1;

      local_8 = (float)piVar8[3] + (float)piVar8[6];

      local_4 = (float)piVar8[4] + (float)piVar8[7];

      *pfVar1 = local_c;

      piVar8[6] = (int)local_8;

      piVar8[7] = (int)local_4;

      piVar8[0xb] = *(int *)(param_1 + 0x2c);

      uVar9 = *(uint *)(param_1 + 0x178);

      if (((uVar9 & 0x20) != 0) &&

         (((((uVar9 & 0x40) != 0 && (param_2 != '\0')) || ((uVar9 & 0x800) != 0)) &&

          (g_flZero < *(float *)(param_1 + 0x15c))))) {

        iVar7 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar7 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

        }

        uVar3 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

        if (((float)uVar3 * DAT_00aaa638 < *(float *)(param_1 + 0x15c)) &&

           (iVar7 = 0, 0 < *(int *)(param_1 + 0x168))) {

          do {

            FUN_005b9740(pfVar2);

            iVar7 = iVar7 + 1;

          } while (iVar7 < *(int *)(param_1 + 0x168));

        }

      }

      piVar8 = (int *)*piVar8;

      local_4c = local_4c + 1;

    } while (local_4c < *(int *)(param_1 + 0x8c) + -1);

  }

  pfVar2 = (float *)(piVar8 + 5);

  FUN_0076e240(pfVar2,DAT_00b04c70 + 0x294,&local_30);

  FUN_0076f5f0(pfVar2,pfVar2);

  fVar10 = *(float *)(param_1 + 0x38);

  *pfVar2 = fVar10 * *pfVar2;

  fVar11 = (float)piVar8[6];

  piVar8[7] = (int)(fVar10 * (float)piVar8[7]);

  piVar8[6] = (int)(fVar10 * fVar11);

  piVar8[8] = (int)((float)piVar8[2] - *pfVar2);

  piVar8[9] = (int)((float)piVar8[3] - fVar10 * fVar11);

  piVar8[10] = (int)((float)piVar8[4] - (float)piVar8[7]);

  *pfVar2 = (float)piVar8[2] + *pfVar2;

  piVar8[6] = (int)((float)piVar8[3] + (float)piVar8[6]);

  piVar8[7] = (int)((float)piVar8[4] + (float)piVar8[7]);

  piVar8[0xb] = *(int *)(param_1 + 0x2c);

  return;

}
