# Annotated low-level: FUN_008da7dc

| Field | Value |
|---|---|
| Stable ID | `aa_008da7dc` |
| VA | `0x008da7dc` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008da7dc`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 FUN_008da7dc(void)

{
  FUN_0094c630();
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
