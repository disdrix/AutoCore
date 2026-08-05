// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×9, return×3.
//  - Notable callees: FUN_007a6de0×5, Mission_ComputeObjectiveCredits×3, sprintf×3, FUN_004111d0×2, FUN_008f8200×2, Mission_ComputeObjectiveXp×2, CNDHash_LookupByKey, Client_EnqueueCombatFloater_INFERRED.
//  - Strings: "Awarded N ..."; "Earned N clink"; "Awarded"; "%s %d %s.".
//  - Return sites: 3.

// =============================================================================
// Client_ShowMissionRewardChatToast
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac540
// Address:   0x008ac540  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 human-refined from raw capture
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * After mission turn-in: format XP/credits chat lines ('Awarded N …', 'Earned N clink', or already-received) and push to chat UI.
 *
 * Notes:
 * - Objective+0x14c mission def; missionId short at def+0xac (index 0x2b) must not be -1 for completed path.
 * - CNDHash_LookupByKey(char+0x538, missionId) - if found, already-received branch.
 * - Else Mission_ComputeObjectiveXp + FUN_0051f510 scaler; clamp with FUN_004111d0 level cap when char+0x6b4<1.
 * - Credits path uses Mission_ComputeObjectiveCredits (continues in raw beyond head).
 * - Chat push FUN_008f8200(DAT_00d1b8dc, 6, …) and floater colors from DAT_00a1e398 family.
 */

void Client_ShowMissionRewardChatToast(void *pObjective)
{
    (void)pObjective;
    /* XP/credits toast or already-received - see raw; uses Mission_ComputeObjectiveXp/Credits */
}

// ---- Full decompiler body (width-normalized; human notes above) ----
/* Client_ShowMissionRewardChatToast

   

   After turn-in button: format XP/credits chat lines ("Awarded N ...", "Earned N clink",

   or already-received message) and push to chat UI. */



void Client_ShowMissionRewardChatToast(void *param_1)



{

  uint *puVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* decomp width */ uVar4;

  int iVar5;

  uint32_t /* decomp width */ uVar6;

  long double /* x87 */ fVar7;

  uint32_t /* decomp width */ local_138;

  uint32_t /* decomp width */ local_134;

  uint32_t /* decomp width */ local_130;

  uint32_t /* decomp width */ local_12c;

  uint32_t /* decomp width */ local_128;

  uint32_t /* decomp width */ local_124;

  uint32_t /* decomp width */ local_120;

  uint32_t /* decomp width */ local_11c;

  int local_118;

  uint8_t local_110;

  uint32_t /* decomp width */ local_108;

  char local_100 [256];

  

  if (param_1 != (void *)0x0) {

    FUN_007a69d0();

    puVar1 = *(uint **)((int)param_1 + 0x14c);

    if ((((puVar1 == (uint *)0x0) || ((short)puVar1[0x2b] == -1)) || (DAT_00d1b6d8 == 0)) ||

       ((*(void **)(DAT_00d1b6d8 + 0x538) == (void *)0x0 ||

        (pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x538),*puVar1),

        pvVar2 == (void *)0x0)))) {

      iVar3 = Mission_ComputeObjectiveXp(param_1);

      if ((0 < iVar3) &&

         ((DAT_00d1b6d8 != 0 &&

          (*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8) != 0)))) {

        fVar7 = (long double /* x87 */)FUN_0051f510(param_1);

        iVar3 = FUN_0040dab0((float)fVar7);

        if ((*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) && (iVar5 = FUN_004111d0(), iVar5 <= iVar3)) {

          iVar3 = FUN_004111d0();

        }

        if (iVar3 != 0) {

          uVar4 = FUN_007a6de0(&DAT_00a43258,0xffffffff);

          iVar5 = iVar3;

          uVar6 = FUN_007a6de0("Awarded",0xffffffff);

          sprintf(local_100,"%s %d %s.",uVar6,iVar5,uVar4);

          if (DAT_00d1b8dc != 0) {

            FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);

          }

          local_130 = DAT_00a1e3a0;

          local_138 = DAT_00a1e398;

          local_134 = DAT_00a1e39c;

          local_12c = DAT_00a1e3a4;

          iVar5 = DAT_00d1b6d8 + *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

          local_128 = *(uint32_t /* decomp width */ *)(iVar5 + 0x164);

          local_124 = *(uint32_t /* decomp width */ *)(iVar5 + 0x168);

          local_120 = *(uint32_t /* decomp width */ *)(iVar5 + 0x16c);

          local_11c = *(uint32_t /* decomp width */ *)(iVar5 + 0x170);

          local_108 = 3;

          local_110 = 0;

          local_118 = iVar3;

          Client_EnqueueCombatFloater_INFERRED(&local_138);

        }

      }

      iVar3 = Mission_ComputeObjectiveCredits(param_1);

      if (iVar3 < 1) {

        return;

      }

      uVar4 = FUN_007a6de0("clink",0xffffffff);

      iVar3 = Mission_ComputeObjectiveCredits(param_1);

      uVar6 = FUN_007a6de0("Earned",0xffffffff);

      sprintf(local_100,"%s %d %s.",uVar6,iVar3,uVar4);

    }

    else {

      iVar3 = Mission_ComputeObjectiveXp(param_1);

      if ((iVar3 < 1) && (iVar3 = Mission_ComputeObjectiveCredits(param_1), iVar3 < 1)) {

        return;

      }

      uVar4 = FUN_007a6de0("(You have already received this mission\'s rewards)",0xffffffff);

      sprintf(local_100,"%s",uVar4);

    }

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);

    }

  }

  return;

}
