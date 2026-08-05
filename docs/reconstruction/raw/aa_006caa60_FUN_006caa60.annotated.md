# Annotated low-level: FUN_006caa60

| Field | Value |
|---|---|
| Stable ID | `aa_006caa60` |
| VA | `0x006caa60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006caa60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006caa60(int param_1)

{
  *(undefined ***)(param_1 + 0x100) = &PTR_LAB_009d2794;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
