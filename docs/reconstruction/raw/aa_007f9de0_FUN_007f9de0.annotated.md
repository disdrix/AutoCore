# Annotated low-level: FUN_007f9de0

| Field | Value |
|---|---|
| Stable ID | `aa_007f9de0` |
| VA | `0x007f9de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007f9de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007f9de0(void)

{
  FUN_007f9cc0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
