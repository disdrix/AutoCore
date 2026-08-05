// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGCharacter_EvaluatePendingObjectives, CVOGHBMissionPatrol_Fn6, FUN_005083f0, __RTDynamicCast.
//  - Return sites: 1.

// =============================================================================
// CVOGHBMissionPatrol_Fn6
// -----------------------------------------------------------------------------
// Purpose:  Mission-patrol HB helper (Ghidra Fn6): companion setup/teardown for patrol
//           heartbeat (pairs with Fn3 + Tick).
//
// Address:  0x00650de0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00650de0
// System:   npc-ai / mission-patrol HB
//
// Part of CVOGHBMissionPatrol family. See MissionPatrol_Tick for schedule.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

void __thiscall CVOGHBMissionPatrol_Fn6(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)
{
  void *this;
  int iVar1;
  
  this = (void *)__RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0,
                                 &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                 &CVOGCharacter::RTTI_Type_Descriptor,0);
  if (this != (void *)0x0) {
    iVar1 = CVOGReaction_ResolveObjectTarget
                      (0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x30),*(uint32_t /* width from decompiler */ *)(param_1 + 0x34));
    if (iVar1 != 0) {
      CVOGCharacter_EvaluatePendingObjectives(this,0xb,0,0,0);
    }
  }
  FUN_005083f0(param_2,param_3);
  return;
}
