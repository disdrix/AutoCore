# Annotated low-level: FUN_006d1ee0

| Field | Value |
|---|---|
| Stable ID | `aa_006d1ee0` |
| VA | `0x006d1ee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d1ee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006d1ee0(int param_1,float *param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * *(float *)(param_1 + 0x20) +
          fVar2 * *(float *)(param_1 + 0x24) + fVar3 * *(float *)(param_1 + 0x28);
  fVar5 = fVar1 * *(float *)(param_1 + 0x30) +
          fVar2 * *(float *)(param_1 + 0x34) + fVar3 * *(float *)(param_1 + 0x38);
  if (fVar5 <= fVar4) {
    uVar6 = 0x10;
  }
  else {
    uVar6 = 0x20;
    fVar4 = fVar5;
  }
  if (fVar4 < fVar1 * *(float *)(param_1 + 0x10) +
              fVar2 * *(float *)(param_1 + 0x14) + fVar3 * *(float *)(param_1 + 0x18)) {
    uVar6 = 0;
  }
  *param_3 = *(undefined4 *)(uVar6 + 0x10 + param_1);
  param_3[1] = *(undefined4 *)(uVar6 + 0x14 + param_1);
  param_3[2] = *(undefined4 *)(uVar6 + 0x18 + param_1);
  param_3[3] = *(undefined4 *)(uVar6 + 0x1c + param_1);
  param_3[3] = uVar6 | 0x3f000000;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
