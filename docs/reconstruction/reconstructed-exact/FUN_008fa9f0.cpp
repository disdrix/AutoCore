// =============================================================================
// FUN_008fa9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fa9f0
// Address:   0x008fa9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fa9f0 @ 0x008fa9f0
// Stable ID: aa_008fa9f0
// Embedded strings (evidence for future rename):
//   - "i_d_c.xml"
//   - "i_d_c_2d_wnd_geo.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_00536920, FUN_00856490, FUN_0087b890, FUN_008f9180, FUN_008fa9f0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_c.xml"; "i_d_c_2d_wnd_geo.xml".
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

int * FUN_008fa9f0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int *piVar2;

  void *unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7a5b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a356f4;

  FUN_00536920(1);

  local_4._0_1_ = 1;

  param_1[0x13f] = 5;

  param_1[0x140] = 1;

  FUN_008f9180();

  param_1[0x536] = 0;

  NDUIWindow_ReloadInterface("i_d_c.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  pvVar1 = operator_new(0x520);

  local_4._0_1_ = 2;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00856490(pvVar1);

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x536] = (int)piVar2;

  (**(code **)(*piVar2 + 0x28))("i_d_c_2d_wnd_geo.xml");

  *(uint8_t *)(param_1[0x536] + 0x51c) = 1;

  (**(code **)(*(int *)param_1[0x536] + 0xcc))(0);

  ExceptionList = unaff_ESI;

  return param_1;

}
