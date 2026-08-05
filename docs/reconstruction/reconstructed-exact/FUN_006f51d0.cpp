// =============================================================================
// FUN_006f51d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f51d0
// Address:   0x006f51d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f51d0 @ 0x006f51d0
// Stable ID: aa_006f51d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: ABS, FUN_006f51d0.
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

float10 __thiscall FUN_006f51d0(int param_1,int *param_2)



{

  float10 fVar1;

  

  fVar1 = ABS((float10)(param_2[5] - param_2[0xd])) * (float10)(float)param_2[7];

  if (*param_2 < param_2[1]) {

    fVar1 = (fVar1 - (float10)DAT_00a0f708) * (float10)DAT_00aaa8dc;

    if (fVar1 < (float10)g_flZero) {

      return (float10)g_flZero;

    }

  }

  else {

    fVar1 = fVar1 * fVar1;

  }

  return fVar1 * fVar1 * fVar1 * fVar1 * (float10)*(float *)(param_1 + 0x10);

}
