# Annotated low-level: thunk_FUN_0055cdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0055cf50` |
| VA | `0x0055cf50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055cf50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void thunk_FUN_0055cdf0(void)

{
  FUN_0055cdf0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
