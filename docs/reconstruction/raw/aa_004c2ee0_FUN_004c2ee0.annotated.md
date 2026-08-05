# Annotated low-level: FUN_004c2ee0

| Field | Value |
|---|---|
| Stable ID | `aa_004c2ee0` |
| VA | `0x004c2ee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c2ee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004c2ee0(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x13c) = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
