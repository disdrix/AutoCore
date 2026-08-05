// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxPhaseAlphaTest_0074f320
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f320
// Callee of Named_CalleeOf_Named_gfxPhaseAlphaTest
// Address:   0x0074f320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxPhaseAlphaTest: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0074f320.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxPhaseAlphaTest
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxPhaseAlphaTest_0074f320(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x28);

  if (-1 < *(int *)(&DAT_00afe00c + iVar1 * 0xc)) {

    (**(code **)(**(int **)(param_1 + 0xc) + 0x108))(*(int **)(param_1 + 0xc));

  }

  (**(code **)(**(int **)(param_1 + 0xc) + 0x100))(*(int **)(param_1 + 0xc),param_2);

  *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar1 * 0xc) = param_2;

  return;

}
