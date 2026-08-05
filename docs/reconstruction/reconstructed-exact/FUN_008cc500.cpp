// =============================================================================
// FUN_008cc500
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc500
// Address:   0x008cc500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc500 @ 0x008cc500
// Stable ID: aa_008cc500
// Embedded strings (evidence for future rename):
//   - "Shaman"
//   - "Champion"
//   - "Avenger"
//   - "Archon"
//   - "Engineer"
//   - "Commando"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×12, if×11.
//  - Notable callees: FUN_008cc500.
//  - Strings: "Shaman"; "Champion"; "Avenger"; "Archon".
//  - Return sites: 12.

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

char * __fastcall FUN_008cc500(int param_1)



{

  int in_EAX;

  

  if (param_1 == 1) {

    if (in_EAX == 1) {

      return "Shaman";

    }

    if (in_EAX != 2) {

      if (in_EAX != 3) {

        return "Champion";

      }

      return "Avenger";

    }

    return "Archon";

  }

  if (param_1 != 2) {

    if (in_EAX == 1) {

      return "Engineer";

    }

    if (in_EAX != 2) {

      if (in_EAX != 3) {

        return "Commando";

      }

      return "Bounty Hunter";

    }

    return "Lieutenant";

  }

  if (in_EAX == 1) {

    return "Constructor";

  }

  if (in_EAX != 2) {

    if (in_EAX != 3) {

      return "Terminator";

    }

    return "Agent";

  }

  return "MasterMind";

}
