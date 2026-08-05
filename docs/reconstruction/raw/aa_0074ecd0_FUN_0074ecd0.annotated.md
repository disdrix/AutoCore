# Annotated low-level: FUN_0074ecd0

| Field | Value |
|---|---|
| Stable ID | `aa_0074ecd0` |
| VA | `0x0074ecd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074ecd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0074ecd0(void)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = FUN_00963950(in_EAX);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  FUN_0074eaa0();
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
