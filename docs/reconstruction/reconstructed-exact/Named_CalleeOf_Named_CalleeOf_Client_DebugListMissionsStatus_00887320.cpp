// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_00887320
// -----------------------------------------------------------------------------
// Stable ID: aa_00887320
// Callee of Named_CalleeOf_Client_DebugListMissionsStatus
// Address:   0x00887320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_DebugListMissionsStatus: callee helper. Evidence string: "i_d_tfield.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_tfield.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_00887320, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_tfield.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_DebugListMissionsStatus
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_00887320(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5728;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a55bcc;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  param_1[0x146] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  NDUIWindow_ReloadInterface("i_d_tfield.xml");

  ExceptionList = local_c;

  return param_1;

}
