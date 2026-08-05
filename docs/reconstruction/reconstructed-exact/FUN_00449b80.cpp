// =============================================================================
// FUN_00449b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00449b80
// Address:   0x00449b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00449b80 @ 0x00449b80
// Stable ID: aa_00449b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00449b80.
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

int * __thiscall FUN_00449b80(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *in_EAX;

  

  while (param_2 != param_1) {

    piVar2 = *(int **)(param_1 + -4);

    param_1 = param_1 + -4;

    in_EAX = in_EAX + -1;

    if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

      (**(code **)(*piVar2 + 4))();

    }

    piVar3 = (int *)*in_EAX;

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *in_EAX = (int)piVar2;

  }

  return in_EAX;

}
