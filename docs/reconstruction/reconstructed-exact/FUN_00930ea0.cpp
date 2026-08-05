// =============================================================================
// FUN_00930ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00930ea0
// Address:   0x00930ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00930ea0 @ 0x00930ea0
// Stable ID: aa_00930ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×6, switch×1.
//  - Notable callees: FUN_00930ea0.
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

void __fastcall FUN_00930ea0(uint32_t /* width from decompiler */ param_1)



{

  uint8_t *in_EAX;

  

  switch(param_1) {

  case 0:

    in_EAX[2] = 99;

    in_EAX[1] = 0x76;

    *in_EAX = 0xce;

    in_EAX[3] = 0xff;

    return;

  case 1:

    in_EAX[2] = 0xd1;

    in_EAX[1] = 0xce;

    *in_EAX = 0x1e;

    in_EAX[3] = 0xff;

    return;

  case 2:

    in_EAX[2] = 0xff;

    in_EAX[1] = 0x9d;

    *in_EAX = 0x1e;

    in_EAX[3] = 0xff;

    return;

  default:

    in_EAX[2] = 0x99;

    in_EAX[1] = 0x99;

    *in_EAX = 0x99;

    in_EAX[3] = 0xff;

    return;

  case 4:

    in_EAX[2] = 0xf9;

    in_EAX[1] = 0xa1;

    *in_EAX = 0x54;

    in_EAX[3] = 0xff;

    return;

  case 9:

    in_EAX[2] = 0x89;

    in_EAX[1] = 0x28;

    *in_EAX = 0x90;

    in_EAX[3] = 0xff;

    return;

  }

}
