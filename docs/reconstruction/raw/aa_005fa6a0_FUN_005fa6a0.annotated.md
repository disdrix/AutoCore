# Annotated low-level: FUN_005fa6a0

| Field | Value |
|---|---|
| Stable ID | `aa_005fa6a0` |
| VA | `0x005fa6a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fa6a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fa6a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dd1f8;
  free((void *)param_1[8]);
  *param_1 = &PTR_LAB_009d7af4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
