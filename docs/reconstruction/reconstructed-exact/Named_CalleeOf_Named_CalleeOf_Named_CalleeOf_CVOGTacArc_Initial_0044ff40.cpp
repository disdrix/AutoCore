// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_0044ff40
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ff40
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x0044ff40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0044ff40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTacArc_Initial_0044ff40(int *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4,code *param_5)



{

  int iVar1;

  char cVar2;

  int iVar3;

  

  iVar3 = param_3 - param_2 >> 2;

  while (iVar1 = iVar3, 0 < iVar1) {

    iVar3 = iVar1 / 2;

    cVar2 = (*param_5)(*(uint32_t /* width from decompiler */ *)(param_2 + iVar3 * 4),*param_4);

    if (cVar2 != '\0') {

      param_2 = param_2 + 4 + iVar3 * 4;

      iVar3 = iVar1 + (-1 - iVar3);

    }

  }

  *param_1 = param_2;

  return;

}
