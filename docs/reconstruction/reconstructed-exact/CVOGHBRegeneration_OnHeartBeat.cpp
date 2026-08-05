// READABILITY (auto CF):
//  - Body size: ~199 non-empty decompiler lines.
//  - Control keywords: if×28, goto×8, for×1, return×1.
//  - Notable callees: NetObject_SetMaskBits×3, Vehicle_GetCoolRate×3, CONCAT22×2, Vehicle_AddHeat×2, Vehicle_IsAnyWeaponFiring×2, Algorithm, CVOGHBBase_RescheduleAfterFire, CVOGHBRegeneration_OnHeartBeat.
//  - Return sites: 1.

// =============================================================================
// CVOGHBRegeneration_OnHeartBeat
// -----------------------------------------------------------------------------
// Purpose:  One combat-pool pulse: HP/power/heat/shield regen with debounces; dirty
//           pool masks; RescheduleAfterFire. Full rates per pulse (no dt).
//
// Address:  0x005fbea0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005fbea0
// System:   heartbeat / combat-pool
//
// Args: pThis, pOutNextDelayMs.
// Algorithm: owner creature+vehicle -> HP race item regen -> power regen/clamp
// -> heat cool (overheat frac) -> shield regen after empty debounce -> reschedule.
// Masks: Power 0x8000000, Heat 0x20000000, Shield 0x4000000 (INFERRED plate).
// AutoCore: src/AutoCore.Game/Combat/VehicleCombatPool.cs
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* CVOGHBRegeneration_OnHeartBeat - one combat-pool pulse (HP/power/heat/shield).
   
   Parameters:
     pThis (ECX): CVOGHBRegeneration* [typed via __fastcall; true ABI is thiscall]
     pOutNextDelayMs (stack+4): list reschedule out-param
   
   Algorithm (full authored rates per pulse; NO dt multiply):
     1. Resolve owner creature + vehicle via pOwnerObject vcalls
     2. HP += Creature_GetHpRegenFromEquippedRaceItem
     3. Power += Vehicle_GetPowerRegenRate; clamp to max; dirty PowerMask 0x8000000
     4. Heat: 2-tick debounce at bHeatAtMaxDebounce when heat==max;
        cool with Vehicle_GetCoolRate; if heat>=max cool*(1-g_flOverheatCoolFrac≈0.7);
        Vehicle_AddHeat(-amount); dirty HeatMask 0x20000000
     5. Shield: if max>0, empty-shield 2-tick debounce at bShieldEmptyDebounce,
        then +Vehicle_GetShieldRegenRate; dirty ShieldMask 0x4000000
     6. CVOGHBBase_RescheduleAfterFire
   
   Returns: pOutNextDelayMs
   
   Period set in ctor: race 0/1/2 → 3000ms else 5000ms (NOT 16ms).
   AutoCore: src/AutoCore.Game/Combat/VehicleCombatPool.cs */
uint * __fastcall CVOGHBRegeneration_OnHeartBeat(CVOGHBRegeneration *pThis,uint *pOutNextDelayMs)
{
  bool bIsFiring;
  uchar bShieldDebounce;
  VehicleCombatPools_Inferred *pVehicle;
  int nTmp;
  int nPowerBefore;
  int nRate;
  uint16_t extraout_var;
  uint16_t extraout_var_00;
  uint dwScratch;
  void *pGhostNetObject;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  uint *extraout_EDX_01;
  uint *extraout_EDX_02;
  int nHeatDelta;
  uint *extraout_EDX_03;
  uint *extraout_EDX_04;
  int nShield;
  uint *extraout_EDX_05;
  uint *pOutNextDelayMs_00;
  uint *extraout_EDX_06;
  int *pCreature;
  uint64_t uVar1;
  uint *in_stack_00000004;
  CVOGHBRegeneration *pActionSelf;
  int nWeaponContext;
  uchar bDebounce;
  bool bForceDirty;
  uint32_t /* width from decompiler */ uUnused;
  
                    /* VehicleCombatPool_OnTick: one pulse for HP / power / heat / shield. Period is
                       3s or 5s (NOT 16ms). */
  pVehicle = (VehicleCombatPools_Inferred *)(**(code **)(*(int *)pThis->pOwnerObject + 0x1d4))();
  if (pVehicle == (VehicleCombatPools_Inferred *)0x0) {
    uVar1 = (**(code **)(*(int *)pThis->pOwnerObject + 0x1d8))();
    pOutNextDelayMs_00 = (uint *)((ulonglong)uVar1 >> 0x20);
    if ((int)uVar1 == 0) goto reschedule_and_return;
    pVehicle = *(VehicleCombatPools_Inferred **)((int)uVar1 + 0x250);
  }
  else {
    uVar1 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)
                             (pVehicle->pOpaqueHeader_Inferred +
                             *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0xb0),0,
                            &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                            &CVOGCreature::RTTI_Type_Descriptor,0);
  }
  pOutNextDelayMs_00 = (uint *)((ulonglong)uVar1 >> 0x20);
  pCreature = (int *)uVar1;
  if (pCreature == (int *)0x0) goto reschedule_and_return;
  nTmp = (**(code **)(*(int *)(*(int *)(pCreature[1] + 4) + 4 + (int)pCreature) + 0x210))(0);
  if (nTmp != 0) {
    uUnused = 0;
    (**(code **)(*(int *)(*(int *)(*(int *)(nTmp + 4) + 4) + 4 + nTmp) + 0x210))(0,0);
    Character_MaybeRefreshCombatState_Inferred(uUnused);
  }
  (**(code **)(*(int *)pThis->pOwnerObject + 0x23c))();
                    /* HP regen: current += race-item RaceRegenRate */
  nTmp = *(int *)pThis->pOwnerObject;
  nPowerBefore = (**(code **)(nTmp + 0x23c))();
  nRate = Creature_GetHpRegenFromEquippedRaceItem(pCreature);
  (**(code **)(nTmp + 0x240))(nPowerBefore + nRate);
  pOutNextDelayMs_00 = extraout_EDX;
  pThis = pActionSelf;
  if (pVehicle == (VehicleCombatPools_Inferred *)0x0) goto reschedule_and_return;
  nPowerBefore = pCreature[0x4b];
                    /* // --- POWER REGEN --- */
  nTmp = *pCreature;
  nRate = Vehicle_GetPowerRegenRate(pVehicle);
  (**(code **)(nTmp + 0xac))(nRate + CONCAT22(extraout_var,(short)nPowerBefore));
                    /* Power regen: character current power += PowerPlant PowerRegenRate; dirty
                       PowerMask */
  pOutNextDelayMs_00 = extraout_EDX_00;
  if (*(short *)((int)pCreature + 0x12e) < (short)pCreature[0x4b]) {
    (**(code **)(*pCreature + 0xac))(CONCAT22(extraout_var_00,*(short *)((int)pCreature + 0x12e)));
    pOutNextDelayMs_00 = extraout_EDX_01;
  }
  if ((short)pCreature[0x4b] != (short)nPowerBefore) {
    pOutNextDelayMs_00 = *(uint **)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4);
    if (*(void **)((int)(pOutNextDelayMs_00 + 6) + (int)pVehicle) != (void *)0x0) {
      NetObject_SetMaskBits(*(void **)((int)(pOutNextDelayMs_00 + 6) + (int)pVehicle),0x8000000,0);
      pOutNextDelayMs_00 = extraout_EDX_02;
    }
  }
  bDebounce = pActionSelf->bHeatAtMaxDebounce;
  if ((bDebounce == '\0') && (pVehicle->nCurrentHeat == pVehicle->nMaxHeat)) {
    pActionSelf->bHeatAtMaxDebounce = '\x02';
    pOutNextDelayMs_00 = *(uint **)(pVehicle->pOpaqueHeader_Inferred + 4);
    pGhostNetObject = *(void **)(pVehicle->pOpaqueHeader_Inferred + pOutNextDelayMs_00[1] + 0x18);
set_heat_mask_bits:
    if (pGhostNetObject != (void *)0x0) {
      NetObject_SetMaskBits(pGhostNetObject,0x20000000,0);
      pOutNextDelayMs_00 = extraout_EDX_04;
    }
  }
  else {
    bForceDirty = false;
    if (bDebounce == '\0') {
cool_heat_path:
                    /* Heat cool path: subtract CoolRate (×0.7 if over max); dirty HeatMask */
      if ((nWeaponContext == 0) ||
         (nTmp = (**(code **)(*(int *)(*(int *)(*(int *)(nWeaponContext + 4) + 4) + 4 +
                                      nWeaponContext) + 0x27c))(), 5 < nTmp)) {
        bIsFiring = Vehicle_IsAnyWeaponFiring(pVehicle);
        dwScratch = ((-(uint)bIsFiring & 2) - 1) + pVehicle->nCoolAccumulator;
        pVehicle->nCoolAccumulator = dwScratch & ((int)dwScratch < 1) - 1;
      }
      if (pVehicle->nMaxHeat <= pVehicle->nCurrentHeat) {
        nTmp = Vehicle_GetCoolRate(pVehicle);
        nPowerBefore = Vehicle_GetCoolRate(pVehicle);
        pVehicle->nCoolAccumulator = (int)((float)nTmp - (float)nPowerBefore * g_flOverheatCoolFrac)
        ;
      }
      Vehicle_GetCoolRate(pVehicle);
      Vehicle_IsAnyWeaponFiring(pVehicle);
      nTmp = pVehicle->nCurrentHeat;
      Vehicle_AddHeat(pVehicle,nHeatDelta);
      pOutNextDelayMs_00 = extraout_EDX_03;
      if (nTmp == pVehicle->nCurrentHeat) goto shield_regen_path;
dirty_heat_mask:
      pOutNextDelayMs_00 = *(uint **)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4);
      pGhostNetObject = *(void **)((int)(pOutNextDelayMs_00 + 6) + (int)pVehicle);
      goto set_heat_mask_bits;
    }
    if (pVehicle->nCurrentHeat == pVehicle->nMaxHeat) {
      pActionSelf->bHeatAtMaxDebounce = bDebounce + 0xff;
    }
    else {
      pActionSelf->bHeatAtMaxDebounce = '\0';
    }
    if (pActionSelf->bHeatAtMaxDebounce == '\0') {
      bForceDirty = true;
      goto cool_heat_path;
    }
shield_regen_path:
                    /* Shield regen path: after 2-tick empty debounce, add RaceShieldRegenerate;
                       dirty ShieldMask */
    if (bForceDirty) goto dirty_heat_mask;
  }
  if (pVehicle->nMaxShield != 0) {
    bDebounce = pActionSelf->bShieldEmptyDebounce;
                    /* // --- SHIELD REGEN (with empty debounce) --- */
    if ((bDebounce == '\0') && (pVehicle->nCurrentShield == 0)) {
      pActionSelf->bShieldEmptyDebounce = '\x02';
      pGhostNetObject =
           *(void **)(pVehicle->pOpaqueHeader_Inferred +
                     *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0x18);
    }
    else {
      bForceDirty = false;
      bShieldDebounce = '\0';
      if (bDebounce != '\0') {
        if (pVehicle->nCurrentShield == 0) {
          pActionSelf->bShieldEmptyDebounce = bDebounce + 0xff;
        }
        else {
          pActionSelf->bShieldEmptyDebounce = '\0';
        }
        bShieldDebounce = pActionSelf->bShieldEmptyDebounce;
        if (bShieldDebounce == '\0') {
          bForceDirty = true;
        }
      }
      nTmp = pVehicle->nCurrentShield;
      if (bShieldDebounce == '\0') {
        Vehicle_GetShieldRegenRate(pVehicle);
        Vehicle_SetCurrentShield(pVehicle,nShield);
        pOutNextDelayMs_00 = extraout_EDX_05;
      }
      if ((nTmp == pVehicle->nCurrentShield) && (!bForceDirty)) goto reschedule_and_return;
      pOutNextDelayMs_00 = *(uint **)(pVehicle->pOpaqueHeader_Inferred + 4);
      pGhostNetObject = *(void **)(pVehicle->pOpaqueHeader_Inferred + pOutNextDelayMs_00[1] + 0x18);
    }
    if (pGhostNetObject != (void *)0x0) {
      NetObject_SetMaskBits(pGhostNetObject,0x4000000,0);
      pOutNextDelayMs_00 = extraout_EDX_06;
    }
  }
reschedule_and_return:
  CVOGHBBase_RescheduleAfterFire((CVOGHBBase *)pThis,pOutNextDelayMs_00);
  return in_stack_00000004;
}
