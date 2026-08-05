# Annotated low-level: CVOGHBMissionPatrol_Fn3

| Field | Value |
|---|---|
| Stable ID | `aa_00650e50` |
| VA | `0x00650e50` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00650e50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall CVOGHBMissionPatrol_Fn3(CVOGHBBase *param_1,undefined4 *param_2)

{
  int iVar1;
  void *this;
  void *pvVar2;
  int iVar3;
  uint *pOutNextDelayMs;
  
  this = (void *)__RTDynamicCast(param_1->pOwnerObject,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor
                                 ,&CVOGCharacter::RTTI_Type_Descriptor,0);
  if (this == (void *)0x0) {
    *param_2 = DAT_00af5174;
    return param_2;
  }
  iVar1._0_1_ = param_1->bHeatAtMaxDebounce;
  iVar1._1_1_ = param_1->bShieldEmptyDebounce;
  iVar1._2_1_ = param_1->bPad26;
  iVar1._3_1_ = param_1->bPad27;
  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0xfc);
  pvVar2 = CNDHash_LookupByKey(*(void **)((int)this + 0x548),(uint)param_1[1].pVTable);
  if (pvVar2 != (void *)0x0) {
    if ((iVar1 == iVar3) &&
       (iVar3 = CVOGReaction_ResolveObjectTarget(0,param_1[1].nPeriodMs,param_1[1].nPeriodSentinel),
       iVar3 != 0)) {
      CVOGCharacter_EvaluatePendingObjectives(this,0xb,0,0,0);
      CVOGHBBase_RescheduleAfterFire(param_1,pOutNextDelayMs);
      return param_2;
    }
    CVOGReaction_FailMission(**(undefined4 **)((int)pvVar2 + 0x14c));
  }
  *param_2 = DAT_00af5174;
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
