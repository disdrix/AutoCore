# Annotated low-level: FUN_004c2eb0

| Field | Value |
|---|---|
| Stable ID | `aa_004c2eb0` |
| VA | `0x004c2eb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c2eb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c2eb0(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(((float)param_1 - DAT_00aaa6c4) * _DAT_009cb8dc);
  return uVar1 & ((int)uVar1 < 0) - 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
