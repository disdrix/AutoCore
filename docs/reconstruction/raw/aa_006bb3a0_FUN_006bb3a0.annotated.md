# Annotated low-level: FUN_006bb3a0

| Field | Value |
|---|---|
| Stable ID | `aa_006bb3a0` |
| VA | `0x006bb3a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bb3a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bb3a0(int *param_1,undefined4 *param_2,float *param_3)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  undefined4 *puVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_40 = *param_2;
  uStack_2c = param_2[1];
  uStack_18 = param_2[2];
  local_20 = 0;
  uStack_1c = 0;
  uStack_14 = 0;
  iVar14 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (0 < param_1[1]) {
    iVar15 = 0;
    do {
      uVar2 = *(undefined4 *)(*param_1 + iVar15);
      iVar11 = *param_1 + iVar15;
      uVar3 = *(undefined4 *)(iVar11 + 4);
      uVar4 = *(undefined4 *)(iVar11 + 8);
      FUN_00645a70(&local_40);
      puVar12 = (undefined4 *)(*param_1 + iVar15);
      *puVar12 = uVar2;
      puVar12[1] = uVar3;
      puVar12[2] = uVar4;
      puVar12[3] = 0;
      pfVar1 = (float *)(*param_1 + iVar15);
      fVar5 = pfVar1[1];
      fVar6 = pfVar1[2];
      fVar7 = pfVar1[3];
      fVar8 = param_3[1];
      fVar9 = param_3[2];
      fVar10 = param_3[3];
      pfVar13 = (float *)(*param_1 + iVar15);
      *pfVar13 = *pfVar1 + *param_3;
      pfVar13[1] = fVar5 + fVar8;
      pfVar13[2] = fVar6 + fVar9;
      pfVar13[3] = fVar7 + fVar10;
      iVar14 = iVar14 + 1;
      iVar15 = iVar15 + 0x10;
    } while (iVar14 < param_1[1]);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
