// =============================================================================
// FUN_00422900
// -----------------------------------------------------------------------------
// Stable ID: aa_00422900
// Address:   0x00422900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00422900 @ 0x00422900
// Stable ID: aa_00422900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×4, if×2, switch×1, goto×1.
//  - Notable callees: FUN_00422900.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00422900(void)



{

  ushort in_AX;

  

  if (((in_AX & 0x4000) == 0) && ((in_AX & 0x2000) == 0)) {

    if ((in_AX & 0x1000) == 0) {

      switch(in_AX) {

      case 2:

      case 0xb:

      case 0x12:

      case 0x82:

      case 0x85:

      case 0x86:

      case 0x87:

        break;

      case 3:

      case 4:

      case 8:

      case 9:

      case 10:

      case 0xd:

      case 0x13:

      case 0x48:

        goto switchD_00422923_caseD_3;

      default:

        return 8;

      case 0x10:

      case 0x11:

      case 0x14:

      case 0x15:

      case 0x80:

      case 0x81:

      case 0x83:

        return 1;

      }

    }

    return 2;

  }

switchD_00422923_caseD_3:

  return 4;

}
