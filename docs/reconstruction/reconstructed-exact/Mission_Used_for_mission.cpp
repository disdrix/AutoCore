// READABILITY (auto CF):
//  - Body size: ~207 non-empty decompiler lines.
//  - Control keywords: if×21, for×6, while×5, do×3, return×2, goto×1.
//  - Notable callees: FUN_007a4480×4, FUN_007a6de0×4, sprintf×3, FUN_007a69d0×2, FUN_00410a20, FUN_00513e70, FUN_0085d970, FUN_008bd580.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "Used for mission".
//  - Return sites: 2.

// =============================================================================
// Mission_Used_for_mission
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd580
// Address:   0x008bd580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Used for mission"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Used_for_mission(int param_1,int param_2,int *param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  int iVar6;

  uint uVar7;

  char *pcVar8;

  int iVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char *pcVar12;

  int *piVar13;

  TypeDescriptor *pTVar14;

  int iStack_130;

  uint32_t /* width from decompiler */ local_12c;

  int iStack_128;

  int iStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint8_t auStack_11c [2];

  uint8_t auStack_11a [6];

  uint32_t /* width from decompiler */ uStack_114;

  char acStack_110 [256];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = -1;

  puStack_8 = &LAB_009b03ee;

  local_c = ExceptionList;

  iVar9 = 0;

  if (param_3 != (int *)0x0) {

    ExceptionList = &local_c;

    local_12c = FUN_007a69d0();

    if (*(int *)(param_1 + 0x55c + param_2 * 4) != 0) {

      (**(code **)(**(int **)(param_1 + 0x55c + param_2 * 4) + 4))(1);

    }

    if (*(int *)(param_1 + 0x58c + param_2 * 4) != 0) {

      (**(code **)(**(int **)(param_1 + 0x58c + param_2 * 4) + 4))(1);

    }

    if (*(int *)(param_1 + 0x56c + param_2 * 4) != 0) {

      (**(code **)(**(int **)(param_1 + 0x56c + param_2 * 4) + 0x1d8))(0,1,1);

      iStack_128 = 0;

      iStack_124 = 0;

      uStack_120 = 0;

      uStack_10 = 0;

      _auStack_11c = (void *)((uint)_auStack_11c & 0xffff0000);

      puVar11 = (uint32_t /* width from decompiler */ *)(auStack_11c + 2);

      for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar11 = 0;

        puVar11 = puVar11 + 1;

      }

      *(uint16_t *)puVar11 = 0;

      iVar6 = *(int *)(DAT_00d1b6d8 + 0x548);

      if (*(char *)(iVar6 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar6 + 0x1d) = 1;

      while( true ) {

        iVar6 = *(int *)(DAT_00d1b6d8 + 0x548);

        if (*(char *)(iVar6 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar9 == 0) {

          iVar9 = *(int *)(iVar6 + 0x14);

          if (iVar9 == 0) {

            iStack_130 = 0;

          }

          else {

            iStack_130 = *(int *)(iVar9 + 8);

          }

        }

        else {

          iVar9 = *(int *)(iVar9 + 0x14);

          if (iVar9 == 0) {

            iStack_130 = 0;

          }

          else {

            iStack_130 = *(int *)(iVar9 + 8);

          }

        }

        if (iStack_130 == 0) break;

        FUN_00410a20();

        iVar6 = 0;

        while( true ) {

          if (iStack_128 == 0) {

            iVar2 = 0;

          }

          else {

            iVar2 = iStack_124 - iStack_128 >> 2;

          }

          if (iVar2 <= iVar6) break;

          piVar13 = *(int **)(iStack_128 + iVar6 * 4);

          iVar2 = (**(code **)(*piVar13 + 0x50))();

          if (iVar2 == 2) {

            pTVar14 = &CVOGObjectiveRequirement_Collect::RTTI_Type_Descriptor;

LAB_008bd735:

            iVar2 = __RTDynamicCast(piVar13,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                    pTVar14,0);

            if ((*(int *)(iVar2 + 0x10) == *(int *)(*(int *)(iStack_4 + 0xa8) + 0x34)) &&

               (*(int *)(iStack_130 + 0x14c) != 0)) {

              uVar3 = FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(*(int *)(iStack_130 + 0x14c) + 0x14c),0xffffffff)

              ;

              uVar4 = FUN_007a6de0("Used for mission",0xffffffff);

              sprintf(auStack_11c,"%s: %s",uVar4,uVar3);

              (**(code **)(**(int **)(param_1 + 0x56c + param_2 * 4) + 0x1d8))(auStack_11c,1,1);

            }

          }

          else if (iVar2 == 3) {

            pTVar14 = &CVOGObjectiveRequirement_Deliver::RTTI_Type_Descriptor;

            goto LAB_008bd735;

          }

          iVar6 = iVar6 + 1;

        }

      }

      *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0x1d) = 0;

      (**(code **)(**(int **)(param_1 + 0x56c + param_2 * 4) + 0xcc))(1);

      (**(code **)(**(int **)(param_1 + 0x56c + param_2 * 4) + 0x34c))();

      iStack_4 = -1;

      if (_auStack_11c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(_auStack_11c);

      }

      _auStack_11c = (void *)0x0;

      auStack_11a._2_4_ = 0;

      uStack_114 = 0;

    }

    if (*(int *)(param_1 + 0x57c + param_2 * 4) != 0) {

      uVar4 = 0xffffffff;

      uVar3 = (**(code **)(*param_3 + 0x15c))(0xffffffff);

      pcVar5 = (char *)FUN_007a6de0(uVar3,uVar4);

      pcVar8 = acStack_110;

      do {

        cVar1 = *pcVar5;

        *pcVar8 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      if (((*(byte *)(*(int *)(param_3[0x2a] + 0x3c) + 0x3f2) & 0x80) != 0) &&

         (iVar9 = (**(code **)(*param_3 + 0x234))

                            (*(uint32_t /* width from decompiler */ *)(*(int *)(param_3[0x2a] + 0x3c) + 0x3bc)), iVar9 != 0))

      {

        pcVar5 = (char *)FUN_007a6de0(" (Usable)",0xffffffff);

        pcVar8 = pcVar5;

        do {

          cVar1 = *pcVar8;

          pcVar8 = pcVar8 + 1;

        } while (cVar1 != '\0');

        pcVar12 = (char *)((int)&uStack_114 + 3);

        do {

          pcVar10 = pcVar12 + 1;

          pcVar12 = pcVar12 + 1;

        } while (*pcVar10 != '\0');

        pcVar10 = pcVar5;

        for (uVar7 = (uint)((int)pcVar8 - (int)pcVar5) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar10;

          pcVar10 = pcVar10 + 4;

          pcVar12 = pcVar12 + 4;

        }

        for (uVar7 = (int)pcVar8 - (int)pcVar5 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *pcVar12 = *pcVar10;

          pcVar10 = pcVar10 + 1;

          pcVar12 = pcVar12 + 1;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x57c + param_2 * 4) + 0x1d8))(acStack_110,1,1);

      (**(code **)(**(int **)(param_1 + 0x57c + param_2 * 4) + 0xcc))(1);

      (**(code **)(**(int **)(param_1 + 0x57c + param_2 * 4) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x59c + param_2 * 4) != 0) {

      FUN_0085d970(param_3,acStack_110);

      piVar13 = *(int **)(param_1 + 0x59c + param_2 * 4);

      iStack_128 = *piVar13;

      uVar3 = (**(code **)(*piVar13 + 0x2c8))(0);

      (**(code **)(iStack_128 + 0x50))(acStack_110,uVar3);

      (**(code **)(**(int **)(param_1 + 0x59c + param_2 * 4) + 0xcc))(1);

      (**(code **)(**(int **)(param_1 + 0x59c + param_2 * 4) + 0x34c))();

      cVar1 = FUN_00513e70();

      if (cVar1 == '\0') {

        piVar13 = (int *)0x0;

      }

      else {

        iVar9 = (**(code **)(*param_3 + 0x25c))();

        if (iVar9 < 1000) {

          uVar3 = (**(code **)(*param_3 + 0x25c))();

          sprintf((char *)&iStack_130,"%d",uVar3);

          piVar13 = &iStack_130;

        }

        else {

          iVar9 = FUN_007a69d0();

          cVar1 = *(char *)(iVar9 + 0xc4);

          iVar9 = (**(code **)(*param_3 + 0x25c))();

          iVar9 = (**(code **)(*param_3 + 0x25c))((int)cVar1,iVar9 % 1000);

          sprintf((char *)&iStack_130,"%d%c%03d",iVar9 / 1000);

          piVar13 = &iStack_130;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x59c + param_2 * 4) + 0x1d8))(piVar13,1,1);

    }

  }

  ExceptionList = local_c;

  return;

}
