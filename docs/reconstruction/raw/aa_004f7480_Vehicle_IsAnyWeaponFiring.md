# Raw capture: Vehicle_IsAnyWeaponFiring

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7480` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f7480` |
| **Canonical name** | `Vehicle_IsAnyWeaponFiring` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
