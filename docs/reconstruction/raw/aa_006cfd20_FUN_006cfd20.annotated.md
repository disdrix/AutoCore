# Annotated low-level: FUN_006cfd20

| Field | Value |
|---|---|
| Stable ID | `aa_006cfd20` |
| VA | `0x006cfd20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cfd20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006cfd20(undefined4 *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  int iVar1;
  int local_50;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  *param_1 = param_4;
  param_1[0xc] = param_2;
  param_1[8] = (int)ROUND((*param_3 - *param_2) * param_2[3]) + -1;
  param_1[4] = (int)ROUND((param_3[4] - *(float *)param_1[0xc]) * ((float *)param_1[0xc])[3]) + -1;
  param_1[9] = (int)ROUND((param_3[1] - *(float *)(param_1[0xc] + 4)) *
                          *(float *)(param_1[0xc] + 0xc)) + -1;
  param_1[5] = (int)ROUND((param_3[5] - *(float *)(param_1[0xc] + 4)) *
                          *(float *)(param_1[0xc] + 0xc)) + -1;
  param_1[10] = (int)ROUND((param_3[2] - *(float *)(param_1[0xc] + 8)) *
                           *(float *)(param_1[0xc] + 0xc)) + -1;
  local_40 = (int)*(short *)((int)param_1 + 0x22);
  iVar1 = (int)ROUND((param_3[6] - *(float *)(param_1[0xc] + 8)) * *(float *)(param_1[0xc] + 0xc)) +
          -1;
  local_50 = *(short *)((int)param_1 + 0x12) + 1;
  local_3c = (int)*(short *)((int)param_1 + 0x26);
  local_4c = *(short *)((int)param_1 + 0x16) + 1;
  param_1[6] = iVar1;
  local_38 = (int)*(short *)((int)param_1 + 0x2a);
  local_48 = (iVar1 >> 0x10) + 1;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  FUN_006cf3b0(&local_50,param_2 + 0xc);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
