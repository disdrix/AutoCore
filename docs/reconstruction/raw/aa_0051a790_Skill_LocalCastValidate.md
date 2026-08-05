# Raw capture: Skill_LocalCastValidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051a790` |
| **Canonical name** | `Skill_LocalCastValidate` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_LocalCastValidate(pCaster, bSkipBusyCheck, pSkill)
   
   Parameters:
     pCaster         - caster object (this)
     bSkipBusyCheck  - skip busy/active-cast gate when nonzero
     pSkill          - skill runtime (may be null for lightweight check)
   
   Returns: eSkillResponses (0=ok, 4=power, 6=busy, 7=recharge, ...)
   
   VERIFIED error codes via Skill_FormatFailureMessage strings. */

int __thiscall Skill_LocalCastValidate(void *this,void *pCaster,char bSkipBusyCheck,void *pSkill)

{
  char cVar1;
  int iVar2;
  void *pA;
  int iVar3;
  float10 extraout_ST0;
  void *unaff_retaddr;
  undefined3 in_stack_00000009;
  byte *pB;
  undefined1 auStack_10 [16];
  
  if ((*(byte *)((int)this + 0xb4) & 2) != 0) {
    return 5;
  }
  cVar1 = (**(code **)(*(int *)this + 0x198))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*(int *)this + 0x210))(0);
    if (iVar2 == 0) {
      return 3;
    }
    iVar2 = (**(code **)(*(int *)this + 0x210))(0);
    if (*(int *)(iVar2 + 0x6b4) < 1) {
      return 3;
    }
  }
  if ((char)pCaster == '\0') {
    if (((*(byte *)((int)this + 0xb4) & 8) != 0) &&
       (*(int *)(*(int *)((int)this + 0xa8) + 0x38) == 0x14)) {
      return 5;
    }
    iVar2 = FUN_005169c0();
    if (*(int *)(iVar2 + 0x10) != 0) {
      return 6;
    }
  }
  if (_bSkipBusyCheck != (void *)0x0) {
    pB = g_abTfidInvalid_9CDF88;
    Skill_LookupActiveCastBinding(auStack_10,*(int *)((int)_bSkipBusyCheck + 0x5fc));
    iVar2 = TFID_NotEquals(pA,pB);
    if ((char)iVar2 == '\0') {
      cVar1 = '\0';
      iVar2 = (**(code **)(*(int *)this + 0x210))();
      if (((iVar2 != 0) && (*(int *)(iVar2 + 0x6b4) < 1)) &&
         (*(short *)(iVar2 + 300) < *(short *)((int)_bSkipBusyCheck + 8))) {
        return 4;
      }
      if ((*(char *)((int)_bSkipBusyCheck + 0x628) != '\0') ||
         (Skill_GetCategoryCooldownRemaining(*(float10 **)((int)_bSkipBusyCheck + 0x5e8),1,cVar1),
         (float10)g_flZero != extraout_ST0)) {
        return 7;
      }
      if ((iVar2 == 0) &&
         ((iVar3 = FUN_00518c20(), *(int *)(iVar3 + 8) != 0 &&
          ((*(byte *)((int)_bSkipBusyCheck + 0x615) & 2) != 0)))) {
        return 10;
      }
      iVar3 = (**(code **)(*(int *)this + 0x19c))();
      if (iVar3 == 0) {
        if ((*(byte *)((int)_bSkipBusyCheck + 0x615) & 0x40) == 0) goto LAB_0051a94e;
      }
      else {
        if ((iVar2 == 0) && (*(char *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x29 + iVar3) != '\0')) {
          if ((*(uint *)((int)_bSkipBusyCheck + 0x614) & 0x4000) == 0) {
            return 0xc;
          }
        }
        else if ((*(uint *)((int)_bSkipBusyCheck + 0x614) & 0x4000) == 0) goto LAB_0051a94e;
        if (*(char *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x29 + iVar3) != '\0') {
LAB_0051a94e:
          iVar2 = Skill_LocalRangeTargetCheck(_bSkipBusyCheck,this,_bSkipBusyCheck,unaff_retaddr);
          return iVar2;
        }
      }
      return 0xb;
    }
  }
  return 0;
}
```
