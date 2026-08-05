// =============================================================================
// Vehicle_EnsureRegenerationHeartbeat
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7e10
// Address:   0x004f7e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Vehicle_EnsureRegenerationHeartbeat — create/enqueue combat-pool HB once.
   
   Guards: pRegenerationHeartbeat null; map present; sector-active map+0x7E.
   new 0x28 CVOGHBRegeneration_ctor(vehicleBase, periodOverride=0);
   store at vehicle+0x27C; CVOGHBList_Enqueue; CVOGHBBase_Start.
   Called from Vehicle_ActivateEnterWorld when owner present. */

void __fastcall Vehicle_EnsureRegenerationHeartbeat(VehicleCombatPools_Inferred *pVehicle)

{
  int iVar1;
  RE_CombatPoolAction *pCombatPoolAction;
  CVOGHBRegeneration *pAction;
  void *pSehPrev;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ nSehState;
  
                    /* Create/enqueue combat pool action once per vehicle (slot vehicle+0x27C). */
  nSehState = 0xffffffff;
  puStack_8 = &seh_Vehicle_CreateCombatPoolAction;
  pSehPrev = ExceptionList;
  if (((pVehicle->pRegenerationHeartbeat == (CVOGHBBase *)0x0) &&
      (*(int *)(pVehicle->pOpaqueHeader_Inferred +
               *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) != 0)) &&
     (*(char *)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                        *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0xa8) + 0x7e)
      != '\0')) {
    ExceptionList = &pSehPrev;
    pCombatPoolAction = operator_new(0x28);
    nSehState = 0;
    if (pCombatPoolAction == (RE_CombatPoolAction *)0x0) {
      pAction = (CVOGHBRegeneration *)0x0;
    }
    else {
      pAction = CVOGHBRegeneration_ctor
                          (pCombatPoolAction,
                           pVehicle->pOpaqueHeader_Inferred +
                           *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 4,0);
    }
    iVar1 = *(int *)(pVehicle->pOpaqueHeader_Inferred + 4);
    pVehicle->pRegenerationHeartbeat = (CVOGHBBase *)pAction;
    nSehState = 0xffffffff;
    CVOGHBList_Enqueue(*(void **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                                          *(int *)(iVar1 + 4) + 0xa8) + 0xe4ec),
                       (CVOGHBBase *)pAction);
    CVOGHBBase_Start(pVehicle->pRegenerationHeartbeat);
  }
  ExceptionList = pSehPrev;
  return;
}
