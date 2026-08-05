// =============================================================================
// Named_CalleeOf_Named_Combat_0051f940
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f940
// Callee of Named_Combat (+3 other named callers)
// Address:   0x0051f940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Combat: combat/reward helper. Evidence string: "Shaman". Supports parent flow (not a free-standing entry point). Named_Combat (+3 other named callers).
// Embedded strings (evidence):
//   - "Shaman"
//   - "Constructor"
//   - "Engineer"
//   - "Lieutenant"
//   - "Archon"
//   - "MasterMind"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×15, if×12, switch×1.
//  - Notable callees: FUN_0051f940.
//  - Strings: "Shaman"; "Constructor"; "Engineer"; "Lieutenant".
//  - Return sites: 15.

/*
 * Behavioral notes:
 * Callee of Named_Combat (+3 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char * Named_CalleeOf_Named_Combat_0051f940(uint32_t /* width from decompiler */ param_1,int param_2)



{

  switch(param_1) {

  case 0:

    break;

  case 1:

    if (param_2 != 0) {

      if (param_2 == 1) {

        return "Shaman";

      }

      if (param_2 == 2) {

        return "Constructor";

      }

    }

    return "Engineer";

  case 2:

    if (param_2 == 0) {

      return "Lieutenant";

    }

    if (param_2 == 1) {

      return "Archon";

    }

    if (param_2 == 2) {

      return "MasterMind";

    }

    return "Officer";

  case 3:

    if (param_2 == 0) {

      return "Bounty Hunter";

    }

    if (param_2 == 1) {

      return "Avenger";

    }

    if (param_2 == 2) {

      return "Agent";

    }

    return "Ranger";

  default:

    return "Unknown";

  }

  if (param_2 != 0) {

    if (param_2 == 1) {

      return "Champion";

    }

    if (param_2 == 2) {

      return "Terminator";

    }

  }

  return "Commando";

}
