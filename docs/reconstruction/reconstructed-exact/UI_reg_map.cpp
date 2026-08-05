// =============================================================================
// UI_reg_map
// -----------------------------------------------------------------------------
// Stable ID: aa_008525b0
// Address:   0x008525b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_reg_map @ 0x008525b0
// Stable ID: aa_008525b0
// Embedded strings (evidence for future rename):
//   - "i_d_reg_2d_wnd_map.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: InitializeCriticalSection×2, CONCAT31, FUN_00792d20, FUN_0084fb20, FUN_00850e90, UI_reg_map.
//  - Strings: "i_d_reg_2d_wnd_map.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_reg_2d_wnd_map.xml"
 * Domain alias of FUN_008525b0 (FUN_* retained)
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



uint32_t /* width from decompiler */ * UI_reg_map(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b490a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00792d20(param_1);

  uVar2 = DAT_00af9334;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6842c;

  *(uint8_t *)((int)param_1 + 0x4fd) = 1;

  param_1[0x140] = uVar2;

  param_1[0x189] = &PTR_FUN_00a660c8;

  param_1[0x18a] = 0;

  param_1[0x18b] = 0;

  param_1[0x18c] = 0;

  param_1[0x199] = 0xffffffff;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18d));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x193));

  local_4 = CONCAT31(local_4._1_3_,1);

  param_1[0x19a] = 0;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)(param_1 + 0x13f) = 1;

  param_1[0x167] = 0;

  param_1[0x169] = 0;

  param_1[0x168] = 0;

  param_1[0x16a] = 0;

  param_1[0x16b] = 0;

  param_1[0x16c] = 0;

  param_1[0x16d] = 0;

  param_1[0x16e] = 0;

  param_1[0x16f] = 0;

  param_1[0x170] = 0;

  param_1[0x171] = 0;

  param_1[0x172] = 0;

  param_1[0x173] = 0;

  param_1[0x174] = 0;

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

  param_1[0x156] = 10;

  param_1[0x157] = 10;

  param_1[0x154] = 8;

  param_1[0x155] = 8;

  param_1[0x152] = 8;

  param_1[0x153] = 8;

  param_1[0x150] = 0xe;

  param_1[0x151] = 0xe;

  fVar1 = DAT_00af9328;

  param_1[0x158] = 0xe;

  param_1[0x159] = 0xe;

  param_1[0x145] = 0;

  param_1[0x142] = DAT_00a1109c;

  param_1[0x141] = g_flVehicleHpTechCoeff;

  param_1[0x143] = DAT_00aaabd0;

  fVar3 = DAT_00af932c;

  if (fVar1 < DAT_00af932c) {

    fVar3 = fVar1;

  }

  _DAT_00af9330 = fVar3 * DAT_00a0f298 * g_flDisplayRateScaleOneThird;

  if (_DAT_00af9330 < g_flOne) {

    _DAT_00af9330 = g_flOne;

  }

  FUN_0084fb20();

  FUN_00850e90("i_d_reg_2d_wnd_map.xml");

  ExceptionList = local_c;

  return param_1;

}
