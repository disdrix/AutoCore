// =============================================================================
// FUN_0075a150
// -----------------------------------------------------------------------------
// Stable ID: aa_0075a150
// Address:   0x0075a150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075a150 @ 0x0075a150
// Stable ID: aa_0075a150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, while×1, return×1.
//  - Notable callees: FUN_0075a150.
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

void __thiscall FUN_0075a150(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  

  piVar1 = *(int **)(param_1 + 0x20);

  for (piVar5 = *(int **)(param_1 + 0x1c); piVar5 != piVar1; piVar5 = piVar5 + 4) {

    if (*piVar5 == param_2) {

      piVar2 = *(int **)(param_1 + 0x20);

      piVar3 = piVar5;

      piVar4 = piVar5;

      while (piVar4 = piVar4 + 4, piVar4 != piVar2) {

        *piVar3 = *piVar4;

        piVar3[1] = piVar4[1];

        piVar3[2] = piVar4[2];

        piVar3[3] = piVar4[3];

        piVar3 = piVar3 + 4;

      }

      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -0x10;

    }

  }

  return;

}
