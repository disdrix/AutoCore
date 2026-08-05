// =============================================================================
// FUN_006d7370
// -----------------------------------------------------------------------------
// Stable ID: aa_006d7370
// Address:   0x006d7370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d7370 @ 0x006d7370
// Stable ID: aa_006d7370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cb390×2, FUN_006d7370.
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

void FUN_006d7370(void)



{

  uint8_t *local_10;

  code *local_c;

  code *local_8;

  code *local_4;

  

  local_10 = &LAB_006d5a60;

  local_c = FUN_006d7240;

  local_8 = FUN_006d72c0;

  local_4 = FUN_006d51b0;

  FUN_006cb390(&local_10,5,9);

  local_10 = &LAB_006d5a10;

  local_c = FUN_006d6e10;

  local_8 = FUN_006d6520;

  local_4 = FUN_006f63e0;

  FUN_006cb390(&local_10,9,5);

  return;

}
