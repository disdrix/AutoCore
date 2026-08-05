// =============================================================================
// FUN_00808b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00808b50
// Address:   0x00808b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808b50 @ 0x00808b50
// Stable ID: aa_00808b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_004c26f0, FUN_00521440, FUN_00808b50.
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

void FUN_00808b50(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x31f0) != 0) {

    FUN_004c26f0(in_EAX);

    if (*(int *)(unaff_ESI + 0xe98) != 0) {

      FUN_00521440(*(int *)(unaff_ESI + 0x31f0) + 4);

    }

  }

  if (*(int **)(unaff_ESI + 0x1090) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x1090) + 0x448))();

  }

  if (*(int **)(unaff_ESI + 0x106c) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x106c) + 0x448))();

  }

  if (*(int **)(unaff_ESI + 0x1038) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x1038) + 0x448))();

  }

  *(uint8_t *)(unaff_ESI + 0x31f4) = 0;

  return;

}
