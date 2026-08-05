# Raw capture: CVOGHBRegeneration_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fbdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fbdb0` |
| **Canonical name** | `CVOGHBRegeneration_ctor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBRegeneration_ctor — construct regeneration heartbeat action (size 0x28).
   
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
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Construct combat-pool TimedAction. Period 3000ms (race 0-2) or 5000ms. */
  local_4 = 0xffffffff;
  puStack_8 = &seh_VehicleCombatPoolAction_ctor;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  CVOGHBBase_ctor(this);
  *(void ***)this = &g_pVtbl_VehicleCombatPoolAction;
  *(undefined1 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x25) = 0;
  *(undefined1 *)((int)this + 0x26) = 0;
  local_4 = 0;
  iVar1 = (**(code **)(*(int *)pVehicleBase + 0x1d4))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)pVehicleBase + 0x1d8))();
  }
  else {
    iVar1 = __RTDynamicCast(*(undefined4 *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xb0 + iVar1),0,
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
      *(undefined4 *)((int)this + 8) = 3000;
    }
    else {
      *(undefined4 *)((int)this + 8) = 5000;
    }
  }
  CVOGHBBase_AttachOwnerObject(this,pVehicleBase);
  ExceptionList = pvStack_c;
  return this;
}
```
