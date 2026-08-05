# Annotated low-level: Vehicle_SetCurrentShield

| Field | Value |
|---|---|
| Stable ID | `aa_00419140` |
| VA | `0x00419140` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00419140`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vehicle_SetCurrentShield
   
   Parameters:
     this       - vehicle (RE_VehicleCombatPoolFields*)
     nNewShield - desired current shield
   
   Algorithm:
     clamp to [0, MaxShield at +0x148]
     store at CurrentShield +0x144
   
   Returns: void
   
   NOTE: does NOT call NetObject_SetMaskBits — caller must dirty
   ShieldMask (0x04000000) when value changes. */

void __fastcall Vehicle_SetCurrentShield(VehicleCombatPools_Inferred *pVehicle,int nShield)

{
  int nMaxShield;
  int nClamped;
  int in_stack_00000004;
  
  nMaxShield = pVehicle->nMaxShield;
  nClamped = in_stack_00000004;
  if (nMaxShield <= in_stack_00000004) {
    nClamped = nMaxShield;
  }
  if (nClamped < 1) {
    nMaxShield = 0;
  }
  else if (in_stack_00000004 < nMaxShield) {
    pVehicle->nCurrentShield = in_stack_00000004;
    return;
  }
  pVehicle->nCurrentShield = nMaxShield;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
