# Annotated low-level: FUN_0042aea0

| Field | Value |
|---|---|
| Stable ID | `aa_0042aea0` |
| VA | `0x0042aea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0042aea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0042aea0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_009d7af4;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[10] = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
