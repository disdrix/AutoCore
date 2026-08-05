# Annotated low-level: FUN_0084fbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0084fbb0` |
| VA | `0x0084fbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0084fbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0084fbb0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 300))(param_2);
  FUN_0084f760();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
