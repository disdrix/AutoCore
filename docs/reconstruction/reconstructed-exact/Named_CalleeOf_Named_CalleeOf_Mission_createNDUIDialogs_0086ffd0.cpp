// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0086ffd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086ffd0
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x0086ffd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_arena/i_d_arena_selection.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_arena/i_d_arena_selection.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0040fb90, FUN_0086e840, FUN_0086ffd0, FUN_0087b890, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_arena/i_d_arena_selection.xml".
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_0086ffd0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8c7f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a5d3ec;

  uVar1 = FUN_0040fb90();

  param_1[0x146] = uVar1;

  param_1[0x147] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  FUN_0086e840();

  *(uint8_t *)(param_1 + 0x144) = 0;

  param_1[0x143] = 0;

  NDUIWindow_ReloadInterface("i_d_arena/i_d_arena_selection.xml");

  ExceptionList = local_c;

  return param_1;

}
