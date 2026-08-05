# Annotated low-level: FUN_006ed4a0

| Field | Value |
|---|---|
| Stable ID | `aa_006ed4a0` |
| VA | `0x006ed4a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ed4a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ed4a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 int param_5)

{
  undefined ***pppuVar1;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined **local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined **local_40;
  undefined4 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_90 = -(float)param_3[4];
  local_a0 = *param_3;
  local_9c = param_3[1];
  local_8c = -(float)param_3[5];
  local_98 = param_3[2];
  local_94 = param_3[3];
  local_88 = -(float)param_3[6];
  local_80 = param_3[8];
  local_84 = -(float)param_3[7];
  local_7c = param_3[9];
  local_60 = param_3[4];
  local_5c = param_3[5];
  local_58 = param_3[6];
  local_54 = param_3[7];
  local_50 = param_4;
  local_6c = 0x7f7fffff;
  local_70 = &PTR_LAB_00a0e334;
  if (param_5 == 0) {
    pppuVar1 = (undefined ***)0x0;
  }
  else {
    local_40 = &PTR_LAB_00a0e334;
    local_30 = param_3[4];
    local_2c = param_3[5];
    local_28 = param_3[6];
    local_24 = param_3[7];
    local_20 = param_5;
    pppuVar1 = &local_40;
    local_3c = 0x7f7fffff;
  }
  FUN_006ec970(param_2,param_1,&local_a0,&local_70,pppuVar1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
