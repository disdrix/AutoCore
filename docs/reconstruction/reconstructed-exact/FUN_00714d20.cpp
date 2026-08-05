// =============================================================================
// FUN_00714d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00714d20
// Address:   0x00714d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714d20 @ 0x00714d20
// Stable ID: aa_00714d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00714d20.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 FUN_00714d20(float param_1,float param_2,float param_3)



{

  float fVar1;

  

  fVar1 = _DAT_00a110e4;

  if ((g_flZero < param_3) && (fVar1 = param_3, g_flOne <= param_3)) {

    fVar1 = _DAT_00a110e0;

  }

  fVar1 = (g_flOne - fVar1) * 0.30103 * DAT_00a110dc;

  if (param_1 <= fVar1) {

    if (fVar1 <= param_2) {

      return ((float10)fVar1 - (float10)param_1) / ((float10)param_2 - (float10)param_1);

    }

    return (float10)g_flOne;

  }

  return (float10)g_flZero;

}
