# Annotated low-level: FUN_005ebec0

| Field | Value |
|---|---|
| Stable ID | `aa_005ebec0` |
| VA | `0x005ebec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ebec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005ebec0(undefined4 *param_1,undefined4 param_2)

{
  FUN_005eb210(param_2);
  *param_1 = &PTR_FUN_009dce90;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0x80000000;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
