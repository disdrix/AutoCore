// =============================================================================
// FUN_0098ef00
// -----------------------------------------------------------------------------
// Stable ID: aa_0098ef00
// Address:   0x0098ef00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098ef00 @ 0x0098ef00
// Stable ID: aa_0098ef00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005ae2b0, FUN_0098ef00.
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

uint32_t /* width from decompiler */ * FUN_0098ef00(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac893;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00aa6d18;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  local_4 = 2;

  iVar2 = FUN_005ae2b0();

  param_1[10] = iVar2;

  *(uint8_t *)(iVar2 + 0x19) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[10] + 4) = param_1[10];

  *(uint32_t /* width from decompiler */ *)param_1[10] = param_1[10];

  *(uint32_t /* width from decompiler */ *)(param_1[10] + 8) = param_1[10];

  param_1[0xb] = 0;

  param_1[0xc] = DAT_00d1a6c0;

  param_1[0xd] = DAT_00d1a6c4;

  param_1[0xe] = DAT_00d1a6c8;

  fVar1 = g_flOne;

  param_1[0xf] = g_flOne;

  param_1[0x10] = fVar1;

  param_1[0x11] = DAT_00afdf0c;

  ExceptionList = local_c;

  return param_1;

}
