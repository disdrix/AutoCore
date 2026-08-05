# Annotated low-level: FUN_006cf2d0

| Field | Value |
|---|---|
| Stable ID | `aa_006cf2d0` |
| VA | `0x006cf2d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cf2d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006cf2d0(undefined4 *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *param_1 = param_4;
  param_1[4] = (int)ROUND((*param_3 - *param_2) * param_2[3]) + -1;
  param_1[5] = (int)ROUND((param_3[1] - param_2[1]) * param_2[3]) + -1;
  param_1[6] = (int)ROUND((param_3[2] - param_2[2]) * param_2[3]) + -1;
  fVar1 = param_3[3];
  fVar2 = param_2[3];
  local_28 = (int)*(short *)((int)param_1 + 0x12);
  param_1[7] = (int)ROUND(fVar1 * fVar2);
  local_24 = (int)*(short *)((int)param_1 + 0x16);
  local_1c = ((int)ROUND(fVar1 * fVar2) >> 0x10) + 1;
  local_20 = (int)*(short *)((int)param_1 + 0x1a);
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_4 = 0;
  local_8 = 0x10;
  FUN_006cec90(&local_28,param_2 + 0xc);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
