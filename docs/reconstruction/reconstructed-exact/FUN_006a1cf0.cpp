// =============================================================================
// FUN_006a1cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a1cf0
// Address:   0x006a1cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a1cf0 @ 0x006a1cf0
// Stable ID: aa_006a1cf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_006a1090×6, FUN_006a1cf0.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * __fastcall FUN_006a1cf0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab292;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 6;

  param_1[1] = 3;

  param_1[2] = 0x3e99999a;

  param_1[3] = 0x3f800000;

  param_1[4] = 0x3e99999a;

  param_1[5] = 0x3f800000;

  param_1[6] = 0x3f800000;

  *(uint8_t *)(param_1 + 7) = 1;

  *(uint8_t *)((int)param_1 + 0x1d) = 0;

  *(uint8_t *)((int)param_1 + 0x1e) = 0;

  param_1[8] = 0;

  param_1[9] = 0x3f800000;

  param_1[10] = 0;

  param_1[0xb] = 0x3f800000;

  param_1[0xc] = 0x41f00000;

  param_1[0xd] = 0x41200000;

  param_1[0xe] = 0x3f800000;

  param_1[0xf] = 0x3f000000;

  param_1[0x10] = 0x3e800000;

  param_1[0x11] = 0x3e99999a;

  param_1[0x12] = 0x3dcccccd;

  param_1[0x13] = 0x3f800000;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  pvVar1 = operator_new(0x5c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006a1090();

  }

  local_4 = 0xffffffff;

  param_1[0x16] = uVar2;

  pvVar1 = operator_new(0x5c);

  local_4 = 1;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006a1090();

  }

  local_4 = 0xffffffff;

  param_1[0x15] = uVar2;

  pvVar1 = operator_new(0x5c);

  local_4 = 2;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006a1090();

  }

  local_4 = 0xffffffff;

  param_1[0x19] = uVar2;

  pvVar1 = operator_new(0x5c);

  local_4 = 3;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006a1090();

  }

  local_4 = 0xffffffff;

  param_1[0x1b] = uVar2;

  pvVar1 = operator_new(0x5c);

  local_4 = 4;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_006a1090();

  }

  local_4 = 0xffffffff;

  param_1[0x1a] = uVar2;

  pvVar1 = operator_new(0x5c);

  local_4 = 5;

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_006a1090();

    param_1[0x18] = uVar2;

    ExceptionList = local_c;

    return param_1;

  }

  param_1[0x18] = 0;

  ExceptionList = local_c;

  return param_1;

}
