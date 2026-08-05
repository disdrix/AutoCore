// =============================================================================
// FUN_00648ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00648ea0
// Address:   0x00648ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00648ea0 @ 0x00648ea0
// Stable ID: aa_00648ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_005070b0×4, FUN_005070d0×4, FUN_00635bd0, FUN_00648ea0.
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

void __fastcall FUN_00648ea0(int param_1)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  char *pcVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  uint32_t /* width from decompiler */ local_23c;

  uint8_t auStack_238 [2];

  uint8_t local_236;

  uint8_t local_235;

  int local_234;

  float local_22c;

  float local_228;

  float local_224;

  char local_214;

  float local_210;

  uint8_t *local_200;

  int local_1fc;

  int local_1f8;

  uint8_t local_1f0 [492];

  

  local_200 = local_1f0;

  iVar12 = 0;

  local_1fc = 0;

  local_1f8 = -0x7ffffff1;

  local_234 = param_1;

  FUN_00635bd0(&local_200);

  local_214 = *(int *)(param_1 + 0x24) != 0;

  local_23c = 0;

  if (0 < local_1fc) {

    do {

      iVar8 = *(int *)(*(int *)(param_1 + 8) + local_23c * 4);

      pfVar1 = (float *)(local_200 + iVar12);

      if (local_214 != '\0') {

        iVar9 = *(int *)(local_234 + 0x20);

        fVar2 = *(float *)(iVar9 + 4 + iVar12);

        fVar3 = *(float *)(iVar9 + iVar12);

        pfVar10 = (float *)(iVar9 + iVar12);

        fVar13 = (*(float *)(iVar9 + 8 + iVar12) * pfVar1[6] +

                  pfVar1[4] * *(float *)(iVar9 + iVar12) + pfVar10[1] * pfVar1[5]) *

                 g_flLevelUpUiBase_Inferred;

        fVar14 = pfVar1[7] * g_flLevelUpUiBase_Inferred;

        fVar4 = pfVar10[2];

        fVar16 = pfVar1[7] * pfVar1[7] * g_flLevelUpUiBase_Inferred - g_flOne;

        fVar5 = pfVar10[1];

        fVar6 = *pfVar10;

        local_228 = pfVar10[2] * fVar16;

        local_224 = pfVar10[3] * fVar16;

        local_22c = pfVar1[5] * fVar13 + *(float *)(iVar9 + 4 + iVar12) * fVar16;

        pfVar1[1] = pfVar1[1] +

                    (pfVar1[6] * *pfVar10 - *(float *)(iVar9 + 8 + iVar12) * pfVar1[4]) * fVar14 +

                    local_22c;

        fVar15 = fVar14 * g_flZero;

        pfVar1[2] = pfVar1[2] +

                    (pfVar1[4] * fVar5 - fVar3 * pfVar1[5]) * fVar14 +

                    pfVar1[6] * fVar13 + local_228;

        *pfVar1 = (fVar4 * pfVar1[5] - pfVar1[6] * fVar2) * fVar14 +

                  pfVar1[4] * fVar13 + fVar6 * fVar16 + *pfVar1;

        pfVar1[3] = pfVar1[3] + fVar15 + pfVar1[7] * fVar13 + local_224;

        iVar9 = *(int *)(local_234 + 0x20);

        fVar2 = *(float *)(iVar9 + 0x10 + iVar12);

        fVar3 = *(float *)(iVar9 + 0x14 + iVar12);

        iVar9 = iVar9 + 0x10 + iVar12;

        fVar4 = *(float *)(iVar9 + 8);

        fVar5 = pfVar1[5];

        fVar6 = *(float *)(iVar9 + 0xc);

        fVar13 = pfVar1[4];

        fVar14 = pfVar1[4];

        fVar15 = pfVar1[4];

        local_210 = pfVar1[7] * fVar2 + (pfVar1[5] * fVar4 - pfVar1[6] * fVar3);

        fVar16 = pfVar1[6];

        fVar7 = pfVar1[5];

        pfVar1[4] = fVar6 * pfVar1[4] + local_210;

        pfVar1[5] = pfVar1[5] * fVar6 + fVar3 * pfVar1[7] + (pfVar1[6] * fVar2 - fVar4 * fVar13);

        pfVar1[6] = pfVar1[6] * fVar6 + fVar4 * pfVar1[7] + (fVar3 * fVar14 - fVar5 * fVar2);

        pfVar1[7] = fVar6 * pfVar1[7] - (fVar16 * fVar4 + fVar7 * fVar3 + fVar2 * fVar15);

      }

      pcVar11 = (char *)FUN_005070b0(&local_235);

      if ((*pcVar11 == '\0') && (*(int *)(iVar8 + 0x44) != 0)) {

        FUN_005070d0();

      }

      if ((*(char *)(iVar8 + 0x40) == '\0') || (*(int *)(iVar8 + 8) == 0)) {

        (**(code **)(**(int **)(iVar8 + 0x3c) + 0x40))(pfVar1);

      }

      pcVar11 = (char *)FUN_005070b0(&local_236);

      if ((*pcVar11 == '\0') && (*(int *)(iVar8 + 0x44) != 0)) {

        FUN_005070d0();

      }

      if ((*(char *)(iVar8 + 0x40) == '\0') || (*(int *)(iVar8 + 8) == 0)) {

        (**(code **)(**(int **)(iVar8 + 0x3c) + 0x44))(pfVar1 + 4);

      }

      pcVar11 = (char *)FUN_005070b0(auStack_238);

      if ((*pcVar11 == '\0') && (*(int *)(iVar8 + 0x44) != 0)) {

        FUN_005070d0();

      }

      (**(code **)(**(int **)(iVar8 + 0x3c) + 0x50))(&DAT_00bc5630);

      pcVar11 = (char *)FUN_005070b0((int)&local_23c + 1);

      if ((*pcVar11 == '\0') && (*(int *)(iVar8 + 0x44) != 0)) {

        FUN_005070d0();

      }

      (**(code **)(**(int **)(iVar8 + 0x3c) + 0x54))(&DAT_00bc5630);

      local_23c = local_23c + 1;

      iVar12 = iVar12 + 0x20;

      param_1 = local_234;

    } while (local_23c < local_1fc);

  }

  if (-1 < local_1f8) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_200,local_1f8 << 5,0x12);

  }

  return;

}
