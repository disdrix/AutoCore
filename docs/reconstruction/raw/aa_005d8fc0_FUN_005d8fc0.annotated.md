# Annotated low-level: FUN_005d8fc0

| Field | Value |
|---|---|
| Stable ID | `aa_005d8fc0` |
| VA | `0x005d8fc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d8fc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_005d8fc0(undefined4 param_1)

{
  int iVar1;
  undefined4 unaff_retaddr;
  undefined4 uVar2;
  
  uVar2 = 0xc;
  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x68,0xc);
  if (iVar1 != 0) {
    uVar2 = FUN_005d89f0(uVar2,unaff_retaddr,param_1);
    return uVar2;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
