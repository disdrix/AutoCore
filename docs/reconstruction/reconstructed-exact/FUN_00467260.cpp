// =============================================================================
// FUN_00467260
// -----------------------------------------------------------------------------
// Stable ID: aa_00467260
// Address:   0x00467260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00467260 @ 0x00467260
// Stable ID: aa_00467260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00443040, FUN_00467260.
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

int * FUN_00467260(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 != 0) {

    if ((*(int *)(unaff_EDI + 8) - iVar1) / 0x14 != 0) {

      iVar1 = (param_2 - iVar1) / 0x14;

      goto LAB_004672a7;

    }

  }

  iVar1 = 0;

LAB_004672a7:

  FUN_00443040(param_2,param_3);

  *param_1 = *(int *)(unaff_EDI + 4) + iVar1 * 0x14;

  return param_1;

}
