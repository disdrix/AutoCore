// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00930010
// -----------------------------------------------------------------------------
// Stable ID: aa_00930010
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x00930010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008b30c0, FUN_00930010.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_00930010(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x1030);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if ((cVar2 != '\0') && (piVar1[0x145] != 0)) {

      FUN_008b30c0(0);

    }

  }

  return;

}
