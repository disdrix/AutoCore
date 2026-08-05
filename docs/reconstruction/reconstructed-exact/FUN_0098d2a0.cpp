// =============================================================================
// FUN_0098d2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d2a0
// Address:   0x0098d2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d2a0 @ 0x0098d2a0
// Stable ID: aa_0098d2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×2.
//  - Notable callees: FUN_0074f360×2, FUN_0074fca0×2, FUN_0074dfd0, FUN_0074f200, FUN_0074f320, FUN_0074fba0, FUN_0098d2a0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0098d2a0(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  char cVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  int local_18;

  int local_14;

  int local_10;

  

  if (((*(int *)(param_1 + 0xc) != 0) &&

      (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2 != 0)) &&

     (cVar7 = FUN_0074dfd0(DAT_00d1a54c), cVar7 != '\0')) {

    FUN_0074fca0(2);

    FUN_0074f320(0);

    local_14 = 0;

    local_10 = 0;

    local_18 = 0;

    piVar9 = *(int **)(param_1 + 0xc);

    piVar2 = *(int **)(param_1 + 0x10);

    if (piVar9 != piVar2) {

      do {

        puVar3 = (uint32_t /* width from decompiler */ *)*piVar9;

        piVar4 = (int *)*puVar3;

        iVar8 = puVar3[1];

        iVar5 = *(int *)(iVar8 + 8);

        (**(code **)(*piVar4 + 0xc))(puVar3);

        if ((iVar5 != local_14) || (*(int *)(*piVar9 + 8) != local_18)) {

          local_18 = *(int *)(*piVar9 + 8);

          FUN_0074fba0(local_18);

          FUN_0074fca0(2);

          iVar10 = *(int *)(iVar5 + 0x28);

          if (-1 < *(int *)(&DAT_00afe00c + iVar10 * 0xc)) {

            (**(code **)(**(int **)(iVar5 + 0xc) + 0x108))(*(int **)(iVar5 + 0xc));

          }

          (**(code **)(**(int **)(iVar5 + 0xc) + 0x100))(*(int **)(iVar5 + 0xc),0);

          *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar10 * 0xc) = 0;

          local_14 = iVar5;

        }

        if (DAT_00d1f614 != 0) {

          piVar1 = (int *)(DAT_00d1f614 + 0xd8 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

          *piVar1 = *piVar1 + 1;

        }

        if ((local_10 != iVar8) &&

           (FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar8 + 0xc)), local_10 = iVar8, DAT_00d1f614 != 0)) {

          piVar1 = (int *)(DAT_00d1f614 + 0xd4 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

          *piVar1 = *piVar1 + 1;

        }

        if (*(int *)(local_18 + 200) == 0) {

          iVar8 = 0;

        }

        else {

          iVar8 = (*(int *)(local_18 + 0xcc) - *(int *)(local_18 + 200)) / 0x24;

        }

        iVar10 = 0;

        if (0 < iVar8) {

          do {

            if (0 < iVar10) {

              iVar6 = *(int *)(iVar5 + 0x28);

              if (-1 < *(int *)(&DAT_00afe00c + iVar6 * 0xc)) {

                (**(code **)(**(int **)(iVar5 + 0xc) + 0x108))(*(int **)(iVar5 + 0xc));

              }

              (**(code **)(**(int **)(iVar5 + 0xc) + 0x100))(*(int **)(iVar5 + 0xc),iVar10);

              *(int *)(&DAT_00afe00c + iVar6 * 0xc) = iVar10;

            }

            (**(code **)(*piVar4 + 8))(*piVar9);

            iVar10 = iVar10 + 1;

          } while (iVar10 < iVar8);

        }

        if (1 < iVar8) {

          iVar8 = *(int *)(iVar5 + 0x28);

          if (-1 < *(int *)(&DAT_00afe00c + iVar8 * 0xc)) {

            (**(code **)(**(int **)(iVar5 + 0xc) + 0x108))(*(int **)(iVar5 + 0xc));

          }

          (**(code **)(**(int **)(iVar5 + 0xc) + 0x100))(*(int **)(iVar5 + 0xc),0);

          *(uint32_t /* width from decompiler */ *)(&DAT_00afe00c + iVar8 * 0xc) = 0;

        }

        piVar9 = piVar9 + 1;

      } while (piVar9 != piVar2);

      if (local_14 != 0) {

        FUN_0074f360();

      }

    }

    FUN_0074f360();

    return 0;

  }

  return 1;

}
