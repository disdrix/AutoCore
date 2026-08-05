// =============================================================================
// FUN_005e0430
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0430
// Address:   0x005e0430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e0430 @ 0x005e0430
// Stable ID: aa_005e0430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_005e0430.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ FUN_005e0430(uint32_t /* width from decompiler */ param_1)



{

  switch(param_1) {

  case 0:

    return 0;

  case 1:

    return 1;

  case 2:

    return 2;

  case 3:

    return 3;

  default:

    return 4;

  }

}
