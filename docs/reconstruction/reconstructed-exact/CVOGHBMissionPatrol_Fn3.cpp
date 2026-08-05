// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CNDHash_LookupByKey, CVOGCharacter_EvaluatePendingObjectives, CVOGHBBase_RescheduleAfterFire, CVOGHBMissionPatrol_Fn3, CVOGReaction_FailMission, CVOGReaction_ResolveObjectTarget, __RTDynamicCast.
//  - Return sites: 3.

// =============================================================================
// CVOGHBMissionPatrol_Fn3
// -----------------------------------------------------------------------------
// Purpose:  Mission-patrol HB helper (Ghidra Fn3): patrol-related state transition /
//           waypoint side effect on mission HB object.
//
// Address:  0x00650e50  (autoassault.exe, image base 0x400000)
// Stable:   aa_00650e50
// System:   npc-ai / mission-patrol HB
//
// Part of CVOGHBMissionPatrol family with Fn6 + Tick.
// Prefer annotated raw for full CF; plate is human entry point only.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

uint32_t /* width from decompiler */ * __thiscall CVOGHBMissionPatrol_Fn3(CVOGHBBase *param_1,uint32_t /* width from decompiler */ *param_2)
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
    CVOGReaction_FailMission(**(uint32_t /* width from decompiler */ **)((int)pvVar2 + 0x14c));
  }
  *param_2 = DAT_00af5174;
  return param_2;
}
