# Annotated low-level: VehicleEngine_torqueCurve2D

| Field | Value |
|---|---|
| Stable ID | `aa_004a9750` |
| VA | `0x004a9750` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004a9750`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* VehicleEngine::torqueCurve2D — 2D byte-indexed torque curve lookup.
   
   Called from VehicleAction_calcWheelTorque (0x598040) as:
     fVar8 = torqueCurve2D(rpm, throttle)  → returns normalized torque factor [0..1]
   
   Structure (param_1 = engine component):
     param_1+0x0c = enabled flag (byte; if 0 → return DAT_00a0f2a0 = 1.0)
     param_1+0x18 = RPM range scale (float; multiplied by DAT_00a0f298=0.5 to get base RPM)
     param_1+0x10 = table rows (int; X axis = RPM bins)
     param_1+0x14 = table cols (int; Y axis = throttle bins)
     param_1+0x3dc = 2D byte table (rows * cols bytes, each & 7 = index into float array)
     param_1+0x344 = float[8] lookup array (the 8 torque-factor values; index 0 =
   default/out-of-range)
   
   Algorithm:
     fVar4 = param_1+0x18 * 0.5          // base RPM for binning
     fVar5 = 1.0 / (param_1+0x18)        // inverse RPM range
     iVar3 = int((rpm - fVar4) * fVar5)  // X bin index
     iVar2 = int((throttle - fVar4) * fVar5) // Y bin index
     if in-range: byte = table[rows * iVar3 + iVar2] & 7; return float[byte]
     else: return float[0]  (default)
   
   This is Havok's hkVehicleDefaultEngine::calcEngineTorque shape: a 2D table of
   torque factors indexed by (RPM, throttle), with 8 discrete factor levels (the & 7).
   The float[8] array at +0x344 holds the actual factor values (typically mapping to
   the MinTorqueFactor/MaxTorqueFactor endpoints + intermediate values).
   
   For the JS port: this maps to a piecewise-linear interpolation between the 4 RPM
   breakpoints (MinimumRPM, OptimumRPMMin, OptimumRPMMax, MaximumRPMMax) × 2 throttle
   factors (MinTorqueFactor, MaxTorqueFactor) from VehicleSpecific. The exact 8-level
   quantization is an AA-specific detail; a smooth LERP between the 4 breakpoints
   captures the same shape.
   
   Key constants:
     DAT_00a0f298 = 0.5  (RPM binning base factor)
     DAT_00a0f2a0 = 1.0  (default return when engine disabled) */

float10 __thiscall VehicleEngine_torqueCurve2D(int param_1,float param_2,float param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    return (float10)g_flOne;
  }
  fVar4 = *(float *)(param_1 + 0x18) * DAT_00a0f298;
  fVar5 = g_flOne / *(float *)(param_1 + 0x18);
  iVar3 = (int)((param_2 - fVar4) * fVar5);
  iVar2 = (int)((param_3 - fVar4) * fVar5);
  if ((((-1 < iVar3) && (iVar3 < *(int *)(param_1 + 0x10))) && (-1 < iVar2)) &&
     (iVar2 < *(int *)(param_1 + 0x14))) {
    bVar1 = *(byte *)(*(int *)(param_1 + 0x14) * iVar3 + *(int *)(param_1 + 0x3dc) + iVar2) & 7;
    if (7 < bVar1) {
      FUN_007a4480(0,"VOG_DEBUG_STOP");
      return (float10)g_flOne;
    }
    return (float10)*(float *)(param_1 + 0x344 + (char)bVar1 * 4);
  }
  return (float10)*(float *)(param_1 + 0x344);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
