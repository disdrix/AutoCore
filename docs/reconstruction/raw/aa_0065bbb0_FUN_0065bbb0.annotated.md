# Annotated low-level: FUN_0065bbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0065bbb0` |
| VA | `0x0065bbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065bbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0065bbb0(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_005edf20();
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
