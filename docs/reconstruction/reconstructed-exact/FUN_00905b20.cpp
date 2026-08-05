// =============================================================================
// FUN_00905b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00905b20
// Address:   0x00905b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00905b20 @ 0x00905b20
// Stable ID: aa_00905b20
// Embedded strings (evidence for future rename):
//   - "i_d_ah_list.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_00905b20, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_ah_list.xml".
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

int * FUN_00905b20(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b7c7b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,param_2);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a32f84;

  param_1[0x13f] = 0;

  param_1[0x140] = 2;

  *(uint8_t *)((int)param_1 + 0xc5) = 0;

  *(uint8_t *)(param_1 + 0x31) = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x143] = param_3;

  param_1[0x14c] = 0;

  param_1[0x149] = 10;

  param_1[0x14d] = -1;

  param_1[0x14e] = 0;

  param_1[0x14f] = 0;

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  param_1[0x152] = 0;

  param_1[0x153] = 0;

  param_1[0x154] = 0;

  param_1[0x155] = 0;

  param_1[0x156] = 0;

  param_1[0x158] = 0;

  param_1[0x159] = 0;

  param_1[0x15a] = 0;

  param_1[0x15b] = 0;

  param_1[0x14a] = 0;

  param_1[0x146] = 0;

  NDUIWindow_ReloadInterface("i_d_ah_list.xml");

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
