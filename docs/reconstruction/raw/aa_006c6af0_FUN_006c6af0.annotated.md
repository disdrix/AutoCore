# Annotated low-level: FUN_006c6af0

| Field | Value |
|---|---|
| Stable ID | `aa_006c6af0` |
| VA | `0x006c6af0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c6af0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006c6af0(undefined4 *param_1)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_00a0d3c8;
  param_1[3] = 0x3d4ccccd;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x80000000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0x80000000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0x80000000;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
