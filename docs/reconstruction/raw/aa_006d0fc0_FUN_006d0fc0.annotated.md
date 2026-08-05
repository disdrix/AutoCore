# Annotated low-level: FUN_006d0fc0

| Field | Value |
|---|---|
| Stable ID | `aa_006d0fc0` |
| VA | `0x006d0fc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d0fc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_006d0fc0(int param_1,undefined4 param_2,float *param_3,float *param_4,undefined4 param_5,
            int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  fVar1 = g_flOne;
  *(undefined4 *)(param_1 + 100) = param_2;
  *(undefined4 *)(param_1 + 0x60) = param_5;
  *(int *)(param_1 + 0x5c) = param_6;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_6 + 4);
  *(float **)(param_1 + 0x10) = param_3;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  *(float *)(param_1 + 0x14) = fVar1 / param_3[3];
  local_1c = param_3[3] * _DAT_00a0e2ac;
  fVar1 = *param_4;
  fVar2 = *param_3;
  fVar3 = param_4[1];
  fVar4 = param_3[1];
  fVar5 = param_4[2];
  fVar6 = param_3[2];
  fVar7 = param_4[3];
  fVar8 = param_3[3];
  fVar9 = param_4[4];
  fVar10 = *param_3;
  fVar11 = param_4[5];
  fVar12 = param_3[1];
  fVar13 = param_4[6];
  fVar14 = param_3[2];
  fVar15 = param_4[7];
  fVar16 = param_3[3];
  *(float *)(param_1 + 0x20) = *param_4;
  *(float *)(param_1 + 0x24) = param_4[1];
  local_50 = (fVar1 - fVar2) * local_1c;
  *(float *)(param_1 + 0x28) = param_4[2];
  *(float *)(param_1 + 0x2c) = param_4[3];
  *(float *)(param_1 + 0x30) = param_4[4];
  local_4c = (fVar3 - fVar4) * local_1c;
  local_48 = (fVar5 - fVar6) * local_1c;
  local_44 = (fVar7 - fVar8) * local_1c;
  local_40 = (fVar9 - fVar10) * local_1c;
  local_3c = (fVar11 - fVar12) * local_1c;
  local_38 = (fVar13 - fVar14) * local_1c;
  local_34 = (fVar15 - fVar16) * local_1c;
  *(float *)(param_1 + 0x34) = param_4[5];
  *(float *)(param_1 + 0x38) = param_4[6];
  *(float *)(param_1 + 0x3c) = param_4[7];
  *(float *)(param_1 + 0x40) = param_4[8];
  *(float *)(param_1 + 0x44) = param_4[9];
  *(undefined1 *)(param_1 + 0x50) = 0;
  local_18 = 0;
  local_20 = 0;
  local_14 = 0;
  FUN_006cfe60(&local_30,param_3 + 0xc,&local_50);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
