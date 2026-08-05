// =============================================================================
// FUN_00580a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00580a20
// Address:   0x00580a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00580a20 @ 0x00580a20
// Stable ID: aa_00580a20
// Embedded strings (evidence for future rename):
//   - "Afraid"
//   - "GM Frozen"
//   - "Stunned"
//   - "Locked Down"
//   - "Silenced"
//   - "Weapons Disabled"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: return×14, if×9, switch×1.
//  - Notable callees: FUN_00580a20.
//  - Strings: "Afraid"; "GM Frozen"; "Stunned"; "Locked Down".
//  - Return sites: 14.

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

char * FUN_00580a20(int param_1)



{

  if (param_1 < 0x41) {

    if (param_1 == 0x40) {

      return "Afraid";

    }

    switch(param_1) {

    case 1:

      return "GM Frozen";

    case 2:

      return "Stunned";

    case 4:

      return "Locked Down";

    case 8:

      return "Silenced";

    case 0x10:

      return "Weapons Disabled";

    case 0x20:

      return "GM Chat Banned";

    }

  }

  else if (param_1 < 0x2001) {

    if (param_1 == 0x2000) {

      return "Immune to death";

    }

    if (param_1 == 0x80) {

      return "Confused";

    }

    if (param_1 == 0x200) {

      return "Blind";

    }

    if (param_1 == 0x1000) {

      return "Slowed";

    }

  }

  else {

    if (param_1 == 0x4000) {

      return "Speeding";

    }

    if (param_1 == 0x10000) {

      return "Zombied";

    }

  }

  return "in a world of hurt";

}
