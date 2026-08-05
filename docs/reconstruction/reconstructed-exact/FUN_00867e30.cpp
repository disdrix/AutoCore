// =============================================================================
// FUN_00867e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00867e30
// Address:   0x00867e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867e30 @ 0x00867e30
// Stable ID: aa_00867e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×15, do×3, while×3, return×1.
//  - Notable callees: FUN_00867c20×2, FUN_00867e30.
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

void __fastcall FUN_00867e30(int param_1)



{

  int iVar1;

  int *piVar2;

  short sVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int iStack_18;

  int iStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint8_t auStack_8 [4];

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar6 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0;

  if (*(int *)(param_1 + 0x560) != 0) {

    iVar4 = 0;

    iVar5 = 0;

    do {

      if (iVar6 != 4) {

        iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x214))();

        if (iVar1 == 0) {

          sVar3 = 0;

        }

        else {

          iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x214))();

          sVar3 = *(short *)(iVar6 + 0x1ac + iVar1);

        }

        iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x1d8))();

        if ((iVar1 == 0) ||

           (iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x1d8))(),

           *(char *)(iVar1 + 0x30c) == '\0')) {

          iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x1d4))();

        }

        else {

          iVar1 = (**(code **)(**(int **)(param_1 + 0x560) + 0x1d8))();

          iVar1 = *(int *)(iVar1 + 0x250);

        }

        if ((iVar1 != 0) && (*(int **)(iVar1 + 0x254) != (int *)0x0)) {

          iVar1 = (**(code **)(**(int **)(iVar1 + 0x254) + 0x38))();

          sVar3 = sVar3 + *(short *)(iVar1 + iVar6);

        }

        if (sVar3 < 1000) {

          if (0 < sVar3) {

            iVar5 = iVar5 + 1;

          }

        }

        else {

          iVar4 = iVar4 + 1;

        }

      }

      iVar6 = iVar6 + 2;

    } while (iVar6 < 0xc);

    if (0 < iVar4) {

      FUN_00867c20(1);

    }

    if (0 < iVar5) {

      FUN_00867c20(1);

    }

    piVar7 = (int *)(param_1 + 0x520);

    iStack_18 = 0;

    if (*(int **)(param_1 + 0x520) != (int *)0x0) {

      piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0x520) + 0x140))(auStack_8,1);

      iStack_18 = *piVar2;

    }

    uStack_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x548);

    iVar6 = *(int *)(param_1 + 0x544);

    iVar5 = 0;

    if (0 < *(int *)(param_1 + 0x540)) {

      do {

        if (*piVar7 != 0) {

          if ((iVar4 < 1) || (iVar5 <= iVar4)) {

            iStack_10 = 0;

          }

          else {

            iStack_10 = iStack_18 / 2;

          }

          iStack_10 = iVar6 - iStack_10;

          uStack_c = uStack_4;

          (**(code **)(*(int *)*piVar7 + 0x110))(&iStack_10);

        }

        iVar5 = iVar5 + 1;

        piVar7 = piVar7 + 1;

        iVar6 = iVar6 - iStack_18;

      } while (iVar5 < *(int *)(param_1 + 0x540));

    }

  }

  iVar6 = *(int *)(param_1 + 0x540);

  if (iVar6 < 8) {

    piVar7 = (int *)(param_1 + 0x520 + iVar6 * 4);

    iVar6 = 8 - iVar6;

    do {

      if (*piVar7 != 0) {

        (**(code **)(*(int *)*piVar7 + 4))(0);

      }

      piVar7 = piVar7 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  return;

}
