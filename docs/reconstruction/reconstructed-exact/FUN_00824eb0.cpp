// =============================================================================
// FUN_00824eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00824eb0
// Address:   0x00824eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824eb0 @ 0x00824eb0
// Stable ID: aa_00824eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00824eb0.
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

void FUN_00824eb0(void)



{

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x4fd) != '\0') {

    if (*(int **)(unaff_ESI + 0x544) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 8))(unaff_ESI + 0x530);

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x118))(unaff_ESI + 0x520);

      (**(code **)(**(int **)(unaff_ESI + 0x544) + 0x34c))();

    }

    if (*(int **)(unaff_ESI + 0x540) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 8))(unaff_ESI + 0x528);

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x118))(unaff_ESI + 0x518);

      (**(code **)(**(int **)(unaff_ESI + 0x540) + 0x34c))();

    }

    *(uint8_t *)(unaff_ESI + 0x4fd) = 0;

  }

  return;

}
