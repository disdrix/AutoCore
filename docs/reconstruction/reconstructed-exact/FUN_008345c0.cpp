// =============================================================================
// FUN_008345c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008345c0
// Address:   0x008345c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008345c0 @ 0x008345c0
// Stable ID: aa_008345c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0078caf0, FUN_008345c0, FUN_00972cc0.
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

uint32_t /* width from decompiler */ * FUN_008345c0(uint32_t /* width from decompiler */ *param_1,float param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4575;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0078caf0(param_1,0,1);

  local_4 = 0;

  *param_1 = &PTR_FUN_00a6fbcc;

  FUN_00972cc0();

  param_2 = DAT_00aaa954 - param_2;

  param_1[0x178] = param_1[0x164];

  param_1[0x179] = param_1[0x165];

  param_1[0x176] = param_2;

  uVar1 = DAT_00aaa690;

  param_1[0x17a] = param_1[0x166];

  param_1[0x142] = 0;

  param_1[0x143] = 0;

  param_1[0x4d] = uVar1;

  *(uint8_t *)(param_1 + 0x13f) = 0;

  param_1[0x175] = 0;

  param_1[0x140] = 0;

  param_1[0x141] = 0x10;

  *(uint8_t *)(param_1 + 0x174) = 1;

  *(uint8_t *)(param_1 + 0x177) = 0;

  param_1[0x17b] = param_1[0x167];

  ExceptionList = local_c;

  return param_1;

}
