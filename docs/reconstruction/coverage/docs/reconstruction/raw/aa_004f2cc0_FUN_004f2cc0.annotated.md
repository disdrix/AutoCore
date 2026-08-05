# Annotated low-level: FUN_004f2cc0

| Field | Value |
|---|---|
| Stable ID | `aa_004f2cc0` |
| VA | `0x004f2cc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f2cc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004f2cc0(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0x14))(param_2,0x50);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
