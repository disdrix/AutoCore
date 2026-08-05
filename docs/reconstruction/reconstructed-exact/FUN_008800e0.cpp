// =============================================================================
// FUN_008800e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008800e0
// Address:   0x008800e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008800e0 @ 0x008800e0
// Stable ID: aa_008800e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_00862b70×10, FUN_0087d810, FUN_008800e0.
//  - Return sites: 1.

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

void FUN_008800e0(void)



{

  char cVar1;

  int *unaff_ESI;

  

  if (DAT_00d1b6d8 != 0) {

    cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();

    if (cVar1 != '\0') {

      if (unaff_ESI[0x168] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x16a] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x169] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x162] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x163] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x164] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x165] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x166] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x167] != 0) {

        FUN_00862b70();

      }

      if (unaff_ESI[0x16b] != 0) {

        FUN_00862b70();

      }

      FUN_0087d810();

    }

  }

  return;

}
