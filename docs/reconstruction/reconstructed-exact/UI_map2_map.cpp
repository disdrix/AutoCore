// =============================================================================
// UI_map2_map
// -----------------------------------------------------------------------------
// Stable ID: aa_0085ba60
// Address:   0x0085ba60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_map2_map @ 0x0085ba60
// Stable ID: aa_0085ba60
// Embedded strings (evidence for future rename):
//   - "i_d_map_2d_wnd_map.xml"
//   - "i_d_map2_2d_wnd_map.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: InitializeCriticalSection×2, CONCAT31, FUN_00792d20, FUN_008575e0, FUN_00857d80, FUN_00858a30, UI_map2_map.
//  - Strings: "i_d_map_2d_wnd_map.xml"; "i_d_map2_2d_wnd_map.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_map2_2d_wnd_map.xml"
 * Domain alias of FUN_0085ba60 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * UI_map2_map(uint32_t /* width from decompiler */ *param_1,uint8_t param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  float fVar4;

  char *pcVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4a01;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a65c7c;

  param_1[0x194] = &PTR_FUN_00a660c8;

  param_1[0x195] = 0;

  param_1[0x196] = 0;

  param_1[0x197] = 0;

  param_1[0x1a4] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x198));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x19e));

  local_4 = CONCAT31(local_4._1_3_,1);

  *(uint8_t *)(param_1 + 0x16e) = 1;

  param_1[0x1a5] = 0;

  param_1[0x1a6] = 0;

  param_1[0x1a7] = 0;

  param_1[0x1a8] = 0;

  param_1[0x1a9] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)((int)param_1 + 0x5b9) = param_2;

  param_1[0x172] = 0;

  param_1[0x173] = 0;

  param_1[0x174] = 0;

  param_1[0x192] = 0;

  param_1[0x175] = 0;

  param_1[0x176] = 0;

  param_1[0x177] = 0;

  param_1[0x178] = 0;

  param_1[0x179] = 0;

  param_1[0x17a] = 0;

  param_1[0x17b] = 0;

  param_1[0x17c] = 0;

  param_1[0x17d] = 0;

  param_1[0x17e] = 0;

  param_1[0x17f] = 0;

  param_1[0x180] = 0;

  param_1[0x181] = 0;

  param_1[0x182] = 0;

  param_1[0x183] = 0;

  param_1[0x184] = 0;

  param_1[0x185] = 0;

  param_1[0x186] = 0;

  param_1[0x187] = 0;

  param_1[0x188] = 0;

  param_1[0x189] = 0;

  param_1[0x18a] = 0;

  param_1[0x18b] = 0;

  param_1[0x18c] = 0;

  param_1[0x18d] = 0;

  param_1[0x18e] = 0;

  param_1[399] = 0;

  param_1[400] = 0;

  param_1[0x191] = 0;

  param_1[0x193] = 0;

  FUN_00857d80(0x1e);

  param_1[0x156] = 10;

  param_1[0x157] = 10;

  uVar2 = DAT_00aaabd8;

  param_1[0x154] = 8;

  param_1[0x155] = 8;

  param_1[0x152] = 8;

  param_1[0x153] = 8;

  param_1[0x150] = 0xe;

  param_1[0x151] = 0xe;

  param_1[0x158] = 0xe;

  param_1[0x159] = 0xe;

  fVar4 = DAT_00af931c;

  fVar1 = g_flOne;

  if (*(char *)((int)param_1 + 0x5b9) == '\0') {

    uVar2 = DAT_00aaabd4;

  }

  param_1[0x140] = uVar2;

  param_1[0x142] = DAT_00a0f694;

  param_1[0x141] = g_flVehicleHpTechCoeff;

  param_1[0x143] = DAT_00a110d8;

  fVar3 = DAT_00af9320;

  param_1[0x13f] = fVar1;

  param_1[0x145] = fVar1;

  if (fVar4 < fVar3) {

    fVar3 = fVar4;

  }

  fVar4 = fVar3 * DAT_00a0f298 * g_flDisplayRateScaleOneThird;

  param_1[0x13f] = fVar4;

  if (fVar4 < fVar1) {

    param_1[0x13f] = fVar1;

  }

  param_1[0x164] = 0;

  param_1[0x165] = 0;

  param_1[0x16f] = 0;

  param_1[0x170] = 0;

  param_1[0x171] = DAT_00aaa668;

  FUN_008575e0();

  if (*(char *)((int)param_1 + 0x5b9) == '\0') {

    pcVar5 = "i_d_map_2d_wnd_map.xml";

  }

  else {

    pcVar5 = "i_d_map2_2d_wnd_map.xml";

  }

  FUN_00858a30(pcVar5);

  ExceptionList = local_c;

  return param_1;

}
