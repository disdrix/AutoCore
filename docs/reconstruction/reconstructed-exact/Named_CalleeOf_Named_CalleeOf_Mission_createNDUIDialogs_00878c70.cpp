// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_00878c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00878c70
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x00878c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_arena/i_d_arena_console.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_arena/i_d_arena_console.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00877d90, FUN_00878110, FUN_00878c70, FUN_0087b890.
//  - Strings: "i_d_arena/i_d_arena_console.xml".
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_00878c70(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b905b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  param_1[0x143] = 0;

  *param_1 = &PTR_FUN_00a5a204;

  param_1[0x13f] = 0xf;

  param_1[0x140] = 1;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  uVar1 = DAT_00aaa6b0;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  param_1[0x150] = 0;

  *(uint8_t *)(param_1 + 0x149) = 0;

  param_1[0x14d] = uVar1;

  param_1[0x14c] = uVar1;

  FUN_00877d90();

  FUN_00878110("i_d_arena/i_d_arena_console.xml");

  param_1[0x151] = 0;

  param_1[0x152] = 0;

  ExceptionList = local_c;

  return param_1;

}
