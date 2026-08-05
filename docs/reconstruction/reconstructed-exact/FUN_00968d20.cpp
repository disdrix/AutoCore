// =============================================================================
// FUN_00968d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00968d20
// Address:   0x00968d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00968d20 @ 0x00968d20
// Stable ID: aa_00968d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0074b510, FUN_0074b700, FUN_00968d20.
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

void __fastcall FUN_00968d20(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  FUN_0074b510();

  piVar1 = *(int **)(param_1 + 0xc4);

  for (piVar3 = *(int **)(param_1 + 0xc0); piVar3 != piVar1; piVar3 = piVar3 + 1) {

    piVar2 = (int *)*piVar3;

    if ((*(byte *)(piVar2 + 0x2f) & 1) != 0) {

      (**(code **)(*piVar2 + 0x5c))();

    }

    FUN_0074b700(piVar2 + 10);

  }

  return;

}
