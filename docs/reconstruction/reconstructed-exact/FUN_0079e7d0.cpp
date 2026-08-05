// =============================================================================
// FUN_0079e7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079e7d0
// Address:   0x0079e7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079e7d0 @ 0x0079e7d0
// Stable ID: aa_0079e7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0079e7d0, block.
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

/* WARNING: Removing unreachable block (ram,0x0079e810) */



uint32_t /* width from decompiler */ FUN_0079e7d0(int param_1)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0x2dc);

  if (piVar1 == *(int **)(param_1 + 0x2dc)) {

    return 1;

  }

  *(int *)piVar1[1] = *piVar1;

  *(int *)(*piVar1 + 4) = piVar1[1];

  if ((void *)piVar1[0x1b] != (void *)0x0) {

    operator_delete__((void *)piVar1[0x1b]);

  }

  piVar1[0x1b] = 0;

  piVar1[0x1b] = 0;

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar1);

}
