// =============================================================================
// FUN_0075c6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c6e0
// Address:   0x0075c6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075c6e0 @ 0x0075c6e0
// Stable ID: aa_0075c6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043f660, FUN_0075b7f0, FUN_0075c6e0, FUN_0076f6e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0075c6e0(int param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float local_c;

  float local_8;

  float local_4;

  

  FUN_0075b7f0();

  FUN_0043f660();

  FUN_0076f6e0();

  fVar3 = g_flOne;

  fVar2 = DAT_00a0f298;

  iVar1 = *(int *)(param_1 + 0xdc);

  fVar5 = local_c + g_flOne;

  param_3[1] = (g_flOne - local_8) * (float)*(int *)(param_1 + 0xe0) * DAT_00a0f298;

  fVar4 = g_flZero;

  *param_3 = (float)iVar1 * fVar5 * fVar2;

  param_3[2] = local_4;

  if ((((fVar4 < local_4) && (local_4 < fVar3)) && (DAT_00aaa668 < local_c)) &&

     (((DAT_00aaa668 < local_8 && (local_c < fVar3)) && (local_8 < fVar3)))) {

    return 1;

  }

  return 0;

}
