// =============================================================================
// FUN_00844fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00844fa0
// Address:   0x00844fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00844fa0 @ 0x00844fa0
// Stable ID: aa_00844fa0
// Embedded strings (evidence for future rename):
//   - "Small"
//   - "Large"
//   - "Medium"
//   - "Small Turret"
//   - "Universal Turret"
//   - "Large Turret"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×8, if×7.
//  - Notable callees: FUN_007a6de0×8, FUN_007a69d0, FUN_00844fa0.
//  - Strings: "Small"; "Large"; "Medium"; "Small Turret".
//  - Return sites: 8.

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

void FUN_00844fa0(char param_1)



{

  int unaff_ESI;

  

  FUN_007a69d0();

  if (param_1 == '\0') {

    if (unaff_ESI == 1) {

      FUN_007a6de0("Small",0xffffffff);

      return;

    }

    if (unaff_ESI != 2) {

      if (unaff_ESI != 3) {

        FUN_007a6de0(&DAT_00a328a0,0xffffffff);

        return;

      }

      FUN_007a6de0("Large",0xffffffff);

      return;

    }

    FUN_007a6de0("Medium",0xffffffff);

    return;

  }

  if (unaff_ESI == 1) {

    FUN_007a6de0("Small Turret",0xffffffff);

    return;

  }

  if (unaff_ESI != 2) {

    if (unaff_ESI != 3) {

      FUN_007a6de0("Universal Turret",0xffffffff);

      return;

    }

    FUN_007a6de0("Large Turret",0xffffffff);

    return;

  }

  FUN_007a6de0("Medium Turret",0xffffffff);

  return;

}
