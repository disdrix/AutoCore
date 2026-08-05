// =============================================================================
// FUN_00867c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00867c20
// Address:   0x00867c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867c20 @ 0x00867c20
// Stable ID: aa_00867c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_00867a20×2, FUN_00867bd0×2, FUN_00867c20.
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

void FUN_00867c20(char param_1)



{

  char in_AL;

  int iVar1;

  int iVar2;

  short sVar3;

  int unaff_EDI;

  

  if ((*(int **)(unaff_EDI + 0x560) != (int *)0x0) &&

     (iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x214))(), iVar1 != 0)) {

    iVar1 = 0;

    do {

      if (iVar1 != 2) {

        iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x214))();

        sVar3 = *(short *)(iVar2 + 0x1ac + iVar1 * 2);

        iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x214))();

        if ((*(int *)(iVar2 + 0x250) == 0) ||

           (iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x214))(),

           *(char *)(iVar2 + 0x30c) == '\0')) {

          iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x1d4))();

        }

        else {

          iVar2 = (**(code **)(**(int **)(unaff_EDI + 0x560) + 0x214))();

          iVar2 = *(int *)(iVar2 + 0x250);

        }

        if ((iVar2 != 0) && (*(int **)(iVar2 + 0x254) != (int *)0x0)) {

          iVar2 = (**(code **)(**(int **)(iVar2 + 0x254) + 0x38))();

          sVar3 = sVar3 + *(short *)(iVar2 + iVar1 * 2);

        }

        if (in_AL == '\0') {

          if ((0 < sVar3) && (sVar3 < 1000)) goto LAB_00867d07;

        }

        else if (999 < sVar3) {

LAB_00867d07:

          if (*(int *)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4) != 0) {

            FUN_00867bd0(sVar3,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54c),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x550)

                         ,1);

            FUN_00867a20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4),sVar3,

                         0);

            (**(code **)(**(int **)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4) + 0x34c))()

            ;

          }

          *(int *)(unaff_EDI + 0x540) = *(int *)(unaff_EDI + 0x540) + 1;

        }

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < 6);

    if ((param_1 != '\0') && (*(int *)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4) != 0)) {

      iVar1 = (-(uint)(in_AL != '\0') & 999) + 1;

      FUN_00867bd0(iVar1,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54c),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x550),0);

      FUN_00867a20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4),iVar1,0);

      (**(code **)(**(int **)(unaff_EDI + 0x520 + *(int *)(unaff_EDI + 0x540) * 4) + 0x34c))();

    }

    *(int *)(unaff_EDI + 0x540) = *(int *)(unaff_EDI + 0x540) + 1;

  }

  return;

}
