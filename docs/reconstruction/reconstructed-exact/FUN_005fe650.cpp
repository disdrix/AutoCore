// =============================================================================
// FUN_005fe650
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe650
// Address:   0x005fe650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fe650 @ 0x005fe650
// Stable ID: aa_005fe650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005fe650, FUN_0063f5b0.
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

void FUN_005fe650(uint32_t /* width from decompiler */ *param_1)



{

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_0063f5b0();

    *param_1 = 0;

    param_1[1] = 0;

    param_1[2] = 0;

    *(uint8_t *)(param_1 + 3) = 0;

  }

  return;

}
