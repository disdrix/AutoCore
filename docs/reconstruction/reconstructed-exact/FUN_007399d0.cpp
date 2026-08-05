// =============================================================================
// FUN_007399d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007399d0
// Address:   0x007399d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007399d0 @ 0x007399d0
// Stable ID: aa_007399d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00464f50, FUN_00739670, FUN_007399d0, FUN_00748430.
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

void FUN_007399d0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int *piVar3;

  

  FUN_00748430(param_1);

  if (param_1 == -0xc4) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)(param_1 + 200);

  }

  piVar3 = (int *)*piVar3;

  if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

    (**(code **)(*piVar3 + 4))();

  }

  piVar2 = *(int **)(in_EAX + 200);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(in_EAX + 200) = piVar3;

  FUN_00464f50();

  *(uint8_t *)(in_EAX + 0xcc) = *(uint8_t *)(param_1 + 0xcc);

  if ((*(uint *)(in_EAX + 0xbc) >> 4 & 1) != 0) {

    FUN_00739670();

  }

  return;

}
