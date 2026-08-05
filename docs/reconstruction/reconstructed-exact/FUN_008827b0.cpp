// =============================================================================
// FUN_008827b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008827b0
// Address:   0x008827b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008827b0 @ 0x008827b0
// Stable ID: aa_008827b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×10, switch×1.
//  - Notable callees: FUN_008827b0.
//  - Return sites: 10.

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

uint32_t /* width from decompiler */ FUN_008827b0(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  switch(in_EAX) {

  case 0:

    return 1;

  case 1:

    return 5;

  case 2:

    return 4;

  case 3:

    return 2;

  case 4:

    return 9;

  case 5:

    return 8;

  case 6:

    return 3;

  case 7:

    return 7;

  case 8:

    return 6;

  default:

    return 0;

  }

}
