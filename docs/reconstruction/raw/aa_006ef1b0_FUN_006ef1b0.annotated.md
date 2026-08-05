# Annotated low-level: FUN_006ef1b0

| Field | Value |
|---|---|
| Stable ID | `aa_006ef1b0` |
| VA | `0x006ef1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ef1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __thiscall FUN_006ef1b0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float fStack_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  local_14 = 0;
  local_20 = fVar1 * *(float *)(param_1 + 0x10) +
             fVar2 * *(float *)(param_1 + 0x14) + fVar3 * *(float *)(param_1 + 0x18);
  local_1c = fVar1 * *(float *)(param_1 + 0x20) +
             fVar2 * *(float *)(param_1 + 0x24) + fVar3 * *(float *)(param_1 + 0x28);
  local_18 = fVar1 * *(float *)(param_1 + 0x30) +
             fVar2 * *(float *)(param_1 + 0x34) + fVar3 * *(float *)(param_1 + 0x38);
  fVar4 = (float10)(**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(&local_20);
  fVar5 = (float10)fStack_24 * fVar4;
  fVar6 = (float10)local_20 * fVar4;
  fVar4 = (float10)local_1c * fVar4;
  return (float10)(float)(fVar5 * (float10)*(float *)(param_1 + 0x14) +
                          fVar6 * (float10)*(float *)(param_1 + 0x24) +
                          fVar4 * (float10)*(float *)(param_1 + 0x34) +
                         (float10)*(float *)(param_1 + 0x44)) * (float10)param_2[1] +
         (float10)(float)(fVar5 * (float10)*(float *)(param_1 + 0x10) +
                          fVar6 * (float10)*(float *)(param_1 + 0x20) +
                          fVar4 * (float10)*(float *)(param_1 + 0x30) +
                         (float10)*(float *)(param_1 + 0x40)) * (float10)*param_2 +
         (fVar5 * (float10)*(float *)(param_1 + 0x18) +
          fVar6 * (float10)*(float *)(param_1 + 0x28) + fVar4 * (float10)*(float *)(param_1 + 0x38)
         + (float10)*(float *)(param_1 + 0x48)) * (float10)param_2[2];
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
