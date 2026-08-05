// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0082ff80
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ff80
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x0082ff80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_m_int.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_m_int.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0082cfb0, FUN_0082d590, FUN_0082f850, FUN_0082ff80.
//  - Strings: "i_m_int.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_createNDUIDialogs
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0082ff80(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b44c1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0082d590(param_1);

  local_4 = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *param_1 = &PTR_FUN_00a71c94;

  param_1[0x15e] = DAT_00a1e800;

  param_1[0x15f] = DAT_00a1e804;

  param_1[0x160] = DAT_00a1e808;

  param_1[0x161] = DAT_00a1e80c;

  FUN_0082f850();

  FUN_0082cfb0("i_m_int.xml");

  ExceptionList = local_c;

  return param_1;

}
