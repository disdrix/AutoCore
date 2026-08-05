// =============================================================================
// FUN_007fbd10
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbd10
// Address:   0x007fbd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbd10 @ 0x007fbd10
// Stable ID: aa_007fbd10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007fbd10.
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

uint FUN_007fbd10(void)



{

  uint uVar1;

  

  if (DAT_00d1b251 == 1) {

    return 1;

  }

  uVar1 = DAT_00d1b251 - 2;

  if (uVar1 != 0) {

    return uVar1 & 0xffffff00;

  }

  return 2;

}
