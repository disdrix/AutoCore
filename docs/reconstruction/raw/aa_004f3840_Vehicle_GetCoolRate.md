# Raw capture: Vehicle_GetCoolRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3840` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f3840` |
| **Canonical name** | `Vehicle_GetCoolRate` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
