// =============================================================================
// FUN_007f7240
// -----------------------------------------------------------------------------
// Stable ID: aa_007f7240
// Address:   0x007f7240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f7240 @ 0x007f7240
// Stable ID: aa_007f7240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×5, if×4, switch×1.
//  - Notable callees: FUN_007f7240.
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

int __fastcall FUN_007f7240(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  byte in_AL;

  

  switch(param_2) {

  case 0:

    if (in_AL < 5) {

      return param_3 + 6 + (uint)in_AL * 0x34;

    }

    break;

  case 1:

    if (in_AL < 6) {

      return param_3 + 0x10a + (uint)in_AL * 0x34;

    }

    break;

  case 2:

    if (in_AL < 0x78) {

      return param_3 + 0x242 + (uint)in_AL * 0x34;

    }

    break;

  case 3:

    if (in_AL < 0x14) {

      return param_3 + 0x1aa2 + (uint)in_AL * 0x34;

    }

  }

  return 0;

}
