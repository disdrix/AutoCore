// READABILITY (auto CF):
//  - Body size: ~162 non-empty decompiler lines.
//  - Control keywords: if×19, do×3, while×3, return×2, switch×1.
//  - Notable callees: CONCAT22×2, FUN_004ce940×2, CVOGReaction_GiveItemByCbid, Client_SendSectorPacket, FUN_00508e20, FUN_00509c70, FUN_00516720, FUN_007a69d0.
//  - Strings: "You need to select a reward first!".
//  - Return sites: 2.

// =============================================================================
// Mission_Client_ClaimSelectedReward
// -----------------------------------------------------------------------------
// Purpose:  Mission/arena reward claim UI handler. On accept UI message, requires a selected reward ('You need to select a reward first!'), then sends sector packet and may grant item via CVOGReaction_GiveItemByCbid.
//
// Address:  0x0086d020  (autoassault.exe, image base 0x400000)
// Stable:   aa_0086d020
// System:   missions-progression
//
// Evidence strings (from raw decompile):
//   - "You need to select a reward first!"
//
// Notable callees:
//   - FUN_007a6de0 / FUN_007fdfb0
//   - Client_SendSectorPacket
//   - CVOGReaction_GiveItemByCbid
//   - FUN_00508e20 / FUN_00516720 / FUN_00509c70
//   - FUN_007fca10 / FUN_007fd420 / FUN_0087b500
//
// Notes:    __thiscall; switch on UI message ids 40000 / 0x9c41.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

uint32_t /* width from decompiler */ __thiscall Mission_Client_ClaimSelectedReward(int param_1,int param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  int iVar11;

  int iStack_30;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  

  switch(param_3) {

  case 40000:

  case 0x9c41:

    if (param_2 == 8) {

      if ((0 < *(int *)(param_1 + 0x510)) && (*(int *)(param_1 + 0x528) < 1)) {

        FUN_007a69d0();

        uVar10 = 0;

        uVar9 = 1;

        uVar8 = 0xffffffff;

        uVar5 = FUN_007a6de0("You need to select a reward first!",0xffffffff);

        FUN_007fdfb0(&DAT_00d1a840,uVar5,uVar8,uVar9,uVar10);

        return 1;

      }

      uStack_10 = DAT_00d1ad48;

      uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c);

      uStack_c = DAT_00d1ad4c;

      uStack_8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x528);

      uStack_18 = 0x20c6;

      Client_SendSectorPacket(&DAT_00d1a840,0x18,&uStack_18);

      FUN_007fca10();

    }

    break;

  case 0x9c42:

  case 0x9c43:

  case 0x9c44:

  case 0x9c45:

    iVar6 = param_3 + -0x9c42;

    if (param_2 == 5) {

      iStack_30 = *(int *)(param_1 + 0x50c + iVar6 * 4);

      puVar7 = (uint32_t /* width from decompiler */ *)0x0;

      if (*(char *)(param_3 + -0x9722 + param_1) != '\0') {

        iVar11 = iStack_30;

        FUN_004ce940(iStack_30);

        puVar7 = (uint32_t /* width from decompiler */ *)FUN_00508e20(iVar11);

        if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

          iStack_30 = puVar7[0x21];

        }

      }

      piVar2 = (int *)CVOGReaction_GiveItemByCbid(iStack_30);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 8))(iStack_30,DAT_00d1b644,0);

        if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00516720(puVar7 + 1);

          uVar5 = puVar7[0x22];

          uVar10 = 0;

          uVar9 = 0x80000000;

          uVar8 = 0;

          piVar3 = piVar2;

          FUN_004ce940(piVar2,0,0x80000000,0,uVar5);

          FUN_00509c70(piVar3,uVar8,uVar9,uVar10,uVar5);

          piVar3 = puVar7 + 0x24;

          iVar11 = 5;

          do {

            if (*piVar3 != -1) {

              (**(code **)(*piVar2 + 0x78))(CONCAT22((short)((uint)piVar3 >> 0x10),(short)*piVar3));

            }

            piVar3 = piVar3 + 1;

            iVar11 = iVar11 + -1;

          } while (iVar11 != 0);

          piVar3 = puVar7 + 0x29;

          iVar11 = 5;

          do {

            if (*piVar3 != -1) {

              (**(code **)(*piVar2 + 0x54))(CONCAT22((short)((uint)piVar3 >> 0x10),(short)*piVar3));

            }

            piVar3 = piVar3 + 1;

            iVar11 = iVar11 + -1;

          } while (iVar11 != 0);

          (**(code **)(*piVar2 + 100))();

          (**(code **)(*piVar2 + 0x9c))(*puVar7);

        }

        puVar7 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x140))(&stack0xffffffcc,1);

        puVar4 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x120))

                           (&stack0xffffffcc,1,1);

        FUN_007fd420(*puVar4,puVar4[1],*puVar7,puVar7[1]);

        if (DAT_00d1d8dc != (int *)0x0) {

          DAT_00d1d8dc[0x146] = 0;

        }

        if ((*(int *)(param_1 + 0x528) != iVar6) && (0 < iVar6)) {

          (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x158))(0,param_1 + 0x530);

          cVar1 = (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0xf8))();

          if (cVar1 != '\0') {

            *(int *)(*(int *)(param_1 + 0x588 + iVar6 * 4) + 0xf8) =

                 (int)(*(float *)(param_1 + 0x53c) * DAT_00aaa6f8);

          }

          (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x34c))();

          (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x158))(0,param_1 + 0x530);

          cVar1 = (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0xf8))();

          if (cVar1 != '\0') {

            *(int *)(*(int *)(param_1 + 0x5b0 + iVar6 * 4) + 0xf8) =

                 (int)(*(float *)(param_1 + 0x53c) * DAT_00aaa6f8);

          }

          (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0x34c))();

        }

        (**(code **)*piVar2)(1);

      }

    }

    else if (param_2 == 6) {

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      if (DAT_00d1d8dc != (int *)0x0) {

        (**(code **)(*DAT_00d1d8dc + 4))(0);

      }

      if ((*(int *)(param_1 + 0x528) != iVar6) && (0 < iVar6)) {

        (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x158))(0,param_1 + 0x540);

        cVar1 = (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0xf8))();

        if (cVar1 != '\0') {

          *(int *)(*(int *)(param_1 + 0x588 + iVar6 * 4) + 0xf8) =

               (int)(*(float *)(param_1 + 0x54c) * DAT_00aaa6f8);

        }

        (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x34c))();

        (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0x158))(0,param_1 + 0x540);

        cVar1 = (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0xf8))();

        if (cVar1 != '\0') {

          *(int *)(*(int *)(param_1 + 0x5b0 + iVar6 * 4) + 0xf8) =

               (int)(*(float *)(param_1 + 0x54c) * DAT_00aaa6f8);

        }

        (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0x34c))();

      }

    }

    else if ((param_2 == 8) && (0 < iVar6)) {

      *(int *)(param_1 + 0x528) = iVar6;

      puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b4);

      iStack_30 = 4;

      do {

        (**(code **)(*(int *)puVar7[-10] + 0x158))(0,param_1 + 0x540);

        (**(code **)(*(int *)puVar7[-10] + 0x34c))();

        (**(code **)(*(int *)*puVar7 + 0x158))(0,param_1 + 0x540);

        (**(code **)(*(int *)*puVar7 + 0x34c))();

        puVar7 = puVar7 + 1;

        iStack_30 = iStack_30 + -1;

      } while (iStack_30 != 0);

      (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x158))(0,param_1 + 0x550);

      (**(code **)(**(int **)(param_1 + 0x588 + iVar6 * 4) + 0x34c))();

      (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0x158))(0,param_1 + 0x550);

      (**(code **)(**(int **)(param_1 + 0x5b0 + iVar6 * 4) + 0x34c))();

    }

  }

  uVar5 = FUN_0087b500(param_2,param_3);

  return uVar5;

}
