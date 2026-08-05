# Annotated low-level: FUN_006c7bc0

| Field | Value |
|---|---|
| Stable ID | `aa_006c7bc0` |
| VA | `0x006c7bc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c7bc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_006c7bc0(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  *param_1 = &PTR_FUN_009e5fdc;
  *(undefined2 *)((int)param_1 + 6) = 1;
  uVar2 = *param_2;
  *param_1 = &PTR_FUN_009e6008;
  param_1[2] = uVar2;
  param_1[3] = param_2[1];
  *param_1 = &PTR_FUN_00a0d530;
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  if ((float)param_1[5] <= (float)param_1[4]) {
    fVar1 = (float)param_1[5];
  }
  else {
    fVar1 = (float)param_1[4];
  }
  param_1[7] = fVar1;
  if ((float)param_1[6] < fVar1) {
    fVar1 = (float)param_1[6];
  }
  param_1[7] = fVar1;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
