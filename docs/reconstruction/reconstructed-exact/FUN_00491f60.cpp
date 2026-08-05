// =============================================================================
// FUN_00491f60
// -----------------------------------------------------------------------------
// Stable ID: aa_00491f60
// Address:   0x00491f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491f60 @ 0x00491f60
// Stable ID: aa_00491f60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×9, while×3, for×2, do×2, return×2.
//  - Notable callees: ROUND×4, FUN_004507a0, FUN_00491f60, FUN_004cd330, FUN_0076c3c0, FUN_0076c500, thunk_FUN_0076c4d0.
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

void __thiscall FUN_00491f60(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int *piVar12;

  

  if (*(char *)(param_1 + 0x171) != '\0') {

    FUN_0076c500(10000);

    piVar12 = param_3;

    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x80);

    fVar2 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0);

    fVar3 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x7c);

    fVar4 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4);

    fVar5 = *(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x88);

    fVar6 = *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c4);

    for (iVar10 = (int)ROUND(*(float *)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe898) + 0x74) /

                             *(float *)(*(int *)(param_1 + 0xb8) + 0xe7c0));

        piVar8 = (int *)(int)ROUND(fVar3 / fVar4), iVar10 < (int)ROUND(fVar1 / fVar2);

        iVar10 = iVar10 + 1) {

      while (param_3 = piVar8, (int)param_3 < (int)ROUND(fVar5 / fVar6)) {

        iVar9 = FUN_004cd330(iVar10,param_3);

        if (((iVar9 != 0) &&

            (puVar11 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x14), puVar11 != (uint32_t /* width from decompiler */ *)0x0)) &&

           (*(int *)(iVar9 + 0x18) - (int)puVar11 >> 2 != 0)) {

          puVar7 = *(uint32_t /* width from decompiler */ **)(iVar9 + 0x18);

          for (; puVar11 != puVar7; puVar11 = puVar11 + 1) {

            if (0 < *piVar12) {

              thunk_FUN_0076c4d0();

              (**(code **)(*(int *)*puVar11 + 0x50))();

              iVar9 = FUN_0076c3c0();

              *piVar12 = *piVar12 - iVar9;

            }

            (**(code **)(*(int *)*puVar11 + 0x7c))(param_2);

          }

        }

        piVar8 = (int *)((int)param_3 + 1);

      }

    }

    if (*(char *)(*(int *)(param_1 + 0xb8) + 0x7d) == '\0') {

      piVar12 = *(int **)(param_1 + 0x164);

      if (piVar12 != *(int **)(param_1 + 0x168)) {

        do {

          if ((*(int **)(*piVar12 + 8) != (int *)0x0) &&

             (iVar10 = (**(code **)(**(int **)(*piVar12 + 8) + 0x68))

                                 (*(uint32_t /* width from decompiler */ *)(param_1 + 0xc0)), iVar10 != -1)) {

            (**(code **)(**(int **)(*piVar12 + 8) + 0x3c))(param_2);

          }

          piVar12 = piVar12 + 1;

        } while (piVar12 != *(int **)(param_1 + 0x168));

      }

    }

    else {

      piVar12 = *(int **)(param_1 + 0x164);

      if (piVar12 != *(int **)(param_1 + 0x168)) {

        do {

          if ((*(int **)(*piVar12 + 8) != (int *)0x0) &&

             (iVar10 = (**(code **)(**(int **)(*piVar12 + 8) + 0x68))

                                 (*(uint32_t /* width from decompiler */ *)(param_1 + 0xc0)), iVar10 != -1)) {

            iVar10 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

            param_2 = *(uint32_t /* width from decompiler */ *)(*piVar12 + 8);

            iVar9 = *(int *)(iVar10 + 0xac);

            if ((iVar9 == 0) ||

               ((uint)(*(int *)(iVar10 + 0xb4) - iVar9 >> 2) <=

                (uint)(*(int *)(iVar10 + 0xb0) - iVar9 >> 2))) {

              FUN_004507a0(*(uint32_t /* width from decompiler */ *)(iVar10 + 0xb0),1,&param_2);

            }

            else {

              puVar11 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0xb0);

              *puVar11 = param_2;

              *(uint32_t /* width from decompiler */ **)(iVar10 + 0xb0) = puVar11 + 1;

            }

          }

          piVar12 = piVar12 + 1;

        } while (piVar12 != *(int **)(param_1 + 0x168));

        return;

      }

    }

  }

  return;

}
