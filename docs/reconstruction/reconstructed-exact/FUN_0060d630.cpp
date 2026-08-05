// =============================================================================
// FUN_0060d630 / CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress twin
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d630
// Address:   0x0060d630
// Generated: 2026-08-04 WQ7R-H live decompile
// Product name: CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress
// ABI: __thiscall ret 0x0C; AL 0|1
// =============================================================================

undefined4 __thiscall FUN_0060d630(int *param_1,int param_2,int param_3)



{

  undefined4 *puVar1;

  int iVar2;

  char cVar3;

  int unaff_EBX;

  

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xa8 + param_2) + 0x7e) == '\0') {

    return 0;

  }

  cVar3 = (**(code **)(*param_1 + 8))(param_2,param_3);

  if (cVar3 != '\0') {

    return 0;

  }

  if (*(int *)(param_2 + 0x250) == 0) {

    return 0;

  }

  if (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0) {

    if ((param_1[10] != -1) && (cVar3 = FUN_005310a0(param_1[10],1), cVar3 == '\0')) {

      puVar1 = *(undefined4 **)(param_1[1] + 0x14c);

      iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

      FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",param_1[10],

                   *(undefined4 *)(iVar2 + 0x164 + param_2),*(undefined4 *)(iVar2 + 0x168 + param_2)

                   ,*(undefined4 *)(param_1[1] + 0x10),puVar1 + 1,*puVar1);

    }

    *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) =

         *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4) + g_flOne;

    cVar3 = (**(code **)(*param_1 + 8))(param_2,param_3);

    if (((char)param_1[7] != '\0') && ((cVar3 != '\0' || (*(char *)((int)param_1 + 0x25) == '\0'))))

    {

      if (*(char *)((int)param_1 + 0x1d) == '\0') {

        CVOGReaction_RemoveInventoryItem(*(undefined4 *)(*(int *)(unaff_EBX + 0xa8) + 0x34),1);

      }

      else {

        *(uint *)(unaff_EBX + 0xcc) = (*(char *)((int)param_1 + 0x26) != '\0') + 1;

        FUN_004d0e90(unaff_EBX);

      }

    }

    if ((char)param_1[0xc] != '\0') {

      if ((cVar3 == '\0') && (*(char *)((int)param_1 + 0x32) != '\0')) {

        return 1;

      }

      CVOGReaction_RemoveInventoryItem(param_1[0xb],1);

    }

    if (cVar3 != '\0') {

      if (param_1[0x13] != -1) {

        CVOGReaction_GiveMission(param_1[0x13]);

      }

      if ((param_1[0x12] != -1) && (cVar3 = FUN_005310a0(param_1[0x12],1), cVar3 == '\0')) {

        puVar1 = *(undefined4 **)(param_1[1] + 0x14c);

        iVar2 = *(int *)(*(int *)(param_2 + 4) + 4);

        FUN_007a4480(1,"Failed to give item %d to %I64d, objective %d mission: %S(%d)",param_1[0x12]

                     ,*(undefined4 *)(iVar2 + 0x164 + param_2),

                     *(undefined4 *)(iVar2 + 0x168 + param_2),*(undefined4 *)(param_1[1] + 0x10),

                     puVar1 + 1,*puVar1);

      }

    }

    return 1;

  }

  return 0;

}
