// =============================================================================
// FUN_008350a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008350a0
// Address:   0x008350a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008350a0 @ 0x008350a0
// Stable ID: aa_008350a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×9, if×7, switch×1, goto×1.
//  - Notable callees: FUN_008350a0.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_008350a0(void)



{

  int in_EAX;

  

  if (0x20 < in_EAX) {

    if (in_EAX < 0x201) {

      if (in_EAX == 0x200) {

        return 5;

      }

      if ((in_EAX == 0x40) || (in_EAX == 0x80)) {

        return 6;

      }

    }

    else {

      if (in_EAX == 0x1000) {

        return 0;

      }

      if (in_EAX == 0x4000) {

        return 1;

      }

    }

switchD_008350b6_caseD_3:

    return 0xffffffff;

  }

  if (in_EAX != 0x20) {

    switch(in_EAX) {

    case 1:

    case 4:

      break;

    case 2:

      return 7;

    default:

      goto switchD_008350b6_caseD_3;

    case 8:

      return 2;

    case 0x10:

      return 3;

    }

  }

  return 4;

}
