# Annotated low-level: FUN_005eadb0

| Field | Value |
|---|---|
| Stable ID | `aa_005eadb0` |
| VA | `0x005eadb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eadb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005eadb0(float *param_1,float *param_2)

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
  undefined1 local_2d [13];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = param_2[2];
  local_14 = param_2[3];
  FUN_00568100(local_2d);
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar9 = param_2[2] * g_flLevelUpUiBase_Inferred;
  fVar12 = *param_2 * *param_2 * g_flLevelUpUiBase_Inferred;
  fVar11 = *param_2 * g_flLevelUpUiBase_Inferred * param_2[3];
  fVar4 = param_2[3];
  fVar10 = param_2[1] * g_flLevelUpUiBase_Inferred;
  fVar5 = *param_2;
  fVar6 = param_2[1];
  fVar7 = param_2[3];
  *param_1 = g_flOne - (fVar3 * fVar9 + fVar6 * fVar10);
  param_1[1] = fVar9 * fVar4 + fVar5 * fVar10;
  param_1[2] = fVar1 * fVar9 - fVar10 * fVar7;
  param_1[3] = 0.0;
  fVar8 = g_flOne;
  param_1[4] = fVar5 * fVar10 - fVar9 * fVar4;
  param_1[5] = fVar8 - (fVar3 * fVar9 + fVar12);
  param_1[7] = 0.0;
  param_1[6] = fVar11 + fVar2 * fVar9;
  param_1[8] = fVar10 * fVar7 + fVar1 * fVar9;
  param_1[9] = fVar2 * fVar9 - fVar11;
  param_1[10] = fVar8 - (fVar6 * fVar10 + fVar12);
  param_1[0xb] = 0.0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
