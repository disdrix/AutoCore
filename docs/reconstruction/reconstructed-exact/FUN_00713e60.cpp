// =============================================================================
// FUN_00713e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00713e60
// Address:   0x00713e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713e60 @ 0x00713e60
// Stable ID: aa_00713e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00713e60.
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

int FUN_00713e60(int param_1,int param_2)



{

  float fVar1;

  float fVar2;

  float *pfVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = param_2 + -1;

  fVar1 = g_flZero;

  if (-1 < iVar5) {

    pfVar3 = (float *)(param_1 + iVar5 * 4);

    do {

      fVar1 = fVar1 + *pfVar3;

      pfVar3 = pfVar3 + -1;

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  if (-1 < iVar5) {

    pfVar3 = (float *)(param_1 + iVar5 * 4);

    fVar2 = g_flZero;

    do {

      fVar2 = fVar2 + *pfVar3;

      if (fVar1 * DAT_00a10e78 <= fVar2) break;

      iVar5 = iVar5 + -1;

      pfVar3 = pfVar3 + -1;

    } while (-1 < iVar5);

  }

  iVar4 = 0x4c;

  if (0x4b < iVar5 + 2) {

    iVar4 = iVar5 + 2;

  }

  return iVar4;

}
