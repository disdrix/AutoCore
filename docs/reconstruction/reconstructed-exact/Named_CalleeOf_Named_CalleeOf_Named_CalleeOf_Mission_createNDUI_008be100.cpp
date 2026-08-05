// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008be100
// -----------------------------------------------------------------------------
// Stable ID: aa_008be100
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008be100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_invmis.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_invmis.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008bcf90, FUN_008be100, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_invmis.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008be100(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b68af;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  *param_1 = &PTR_FUN_00a4546c;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  local_4 = 1;

  param_1[0x13f] = 7;

  param_1[0x140] = 1;

  *(uint8_t *)(param_1 + 0x124) = 0;

  param_1[0x144] = 0xffffffff;

  param_1[0x145] = 0xffffffff;

  param_1[0x152] = 0;

  FUN_008bcf90();

  NDUIWindow_ReloadInterface("i_d_invmis.xml");

  ExceptionList = local_c;

  return param_1;

}
