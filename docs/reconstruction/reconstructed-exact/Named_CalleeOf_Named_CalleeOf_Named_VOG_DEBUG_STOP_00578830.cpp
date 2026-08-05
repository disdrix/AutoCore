// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00578830
// -----------------------------------------------------------------------------
// Stable ID: aa_00578830
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00578830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_ctor, FUN_0054f3c0, FUN_00578830.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00578830(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a51f8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  CVOGHBBase_ctor(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_009d3fdc;

  FUN_0054f3c0();

  param_1[0x1ac] = 0;

  param_1[0x1ad] = 0;

  param_1[0x1ae] = 0;

  param_1[0x1a2] = 0;

  param_1[0x1a8] = 0;

  CVOGHBBase_AttachOwnerObject(param_1,(void *)0x0);

  param_1[0x19e] = DAT_009d3f88;

  param_1[0x19f] = DAT_009d3f8c;

  param_1[0x1a0] = DAT_009d3f90;

  param_1[0x1a1] = DAT_009d3f94;

  ExceptionList = local_c;

  return param_1;

}
