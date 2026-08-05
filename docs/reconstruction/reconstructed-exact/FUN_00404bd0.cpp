// =============================================================================
// FUN_00404bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00404bd0
// Address:   0x00404bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404bd0 @ 0x00404bd0
// Stable ID: aa_00404bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00404bd0, SQRT.
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

float10 __thiscall FUN_00404bd0(float *param_1,float *param_2)



{

  return SQRT(((float10)param_1[1] - (float10)param_2[1]) *

              ((float10)param_1[1] - (float10)param_2[1]) +

              ((float10)param_1[2] - (float10)param_2[2]) *

              ((float10)param_1[2] - (float10)param_2[2]) +

              ((float10)*param_1 - (float10)*param_2) * ((float10)*param_1 - (float10)*param_2));

}
