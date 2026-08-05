// =============================================================================
// FUN_008e1bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1bb0
// Address:   0x008e1bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e1bb0 @ 0x008e1bb0
// Stable ID: aa_008e1bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008e1bb0, sprintf.
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

void FUN_008e1bb0(void)



{

  int unaff_ESI;

  char local_100 [256];

  

  if ((*(int *)(unaff_ESI + 0x51c) != 0) && (DAT_00d1b6d8 != 0)) {

    sprintf(local_100,"%i",(int)*(short *)(DAT_00d1b6d8 + 0x580));

    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x1d8))(local_100,1,1);

    (**(code **)(**(int **)(unaff_ESI + 0x51c) + 0x34c))();

  }

  return;

}
