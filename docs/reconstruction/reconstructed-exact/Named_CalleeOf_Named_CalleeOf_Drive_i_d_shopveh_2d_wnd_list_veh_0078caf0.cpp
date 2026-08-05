// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078caf0
// Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml (+1 other named callers)
// Address:   0x0078caf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007560d0, FUN_00756320, FUN_0078caf0, FUN_007b5dd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0078caf0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b400b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,param_2);

  fVar9 = g_flOne;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a99f74;

  *(uint8_t *)((int)param_1 + 0x4a6) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4a5) = 0xff;

  *(uint8_t *)(param_1 + 0x129) = 0xff;

  *(uint8_t *)((int)param_1 + 0x4a7) = 0xff;

  param_1[0x12a] = 0;

  param_1[299] = 0;

  param_1[300] = 0;

  param_1[0x12d] = fVar9;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x130] = 0;

  param_1[0x131] = fVar9;

  param_1[0x132] = 0;

  param_1[0x133] = 0;

  param_1[0x134] = 0;

  param_1[0x135] = fVar9;

  param_1[0x136] = 0;

  param_1[0x137] = 0;

  param_1[0x138] = 0;

  param_1[0x139] = fVar9;

  param_1[0x13a] = 0;

  param_1[0x13b] = 0;

  param_1[0x13c] = 0;

  fVar5 = g_flLevelUpUiBase_Inferred;

  param_1[0x13d] = fVar9;

  param_1[0x4d] = fVar5;

  uVar4 = DAT_00a0f710;

  param_1[0x122] = param_3;

  uVar2 = DAT_00aaabbc;

  *(uint8_t *)(param_1 + 0x13e) = 0;

  *(uint8_t *)((int)param_1 + 0xbe) = 1;

  *(uint8_t *)((int)param_1 + 0xbf) = 1;

  param_1[0x123] = 0x10;

  *(uint8_t *)((int)param_1 + 0x4a1) = 0;

  *(uint8_t *)(param_1 + 0x128) = 0;

  *(uint8_t *)((int)param_1 + 0x4a6) = 0;

  *(uint8_t *)((int)param_1 + 0x4a5) = 0;

  *(uint8_t *)(param_1 + 0x129) = 0;

  *(uint8_t *)((int)param_1 + 0x4a7) = 0;

  uVar1 = DAT_00a0f720;

  param_1[0x124] = uVar4;

  uVar4 = DAT_00a0f298;

  param_1[0x125] = uVar2;

  param_1[0x126] = uVar1;

  param_1[0x12a] = fVar9;

  param_1[299] = fVar9;

  param_1[300] = fVar9;

  param_1[0x12d] = fVar9;

  fVar5 = DAT_00b017e8;

  param_1[0x12e] = uVar4;

  param_1[0x12f] = uVar4;

  param_1[0x130] = uVar4;

  fVar6 = fVar5 * _DAT_00aaaa68;

  param_1[0x132] = fVar9;

  param_1[0x131] = fVar9;

  param_1[0x133] = fVar9;

  fVar7 = fVar5 * _DAT_00aaaa64;

  param_1[0x134] = fVar9;

  fVar8 = fVar5 * _DAT_00aaaa60;

  param_1[0x136] = fVar6;

  fVar6 = fVar5 * _DAT_00aaaa5c;

  param_1[0x135] = fVar9;

  param_1[0x137] = fVar7;

  fVar9 = fVar5 * DAT_00aaa6f8;

  fVar7 = fVar5 * _DAT_00aaaa58;

  fVar5 = fVar5 * _DAT_00aaa7c0;

  param_1[0x138] = fVar8;

  param_1[0x13a] = fVar6;

  param_1[0x139] = fVar9;

  param_1[0x13b] = fVar7;

  param_1[0x13c] = fVar5;

  param_1[0x13d] = fVar9;

  param_1[0xab] = 0;

  param_1[0x127] = 0;

  param_1[0x8a] = 0;

  param_1[0x8b] = 0;

  param_1[0x8c] = 0;

  pvVar3 = operator_new(0x80);

  local_4._0_1_ = 1;

  if (pvVar3 == (void *)0x0) {

    uVar4 = 0;

  }

  else {

    uVar4 = FUN_007560d0();

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0xaa] = uVar4;

  FUN_00756320(1);

  ExceptionList = local_c;

  return param_1;

}
