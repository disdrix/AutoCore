// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_008717d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008717d0
// Callee of Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x008717d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00416c90, FUN_007fbd30, FUN_008717d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_008717d0(void)



{

  int in_EAX;

  

  FUN_00416c90();

  if (*(int *)(in_EAX + 0x5e8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5e8) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x5ec) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5ec) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x5f0) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5f0) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x5f4) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5f4) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x5f8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5f8) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x5fc) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x5fc) + 0x458))();

  }

  if (*(int *)(in_EAX + 0x600) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x600) + 0x458))();

  }

  FUN_007fbd30();

  return;

}
