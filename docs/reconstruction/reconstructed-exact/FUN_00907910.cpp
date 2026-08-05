// =============================================================================
// FUN_00907910
// -----------------------------------------------------------------------------
// Stable ID: aa_00907910
// Address:   0x00907910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907910 @ 0x00907910
// Stable ID: aa_00907910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_007a4e70, FUN_00907910.
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

void FUN_00907910(char param_1)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int unaff_ESI;

  

  iVar3 = *(int *)(unaff_ESI + 0x718);

  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x534) != -1)) && (*(int *)(iVar3 + 0x56c) != 0)) {

    if ((*(int *)(*(int *)(iVar3 + 0x56c) + *(int *)(iVar3 + 0x534) * 4) == 0) ||

       (((cVar2 = (**(code **)(**(int **)(*(int *)(iVar3 + 0x56c) + *(int *)(iVar3 + 0x534) * 4) +

                              0xd0))(), cVar2 != '\0' &&

         (cVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(unaff_ESI + 0x718) + 0x56c) +

                                         *(int *)(*(int *)(unaff_ESI + 0x718) + 0x534) * 4) + 0x3bc)

                  )(), cVar2 != '\0')) && (param_1 == '\0')))) {

      iVar3 = *(int *)(unaff_ESI + 0x718);

      if (((*(int *)(*(int *)(iVar3 + 0x56c) + *(int *)(iVar3 + 0x534) * 4) != 0) &&

          (cVar2 = (**(code **)(**(int **)(*(int *)(iVar3 + 0x56c) + *(int *)(iVar3 + 0x534) * 4) +

                               0xd0))(), cVar2 == '\x01')) &&

         ((iVar3 = *(int *)(*(int *)(unaff_ESI + 0x718) + 0x534),

          iVar1 = *(int *)(*(int *)(unaff_ESI + 0x718) + 0x570),

          iVar3 = FUN_007a4e70(*(uint32_t /* width from decompiler */ *)(iVar1 + iVar3 * 8),

                               *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar3 * 8)), iVar3 != 0 &&

          (DAT_00d1b6d8 != 0)))) {

        if ((*(int *)(unaff_ESI + 0x670) != 0) &&

           (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x670) + 0xd8))(), cVar2 == '\0')) {

          (**(code **)(**(int **)(unaff_ESI + 0x670) + 0xd4))(1);

          (**(code **)(**(int **)(unaff_ESI + 0x670) + 0x34c))();

        }

        if (*(int *)(unaff_ESI + 0x674) != 0) {

          if (*(int *)(iVar3 + 0x238) == 0 && *(int *)(iVar3 + 0x23c) == 0) {

            cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd8))();

            if (cVar2 != '\0') {

              (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd4))(0);

              (**(code **)(**(int **)(unaff_ESI + 0x674) + 0x34c))();

            }

          }

          else {

            cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd8))();

            if (cVar2 == '\0') {

              (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd4))(1);

              (**(code **)(**(int **)(unaff_ESI + 0x674) + 0x34c))();

            }

          }

        }

        if ((*(int *)(unaff_ESI + 0x66c) != 0) &&

           (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0xd8))(), cVar2 == '\0')) {

          (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0xd4))(1);

          (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0x34c))();

        }

      }

    }

    else {

      if ((*(int *)(unaff_ESI + 0x670) != 0) &&

         (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x670) + 0xd8))(), cVar2 != '\0')) {

        (**(code **)(**(int **)(unaff_ESI + 0x670) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x670) + 0x34c))();

      }

      if ((*(int *)(unaff_ESI + 0x674) != 0) &&

         (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd8))(), cVar2 != '\0')) {

        (**(code **)(**(int **)(unaff_ESI + 0x674) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x674) + 0x34c))();

      }

      if ((*(int *)(unaff_ESI + 0x66c) != 0) &&

         (cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0xd8))(), cVar2 != '\0')) {

        (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0xd4))(0);

        (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0x34c))();

        return;

      }

    }

  }

  return;

}
