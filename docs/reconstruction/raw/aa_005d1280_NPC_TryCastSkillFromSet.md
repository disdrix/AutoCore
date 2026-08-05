# Raw capture: NPC_TryCastSkillFromSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1280` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d1280` |
| **Canonical name** | `NPC_TryCastSkillFromSet` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* NPC_TryCastSkillFromSet(this, nSkillSetIndex)
   
   AI skill selection + cast for NPCs (called from CVOGHBAIDriver_DoLogic).
   
   Parameters:
     this            - AI skill-set controller (owner at +0x64, cast-cooldown map at +0x9c)
     nSkillSetIndex  - which skill bank / set key (char map key + int map key for post-cast CD)
   
   Algorithm:
     1. If post-cast timer for this set still active (map+0x9c), return early
     2. Require Skill_LocalCastValidate ok AND world is server/sim (owner world+0x7e)
     3. Optional random gate using this+0x08 (cast chance)
     4. Lookup skill vector for set index; walk entries (NPCSkillSetEntry, stride 0x18)
     5. Filter by HP ratio band [flHpRatioMin, flHpRatioMax] vs curHP/maxHP
     6. Skip if casting flag skill+0x628 or category CD remaining
     7. Resolve target TFID (self / selected / skill targeting flags at +0x614)
     8. Skill_ResolveTargetList + Skill_LocalRangeTargetCheck + Skill_ValidateTargetForSkill
     9. CVOGReaction_CastSkillOnTarget; insert post-cast timer = now + usPostCastDelayMs
   
   Returns: inferred cast-result pointer / null (uncertain exact type).
   
   INFERRED: skill-set entry layout, flag bit meanings, this offsets — not PDB-verified. */

void * __thiscall NPC_TryCastSkillFromSet(void *this,int nSkillSetIndex)

{
  uint *puVar1;
  undefined4 uVar2;
  bool bCmp;
  int *pResult;
  int pSkillRuntime;
  int nSkillFlags;
  uint uVar3;
  int nTemp;
  int pOwnerBase;
  undefined4 uVar4;
  void *pCaster;
  NPCSkillSetEntry *pEntry;
  int *unaff_ESI;
  int *unaff_EDI;
  void *pvVar5;
  float10 flCdRemain;
  bool bDidCast;
  bool bCapturedThreatSkill;
  bool bSlotTimerReady;
  char cStack_68f;
  char cStack_68e;
  char cStack_68d;
  void *pCastTimerNode;
  float pSkillSetNode;
  int pEntryScratch;
  NPCSkillSetEntry *pNStack_680;
  int nEntryCursor;
  uint nResolveFlags [2];
  int *nSkillParam0x28;
  undefined4 flHpRatio;
  float fStack_668;
  int nCooldownDeadline;
  int iStack_660;
  undefined1 auStack_65c [16];
  TFID_16 targetTfid_hi [100];
  byte bBlockedByState;
  double dblCastChance;
  ushort usRandom;
  
  Map_LowerBoundFindByIntKey((void *)((int)this + 0x98),&pCastTimerNode,&nSkillSetIndex,unaff_EDI);
  if (pCastTimerNode != *(void **)((int)this + 0x9c)) {
    if (g_dwClientTickMs <= *(uint *)((int)pCastTimerNode + 0x10)) {
      return pCastTimerNode;
    }
    Map_EraseNode_IntKey((void *)((int)this + 0x98),nResolveFlags,pCastTimerNode,unaff_EDI);
  }
  pResult = (int *)Skill_LocalCastValidate
                             ((void *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                      *(int *)((int)this + 100)),(void *)0x0,'\0',(void *)0x0);
  if ((pResult == (int *)0x0) &&
     (pResult = *(int **)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 0xa8 +
                         *(int *)((int)this + 100)), *(char *)((int)pResult + 0x7e) != '\0')) {
    if ((*(byte *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 0xb8 +
                  *(int *)((int)this + 100)) & 0x80) != 0) {
      pSkillRuntime = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(pSkillRuntime + 0xc)) {
        *(undefined4 *)(pSkillRuntime + 0xc) = 0;
      }
      usRandom = *(ushort *)(*(int *)(pSkillRuntime + 8) + *(int *)(pSkillRuntime + 0xc) * 2);
      *(int *)(pSkillRuntime + 0xc) = *(int *)(pSkillRuntime + 0xc) + 1;
      nSkillFlags = (int)usRandom;
      pSkillSetNode = (float)((uint)nSkillFlags % 100);
      dblCastChance = (double)*(int *)((int)this + 8);
      if (*(int *)((int)this + 8) < 0) {
        dblCastChance = dblCastChance + _DAT_00aaa728;
      }
      if (_DAT_009da970 - dblCastChance * _DAT_00aaaaa8 * _DAT_009da978 < (double)(int)pSkillSetNode
         ) {
        return (void *)((uint)nSkillFlags / 100);
      }
    }
    pSkillRuntime = *(int *)((int)this + 100);
    cStack_68f = (char)nSkillSetIndex;
                    /* INFERRED: flHpRatio = currentHP/maxHP via vtable +0x23c / +0x244 */
    Map_LowerBoundFindByCharKey
              ((void *)(*(int *)(*(int *)(*(int *)(*(int *)(pSkillRuntime + 4) + 4) + 0xac +
                                         pSkillRuntime) + 0x3c) + 0x51c),&pEntryScratch,&cStack_68f,
               (char *)unaff_ESI);
    pResult = *(int **)(*(int *)(*(int *)(*(int *)(pSkillRuntime + 4) + 4) + 0xac + pSkillRuntime) +
                       0x3c);
    if (pEntryScratch != pResult[0x148]) {
      cStack_68f = '\0';
      pSkillSetNode = (float)g_nInferredThreatDefault;
      cStack_68e = '\0';
      uVar3 = AI_CheckSlotTimerReady(this,(void *)0x2,(uint)unaff_ESI);
      cStack_68d = (char)uVar3;
      nTemp = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                   *(int *)((int)this + 100)) + 0x19c))();
      pOwnerBase = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                        *(int *)((int)this + 100)) + 0x19c))();
      pSkillRuntime = *(int *)(*(int *)(pOwnerBase + 4) + 4);
      nTemp = (**(code **)(*(int *)(*(int *)(*(int *)(nTemp + 4) + 4) + 4 + nTemp) + 0x23c))();
      pNStack_680 = (NPCSkillSetEntry *)(float)nTemp;
      pSkillRuntime = (**(code **)(*(int *)(pSkillRuntime + 4 + pOwnerBase) + 0x244))();
      fStack_668 = (float)pNStack_680 / (float)pSkillRuntime;
      pSkillRuntime = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(pSkillRuntime + 0xc)) {
        *(undefined4 *)(pSkillRuntime + 0xc) = 0;
      }
                    /* Stack reuse: bDidCast temporarily holds (char)nSkillSetIndex as map key for
                       skill-set lookup, then reset to false for cast-success flag. */
      usRandom = *(ushort *)(*(int *)(pSkillRuntime + 8) + *(int *)(pSkillRuntime + 0xc) * 2);
      *(int *)(pSkillRuntime + 0xc) = *(int *)(pSkillRuntime + 0xc) + 1;
      pvVar5 = (void *)(pEntryScratch + 0x10);
      nResolveFlags[0] = SkillSet_GetEntryCount(pvVar5);
      nResolveFlags[0] = (uint)usRandom % nResolveFlags[0];
      nSkillParam0x28 = (int *)0x0;
      while( true ) {
        pResult = (int *)0x0;
        if ((*(int *)((int)pvVar5 + 4) == 0) ||
           (pResult = (int *)((*(int *)((int)pvVar5 + 8) - *(int *)((int)pvVar5 + 4)) / 0x18),
           pResult <= nSkillParam0x28)) break;
        pEntry = (NPCSkillSetEntry *)(*(int *)(pEntryScratch + 0x14) + nResolveFlags[0] * 0x18);
        pNStack_680 = pEntry;
        pvVar5 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4)
                                               + 4 + *(int *)((int)this + 100)) + 0x234))
                                   (pEntry->nSkillId);
        if (pvVar5 == (void *)0x0) {
          Skill_EnsureLoadedInTree
                    ((void *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                             *(int *)((int)this + 100)),pEntry->nSkillId,pEntry->nSRank);
          pvVar5 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) +
                                                         4) + 4 + *(int *)((int)this + 100)) + 0x234
                                       ))(pEntry->nSkillId);
          if (pvVar5 != (void *)0x0) goto skill_entry_ready_check;
        }
        else {
skill_entry_ready_check:
                    /* Filter NPCSkillSetEntry by HP ratio [min,max]; skip if skill casting or
                       category CD */
          if ((fStack_668 < pEntry->flHpRatioMax || fStack_668 == pEntry->flHpRatioMax) &&
             (pEntry->flHpRatioMin <= fStack_668)) {
            if ((cStack_68d != '\0') &&
               ((((*(byte *)((int)pvVar5 + 0x614) & 8) != 0 || (*(int *)((int)pvVar5 + 0x60c) == 2))
                && (cStack_68e == '\0')))) {
              pSkillSetNode = *(float *)((int)pvVar5 + 0x28);
              cStack_68e = '\x01';
            }
            if (((cStack_68f == '\0') && (*(char *)((int)pvVar5 + 0x628) == '\0')) &&
               ((Skill_GetCategoryCooldownRemaining
                           (*(float10 **)((int)pvVar5 + 0x5e8),1,(char)unaff_ESI),
                (float10)g_flZero == flCdRemain &&
                (uVar3 = *(uint *)((int)pvVar5 + 0x614), (uVar3 & 0x100) == 0)))) {
              pSkillRuntime = *(int *)((int)this + 100);
              nTemp = *(int *)(*(int *)(pSkillRuntime + 4) + 4);
              if ((*(byte *)((int)pvVar5 + 0x624) & 1) == 0) {
                bBlockedByState = *(byte *)(nTemp + 0xb8 + pSkillRuntime) & 8;
              }
              else {
                bBlockedByState = *(byte *)(nTemp + 0xb8 + pSkillRuntime) & 0x10;
              }
              if (bBlockedByState == 0) {
                targetTfid_hi[0].dwCoidLo._0_1_ = g_abTfidInvalid_9DA850[0];
                targetTfid_hi[0].dwCoidLo._1_1_ = g_abTfidInvalid_9DA850[1];
                targetTfid_hi[0].dwCoidLo._2_1_ = g_abTfidInvalid_9DA850[2];
                targetTfid_hi[0].dwCoidLo._3_1_ = g_abTfidInvalid_9DA850[3];
                targetTfid_hi[0].dwCoidHi._0_1_ = g_abTfidInvalid_9DA850[4];
                targetTfid_hi[0].dwCoidHi._1_1_ = g_abTfidInvalid_9DA850[5];
                targetTfid_hi[0].dwCoidHi._2_1_ = g_abTfidInvalid_9DA850[6];
                targetTfid_hi[0].dwCoidHi._3_1_ = g_abTfidInvalid_9DA850[7];
                targetTfid_hi[0].bGlobal = g_abTfidInvalid_9DA850[8];
                targetTfid_hi[0].bPad0 = g_abTfidInvalid_9DA850[9];
                targetTfid_hi[0].bPad1 = g_abTfidInvalid_9DA850[10];
                targetTfid_hi[0].bPad2 = g_abTfidInvalid_9DA850[0xb];
                targetTfid_hi[0].bPad3 = g_abTfidInvalid_9DA850[0xc];
                targetTfid_hi[0].bPad4 = g_abTfidInvalid_9DA850[0xd];
                targetTfid_hi[0].bPad5 = g_abTfidInvalid_9DA850[0xe];
                targetTfid_hi[0].bPad6 = g_abTfidInvalid_9DA850[0xf];
                if ((uVar3 & 8) == 0) {
                  if ((uVar3 & 4) != 0) {
                    if (*(int *)((int)this + 100) == 0) {
                      pCastTimerNode = (void *)0x0;
                    }
                    else {
                      pCastTimerNode =
                           (void *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                   *(int *)((int)this + 100));
                    }
                    flHpRatio = *(undefined4 *)((int)pvVar5 + 0x28);
                    pSkillRuntime = *(int *)((int)this + 100);
                    uVar2 = *(undefined4 *)
                             (*(int *)(*(int *)(pSkillRuntime + 4) + 4) + 0xa8 + pSkillRuntime);
                    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(pSkillRuntime + 4) + 4) + 4 +
                                                 pSkillRuntime) + 0x1a0))
                                      (flHpRatio,1,1,0,
                                       *(uint *)((int)pvVar5 + 0x620) >> 0xe & 0xffffff01,
                                       *(uint *)((int)pvVar5 + 0x620) >> 5 & 0xffffff01,0,1,0,
                                       0xbf800000);
                    Skill_GatherTargetsInArea(targetTfid_hi,0,uVar2,pCastTimerNode,uVar4);
                    pEntry = pNStack_680;
                  }
                }
                else {
                  pSkillRuntime = *(int *)(*(int *)((int)this + 0x18) + 0xa0);
                  if (pSkillRuntime != 0) {
                    targetTfid_hi[0].dwCoidLo = *(uint *)(pSkillRuntime + 0x160);
                    targetTfid_hi[0].dwCoidHi = *(uint *)(pSkillRuntime + 0x164);
                    targetTfid_hi[0]._8_4_ = *(uint *)(pSkillRuntime + 0x168);
                    targetTfid_hi[0]._12_4_ = *(uint *)(pSkillRuntime + 0x16c);
                  }
                }
                if (((*(byte *)((int)pvVar5 + 0x614) & 3) != 0) &&
                   (pSkillRuntime = TFID_EqualsObjectId(targetTfid_hi,g_abTfidInvalid_9DA850),
                   (char)pSkillRuntime != '\0')) {
                  pSkillRuntime =
                       (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) +
                                             4 + *(int *)((int)this + 100)) + 0x19c))();
                  puVar1 = (uint *)(*(int *)(*(int *)(pSkillRuntime + 4) + 4) + 0x164 +
                                   pSkillRuntime);
                  targetTfid_hi[0].dwCoidLo = *puVar1;
                  targetTfid_hi[0].dwCoidHi = puVar1[1];
                  targetTfid_hi[0]._8_4_ = puVar1[2];
                  targetTfid_hi[0]._12_4_ = puVar1[3];
                }
                pSkillRuntime = TFID_NotEquals(targetTfid_hi,g_abTfidInvalid_9DA850);
                if ((char)pSkillRuntime != '\0') {
                  pCastTimerNode = Object_ResolveFromTFID(targetTfid_hi);
                  pSkillRuntime = 0;
                  nResolveFlags[1] = 0;
                  if (*(int *)((int)this + 100) != 0) {
                    pSkillRuntime =
                         *(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                         *(int *)((int)this + 100);
                  }
                  Skill_ResolveTargetList
                            (targetTfid_hi,
                             *(undefined4 *)
                              (*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 0xa8 +
                              *(int *)((int)this + 100)),pSkillRuntime,targetTfid_hi[0].dwCoidLo,
                             targetTfid_hi[0].dwCoidHi,targetTfid_hi[0]._8_4_,
                             targetTfid_hi[0]._12_4_,g_abInferredDefaultAimPos,nResolveFlags + 1);
                  pSkillRuntime = TFID_NotEquals(targetTfid_hi,g_abTfidInvalid_9DA850);
                  if (((char)pSkillRuntime != '\0') && (pCastTimerNode != (void *)0x0)) {
                    if (*(int *)((int)this + 100) == 0) {
                      pCaster = (void *)0x0;
                    }
                    else {
                      pCaster = (void *)(*(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                                        *(int *)((int)this + 100));
                    }
                    pSkillRuntime =
                         Skill_LocalRangeTargetCheck(pvVar5,pCaster,(void *)0x0,(void *)0x0);
                    if ((pSkillRuntime == 0) &&
                       ((((*(byte *)((int)pvVar5 + 0x614) & 1) != 0 &&
                         (*(float *)((int)pvVar5 + 0x38) != g_flZero)) ||
                        (pSkillRuntime =
                              Skill_ValidateTargetForSkill(pvVar5,pCastTimerNode,(void *)0x0),
                        (char)pSkillRuntime != '\0')))) {
                      if (*(int *)((int)this + 100) == 0) {
                        pSkillRuntime = 0;
                      }
                      else {
                        pSkillRuntime =
                             *(int *)(*(int *)(*(int *)((int)this + 100) + 4) + 4) + 4 +
                             *(int *)((int)this + 100);
                      }
                      CVOGReaction_CastSkillOnTarget
                                (pvVar5,pSkillRuntime,pCastTimerNode,1,targetTfid_hi,auStack_65c,0,
                                 0xffffffff,0,0);
                      iStack_660 = pEntry->wUsPostCastDelayMs + g_dwClientTickMs;
                      nCooldownDeadline = nSkillSetIndex;
                      Map_InsertOrFind_IntKey
                                ((void *)((int)this + 0x98),&pNStack_680,&nCooldownDeadline,
                                 unaff_ESI);
                      cStack_68f = '\x01';
                    }
                  }
                }
              }
            }
          }
        }
        pvVar5 = (void *)(pEntryScratch + 0x10);
        uVar3 = 0;
        if (*(int *)(pEntryScratch + 0x14) != 0) {
          uVar3 = (*(int *)(pEntryScratch + 0x18) - *(int *)(pEntryScratch + 0x14)) / 0x18;
        }
        nResolveFlags[0] = -(uint)(nResolveFlags[0] + 1 < uVar3) & nResolveFlags[0] + 1;
        nSkillParam0x28 = (int *)((int)nSkillParam0x28 + 1);
      }
      if (cStack_68e != '\0') {
        pSkillRuntime = *(int *)(*(int *)((int)this + 100) + 0x250);
        pResult = (int *)0x0;
        if ((pSkillRuntime == 0) ||
           ((pResult = *(int **)(pSkillRuntime + 0x260), *pResult == 0 && (pResult[1] == 0)))) {
          *(float *)(*(int *)((int)this + 100) + 0x124) = pSkillSetNode * g_flInferredThreatScale;
        }
      }
    }
  }
  return pResult;
}
```
