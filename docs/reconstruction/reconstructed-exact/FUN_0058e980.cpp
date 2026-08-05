// =============================================================================
// FUN_0058e980
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e980
// Address:   0x0058e980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058e980 @ 0x0058e980
// Stable ID: aa_0058e980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: if×16, do×3, return×3, while×3, goto×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_005070d0×2, SQRT×2, FUN_004e8bf0, FUN_005070b0, FUN_0058e980.
//  - Return sites: 3.

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

void __thiscall FUN_0058e980(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  ushort uVar1;

  ushort uVar2;

  float *pfVar3;

  int iVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  uint8_t local_59;

  float local_58;

  uint local_54;

  int local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  iVar7 = 0;

  uVar8 = 0;

  local_54 = 0;

  local_50 = param_1;

  do {

    do {

      do {

        iVar4 = *(int *)(param_1 + 0x50);

        if (iVar4 == 0) {

          if (iVar7 != 0) {

            return;

          }

          iVar7 = *(int *)(param_1 + 0x260);

        }

        else {

          if (*(int *)(iVar4 + 0xc) <= (int)uVar8) {

            return;

          }

          iVar7 = *(int *)(*(int *)(iVar4 + 8) + uVar8 * 4);

          uVar8 = uVar8 + 1;

          local_54 = uVar8;

        }

        if (iVar7 == 0) {

          return;

        }

      } while ((*(char *)(iVar7 + 0x40) != '\0') ||

              ((param_2[0xd] != 0 && (param_2[0xd] != *(int *)(param_1 + 0x14)))));

      iVar4 = *(int *)(iVar7 + 0x3c);

      local_40 = *(float *)(iVar4 + 0xb0) - (float)param_2[8];

      local_3c = *(float *)(iVar4 + 0xb4) - (float)param_2[9];

      local_38 = *(float *)(iVar4 + 0xb8) - (float)param_2[10];

      local_4c = local_38 * local_38 + local_3c * local_3c + local_40 * local_40;

      local_58 = SQRT(local_4c);

      pfVar3 = (float *)*param_2;

      param_1 = local_50;

    } while (*pfVar3 < local_58);

    if (DAT_009d51dc < local_58) {

      local_34 = 0.0;

      if (local_4c != 0.0) {

        local_34 = g_flOne / SQRT(local_4c);

        local_44 = local_34;

      }

      local_3c = local_3c * local_34;

      local_40 = local_34 * local_40;

      local_38 = local_38 * local_34;

      local_34 = (*(float *)(iVar4 + 0xbc) - (float)param_2[0xb]) * local_34;

      local_48 = local_4c;

    }

    else {

      local_38 = 0.0;

      local_40 = 0.0;

      local_34 = 0.0;

      local_3c = g_flOne;

    }

    fVar9 = g_flOne - pfVar3[8];

    local_40 = fVar9 * local_40;

    local_38 = local_38 * fVar9;

    local_34 = local_34 * fVar9;

    local_3c = local_3c * fVar9;

    if (*(char *)(pfVar3 + 9) == '\0') {

      local_3c = (float)param_2[5] + local_3c;

      local_40 = (float)param_2[4] + local_40;

      local_38 = (float)param_2[6] + local_38;

      local_34 = (float)param_2[7] + local_34;

    }

    else {

      local_30 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x30);

      local_2c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x34);

      local_28 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38);

      local_24 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c);

      FUN_004e8bf0(&DAT_00b04e20,&local_30,param_2 + 4,&local_20);

      local_40 = local_20 + local_40;

      local_3c = local_1c + local_3c;

      local_38 = local_18 + local_38;

      local_34 = local_14 + local_34;

    }

    uVar6 = uVar8 & 0x80000001;

    if ((int)uVar6 < 0) {

      uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;

    }

    fVar9 = g_flOne;

    if (uVar6 == 1) {

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      fVar10 = DAT_00aaaaf0;

      fVar11 = DAT_00a0f71c;

      fVar9 = g_flOne;

      uVar2 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      local_40 = ((float)uVar2 * fVar10 - fVar11) + local_40;

      local_38 = ((float)uVar1 * fVar10 - fVar11) + local_38;

      uVar8 = local_54;

    }

    pfVar3 = (float *)*param_2;

    fVar11 = pfVar3[1];

    if (pfVar3[10] == 1.4013e-45) {

      fVar10 = fVar9 - local_58 / *pfVar3;

LAB_0058ed19:

      fVar11 = fVar10 * fVar11;

    }

    else if (pfVar3[10] == 2.8026e-45) {

      fVar10 = fVar9 - local_58 / *pfVar3;

      fVar10 = fVar10 * fVar10;

      goto LAB_0058ed19;

    }

    local_40 = local_40 * fVar11;

    local_3c = local_3c * fVar11;

    local_38 = local_38 * fVar11;

    local_34 = local_34 * fVar11;

    if (*(char *)((int)pfVar3 + 0x25) != '\0') {

      fVar11 = *(float *)(*(int *)(iVar7 + 0x3c) + 0x2c);

      fVar10 = 0.0;

      if (fVar11 != 0.0) {

        fVar10 = fVar9 / fVar11;

      }

      local_40 = fVar10 * local_40;

      local_3c = local_3c * fVar10;

      local_38 = local_38 * fVar10;

      local_34 = local_34 * fVar10;

    }

    FUN_005070d0();

    pcVar5 = (char *)FUN_005070b0(&local_59);

    if ((*pcVar5 == '\0') && (*(int *)(iVar7 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar7 + 0x3c) + 0x5c))(&local_40);

    param_1 = local_50;

  } while( true );

}
