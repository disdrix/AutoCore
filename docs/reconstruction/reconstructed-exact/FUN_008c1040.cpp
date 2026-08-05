// =============================================================================
// FUN_008c1040
// -----------------------------------------------------------------------------
// Stable ID: aa_008c1040
// Address:   0x008c1040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c1040 @ 0x008c1040
// Stable ID: aa_008c1040
// Embedded strings (evidence for future rename):
//   - "i_d_inventory_list.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008bfec0, FUN_008c1040, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_inventory_list.xml".
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

int * FUN_008c1040(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b693f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  *param_1 = (int)&PTR_FUN_00a447c4;

  param_1[0x15a] = 0;

  param_1[0x15b] = 0;

  param_1[0x15c] = 0;

  local_4 = 1;

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  *(uint8_t *)(param_1 + 0x31) = 0;

  param_1[0x158] = 0;

  param_1[0x14a] = 0;

  param_1[0x14b] = 0;

  param_1[0x156] = 0;

  param_1[0x14c] = 10;

  param_1[0x15e] = 0;

  param_1[0x15f] = 0;

  param_1[0x160] = 0;

  param_1[0x161] = 0;

  param_1[0x162] = 0;

  param_1[0x163] = 0;

  param_1[0x164] = 0;

  param_1[0x165] = 0;

  param_1[0x166] = 0;

  FUN_008bfec0();

  NDUIWindow_ReloadInterface("i_d_inventory_list.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
