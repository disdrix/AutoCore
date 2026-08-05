// =============================================================================
// FUN_008f0d80
// -----------------------------------------------------------------------------
// Stable ID: aa_008f0d80
// Address:   0x008f0d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f0d80 @ 0x008f0d80
// Stable ID: aa_008f0d80
// Embedded strings (evidence for future rename):
//   - "i_d_cont.xml"
//   - "i_d_cont_2d_wnd_reg.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: InitializeCriticalSection×2, CONCAT31, FUN_0040e030, FUN_008525b0, FUN_0087b890, FUN_008ebea0, FUN_008f0d80, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_cont.xml"; "i_d_cont_2d_wnd_reg.xml".
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

int * FUN_008f0d80(int *param_1)



{

  int iVar1;

  float fVar2;

  void *pvVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7729;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a38aac;

  FUN_0040e030(param_1 + 0x157);

  local_4._0_1_ = 1;

  param_1[0x16c] = (int)&PTR_FUN_00a39350;

  param_1[0x16d] = 0;

  param_1[0x16e] = 0;

  param_1[0x16f] = 0;

  param_1[0x17c] = -1;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x176));

  iVar1 = DAT_00aaaae8;

  local_4._0_1_ = 2;

  param_1[0x145] = DAT_00aaaae8;

  param_1[0x146] = iVar1;

  fVar2 = g_flOne;

  param_1[0x147] = (int)g_flOne;

  param_1[0x148] = (int)fVar2;

  param_1[0x149] = (int)fVar2;

  iVar1 = DAT_00a0f298;

  param_1[0x13f] = 0x10;

  param_1[0x140] = 1;

  param_1[0x14c] = iVar1;

  param_1[0x14e] = iVar1;

  param_1[0x14a] = iVar1;

  param_1[0x14d] = iVar1;

  param_1[0x14f] = iVar1;

  param_1[0x14b] = iVar1;

  param_1[0x154] = 0;

  param_1[0x1a0] = 0;

  param_1[0x143] = 0;

  param_1[0x150] = -1;

  param_1[0x151] = -1;

  param_1[0x152] = -1;

  param_1[0x153] = -1;

  FUN_008ebea0();

  NDUIWindow_ReloadInterface("i_d_cont.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  pvVar3 = operator_new(0x66c);

  local_4._0_1_ = 3;

  if (pvVar3 == (void *)0x0) {

    piVar4 = (int *)0x0;

  }

  else {

    piVar4 = (int *)FUN_008525b0(pvVar3);

  }

  local_4 = CONCAT31(local_4._1_3_,2);

  param_1[0x19f] = (int)piVar4;

  (**(code **)(*piVar4 + 0x28))("i_d_cont_2d_wnd_reg.xml");

  ExceptionList = pvVar3;

  return param_1;

}
