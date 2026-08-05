# Annotated low-level: FUN_007fbcf0

| Field | Value |
|---|---|
| Stable ID | `aa_007fbcf0` |
| VA | `0x007fbcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fbcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fbcf0(void)

{
  int iVar1;
  
  if (DAT_00d1b252 == 1) {
    return 0x4b;
  }
  iVar1 = DAT_00d1b252 - 2;
  if (iVar1 != 0) {
    return CONCAT22((short)((uint)iVar1 >> 0x10),100);
  }
  return 0x32;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
