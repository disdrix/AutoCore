# Annotated low-level: FUN_006ea1b0

| Field | Value |
|---|---|
| Stable ID | `aa_006ea1b0` |
| VA | `0x006ea1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ea1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ea1b0(undefined4 *param_1,int param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float unaff_EBX;
  float unaff_ESI;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined1 local_50 [76];
  
  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);
  (**(code **)(*(int *)*param_1 + 0x18))(local_50,*(undefined4 *)(param_3 + 8),param_4);
  FUN_005d6a40(*(int *)(param_2 + 8) + 0x20,param_3 + 0x10);
  fStack_6c = unaff_ESI;
  if (g_flZero < unaff_ESI) {
    fStack_6c = 0.0;
  }
  fVar1 = unaff_EBX;
  if (g_flZero < unaff_EBX) {
    fVar1 = g_flZero;
  }
  fVar2 = fStack_74;
  if (g_flZero < fStack_74) {
    fVar2 = g_flZero;
  }
  fVar3 = fStack_70;
  if (g_flZero < fStack_70) {
    fVar3 = g_flZero;
  }
  if (unaff_ESI < g_flZero) {
    unaff_ESI = g_flZero;
  }
  if (unaff_EBX < g_flZero) {
    unaff_EBX = g_flZero;
  }
  if (fStack_74 < g_flZero) {
    fStack_74 = g_flZero;
  }
  if (fStack_70 < g_flZero) {
    fStack_70 = g_flZero;
  }
  *param_4 = fStack_6c + *param_4;
  param_4[1] = fVar1 + param_4[1];
  param_4[2] = fVar2 + param_4[2];
  param_4[3] = fVar3 + param_4[3];
  param_4[4] = unaff_ESI + param_4[4];
  param_4[5] = unaff_EBX + param_4[5];
  param_4[6] = fStack_74 + param_4[6];
  param_4[7] = fStack_70 + param_4[7];
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
