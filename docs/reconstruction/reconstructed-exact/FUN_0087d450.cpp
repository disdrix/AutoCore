// =============================================================================
// FUN_0087d450
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d450
// Address:   0x0087d450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0087d450 @ 0x0087d450
// Stable ID: aa_0087d450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_0087d450.
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

void FUN_0087d450(uint32_t /* width from decompiler */ param_1)



{

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x5a0) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5a0) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x5a8) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5a8) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x5a4) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x588) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x588) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x58c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x58c) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x590) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x590) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x594) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x594) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x598) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x598) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x59c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x59c) + 0xfc))(param_1,0x3f000000);

  }

  if (*(int *)(unaff_ESI + 0x5ac) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0xfc))(param_1,0x3f000000);

  }

  return;

}
