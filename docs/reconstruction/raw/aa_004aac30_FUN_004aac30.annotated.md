# Annotated low-level: FUN_004aac30

| Field | Value |
|---|---|
| Stable ID | `aa_004aac30` |
| VA | `0x004aac30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004aac30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_004aac30(void)

{
  FUN_004aa300();
  FUN_004930b0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
