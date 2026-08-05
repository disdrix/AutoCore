// =============================================================================
// FUN_00698150
// -----------------------------------------------------------------------------
// Stable ID: aa_00698150
// Address:   0x00698150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00698150 @ 0x00698150
// Stable ID: aa_00698150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_00698150, FUN_0069a050, FUN_0069edd0, FUN_006a1cd0, FUN_006a29c0, FUN_006a2b20.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall FUN_00698150(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aabc2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0069a050();

  local_4 = 0;

  *param_1 = &PTR_FUN_009eb364;

  param_1[4] = 0x3f800000;

  param_1[5] = 0x3f800000;

  param_1[6] = 0xbf800000;

  param_1[7] = 0;

  FUN_006a1cd0();

  local_4._0_1_ = 1;

  *(uint8_t *)((int)param_1 + 0x21) = 1;

  FUN_006a2b20();

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 6;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  local_4._0_1_ = 4;

  FUN_0069edd0();

  param_1[0x35] = 0x3f800000;

  local_4 = CONCAT31(local_4._1_3_,5);

  param_1[0x32] = 0;

  *(uint8_t *)(param_1 + 0x33) = 0;

  param_1[0x34] = 0x3f000000;

  param_1[0x36] = 0x3e99999a;

  param_1[0x37] = 0;

  param_1[0x38] = 0x3d4ccccd;

  param_1[0x39] = 1;

  FUN_006a29c0();

  param_1[0x17] = param_2;

  param_1[0x40] = 0x3e800000;

  fVar1 = (float)param_1[0x3a] * _DAT_00aaa7c0;

  param_1[0x3d] = -fVar1;

  param_1[0x3e] = fVar1;

  param_1[0x3f] = (float)param_1[0x3b] + (float)param_1[0x3b];

  ExceptionList = local_c;

  return param_1;

}
