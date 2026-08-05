// READABILITY (auto CF):
//  - Body size: ~361 non-empty decompiler lines.
//  - Control keywords: if×29, while×11, do×10, goto×4, return×2, for×1.
//  - Notable callees: CONCAT22×5, CONCAT31×2, FUN_00418b80×2, FUN_0053c360×2, FUN_0053fff0×2, FUN_00547920×2, CNDHash_Insert, CVOGCharacter_ApplyCreateFromPacket.
//  - Return sites: 2.

// =============================================================================
// CVOGCharacter_ApplyCreateFromPacket
// -----------------------------------------------------------------------------
// Stable ID: aa_00534bd0
// Address:   0x00534bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Apply CreateCharacter / CreateCharacterExtended packet to CVOGCharacter.

   When extended (param_4 != 0): reads FirstTimeFlags from packet offsets 0x8EC..0x8F8

   into secondary-this-relative -0x70..-0x64 (= primary char+0xD30).

   AutoCore CreateCharacterExtendedPacket.FirstTimeFlagsPacketOffset = 0x8EC.

   NOTE: extended HP at 0x8D6 is int16 (not int32). */



void __thiscall

CVOGCharacter_ApplyCreateFromPacket(int param_1,int param_2,uint32_t /* or float bits */ *param_3,uint param_4)



{

  uint32_t /* or float bits */ uVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  byte bVar5;

  char *pcVar6;

  undefined2 extraout_var_00;

  undefined3 extraout_var;

  uint *value;

  void *this;

  int *piVar7;

  int iVar8;

  int iVar9;

  undefined2 extraout_var_01;

  undefined2 extraout_var_02;

  undefined2 extraout_var_03;

  uint *puVar10;

  uint32_t /* or float bits */ *puVar11;

  uint32_t /* or float bits */ *puVar12;

  int iVar13;

  uint32_t /* or float bits */ unaff_EDI;

  uint32_t /* or float bits */ *puVar14;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int *piStack_4;

  

  iVar13 = param_2;

  FUN_005cbcb0(param_2,param_3,param_4);

  if ((param_2 != 0) && (param_3 == (uint32_t /* or float bits */ *)0x2)) {

    FUN_0051fae0(param_2 + 0x138);

    *(byte *)(param_1 + -0xa94) = *(byte *)(param_2 + 0x129) & 1;

    *(byte *)(param_1 + -0x6e7) = *(byte *)(param_2 + 0x129) >> 2 & 1;

    *(uint32_t /* or float bits */ *)(param_1 + -0xb90) = *(uint32_t /* or float bits */ *)(param_2 + 0xd8);

    *(uint32_t /* or float bits */ *)(param_1 + -0xb8c) = *(uint32_t /* or float bits */ *)(param_2 + 0xdc);

    *(uint32_t /* or float bits */ *)(param_1 + -0x6a4) = *(uint32_t /* or float bits */ *)(param_2 + 0xe8);

    *(uint32_t /* or float bits */ *)(param_1 + -0x6a8) = *(uint32_t /* or float bits */ *)(param_2 + 0xec);

    *(uint32_t /* or float bits */ *)(param_1 + -0x698) = *(uint32_t /* or float bits */ *)(param_2 + 0xf0);

    *(uint32_t /* or float bits */ *)(param_1 + -0x694) = *(uint32_t /* or float bits */ *)(param_2 + 0xf4);

    *(uint32_t /* or float bits */ *)(param_1 + -0x68c) = *(uint32_t /* or float bits */ *)(param_2 + 0xfc);

    *(uint32_t /* or float bits */ *)(param_1 + -0x690) = *(uint32_t /* or float bits */ *)(param_2 + 0x100);

    *(uint32_t /* or float bits */ *)(param_1 + -0x69c) = *(uint32_t /* or float bits */ *)(param_2 + 0x104);

    *(uint32_t /* or float bits */ *)(param_1 + -0x6a0) = *(uint32_t /* or float bits */ *)(param_2 + 0xf8);

    *(uint *)(param_1 + -0x6d8) = (uint)*(byte *)(param_2 + 0x128);

    *(uint *)(param_1 + -0x6ec) = (uint)*(byte *)(param_2 + 0x12a);

    DAT_00b04590 = *(uint32_t /* or float bits */ *)(param_2 + 0x130);

    _DAT_00b04594 = *(uint32_t /* or float bits */ *)(param_2 + 0x134);

    *(uint32_t /* or float bits */ *)(param_1 + -0x664) = *(uint32_t /* or float bits */ *)(param_2 + 0x120);

    pcVar6 = (char *)(param_2 + 0x16b);

    iVar9 = param_1 - (int)pcVar6;

    *(uint32_t /* or float bits */ *)(param_1 + -0x660) = *(uint32_t /* or float bits */ *)(param_2 + 0x124);

    do {

      cVar2 = *pcVar6;

      pcVar6[iVar9 + -0xa4] = cVar2;

      pcVar6 = pcVar6 + 1;

    } while (cVar2 != '\0');

    *(uint32_t /* or float bits */ *)(param_1 + -0x768) = *(uint32_t /* or float bits */ *)(param_2 + 0x1a0);

    *(uint32_t /* or float bits */ *)(param_1 + -0x73c) = *(uint32_t /* or float bits */ *)(param_2 + 0x108);

    *(uint32_t /* or float bits */ *)(param_1 + -0x738) = *(uint32_t /* or float bits */ *)(param_2 + 0x10c);

    *(uint32_t /* or float bits */ *)(param_1 + -0x730) = *(uint32_t /* or float bits */ *)(param_2 + 0x110);

    *(uint32_t /* or float bits */ *)(param_1 + -0x72c) = *(uint32_t /* or float bits */ *)(param_2 + 0x114);

    *(uint32_t /* or float bits */ *)(param_1 + -0x734) = *(uint32_t /* or float bits */ *)(param_2 + 0x118);

    *(uint32_t /* or float bits */ *)(param_1 + -0x728) = *(uint32_t /* or float bits */ *)(param_2 + 0x11c);

    if ((char)param_4 != '\0') {

      uVar1 = *(uint32_t /* or float bits */ *)(param_2 + 0x1320);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6dc) = uVar1;

      *(uint32_t /* or float bits */ *)(param_1 + -0x6e0) = uVar1;

      *(uint32_t /* or float bits */ *)(param_1 + -0x680) = *(uint32_t /* or float bits */ *)(param_2 + 0x8c0);

      *(uint32_t /* or float bits */ *)(param_1 + -0x67c) = *(uint32_t /* or float bits */ *)(param_2 + 0x8c4);

      uVar1 = *(uint32_t /* or float bits */ *)(param_2 + 0x8c8);

      *(uint32_t /* or float bits */ *)(param_1 + -0x678) = uVar1;

      *(uint32_t /* or float bits */ *)(param_1 + -0x674) = *(uint32_t /* or float bits */ *)(param_2 + 0x8cc);

      *(uint32_t /* or float bits */ *)(param_1 + -0x670) = *(uint32_t /* or float bits */ *)(param_2 + 0x8d0);

      FUN_004c2ee0(CONCAT22((short)((uint)uVar1 >> 0x10),*(undefined2 *)(param_2 + 0x8da)));

      FUN_004c2ef0(CONCAT22(extraout_var_00,*(undefined2 *)(param_2 + 0x8dc)));

      FUN_004c2f00(CONCAT22(extraout_var_01,*(undefined2 *)(param_2 + 0x8de)));

      FUN_004c2f10(CONCAT22(extraout_var_02,*(undefined2 *)(param_2 + 0x8e0)));

      *(undefined2 *)(param_1 + -0x6d4) = *(undefined2 *)(param_2 + 0x8e4);

      *(undefined2 *)(param_1 + -0x6d2) = *(undefined2 *)(param_2 + 0x8d8);

      *(undefined2 *)(param_1 + -0xc74) = *(undefined2 *)(param_2 + 0x8d4);

      *(undefined2 *)(param_1 + -0xc72) = *(undefined2 *)(param_2 + 0x8d6);

      *(uint8_t *)(param_1 + -0x807) = *(uint8_t *)(param_2 + 0x8e7);

      *(uint8_t *)(param_1 + -0x808) = *(uint8_t *)(param_2 + 0x8e6);

      *(uint8_t *)(param_1 + -0x806) = *(uint8_t *)(param_2 + 0x8e8);

      *(uint8_t *)(param_1 + -0x805) = *(uint8_t *)(param_2 + 0x8e9);

      *(uint32_t /* or float bits */ *)(param_1 + -0x74c) = *(uint32_t /* or float bits */ *)(param_2 + 0x1328);

      *(uint32_t /* or float bits */ *)(param_1 + -0x748) = *(uint32_t /* or float bits */ *)(param_2 + 0x1330);

      *(uint32_t /* or float bits */ *)(param_1 + -0x744) = *(uint32_t /* or float bits */ *)(param_2 + 0x1334);

      *(uint32_t /* or float bits */ *)(param_1 + -0x740) = *(uint32_t /* or float bits */ *)(param_2 + 0x1338);

      *(uint32_t /* or float bits */ *)(param_1 + -0x70) = *(uint32_t /* or float bits */ *)(param_2 + 0x8ec);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6c) = *(uint32_t /* or float bits */ *)(param_2 + 0x8f0);

      *(uint32_t /* or float bits */ *)(param_1 + -0x68) = *(uint32_t /* or float bits */ *)(param_2 + 0x8f4);

      *(uint32_t /* or float bits */ *)(param_1 + -100) = *(uint32_t /* or float bits */ *)(param_2 + 0x8f8);

      *(undefined2 *)(param_1 + -0x820) = *(undefined2 *)(param_2 + 0x8e2);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7a0) = *(uint32_t /* or float bits */ *)(param_2 + 0x1324);

      *(uint32_t /* or float bits */ *)(param_1 + -0x800) = *(uint32_t /* or float bits */ *)(param_2 + 0x900);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7fc) = *(uint32_t /* or float bits */ *)(param_2 + 0x904);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7f8) = *(uint32_t /* or float bits */ *)(param_2 + 0x908);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7f4) = *(uint32_t /* or float bits */ *)(param_2 + 0x90c);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7f0) = *(uint32_t /* or float bits */ *)(param_2 + 0x910);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7ec) = *(uint32_t /* or float bits */ *)(param_2 + 0x914);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7e8) = *(uint32_t /* or float bits */ *)(param_2 + 0x918);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7e4) = *(uint32_t /* or float bits */ *)(param_2 + 0x91c);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7e0) = *(uint32_t /* or float bits */ *)(param_2 + 0x920);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7dc) = *(uint32_t /* or float bits */ *)(param_2 + 0x924);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7d8) = *(uint32_t /* or float bits */ *)(param_2 + 0x928);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7d4) = *(uint32_t /* or float bits */ *)(param_2 + 0x92c);

      *(uint32_t /* or float bits */ *)(param_1 + -2000) = *(uint32_t /* or float bits */ *)(param_2 + 0x930);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7cc) = *(uint32_t /* or float bits */ *)(param_2 + 0x934);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7c8) = *(uint32_t /* or float bits */ *)(param_2 + 0x938);

      *(uint32_t /* or float bits */ *)(param_1 + -0x7c4) = *(uint32_t /* or float bits */ *)(param_2 + 0x93c);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6d0) = *(uint32_t /* or float bits */ *)(param_2 + 0x940);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6cc) = *(uint32_t /* or float bits */ *)(param_2 + 0x944);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6c8) = *(uint32_t /* or float bits */ *)(param_2 + 0x948);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6c4) = *(uint32_t /* or float bits */ *)(param_2 + 0x94c);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6c0) = *(uint32_t /* or float bits */ *)(param_2 + 0x950);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6bc) = *(uint32_t /* or float bits */ *)(param_2 + 0x954);

      *(uint32_t /* or float bits */ *)(param_1 + -0x6b8) = *(uint32_t /* or float bits */ *)(param_2 + 0x958);

      (**(code **)(*(int *)(param_1 + -0xda0) + 0x5c))();

      CVOGReaction_AddExperience((int *)(param_1 + -0xda0),0,PacketOrNonKill);

      FUN_00539d70(CONCAT31(extraout_var,*(uint8_t *)(*(int *)(param_1 + -0x86c) + 0x1c)));

      puVar10 = (uint *)(param_2 + 0x1b8);

      uVar3 = *(uint *)(param_2 + 0x1b8);

      while (uVar3 != 0) {

        value = operator_new(0xc);

        *value = *puVar10;

        value[1] = puVar10[1];

        value[2] = puVar10[2];

        CNDHash_Insert(*(void **)(param_1 + -0x86c),*value,value,'\0');

        puVar10 = puVar10 + 3;

        uVar3 = *puVar10;

      }

      *(int *)(param_2 + 0x133c) = param_2 + 0x1358;

      param_4 = param_4 & 0xffffff00;

      if (*(char *)(param_2 + 0x1b4) != '\0') {

        do {

          iVar9 = (param_4 & 0xff) * 8;

          this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c +

                                              param_1) + 0x234))

                                   (*(uint32_t /* or float bits */ *)(iVar9 + *(int *)(param_2 + 0x133c)));

          if (this != (void *)0x0) {

            Skill_SetRankAndReevaluate

                      (this,(void *)CONCAT22(extraout_var_03,

                                             *(undefined2 *)(iVar9 + 4 + *(int *)(param_2 + 0x133c))

                                            ),(short)unaff_EDI);

          }

          bVar5 = (char)param_4 + 1;

          param_4 = CONCAT31(param_4._1_3_,bVar5);

        } while (bVar5 < *(byte *)(param_2 + 0x1b4));

      }

      *(uint *)(param_2 + 0x1340) =

           *(int *)(param_2 + 0x133c) + (uint)*(byte *)(param_2 + 0x1b4) * 8;

      (**(code **)(**(int **)(param_1 + -0x868) + 4))();

      iVar9 = 0;

      if (0 < *(int *)(param_2 + 0x1a8)) {

        do {

          uVar3 = *(uint *)(*(int *)(param_2 + 0x1340) + iVar9 * 4);

          piVar7 = (int *)FUN_0053fff0();

          iVar8 = *piVar7;

          if (iVar8 != 0) {

            iVar8 = *(int *)(*(int *)(*(int *)(iVar8 + 0x10) + (*(uint *)(iVar8 + 8) & uVar3) * 4) +

                            4);

            if (iVar8 == 0) {

LAB_00535154:

              puVar11 = (uint32_t /* or float bits */ *)0x0;

            }

            else {

              do {

                if (uVar3 == *(uint *)(iVar8 + 0x10)) {

                  if (iVar8 == 0) goto LAB_00535154;

                  puVar11 = *(uint32_t /* or float bits */ **)(iVar8 + 8);

                  goto LAB_0053515b;

                }

                iVar8 = *(int *)(iVar8 + 0xc);

              } while (iVar8 != 0);

              puVar11 = (uint32_t /* or float bits */ *)0x0;

            }

LAB_0053515b:

            if (puVar11 != (uint32_t /* or float bits */ *)0x0) {

              FUN_00547920(0);

              FUN_0053c360(*puVar11,puVar11,0);

            }

          }

          iVar9 = iVar9 + 1;

        } while (iVar9 < *(int *)(param_2 + 0x1a8));

      }

      *(int *)(param_2 + 0x1344) = *(int *)(param_2 + 0x1340) + *(int *)(param_2 + 0x1a8) * 4;

      if (*(void **)(param_1 + -0x82c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(param_1 + -0x82c));

      }

      *(uint32_t /* or float bits */ *)(param_1 + -0x82c) = 0;

      *(uint32_t /* or float bits */ *)(param_1 + -0x828) = 0;

      *(uint32_t /* or float bits */ *)(param_1 + -0x824) = 0;

      param_4 = 0;

      if (0 < *(short *)(param_2 + 0x1b0)) {

        do {

          puVar11 = (uint32_t /* or float bits */ *)(*(int *)(param_2 + 0x1344) + param_4 * 4);

          iVar9 = *(int *)(param_1 + -0x82c);

          if ((iVar9 == 0) ||

             ((uint)(*(int *)(param_1 + -0x824) - iVar9 >> 2) <=

              (uint)(*(int *)(param_1 + -0x828) - iVar9 >> 2))) {

            FUN_004073a0(*(uint32_t /* or float bits */ *)(param_1 + -0x828),1,puVar11);

          }

          else {

            puVar12 = *(uint32_t /* or float bits */ **)(param_1 + -0x828);

            *puVar12 = *puVar11;

            *(uint32_t /* or float bits */ **)(param_1 + -0x828) = puVar12 + 1;

          }

          iVar9 = FUN_0051a0e0(*(uint32_t /* or float bits */ *)(*(int *)(param_2 + 0x1344) + param_4 * 4));

          if ((iVar9 != 0) && (*(int *)(iVar9 + 0x14) != -1)) {

            FUN_005304a0(*(int *)(iVar9 + 0x14),*(uint32_t /* or float bits */ *)(iVar9 + 0x18),0);

          }

          param_4 = param_4 + 1;

        } while ((int)param_4 < (int)*(short *)(param_2 + 0x1b0));

      }

      piVar7 = (int *)(*(int *)(param_2 + 0x1344) + *(short *)(param_2 + 0x1b0) * 4);

      iVar9 = (int)*(short *)(param_2 + 0x1b2);

      piStack_4 = piVar7 + iVar9 * 2;

      param_2 = 0;

      if (0 < iVar9) {

        iVar8 = (int)piStack_4 - (int)piVar7;

        iStack_8 = iVar9 * 4;

        do {

          uVar1 = *(uint32_t /* or float bits */ *)(iVar8 + (int)piVar7);

          param_4 = *piVar7;

          FUN_00418b80(&iStack_10,&param_4);

          if (iStack_10 == *(int *)(param_1 + -0x818)) {

            puVar11 = (uint32_t /* or float bits */ *)FUN_0053af20(&param_4);

            *puVar11 = 0;

            puVar11[1] = uVar1;

          }

          else {

            *(uint32_t /* or float bits */ *)(iStack_10 + 0x14) = uVar1;

          }

          param_4 = *piVar7;

          FUN_00418b80(&iStack_c,&param_4);

          if (iStack_c != *(int *)(param_1 + -0x818)) {

            iVar9 = *(int *)(iStack_8 + (int)piVar7);

            *(int *)(iStack_c + 0x10) = iVar9;

            if (*(int *)(iStack_c + 0x14) < iVar9) {

              *(int *)(iStack_c + 0x10) = *(int *)(iStack_c + 0x14);

            }

            *(uint *)(param_1 + -0x76c) = *(uint *)(param_1 + -0x76c) | 0x40;

          }

          param_2 = param_2 + 1;

          piVar7 = piVar7 + 1;

        } while (param_2 < *(short *)(iVar13 + 0x1b2));

      }

      *(int **)(iVar13 + 0x1354) = piStack_4 + *(short *)(iVar13 + 0x1b2);

      (**(code **)(**(int **)(param_1 + -0x860) + 4))();

      iStack_14 = 0;

      if (0 < *(int *)(iVar13 + 0x1ac)) {

        param_4 = 0;

        do {

          iVar8 = param_4;

          uVar3 = *(uint *)(param_4 + *(int *)(iVar13 + 0x1354));

          piVar7 = (int *)FUN_0053fff0();

          iVar9 = *piVar7;

          if (iVar9 != 0) {

            iVar9 = *(int *)(*(int *)(*(int *)(iVar9 + 0x10) + (*(uint *)(iVar9 + 8) & uVar3) * 4) +

                            4);

            if (iVar9 == 0) {

LAB_005353e8:

              param_3 = (uint32_t /* or float bits */ *)0x0;

            }

            else {

              do {

                if (uVar3 == *(uint *)(iVar9 + 0x10)) {

                  if (iVar9 == 0) goto LAB_005353e8;

                  param_3 = *(uint32_t /* or float bits */ **)(iVar9 + 8);

                  goto LAB_005353f9;

                }

                iVar9 = *(int *)(iVar9 + 0xc);

              } while (iVar9 != 0);

              param_3 = (uint32_t /* or float bits */ *)0x0;

            }

LAB_005353f9:

            if (param_3 != (uint32_t /* or float bits */ *)0x0) {

              FUN_00547920(1);

              FUN_0053c360(*param_3,param_3,0);

              piStack_4 = *(int **)(*(int *)(iVar13 + 0x1354) + 0x30 + iVar8);

              iVar9 = 0;

              param_2 = 0;

              if (*(byte *)(param_3 + 0x4c) != 0) {

                piVar7 = (int *)param_3[0x4f];

                do {

                  iVar4 = *piVar7;

                  if (*(int **)(iVar4 + 0x10) == piStack_4) {

                    FUN_0053c460(piStack_4,iVar4,0);

                    iVar8 = param_4;

                    param_2 = iVar4;

                    break;

                  }

                  iVar9 = iVar9 + 1;

                  piVar7 = piVar7 + 1;

                  iVar8 = param_4;

                } while (iVar9 < (int)(uint)*(byte *)(param_3 + 0x4c));

              }

              puVar11 = operator_new(0x30);

              if (puVar11 == (uint32_t /* or float bits */ *)0x0) {

                puVar11 = (uint32_t /* or float bits */ *)0x0;

              }

              else {

                *(uint8_t *)(puVar11 + 0xb) = 0;

                puVar11[8] = 0xffffffff;

                puVar11[9] = 0xffffffff;

                puVar11[10] = 0xffffffff;

                *puVar11 = 0xffffffff;

                puVar11[1] = 0xffffffff;

                puVar11[2] = 0xffffffff;

                puVar11[3] = 0xffffffff;

                puVar11[4] = 0xffffffff;

                puVar11[5] = 0xffffffff;

                puVar11[6] = 0xffffffff;

                puVar11[7] = 0xffffffff;

              }

              puVar11[8] = *(uint32_t /* or float bits */ *)(*(int *)(iVar13 + 0x1354) + 0x28 + iVar8);

              puVar11[9] = *(uint32_t /* or float bits */ *)(*(int *)(iVar13 + 0x1354) + 0x2c + iVar8);

              puVar12 = (uint32_t /* or float bits */ *)(*(int *)(iVar13 + 0x1354) + 8 + iVar8);

              puVar14 = puVar11;

              for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {

                *puVar14 = *puVar12;

                puVar12 = puVar12 + 1;

                puVar14 = puVar14 + 1;

              }

              FUN_0053c660(*param_3,puVar11,0);

              FUN_00531bd0(param_2,*(int *)(iVar13 + 0x1354) + 0x34 + param_4);

              iVar8 = param_4;

            }

          }

          iStack_14 = iStack_14 + 1;

          param_4 = iVar8 + 0x48;

        } while (iStack_14 < *(int *)(iVar13 + 0x1ac));

      }

      if (*(int *)(param_1 + -0xe4) != 0) {

        FUN_00570f50();

        puVar11 = (uint32_t /* or float bits */ *)(iVar13 + 0x960);

        iVar13 = 0x138;

        do {

          iVar9 = CVOGReaction_ResolveObjectTarget(1,*puVar11,puVar11[1]);

          if (iVar9 != 0) {

            FUN_00571d30(iVar9);

          }

          puVar11 = puVar11 + 2;

          iVar13 = iVar13 + -1;

        } while (iVar13 != 0);

      }

    }

  }

  return;

}
