// =============================================================================
// FUN_00609620
// -----------------------------------------------------------------------------
// Stable ID: aa_00609620
// Address:   0x00609620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00609620 @ 0x00609620
// Stable ID: aa_00609620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00518940, FUN_005c7f30, FUN_00609620.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00609620(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  float fVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a829f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (param_2 != 0) {

    ExceptionList = &local_c;

    param_1[1] = &DAT_009dd760;

    FUN_00518940();

    local_4 = 0;

  }

  FUN_005c7f30(0);

  fVar1 = g_flOne;

  *param_1 = &PTR_FUN_009df540;

  *(undefined ***)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) = &PTR_LAB_009df27c;

  *(int *)(*(int *)(param_1[1] + 4) + (int)param_1) = *(int *)(param_1[1] + 4) + -0xdc;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[0x2e] = 0;

  param_1[0x2f] = fVar1;

  param_1[0x30] = fVar1;

  param_1[0x31] = fVar1;

  param_1[0x32] = fVar1;

  param_1[0x33] = fVar1;

  ExceptionList = local_c;

  return param_1;

}
