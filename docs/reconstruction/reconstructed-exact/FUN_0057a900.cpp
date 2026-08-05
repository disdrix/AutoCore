// =============================================================================
// FUN_0057a900
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a900
// Address:   0x0057a900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057a900 @ 0x0057a900
// Stable ID: aa_0057a900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×20, while×5, do×3, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget×5, FUN_00404840, FUN_00418700, FUN_0057a250, FUN_0057a900.
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

void __thiscall

FUN_0057a900(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5,

            int *param_6)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  char cVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint64_t uVar11;

  

  uVar1 = param_6;

  if (((char)param_1[0x81] == '\0') &&

     (((cVar8 = (char)param_6, cVar8 != '\0' || ((char)param_3 == '\0')) ||

      (cVar2 = (**(code **)(*param_1 + 0x2c4))(param_2), cVar2 != '\0')))) {

    *(uint8_t *)(param_1 + 0x81) = 1;

    iVar9 = *(int *)(param_5 + 4);

    param_6 = param_1;

    iVar3 = FUN_00418700(iVar9,*(uint32_t /* width from decompiler */ *)(iVar9 + 4),&param_6);

    FUN_00404840(1);

    *(int *)(iVar9 + 4) = iVar3;

    **(int **)(iVar3 + 4) = iVar3;

    if (cVar8 == '\0') {

      if (*(char *)((int)param_1 + 0x1d1) == '\0') {

        puVar10 = (uint32_t /* width from decompiler */ *)param_1[0x76];

        if (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x77]) {

          do {

            piVar4 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar10,puVar10[1]);

            if (piVar4 != (int *)0x0) {

              (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,0);

            }

            puVar10 = puVar10 + 2;

          } while (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x77]);

        }

      }

      else if (((*(char *)((int)param_1 + 0x1d1) == '\x12') &&

               ((char *)param_1[0x96] != (char *)0x0)) && (*(char *)param_1[0x96] == '\0')) {

        iVar9 = 0;

        while( true ) {

          iVar3 = *(int *)(param_1[0x96] + 0x1c);

          if (iVar3 == 0) {

            iVar3 = 0;

          }

          else {

            iVar3 = *(int *)(param_1[0x96] + 0x20) - iVar3 >> 2;

          }

          if (iVar3 <= iVar9) break;

          uVar11 = FUN_0057a250(iVar9);

          piVar4 = (int *)CVOGReaction_ResolveObjectTarget(0,uVar11);

          if (piVar4 != (int *)0x0) {

            (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,0);

          }

          iVar9 = iVar9 + 1;

        }

      }

    }

    else {

      puVar10 = (uint32_t /* width from decompiler */ *)param_1[0x76];

      if (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x77]) {

        do {

          piVar4 = (int *)CVOGReaction_ResolveObjectTarget(uVar1,*puVar10,puVar10[1]);

          if (piVar4 != (int *)0x0) {

            (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,uVar1);

          }

          puVar10 = puVar10 + 2;

        } while (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x77]);

      }

      if (((*(char *)((int)param_1 + 0x1d1) == '\x12') && ((char *)param_1[0x96] != (char *)0x0)) &&

         (*(char *)param_1[0x96] == '\0')) {

        iVar9 = 0;

        while( true ) {

          iVar3 = param_1[0x96];

          if (*(int *)(iVar3 + 0x1c) == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x1c) >> 2;

          }

          if (iVar6 <= iVar9) break;

          if (*(int *)(iVar3 + 0x1c) == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x1c) >> 2;

          }

          if (iVar9 < iVar6) {

            puVar10 = *(uint32_t /* width from decompiler */ **)(*(int *)(iVar3 + 0x1c) + iVar9 * 4);

            uVar5 = *puVar10;

            uVar7 = puVar10[1];

          }

          else {

            uVar5 = 0xffffffff;

            uVar7 = 0xffffffff;

          }

          piVar4 = (int *)CVOGReaction_ResolveObjectTarget(uVar1,uVar5,uVar7);

          if (piVar4 != (int *)0x0) {

            (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,uVar1);

          }

          iVar9 = iVar9 + 1;

        }

      }

      cVar8 = *(char *)((int)param_1 + 0x1d1);

      if ((((cVar8 == '-') || (cVar8 == '4')) || (cVar8 == 'N')) &&

         (piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                                    (uVar1,param_1[0x97],param_1[0x97] >> 0x1f),

         piVar4 != (int *)0x0)) {

        (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,uVar1);

      }

    }

    puVar10 = (uint32_t /* width from decompiler */ *)param_1[0x7a];

    if (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x7b]) {

      do {

        piVar4 = (int *)CVOGReaction_ResolveObjectTarget(uVar1,*puVar10,puVar10[1]);

        if (piVar4 != (int *)0x0) {

          (**(code **)(*piVar4 + 0x130))(param_2,param_3,param_4,param_5,uVar1);

        }

        puVar10 = puVar10 + 2;

      } while (puVar10 != (uint32_t /* width from decompiler */ *)param_1[0x7b]);

    }

    *(uint8_t *)(param_1 + 0x81) = 0;

  }

  return;

}
