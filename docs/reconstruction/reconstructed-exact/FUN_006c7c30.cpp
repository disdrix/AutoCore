// =============================================================================
// FUN_006c7c30
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7c30
// Address:   0x006c7c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c7c30 @ 0x006c7c30
// Stable ID: aa_006c7c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c7c30.
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

float10 __thiscall FUN_006c7c30(int *param_1,float *param_2)



{

  float fStack_28;

  float fStack_24;

  float local_20 [7];

  

  (**(code **)(*param_1 + 0x30))(param_2,local_20);

  return (float10)fStack_28 * (float10)*param_2 +

         (float10)fStack_24 * (float10)param_2[1] + (float10)local_20[0] * (float10)param_2[2] +

         (float10)(float)param_1[3];

}
