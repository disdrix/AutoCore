// =============================================================================
// FUN_00763260
// -----------------------------------------------------------------------------
// Stable ID: aa_00763260
// Address:   0x00763260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00763260 @ 0x00763260
// Stable ID: aa_00763260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×1.
//  - Notable callees: FUN_00456960×2, FUN_00763260.
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

void FUN_00763260(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int in_EAX;

  int *piVar4;

  int unaff_EDI;

  

  if (in_EAX != 0) {

    piVar1 = *(int **)(param_1 + 0xc4);

    for (piVar4 = *(int **)(param_1 + 0xc0); piVar4 != piVar1; piVar4 = piVar4 + 1) {

      if (*(int *)(*piVar4 + 0x8c) == param_2) {

        iVar2 = *(int *)(in_EAX + 4);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(in_EAX + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(in_EAX + 8) - iVar2 >> 2)

           )) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(in_EAX + 8));

        }

        else {

          piVar3 = *(int **)(in_EAX + 8);

          *piVar3 = *piVar4;

          *(int **)(in_EAX + 8) = piVar3 + 1;

        }

      }

    }

  }

  if (unaff_EDI != 0) {

    piVar1 = *(int **)(param_1 + 0xd4);

    for (piVar4 = *(int **)(param_1 + 0xd0); piVar4 != piVar1; piVar4 = piVar4 + 1) {

      if (*(int *)(*piVar4 + 0x8c) == param_2) {

        iVar2 = *(int *)(unaff_EDI + 4);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(unaff_EDI + 0xc) - iVar2 >> 2) <=

            (uint)(*(int *)(unaff_EDI + 8) - iVar2 >> 2))) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8));

        }

        else {

          piVar3 = *(int **)(unaff_EDI + 8);

          *piVar3 = *piVar4;

          *(int **)(unaff_EDI + 8) = piVar3 + 1;

        }

      }

    }

  }

  return;

}
