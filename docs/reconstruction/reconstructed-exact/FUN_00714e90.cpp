// =============================================================================
// FUN_00714e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00714e90
// Address:   0x00714e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714e90 @ 0x00714e90
// Stable ID: aa_00714e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00714e90.
//  - Return sites: 4.

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



float10 FUN_00714e90(float param_1,float param_2,float param_3,float param_4)



{

  float fVar1;

  float10 fVar2;

  

  if ((param_2 <= param_1 * _DAT_00a0f69c) && (param_1 * DAT_00a0f698 <= param_2)) {

    return ((float10)param_1 + (float10)param_2) * (float10)DAT_00a0f298;

  }

  fVar1 = param_2;

  if (param_4 < param_3) {

    param_4 = param_3;

    fVar1 = param_1;

  }

  fVar2 = (float10)fVar1;

  if ((fVar2 < (float10)DAT_00a0f694) &&

     ((float10)param_4 * fVar2 * (float10)DAT_00a0f298 < (float10)g_flOne)) {

    if (param_2 <= param_1) {

      return (float10)param_1;

    }

    return (float10)param_2;

  }

  return fVar2;

}
