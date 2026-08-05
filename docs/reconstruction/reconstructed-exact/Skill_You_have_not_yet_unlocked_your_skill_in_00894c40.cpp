// READABILITY (auto CF):
//  - Body size: ~294 non-empty decompiler lines.
//  - Control keywords: if×36, goto×6, return×5, do×3.
//  - Notable callees: FUN_007a6de0×28, sprintf×12, FUN_00402d50×8, free×5, FUN_0052ad60×2, FUN_0051fc80, FUN_0052ada0, FUN_0052b040.
//  - Strings: "Level"; "%s %s %d"; "This trainer can train up to a max of"; "%s %d %s %s.".
//  - Return sites: 5.

// =============================================================================
// Skill_You_have_not_yet_unlocked_your_skill_in_00894c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00894c40
// Address:   0x00894c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "You have not yet unlocked your skill in"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_You_have_not_yet_unlocked_your_skill_in_00894c40(void)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  int iVar10;

  uint8_t **ppuVar11;

  int *unaff_ESI;

  bool bVar12;

  char *pcVar13;

  uint32_t /* width from decompiler */ uStack_4dc;

  int iStack_4d8;

  uint8_t *puStack_4d0;

  uint8_t auStack_4cc [192];

  uint8_t auStack_40c [3];

  uint8_t uStack_409;

  uint8_t *puStack_408;

  uint8_t auStack_404 [252];

  uint8_t *apuStack_308 [74];

  uint8_t auStack_1de [466];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b1019;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar2 == '\0') {

    ExceptionList = pvStack_c;

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    ExceptionList = pvStack_c;

    return;

  }

  iVar3 = *(int *)(DAT_00d1b6d8 + 0x594);

  unaff_ESI[0x148] = iVar3;

  unaff_ESI[0x149] = *(int *)(DAT_00d1b6d8 + 0x590);

  if (iVar3 == -1) {

    ExceptionList = pvStack_c;

    return;

  }

  cVar2 = FUN_0052b040();

  if (cVar2 == '\0') {

    ExceptionList = pvStack_c;

    return;

  }

  iVar3 = FUN_0052d180(unaff_ESI[0x148]);

  FUN_007a69d0();

  uStack_4dc = 0;

  iStack_4d8 = 0;

  if (DAT_00d1b6d8 != 0) {

    uStack_4dc = FUN_0052ada0(unaff_ESI[0x148]);

    iStack_4d8 = FUN_0052ad60(unaff_ESI[0x148]);

  }

  if ((int *)unaff_ESI[0x153] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x1d8))(unaff_ESI[0x14c],1,1);

    (**(code **)(*(int *)unaff_ESI[0x153] + 0x34c))();

  }

  if (unaff_ESI[0x154] != 0) {

    uStack_409 = 0;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

    uStack_4 = 0;

    uVar6 = *puVar4;

    iVar9 = iStack_4d8 / 0x32 + 1;

    uVar5 = FUN_007a6de0("Level",0xffffffff);

    uVar6 = FUN_007a6de0(uVar6,0xffffffff);

    sprintf((char *)&puStack_4d0,"%s %s %d",uVar6,uVar5,iVar9);

    uStack_4 = 0xffffffff;

    if (puStack_408 != auStack_404) {

      free(puStack_408);

    }

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x1d8))(&puStack_4d0,1,1);

    (**(code **)(*(int *)unaff_ESI[0x154] + 0x34c))();

  }

  if (unaff_ESI[0x156] != 0) {

    if (iVar3 == 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

      uStack_4 = 1;

      uVar6 = FUN_007a6de0(*puVar4,0xffffffff);

      uVar5 = FUN_007a6de0(&DAT_00a28b50,0xffffffff);

      iVar9 = unaff_ESI[0x149];

      uVar7 = FUN_007a6de0("This trainer can train up to a max of",0xffffffff);

      sprintf((char *)apuStack_308,"%s %d %s %s.",uVar7,iVar9,uVar5,uVar6);

LAB_00894ef7:

      bVar12 = puStack_408 == auStack_404;

LAB_00894fa3:

      uStack_4 = 0xffffffff;

      if (!bVar12) {

        free(puStack_408);

      }

    }

    else {

      if (iVar3 == 2) {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

        uStack_4 = 2;

        uVar6 = *puVar4;

        uVar5 = FUN_007a6de0("before you may train further",0xffffffff);

        uVar6 = FUN_007a6de0(uVar6,0xffffffff);

        uVar7 = FUN_007a6de0("You must practice",0xffffffff);

        sprintf((char *)apuStack_308,"%s \'%s\' %s.",uVar7,uVar6,uVar5);

        bVar12 = puStack_4d0 == auStack_4cc;

        puStack_408 = puStack_4d0;

        goto LAB_00894fa3;

      }

      if (iVar3 == 3) {

        pcVar13 = (char *)FUN_007a6de0("You have learned all the disciplines you can in this tier.",

                                       0xffffffff);

        sprintf((char *)apuStack_308,pcVar13);

      }

      else if (iVar3 == 4) {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

        uStack_4 = 3;

        uVar6 = FUN_007a6de0(*puVar4,0xffffffff);

        uVar5 = FUN_007a6de0("You do not meet the requirements to train",0xffffffff);

        sprintf((char *)apuStack_308,"%s %s.",uVar5,uVar6);

        goto LAB_00894ef7;

      }

    }

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x1d8))(apuStack_308,1,1);

    (**(code **)(*(int *)unaff_ESI[0x156] + 0x34c))();

  }

  if ((unaff_ESI[0x157] != 0) && (DAT_00d1b6d8 != 0)) {

    if (iStack_4d8 == 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

      uStack_4 = 4;

      uVar6 = FUN_007a6de0(*puVar4,0xffffffff);

      uVar5 = FUN_007a6de0("You have not yet unlocked your skill in",0xffffffff);

      sprintf((char *)apuStack_308,"%s %s",uVar5,uVar6);

      bVar12 = puStack_4d0 == auStack_4cc;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

      uStack_4 = 5;

      uVar6 = FUN_007a6de0(*puVar4,0xffffffff);

      uVar5 = FUN_007a6de0(&DAT_00a28b50,0xffffffff);

      iVar9 = iStack_4d8;

      uVar7 = FUN_007a6de0("skill with a max of",0xffffffff);

      uVar8 = FUN_007a6de0("You currently have",0xffffffff);

      sprintf((char *)apuStack_308,"%s %d %s %d %s %s",uVar8,uStack_4dc,uVar7,iVar9,uVar5,uVar6);

      bVar12 = puStack_4d0 == auStack_4cc;

    }

    uStack_4 = 0xffffffff;

    if (!bVar12) {

      free(puStack_4d0);

    }

    (**(code **)(*(int *)unaff_ESI[0x157] + 0x1d8))(apuStack_308,1,1);

    (**(code **)(*(int *)unaff_ESI[0x157] + 0x34c))();

  }

  if (unaff_ESI[0x158] != 0) {

    iVar9 = FUN_0052dff0();

    unaff_ESI[0x14a] = iVar9;

    unaff_ESI[0x14b] = iVar9 >> 0x1f;

    FUN_0051fc80(iVar9,iVar9 >> 0x1f,&puStack_408,1);

    (**(code **)(*(int *)unaff_ESI[0x158] + 0x268))();

    iVar9 = *(int *)unaff_ESI[0x158];

    uVar6 = FUN_007a6de0("Cost: ",0xffffffff);

    (**(code **)(iVar9 + 0x250))(uVar6);

    if (DAT_00d1b6d8 == 0) {

LAB_008951b9:

      uVar6 = 0xffff2020;

    }

    else {

      iVar9 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

              (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

      if ((iVar9 < unaff_ESI[0x14b]) ||

         ((iVar9 <= unaff_ESI[0x14b] &&

          (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) <

           (uint)unaff_ESI[0x14a])))) goto LAB_008951b9;

      uVar6 = 0xff20ff20;

    }

    (**(code **)(*(int *)unaff_ESI[0x158] + 0x224))(auStack_40c,uVar6);

    (**(code **)(*(int *)unaff_ESI[0x158] + 0x34c))();

  }

  if ((int *)unaff_ESI[0x159] != (int *)0x0) {

    if (iStack_4d8 < unaff_ESI[0x149]) {

      if (DAT_00d1b6d8 != 0) {

        iVar9 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

        if ((iVar9 <= unaff_ESI[0x14b]) &&

           ((iVar9 < unaff_ESI[0x14b] ||

            (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) <

             (uint)unaff_ESI[0x14a])))) {

          iVar9 = *(int *)unaff_ESI[0x159];

          uVar7 = 1;

          uVar5 = 1;

          uVar6 = FUN_007a6de0("You do not have enough money!",0xffffffff);

          (**(code **)(iVar9 + 0x1d8))(uVar6,uVar5,uVar7);

          goto LAB_0089545f;

        }

        if (iVar3 != 0) {

          if (iVar3 == 2) {

            puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

            uStack_4 = 7;

            uVar6 = *puVar4;

            uVar5 = FUN_007a6de0("before you may train further",0xffffffff);

            uVar6 = FUN_007a6de0(uVar6,0xffffffff);

            uVar7 = FUN_007a6de0("You must practice",0xffffffff);

            sprintf((char *)&puStack_408,"%s %s %s.",uVar7,uVar6,uVar5);

            uStack_4 = 0xffffffff;

            if (puStack_4d0 != auStack_4cc) {

              free(puStack_4d0);

            }

          }

          else if (iVar3 == 3) {

            pcVar13 = (char *)FUN_007a6de0("You have learned all the disciplines you can in this tier."

                                           ,0xffffffff);

            sprintf((char *)&puStack_408,pcVar13);

          }

          else {

            pcVar13 = (char *)FUN_007a6de0("You do not meet the requirements to train this discipline."

                                           ,0xffffffff);

            sprintf((char *)&puStack_408,pcVar13);

          }

          ppuVar11 = &puStack_408;

          goto LAB_0089544c;

        }

        iVar9 = FUN_0052ad60(unaff_ESI[0x148]);

        iVar10 = FUN_0052d0b0();

        iVar9 = iVar9 + iVar10;

        if (iStack_4d8 < 1) {

          pcVar13 = "Do you wish to unlock this discipline and set your max ability to";

        }

        else {

          pcVar13 = "Do you wish to train in this discipline and raise your max ability to";

        }

        uVar6 = FUN_007a6de0(pcVar13,0xffffffff);

        sprintf((char *)&puStack_408,"%s %d?",uVar6,iVar9);

        (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(&puStack_408,1,1);

        (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(1,&stack0xfffffb18);

      }

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1de);

      uStack_4 = 6;

      uVar6 = *puVar4;

      uVar5 = FUN_007a6de0("than this trainer can teach you",0xffffffff);

      uVar6 = FUN_007a6de0(uVar6,0xffffffff);

      uVar7 = FUN_007a6de0("You already know more",0xffffffff);

      sprintf((char *)apuStack_308,"%s %s %s!",uVar7,uVar6,uVar5);

      uStack_4 = 0xffffffff;

      if (puStack_4d0 != auStack_4cc) {

        free(puStack_4d0);

      }

      ppuVar11 = apuStack_308;

LAB_0089544c:

      (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(ppuVar11,1,1);

LAB_0089545f:

      (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(1,&stack0xfffffb18);

    }

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x34c))();

  }

  piVar1 = (int *)unaff_ESI[0x15a];

  if (piVar1 != (int *)0x0) {

    if (iVar3 == 0) {

      if (DAT_00d1b6d8 != 0) {

        iVar3 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

        if ((unaff_ESI[0x14b] <= iVar3) &&

           (((unaff_ESI[0x14b] < iVar3 ||

             ((uint)unaff_ESI[0x14a] <=

              *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))) &&

            (iStack_4d8 < unaff_ESI[0x149])))) {

          cVar2 = (**(code **)(*piVar1 + 0xd8))();

          if (cVar2 == '\0') {

            (**(code **)(*(int *)unaff_ESI[0x15a] + 0xd4))(1);

            (**(code **)(*(int *)unaff_ESI[0x15a] + 0x34c))();

          }

          goto LAB_0089555d;

        }

      }

      cVar2 = (**(code **)(*piVar1 + 0xd8))();

      if (cVar2 == '\x01') {

        (**(code **)(*(int *)unaff_ESI[0x15a] + 0xd4))(0);

        (**(code **)(*(int *)unaff_ESI[0x15a] + 0x34c))();

      }

    }

    else {

      (**(code **)(*piVar1 + 0xd4))(0);

      (**(code **)(*(int *)unaff_ESI[0x15a] + 0x34c))();

    }

  }

LAB_0089555d:

  FUN_00894590();

  ExceptionList = pvStack_c;

  return;

}
