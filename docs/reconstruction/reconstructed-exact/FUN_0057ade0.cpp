// =============================================================================
// FUN_0057ade0
// -----------------------------------------------------------------------------
// Stable ID: aa_0057ade0
// Address:   0x0057ade0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057ade0 @ 0x0057ade0
// Stable ID: aa_0057ade0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×17, while×4, return×4, do×3.
//  - Notable callees: FUN_00402d10×5, FUN_004022a0×2, CVOGReaction_ResolveObjectTarget, FUN_00404840, FUN_0040c700, FUN_00418700, FUN_004294f0, FUN_00574760.
//  - Return sites: 4.

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

void __thiscall FUN_0057ade0(int *param_1,int *param_2,int param_3,int param_4)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  if ((char)param_1[0x7d] == '\0') {

    if (*(char *)((int)param_1 + 0x1f6) == '\0') {

      if (*(char *)((int)param_1 + 0x1f5) == '\0') {

        puVar7 = (uint32_t /* width from decompiler */ *)param_1[0x77];

        puVar6 = (uint32_t /* width from decompiler */ *)param_1[0x76];

        local_4 = puVar7;

        if (puVar6 != puVar7) {

          do {

            piVar5 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar6,puVar6[1]);

            local_8 = piVar5;

            if (piVar5 != (int *)0x0) {

              if (*(int *)(piVar5[0x2a] + 0x38) == 0x3c) {

                __RTDynamicCast(piVar5,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGMapModulePlacement::RTTI_Type_Descriptor,0);

              }

              else if (((char)param_4 == '\0') || (*(int *)(piVar5[0x2a] + 0x38) != 0x36)) {

                cVar1 = (**(code **)(*param_1 + 0x2c4))(piVar5);

                if (cVar1 != '\0') {

                  FUN_00402d10(&local_8);

                }

              }

              else {

                (**(code **)(*piVar5 + 0x1ec))();

                FUN_004294f0();

                local_8 = (int *)0x0;

                iVar3 = FUN_004022a0(&local_8,&param_2);

                while (iVar3 == 0) {

                  if ((param_2 != (int *)0x0) &&

                     (cVar1 = (**(code **)(*param_1 + 0x2c4))(piVar5), cVar1 != '\0')) {

                    FUN_00402d10(&param_2);

                  }

                  iVar3 = FUN_004022a0(&local_8,&param_2);

                }

                FUN_0040c700();

                puVar7 = local_4;

              }

            }

            puVar6 = puVar6 + 2;

          } while (puVar6 != puVar7);

        }

      }

      else if ((param_2 != (int *)0x0) &&

              (cVar1 = (**(code **)(*param_1 + 0x2c4))(param_2), cVar1 != '\0')) {

        FUN_00402d10(&stack0x00000000);

        return;

      }

    }

    else if ((param_2 != (int *)0x0) && (iVar3 = (**(code **)(*param_2 + 0x210))(0), iVar3 != 0)) {

      cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

      if (cVar1 != '\0') {

        param_2 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

        FUN_00402d10(&param_2);

      }

      if (*(int *)(iVar3 + 0xcb0) != 0) {

        iVar2 = 0;

        do {

          iVar4 = FUN_00574760(iVar2);

          if (((iVar4 != 0) && (iVar3 != iVar4)) &&

             (cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4)

             , cVar1 != '\0')) {

            param_2 = (int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

            FUN_00402d10(&param_2);

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < 4);

        return;

      }

    }

  }

  else {

    piVar5 = *(int **)(param_1[0x29] + 0xe75c);

    if (piVar5 != *(int **)(param_1[0x29] + 0xe760)) {

      do {

        iVar3 = *piVar5;

        if ((iVar3 != 0) &&

           (cVar1 = (**(code **)(*param_1 + 0x2c4))(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3),

           cVar1 != '\0')) {

          param_4 = *piVar5;

          if (param_4 == 0) {

            param_4 = 0;

          }

          else {

            param_4 = *(int *)(*(int *)(param_4 + 4) + 4) + 4 + param_4;

          }

          iVar3 = *(int *)(param_3 + 4);

          iVar2 = FUN_00418700(iVar3,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),&param_4);

          FUN_00404840(1);

          *(int *)(iVar3 + 4) = iVar2;

          **(int **)(iVar2 + 4) = iVar2;

        }

        piVar5 = piVar5 + 1;

      } while (piVar5 != *(int **)(param_1[0x29] + 0xe760));

      return;

    }

  }

  return;

}
