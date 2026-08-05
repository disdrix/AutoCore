// =============================================================================
// FUN_005fdf20
// -----------------------------------------------------------------------------
// Stable ID: aa_005fdf20
// Address:   0x005fdf20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fdf20 @ 0x005fdf20
// Stable ID: aa_005fdf20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: ABS, FUN_005fdf20.
//  - Return sites: 3.

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

float10 __fastcall FUN_005fdf20(int param_1)



{

  float fVar1;

  float fVar2;

  

  fVar1 = ABS(*(float *)(param_1 + 0x1c));

  if (fVar1 < *(float *)(param_1 + 0x38)) {

    return (float10)g_flZero;

  }

  fVar2 = g_flOne;

  if (*(float *)(param_1 + 0x1c) <= g_flZero) {

    fVar2 = DAT_00aaa668;

  }

  if (fVar1 < *(float *)(param_1 + 0x28)) {

    return ((float10)fVar1 - (float10)*(float *)(param_1 + 0x38)) *

           (float10)*(float *)(param_1 + 0x2c) * (float10)fVar2;

  }

  return (((float10)fVar1 - (float10)*(float *)(param_1 + 0x28)) *

          (float10)*(float *)(param_1 + 0x30) + (float10)*(float *)(param_1 + 0x34)) *

         (float10)fVar2;

}
