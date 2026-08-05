// =============================================================================
// FUN_006e8240
// -----------------------------------------------------------------------------
// Stable ID: aa_006e8240
// Address:   0x006e8240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e8240 @ 0x006e8240
// Stable ID: aa_006e8240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cb390×2, FUN_006e8240.
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

void FUN_006e8240(void)



{

  uint8_t *local_10;

  uint8_t *local_c;

  code *local_8;

  code *local_4;

  

  local_10 = &LAB_006e8180;

  local_c = &LAB_006e80e0;

  local_8 = FUN_0056f570;

  local_4 = FUN_0056f570;

  FUN_006cb390(&local_10,0x16,0xffffffff);

  FUN_006cb390(&local_10,0xffffffff,0x16);

  return;

}
