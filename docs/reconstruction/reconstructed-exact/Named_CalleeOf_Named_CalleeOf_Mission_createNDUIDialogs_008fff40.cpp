// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008fff40
// -----------------------------------------------------------------------------
// Stable ID: aa_008fff40
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008fff40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_body.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_body.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008fd530, FUN_008ffe20, FUN_008fff40.
//  - Strings: "i_d_body.xml".
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008fff40(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7c23;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  *param_1 = &PTR_FUN_00a33cec;

  param_1[0x1ef] = 0;

  param_1[0x1f0] = 0;

  param_1[0x1f1] = 0;

  param_1[0x1f5] = 0;

  param_1[0x1f6] = 0;

  param_1[0x1f7] = 0;

  uVar1 = DAT_00aaabe8;

  local_4 = 2;

  param_1[0x140] = 1;

  param_1[0x165] = uVar1;

  param_1[0x13f] = 0x10;

  param_1[0x146] = 7;

  param_1[0x147] = 7;

  param_1[0x166] = 0;

  param_1[0x1ec] = 0xffffffff;

  param_1[0x1f2] = 0xffffffff;

  param_1[0x1f8] = 0xffffffff;

  FUN_008fd530();

  FUN_008ffe20("i_d_body.xml");

  ExceptionList = local_c;

  return param_1;

}
