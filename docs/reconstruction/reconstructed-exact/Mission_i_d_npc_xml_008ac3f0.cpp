// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0087b890, FUN_008ab0a0, FUN_008ac110, FUN_008ac3f0, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_npc.xml".
//  - Return sites: 1.

// =============================================================================
// Mission_i_d_npc_xml_008ac3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac3f0
// Address:   0x008ac3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "i_d_npc.xml"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Mission_i_d_npc_xml_008ac3f0(int *param_1)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b645d;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0087b890(param_1,0);

  fVar1 = g_flOne;

  *param_1 = (int)&PTR_FUN_00a4a51c;

  param_1[0x161] = 0;

  param_1[0x162] = 0;

  param_1[0x163] = 0;

  param_1[0x164] = (int)fVar1;

  param_1[0x165] = 0;

  param_1[0x166] = 0;

  param_1[0x167] = 0;

  param_1[0x168] = (int)fVar1;

  param_1[0x169] = 0;

  param_1[0x16a] = 0;

  param_1[0x16b] = 0;

  param_1[0x16c] = (int)fVar1;

  param_1[0x1cb] = 0;

  param_1[0x1cc] = 0;

  param_1[0x1cd] = 0;

  param_1[0x1cf] = 0;

  param_1[0x1d0] = 0;

  param_1[0x1d1] = 0;

  local_4 = 2;

  param_1[0x13f] = 0xc;

  param_1[0x140] = 1;

  param_1[0x192] = 0;

  param_1[0x143] = 0;

  param_1[399] = 1;

  param_1[400] = 1;

  param_1[0x145] = 0;

  *(uint8_t *)(param_1 + 0x160) = 0;

  param_1[0x1c1] = 0;

  param_1[0x170] = 0;

  param_1[0x16f] = 0;

  FUN_008ab0a0();

  NDUIWindow_ReloadInterface("i_d_npc.xml");

  FUN_008ac110();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = local_c;

  return param_1;

}
