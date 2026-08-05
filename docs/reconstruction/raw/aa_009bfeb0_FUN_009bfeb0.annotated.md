# Annotated low-level: FUN_009bfeb0

| Field | Value |
|---|---|
| Stable ID | `aa_009bfeb0` |
| VA | `0x009bfeb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009bfeb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_009bfeb0(void)

{
  FUN_00445160();
  _atexit((_func_4879 *)&LAB_009c3350);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
