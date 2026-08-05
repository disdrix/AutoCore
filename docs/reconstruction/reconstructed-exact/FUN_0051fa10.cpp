// =============================================================================
// FUN_0051fa10
// -----------------------------------------------------------------------------
// Stable ID: aa_0051fa10
// Address:   0x0051fa10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051fa10 @ 0x0051fa10
// Stable ID: aa_0051fa10
// Embedded strings (evidence for future rename):
//   - ";

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×15, if×12, switch×1.
//  - Notable callees: FUN_0051fa10.
//  - Strings: "SHM"; "CON"; "ENG"; ";

    }

    if (param_2 == 1) {

      return ".
//  - Return sites: 15.

    }

    if (param_2 == 1) {

      return "
//   - ";

    }

    if (param_2 == 2) {

      return "
//   - ";

    }

    return "
//   - ";

  case 3:

    if (param_2 == 0) {

      return "
//   - ";

  default:

    return "
//   - ";

  }

  if (param_2 != 0) {

    if (param_2 == 1) {

      return "
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

char * FUN_0051fa10(uint32_t /* width from decompiler */ param_1,int param_2)



{

  switch(param_1) {

  case 0:

    break;

  case 1:

    if (param_2 != 0) {

      if (param_2 == 1) {

        return "SHM";

      }

      if (param_2 == 2) {

        return "CON";

      }

    }

    return "ENG";

  case 2:

    if (param_2 == 0) {

      return "LT";

    }

    if (param_2 == 1) {

      return "ARC";

    }

    if (param_2 == 2) {

      return "MM";

    }

    return "OFF";

  case 3:

    if (param_2 == 0) {

      return "BH";

    }

    if (param_2 == 1) {

      return "AVG";

    }

    if (param_2 == 2) {

      return "AGT";

    }

    return "RNG";

  default:

    return "Unknown";

  }

  if (param_2 != 0) {

    if (param_2 == 1) {

      return "CHA";

    }

    if (param_2 == 2) {

      return "TRM";

    }

  }

  return "COM";

}
