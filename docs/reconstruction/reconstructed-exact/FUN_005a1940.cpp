// =============================================================================
// FUN_005a1940
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1940
// Address:   0x005a1940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a1940 @ 0x005a1940
// Stable ID: aa_005a1940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00439770×3, CONCAT31, FUN_00426120, FUN_0058d9c0, FUN_005a1940, FUN_007822a0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_005a1940(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a61ef;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007822a0();

  local_4 = 0;

  *param_1 = &PTR_LAB_009d7f1c;

  iVar2 = FUN_0058d9c0();

  param_1[0x92] = iVar2;

  *(uint8_t *)(iVar2 + 0x29) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x92] + 4) = param_1[0x92];

  *(uint32_t /* width from decompiler */ *)param_1[0x92] = param_1[0x92];

  *(uint32_t /* width from decompiler */ *)(param_1[0x92] + 8) = param_1[0x92];

  param_1[0x93] = 0;

  local_4._0_1_ = 1;

  iVar2 = FUN_00439770();

  param_1[0x9b] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x9b] + 4) = param_1[0x9b];

  *(uint32_t /* width from decompiler */ *)param_1[0x9b] = param_1[0x9b];

  *(uint32_t /* width from decompiler */ *)(param_1[0x9b] + 8) = param_1[0x9b];

  param_1[0x9c] = 0;

  local_4._0_1_ = 2;

  iVar2 = FUN_00439770();

  param_1[0xa0] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0xa0] + 4) = param_1[0xa0];

  *(uint32_t /* width from decompiler */ *)param_1[0xa0] = param_1[0xa0];

  *(uint32_t /* width from decompiler */ *)(param_1[0xa0] + 8) = param_1[0xa0];

  param_1[0xa1] = 0;

  local_4._0_1_ = 3;

  iVar2 = FUN_00439770();

  param_1[0xa5] = iVar2;

  *(uint8_t *)(iVar2 + 0x15) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0xa5] + 4) = param_1[0xa5];

  *(uint32_t /* width from decompiler */ *)param_1[0xa5] = param_1[0xa5];

  *(uint32_t /* width from decompiler */ *)(param_1[0xa5] + 8) = param_1[0xa5];

  param_1[0xa6] = 0;

  local_4 = CONCAT31(local_4._1_3_,4);

  param_1[0x90] = 1;

  param_1[0x98] = 0;

  param_1[0x9d] = 0;

  param_1[0xa2] = 0;

  FUN_00426120(0x32,0x32,40000,40000);

  uVar1 = DAT_00b05058;

  param_1[0x32] = DAT_00b0505c;

  param_1[0x31] = uVar1;

  param_1[0x2c] = 6;

  param_1[0x2b] = 7000;

  ExceptionList = local_c;

  return param_1;

}
