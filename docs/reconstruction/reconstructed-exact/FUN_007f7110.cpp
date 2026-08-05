// =============================================================================
// FUN_007f7110
// -----------------------------------------------------------------------------
// Stable ID: aa_007f7110
// Address:   0x007f7110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f7110 @ 0x007f7110
// Stable ID: aa_007f7110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_007f7110.
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

int __fastcall FUN_007f7110(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  switch(param_1) {

  case 0:

    return in_EAX + 6;

  case 1:

    return in_EAX + 0x10a;

  case 2:

    return in_EAX + 0x242;

  case 3:

    return in_EAX + 0x1aa2;

  default:

    return 0;

  }

}
