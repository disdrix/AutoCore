// READABILITY (auto CF):
//  - Body size: ~338 non-empty decompiler lines.
//  - Control keywords: if×58, while×5, for×5, do×3, goto×2, return×1.
//  - Notable callees: FUN_005714e0×12, FUN_00571620×12, FUN_007a4480×8, FUN_004d0e90×6, FUN_00514390×6, CONCAT31×2, Experience_EnsureLevelTableLoaded_INFERRED×2, Skill_SetRankAndReevaluate×2.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00533220
// -----------------------------------------------------------------------------
// Stable ID: aa_00533220
// Address:   0x00533220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_00533220(int *param_1,int param_2,uint param_3)



{

  int iVar1;

  uint uVar2;

  char cVar3;

  int *extraout_EAX;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ unaff_EDI;

  int *piVar8;

  int local_44;

  uint local_40;

  uint local_3c;

  uint local_38;

  void *local_34;

  uint local_30 [12];

  

  uVar2 = param_3;

  uVar6 = param_3 & 1;

  local_38 = uVar6;

  if (uVar6 != 0) {

    FUN_00521230();

  }

  iVar5 = param_2;

  local_40 = uVar2 & 4;

  if (local_40 != 0) {

    *(uint16_t *)(param_1 + 0x1b3) = 0;

  }

  if (uVar6 != 0) {

    *(uint16_t *)((int)param_1 + 0x6ce) = 0;

  }

  local_3c = uVar2 & 0x40;

  if (local_3c != 0) {

    *(uint16_t *)(param_1 + 0x160) = 0;

    *(uint8_t *)((int)param_1 + 0x599) = 1;

    *(uint8_t *)((int)param_1 + 0x59b) = 1;

    *(uint8_t *)(param_1 + 0x166) = 1;

    *(uint8_t *)((int)param_1 + 0x59a) = 1;

  }

  param_3 = CONCAT31(param_3._1_3_,param_1[0x1b2] != param_2);

  iVar7 = 2;

  param_2 = CONCAT31(param_2._1_3_,param_1[0x1b2] < param_2);

  param_1[0x1b2] = iVar5;

  if (1 < iVar5) {

    do {

      local_44 = iVar7;

      if (g_nExperienceLevelTableReady == 0) {

        Experience_EnsureLevelTableLoaded_INFERRED();

      }

      StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_34,&local_44);

      pvVar4 = (void *)*extraout_EAX;

      if (g_nExperienceLevelTableReady == 0) {

        Experience_EnsureLevelTableLoaded_INFERRED();

      }

      if (pvVar4 != g_pExperienceLevelMapEnd) {

        if (local_38 != 0) {

          *(short *)((int)param_1 + 0x6ce) =

               *(short *)((int)param_1 + 0x6ce) + *(short *)((int)pvVar4 + 0x16);

          FUN_004c2ef0(*(short *)((int)param_1 + 0x13e) + 1);

          FUN_004c2ee0((short)param_1[0x4f] + 1);

          FUN_004c2f00((short)param_1[0x50] + 1);

          FUN_004c2f10(*(short *)((int)param_1 + 0x142) + 1);

        }

        if (local_40 != 0) {

          *(short *)(param_1 + 0x1b3) = (short)param_1[0x1b3] + *(short *)((int)pvVar4 + 0x14);

        }

        if (local_3c != 0) {

          *(short *)(param_1 + 0x160) = (short)param_1[0x160] + *(short *)((int)pvVar4 + 0x18);

        }

        if ((char)param_3 != '\0') {

          if ((char)param_2 == '\0') {

            if (iVar7 == iVar5) {

              param_1[0x1cc] = *(int *)((int)pvVar4 + 0x10) + -1;

            }

          }

          else if (iVar7 == iVar5 + -1) {

            param_1[0x1cc] = *(int *)((int)pvVar4 + 0x10);

          }

        }

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 <= iVar5);

  }

  if (local_40 != 0) {

    iVar5 = *(int *)(*(int *)(param_1[1] + 4) + 0x74 + (int)param_1);

    if (iVar5 != 0) {

      iVar7 = 0;

      if (*(char *)(iVar5 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar5 + 0x1d) = 1;

      while( true ) {

        iVar5 = *(int *)(*(int *)(param_1[1] + 4) + 0x74 + (int)param_1);

        if (*(char *)(iVar5 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar7 == 0) {

          iVar7 = *(int *)(iVar5 + 0x14);

        }

        else {

          iVar7 = *(int *)(iVar7 + 0x14);

        }

        if (iVar7 == 0) {

          pvVar4 = (void *)0x0;

        }

        else {

          pvVar4 = *(void **)(iVar7 + 8);

        }

        if (pvVar4 == (void *)0x0) break;

        if ((*(char *)((int)pvVar4 + 0x5f8) != '\0') || (*(char *)((int)pvVar4 + 0x5f9) != '\0')) {

          Skill_SetRankAndReevaluate(pvVar4,(void *)0x0,(short)unaff_EDI);

        }

      }

      *(uint8_t *)(*(int *)(*(int *)(param_1[1] + 4) + 0x74 + (int)param_1) + 0x1d) = 0;

      iVar5 = *(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c);

      iVar7 = *(int *)((int)param_1 + *(int *)(param_1[1] + 4) + 0x74);

      local_30[0] = 0x294;

      local_30[1] = 0x29b;

      local_30[2] = 0x333;

      local_30[3] = 0x837;

      local_30[4] = 0x224;

      local_30[5] = 0x2bd;

      local_30[6] = 0x310;

      local_30[7] = 0x2fc;

      local_30[8] = 0x225;

      local_30[9] = 0x29a;

      local_30[10] = 0x317;

      local_30[0xb] = 0x365;

      iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 0x10) +

                               (*(uint *)(iVar7 + 8) &

                               local_30[(uint)*(byte *)(iVar5 + 0x531) +

                                        (uint)*(byte *)(iVar5 + 0x532) * 4]) * 4) + 4);

      if (iVar7 == 0) {

LAB_00533522:

        pvVar4 = (void *)0x0;

      }

      else {

        do {

          if (local_30[(uint)*(byte *)(iVar5 + 0x531) + (uint)*(byte *)(iVar5 + 0x532) * 4] ==

              *(uint *)(iVar7 + 0x10)) {

            if (iVar7 == 0) goto LAB_00533522;

            pvVar4 = *(void **)(iVar7 + 8);

            goto LAB_00533529;

          }

          iVar7 = *(int *)(iVar7 + 0xc);

        } while (iVar7 != 0);

        pvVar4 = (void *)0x0;

      }

LAB_00533529:

      if (pvVar4 != (void *)0x0) {

        Skill_SetRankAndReevaluate(pvVar4,(void *)0x1,(short)unaff_EDI);

      }

    }

    piVar8 = param_1 + 0x1d3;

    for (iVar5 = 100; iVar5 != 0; iVar5 = iVar5 + -1) {

      *piVar8 = -1;

      piVar8 = piVar8 + 1;

    }

  }

  if ((void *)param_1[0x94] != (void *)0x0) {

    Vehicle_RecalcCombatPools((void *)param_1[0x94]);

  }

  (**(code **)(*param_1 + 0x5c))();

  *(uint16_t *)(param_1 + 0x4b) = *(uint16_t *)((int)param_1 + 0x12e);

  *(uint8_t *)((int)param_1 + 0x4f2) = 1;

  if (*(char *)(*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) + 0x7e) != '\0') {

    CVOGCharacter_SearchAutoMissions(param_1);

  }

  if (((param_1[0x94] != 0) && (*(int *)(param_1[0x94] + 0x2b0) != 0)) &&

     (local_44 = param_1[0x32f], local_44 != 0)) {

    iVar5 = 0;

    do {

      iVar7 = *(int *)(*(int *)(param_1[0x94] + 0x260) + iVar5 * 4);

      if ((iVar7 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

        Vehicle_AttachWeapon(0,iVar5,0);

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,&param_2,&param_3,1,

                               0xffffffff);

          if (cVar3 == '\0') {

            FUN_004d0e90(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7);

          }

          else {

            FUN_00571620(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,param_2,param_3,1);

          }

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7,param_2,param_3,1);

        }

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < 3);

    iVar5 = *(int *)(param_1[0x94] + 0x264);

    if ((iVar5 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

      FUN_004fe800(0,0,0);

      cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                           0xffffffff);

      if (cVar3 == '\0') {

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          FUN_004d0e90(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

        }

      }

      else {

        FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

      }

    }

    iVar5 = *(int *)(param_1[0x94] + 0x26c);

    if ((iVar5 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

      FUN_004fe620(0,0,0);

      cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                           0xffffffff);

      if (cVar3 == '\0') {

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          FUN_004d0e90(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

        }

      }

      else {

        FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

      }

    }

    iVar5 = *(int *)(param_1[0x94] + 0x268);

    if ((iVar5 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

      Vehicle_EquipPowerPlant((void *)param_1[0x94],(void *)0x0,(void **)0x0,false);

      cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                           0xffffffff);

      if (cVar3 == '\0') {

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          FUN_004d0e90(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

        }

      }

      else {

        FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

      }

    }

    iVar5 = *(int *)(param_1[0x94] + 0x254);

    if ((iVar5 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

      Vehicle_SetEquippedArmor((void *)param_1[0x94],(void *)0x0,'\0');

      cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                           0xffffffff);

      if (cVar3 == '\0') {

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          FUN_004d0e90(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

        }

      }

      else {

        FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

      }

    }

    iVar5 = *(int *)(param_1[0x94] + 0x270);

    if ((iVar5 != 0) && (cVar3 = FUN_00514390(param_1,1), cVar3 == '\0')) {

      Vehicle_SetEquippedRaceItem((void *)param_1[0x94],(void *)0x0,(void **)0x0,'\0');

      cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                           0xffffffff);

      if (cVar3 == '\0') {

        cVar3 = FUN_005714e0(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,&param_2,&param_3,1,

                             0xffffffff);

        if (cVar3 == '\0') {

          FUN_004d0e90(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        }

        else {

          FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

        }

      }

      else {

        FUN_00571620(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5,param_2,param_3,1);

      }

    }

  }

  iVar5 = param_1[0x14e];

  if (iVar5 != 0) {

    iVar7 = 0;

    if (*(char *)(iVar5 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    uVar2 = local_3c;

    *(uint8_t *)(iVar5 + 0x1d) = 1;

    while( true ) {

      iVar5 = param_1[0x14e];

      if (*(char *)(iVar5 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar7 == 0) {

        iVar7 = *(int *)(iVar5 + 0x14);

      }

      else {

        iVar7 = *(int *)(iVar7 + 0x14);

      }

      if (iVar7 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(iVar7 + 8);

      }

      if (iVar5 == 0) break;

      iVar1 = *(int *)(*(int *)(iVar5 + 0x13c) + -4 + (uint)*(byte *)(iVar5 + 0x130) * 4);

      if (iVar1 != 0) {

        if ((0 < *(int *)(iVar1 + 0x130)) && (local_38 != 0)) {

          *(short *)((int)param_1 + 0x6ce) =

               *(short *)((int)param_1 + 0x6ce) + (short)*(int *)(iVar1 + 0x130);

        }

        if ((0 < *(int *)(iVar1 + 0x134)) && (local_40 != 0)) {

          *(short *)(param_1 + 0x1b3) = (short)param_1[0x1b3] + (short)*(int *)(iVar1 + 0x134);

        }

      }

      if ((0 < *(int *)(iVar5 + 0x114)) && (uVar2 != 0)) {

        *(short *)(param_1 + 0x160) = (short)param_1[0x160] + (short)*(int *)(iVar5 + 0x114);

      }

    }

    *(uint8_t *)(param_1[0x14e] + 0x1d) = 0;

  }

  return;

}
