// =============================================================================
// FUN_00967b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00967b10
// Address:   0x00967b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00967b10 @ 0x00967b10
// Stable ID: aa_00967b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×14, return×2, for×1, while×1.
//  - Notable callees: FUN_00456500, FUN_00456600, FUN_00456960, FUN_00967b10.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00967b10(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  float10 fVar8;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad77a;

  local_c = ExceptionList;

  if ((param_1[7] & param_2[0x38]) == 0) {

    iVar5 = param_2[0x36] * 0x10 + 4 + param_1[2];

    iVar1 = param_2[0x36] * 4 + 0x44;

    iVar3 = *(int *)(iVar1 + param_1[2]);

    piVar2 = *(int **)(iVar5 + 4);

    if (*(char *)((int)param_2 + 0xd1) == '\0') {

      piVar6 = piVar2 + iVar3;

      piVar7 = piVar2;

    }

    else {

      piVar6 = *(int **)(iVar5 + 8);

      piVar2 = piVar2 + iVar3;

      piVar7 = piVar2;

    }

    for (; piVar2 != piVar6; piVar2 = piVar2 + 1) {

      if (*(int **)*piVar2 == param_2) {

        return;

      }

    }

    ExceptionList = &local_c;

    fVar8 = (float10)(**(code **)(*param_2 + 0x2c))(*param_1,param_1[1]);

    if ((float10)_DAT_00a13fe4 < fVar8) {

      iVar3 = FUN_00456600();

      uStack_4 = 0;

      if (iVar3 != 0) {

        FUN_00456500(iVar3,param_2[0x37]);

      }

      uStack_4 = 0xffffffff;

      while ((piVar7 != piVar6 &&

             ((float)fVar8 < *(float *)(*piVar7 + 4) || (float)fVar8 == *(float *)(*piVar7 + 4)))) {

        piVar7 = piVar7 + 1;

      }

      FUN_00456960(piVar7);

      if (*(int *)(iVar5 + 4) != 0) {

        iVar3 = *(int *)(iVar5 + 8);

        uVar4 = iVar3 - *(int *)(iVar5 + 4) >> 2;

        if (0x40 < uVar4) {

          piVar2 = *(int **)(iVar3 + -4);

          if (uVar4 != 0) {

            *(int *)(iVar5 + 8) = iVar3 + -4;

          }

          if (piVar2 != (int *)0x0) {

            piVar6 = (int *)*piVar2;

            if (piVar6 != (int *)0x0) {

              piVar7 = piVar6 + 1;

              *piVar7 = *piVar7 + -1;

              if (*piVar7 == 0) {

                (**(code **)(*piVar6 + 8))();

              }

            }

            *piVar2 = (int)DAT_00d21998;

            DAT_00d21998 = piVar2;

          }

        }

      }

      if (*(char *)((int)param_2 + 0xd1) == '\0') {

        if (*(int *)(iVar5 + 4) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2;

        }

        *(int *)(param_1[2] + iVar1) = *(int *)(param_1[2] + iVar1) + 1;

        if (iVar5 < *(int *)(iVar1 + param_1[2])) {

          *(int *)(iVar1 + param_1[2]) = iVar5;

        }

      }

    }

  }

  ExceptionList = local_c;

  return;

}
