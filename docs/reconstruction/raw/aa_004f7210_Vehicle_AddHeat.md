# Raw capture: Vehicle_AddHeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7210` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f7210` |
| **Canonical name** | `Vehicle_AddHeat` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_AddHeat — apply signed heat delta; clamp [0, 2*MaxHeat]; dirty HeatMask 0x20000000.
   
   Parameters:
     pVehicle (ECX): VehicleCombatPools_Inferred*
     nHeatDelta (stack; decomp may show unaff_retaddr — INFERRED fragile):
       positive heats, negative cools (regen uses negative cool amount)
   
   Algorithm: floor cool accumulator; optional character heat-sink divert;
   CurrentHeat += delta; clamp; NetObject_SetMaskBits if ghosted and changed.
   
   Returns: void */

void __fastcall Vehicle_AddHeat(VehicleCombatPools_Inferred *pVehicle,int nHeatDelta)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int iVar3;
  int unaff_retaddr;
  
                    /* Add/subtract heat; clamp to [0, 2*MaxHeat]; dirty HeatMask. */
  if (pVehicle->nCoolAccumulator < 0) {
    pVehicle->nCoolAccumulator = 0;
  }
  iVar1 = (**(code **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                               *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 4) +
                      0x210))(0);
  if ((iVar1 != 0) && (pVehicle->nMaxHeat < pVehicle->nCurrentHeat + unaff_retaddr)) {
    iVar1 = (**(code **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                                 *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 4) +
                        0x210))(0);
    if (*(float *)(iVar1 + 0xc6c) != g_flZero) {
      iVar1 = (**(code **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                                   *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 4)
                          + 0x210))(0);
      iVar3 = (int)((float)unaff_retaddr * *(float *)(iVar1 + 0xc6c));
      iVar1 = (**(code **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                                   *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 4)
                          + 0x210))(0);
      if ((short)iVar3 <= *(short *)(iVar1 + 300)) {
        piVar2 = (int *)(**(code **)(*(int *)(pVehicle->pOpaqueHeader_Inferred +
                                             *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4)
                                                     + 4) + 4) + 0x210))(0);
        (**(code **)(*piVar2 + 0xb0))(iVar3);
        unaff_retaddr = 0;
      }
    }
  }
  pVehicle->nCurrentHeat = pVehicle->nCurrentHeat + unaff_retaddr;
  iVar1 = pVehicle->nMaxHeat * 2;
  if (iVar1 < pVehicle->nCurrentHeat) {
    pVehicle->nCurrentHeat = iVar1;
  }
  if (pVehicle->nCurrentHeat < 0) {
    pVehicle->nCurrentHeat = 0;
  }
  if ((*(void **)(pVehicle->pOpaqueHeader_Inferred +
                 *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0x18) != (void *)0x0
      ) && (unaff_ESI != pVehicle->nCurrentHeat)) {
    NetObject_SetMaskBits
              (*(void **)(pVehicle->pOpaqueHeader_Inferred +
                         *(int *)(*(int *)(pVehicle->pOpaqueHeader_Inferred + 4) + 4) + 0x18),
               0x20000000,0);
  }
  return;
}
```
