// =============================================================================
// FUN_0070e520
// -----------------------------------------------------------------------------
// Stable ID: aa_0070e520
// Address:   0x0070e520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070e520 @ 0x0070e520
// Stable ID: aa_0070e520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_0070e520, SQRT.
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



float10 FUN_0070e520(int param_1,int param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float10 fVar5;

  

  fVar4 = (float10)g_flZero;

  iVar3 = 0;

  if (3 < param_2) {

    iVar2 = (param_2 - 4U >> 2) + 1;

    iVar3 = iVar2 * 4;

    pfVar1 = (float *)(param_1 + 8);

    do {

      iVar2 = iVar2 + -1;

      fVar4 = (float10)pfVar1[1] * (float10)pfVar1[1] +

              (float10)*pfVar1 * (float10)*pfVar1 +

              (float10)pfVar1[-1] * (float10)pfVar1[-1] +

              (float10)pfVar1[-2] * (float10)pfVar1[-2] + fVar4;

      pfVar1 = pfVar1 + 4;

    } while (iVar2 != 0);

  }

  for (; iVar3 < param_2; iVar3 = iVar3 + 1) {

    fVar5 = (float10)*(float *)(param_1 + iVar3 * 4);

    fVar4 = fVar5 * fVar5 + fVar4;

  }

  return SQRT(fVar4 / (float10)param_2 + (float10)_DAT_00aaa6e0);

}
