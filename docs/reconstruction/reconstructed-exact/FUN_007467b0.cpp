// =============================================================================
// FUN_007467b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007467b0
// Address:   0x007467b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007467b0 @ 0x007467b0
// Stable ID: aa_007467b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_007467b0.
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

uint32_t /* width from decompiler */ FUN_007467b0(void)



{

  int in_EAX;

  

  switch(*(uint8_t *)(in_EAX + 4)) {

  case 0:

  case 4:

  case 5:

  case 6:

  case 8:

  case 9:

  case 0xb:

  case 0xd:

  case 0xe:

  case 0xf:

    return 4;

  case 1:

  case 7:

  case 10:

  case 0xc:

  case 0x10:

    return 8;

  case 2:

    return 0xc;

  case 3:

    return 0x10;

  default:

    return 0;

  }

}
