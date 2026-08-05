// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: CVOGHBBase_AttachOwnerObject, CVOGHBBase_SetPeriodAndCounter, CVOGHBBase_ctor, CVOGHBRegeneration_ctor, Object_GetRootRaceId, SetPeriodAndCounter, __RTDynamicCast, action.
//  - Return sites: 1.

// =============================================================================
// CVOGHBRegeneration_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct combat-pool regeneration HB: attach owner, set period from race
//           (0/1/2 -> 3000ms else 5000ms), not 16ms (16 is Remove status).
//
// Address:  0x005fbdb0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005fbdb0
// System:   heartbeat / combat-pool
//
// AutoCore: VehicleCombatPool.cs. Periods race-dependent 3s/5s.
// OnHeartBeat applies HP/power/heat/shield authored rates per pulse.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* CVOGHBRegeneration_ctor - construct regeneration heartbeat action (size 0x28).
   
   Parameters:
     this (ECX): CVOGHBRegeneration* [API shows void* for thiscall]
     pVehicleBase: vehicle SimpleObject base to attach as owner
     nPeriodOverrideMs: 0 means pick by race (3000 Human/Biomek/Tribe, else 5000)
   
   Algorithm:
     CVOGHBBase_ctor; install regen vtable; clear debounce bytes (+0x24..+0x26);
     SetPeriodAndCounter(-1000,true) sentinel; set nPeriodMs; AttachOwnerObject.
   
   Returns: this
   
   Caller: Vehicle_EnsureRegenerationHeartbeat from Vehicle_ActivateEnterWorld. */
CVOGHBRegeneration * __thiscall
CVOGHBRegeneration_ctor(void *this,void *pVehicleBase,int nPeriodOverrideMs)
{
  int iVar1;
  RACE_ID_INFERRED RVar2;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
                    /* Construct combat-pool TimedAction. Period 3000ms (race 0-2) or 5000ms. */
  local_4 = 0xffffffff;
  puStack_8 = &seh_VehicleCombatPoolAction_ctor;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CVOGHBBase_ctor(this);
  *(void ***)this = &g_pVtbl_VehicleCombatPoolAction;
  *(uint8_t *)((int)this + 0x24) = 0;
  *(uint8_t *)((int)this + 0x25) = 0;
  *(uint8_t *)((int)this + 0x26) = 0;
  local_4 = 0;
  iVar1 = (**(code **)(*(int *)pVehicleBase + 0x1d4))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)pVehicleBase + 0x1d8))();
  }
  else {
    iVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xb0 + iVar1),0,
                            &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                            &CVOGCreature::RTTI_Type_Descriptor,0);
  }
  CVOGHBBase_SetPeriodAndCounter(this,-1000,true);
  *(int *)((int)this + 8) = nPeriodOverrideMs;
  if ((nPeriodOverrideMs == 0) && (iVar1 != 0)) {
                    /* periodMsOverride from ctor arg; if 0, pick race default 3000 or 5000 */
    RVar2 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1));
    if ((RVar2 == RACE_HUMAN_INFERRED) ||
       ((RVar2 == RACE_BIOMEK_INFERRED || (RVar2 == RACE_TRIBE_INFERRED)))) {
      *(uint32_t /* width from decompiler */ *)((int)this + 8) = 3000;
    }
    else {
      *(uint32_t /* width from decompiler */ *)((int)this + 8) = 5000;
    }
  }
  CVOGHBBase_AttachOwnerObject(this,pVehicleBase);
  ExceptionList = pvStack_c;
  return this;
}
