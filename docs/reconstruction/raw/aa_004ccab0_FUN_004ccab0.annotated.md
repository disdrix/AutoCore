# Annotated low-level: FUN_004ccab0

| Field | Value |
|---|---|
| Stable ID | `aa_004ccab0` |
| VA | `0x004ccab0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ccab0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_004ccab0(int param_1)

{
  return param_1 + -0xe0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
