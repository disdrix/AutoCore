// =============================================================================
// FUN_008aa760 — Client_MissionDialog_FillRewardChrome (Tentative product name)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa760
// Address:   0x008aa760  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; dual residual seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual: reviews/A_aa_008aa760_DialogRewardChrome.md
//       reviews/B_aa_008aa760_DialogRewardChrome.md
// =============================================================================
//
// PURPOSE:
//   Mission dialog reward chrome. EDI = dialog host (caller MOV EDI,EBX).
//   First store: *(uint8_t*)(dialog+0x64c) = turnInFlag  // MOV [EDI+0x64c],AL
//   Clears selected reward TFID +0x578/+0x57c = -1 and count +0x514 = 0.
//   Binds up to 4 reward TFIDs from param_1 into dialog+0x558[]; resolves each;
//   shows/hides slot widgets; sets header/hint/banner strings from (count, flag).
//   Single resolved + turn-in → FUN_008aa3f0(0) auto-selects slot 0 → +0x578/57c.
//
// CALLER (sole): Client_ShowNpcMissionDialogUI @ 0x009438f0 (call 0x00943b6b)
//   push turnInFlag (0/1); push 4; push rewardRegion; mov edi, dialog; call
//
// Embedded strings:
//   ".dds"
//   "You Will Receive:" / "Your Reward:"
//   "You Will Get To Choose From:" / "Select A Reward:"
//   "You must choose a reward item first"
//   "Mission Complete!" / "… You receive:" / "… Select a reward:"
//   DAT_00a1419b = empty C-string (multi-offer hint clear)
//
// Does NOT: send packets; write +0x510 chrome mode; write +0x648 button router.
//
// Calling convention note:
//   unaff_EDI is dialog this (not a free register). param_3 is a stack byte.

/*
 * Behavioral notes:
 * - Live Ghidra 2026-07-29 ≡ raw; clean CF preserved (no deleted branches).
 * - 0x3f000000 show-alpha args are IEEE 0.5f.
 * - Runtime / differential verification: OPEN.
 */

void FUN_008aa760(int param_1,int param_2,uint8_t param_3)



{

  int iVar1;

  int *piVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int *piVar8;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar9;

  size_t _Count;

  char acStack_80 [128];

  

  FUN_007a69d0();

  iVar7 = 0;

  *(uint8_t *)(unaff_EDI + 0x64c) = param_3;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x578) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x57c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x514) = 0;

  if ((param_2 != 0) && (param_1 != 0)) {

    if (0 < param_2) {

      puVar6 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 0x558);

      piVar8 = (int *)(unaff_EDI + 0x698);

      do {

        if (3 < iVar7) break;

        *puVar6 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar7 * 8);

        puVar6[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar7 * 8);

        piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                                  (1,*(uint32_t /* width from decompiler */ *)(param_1 + iVar7 * 8),

                                   *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar7 * 8));

        if (piVar2 == (int *)0x0) {

          if ((int *)piVar8[4] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[4] + 4))(0);

          }

          if ((int *)*piVar8 != (int *)0x0) {

            (**(code **)(*(int *)*piVar8 + 4))(0);

          }

          if ((int *)piVar8[8] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[8] + 4))(0);

          }

          if ((int *)piVar8[0xc] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[0xc] + 4))(0);

          }

        }

        else {

          if (piVar8[4] != 0) {

            _Count = 0x80;

            pcVar3 = (char *)(**(code **)(*piVar2 + 0x1c4))();

            strncpy(acStack_80,pcVar3,_Count);

            strncat(acStack_80,".dds",0x80);

            (**(code **)(*(int *)piVar8[4] + 0x50))(acStack_80,1,0);

            (**(code **)(*(int *)piVar8[4] + 0xfc))(1,0x3f000000);

          }

          if ((int *)piVar8[0xc] != (int *)0x0) {

            (**(code **)(*(int *)piVar8[0xc] + 0xfc))(1,0x3f000000);

          }

          if ((int *)*piVar8 != (int *)0x0) {

            (**(code **)(*(int *)*piVar8 + 0x158))(0,unaff_EDI + 0x594);

            (**(code **)(*(int *)*piVar8 + 0xfc))(1,0x3f000000);

          }

          if ((int *)piVar8[8] != (int *)0x0) {

            iVar1 = *(int *)piVar8[8];

            uVar4 = (**(code **)(*piVar2 + 0x15c))(1,1);

            (**(code **)(iVar1 + 0x1d8))(uVar4);

            (**(code **)(*(int *)piVar8[8] + 0xfc))(1,0x3f000000);

          }

          *(int *)(unaff_EDI + 0x514) = *(int *)(unaff_EDI + 0x514) + 1;

        }

        puVar6 = puVar6 + 2;

        iVar7 = iVar7 + 1;

        piVar8 = piVar8 + 1;

      } while (iVar7 < param_2);

    }

    if (*(int *)(unaff_EDI + 0x514) == 1) {

      if (*(char *)(unaff_EDI + 0x64c) != '\0') {

        FUN_008aa3f0(0);

      }

      if (*(int **)(unaff_EDI + 0x690) != (int *)0x0) {

        (**(code **)(**(int **)(unaff_EDI + 0x690) + 0xfc))(1,0x3f000000);

        uVar9 = 1;

        uVar4 = 1;

        if (*(char *)(unaff_EDI + 0x64c) == '\0') {

          iVar7 = **(int **)(unaff_EDI + 0x690);

          pcVar3 = "You Will Receive:";

        }

        else {

          iVar7 = **(int **)(unaff_EDI + 0x690);

          pcVar3 = "Your Reward:";

        }

        uVar5 = FUN_007a6de0(pcVar3,0xffffffff);

        (**(code **)(iVar7 + 0x1d8))(uVar5,uVar4,uVar9);

        (**(code **)(**(int **)(unaff_EDI + 0x690) + 0x34c))();

      }

    }

    else {

      piVar8 = *(int **)(unaff_EDI + 0x690);

      if (*(int *)(unaff_EDI + 0x514) < 2) {

        if (piVar8 != (int *)0x0) {

          (**(code **)(*piVar8 + 4))(0);

        }

      }

      else {

        if (piVar8 != (int *)0x0) {

          (**(code **)(*piVar8 + 0xfc))(1,0x3f000000);

          uVar9 = 1;

          uVar4 = 1;

          if (*(char *)(unaff_EDI + 0x64c) == '\0') {

            iVar7 = **(int **)(unaff_EDI + 0x690);

            pcVar3 = "You Will Get To Choose From:";

          }

          else {

            iVar7 = **(int **)(unaff_EDI + 0x690);

            pcVar3 = "Select A Reward:";

          }

          uVar5 = FUN_007a6de0(pcVar3,0xffffffff);

          (**(code **)(iVar7 + 0x1d8))(uVar5,uVar4,uVar9);

          (**(code **)(**(int **)(unaff_EDI + 0x690) + 0x34c))();

        }

        piVar8 = *(int **)(unaff_EDI + 0x708);

        if (piVar8 != (int *)0x0) {

          if (*(char *)(unaff_EDI + 0x64c) == '\0') {

            (**(code **)(*piVar8 + 0x308))(&DAT_00a1419b);

          }

          else {

            iVar7 = *piVar8;

            uVar4 = FUN_007a6de0("You must choose a reward item first",0xffffffff);

            (**(code **)(iVar7 + 0x308))(uVar4);

          }

        }

      }

    }

  }

  if (*(int **)(unaff_EDI + 0x6e8) != (int *)0x0) {

    uVar9 = 1;

    uVar4 = 1;

    if (*(int *)(unaff_EDI + 0x514) < 2) {

      if (*(int *)(unaff_EDI + 0x514) == 1) {

        pcVar3 = "Mission Complete!  You receive:";

      }

      else {

        pcVar3 = "Mission Complete!";

      }

    }

    else {

      pcVar3 = "Mission Complete!  Select a reward:";

    }

    iVar7 = **(int **)(unaff_EDI + 0x6e8);

    uVar5 = FUN_007a6de0(pcVar3,0xffffffff);

    (**(code **)(iVar7 + 0x1d8))(uVar5,uVar4,uVar9);

    (**(code **)(**(int **)(unaff_EDI + 0x6e8) + 0x34c))();

  }

  return;

}
