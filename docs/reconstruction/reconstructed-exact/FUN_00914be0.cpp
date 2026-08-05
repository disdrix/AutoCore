// =============================================================================
// FUN_00914be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00914be0
// Address:   0x00914be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914be0 @ 0x00914be0
// Stable ID: aa_00914be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, FUN_00914be0.
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

uint32_t /* width from decompiler */ FUN_00914be0(void)



{

  if ((DAT_00d1b644 == 0) || (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

    return CONCAT31((int3)((uint)DAT_00d1b644 >> 8),DAT_00d1b222);

  }

  if ((DAT_00d1b221 == '\0') && (DAT_00d1d866 == '\0')) {

    return 0;

  }

  return 1;

}
