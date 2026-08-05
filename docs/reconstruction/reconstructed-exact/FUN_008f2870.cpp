// =============================================================================
// FUN_008f2870
// -----------------------------------------------------------------------------
// Stable ID: aa_008f2870
// Address:   0x008f2870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f2870 @ 0x008f2870
// Stable ID: aa_008f2870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_007fbe50, FUN_008f2870.
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

void FUN_008f2870(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x564) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x564) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x568) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x568) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x56c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x56c) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x570) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x570) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x574) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x574) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x578) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x578) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x57c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x57c) + 0x458))();

  }

  FUN_007fbe50();

  return;

}
