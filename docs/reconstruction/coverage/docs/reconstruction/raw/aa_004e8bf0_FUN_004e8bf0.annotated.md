# Annotated low-level: FUN_004e8bf0

| Field | Value |
|---|---|
| Stable ID | `aa_004e8bf0` |
| VA | `0x004e8bf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004e8bf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004e8bf0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = g_flLevelUpUiBase_Inferred;
  fVar5 = g_flOne;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[3];
  fVar4 = *param_2;
  fVar7 = (fVar2 * fVar3 + *param_2 * fVar1) * g_flLevelUpUiBase_Inferred;
  *param_4 = *param_3 * (g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred) +
             *param_1;
  param_4[1] = *param_3 * fVar7 + param_1[1];
  param_4[2] = *param_3 * (fVar2 * fVar4 - fVar3 * fVar1) * fVar6 + param_1[2];
  fVar1 = param_2[2];
  fVar2 = *param_2;
  fVar3 = param_2[1];
  fVar4 = param_2[3];
  *param_4 = (fVar3 * fVar2 - fVar1 * param_2[3]) * fVar6 * param_3[1] + *param_4;
  param_4[1] = (fVar5 - (fVar1 * fVar1 + fVar2 * fVar2) * fVar6) * param_3[1] + param_4[1];
  param_4[2] = (fVar1 * fVar3 + fVar2 * fVar4) * fVar6 * param_3[1] + param_4[2];
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_2;
  fVar4 = param_2[3];
  *param_4 = param_3[2] * (fVar2 * fVar3 + fVar1 * fVar4) * fVar6 + *param_4;
  param_4[1] = param_3[2] * (fVar2 * fVar1 - fVar3 * fVar4) * fVar6 + param_4[1];
  param_4[2] = param_3[2] * (fVar5 - (fVar1 * fVar1 + fVar3 * fVar3) * fVar6) + param_4[2];
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
