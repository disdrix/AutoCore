# Annotated low-level: FUN_009c3bf0

| Field | Value |
|---|---|
| Stable ID | `aa_009c3bf0` |
| VA | `0x009c3bf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c3bf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_009c3bf0(void)

{
  FUN_0054eef0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
