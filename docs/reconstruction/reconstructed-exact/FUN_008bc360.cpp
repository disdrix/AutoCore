// =============================================================================
// FUN_008bc360
// -----------------------------------------------------------------------------
// Stable ID: aa_008bc360
// Address:   0x008bc360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bc360 @ 0x008bc360
// Stable ID: aa_008bc360
// Embedded strings (evidence for future rename):
//   - "i_d_ls.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, FUN_00410bc0, FUN_0087b890, FUN_008bb230, FUN_008bb2c0, FUN_008bc360, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_ls.xml".
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

int * FUN_008bc360(int *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b67d9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a4639c;

  FUN_00410bc0();

  iVar1 = DAT_00a0f70c;

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x13f] = 0x10;

  param_1[0x140] = 1;

  *(uint8_t *)(param_1 + 0x144) = 0;

  param_1[0x146] = iVar1;

  FUN_008bb230();

  FUN_008bb2c0();

  NDUIWindow_ReloadInterface("i_d_ls.xml");

  if (param_1[0x130] != 0) {

    (**(code **)(*param_1 + 0x448))();

    (**(code **)(*param_1 + 0x34c))();

  }

  ExceptionList = local_c;

  return param_1;

}
