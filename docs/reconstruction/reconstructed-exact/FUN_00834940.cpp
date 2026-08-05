// =============================================================================
// FUN_00834940
// -----------------------------------------------------------------------------
// Stable ID: aa_00834940
// Address:   0x00834940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00834940 @ 0x00834940
// Stable ID: aa_00834940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00415d80, FUN_00415e00, FUN_007b5dd0, FUN_00834940.
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

uint32_t /* width from decompiler */ * FUN_00834940(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3423;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6f26c;

  uVar1 = FUN_00415e00();

  param_1[0x124] = uVar1;

  param_1[0x125] = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  *(uint8_t *)((int)param_1 + 0x4da) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4d9) = 0xff;

  *(uint8_t *)(param_1 + 0x136) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4db) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4de) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4dd) = 0xff;

  *(uint8_t *)(param_1 + 0x137) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4df) = 0xff;

  *(uint8_t *)(param_1 + 0x122) = 0;

  FUN_00415d80(0,0);

  param_1[0x129] = 0;

  param_1[0x128] = 0;

  param_1[0x127] = 0;

  param_1[0x126] = 0;

  param_1[0x12d] = 0;

  param_1[300] = 0;

  param_1[299] = 0;

  param_1[0x12a] = 0;

  param_1[0x131] = 0;

  param_1[0x130] = 0;

  param_1[0x12f] = 0;

  param_1[0x12e] = 0;

  param_1[0x135] = 0;

  param_1[0x134] = 0;

  param_1[0x133] = 0;

  param_1[0x132] = 0;

  ExceptionList = local_c;

  return param_1;

}
