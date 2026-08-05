# Annotated low-level: FUN_0040cbe0

| Field | Value |
|---|---|
| Stable ID | `aa_0040cbe0` |
| VA | `0x0040cbe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040cbe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 __fastcall FUN_0040cbe0(int param_1)

{
  return *(undefined1 *)(param_1 + 0xc9);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
