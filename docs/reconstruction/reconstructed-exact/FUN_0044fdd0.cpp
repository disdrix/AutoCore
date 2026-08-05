// =============================================================================
// FUN_0044fdd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044fdd0
// Address:   0x0044fdd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044fdd0 @ 0x0044fdd0
// Stable ID: aa_0044fdd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044fdd0, FUN_0044fe70.
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

void FUN_0044fdd0(void)



{

  int *piVar1;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x10);

  if (piVar1 != *(int **)(unaff_EDI + 0x14)) {

    do {

      if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      }

      piVar1 = piVar1 + 1;

    } while (piVar1 != *(int **)(unaff_EDI + 0x14));

  }

  FUN_0044fe70(0);

  return;

}
