// =============================================================================
// FUN_0074ecd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074ecd0
// Address:   0x0074ecd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074ecd0 @ 0x0074ecd0
// Stable ID: aa_0074ecd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0074eaa0, FUN_0074ecd0, FUN_00963950.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_0074ecd0(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  int iVar1;

  

  iVar1 = FUN_00963950(in_EAX);

  if (iVar1 == -1) {

    return 0xffffffff;

  }

  FUN_0074eaa0();

  return 0;

}
