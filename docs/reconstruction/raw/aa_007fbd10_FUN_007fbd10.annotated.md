# Annotated low-level: FUN_007fbd10

| Field | Value |
|---|---|
| Stable ID | `aa_007fbd10` |
| VA | `0x007fbd10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbd10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint FUN_007fbd10(void)

{
  uint uVar1;
  
  if (DAT_00d1b251 == 1) {
    return 1;
  }
  uVar1 = DAT_00d1b251 - 2;
  if (uVar1 != 0) {
    return uVar1 & 0xffffff00;
  }
  return 2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
