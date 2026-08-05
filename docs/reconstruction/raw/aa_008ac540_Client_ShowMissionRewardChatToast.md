# Raw capture: Client_ShowMissionRewardChatToast

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac540` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ac540` |
| **Canonical name** | `Client_ShowMissionRewardChatToast` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_ShowMissionRewardChatToast
   
   After turn-in button: format XP/credits chat lines ("Awarded N ...", "Earned N clink",
   or already-received message) and push to chat UI. */

void Client_ShowMissionRewardChatToast(void *param_1)

{
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  float10 fVar7;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  int local_118;
  undefined1 local_110;
  undefined4 local_108;
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
        fVar7 = (float10)FUN_0051f510(param_1);
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
          local_128 = *(undefined4 *)(iVar5 + 0x164);
          local_124 = *(undefined4 *)(iVar5 + 0x168);
          local_120 = *(undefined4 *)(iVar5 + 0x16c);
          local_11c = *(undefined4 *)(iVar5 + 0x170);
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
```
