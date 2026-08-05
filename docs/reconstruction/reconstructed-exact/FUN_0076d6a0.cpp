// =============================================================================
// FUN_0076d6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d6a0
// Address:   0x0076d6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d6a0 @ 0x0076d6a0
// Stable ID: aa_0076d6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076d6a0, FreeLibrary.
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

void FUN_0076d6a0(void)



{

  uint8_t *unaff_ESI;

  

  (*DAT_00d0dfc4)(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4));

  FreeLibrary(*(HMODULE *)(unaff_ESI + 8));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0xffffffff;

  *unaff_ESI = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  DAT_00d0dfa8 = 0;

  DAT_00d0dfc8 = 0;

  DAT_00d0dfb8 = 0;

  DAT_00d0dfac = 0;

  DAT_00d0dfc0 = 0;

  DAT_00d0dfb4 = 0;

  DAT_00d0dfbc = 0;

  DAT_00d0dfb0 = 0;

  DAT_00d0dfd0 = 0;

  return;

}
