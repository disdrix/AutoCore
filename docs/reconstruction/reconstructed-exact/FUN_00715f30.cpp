// =============================================================================
// FUN_00715f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00715f30
// Address:   0x00715f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00715f30 @ 0x00715f30
// Stable ID: aa_00715f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×7, do×5, while×5, goto×1, return×1.
//  - Notable callees: FUN_00715f30.
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

void FUN_00715f30(undefined **param_1,int param_2,int param_3,float param_4,int *param_5)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  float *pfVar9;

  float *pfVar10;

  int iVar11;

  undefined *puVar12;

  int iVar13;

  int *piVar14;

  int *piVar15;

  int iVar16;

  float *local_28;

  int local_24;

  undefined *local_18;

  int local_10 [4];

  

  iVar11 = (int)param_5;

  piVar14 = (int *)param_1;

  pfVar9 = (float *)((int)param_5 + 0x140);

  pfVar7 = (float *)((int)param_5 + 0x170);

  if (param_4 <= DAT_00a0f698) {

    local_18 = &DAT_00a112a0;

    puVar12 = &DAT_00af8af0;

  }

  else {

    local_18 = &DAT_00a11270;

    puVar12 = &DAT_00af8ad8;

  }

  param_5 = local_10;

  param_4 = 0.0;

  local_28 = (float *)0x0;

  param_1 = &PTR_DAT_00af8af8;

  pfVar8 = pfVar9;

  do {

    pfVar6 = local_28;

    if ((int)param_1 < 0xaf8b08) {

      iVar16 = *param_5;

      pfVar10 = (float *)(*(int *)(iVar16 + 4) + *piVar14 * 8);

      *pfVar8 = *pfVar10;

      pfVar8[1] = pfVar10[1];

      iVar13 = 0;

      if (0 < *(int *)(iVar16 + 0x18)) {

        piVar15 = *(int **)(iVar16 + 0x1c);

        do {

          if (*piVar15 == *piVar14) {

            iVar13 = *(int *)(iVar16 + 0x14);

            goto LAB_0071601c;

          }

          iVar13 = iVar13 + 1;

          piVar15 = piVar15 + 1;

        } while (iVar13 < *(int *)(iVar16 + 0x18));

      }

      iVar13 = *(int *)(iVar16 + 0x10);

LAB_0071601c:

      iVar16 = *(int *)(iVar16 + 8);

      fVar2 = *(float *)(iVar13 + piVar14[1] * 8);

      fVar3 = *(float *)(iVar13 + 4 + piVar14[1] * 8);

      iVar13 = *piVar14;

      fVar4 = *(float *)(iVar16 + 4 + iVar13 * 8);

      fVar5 = *(float *)(iVar16 + iVar13 * 8);

      pfVar10 = (float *)(iVar16 + iVar13 * 8);

      fVar4 = g_flOne / (fVar4 * fVar4 + fVar5 * fVar5);

      *pfVar8 = (fVar2 * *pfVar10 - fVar3 * pfVar10[1]) * fVar4 + *pfVar8;

      pfVar8[1] = (fVar2 * pfVar10[1] + fVar3 * *pfVar10) * fVar4 + pfVar8[1];

    }

    else {

      pfVar10 = (float *)(*(int *)(*param_1 + 4) + *piVar14 * 8);

      *pfVar8 = *pfVar10;

      pfVar8[1] = pfVar10[1];

    }

    iVar16 = 0;

    local_24 = 2;

    local_28 = pfVar7;

    do {

      fVar2 = g_flZero;

      if (0 < (int)pfVar6) {

        pfVar10 = pfVar9;

        iVar13 = (int)param_4;

        do {

          pfVar1 = (float *)(((iVar16 + *(int *)(((int)puVar12 - (int)local_10) + (int)param_5)) -

                             (int)pfVar9) + (int)pfVar10);

          fVar3 = *pfVar10;

          pfVar10 = pfVar10 + 1;

          iVar13 = iVar13 + -1;

          fVar2 = *pfVar1 * fVar3 + fVar2;

        } while (iVar13 != 0);

      }

      iVar16 = iVar16 + (int)pfVar6;

      *local_28 = fVar2;

      local_28 = local_28 + 1;

      local_24 = local_24 + -1;

    } while (local_24 != 0);

    param_4 = (float)((int)param_4 + 2);

    *pfVar8 = *pfVar7 + *pfVar8;

    param_1 = param_1 + 1;

    local_28 = (float *)((int)pfVar6 + 8);

    piVar14 = piVar14 + 2;

    param_5 = param_5 + 1;

    pfVar8[1] = *(float *)(iVar11 + 0x174) + pfVar8[1];

    pfVar8 = pfVar8 + 2;

    if (0xaf8b0f < (int)param_1) {

      if (0 < param_3) {

        iVar11 = (int)local_18 - (int)pfVar9;

        param_2 = param_2 - (int)pfVar9;

        do {

          pfVar7 = (float *)(iVar11 + (int)pfVar9);

          fVar2 = *pfVar9;

          pfVar9 = pfVar9 + 1;

          param_3 = param_3 + -1;

          *(float *)(param_2 + -4 + (int)pfVar9) = *pfVar7 + fVar2;

        } while (param_3 != 0);

      }

      return;

    }

  } while( true );

}
