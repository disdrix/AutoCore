// =============================================================================
// Named_i_w_util
// -----------------------------------------------------------------------------
// Stable ID: aa_00892190
// Address:   0x00892190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_w_util @ 0x00892190
// Stable ID: aa_00892190
// Embedded strings (evidence for future rename):
//   - "i_w_util.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, Named_i_w_util, NDUIWindow_ReloadInterface.
//  - Strings: "i_w_util.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_w_util.xml"
 * Domain alias of FUN_00892190 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * Named_i_w_util(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b5bc4;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a51efc;

  *(uint8_t *)((int)param_1 + 0x536) = 0xff;

  *(uint8_t *)((int)param_1 + 0x535) = 0xff;

  *(uint8_t *)(param_1 + 0x14d) = 0xff;

  *(uint8_t *)((int)param_1 + 0x537) = 0xff;

  *(uint8_t *)((int)param_1 + 0x53a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x539) = 0xff;

  *(uint8_t *)(param_1 + 0x14e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x53b) = 0xff;

  uVar2 = DAT_00aaa668;

  *(uint8_t *)((int)param_1 + 0x56a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x569) = 0xff;

  *(uint8_t *)(param_1 + 0x15a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56d) = 0xff;

  *(uint8_t *)(param_1 + 0x15b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x56f) = 0xff;

  *(uint8_t *)((int)param_1 + 0x572) = 0xff;

  *(uint8_t *)((int)param_1 + 0x571) = 0xff;

  *(uint8_t *)(param_1 + 0x15c) = 0xff;

  *(uint8_t *)((int)param_1 + 0x573) = 0xff;

  *(uint8_t *)((int)param_1 + 0x576) = 0xff;

  *(uint8_t *)((int)param_1 + 0x575) = 0xff;

  *(uint8_t *)(param_1 + 0x15d) = 0xff;

  *(uint8_t *)((int)param_1 + 0x577) = 0xff;

  param_1[0x167] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  fVar1 = g_flOne;

  param_1[0x16c] = 0xffffffff;

  param_1[0x16d] = 0xffffffff;

  param_1[0x16b] = 4;

  param_1[0x145] = 0;

  param_1[0x168] = 0;

  param_1[0x169] = uVar2;

  *(uint8_t *)(param_1 + 0x16a) = 0;

  param_1[0x14b] = 0;

  param_1[0x147] = 0;

  param_1[0x14d] = DAT_00afdf0c;

  param_1[0x14e] = DAT_00afdef0;

  param_1[0x150] = fVar1;

  *(uint16_t *)(param_1 + 0x166) = 0;

  param_1[0x15a] = DAT_00afdf0c;

  param_1[0x15e] = 0;

  param_1[0x162] = 0;

  param_1[0x15b] = DAT_00afdf0c;

  param_1[0x15f] = 0;

  param_1[0x163] = 0;

  param_1[0x15c] = DAT_00afdf0c;

  param_1[0x160] = 0;

  param_1[0x164] = 0;

  param_1[0x15d] = DAT_00afdf0c;

  param_1[0x161] = 0;

  param_1[0x165] = 0;

  param_1[0x143] = 0;

  param_1[0x144] = 0;

  param_1[0x146] = 0;

  param_1[0x148] = 0;

  param_1[0x14c] = 0;

  param_1[0x159] = 0;

  param_1[0x151] = 0;

  param_1[0x155] = 0;

  param_1[0x152] = 0;

  param_1[0x156] = 0;

  param_1[0x153] = 0;

  param_1[0x157] = 0;

  param_1[0x154] = 0;

  param_1[0x158] = 0;

  NDUIWindow_ReloadInterface("i_w_util.xml");

  ExceptionList = local_c;

  return param_1;

}
