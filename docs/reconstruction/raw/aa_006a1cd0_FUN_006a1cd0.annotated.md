# Annotated low-level: FUN_006a1cd0

| Field | Value |
|---|---|
| Stable ID | `aa_006a1cd0` |
| VA | `0x006a1cd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a1cd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_006a1cd0(undefined4 param_1)

{
  if (DAT_00d08f98 == '\0') {
    FUN_006a1c00(0xffffffff);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
