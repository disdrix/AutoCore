# Annotated low-level: Vehicle_EnsureRegenerationHeartbeat

| Field | Value |
|---|---|
| Stable ID | `aa_004f7e10` |
| VA | `0x004f7e10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f7e10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
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
  undefined1 *puStack_8;
  undefined4 nSehState;
  
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
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
