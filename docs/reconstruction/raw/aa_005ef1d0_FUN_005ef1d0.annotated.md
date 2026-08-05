# Annotated low-level: FUN_005ef1d0

| Field | Value |
|---|---|
| Stable ID | `aa_005ef1d0` |
| VA | `0x005ef1d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ef1d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ef1d0(float *param_1,float param_2,float param_3)

{
  float *in_EAX;
  float fVar1;
  
  fVar1 = g_flOne / DAT_00d027b0;
  *param_1 = fVar1 * DAT_00d02800;
  param_1[1] = fVar1 * DAT_00d02804;
  param_1[2] = fVar1 * DAT_00d02808;
  *in_EAX = (DAT_00d027e0 + DAT_00d027dc) * param_3;
  in_EAX[5] = (DAT_00d027d8 + DAT_00d027e0) * param_3;
  in_EAX[10] = (DAT_00d027d8 + DAT_00d027dc) * param_3;
  fVar1 = 0.0 - DAT_00d027a4 * param_3;
  in_EAX[1] = fVar1;
  in_EAX[4] = fVar1;
  fVar1 = 0.0 - DAT_00d027a8 * param_3;
  in_EAX[6] = fVar1;
  in_EAX[9] = fVar1;
  fVar1 = 0.0 - DAT_00d027ac * param_3;
  in_EAX[8] = fVar1;
  in_EAX[2] = fVar1;
  *in_EAX = *in_EAX - (param_1[1] * param_1[1] + param_1[2] * param_1[2]) * param_2;
  in_EAX[5] = in_EAX[5] - (*param_1 * *param_1 + param_1[2] * param_1[2]) * param_2;
  in_EAX[10] = in_EAX[10] - (*param_1 * *param_1 + param_1[1] * param_1[1]) * param_2;
  fVar1 = *param_1 * param_2 * param_1[1] + in_EAX[1];
  in_EAX[1] = fVar1;
  in_EAX[4] = fVar1;
  fVar1 = param_1[2] * param_2 * param_1[1] + in_EAX[6];
  in_EAX[6] = fVar1;
  in_EAX[9] = fVar1;
  fVar1 = param_1[2] * *param_1 * param_2 + in_EAX[8];
  in_EAX[8] = fVar1;
  in_EAX[2] = fVar1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
