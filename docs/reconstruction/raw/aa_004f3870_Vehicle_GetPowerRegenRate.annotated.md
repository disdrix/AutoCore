# Annotated low-level: Vehicle_GetPowerRegenRate

| Field | Value |
|---|---|
| Stable ID | `aa_004f3870` |
| VA | `0x004f3870` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f3870`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_GetPowerRegenRate — raw power points added each regen pulse.
   
   pVehicle: VehicleCombatPools_Inferred*
   Returns: PowerPlantRuntime_Inferred.nPowerRegenRate (short at plant+0xB8),
   or 1 if no plant.
   UI shows rate * g_flDisplayRateScaleOneThird as MKz/sec. */

int __fastcall Vehicle_GetPowerRegenRate(VehicleCombatPools_Inferred *pVehicle)

{
  if (pVehicle->pPowerPlant_Inferred != (PowerPlantRuntime_Inferred *)0x0) {
    return (int)pVehicle->pPowerPlant_Inferred->nPowerRegenRate;
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
