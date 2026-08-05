// =============================================================================
// FUN_0075c7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c7e0
// Address:   0x0075c7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075c7e0 @ 0x0075c7e0
// Stable ID: aa_0075c7e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ROUND×2, FUN_0043f660, FUN_0075b7f0, FUN_0075c7e0, FUN_0076f6e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0075c7e0(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_0075b7f0();

  FUN_0043f660();

  FUN_0076f6e0();

  fVar2 = g_flZero;

  fVar1 = g_flOne;

  fVar3 = (float)*(int *)(param_1 + 0xe0) * (g_flOne - local_8) * DAT_00a0f298;

  *param_3 = (int)ROUND((float)*(int *)(param_1 + 0xdc) * (local_c + g_flOne) * DAT_00a0f298);

  param_3[1] = (int)ROUND(fVar3);

  if ((((fVar2 < local_4) && (local_4 < fVar1)) && (DAT_00aaa668 < local_c)) &&

     (((DAT_00aaa668 < local_8 && (local_c < fVar1)) && (local_8 < fVar1)))) {

    return 1;

  }

  return 0;

}
