# Raw capture: Vehicle_SetCurrentShield

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419140` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00419140` |
| **Canonical name** | `Vehicle_SetCurrentShield` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
