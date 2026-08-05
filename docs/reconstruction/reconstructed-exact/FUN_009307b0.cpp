// =============================================================================
// FUN_009307b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009307b0
// Address:   0x009307b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009307b0 @ 0x009307b0
// Stable ID: aa_009307b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×1, goto×1, while×1.
//  - Notable callees: FUN_00756be0×2, FUN_004406e0, FUN_009307b0.
//  - Return sites: 3.

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

void FUN_009307b0(int param_1,float param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  char cVar4;

  int iVar5;

  uint8_t uVar6;

  int *piVar7;

  int *piVar8;

  float fVar9;

  uint8_t local_10 [12];

  

  piVar1 = *(int **)(*(int *)(param_1 + 0xe04) + 0xe890);

  piVar7 = (int *)**(int **)(param_1 + 0xef4);

  if (piVar7 != *(int **)(param_1 + 0xef4)) {

    do {

      piVar8 = piVar7;

      if (((int *)piVar7[2] != (int *)0x0) && (iVar5 = *(int *)piVar7[2], iVar5 != 0)) {

        FUN_00756be0(iVar5);

        *(float *)(piVar7[2] + 0x28) = *(float *)(piVar7[2] + 0x28) - param_2;

        iVar5 = piVar7[2];

        *(float *)(iVar5 + 0x20) = *(float *)(iVar5 + 0x20) + *(float *)(iVar5 + 0x14) * param_2;

        *(float *)(iVar5 + 0x1c) = *(float *)(iVar5 + 0x1c) + *(float *)(iVar5 + 0x10) * param_2;

        *(float *)(iVar5 + 0x24) = *(float *)(iVar5 + 0x24) + *(float *)(iVar5 + 0x18) * param_2;

        cVar4 = (**(code **)(*piVar1 + 4))(piVar7[2] + 0x1c,local_10);

        if (cVar4 != '\0') {

          (**(code **)(**(int **)piVar7[2] + 0x118))(local_10);

          puVar2 = (uint32_t /* width from decompiler */ *)piVar7[2];

          if ((*(char *)(puVar2 + 0xc) != '\0') && (g_flZero < (float)puVar2[0xb])) {

            fVar9 = ((float)puVar2[10] / (float)puVar2[0xb]) * DAT_00aaa6f8;

            iVar5 = (**(code **)(*(int *)*puVar2 + 0x164))(1);

            uVar6 = (uint8_t)(int)fVar9;

            *(uint8_t *)(iVar5 + 3) = uVar6;

            iVar5 = (**(code **)(**(int **)piVar7[2] + 0x164))(0);

            *(uint8_t *)(iVar5 + 3) = uVar6;

            (**(code **)(**(int **)piVar7[2] + 0x34c))();

          }

          piVar8 = (int *)piVar7[2];

          if (((float)piVar8[10] <= 0.0) && (0.0 < (float)piVar8[0xb])) {

            if ((uint32_t /* width from decompiler */ *)*piVar8 != (uint32_t /* width from decompiler */ *)0x0) {

              (*(code *)**(uint32_t /* width from decompiler */ **)*piVar8)(1);

            }

            *(uint32_t /* width from decompiler */ *)piVar7[2] = 0;

            if ((void *)piVar7[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

              operator_delete((void *)piVar7[2]);

            }

            piVar7[2] = 0;

            piVar8 = (int *)*piVar7;

            if (piVar7 != *(int **)(param_1 + 0xef4)) {

              *(int **)piVar7[1] = piVar8;

              *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

              operator_delete(piVar7);

            }

            goto LAB_00930999;

          }

          iVar5 = *piVar8;

          uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xde8) + 0x2c);

          if (*(int *)(iVar5 + 0x88) != 0) {

            FUN_00756be0(iVar5);

          }

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0x88) = uVar3;

          FUN_004406e0();

        }

        piVar8 = (int *)*piVar7;

      }

LAB_00930999:

      piVar7 = piVar8;

    } while (piVar8 != *(int **)(param_1 + 0xef4));

  }

  return;

}
