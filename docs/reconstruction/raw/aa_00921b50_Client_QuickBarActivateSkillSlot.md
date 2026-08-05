# Raw capture: Client_QuickBarActivateSkillSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00921b50` |
| **Canonical name** | `Client_QuickBarActivateSkillSlot` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_QuickBarActivateSkillSlot — builds C2S RequestCastSkill 0x2030 size 0x28 (WI-SKL-001
   Confirmed).\nPacket at send (conn vtable+0x18): +0=0x2030; +4 pad; +8 TFID16 from FUN_0093b3a0;
   +0x18=skill+0x5fc; +0x1C aim XYZ (often 0).\nNote: LEA buf after PUSH size/flag → recompute
   ESP; opcode store is 8B before resolve[0]. */

void Client_QuickBarActivateSkillSlot(char nSlotIndex)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int pCharacter;
  void *pOwnerCtx;
  int pSkill;
  undefined4 *puVar4;
  int unaff_EDI;
  int iStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_48 [16];
  undefined4 auStack_38 [2];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  piVar1 = *(int **)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8);
  if ((piVar1 != (int *)0x0) && (pCharacter = (**(code **)(*piVar1 + 0x1d8))(), pCharacter != 0)) {
    pSkill = *(int *)(*(int *)(pCharacter + 4) + 4) + pCharacter;
    uStack_70 = *(undefined4 *)(pSkill + 0x164);
    uStack_6c = *(undefined4 *)(pSkill + 0x168);
    uStack_68 = *(undefined4 *)(pSkill + 0x16c);
    uStack_64 = *(undefined4 *)(pSkill + 0x170);
    iVar2 = *(int *)(pSkill + 0xa4);
    if (iVar2 != 0) {
      uStack_70 = *(undefined4 *)(iVar2 + 0x160);
      uStack_6c = *(undefined4 *)(iVar2 + 0x164);
      uStack_68 = *(undefined4 *)(iVar2 + 0x168);
      uStack_64 = *(undefined4 *)(iVar2 + 0x16c);
    }
    pSkill = *(int *)(pSkill + 0x74);
    iStack_78 = 0;
    iStack_74 = 0;
    if (*(char *)(pSkill + 0x1d) != '\0') {
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    *(undefined1 *)(pSkill + 0x1d) = 1;
    pOwnerCtx = (void *)FUN_00411900(&iStack_74);
    pSkill = iStack_74;
    while (pOwnerCtx != (void *)0x0) {
      if ((*(byte *)((int)pOwnerCtx + 0x615) & 1) == 0) {
        if (iStack_78 == nSlotIndex) break;
        iStack_78 = iStack_78 + 1;
      }
      iVar2 = *(int *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 0x74 + pCharacter);
      if (*(char *)(iVar2 + 0x1d) == '\0') {
        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0,"VOG_DEBUG_STOP");
      }
      if (pSkill == 0) {
        pSkill = *(int *)(iVar2 + 0x14);
      }
      else {
        pSkill = *(int *)(pSkill + 0x14);
      }
      if (pSkill == 0) {
        pOwnerCtx = (void *)0x0;
      }
      else {
        pOwnerCtx = *(void **)(pSkill + 8);
      }
    }
    *(undefined1 *)(*(int *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 0x74 + pCharacter) + 0x1d) = 0
    ;
    if ((pOwnerCtx != (void *)0x0) &&
       (pSkill = Skill_LocalCastValidate
                           ((void *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 4 + pCharacter),
                            (void *)0x0,(char)pOwnerCtx,(void *)0x0), pSkill == 0)) {
      pSkill = *(int *)((int)pOwnerCtx + 0x5fc);
      if ((*(char *)(*(int *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 0xa8 + pCharacter) + 0x7e) ==
           '\0') &&
         (Skill_ClearActiveCastCounterAndQueueId(pSkill), *(char *)((int)pOwnerCtx + 0x61c) == '\0')
         ) {
        Skill_StartCastAgainHeartbeat
                  ((void *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 4 + pCharacter),pOwnerCtx,
                   (void *)(int)*(short *)((int)pOwnerCtx + 0x14),unaff_EDI);
      }
      if (*(short *)((int)pOwnerCtx + 0x14) != 0) {
        (**(code **)(*(int *)(*(int *)(*(int *)(pCharacter + 4) + 4) + 4 + pCharacter) + 0x238))
                  (3,pSkill,(int)(short)(*(short *)((int)pOwnerCtx + 0x5f6) +
                                        *(short *)((int)pOwnerCtx + 0x174)),
                   (int)*(short *)((int)pOwnerCtx + 0x14),0,0,0,0);
      }
      uStack_14 = 0;
      uStack_18 = 0;
      uStack_1c = 0;
      auStack_38[0] = 0x2030;
      iStack_20 = pSkill;
      puVar4 = (undefined4 *)
               Client_Skill_ResolveCastTarget(auStack_48,pOwnerCtx,&uStack_70,&DAT_00d1a640,1);
      uStack_30 = *puVar4;
      uStack_2c = puVar4[1];
      uStack_28 = puVar4[2];
      uStack_24 = puVar4[3];
      uStack_1c = uStack_60;
      uStack_18 = uStack_5c;
      uStack_14 = uStack_58;
      if (g_pSectorNetConnection_INFERRED != (void *)0x0) {
        (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,auStack_38,0x28,0);
      }
      if ((DAT_00d1b8f0 != (int *)0x0) &&
         (cVar3 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar3 != '\0')) {
        FUN_0089ff80();
      }
    }
  }
  return;
}
```
