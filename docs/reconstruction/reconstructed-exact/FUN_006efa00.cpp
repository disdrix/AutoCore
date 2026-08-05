// =============================================================================
// FUN_006efa00
// -----------------------------------------------------------------------------
// Stable ID: aa_006efa00
// Address:   0x006efa00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006efa00 @ 0x006efa00
// Stable ID: aa_006efa00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_006efa00, SQRT.
//  - Return sites: 2.

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

void __thiscall FUN_006efa00(int param_1,uint8_t *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float *pfVar18;

  float fVar19;

  uint8_t local_34;

  

  fVar19 = 0.0;

  local_34 = 0;

  if (0 < *(int *)(param_1 + 0xc)) {

    pfVar18 = (float *)(param_1 + 0x18);

    do {

      fVar1 = param_3[4];

      fVar8 = param_3[6];

      fVar2 = param_3[5];

      fVar9 = param_3[7];

      fVar3 = pfVar18[-2];

      fVar10 = param_3[3];

      fVar4 = pfVar18[-1];

      fVar5 = *pfVar18;

      fVar6 = pfVar18[1];

      fVar11 = *param_3 - pfVar18[-2];

      fVar12 = param_3[1] - pfVar18[-1];

      fVar13 = param_3[2] - *pfVar18;

      fVar7 = pfVar18[1];

      fVar14 = (fVar1 - fVar3) - fVar11;

      fVar17 = (fVar2 - fVar4) - fVar12;

      fVar15 = (fVar8 - fVar5) - fVar13;

      fVar16 = fVar14 * fVar11 + fVar17 * fVar12 + fVar13 * fVar15;

      fVar16 = fVar16 + fVar16;

      if (fVar16 < g_flZero) {

        fVar14 = fVar14 * fVar14 + fVar17 * fVar17 + fVar15 * fVar15;

        fVar15 = fVar16 * fVar16 -

                 ((fVar11 * fVar11 + fVar12 * fVar12 + fVar13 * fVar13) - pfVar18[1] * pfVar18[1]) *

                 fVar14 * DAT_00aaa690;

        if ((((fVar15 < g_flZero == (fVar15 == g_flZero)) &&

             (fVar15 = (-fVar16 - SQRT(fVar15)) * DAT_00a0f298, fVar15 < fVar14)) &&

            (g_flZero <= fVar15)) && (fVar15 = fVar15 / fVar14, fVar15 < param_4[5])) {

          param_4[5] = fVar15;

          local_34 = 1;

          fVar14 = g_flOne - fVar15;

          *param_4 = (fVar1 - fVar3) * fVar15 + fVar11 * fVar14;

          param_4[1] = (fVar2 - fVar4) * fVar15 + fVar12 * fVar14;

          param_4[2] = (fVar8 - fVar5) * fVar15 + fVar13 * fVar14;

          param_4[3] = (fVar9 - fVar6) * fVar15 + (fVar10 - fVar7) * fVar14;

          fVar1 = g_flOne / pfVar18[1];

          param_4[4] = fVar19;

          *param_4 = fVar1 * *param_4;

          param_4[1] = fVar1 * param_4[1];

          param_4[2] = fVar1 * param_4[2];

          param_4[3] = fVar1 * param_4[3];

        }

      }

      fVar19 = (float)((int)fVar19 + 1);

      pfVar18 = pfVar18 + 4;

    } while ((int)fVar19 < *(int *)(param_1 + 0xc));

    *param_2 = local_34;

    return;

  }

  *param_2 = 0;

  return;

}
