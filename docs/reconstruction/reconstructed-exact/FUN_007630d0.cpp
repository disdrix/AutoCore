// =============================================================================
// FUN_007630d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007630d0
// Address:   0x007630d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007630d0 @ 0x007630d0
// Stable ID: aa_007630d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_00456960×2, memmove×2, FUN_007630d0.
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

void FUN_007630d0(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int in_EAX;

  int *piVar4;

  int unaff_EDI;

  int *local_8;

  

  iVar3 = (int)param_2;

  if ((in_EAX != 0) && (piVar4 = *(int **)(unaff_EDI + 0xc0), piVar4 != *(int **)(unaff_EDI + 0xc4))

     ) {

    local_8 = piVar4 + 1;

    do {

      if (*(int *)(*piVar4 + 0x8c) == param_1) {

        iVar1 = *(int *)(in_EAX + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(in_EAX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_EAX + 8) - iVar1 >> 2)

           )) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(in_EAX + 8));

        }

        else {

          piVar2 = *(int **)(in_EAX + 8);

          *piVar2 = *piVar4;

          *(int **)(in_EAX + 8) = piVar2 + 1;

        }

        memmove(piVar4,local_8,(*(int *)(unaff_EDI + 0xc4) - (int)local_8 >> 2) * 4);

        *(int *)(unaff_EDI + 0xc4) = *(int *)(unaff_EDI + 0xc4) + -4;

      }

      else {

        piVar4 = piVar4 + 1;

        local_8 = local_8 + 1;

      }

    } while (piVar4 != *(int **)(unaff_EDI + 0xc4));

  }

  if ((param_2 != (int *)0x0) &&

     (piVar4 = *(int **)(unaff_EDI + 0xd0), piVar4 != *(int **)(unaff_EDI + 0xd4))) {

    param_2 = piVar4 + 1;

    do {

      if (*(int *)(*piVar4 + 0x8c) == param_1) {

        iVar1 = *(int *)(iVar3 + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 8) - iVar1 >> 2)))

        {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar3 + 8));

        }

        else {

          piVar2 = *(int **)(iVar3 + 8);

          *piVar2 = *piVar4;

          *(int **)(iVar3 + 8) = piVar2 + 1;

        }

        memmove(piVar4,param_2,(*(int *)(unaff_EDI + 0xd4) - (int)param_2 >> 2) * 4);

        *(int *)(unaff_EDI + 0xd4) = *(int *)(unaff_EDI + 0xd4) + -4;

      }

      else {

        piVar4 = piVar4 + 1;

        param_2 = param_2 + 1;

      }

    } while (piVar4 != *(int **)(unaff_EDI + 0xd4));

  }

  return;

}
