// =============================================================================
// FUN_00988970
// -----------------------------------------------------------------------------
// Stable ID: aa_00988970
// Address:   0x00988970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00988970 @ 0x00988970
// Stable ID: aa_00988970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_0044dc00, FUN_009887a0, FUN_00988970.
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

uint FUN_00988970(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  uint uVar5;

  

  piVar1 = *(int **)(param_1 + 4);

  piVar2 = (int *)*piVar1;

  uVar5 = 0;

  while (piVar2 != piVar1) {

    piVar3 = (int *)piVar2[3];

    if ((piVar2[7] != piVar3[0x20]) || (piVar2[8] != piVar3[0x21])) {

      FUN_009887a0();

    }

    uVar4 = (**(code **)(*piVar3 + 0x28))();

    uVar5 = uVar5 | uVar4;

    FUN_0044dc00();

  }

  return uVar5;

}
