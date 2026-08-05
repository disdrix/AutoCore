# Raw capture: Skill_ApplyStatusEffectLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051aa00` |
| **Canonical name** | `Skill_ApplyStatusEffectLocal` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_ApplyStatusEffectLocal(pCasterObj, ..., pPacket, bIsLocalCaster)
   
   Parameters:
     pCasterObj      - resolved source object from packet TFID
     pPacket         - SkillStatusEffect buffer
     bIsLocalCaster  - local character match flag
   
   Algorithm: load/create skill; if item flag use ResolveSkillTargets path;
     if delay<1 apply effects now else spawn active-skill HB;
     may Skill_StartCastAgainHeartbeat when world+0x7e (sim).
   
   Returns: status code (0 or 0x11 cancel) INFERRED
   VERIFIED delay branch and item-skill split. */

int __fastcall
Skill_ApplyStatusEffectLocal(void *pCasterObj,int nInferred,void *pPacket,char bIsLocalCaster)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  CVOGHBBase *this;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  undefined2 extraout_var;
  int unaff_EDI;
  undefined4 uVar7;
  undefined1 *puVar8;
  uint uStack_510;
  undefined1 auStack_50c [4];
  CVOGHBBase *local_508;
  undefined1 auStack_504 [4];
  undefined4 *puStack_500;
  undefined4 local_4fc;
  int local_4f8;
  undefined4 *puStack_4f4;
  uint uStack_4f0;
  uint uStack_4ec;
  int iStack_4e8;
  char cStack_4e4;
  undefined4 uStack_4e0;
  undefined4 uStack_4dc;
  undefined4 uStack_4d8;
  undefined4 uStack_4d4;
  undefined1 local_4d0 [1204];
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a36d2;
  pvStack_1c = ExceptionList;
  local_4f8 = 2;
  if (*(char *)((int)pPacket + 0x38) == '\0') {
    ExceptionList = &pvStack_1c;
    this = (CVOGHBBase *)
           (**(code **)(*(int *)pCasterObj + 0x234))(*(undefined4 *)((int)pPacket + 8));
    local_508 = this;
    if (this == (CVOGHBBase *)0x0) {
      Skill_EnsureLoadedInTree(pCasterObj,*(int *)((int)pPacket + 8),0);
      this = (CVOGHBBase *)
             (**(code **)(*(int *)pCasterObj + 0x234))(*(undefined4 *)((int)pPacket + 8));
      local_508 = this;
      if (this == (CVOGHBBase *)0x0) goto LAB_0051ae9e;
      Skill_SetRankAndReevaluate
                (this,(void *)CONCAT22(extraout_var,*(undefined2 *)((int)pPacket + 0xc)),
                 (short)unaff_EDI);
    }
    else if ((int)(short)this[9].nPeriodSentinel + (int)*(short *)((int)&this[0x26].nRefOrFlags + 2)
             != (int)*(short *)((int)pPacket + 0xc)) {
      Skill_SetRankAndReevaluate
                (this,(void *)CONCAT22((short)((uint)this >> 0x10),*(short *)((int)pPacket + 0xc)),
                 (short)unaff_EDI);
    }
  }
  else {
    ExceptionList = &pvStack_1c;
    this = (CVOGHBBase *)
           CVOGReaction_ResolveSkillTargets
                     (*(void **)((int)pPacket + 8),
                      CONCAT22((short)((uint)nInferred >> 0x10),*(undefined2 *)((int)pPacket + 0xc))
                     );
    local_508 = this;
  }
  if (this != (CVOGHBBase *)0x0) {
    local_4fc = *(undefined4 *)((int)pPacket + 0x3c);
    local_4f8 = 0;
    if (*(char *)(*(int *)((int)pCasterObj + 0xa4) + 0x7e) != '\0') {
      puVar8 = local_4d0;
      uVar7 = 600;
      CVOGReaction_RandomUnitScalar(600,puVar8);
      local_4fc = FUN_0051b720(uVar7,puVar8);
      *(undefined4 *)((int)pPacket + 0x3c) = local_4fc;
    }
    if (*(char *)((int)pPacket + 0x38) == '\0') {
      Skill_LookupActiveCastBinding(&uStack_4f0,*(int *)((int)pPacket + 8));
      if (((uStack_4f0 & uStack_4ec) != 0xffffffff) || ((char)iStack_4e8 != '\0')) {
        local_4f8 = 0x11;
        iVar3 = CVOGReaction_ResolveObjectTarget(iStack_4e8,uStack_4f0,uStack_4ec);
        if (iVar3 != 0) {
          FUN_00514e20(this[0x26].nPeriodSentinel,*(undefined4 *)((int)pCasterObj + 0x160),
                       *(undefined4 *)((int)pCasterObj + 0x164),
                       *(undefined4 *)((int)pCasterObj + 0x168),
                       *(undefined4 *)((int)pCasterObj + 0x16c),0);
        }
        Skill_ClearCastBindingAndMaybeRestartCd
                  (pCasterObj,(void *)this[0x26].nPeriodSentinel,uStack_4f0,uStack_4ec,iStack_4e8,
                   cStack_4e4);
        if (*(char *)(*(int *)((int)pCasterObj + 0xa4) + 0x7e) == '\0') {
          FUN_00514e00();
        }
        if (((((uStack_4f0 == *(uint *)((int)pPacket + 0x40)) &&
              (uStack_4ec == *(uint *)((int)pPacket + 0x44))) &&
             ((char)iStack_4e8 == *(char *)((int)pPacket + 0x48))) ||
            (((this[0x26].bHeatAtMaxDebounce & 1) != 0 ||
             (iVar3 = TFID_EqualsObjectId((void *)((int)pPacket + 0x40),g_abTfidInvalid_9CDF88),
             (char)iVar3 != '\0')))) || ((this[0x26].bHeatAtMaxDebounce & 1) != 0)) {
          ExceptionList = pvStack_1c;
          return 0x11;
        }
      }
      if (*(char *)(*(int *)((int)pCasterObj + 0xa4) + 0x7e) != '\0') {
        if ((char)this[0x27].nRefOrFlags == '\0') {
          Skill_StartCastAgainHeartbeat(pCasterObj,this,*(void **)((int)pPacket + 0x10),unaff_EDI);
        }
        Skill_ClearActiveCastCounterAndQueueId(*(int *)((int)pPacket + 8));
      }
    }
    else {
      iVar3._0_1_ = this[0x25].cStopped;
      iVar3._1_1_ = this[0x25].fDormant;
      iVar3._2_1_ = this[0x25].cPad22;
      iVar3._3_1_ = this[0x25].cPad23;
      Skill_InsertCategoryCooldown(iVar3,*(int *)((int)pPacket + 0x10) + this->nPeriodCounter);
    }
    uStack_4d8 = *(undefined4 *)((int)pPacket + 0x20);
    uStack_4dc = *(undefined4 *)((int)pPacket + 0x1c);
    uStack_4e0 = *(undefined4 *)((int)pPacket + 0x18);
    uStack_510 = (*(ushort *)((int)pPacket + 4) - 0x40) / 0x18;
    uStack_4d4 = 0;
    puStack_500 = operator_new__(uStack_510 << 4);
    if (uStack_510 != 0) {
      puVar4 = (undefined4 *)((int)pPacket + 0x40);
      puStack_4f4 = puStack_500;
      do {
        puVar2 = puStack_4f4 + 4;
        *puStack_4f4 = *puVar4;
        puStack_4f4[1] = puVar4[1];
        puStack_4f4[2] = puVar4[2];
        puVar1 = puVar4 + 3;
        puVar4 = puVar4 + 6;
        uStack_510 = uStack_510 - 1;
        puStack_4f4[3] = *puVar1;
        this = local_508;
        puStack_4f4 = puVar2;
      } while (uStack_510 != 0);
    }
    iVar3 = (**(code **)(*(int *)pCasterObj + 0x19c))();
    if (iVar3 == 0) {
      auStack_50c[0] = 0;
      if (*(char *)((int)pCasterObj + 0x25) != '\0') {
        FUN_004e2600(&LAB_00512eb0,auStack_50c,0);
      }
      iVar3 = *(int *)((int)pCasterObj + 0xac);
    }
    else {
      iVar6 = *(int *)(*(int *)(iVar3 + 4) + 4);
      auStack_504[0] = 0;
      if (*(char *)(iVar6 + 0x29 + iVar3) != '\0') {
        FUN_004e2600(&LAB_00512eb0,auStack_504,0);
      }
      iVar3 = *(int *)(iVar6 + iVar3 + 0xb0);
    }
    if (iVar3 != 0) {
      FUN_00514ff0(0);
    }
    if (*(int *)((int)pPacket + 0x10) < 1) {
      FUN_005538a0(pCasterObj,*(undefined4 *)((int)pCasterObj + 0xa4),puStack_500,&uStack_4e0,
                   local_4fc);
      if (((*(char *)((int)pPacket + 0x38) == '\0') &&
          (iVar3 = *(int *)((int)pCasterObj + 100), iVar3 != 0)) &&
         ((*(int *)(iVar3 + 0x10) != 0 &&
          (iVar6 = *(int *)(iVar3 + 0x10) + -1, *(int *)(iVar3 + 0x10) = iVar6, iVar6 == 0)))) {
        *(undefined4 *)(iVar3 + 0xc) = 0;
      }
    }
    else {
      if (bIsLocalCaster == '\0') {
        (**(code **)(*(int *)pCasterObj + 0x238))
                  (3,*(undefined4 *)((int)pPacket + 8),(int)*(short *)((int)pPacket + 0xc),
                   *(int *)((int)pPacket + 0x10),0,0,0,0);
      }
      pvVar5 = operator_new(0x674);
      uStack_14 = 0;
      if (pvVar5 == (void *)0x0) {
        local_508 = (CVOGHBBase *)0x0;
      }
      else {
        local_508 = (CVOGHBBase *)
                    FUN_006061e0(*(undefined4 *)((int)pPacket + 0x10),pCasterObj,this,
                                 *(undefined4 *)((int)pCasterObj + 0xa4),puStack_500,&uStack_4e0,
                                 local_4fc,*(undefined1 *)((int)pPacket + 0x38));
      }
      uStack_14 = 0xffffffff;
      CVOGHBList_Enqueue(*(void **)(*(int *)((int)pCasterObj + 0xa4) + 0xe4ec),local_508);
      CVOGHBBase_Start(local_508);
    }
    operator_delete__(puStack_500);
    if (*(char *)((int)pPacket + 0x38) == '\0') {
      ExceptionList = pvStack_1c;
      return local_4f8;
    }
                    /* WARNING: Subroutine does not return */
    operator_delete(this);
  }
LAB_0051ae9e:
  FUN_007a4480(0,"VOG_DEBUG_STOP");
  ExceptionList = pvStack_1c;
  return local_4f8;
}
```
