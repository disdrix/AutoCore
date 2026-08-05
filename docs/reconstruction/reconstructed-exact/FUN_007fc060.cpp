// =============================================================================
// FUN_007fc060
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc060
// Address:   0x007fc060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fc060 @ 0x007fc060
// Stable ID: aa_007fc060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_007fc060.
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

void FUN_007fc060(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x3068);

  if (((piVar1 != (int *)0x0) && (*(int *)(unaff_EDI + 0x306c) - (int)piVar1 >> 2 != 0)) &&

     (piVar1 != *(int **)(unaff_EDI + 0x306c))) {

    do {

      if ((int *)*piVar1 != (int *)0x0) {

        (**(code **)(*(int *)*piVar1 + 0x94))();

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != *(int **)(unaff_EDI + 0x306c));

  }

  return;

}
