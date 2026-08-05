# Annotated low-level: FUN_006e1ae0

| Field | Value |
|---|---|
| Stable ID | `aa_006e1ae0` |
| VA | `0x006e1ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006e1ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
char FUN_006e1ae0(int *param_1,int *param_2,int param_3,undefined4 param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  iVar4 = *param_1;
  iVar5 = *param_2;
  fVar1 = *(float *)(iVar5 + 0x10);
  fVar2 = *(float *)(iVar5 + 0x14);
  iVar6 = param_1[2];
  fVar3 = *(float *)(iVar5 + 0x18);
  iVar8 = param_2[2];
  pfVar7 = (float *)(iVar8 + 0x20);
  local_40 = fVar1 * *pfVar7 + fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +
             *(float *)(iVar8 + 0x50);
  local_3c = fVar1 * *(float *)(iVar8 + 0x24) +
             fVar2 * *(float *)(iVar8 + 0x34) + fVar3 * *(float *)(iVar8 + 0x44) +
             *(float *)(iVar8 + 0x54);
  local_38 = fVar1 * *(float *)(iVar8 + 0x28) +
             fVar2 * *(float *)(iVar8 + 0x38) + fVar3 * *(float *)(iVar8 + 0x48) +
             *(float *)(iVar8 + 0x58);
  local_34 = 0;
  fVar1 = *(float *)(iVar5 + 0x20);
  fVar2 = *(float *)(iVar5 + 0x24);
  fVar3 = *(float *)(iVar5 + 0x28);
  local_30 = fVar1 * *pfVar7 + fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +
             *(float *)(iVar8 + 0x50);
  local_2c = fVar1 * *(float *)(iVar8 + 0x24) +
             fVar2 * *(float *)(iVar8 + 0x34) + fVar3 * *(float *)(iVar8 + 0x44) +
             *(float *)(iVar8 + 0x54);
  local_28 = fVar1 * *(float *)(iVar8 + 0x28) +
             fVar2 * *(float *)(iVar8 + 0x38) + fVar3 * *(float *)(iVar8 + 0x48) +
             *(float *)(iVar8 + 0x58);
  local_24 = 0;
  fVar1 = *(float *)(iVar5 + 0x30);
  fVar2 = *(float *)(iVar5 + 0x34);
  fVar3 = *(float *)(iVar5 + 0x38);
  local_20 = fVar1 * *pfVar7 + fVar2 * *(float *)(iVar8 + 0x30) + fVar3 * *(float *)(iVar8 + 0x40) +
             *(float *)(iVar8 + 0x50);
  local_1c = fVar1 * *(float *)(iVar8 + 0x24) +
             fVar2 * *(float *)(iVar8 + 0x34) + fVar3 * *(float *)(iVar8 + 0x44) +
             *(float *)(iVar8 + 0x54);
  local_18 = fVar1 * *(float *)(iVar8 + 0x28) +
             fVar2 * *(float *)(iVar8 + 0x38) + fVar3 * *(float *)(iVar8 + 0x48) +
             *(float *)(iVar8 + 0x58);
  local_14 = 0;
  iVar8 = FUN_006f7820((float *)(iVar6 + 0x50),&local_40,param_4,&local_60);
  fVar1 = *(float *)(iVar4 + 0xc) + *(float *)(iVar5 + 0xc);
  if (local_50 < fVar1 + *(float *)(param_3 + 8)) {
    fVar2 = *(float *)(iVar5 + 0xc) - local_50;
    *param_5 = *(float *)(iVar6 + 0x50);
    param_5[1] = *(float *)(iVar6 + 0x54);
    param_5[2] = *(float *)(iVar6 + 0x58);
    param_5[3] = *(float *)(iVar6 + 0x5c);
    *param_5 = local_60 * fVar2 + *param_5;
    param_5[1] = local_5c * fVar2 + param_5[1];
    param_5[2] = local_58 * fVar2 + param_5[2];
    param_5[3] = local_54 * fVar2 + param_5[3];
    param_5[4] = local_60;
    param_5[5] = local_5c;
    param_5[6] = local_58;
    param_5[7] = local_54;
    param_5[3] = local_50 - fVar1;
    return (iVar8 != 0) + '\x01';
  }
  return '\0';
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
