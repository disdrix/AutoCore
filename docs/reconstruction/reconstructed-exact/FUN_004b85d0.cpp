// =============================================================================
// FUN_004b85d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b85d0
// Address:   0x004b85d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b85d0 @ 0x004b85d0
// Stable ID: aa_004b85d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×17, return×11, while×6, do×4.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_004b85d0, FUN_004ba770, FUN_005b85e0, FUN_005be2f0, FUN_005be310, FUN_00723b20.
//  - Return sites: 11.

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

void __fastcall FUN_004b85d0(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int *piVar4;

  int *piVar5;

  uint uVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  void *pvVar10;

  uint32_t /* width from decompiler */ uVar11;

  

  piVar7 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar7 != *(int **)(param_1 + 0x1e0)) {

    do {

      FUN_005be310(piVar7[2]);

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)*(int *)(param_1 + 0x1e0));

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1e0);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0x1e0) + 4) = *(int *)(param_1 + 0x1e0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4) = 0;

  if (pvVar3 != *(void **)(param_1 + 0x1e0)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  piVar7 = (int *)**(int **)(param_1 + 0x204);

  if (piVar7 != *(int **)(param_1 + 0x204)) {

    do {

      FUN_005be2f0(piVar7[2]);

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)*(int *)(param_1 + 0x204));

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x204);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0x204) + 4) = *(int *)(param_1 + 0x204);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x208) = 0;

  if (pvVar3 != *(void **)(param_1 + 0x204)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  piVar7 = (int *)**(int **)(param_1 + 0x210);

  if (piVar7 != *(int **)(param_1 + 0x210)) {

    do {

      pvVar3 = (void *)piVar7[2];

      if (pvVar3 != (void *)0x0) {

        FUN_005b85e0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)*(int *)(param_1 + 0x210));

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x210);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0x210) + 4) = *(int *)(param_1 + 0x210);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x214) = 0;

  if (pvVar3 != *(void **)(param_1 + 0x210)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  piVar7 = (int *)**(int **)(param_1 + 0x1ec);

  if (piVar7 != *(int **)(param_1 + 0x1ec)) {

    pvVar3 = (void *)piVar7[2];

    if (*(char *)((int)pvVar3 + 0x10b) != '\0') {

      uVar6 = (uint)*(byte *)((int)pvVar3 + 0x128);

      uVar9 = *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x124);

      uVar8 = *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x120);

      uVar11 = 0;

      pvVar10 = pvVar3;

      Client_GetMissionCompleteAudioTable(uVar8,uVar9,uVar6,pvVar3,0);

      FUN_00723b20(uVar8,uVar9,uVar6,pvVar10,uVar11);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1ec);

  pvVar3 = (void *)*puVar2;

  *puVar2 = puVar2;

  *(int *)(*(int *)(param_1 + 0x1ec) + 4) = *(int *)(param_1 + 0x1ec);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f0) = 0;

  if (pvVar3 == *(void **)(param_1 + 0x1ec)) {

    piVar7 = (int *)**(int **)(param_1 + 0x1f8);

    if (piVar7 != *(int **)(param_1 + 0x1f8)) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)piVar7[2]);

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1f8);

    pvVar3 = (void *)*puVar2;

    *puVar2 = puVar2;

    *(int *)(*(int *)(param_1 + 0x1f8) + 4) = *(int *)(param_1 + 0x1f8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc) = 0;

    if (pvVar3 != *(void **)(param_1 + 0x1f8)) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    piVar7 = (int *)**(int **)(param_1 + 0x228);

    if (piVar7 != *(int **)(param_1 + 0x228)) {

      do {

        if ((void *)piVar7[4] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)piVar7[4]);

        }

        if (*(char *)((int)piVar7 + 0x15) == '\0') {

          piVar4 = (int *)piVar7[2];

          if (*(char *)((int)piVar4 + 0x15) == '\0') {

            cVar1 = *(char *)(*piVar4 + 0x15);

            piVar7 = piVar4;

            piVar4 = (int *)*piVar4;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar4 + 0x15);

              piVar7 = piVar4;

              piVar4 = (int *)*piVar4;

            }

          }

          else {

            cVar1 = *(char *)(piVar7[1] + 0x15);

            piVar5 = (int *)piVar7[1];

            piVar4 = piVar7;

            while ((piVar7 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar7[2]))) {

              cVar1 = *(char *)(piVar7[1] + 0x15);

              piVar5 = (int *)piVar7[1];

              piVar4 = piVar7;

            }

          }

        }

      } while (piVar7 != *(int **)(param_1 + 0x228));

    }

    pvVar3 = *(void **)(*(int *)(param_1 + 0x228) + 4);

    if (*(char *)((int)pvVar3 + 0x15) != '\0') {

      *(int *)(*(int *)(param_1 + 0x228) + 4) = *(int *)(param_1 + 0x228);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x22c) = 0;

      *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x228) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x228);

      *(int *)(*(int *)(param_1 + 0x228) + 8) = *(int *)(param_1 + 0x228);

      return;

    }

    FUN_004ba770(*(uint32_t /* width from decompiler */ *)((int)pvVar3 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar3);

}
