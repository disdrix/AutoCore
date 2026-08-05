# Annotated low-level: FUN_004fa0f0

| Field | Value |
|---|---|
| Stable ID | `aa_004fa0f0` |
| VA | `0x004fa0f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004fa0f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004fa0f0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  if ((*(int *)(param_1 + 0x26c) != 0) && (*(int *)(*(int *)(param_1 + 0x26c) + 8) != 0)) {
    iVar4 = *(int *)(param_1 + 8);
    if (iVar4 == 0) {
      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
    }
    else {
      pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0xb0);
    }
    local_40 = *pfVar5;
    local_3c = pfVar5[1];
    local_38 = pfVar5[2];
    if (iVar4 == 0) {
      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
    }
    else {
      pfVar5 = (float *)(*(int *)(iVar4 + 0x3c) + 0x30);
    }
    fVar1 = *pfVar5;
    fVar2 = pfVar5[1];
    fVar3 = pfVar5[2];
    fVar9 = pfVar5[3];
    local_60 = fVar1;
    local_5c = fVar2;
    local_58 = fVar3;
    local_54 = fVar9;
    pfVar5 = (float *)FUN_004e9530(&local_20,param_1 + 0x3bc);
    local_4c = pfVar5[1];
    local_48 = pfVar5[2];
    fVar10 = *pfVar5;
    fVar8 = fVar9 * fVar9 * g_flLevelUpUiBase_Inferred - g_flOne;
    fVar9 = fVar9 * g_flLevelUpUiBase_Inferred;
    fVar7 = (local_48 * fVar3 + local_4c * fVar2 + fVar1 * fVar10) * g_flLevelUpUiBase_Inferred;
    local_1c = local_4c * fVar8;
    local_18 = local_48 * fVar8;
    local_6c = (local_48 * fVar2 - local_4c * fVar3) * fVar9 + fVar7 * fVar1 + fVar8 * fVar10 +
               local_40;
    local_68 = (fVar3 * fVar10 - local_48 * fVar1) * fVar9 + fVar2 * fVar7 + local_1c + local_3c;
    local_64 = (local_4c * fVar1 - fVar2 * fVar10) * fVar9 + fVar3 * fVar7 + local_18 + local_38;
    pfVar5 = (float *)FUN_004e96e0(&local_20,param_1 + 0x3c8);
    fVar1 = pfVar5[1];
    fVar2 = pfVar5[2];
    fVar3 = *pfVar5;
    fVar9 = pfVar5[3];
    fVar11 = fVar2 * local_60;
    fVar12 = fVar1 * local_60;
    fVar13 = local_5c * fVar3;
    fVar10 = fVar3 * local_60;
    fVar7 = fVar1 * local_5c;
    fVar8 = fVar2 * local_54;
    local_60 = fVar9 * local_60 + local_54 * fVar3 + (fVar2 * local_5c - fVar1 * local_58);
    local_5c = fVar9 * local_5c + fVar1 * local_54 + (local_58 * fVar3 - fVar11);
    local_54 = fVar9 * local_54 - (fVar2 * local_58 + fVar7 + fVar10);
    local_58 = fVar9 * local_58 + fVar8 + (fVar12 - fVar13);
    local_20 = local_60;
    puVar6 = (undefined4 *)FUN_004e87d0(&local_20,&local_60);
    local_30 = *puVar6;
    local_2c = puVar6[1];
    local_28 = puVar6[2];
    local_24 = puVar6[3];
    uVar14 = 3;
    (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 8) + 0x10))(3,&local_6c);
    FUN_0040cf90(uVar14);
    (**(code **)(**(int **)(*(int *)(param_1 + 0x26c) + 8) + 0x14))(auStack_34);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
