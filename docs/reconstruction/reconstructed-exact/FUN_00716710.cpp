// =============================================================================
// FUN_00716710
// -----------------------------------------------------------------------------
// Stable ID: aa_00716710
// Address:   0x00716710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716710 @ 0x00716710
// Stable ID: aa_00716710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×6, do×4, while×4, return×2, goto×1.
//  - Notable callees: ROUND×2, FUN_00716710, ftol.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00716710(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float *pfVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  float *pfVar8;

  float *pfVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  float10 extraout_ST0;

  float10 fVar14;

  float10 fVar15;

  float10 fVar16;

  float10 fVar17;

  float10 fVar18;

  int local_c;

  

  iVar3 = ftol();

  iVar6 = (int)ROUND((float)(extraout_ST0 * (float10)_DAT_00a0f6b0)) >> 1;

  if (iVar3 < 1) {

    return (float10)g_flOne - (float10)0.0 / (float10)iVar3;

  }

  fVar14 = (float10)0.0;

  iVar12 = 0x4000;

  iVar10 = iVar6 + 0x4000 >> 0xf;

  local_c = iVar3;

  do {

    iVar12 = iVar12 + (int)ROUND((float)(extraout_ST0 * (float10)_DAT_00a0f6b0));

    iVar7 = iVar6 + iVar12 >> 0xf;

    fVar15 = (float10)_DAT_00a132f4;

    iVar11 = iVar10 * 0x20 - (iVar12 + -0x3e00 >> 10);

    pfVar9 = (float *)(param_3 + iVar10 * 4);

    pfVar8 = (float *)(param_2 + iVar10 * 4);

    if (iVar11 < -0x6f) {

      uVar13 = -iVar11 - 0x50U >> 5;

      iVar11 = iVar11 + uVar13 * 0x20;

      iVar10 = uVar13 + iVar10;

      do {

        fVar1 = *pfVar8;

        fVar2 = *pfVar9;

        pfVar8 = pfVar8 + 1;

        pfVar9 = pfVar9 + 1;

        uVar13 = uVar13 - 1;

        fVar15 = (float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2 + fVar15;

      } while (uVar13 != 0);

    }

    fVar18 = fVar15;

    if (iVar11 < 0x70) {

      pfVar4 = (float *)(&DAT_00a13134 + iVar11 * 4);

      do {

        if (iVar7 <= iVar10) goto LAB_00716881;

        fVar1 = *pfVar9;

        pfVar9 = pfVar9 + 1;

        fVar16 = (float10)*pfVar8;

        pfVar8 = pfVar8 + 1;

        pfVar5 = pfVar4 + 0x20;

        iVar10 = iVar10 + 1;

        fVar18 = fVar16 * fVar16 + (float10)fVar1 * (float10)fVar1 + fVar18;

        fVar16 = fVar16 - (float10)*(float *)(param_2 + (iVar12 >> 0xf) * 4) * (float10)*pfVar4;

        fVar17 = (float10)fVar1 -

                 (float10)*(float *)(param_3 + (iVar12 >> 0xf) * 4) * (float10)*pfVar4;

        fVar15 = fVar16 * fVar16 + fVar17 * fVar17 + fVar15;

        pfVar4 = pfVar5;

      } while ((int)pfVar5 < 0xa132f4);

    }

    if (iVar10 < iVar7) {

      iVar10 = iVar7 - iVar10;

      do {

        fVar1 = *pfVar8;

        fVar2 = *pfVar9;

        pfVar8 = pfVar8 + 1;

        pfVar9 = pfVar9 + 1;

        iVar10 = iVar10 + -1;

        fVar16 = (float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2;

        fVar18 = fVar16 + fVar18;

        fVar15 = fVar15 + fVar16;

      } while (iVar10 != 0);

    }

LAB_00716881:

    local_c = local_c + -1;

    fVar14 = fVar15 / fVar18 + fVar14;

    iVar10 = iVar7;

    if (local_c == 0) {

      return (float10)g_flOne - fVar14 / (float10)iVar3;

    }

  } while( true );

}
