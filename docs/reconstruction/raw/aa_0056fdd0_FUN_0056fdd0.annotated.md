# Annotated low-level: FUN_0056fdd0

| Field | Value |
|---|---|
| Stable ID | `aa_0056fdd0` |
| VA | `0x0056fdd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0056fdd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 FUN_0056fdd0(undefined4 param_1)

{
  int iVar1;
  
  FUN_005c9a00(param_1);
  iVar1 = FUN_004ccf00(param_1);
  return *(undefined1 *)(iVar1 + 2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
