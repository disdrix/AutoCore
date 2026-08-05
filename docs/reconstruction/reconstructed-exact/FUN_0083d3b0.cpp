// =============================================================================
// FUN_0083d3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083d3b0
// Address:   0x0083d3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083d3b0 @ 0x0083d3b0
// Stable ID: aa_0083d3b0
// Embedded strings (evidence for future rename):
//   - "i_d_status.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00415770×2, FUN_00792d20, FUN_0083d100, FUN_0083d3b0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_status.xml".
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

int * FUN_0083d3b0(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4650;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  param_1[0x14c] = DAT_00a0f298;

  *param_1 = (int)&PTR_FUN_00a6d1b4;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0xbf) = 0;

  param_1[0x14d] = 0;

  param_1[0x13f] = 0;

  param_1[0x140] = 0;

  param_1[0x141] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00415770(pvVar1);

  }

  local_4._0_1_ = 0;

  param_1[0x14e] = iVar2;

  pvVar1 = operator_new(0x34);

  local_4._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00415770(pvVar1);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0x14f] = iVar2;

  NDUIWindow_ReloadInterface("i_d_status.xml");

  FUN_0083d100(param_1);

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
