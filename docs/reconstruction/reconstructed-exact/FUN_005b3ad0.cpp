// =============================================================================
// FUN_005b3ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3ad0
// Address:   0x005b3ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b3ad0 @ 0x005b3ad0
// Stable ID: aa_005b3ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_005b3ad0.
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

float10 __thiscall FUN_005b3ad0(int param_1,int param_2)



{

  float fVar1;

  

  fVar1 = *(float *)(param_1 + 0x24) - *(float *)(param_2 + 4);

  if (fVar1 <= 0.0) {

    return (float10)g_flZero;

  }

  if (DAT_00aaa7a4 < fVar1) {

    return (float10)g_flOne;

  }

  return (float10)fVar1 * (float10)DAT_00aaac18;

}
