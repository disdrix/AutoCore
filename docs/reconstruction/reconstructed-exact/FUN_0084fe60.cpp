// =============================================================================
// FUN_0084fe60
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fe60
// Address:   0x0084fe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084fe60 @ 0x0084fe60
// Stable ID: aa_0084fe60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×7, switch×1.
//  - Notable callees: FUN_0084fe60.
//  - Return sites: 7.

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

void __fastcall FUN_0084fe60(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  switch(param_1) {

  case 0:

    *in_EAX = 0xfef59623;

    return;

  case 1:

    *in_EAX = 0xfe11ff11;

    return;

  case 2:

    *in_EAX = 0xfe1111ff;

    return;

  case 3:

  case 4:

  case 5:

  case 6:

  case 7:

  case 8:

  case 0xb:

  case 0xc:

  case 0xd:

  case 0xe:

  case 0xf:

  case 0x10:

  case 0x11:

  case 0x12:

  case 0x13:

    *in_EAX = 0xfeffffff;

    return;

  default:

    *in_EAX = 0xfe66d3ea;

    return;

  case 100:

    *in_EAX = 0xfecccccc;

    return;

  case 0x65:

    *in_EAX = 0xfecaff0b;

    return;

  }

}
