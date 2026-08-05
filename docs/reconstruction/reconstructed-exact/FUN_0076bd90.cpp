// =============================================================================
// FUN_0076bd90
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bd90
// Address:   0x0076bd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076bd90 @ 0x0076bd90
// Stable ID: aa_0076bd90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076aba0, FUN_0076af70, FUN_0076bc80, FUN_0076bd90.
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

void FUN_0076bd90(uint32_t /* width from decompiler */ param_1)



{

  uint8_t local_204 [256];

  uint8_t local_104 [260];

  

  FUN_0076af70(local_204,0,0);

  FUN_0076aba0(local_104,0,0);

  FUN_0076bc80(param_1);

  return;

}
