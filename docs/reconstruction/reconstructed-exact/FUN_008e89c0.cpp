// =============================================================================
// FUN_008e89c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e89c0
// Address:   0x008e89c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e89c0 @ 0x008e89c0
// Stable ID: aa_008e89c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_008e89c0.
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

void FUN_008e89c0(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x504) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x504) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x504) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x5a8) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x508) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x508) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x508) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x5b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5b0) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x5b0) + 0xfc))(0,0x3e800000);

    }

  }

  if (*(int *)(unaff_ESI + 0x5b4) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5b4) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x5b4) + 0xfc))(0,0x3e800000);

    }

  }

  return;

}
