// =============================================================================
// FUN_007fbfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbfb0
// Address:   0x007fbfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbfb0 @ 0x007fbfb0
// Stable ID: aa_007fbfb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_007fbfb0.
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

void FUN_007fbfb0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar1 = (int *)**(int **)(unaff_ESI + 0x3c08);

  if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {

    do {

      if (piVar1[2] == param_1) {

        piVar2 = (int *)*piVar1;

        if (piVar1 != *(int **)(unaff_ESI + 0x3c08)) {

          *(int **)piVar1[1] = piVar2;

          *(int *)(*piVar1 + 4) = piVar1[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar1);

        }

      }

      else {

        piVar2 = (int *)*piVar1;

      }

      piVar1 = piVar2;

    } while (piVar2 != *(int **)(unaff_ESI + 0x3c08));

  }

  return;

}
