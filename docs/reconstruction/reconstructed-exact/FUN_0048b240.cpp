// =============================================================================
// FUN_0048b240
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b240
// Address:   0x0048b240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048b240 @ 0x0048b240
// Stable ID: aa_0048b240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_0048a940×2, FUN_0048b240.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0048b240(uint32_t /* width from decompiler */ *param_1,char *param_2,char *param_3)



{

  char cVar1;

  char *pcVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a04fe;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[2] = 0xffffffff;

  param_1[1] = 0xffffffff;

  param_1[3] = 0;

  *param_1 = &PTR_FUN_009c6e04;

  param_1[5] = &DAT_00b03504;

  param_1[6] = &DAT_00b03504;

  local_4 = 2;

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(param_2,(int)pcVar2 - (int)(param_2 + 1));

  pcVar2 = param_3;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(param_3,(int)pcVar2 - (int)(param_3 + 1));

  param_1[4] = 0;

  param_1[8] = 0;

  param_1[7] = 0;

  ExceptionList = local_c;

  return param_1;

}
