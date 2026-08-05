// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008bb050
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb050
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008bb050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "aamacros.txt". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "aamacros.txt"
//   - "i_d_macro.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_008b9410, FUN_008ba250, FUN_008ba780, FUN_008bb050.
//  - Strings: "aamacros.txt"; "i_d_macro.xml".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008bb050(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b66f8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a46a14;

  param_1[0x13f] = 0;

  param_1[0x140] = 1;

  param_1[0x16c] = 0xffffffff;

  param_1[0x16b] = 5;

  param_1[0x169] = 100;

  param_1[0x16a] = 100;

  FUN_008b9410();

  puVar2 = &DAT_00d177c8;

  for (iVar1 = 0x4b; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  DAT_00d17788 = 0;

  DAT_00d1778c = 0;

  DAT_00d17790 = 0;

  DAT_00d17794 = 0;

  DAT_00d17798 = 0;

  DAT_00d1779c = 0;

  DAT_00d177a0 = 0;

  DAT_00d177a4 = 0;

  DAT_00d177a8 = 0;

  DAT_00d177ac = 0;

  DAT_00d177b0 = 0;

  DAT_00d177b4 = 0;

  _DAT_00d177b8 = 0;

  _DAT_00d177bc = 0;

  _DAT_00d177c0 = 0;

  FUN_008ba250(param_1,"aamacros.txt");

  FUN_008ba780("i_d_macro.xml");

  ExceptionList = local_c;

  return param_1;

}
