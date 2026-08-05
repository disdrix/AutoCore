// =============================================================================
// UI_tabs_car
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a5c0
// Address:   0x0088a5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_tabs_car @ 0x0088a5c0
// Stable ID: aa_0088a5c0
// Embedded strings (evidence for future rename):
//   - "i_d_tabs_car.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_0087b890, UI_tabs_car, FUN_008be100, FUN_008c3b80, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_tabs_car.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_tabs_car.xml"
 * Domain alias of FUN_0088a5c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_tabs_car(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9418;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a541cc;

  param_1[0x13f] = 7;

  param_1[0x140] = 1;

  param_1[0x14a] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  NDUIWindow_ReloadInterface("i_d_tabs_car.xml");

  pvVar1 = operator_new(0x588);

  local_4._0_1_ = 1;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_008c3b80(pvVar1);

  }

  local_4._0_1_ = 0;

  param_1[0x143] = uVar2;

  pvVar1 = operator_new(0x5b0);

  local_4 = CONCAT31(local_4._1_3_,2);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_008be100(pvVar1);

  }

  param_1[0x144] = uVar2;

  ExceptionList = local_c;

  return param_1;

}
