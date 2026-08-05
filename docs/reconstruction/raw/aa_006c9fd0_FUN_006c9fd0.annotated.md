# Annotated low-level: FUN_006c9fd0

| Field | Value |
|---|---|
| Stable ID | `aa_006c9fd0` |
| VA | `0x006c9fd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c9fd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_006c9fd0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  param_1[3] = param_4;
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_00a0d790;
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  param_1[6] = param_2[2];
  param_1[7] = param_2[3];
  param_1[8] = *param_3;
  param_1[9] = param_3[1];
  param_1[10] = param_3[2];
  param_1[0xb] = param_3[3];
  param_1[7] = param_4;
  param_1[0xb] = param_4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
