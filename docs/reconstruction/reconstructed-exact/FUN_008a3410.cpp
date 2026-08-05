// =============================================================================
// FUN_008a3410
// -----------------------------------------------------------------------------
// Stable ID: aa_008a3410
// Address:   0x008a3410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a3410 @ 0x008a3410
// Stable ID: aa_008a3410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×1, do×1, while×1.
//  - Notable callees: FUN_00404840, FUN_00418700, FUN_008a3410.
//  - Return sites: 4.

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

void FUN_008a3410(int param_1,char param_2)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int *piVar3;

  int iVar4;

  

  piVar3 = *(int **)(in_EAX + 0x5c4);

  piVar2 = (int *)*piVar3;

  if (param_2 == '\0') {

    for (; piVar2 != piVar3; piVar2 = (int *)*piVar2) {

      if (piVar2[2] == param_1) {

        return;

      }

    }

    iVar1 = *(int *)(in_EAX + 0x5c4);

    iVar4 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&param_1);

    FUN_00404840(1);

    *(int *)(iVar1 + 4) = iVar4;

    **(int **)(iVar4 + 4) = iVar4;

  }

  else if (piVar2 != piVar3) {

    do {

      if (piVar2[2] == param_1) {

        piVar3 = (int *)*piVar2;

        if (piVar2 != *(int **)(in_EAX + 0x5c4)) {

          *(int **)piVar2[1] = piVar3;

          *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar2);

        }

      }

      else {

        piVar3 = (int *)*piVar2;

      }

      piVar2 = piVar3;

    } while (piVar3 != *(int **)(in_EAX + 0x5c4));

    return;

  }

  return;

}
