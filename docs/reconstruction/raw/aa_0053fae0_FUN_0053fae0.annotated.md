# Annotated low-level: FUN_0053fae0

| Field | Value |
|---|---|
| Stable ID | `aa_0053fae0` |
| VA | `0x0053fae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053fae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0053fae0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = param_3[1];
  fVar2 = param_2[2];
  fVar5 = *param_3 * param_2[2] - param_3[2] * *param_2;
  fVar6 = *param_2 * param_3[1] - param_2[1] * *param_3;
  fVar3 = param_3[2];
  fVar4 = param_2[1];
  param_1[2] = fVar6;
  param_1[1] = fVar5;
  *param_1 = fVar3 * fVar4 - fVar1 * fVar2;
  param_1[3] = 0.0;
  fVar1 = param_2[3];
  *param_1 = *param_3 * fVar1 + *param_1;
  fVar5 = param_3[1] * fVar1 + fVar5;
  param_1[1] = fVar5;
  param_1[2] = param_3[2] * fVar1 + fVar6;
  param_1[3] = param_3[3] * fVar1;
  fVar1 = param_3[3];
  *param_1 = *param_2 * fVar1 + *param_1;
  param_1[1] = param_2[1] * fVar1 + fVar5;
  param_1[2] = fVar1 * param_2[2] + param_1[2];
  param_1[3] = fVar1 * param_2[3] + param_1[3];
  param_1[3] = param_3[3] * param_2[3] -
               (*param_2 * *param_3 + param_2[1] * param_3[1] + param_3[2] * param_2[2]);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
