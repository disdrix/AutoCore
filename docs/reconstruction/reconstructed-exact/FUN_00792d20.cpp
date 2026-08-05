// =============================================================================
// FUN_00792d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00792d20
// Address:   0x00792d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00792d20 @ 0x00792d20
// Stable ID: aa_00792d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004280f0×2, CONCAT31, FUN_0040fb90, FUN_00428480, FUN_00428700, FUN_00428980, FUN_00792d20, FUN_007b5dd0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * FUN_00792d20(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b40aa;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a98f44;

  uVar1 = FUN_0040fb90();

  param_1[0x138] = uVar1;

  param_1[0x139] = 0;

  local_4._0_1_ = 1;

  param_1[0x126] = 0xffffffff;

  param_1[0x127] = 0xffffffff;

  param_1[0x128] = 0xffffffff;

  param_1[299] = 0;

  uVar1 = DAT_00a0f71c;

  *(uint8_t *)(param_1 + 0x23) = 0;

  *(uint8_t *)(param_1 + 0x124) = 1;

  *(uint8_t *)((int)param_1 + 0x491) = 0;

  *(uint8_t *)((int)param_1 + 0x492) = 0;

  *(uint8_t *)((int)param_1 + 0x493) = 1;

  *(uint8_t *)(param_1 + 0x125) = 0;

  *(uint8_t *)((int)param_1 + 0x495) = 0;

  *(uint8_t *)((int)param_1 + 0x496) = 0;

  *(uint8_t *)((int)param_1 + 0x497) = 0;

  param_1[0x129] = 0;

  param_1[0x12a] = 0;

  param_1[300] = uVar1;

  param_1[0x131] = 1;

  param_1[0x130] = 0;

  param_1[0xab] = 0;

  param_1[0x132] = 0;

  param_1[0x133] = 0;

  param_1[0x134] = 0;

  param_1[0x135] = 0;

  param_1[0x136] = 0;

  param_1[0x13a] = 1;

  param_1[0x13b] = 1;

  param_1[0x13c] = 1;

  param_1[0x13d] = 1;

  param_1[0x13e] = 1;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  *(uint8_t *)(param_1 + 0x30) = 0;

  pvVar2 = operator_new(0x34);

  local_4._0_1_ = 2;

  if (pvVar2 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_004280f0(pvVar2);

  }

  local_4._0_1_ = 1;

  param_1[0x132] = uVar1;

  pvVar2 = operator_new(0x34);

  local_4._0_1_ = 3;

  if (pvVar2 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00428480(pvVar2);

  }

  local_4._0_1_ = 1;

  param_1[0x133] = uVar1;

  pvVar2 = operator_new(0x34);

  local_4._0_1_ = 4;

  if (pvVar2 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00428700(pvVar2);

  }

  local_4._0_1_ = 1;

  param_1[0x134] = uVar1;

  pvVar2 = operator_new(0x34);

  local_4._0_1_ = 5;

  if (pvVar2 == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00428980(pvVar2);

  }

  local_4._0_1_ = 1;

  param_1[0x135] = uVar1;

  pvVar2 = operator_new(0x34);

  local_4 = CONCAT31(local_4._1_3_,6);

  if (pvVar2 != (void *)0x0) {

    uVar1 = FUN_004280f0(pvVar2);

    param_1[0x136] = uVar1;

    ExceptionList = local_c;

    return param_1;

  }

  param_1[0x136] = 0;

  ExceptionList = local_c;

  return param_1;

}
