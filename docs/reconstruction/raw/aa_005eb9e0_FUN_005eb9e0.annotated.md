# Annotated low-level: FUN_005eb9e0

| Field | Value |
|---|---|
| Stable ID | `aa_005eb9e0` |
| VA | `0x005eb9e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eb9e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_005eb9e0(int param_1,float *param_2,float *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_78;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float local_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  
  *(float *)(param_1 + 0xb0) = *param_2;
  *(float *)(param_1 + 0xb4) = param_2[1];
  *(float *)(param_1 + 0xb8) = param_2[2];
  *(float *)(param_1 + 0xbc) = param_2[3];
  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
            (param_1 + 0x80,*(float *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8) + param_3[5],
             &local_60);
  fStack_3c = *param_3 - *param_2;
  fStack_38 = param_3[1] - param_2[1];
  fStack_34 = param_3[2] - param_2[2];
  fStack_30 = param_3[3] - param_2[3];
  fVar4 = 0.0;
  if (fStack_3c <= 0.0) {
    fVar4 = fStack_3c;
  }
  fStack_78 = 0.0;
  if (fStack_38 <= 0.0) {
    fStack_78 = fStack_38;
  }
  fVar9 = 0.0;
  if (fStack_34 <= 0.0) {
    fVar9 = fStack_34;
  }
  fVar8 = 0.0;
  if (fStack_30 <= 0.0) {
    fVar8 = fStack_30;
  }
  fVar5 = fStack_3c;
  if (fStack_3c < 0.0) {
    fVar5 = 0.0;
  }
  fVar7 = fStack_38;
  if (fStack_38 < 0.0) {
    fVar7 = 0.0;
  }
  fVar6 = fStack_34;
  if (fStack_34 < 0.0) {
    fVar6 = 0.0;
  }
  fVar3 = 0.0;
  if (0.0 <= fStack_30) {
    fVar3 = fStack_30;
  }
  fStack_6c = fVar4 + fStack_6c;
  fStack_68 = fStack_68 + fStack_78;
  fStack_64 = fStack_64 + fVar9;
  local_60 = local_60 + fVar8;
  fStack_5c = fStack_5c + fVar5;
  fStack_58 = fStack_58 + fVar7;
  fStack_54 = fStack_54 + fVar6;
  fStack_50 = fStack_50 + fVar3;
  FUN_00634450(&fStack_6c);
  iVar1 = *(int *)(param_1 + 0xc4);
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + 0xcc);
  uStack_4c = *puVar2;
  uStack_48 = puVar2[1];
  fStack_28 = SQRT(fStack_3c * fStack_3c + fStack_38 * fStack_38 + fStack_34 * fStack_34);
  uStack_40 = puVar2[3];
  fStack_44 = param_3[5];
  fStack_2c = param_3[4];
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xc0) + iVar1 * 8) + 0xc))
              (param_1 + 0xc,*(undefined4 *)(*(int *)(param_1 + 0xc0) + iVar1 * 8 + 4),&uStack_4c,
               param_4,param_5);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
