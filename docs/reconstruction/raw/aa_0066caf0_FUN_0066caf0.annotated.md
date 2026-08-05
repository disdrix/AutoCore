# Annotated low-level: FUN_0066caf0

| Field | Value |
|---|---|
| Stable ID | `aa_0066caf0` |
| VA | `0x0066caf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0066caf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_0066caf0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009e7a88;
  param_1[2] = &PTR_LAB_009e7a78;
  FUN_0066e6c0();
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 1),0x24);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
