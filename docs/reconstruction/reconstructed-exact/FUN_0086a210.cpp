// =============================================================================
// FUN_0086a210
// -----------------------------------------------------------------------------
// Stable ID: aa_0086a210
// Address:   0x0086a210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086a210 @ 0x0086a210
// Stable ID: aa_0086a210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004133c0, FUN_007fbe50, FUN_0086a210.
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

void FUN_0086a210(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = (int *)**(int **)(unaff_EDI + 0x564);

  if (piVar1 != *(int **)(unaff_EDI + 0x564)) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)piVar1[2]);

  }

  FUN_004133c0(0);

  if (*(int *)(unaff_EDI + 0x5b4) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x5b4) + 0x458))();

  }

  if (*(int *)(unaff_EDI + 0x5b8) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x5b8) + 0x458))();

  }

  FUN_007fbe50();

  return;

}
