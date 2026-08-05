# Annotated low-level: Vehicle_GetCoolRate

| Field | Value |
|---|---|
| Stable ID | `aa_004f3840` |
| VA | `0x004f3840` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f3840`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_GetCoolRate — heat cool amount applied each regen pulse.
   
   pVehicle: VehicleCombatPools_Inferred*
   Returns: plant.nCoolRate + vehicle.nCoolRateAdjust, or adjust+1 if no plant.
   UI shows rate * g_flDisplayRateScaleOneThird as /sec. */

int __fastcall Vehicle_GetCoolRate(VehicleCombatPools_Inferred *pVehicle)

{
  if (pVehicle->pPowerPlant_Inferred != (PowerPlantRuntime_Inferred *)0x0) {
    return (int)pVehicle->nCoolRateAdjust_Inferred + (int)pVehicle->pPowerPlant_Inferred->nCoolRate;
  }
  return pVehicle->nCoolRateAdjust_Inferred + 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
