# Annotated low-level: FUN_0096fdf0

| Field | Value |
|---|---|
| Stable ID | `aa_0096fdf0` |
| VA | `0x0096fdf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0096fdf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0096fdf0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 4))) {
    iVar1 = FUN_0073df30(DAT_00d1f61c,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0043ed00();
    FUN_0043ee30();
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
