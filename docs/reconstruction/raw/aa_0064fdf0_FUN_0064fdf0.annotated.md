# Annotated low-level: FUN_0064fdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0064fdf0` |
| VA | `0x0064fdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064fdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall hkDefaultChassis_ctor(undefined4 *param_1,undefined4 param_2)

{
  FUN_0065eac0(param_2);
  *param_1 = &PTR_FUN_009e4fd0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
