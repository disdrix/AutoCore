// =============================================================================
// FUN_007133f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007133f0
// Address:   0x007133f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007133f0 @ 0x007133f0
// Stable ID: aa_007133f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007133f0, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_007133f0(float param_1)



{

  float fVar1;

  

  fVar1 = DAT_00a0f6a4;

  if ((DAT_00a0f6a4 < param_1) && (fVar1 = param_1, _DAT_00a0f6a0 < param_1)) {

    fVar1 = _DAT_00a0f6a0;

  }

  return (int)ROUND(((float)_DAT_00a10e08 - fVar1 * 0.6931472) * _DAT_00a10e00);

}
