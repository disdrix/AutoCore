// =============================================================================
// FUN_00930f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00930f40
// Address:   0x00930f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00930f40 @ 0x00930f40
// Stable ID: aa_00930f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_00930f40.
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

void __fastcall FUN_00930f40(uint32_t /* width from decompiler */ param_1)



{

  uint8_t *in_EAX;

  

  switch(param_1) {

  case 0:

    in_EAX[2] = 0xc4;

    in_EAX[1] = 0x16;

    *in_EAX = 0x16;

    in_EAX[3] = 0xff;

    return;

  default:

    in_EAX[2] = 0xdc;

    in_EAX[1] = 0xe0;

    *in_EAX = 200;

    in_EAX[3] = 0xff;

    return;

  case 2:

    in_EAX[2] = 0x66;

    in_EAX[1] = 0xd3;

    *in_EAX = 0xea;

    in_EAX[3] = 0xff;

    return;

  case 3:

    in_EAX[2] = 0x14;

    in_EAX[1] = 0xd3;

    *in_EAX = 0x14;

    in_EAX[3] = 0xff;

    return;

  case 0xffffffff:

    in_EAX[2] = 0xff;

    in_EAX[1] = 0xff;

    *in_EAX = 0xff;

    in_EAX[3] = 0xff;

    return;

  }

}
