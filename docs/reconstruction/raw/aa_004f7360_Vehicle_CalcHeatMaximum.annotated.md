# Annotated low-level: Vehicle_CalcHeatMaximum

| Field | Value |
|---|---|
| Stable ID | `aa_004f7360` |
| VA | `0x004f7360` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f7360`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_CalcHeatMaximum
   
   Parameters:
     pVehicle - vehicle
   
   Algorithm:
     combine power plant heat capacity (+0xB0), creature race/level heat tables
     (+0x531/+0x532), vehicle heat adjust (+0x1E0); ceil to short/int
   
   Returns: int MaxHeat capacity
   
   INFERRED table base addresses DAT_009cd0dc / DAT_009cd0ec. */

int __fastcall Vehicle_CalcHeatMaximum(RE_VehicleCombatPoolFields *pVehicle)

{
  float fVar1;
  byte bVar2;
  void *pCharacter;
  int iVar3;
  int iVar4;
  float fVar5;
  double dVar6;
  float local_c;
  
  local_c = DAT_00a110d8;
  if ((*(int **)(&pVehicle->field_0xb0 + *(int *)(*(int *)&pVehicle->field_0x4 + 4)) != (int *)0x0)
     && (pCharacter = (void *)(**(code **)(**(int **)(&pVehicle->field_0xb0 +
                                                     *(int *)(*(int *)&pVehicle->field_0x4 + 4)) +
                                          0x1dc))(), pCharacter != (void *)0x0)) {
    if (pVehicle->pPowerPlant_Inferred == (PowerPlantRuntime_Inferred *)0x0) {
      fVar5 = 0.0;
    }
    else {
      fVar5 = (float)pVehicle->pPowerPlant_Inferred->nHeatMaximum;
    }
    bVar2 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 0xac +
                                       (int)pCharacter) + 0x3c) + 0x531);
    iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pCharacter + 4) + 4) + 4 + (int)pCharacter)
                        + 0x27c))();
    fVar1 = *(float *)(&DAT_009cd0dc + (uint)bVar2 * 4);
    iVar4 = Character_GetTechForPoolCalcs(pCharacter);
    dVar6 = ceil((double)(*(float *)(&DAT_009cd0ec +
                                    (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)
                                                  pCharacter + 4) + 4) + 0xac + (int)pCharacter) +
                                                  0x3c) + 0x532) * 4) *
                          ((float)iVar3 * fVar1 + (float)(int)(short)iVar4 * DAT_009cd0d8 + fVar5) +
                         (float)pVehicle->nHeatMaxAdd_Inferred));
    local_c = (float)dVar6;
  }
  return (int)(short)(int)local_c;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
