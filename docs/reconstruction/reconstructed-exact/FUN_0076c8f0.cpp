// =============================================================================
// FUN_0076c8f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c8f0
// Address:   0x0076c8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c8f0 @ 0x0076c8f0
// Stable ID: aa_0076c8f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076c5d0, FUN_0076c8f0, _strdup.
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

uint32_t /* width from decompiler */ * __fastcall

FUN_0076c8f0(char *param_1,uint8_t param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  char *pcVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009adcbd;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_3[1] = 0;

  *(uint8_t *)(param_3 + 2) = 0;

  local_4 = 0;

  *(uint8_t *)(param_3 + 3) = param_2;

  param_3[4] = param_4;

  *param_3 = &PTR_FUN_00a9d0f4;

  param_3[5] = 0;

  param_3[6] = 0;

  param_3[8] = 0xffffffff;

  param_3[7] = param_5;

  if (param_1 != (char *)0x0) {

    pcVar1 = _strdup(param_1);

    param_3[5] = pcVar1;

    FUN_0076c5d0();

  }

  ExceptionList = local_c;

  return param_3;

}
