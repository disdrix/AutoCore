// =============================================================================
// FUN_006d3b50
// -----------------------------------------------------------------------------
// Stable ID: aa_006d3b50
// Address:   0x006d3b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d3b50 @ 0x006d3b50
// Stable ID: aa_006d3b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006d3b50.
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

void FUN_006d3b50(uint8_t *param_1,int param_2,int param_3,int param_4)



{

  if (*(code **)(param_2 + 0x18c + (param_3 * 0x20 + param_4) * 4) == FUN_006e4850) {

    *param_1 = 1;

    return;

  }

  *param_1 = 0;

  return;

}
