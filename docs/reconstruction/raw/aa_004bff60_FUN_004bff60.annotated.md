# Annotated low-level: FUN_004bff60

| Field | Value |
|---|---|
| Stable ID | `aa_004bff60` |
| VA | `0x004bff60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bff60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_004bff60(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009cb624;
  _eh_vector_constructor_iterator_(param_1 + 1,0xc,9,FUN_00569290,FUN_004c0520);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
