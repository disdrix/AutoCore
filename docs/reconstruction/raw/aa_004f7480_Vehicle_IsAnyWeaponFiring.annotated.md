# Annotated low-level: Vehicle_IsAnyWeaponFiring

| Field | Value |
|---|---|
| Stable ID | `aa_004f7480` |
| VA | `0x004f7480` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f7480`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_IsAnyWeaponFiring
   
   Parameters:
     pVehicle - vehicle; turret +0x264, hardpoint table +0x260
   
   Algorithm:
     if turret weapon firing flag (+0xC7): true
     else scan 3 hardpoint weapons for flag +0xC7
   
   Returns: bool
   
   Used by OnTick to slow cooling while player is firing. */

bool __fastcall Vehicle_IsAnyWeaponFiring(VehicleCombatPools_Inferred *pVehicle)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(pVehicle->pPad_248_267_Inferred + 0x1c) == 0) ||
     (*(char *)(*(int *)(pVehicle->pPad_248_267_Inferred + 0x1c) + 199) == '\0')) {
    piVar2 = *(int **)(pVehicle->pPad_248_267_Inferred + 0x18);
    iVar1 = 0;
    while ((*piVar2 == 0 || (*(char *)(*piVar2 + 199) == '\0'))) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (2 < iVar1) {
        return false;
      }
    }
  }
  return true;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
