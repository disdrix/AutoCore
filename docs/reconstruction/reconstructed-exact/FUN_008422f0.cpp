// =============================================================================
// FUN_008422f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008422f0
// Address:   0x008422f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008422f0 @ 0x008422f0
// Stable ID: aa_008422f0
// Embedded strings (evidence for future rename):
//   - "i_w_skill.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0054f3c0, FUN_00792d20, FUN_0083ed70, FUN_00841f60, FUN_008422f0.
//  - Strings: "i_w_skill.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * FUN_008422f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4776;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6bb64;

  FUN_0054f3c0();

  param_1[0x143] = 1;

  param_1[0x144] = 1;

  param_1[0x140] = 0;

  uVar1 = DAT_00a0f298;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  *(uint8_t *)((int)param_1 + 0x4fd) = 0;

  *(uint8_t *)((int)param_1 + 0x4fe) = 0;

  param_1[0x141] = uVar1;

  param_1[0x142] = 4;

  param_1[0xa9] = param_2;

  FUN_0083ed70();

  FUN_00841f60("i_w_skill.xml");

  ExceptionList = local_c;

  return param_1;

}
