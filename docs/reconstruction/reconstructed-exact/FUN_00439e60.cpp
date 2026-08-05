// =============================================================================
// FUN_00439e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00439e60
// Address:   0x00439e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00439e60 @ 0x00439e60
// Stable ID: aa_00439e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00439e60.
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

void FUN_00439e60(int param_1)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int *piVar3;

  int unaff_EBX;

  

  for (; in_EAX != unaff_EBX; in_EAX = in_EAX + 8) {

    if (param_1 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)(param_1 + 4);

    }

    piVar3 = (int *)*piVar3;

    if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = *(int **)(in_EAX + 4);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *(int **)(in_EAX + 4) = piVar3;

  }

  return;

}
