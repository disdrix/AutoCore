// =============================================================================
// Named_CalleeOf_Mission_i_d_npc_xml_0087b890
// -----------------------------------------------------------------------------
// Stable ID: aa_0087b890
// Callee of Mission_i_d_npc_xml (+3 other named callers)
// Address:   0x0087b890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_i_d_npc_xml: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_i_d_npc_xml (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_0087b890.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_i_d_npc_xml (+3 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Mission_i_d_npc_xml_0087b890(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b531d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *param_1 = &PTR_FUN_00a58c6c;

  param_1[0xa9] = param_2;

  ExceptionList = local_c;

  return param_1;

}
