# Annotated low-level: Character_MaybeRefreshCombatState_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005355e0` |
| VA | `0x005355e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005355e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Character_MaybeRefreshCombatState_Inferred — called from VehicleCombatPool_OnTick when owner
   character present.
   
   Role INFERRED (not fully analyzed): minor combat/UI state refresh after regen pulse.
   Do not expand RE of this function unless needed. */

void __thiscall Character_MaybeRefreshCombatState_Inferred(void *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  DWORD DVar4;
  uint uVar5;
  
  DVar4 = GetTickCount();
  uVar5 = DVar4 - *(int *)((int)param_1 + 0x8dc);
  puVar1 = (uint *)((int)param_1 + 0x928);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_2 + uVar5;
  *(int *)((int)param_1 + 0x92c) =
       *(int *)((int)param_1 + 0x92c) + (uint)CARRY4(param_2,uVar5) +
       (uint)CARRY4(uVar2,param_2 + uVar5);
  DVar4 = GetTickCount();
  *(uint *)((int)param_1 + 0x634) = *(uint *)((int)param_1 + 0x634) | 1;
  *(DWORD *)((int)param_1 + 0x8dc) = DVar4;
  if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) != 0) {
    fVar3 = (float)(int)param_2;
    if ((int)param_2 < 0) {
      fVar3 = fVar3 + _DAT_00aaa5dc;
    }
    CVOGCharacter_EvaluatePendingObjectives(param_1,7,fVar3 + (float)uVar5,0,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
