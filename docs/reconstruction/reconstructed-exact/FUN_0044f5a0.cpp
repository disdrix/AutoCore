// =============================================================================
// FUN_0044f5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044f5a0
// Address:   0x0044f5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044f5a0 @ 0x0044f5a0
// Stable ID: aa_0044f5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, return×2, do×1.
//  - Notable callees: FUN_0044f5a0.
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

void FUN_0044f5a0(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar2 = (int *)**(int **)(unaff_ESI + 4);

  do {

    while( true ) {

      piVar1 = piVar2;

      if (piVar1 == *(int **)(unaff_ESI + 4)) {

        return;

      }

      if (piVar1[2] == *param_1) break;

      piVar2 = (int *)*piVar1;

    }

    piVar2 = (int *)*piVar1;

  } while (piVar1 == *(int **)(unaff_ESI + 4));

  *(int **)piVar1[1] = (int *)*piVar1;

  *(int *)(*piVar1 + 4) = piVar1[1];

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar1);

}
