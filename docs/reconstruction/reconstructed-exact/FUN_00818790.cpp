// =============================================================================
// FUN_00818790
// -----------------------------------------------------------------------------
// Stable ID: aa_00818790
// Address:   0x00818790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00818790 @ 0x00818790
// Stable ID: aa_00818790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040fb90×2, CONCAT31, FUN_004133c0, FUN_00818790, FUN_0087b890.
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

uint32_t /* width from decompiler */ * FUN_00818790(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b81f1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a7b104;

  uVar1 = FUN_0040fb90();

  param_1[0x144] = uVar1;

  param_1[0x145] = 0;

  local_4._0_1_ = 1;

  uVar1 = FUN_0040fb90();

  param_1[0x147] = uVar1;

  param_1[0x148] = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_004133c0(0);

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x150] = 9999;

  *(uint8_t *)(param_1 + 0x151) = 0;

  *(uint8_t *)(param_1 + 0x153) = 0;

  *(uint8_t *)(param_1 + 0x194) = 0;

  *(uint8_t *)(param_1 + 0x1d5) = 0;

  *(uint8_t *)(param_1 + 0x216) = 0;

  *(uint8_t *)(param_1 + 599) = 0;

  *(uint8_t *)(param_1 + 0x298) = 0;

  *(uint8_t *)(param_1 + 0x2d9) = 0;

  *(uint8_t *)(param_1 + 0x31a) = 0;

  *(uint8_t *)(param_1 + 0x35b) = 0;

  param_1[0x152] = 0;

  ExceptionList = local_c;

  return param_1;

}
