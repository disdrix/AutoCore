// =============================================================================
// FUN_0093ab90
// -----------------------------------------------------------------------------
// Stable ID: aa_0093ab90
// Address:   0x0093ab90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093ab90 @ 0x0093ab90
// Stable ID: aa_0093ab90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~231 non-empty decompiler lines.
//  - Control keywords: if×36, goto×6, return×4, do×2, while×2, for×1.
//  - Notable callees: FUN_00861c10×20, FUN_007fde80×5, FUN_00861bb0×5, FUN_00861be0×5, FUN_00861d20×5, FUN_00405ae0×2, FUN_008f8200, FUN_0093ab90.
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

void FUN_0093ab90(int param_1)



{

  bool bVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  bool bVar6;

  char cVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int local_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  iVar12 = *(int *)(param_1 + 0xe04);

  bVar5 = true;

  bVar1 = true;

  bVar2 = true;

  bVar3 = true;

  bVar4 = true;

  bVar6 = true;

  if (iVar12 == 0) {

    return;

  }

  if (*(int *)(iVar12 + 0xe8cc) == 0) {

    return;

  }

  local_1c = (*(int *)(iVar12 + 0xe8d0) - *(int *)(iVar12 + 0xe8cc)) / 0x98;

  if (local_1c == 0) {

    return;

  }

  if ((((*(int **)(param_1 + 0xf40) == (int *)0x0) ||

       (iVar12 = *(int *)(param_1 + 0xf38), **(int **)(param_1 + 0xf40) != iVar12)) || (iVar12 == 0)

      ) || ((*(int *)(iVar12 + 0xc78) == 0 ||

            (cVar7 = (**(code **)(**(int **)(iVar12 + 0xc78) + 0x3d8))(), cVar7 == '\0')))) {

    if ((*(int *)(param_1 + 0x1124) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

      bVar1 = false;

    }

    if ((*(int *)(param_1 + 0x1128) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

      bVar2 = false;

    }

    if ((*(int *)(param_1 + 0x112c) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

      bVar3 = false;

    }

    if ((*(int *)(param_1 + 0x1130) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

      bVar4 = false;

    }

    if ((*(int *)(param_1 + 0x1134) == 0) || (cVar7 = FUN_00861c10(), cVar7 == '\0'))

    goto LAB_0093acbc;

  }

  else {

    bVar1 = false;

    bVar2 = false;

    bVar3 = false;

    bVar4 = false;

  }

  bVar5 = false;

  bVar6 = false;

LAB_0093acbc:

  iVar12 = *(int *)(param_1 + 0xe04);

  if ((*(int *)(iVar12 + 0xe8cc) != 0) &&

     (1 < (uint)((*(int *)(iVar12 + 0xe8d0) - *(int *)(iVar12 + 0xe8cc)) / 0x98))) {

    iVar10 = *(int *)(iVar12 + 0xe8cc);

    iVar12 = *(int *)(iVar12 + 0xe8d0);

    if (iVar10 != iVar12) {

      do {

        if ((*(uint *)(iVar10 + 0x90) & *(uint *)(iVar10 + 0x94)) == 0xffffffff) {

          iVar11 = iVar10 + 0x98;

        }

        else {

          iVar11 = iVar10 + 0x98;

          for (iVar8 = iVar11; local_1c = iVar11, iVar8 != iVar12; iVar8 = iVar8 + 0x98) {

            if ((*(int *)(iVar8 + 0x90) == *(int *)(iVar10 + 0x90)) &&

               (*(int *)(iVar8 + 0x94) == *(int *)(iVar10 + 0x94))) {

              piVar9 = (int *)FUN_00405ae0(&iStack_18,iVar10);

              iVar11 = *piVar9;

              break;

            }

          }

        }

        iVar12 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe8d0);

        iVar10 = iVar11;

        bVar5 = bVar6;

      } while (iVar11 != iVar12);

    }

  }

  iVar12 = *(int *)(*(int *)(param_1 + 0xe04) + 0xe8cc);

  if (iVar12 != *(int *)(*(int *)(param_1 + 0xe04) + 0xe8d0)) {

    do {

      iVar10 = *(int *)(iVar12 + 0x8c);

      if (iVar10 == 0) {

        if ((bVar1) ||

           (((((*(uint *)(iVar12 + 0x90) & *(uint *)(iVar12 + 0x94)) != 0xffffffff &&

              (*(int *)(param_1 + 0x1124) != 0)) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) &&

            ((*(int *)(*(int *)(param_1 + 0x1124) + 0x518) == *(int *)(iVar12 + 0x90) &&

             (*(int *)(*(int *)(param_1 + 0x1124) + 0x51c) == *(int *)(iVar12 + 0x94))))))) {

          FUN_007fde80(iVar12,iVar12 + 0x80,*(uint32_t /* width from decompiler */ *)(iVar12 + 0x84),

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0x88),0);

          if ((*(int *)(param_1 + 0x1124) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

            iVar10 = *(int *)(param_1 + 0x1124);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x518) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x90);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x51c) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x94);

            bVar1 = false;

          }

          piVar9 = &iStack_18;

          goto LAB_0093b370;

        }

        if (((*(int *)(param_1 + 0x1124) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) &&

           ((cVar7 = FUN_00861bb0(), cVar7 == '\0' && (cVar7 = FUN_00861be0(), cVar7 == '\0')))) {

          FUN_00861d20(0x3f000000);

        }

      }

      else {

        if (iVar10 == 2) {

          if ((!bVar2) &&

             (((((*(uint *)(iVar12 + 0x90) & *(uint *)(iVar12 + 0x94)) == 0xffffffff ||

                (*(int *)(param_1 + 0x1128) == 0)) || (cVar7 = FUN_00861c10(), cVar7 == '\0')) ||

              ((*(int *)(*(int *)(param_1 + 0x1128) + 0x518) != *(int *)(iVar12 + 0x90) ||

               (*(int *)(*(int *)(param_1 + 0x1128) + 0x51c) != *(int *)(iVar12 + 0x94))))))) {

            if (((*(int *)(param_1 + 0x1128) != 0) &&

                ((cVar7 = FUN_00861c10(), cVar7 != '\0' && (cVar7 = FUN_00861bb0(), cVar7 == '\0')))

                ) && (cVar7 = FUN_00861be0(), cVar7 == '\0')) {

              FUN_00861d20(0x3f000000);

            }

            goto LAB_0093b37d;

          }

          FUN_007fde80(iVar12,iVar12 + 0x80,*(uint32_t /* width from decompiler */ *)(iVar12 + 0x84),

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0x88),2);

          if ((*(int *)(param_1 + 0x1128) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

            iVar10 = *(int *)(param_1 + 0x1128);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x518) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x90);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x51c) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x94);

            bVar2 = false;

          }

          piVar9 = &local_1c;

        }

        else if (iVar10 == 3) {

          if ((!bVar3) &&

             (((((*(uint *)(iVar12 + 0x90) & *(uint *)(iVar12 + 0x94)) == 0xffffffff ||

                (*(int *)(param_1 + 0x112c) == 0)) || (cVar7 = FUN_00861c10(), cVar7 == '\0')) ||

              ((*(int *)(*(int *)(param_1 + 0x112c) + 0x518) != *(int *)(iVar12 + 0x90) ||

               (*(int *)(*(int *)(param_1 + 0x112c) + 0x51c) != *(int *)(iVar12 + 0x94))))))) {

            if ((*(int *)(param_1 + 0x112c) != 0) &&

               (((cVar7 = FUN_00861c10(), cVar7 != '\0' && (cVar7 = FUN_00861bb0(), cVar7 == '\0'))

                && (cVar7 = FUN_00861be0(), cVar7 == '\0')))) {

              FUN_00861d20(0x3f000000);

            }

            goto LAB_0093b37d;

          }

          FUN_007fde80(iVar12,iVar12 + 0x80,*(uint32_t /* width from decompiler */ *)(iVar12 + 0x84),

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0x88),3);

          if ((*(int *)(param_1 + 0x112c) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

            iVar10 = *(int *)(param_1 + 0x112c);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x518) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x90);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x51c) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x94);

            bVar3 = false;

          }

          piVar9 = &iStack_14;

        }

        else if (iVar10 == 4) {

          if ((!bVar4) &&

             (((((*(uint *)(iVar12 + 0x90) & *(uint *)(iVar12 + 0x94)) == 0xffffffff ||

                (*(int *)(param_1 + 0x1130) == 0)) || (cVar7 = FUN_00861c10(), cVar7 == '\0')) ||

              ((*(int *)(*(int *)(param_1 + 0x1130) + 0x518) != *(int *)(iVar12 + 0x90) ||

               (*(int *)(*(int *)(param_1 + 0x1130) + 0x51c) != *(int *)(iVar12 + 0x94))))))) {

            if (((*(int *)(param_1 + 0x1130) != 0) &&

                ((cVar7 = FUN_00861c10(), cVar7 != '\0' && (cVar7 = FUN_00861bb0(), cVar7 == '\0')))

                ) && (cVar7 = FUN_00861be0(), cVar7 == '\0')) {

              FUN_00861d20(0x3f000000);

            }

            goto LAB_0093b37d;

          }

          FUN_007fde80(iVar12,iVar12 + 0x80,*(uint32_t /* width from decompiler */ *)(iVar12 + 0x84),

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0x88),4);

          if ((*(int *)(param_1 + 0x1130) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

            iVar10 = *(int *)(param_1 + 0x1130);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x518) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x90);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x51c) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x94);

            bVar4 = false;

          }

          piVar9 = &iStack_10;

        }

        else if (iVar10 == 5) {

          if ((!bVar5) &&

             (((((*(uint *)(iVar12 + 0x90) & *(uint *)(iVar12 + 0x94)) == 0xffffffff ||

                (*(int *)(param_1 + 0x1134) == 0)) || (cVar7 = FUN_00861c10(), cVar7 == '\0')) ||

              ((*(int *)(*(int *)(param_1 + 0x1134) + 0x518) != *(int *)(iVar12 + 0x90) ||

               (*(int *)(*(int *)(param_1 + 0x1134) + 0x51c) != *(int *)(iVar12 + 0x94))))))) {

            if (((*(int *)(param_1 + 0x1134) != 0) &&

                ((cVar7 = FUN_00861c10(), cVar7 != '\0' && (cVar7 = FUN_00861bb0(), cVar7 == '\0')))

                ) && (cVar7 = FUN_00861be0(), cVar7 == '\0')) {

              FUN_00861d20(0x3f000000);

            }

            goto LAB_0093b37d;

          }

          FUN_007fde80(iVar12,iVar12 + 0x80,*(uint32_t /* width from decompiler */ *)(iVar12 + 0x84),

                       *(uint32_t /* width from decompiler */ *)(iVar12 + 0x88),5);

          if ((*(int *)(param_1 + 0x1134) != 0) && (cVar7 = FUN_00861c10(), cVar7 != '\0')) {

            iVar10 = *(int *)(param_1 + 0x1134);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x518) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x90);

            *(uint32_t /* width from decompiler */ *)(iVar10 + 0x51c) = *(uint32_t /* width from decompiler */ *)(iVar12 + 0x94);

            bVar5 = false;

          }

          piVar9 = &iStack_c;

        }

        else if (iVar10 == 1) {

          if (*(int *)(param_1 + 0x109c) != 0) {

            FUN_008f8200(*(int *)(param_1 + 0x109c),6,&DAT_00a1419b,iVar12,0);

          }

          piVar9 = &iStack_8;

        }

        else {

          piVar9 = &iStack_4;

        }

LAB_0093b370:

        piVar9 = (int *)FUN_00405ae0(piVar9,iVar12);

        iVar12 = *piVar9 + -0x98;

      }

LAB_0093b37d:

      iVar12 = iVar12 + 0x98;

    } while (iVar12 != *(int *)(*(int *)(param_1 + 0xe04) + 0xe8d0));

  }

  return;

}
