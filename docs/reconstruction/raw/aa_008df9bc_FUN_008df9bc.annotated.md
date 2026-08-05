# Annotated low-level: FUN_008df9bc

| Field | Value |
|---|---|
| Stable ID | `aa_008df9bc` |
| VA | `0x008df9bc` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008df9bc`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_008df9bc(void)

{
  FUN_007fbb30();
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
