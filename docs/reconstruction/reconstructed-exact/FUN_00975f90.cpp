// =============================================================================
// FUN_00975f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00975f90
// Address:   0x00975f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00975f90 @ 0x00975f90
// Stable ID: aa_00975f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0077bb70×2, FUN_0077b940, FUN_0077bc40, FUN_00975f90.
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

void FUN_00975f90(uint32_t /* width from decompiler */ param_1,int param_2)



{

  if (DAT_00d179d9 == '\0') {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077b940(param_1,param_2,&DAT_00d0a3b8);

  DAT_00d179dc = DAT_00d179dc + param_2;

  if (0xf < DAT_00d179dc) {

    FUN_0077bb70(&DAT_00d0a3b8);

    DAT_00d179dc = 0;

  }

  return;

}
