# Annotated low-level: BitStream_writeQuantizedFloat

| Field | Value |
|---|---|
| Stable ID | `aa_0042b910` |
| VA | `0x0042b910` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042b910`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void BitStream_writeQuantizedFloat(void)

{
  FUN_0042b980();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
