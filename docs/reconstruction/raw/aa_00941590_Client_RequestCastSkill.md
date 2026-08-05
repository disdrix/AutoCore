# Raw capture: Client_RequestCastSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00941590` |
| **Canonical name** | `Client_RequestCastSkill` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_RequestCastSkill — C2S 0x2030 size 0x28 Confirmed (WI-SKL-001).\nLayout: +0 msgId
   0x2030; +4 pad; +8 target TFID 16B (from Skill_ResolveTarget/FUN_0093b3a0); +0x18 skillId (stack
   skill arg / skill+0x5fc on QB path); +0x1C aim float3 (pAimPos).\nFlow: lookup skill
   (rank@+0x5f6), LocalCastValidate, resolve TFID, optional cast-again HB if world+0x7e==0 &&
   skill+0x61c==0, SendSectorPacket, QB UI +0x450.\nAlso QB builder Client_QuickBarActivateSkillSlot
   0x00921b50. */

void Client_RequestCastSkill(int nSkillId,int a2,int a3,int a4,int a5,void *pAimPos)

{
  char cVar1;
  void *in_EAX;
  void *pOwnerCtx;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  void *pA;
  void *pA_00;
  void *pvVar6;
  int unaff_EBX;
  undefined4 unaff_retaddr;
  byte *pbVar7;
  undefined4 auStack_13c [2];
  int iStack_134;
  int iStack_130;
  int iStack_12c;
  int iStack_128;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined1 auStack_114 [16];
  char acStack_104 [260];
  
  pvVar6 = pAimPos;
  if (((*(int *)((int)in_EAX + 0xe98) != 0) &&
      (pOwnerCtx = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 4
                                                                  ) + 4) + 4 +
                                                *(int *)((int)in_EAX + 0xe98)) + 0x234))(nSkillId),
      pOwnerCtx != (void *)0x0)) && (*(short *)((int)pOwnerCtx + 0x5f6) != 0)) {
    iVar2 = Skill_LocalCastValidate
                      ((void *)(*(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 4) + 4) + 4 +
                               *(int *)((int)in_EAX + 0xe98)),(void *)0x0,(char)pOwnerCtx,
                       (void *)0x0);
    if (iVar2 == 0) {
      piVar4 = (int *)Client_Skill_ResolveCastTarget(auStack_114,pOwnerCtx,&nSkillId,pvVar6,1);
      a2 = piVar4[1];
      iVar2 = *piVar4;
      a3 = piVar4[2];
      a4 = piVar4[3];
      nSkillId = iVar2;
      iVar5 = TFID_EqualsObjectId(&nSkillId,g_abTfidInvalid_A15870);
      if ((char)iVar5 == '\0') {
                    /* Skip optimistic cast-again HB when world+0x7e (server/sim mode); inbound
                       SkillStatusEffect creates it instead. */
        if (*(char *)(*(int *)((int)in_EAX + 0xe04) + 0x7e) == '\0') {
          pbVar7 = g_abTfidInvalid_A15870;
          Skill_LookupActiveCastBinding(auStack_114,*(int *)((int)pOwnerCtx + 0x5fc));
          iVar5 = TFID_EqualsObjectId(pA,pbVar7);
          if (((char)iVar5 != '\0') &&
             (Skill_ClearActiveCastCounterAndQueueId(*(int *)((int)pOwnerCtx + 0x5fc)),
             *(char *)((int)pOwnerCtx + 0x61c) == '\0')) {
                    /* Skill_StartCastAgainHeartbeat(skill, chargeDelay) — starts hotbar cooldown
                       before 0x2030 is sent. */
            Skill_StartCastAgainHeartbeat
                      ((void *)(*(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 4) + 4) + 4 +
                               *(int *)((int)in_EAX + 0xe98)),pOwnerCtx,
                       (void *)(int)*(short *)((int)pOwnerCtx + 0x14),unaff_EBX);
          }
        }
        if (0 < *(short *)((int)pOwnerCtx + 0x14)) {
          pbVar7 = g_abTfidInvalid_A15870;
          Skill_LookupActiveCastBinding(auStack_114,*(int *)((int)pOwnerCtx + 0x5fc));
          iVar5 = TFID_EqualsObjectId(pA_00,pbVar7);
          if ((char)iVar5 != '\0') {
            (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 4) + 4) + 4 +
                                 *(int *)((int)in_EAX + 0xe98)) + 0x238))
                      (3,unaff_retaddr,
                       (int)(short)(*(short *)((int)pOwnerCtx + 0x174) +
                                   *(short *)((int)pOwnerCtx + 0x5f6)),0,0,0,0,0);
            FUN_007fb690(0,(float)(int)*(short *)((int)pOwnerCtx + 0x14) * g_flMsToSeconds_Inferred,
                         (int)pOwnerCtx + 0x184,"...Activating Skill...",DAT_00afdf08,0xff400000,0,0
                        );
          }
        }
        uStack_120 = *(undefined4 *)pvVar6;
        iStack_130 = a2;
        uStack_11c = *(undefined4 *)((int)pvVar6 + 4);
        iStack_12c = a3;
        uStack_118 = *(undefined4 *)((int)pvVar6 + 8);
        auStack_13c[0] = 0x2030;
        iStack_128 = a4;
        iStack_134 = iVar2;
        Client_SendSectorPacket(in_EAX,0x28,auStack_13c);
        piVar4 = *(int **)((int)in_EAX + 0x10b0);
        if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0x3d8))(), cVar1 != '\0')) {
          (**(code **)(*piVar4 + 0x450))(pOwnerCtx);
        }
        if (((0 < *(short *)((int)pOwnerCtx + 8)) || (g_flZero < *(float *)((int)pOwnerCtx + 0x44)))
           || (0 < *(short *)((int)pOwnerCtx + 10))) {
          Client_MaybeShowFirstTimeTip(0x23);
        }
      }
    }
    else {
      if (*(int *)((int)in_EAX + 0xe98) == 0) {
        pvVar6 = (void *)0x0;
      }
      else {
        pvVar6 = (void *)(*(int *)(*(int *)(*(int *)((int)in_EAX + 0xe98) + 4) + 4) + 4 +
                         *(int *)((int)in_EAX + 0xe98));
      }
      pcVar3 = Skill_FormatFailureMessage(iVar2,acStack_104,pvVar6);
      if (DAT_00d1b8dc != 0) {
        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,pcVar3,0);
        return;
      }
    }
  }
  return;
}
```
