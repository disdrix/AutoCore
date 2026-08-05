// =============================================================================
// FUN_0045fcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0045fcc0
// Address:   0x0045fcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045fcc0 @ 0x0045fcc0
// Stable ID: aa_0045fcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, return×2.
//  - Notable callees: FUN_0045f9d0, FUN_0045fcc0, FUN_00460430.
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

uint32_t /* width from decompiler */ * FUN_0045fcc0(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int unaff_EDI;

  

  piVar2 = *(int **)(unaff_EDI + 4);

  if ((param_2 == (int *)*piVar2) && (param_3 == piVar2)) {

    FUN_0045f9d0(piVar2[1]);

    *(int *)(*(int *)(unaff_EDI + 4) + 4) = *(int *)(unaff_EDI + 4);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4);

    *(int *)(*(int *)(unaff_EDI + 4) + 8) = *(int *)(unaff_EDI + 4);

    *param_1 = **(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

    return param_1;

  }

  while (param_2 != param_3) {

    if (*(char *)((int)param_2 + 0x21) == '\0') {

      piVar2 = (int *)param_2[2];

      if (*(char *)((int)piVar2 + 0x21) == '\0') {

        cVar1 = *(char *)(*piVar2 + 0x21);

        param_2 = piVar2;

        piVar2 = (int *)*piVar2;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          param_2 = piVar2;

          piVar2 = (int *)*piVar2;

        }

      }

      else {

        cVar1 = *(char *)(param_2[1] + 0x21);

        piVar3 = (int *)param_2[1];

        piVar2 = param_2;

        while ((param_2 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_2[2]))) {

          cVar1 = *(char *)(param_2[1] + 0x21);

          piVar3 = (int *)param_2[1];

          piVar2 = param_2;

        }

      }

    }

    FUN_00460430();

  }

  *param_1 = param_2;

  return param_1;

}
