# Annotated low-level: FUN_004cdd90

| Field | Value |
|---|---|
| Stable ID | `aa_004cdd90` |
| VA | `0x004cdd90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cdd90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_004cdd90(int param_1)

{
  return *(int *)(param_1 + 0xe4a4) + 0xe0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
