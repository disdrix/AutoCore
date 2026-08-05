# Annotated low-level: FUN_009c55ca

| Field | Value |
|---|---|
| Stable ID | `aa_009c55ca` |
| VA | `0x009c55ca` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_009c55ca`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_009c55ca(void)

{
  FUN_006a40b0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
