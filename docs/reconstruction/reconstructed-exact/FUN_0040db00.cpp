// =============================================================================
// FUN_0040db00
// -----------------------------------------------------------------------------
// Stable ID: aa_0040db00
// Address:   0x0040db00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040db00 @ 0x0040db00
// Stable ID: aa_0040db00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040db00, InitializeCriticalSection.
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

void FUN_0040db00(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  unaff_ESI[8] = 0;

  unaff_ESI[7] = 0;

  unaff_ESI[9] = 0;

  *(uint8_t *)(unaff_ESI + 10) = 0;

  *unaff_ESI = &PTR_FUN_00a34140;

  InitializeCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 1));

  return;

}
