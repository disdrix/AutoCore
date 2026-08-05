// =============================================================================
// FUN_0084f1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084f1e0
// Address:   0x0084f1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084f1e0 @ 0x0084f1e0
// Stable ID: aa_0084f1e0
// Embedded strings (evidence for future rename):
//   - "i_d_item.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00792d20, FUN_0084f140, FUN_0084f1e0.
//  - Strings: "i_d_item.xml".
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

uint32_t /* width from decompiler */ * FUN_0084f1e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b48b5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  param_1[0x140] = 0;

  uVar1 = DAT_00a0f298;

  param_1[0xa9] = param_2;

  *param_1 = &PTR_FUN_00a68894;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x143) = 1;

  param_1[0x142] = 0xffffffff;

  param_1[0x141] = uVar1;

  param_1[0x144] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x145] = 0;

  FUN_0084f140("i_d_item.xml");

  ExceptionList = local_c;

  return param_1;

}
