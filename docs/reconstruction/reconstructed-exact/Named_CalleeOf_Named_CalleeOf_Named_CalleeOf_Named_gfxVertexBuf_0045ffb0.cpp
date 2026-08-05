// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBuf_0045ffb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045ffb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x0045ffb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_0045f5d0, FUN_0045ffb0, FUN_00460aa0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBuf_0045ffb0(int param_1,int *param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 == param_4) {

    *param_2 = param_3;

    return;

  }

  iVar2 = FUN_00460aa0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_3,param_3);

  iVar1 = *(int *)(param_1 + 8);

  for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x20) {

    FUN_0045f5d0();

  }

  *(int *)(param_1 + 8) = iVar2;

  *param_2 = param_3;

  return;

}
