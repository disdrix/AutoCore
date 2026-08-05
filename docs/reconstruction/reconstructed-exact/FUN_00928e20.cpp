// =============================================================================
// FUN_00928e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00928e20
// Address:   0x00928e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928e20 @ 0x00928e20
// Stable ID: aa_00928e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×6, return×6.
//  - Notable callees: FUN_00928e20.
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

uint FUN_00928e20(void)



{

  uint in_EAX;

  

  if (in_EAX < 0x11) {

    if (4 < in_EAX) {

      return (-(uint)(8 < in_EAX) & 8) + 8;

    }

    if (2 < in_EAX) {

      in_EAX = 4;

    }

    return in_EAX;

  }

  if (in_EAX < 0x41) {

    return (-(uint)(0x20 < in_EAX) & 0x20) + 0x20;

  }

  if (in_EAX < 0x81) {

    return 0x80;

  }

  if (0x100 < in_EAX) {

    return (-(uint)(0x200 < in_EAX) & 0x200) + 0x200;

  }

  return 0x100;

}
