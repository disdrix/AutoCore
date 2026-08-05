// =============================================================================
// FUN_006ee470
// -----------------------------------------------------------------------------
// Stable ID: aa_006ee470
// Address:   0x006ee470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ee470 @ 0x006ee470
// Stable ID: aa_006ee470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cb390×2, FUN_006ee470.
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

void FUN_006ee470(void)



{

  uint8_t *local_10;

  code *local_c;

  code *local_8;

  code *local_4;

  

  local_10 = &LAB_006ee220;

  local_c = FUN_006ee030;

  local_8 = FUN_006ee070;

  local_4 = FUN_006ee260;

  FUN_006cb390(&local_10,0xffffffff,0x11);

  local_10 = &LAB_006ed710;

  local_c = FUN_006edef0;

  local_8 = FUN_006edd10;

  local_4 = FUN_006eda50;

  FUN_006cb390(&local_10,0x11,0xffffffff);

  return;

}
