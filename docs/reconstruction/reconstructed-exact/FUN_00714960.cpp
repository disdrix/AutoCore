// =============================================================================
// FUN_00714960
// -----------------------------------------------------------------------------
// Stable ID: aa_00714960
// Address:   0x00714960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714960 @ 0x00714960
// Stable ID: aa_00714960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×6, if×5.
//  - Notable callees: FUN_00714960.
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_00714960(float param_1)



{

  if (_DAT_00a110b4 < param_1) {

    return 0x105;

  }

  if (_DAT_00a110b0 < param_1) {

    return 0xf1;

  }

  if (DAT_00a110ac < param_1) {

    return 0xdd;

  }

  if (param_1 <= _DAT_00a110a8) {

    if (param_1 <= DAT_00a11088) {

      return 0xa1;

    }

    return 0xb5;

  }

  return 0xc9;

}
