// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00466da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00466da0
// Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x00466da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00456960, FUN_00466da0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
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

void Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00466da0(int param_1)



{

  int *unaff_EBX;

  int iVar1;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if ((iVar1 == 0) || (*(int *)(unaff_EDI + 8) - iVar1 >> 2 == 0)) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_1 - iVar1 >> 2;

  }

  FUN_00456960(param_1);

  *unaff_EBX = *(int *)(unaff_EDI + 4) + iVar1 * 4;

  return;

}
