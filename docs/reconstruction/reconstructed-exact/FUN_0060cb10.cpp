// =============================================================================
// FUN_0060cb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0060cb10
// Address:   0x0060cb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060cb10 @ 0x0060cb10
// Stable ID: aa_0060cb10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004e2600, FUN_0060cb10.
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

void FUN_0060cb10(uint32_t /* width from decompiler */ param_1)



{

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4;

  

  local_8 = param_1;

  local_4 = 1;

  FUN_004e2600(FUN_0060c9b0,local_c,0);

  return;

}
