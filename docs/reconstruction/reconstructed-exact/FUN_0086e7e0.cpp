// =============================================================================
// FUN_0086e7e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086e7e0
// Address:   0x0086e7e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0086e7e0 @ 0x0086e7e0
// Stable ID: aa_0086e7e0
// Embedded strings (evidence for future rename):
//   - "Join Selected Arena"
//   - "Spectate Selected Arena"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0086e7e0.
//  - Strings: "Join Selected Arena"; "Spectate Selected Arena".
//  - Return sites: 2.

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

void FUN_0086e7e0(void)



{

  char cVar1;

  int *unaff_ESI;

  

  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((cVar1 != '\0') && (unaff_ESI[0x14e] != 0)) {

    if ((char)unaff_ESI[0x144] == '\0') {

      (**(code **)(*(int *)unaff_ESI[0x14e] + 0x1d8))("Join Selected Arena",1,1);

    }

    else {

      (**(code **)(*(int *)unaff_ESI[0x14e] + 0x1d8))("Spectate Selected Arena");

    }

                    /* WARNING: Could not recover jumptable at 0x0086e82e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)unaff_ESI[0x14e] + 0x34c))();

    return;

  }

  return;

}
