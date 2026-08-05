# Annotated low-level: __security_check_cookie

| Field | Value |
|---|---|
| Stable ID | `aa_006a3d0f` |
| VA | `0x006a3d0f` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a3d0f`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: This is an inlined function */

void __fastcall __security_check_cookie(int param_1)

{
  if (param_1 == DAT_00af5894) {
    return;
  }
  FUN_006a3cde();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
