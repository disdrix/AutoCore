// =============================================================================
// FUN_00920790
// -----------------------------------------------------------------------------
// Stable ID: aa_00920790
// Address:   0x00920790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00920790 @ 0x00920790
// Stable ID: aa_00920790
// Embedded strings (evidence for future rename):
//   - "i_s_av.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_009108a0, FUN_00910b40, FUN_009167c0, FUN_00920790.
//  - Strings: "i_s_av.xml".
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

uint32_t /* width from decompiler */ * FUN_00920790(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  float fVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7e7b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00910b40(param_1);

  *param_1 = &PTR_FUN_00a2f0a4;

  param_1[0x328] = 0;

  param_1[0x329] = 0;

  param_1[0x32a] = 0;

  local_4 = 1;

  FUN_009167c0();

  uVar3 = DAT_00a0f298;

  uVar1 = param_1[0x345];

  uVar2 = param_1[0x346];

  param_1[0x295] = DAT_00aaac0c;

  param_1[0x297] = DAT_00a0f704;

  param_1[0x29c] = DAT_00a110d8;

  param_1[0x29e] = g_flLevelUpUiBase_Inferred;

  fVar4 = g_flOne;

  param_1[0x345] = uVar3;

  fVar5 = g_flOverheatCoolFrac;

  param_1[0x333] = uVar1;

  param_1[0x332] = fVar4;

  param_1[0x344] = fVar4;

  param_1[0x346] = fVar5;

  uVar1 = DAT_00aaa7a4;

  param_1[0x29a] = fVar4;

  fVar4 = g_flVehicleHpTechCoeff;

  param_1[0x334] = uVar2;

  *(uint8_t *)(param_1 + 0x319) = 0;

  param_1[0x292] = 0;

  param_1[0x293] = 0;

  *(uint8_t *)((int)param_1 + 0x509) = 1;

  *(uint8_t *)((int)param_1 + 0xa33) = 0;

  param_1[0x296] = 0;

  param_1[0x298] = 0;

  *(uint8_t *)(param_1 + 0x28d) = 0;

  *(uint8_t *)((int)param_1 + 0x50a) = 1;

  *(uint8_t *)(param_1 + 0x340) = 0;

  *(uint8_t *)((int)param_1 + 0xa83) = 0;

  *(uint8_t *)(param_1 + 0x2a1) = 0;

  *(uint8_t *)((int)param_1 + 0xa82) = 0;

  *(uint8_t *)((int)param_1 + 0xa36) = 0;

  *(uint8_t *)((int)param_1 + 0xa37) = 0;

  *(uint8_t *)((int)param_1 + 0xa87) = 1;

  *(uint8_t *)((int)param_1 + 0xce1) = 1;

  *(uint8_t *)(param_1 + 0x28e) = 0;

  *(uint8_t *)((int)param_1 + 0xa85) = 0;

  *(uint8_t *)((int)param_1 + 0xa86) = 0;

  *(uint8_t *)((int)param_1 + 0xa39) = 0;

  *(uint8_t *)(param_1 + 0x2a2) = 0xff;

  param_1[0x2a3] = 0;

  param_1[0x29d] = 0;

  *(uint8_t *)((int)param_1 + 0xa81) = 0;

  *(uint8_t *)(param_1 + 0x2a0) = 3;

  param_1[0x29f] = 0;

  param_1[0x337] = param_1[0x14a];

  *(uint8_t *)(param_1 + 0x338) = 0;

  param_1[0x335] = 0;

  param_1[0x331] = 0;

  param_1[0x299] = uVar1;

  param_1[0x29b] = fVar4;

  param_1[0x336] = uVar1;

  param_1[0x341] = DAT_00d1a6c0;

  param_1[0x342] = DAT_00d1a6c4;

  param_1[0x343] = DAT_00d1a6c8;

  param_1[0x309] = 0;

  param_1[0x30a] = 0;

  param_1[0x308] = 0;

  param_1[0x30c] = 0;

  param_1[0x314] = 0;

  param_1[0x315] = 0;

  param_1[0x316] = 0;

  param_1[0x317] = 0;

  param_1[0x347] = 0;

  param_1[0x14e] = 0;

  uVar1 = DAT_00aaac08;

  param_1[0x318] = 0;

  param_1[0x28f] = 4;

  param_1[0x290] = 5;

  param_1[0x291] = 3;

  param_1[0x14f] = uVar1;

  param_1[0x348] = 0;

  param_1[0x34a] = 0;

  param_1[0x34b] = 0;

  FUN_009108a0("i_s_av.xml");

  ExceptionList = local_c;

  return param_1;

}
