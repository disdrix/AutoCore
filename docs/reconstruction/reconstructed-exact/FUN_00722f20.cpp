// =============================================================================
// FUN_00722f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00722f20
// Address:   0x00722f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00722f20 @ 0x00722f20
// Stable ID: aa_00722f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, do×3, while×3, goto×1.
//  - Notable callees: FUN_00722aa0, FUN_00722f20, memmove.
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

void FUN_00722f20(int param_1,int param_2,char param_3)



{

  int iVar1;

  void *pvVar2;

  int *piVar3;

  int *piVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  int *local_24;

  

  piVar3 = (int *)**(int **)(unaff_ESI + 0x314);

  if (piVar3 != *(int **)(unaff_ESI + 0x314)) {

    do {

      iVar1 = piVar3[2];

      if ((((*(int *)(iVar1 + 0x120) == param_1) && (*(int *)(iVar1 + 0x124) == param_2)) &&

          (*(char *)(iVar1 + 0x128) == param_3)) && (*(char *)(iVar1 + 0x10c) != '\0')) {

        piVar4 = (int *)*piVar3;

        if (piVar3 != *(int **)(unaff_ESI + 0x314)) {

          *(int **)piVar3[1] = piVar4;

          *(int *)(*piVar3 + 4) = piVar3[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar3);

        }

      }

      else {

        piVar4 = (int *)*piVar3;

      }

      piVar3 = piVar4;

    } while (piVar4 != *(int **)(unaff_ESI + 0x314));

  }

  piVar3 = *(int **)(unaff_ESI + 0x29c);

  if (piVar3 != *(int **)(unaff_ESI + 0x2a0)) {

    local_24 = piVar3 + 1;

    do {

      iVar1 = *piVar3;

      if (iVar1 == 0) {

LAB_0072307d:

        piVar3 = piVar3 + 1;

        local_24 = local_24 + 1;

      }

      else {

        if (((*(int *)(iVar1 + 0x128) != param_1) || (*(int *)(iVar1 + 300) != param_2)) ||

           ((char)*(uint32_t /* width from decompiler */ *)(iVar1 + 0x130) != param_3)) goto LAB_0072307d;

        FUN_00722aa0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x128),*(uint32_t /* width from decompiler */ *)(iVar1 + 300),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x130),0);

        if ((void *)*piVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)*piVar3);

        }

        memmove(piVar3,local_24,(*(int *)(unaff_ESI + 0x2a0) - (int)local_24 >> 2) * 4);

        *(int *)(unaff_ESI + 0x2a0) = *(int *)(unaff_ESI + 0x2a0) + -4;

      }

    } while (piVar3 != *(int **)(unaff_ESI + 0x2a0));

  }

  puVar5 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28c);

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x290)) {

    do {

      pvVar2 = (void *)*puVar5;

      if (pvVar2 != (void *)0x0) {

        if (((*(int *)((int)pvVar2 + 0x128) == param_1) && (*(int *)((int)pvVar2 + 300) == param_2))

           && ((char)*(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x130) == param_3)) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar2);

        }

      }

      puVar5 = puVar5 + 1;

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x290));

  }

  return;

}
