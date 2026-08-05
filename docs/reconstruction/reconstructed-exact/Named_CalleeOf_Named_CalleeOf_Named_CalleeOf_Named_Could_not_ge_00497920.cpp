// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_00497920
// -----------------------------------------------------------------------------
// Stable ID: aa_00497920
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
// Address:   0x00497920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00497920, FUN_00787520, FUN_00788db0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
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

uint8_t * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_00497920(uint8_t *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0dbe;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00787520();

  local_4 = 0;

  *param_1 = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  FUN_00788db0(param_1 + 0x14,0xa0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = param_2;

  DAT_00b035cc = param_1;

  ExceptionList = local_c;

  return param_1;

}
