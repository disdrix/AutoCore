# Annotated low-level: FUN_006eefc0

| Field | Value |
|---|---|
| Stable ID | `aa_006eefc0` |
| VA | `0x006eefc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006eefc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006eefc0(float *param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  
  *param_4 = *param_1;
  param_4[1] = param_1[1];
  param_1 = param_1 + 2;
  param_4[2] = *param_1;
  param_4[3] = 0.0;
  param_4[4] = *param_4;
  param_4[5] = param_4[1];
  param_4[6] = param_4[2];
  param_4[7] = param_4[3];
  if (0 < param_2) {
    do {
      fVar1 = param_1[-2];
      if (param_1[-2] < param_4[4]) {
        fVar1 = param_4[4];
      }
      param_4[4] = fVar1;
      fVar1 = param_1[-1];
      if (param_1[-1] < param_4[5]) {
        fVar1 = param_4[5];
      }
      param_4[5] = fVar1;
      fVar1 = *param_1;
      if (*param_1 < param_4[6]) {
        fVar1 = param_4[6];
      }
      param_4[6] = fVar1;
      fVar1 = param_1[-2];
      if (*param_4 < param_1[-2]) {
        fVar1 = *param_4;
      }
      *param_4 = fVar1;
      fVar1 = param_1[-1];
      if (param_4[1] < param_1[-1]) {
        fVar1 = param_4[1];
      }
      param_4[1] = fVar1;
      fVar1 = *param_1;
      if (param_4[2] < *param_1) {
        fVar1 = param_4[2];
      }
      param_1 = (float *)((int)param_1 + param_3);
      param_4[2] = fVar1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
