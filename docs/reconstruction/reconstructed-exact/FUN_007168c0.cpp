// =============================================================================
// FUN_007168c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007168c0
// Address:   0x007168c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007168c0 @ 0x007168c0
// Stable ID: aa_007168c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007168c0, ROUND.
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



int FUN_007168c0(int param_1,float param_2)



{

  int iVar1;

  

  iVar1 = (int)ROUND((_DAT_00a0f51c / param_2) * _DAT_00a132f8);

  if (param_1 < iVar1) {

    iVar1 = param_1;

  }

  return iVar1;

}
