// =============================================================================
// FUN_00577df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00577df0
// Address:   0x00577df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00577df0 @ 0x00577df0
// Stable ID: aa_00577df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_00577590, FUN_005776e0, FUN_00577df0, FUN_00581330.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * __thiscall FUN_00577df0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a51e5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009d3f7c;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_00581330(0);

  uVar2 = DAT_00aaa688;

  *param_1 = &PTR_FUN_009d3ee4;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009d3c1c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0x36c;

  param_1[0x6a] = 0xffffffff;

  param_1[0x7c] = 0;

  param_1[0x7d] = 0;

  param_1[0x60] = 0;

  param_1[0x7e] = 0;

  *(uint8_t *)(param_1 + 0x65) = 0;

  *(uint8_t *)((int)param_1 + 0x195) = 0;

  *(uint8_t *)((int)param_1 + 0x196) = 0;

  param_1[0x79] = 0;

  param_1[0x7a] = 0;

  param_1[0x7b] = 0;

  param_1[0x6e] = 0;

  param_1[0x6f] = 0;

  param_1[0x6b] = _DAT_009cb8dc;

  uVar1 = DAT_00a0f298;

  param_1[0x67] = 0xffffffff;

  local_4 = 1;

  param_1[0x6d] = uVar2;

  param_1[0x61] = 0;

  param_1[0x62] = 0;

  param_1[99] = 0;

  param_1[100] = 3;

  param_1[0x6c] = uVar1;

  param_1[0x68] = 0x20;

  param_1[0x69] = 0x20;

  FUN_00577590();

  FUN_005776e0();

  *(uint8_t *)(param_1 + 0xd4) = 0;

  *(uint8_t *)((int)param_1 + 0x351) = 0;

  *(uint8_t *)((int)param_1 + 0x197) = 0;

  ExceptionList = local_c;

  return param_1;

}
