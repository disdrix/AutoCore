// =============================================================================
// FUN_00713450
// -----------------------------------------------------------------------------
// Stable ID: aa_00713450
// Address:   0x00713450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713450 @ 0x00713450
// Stable ID: aa_00713450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00713450, ROUND, f2xm1, fscale.
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



unkbyte10 FUN_00713450(int param_1)



{

  float10 fVar1;

  unkbyte10 Var2;

  float10 fVar3;

  

  fVar3 = (float10)1.4426950408889634 *

          ((float10)_DAT_00a0f6a8 - (float10)param_1 * (float10)_DAT_00a0f6ac);

  fVar1 = ROUND(fVar3);

  fVar3 = (float10)f2xm1(fVar3 - fVar1);

  Var2 = fscale((float10)1 + fVar3,fVar1);

  return Var2;

}
