# Raw capture: Vehicle_GetPowerRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3870` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f3870` |
| **Canonical name** | `Vehicle_GetPowerRegenRate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
