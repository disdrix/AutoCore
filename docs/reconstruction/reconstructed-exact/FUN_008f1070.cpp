// =============================================================================
// FUN_008f1070
// -----------------------------------------------------------------------------
// Stable ID: aa_008f1070
// Address:   0x008f1070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f1070 @ 0x008f1070
// Stable ID: aa_008f1070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_008f1070.
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

void FUN_008f1070(uint32_t /* width from decompiler */ param_1)



{

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x544) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x544) + 4))(param_1);

  }

  if (*(int *)(unaff_ESI + 0x548) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x548) + 4))(param_1);

  }

  if (*(int *)(unaff_ESI + 0x54c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x54c) + 4))(param_1);

  }

  if (*(int *)(unaff_ESI + 0x550) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x550) + 4))(param_1);

  }

  if (*(int *)(unaff_ESI + 0x554) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x554) + 4))(param_1);

  }

  if (*(int *)(unaff_ESI + 0x558) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x558) + 4))(param_1);

  }

  return;

}
