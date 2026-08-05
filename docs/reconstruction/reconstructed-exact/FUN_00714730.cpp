// =============================================================================
// FUN_00714730
// -----------------------------------------------------------------------------
// Stable ID: aa_00714730
// Address:   0x00714730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714730 @ 0x00714730
// Stable ID: aa_00714730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00714730.
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

void FUN_00714730(float *param_1,float *param_2,float *param_3,uint param_4)



{

  float fVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float *pfVar5;

  float *pfVar6;

  

  iVar2 = (int)param_4 >> 1;

  pfVar6 = param_1 + (param_4 - 1);

  pfVar5 = param_3 + (param_4 - 1);

  pfVar3 = param_2;

  pfVar4 = param_3;

  if (0 < iVar2) {

    do {

      fVar1 = *param_1;

      pfVar4 = param_3 + 1;

      param_1 = param_1 + 1;

      pfVar3 = param_2 + 1;

      iVar2 = iVar2 + -1;

      *param_3 = fVar1 * *param_2;

      *pfVar5 = *pfVar6 * *param_2;

      param_2 = pfVar3;

      param_3 = pfVar4;

      pfVar5 = pfVar5 + -1;

      pfVar6 = pfVar6 + -1;

    } while (iVar2 != 0);

  }

  if ((param_4 & 1) != 0) {

    *pfVar4 = *param_1 * *pfVar3;

  }

  return;

}
