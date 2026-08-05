// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f4d0
// Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
// Address:   0x0045f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxVertexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004568c0, FUN_0045f4d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxVertexBufferImpl
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_gfxVertexBufferImpl_0045f4d0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bd35b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  iVar1 = FUN_004568c0();

  param_1[2] = iVar1;

  *(uint8_t *)(iVar1 + 0x11) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 4) = param_1[2];

  *(uint32_t /* width from decompiler */ *)param_1[2] = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 8) = param_1[2];

  param_1[3] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  ExceptionList = local_c;

  return param_1;

}
