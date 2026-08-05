// =============================================================================
// FUN_008b7020
// -----------------------------------------------------------------------------
// Stable ID: aa_008b7020
// Address:   0x008b7020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b7020 @ 0x008b7020
// Stable ID: aa_008b7020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_007906a0, FUN_007fef20, FUN_008b5ea0, FUN_008b7020.
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

void __thiscall FUN_008b7020(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int *piVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iStack_3c;

  uint8_t local_38 [4];

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [4];

  uint8_t auStack_18 [20];

  

  uVar8 = 0;

  if (*(int *)(param_1 + 0x520) != 0) {

    do {

      if ((*(int *)(*(int *)(param_1 + 0x55c) + uVar8 * 4) != 0) &&

         (iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4) + 0x120))

                            (local_38,1,1), *(int *)(iVar2 + 4) < DAT_00d1d870)) {

        piVar4 = *(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4);

        uVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4) + 0x120))

                          (auStack_30,1,1);

        iVar2 = (**(code **)(*piVar4 + 0x140))(auStack_34,1);

        if ((DAT_00d1d870 < *(int *)(iStack_3c + 4) + *(int *)(iVar2 + 4)) &&

           (piVar4 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4) + 0x120))

                                      (auStack_20,1,1,uVar3), *piVar4 < DAT_00d1d86c)) {

          piVar4 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4) + 0x120))

                                    (auStack_18,1,1);

          piVar5 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x55c) + uVar8 * 4) + 0x140))

                                    (auStack_1c,1);

          if (DAT_00d1d86c < *piVar5 + *piVar4) {

            iVar2 = *(int *)(DAT_00d1ad2c + 8);

            if (iVar2 == 0) {

              uVar6 = 0;

            }

            else {

              uVar6 = *(int *)(DAT_00d1ad2c + 0xc) - iVar2 >> 2;

            }

            uVar7 = *(int *)(param_1 + 0x52c) + uVar8;

            if ((((uVar7 < uVar6) && (*(int *)(iVar2 + uVar7 * 4) != 0)) &&

                (iStack_3c = *(int *)(iVar2 + uVar7 * 4), iStack_3c != 0)) &&

               ((FUN_007fef20(0x38,1,0), DAT_00d1b950 != (int *)0x0 &&

                (cVar1 = (**(code **)(*DAT_00d1b950 + 0x3d8))(), cVar1 != '\0')))) {

              FUN_008b5ea0();

            }

          }

        }

      }

      uVar8 = uVar8 + 1;

    } while (uVar8 < *(uint *)(param_1 + 0x520));

  }

  FUN_007906a0(param_2,param_3);

  return;

}
