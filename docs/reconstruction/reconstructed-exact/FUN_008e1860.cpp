// =============================================================================
// FUN_008e1860
// -----------------------------------------------------------------------------
// Stable ID: aa_008e1860
// Address:   0x008e1860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e1860 @ 0x008e1860
// Stable ID: aa_008e1860
// Embedded strings (evidence for future rename):
//   - "i_d_dt.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040fb90×2, CONCAT31, FUN_0087b890, FUN_008df710, FUN_008e1860, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_dt.xml".
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

int * FUN_008e1860(int *param_1)



{

  int iVar1;

  float fVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7308;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a3bf64;

  iVar1 = FUN_0040fb90();

  param_1[0x1ac] = iVar1;

  param_1[0x1ad] = 0;

  local_4._0_1_ = 1;

  iVar1 = FUN_0040fb90();

  param_1[0x1af] = iVar1;

  param_1[0x1b0] = 0;

  local_4 = CONCAT31(local_4._1_3_,2);

  param_1[0x140] = 1;

  param_1[0x13f] = 0xc;

  fVar2 = (float)DAT_00d1e818 * g_flZero;

  param_1[0x145] = (int)((float)DAT_00d1e81c * DAT_00a1e8b4);

  param_1[0x144] = (int)fVar2;

  fVar2 = (float)DAT_00d1e818 * DAT_00aaa8f0;

  param_1[0x147] = (int)((float)DAT_00d1e81c * DAT_00aaa8ec);

  param_1[0x146] = (int)fVar2;

  FUN_008df710();

  NDUIWindow_ReloadInterface("i_d_dt.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
