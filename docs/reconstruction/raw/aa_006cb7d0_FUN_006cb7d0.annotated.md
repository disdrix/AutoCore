# Annotated low-level: FUN_006cb7d0

| Field | Value |
|---|---|
| Stable ID | `aa_006cb7d0` |
| VA | `0x006cb7d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cb7d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined ** FUN_006cb7d0(void)

{
  return &PTR_PTR_00af58a4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
