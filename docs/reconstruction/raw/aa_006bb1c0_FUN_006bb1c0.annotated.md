# Annotated low-level: FUN_006bb1c0

| Field | Value |
|---|---|
| Stable ID | `aa_006bb1c0` |
| VA | `0x006bb1c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bb1c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bb1c0(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40 [6];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  
  FUN_006bb0c0(param_1,&local_90);
  *param_3 = local_90 + local_80;
  param_3[1] = local_8c + local_7c;
  param_3[2] = local_88 + local_78;
  param_3[3] = local_84 + local_74;
  *param_3 = *param_3 * 0.5;
  param_3[1] = param_3[1] * 0.5;
  param_3[2] = param_3[2] * 0.5;
  param_3[3] = param_3[3] * 0.5;
  *param_2 = local_80 - local_90;
  param_2[1] = local_7c - local_8c;
  param_2[2] = local_78 - local_88;
  param_2[3] = local_74 - local_84;
  fStack_18 = g_flOne;
  if (_DAT_00a0d150 < param_2[2]) {
    fStack_18 = g_flOne / param_2[2];
  }
  local_40[5] = g_flOne;
  if (_DAT_00a0d150 < param_2[1]) {
    local_40[5] = g_flOne / param_2[1];
  }
  local_40[0] = g_flOne;
  if (_DAT_00a0d150 < *param_2) {
    local_40[0] = g_flOne / *param_2;
  }
  local_40[1] = 0.0;
  local_40[2] = 0.0;
  local_40[3] = 0.0;
  local_40[4] = 0.0;
  uStack_28 = 0;
  uStack_24 = 0;
  iVar3 = 0;
  local_20 = 0;
  uStack_1c = 0;
  uStack_14 = 0;
  local_94 = 0;
  if (0 < param_1[1]) {
    do {
      local_70 = *(float *)(*param_1 + iVar3) - *param_3;
      iVar1 = *param_1 + iVar3;
      local_60 = *(float *)(iVar1 + 4) - param_3[1];
      local_88 = *(float *)(iVar1 + 8) - param_3[2];
      local_6c = DAT_00bc5630;
      local_68 = DAT_00bc5630;
      local_5c = DAT_00bc5634;
      local_58 = DAT_00bc5634;
      local_48 = DAT_00bc5638;
      local_64 = 0;
      local_54 = 0;
      local_4c = DAT_00bc5638;
      local_44 = 0;
      local_50 = local_88;
      FUN_00645a70(local_40);
      pfVar2 = (float *)(*param_1 + iVar3);
      *pfVar2 = local_70;
      pfVar2[1] = local_60;
      iVar3 = iVar3 + 0x10;
      pfVar2[2] = local_50;
      pfVar2[3] = 0.0;
      local_94 = local_94 + 1;
    } while (local_94 < param_1[1]);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
