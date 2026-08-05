# Annotated low-level: FUN_005bdcf0

| Field | Value |
|---|---|
| Stable ID | `aa_005bdcf0` |
| VA | `0x005bdcf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005bdcf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005bdcf0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(DAT_00b037f0 + 0x15) != '\0') {
    return 0;
  }
  uVar1 = FUN_005be460(param_2);
  FUN_005bdf00(param_1);
  if (*param_1 != 0) {
    iVar2 = FUN_0049a120();
    if (iVar2 != 0) {
      FUN_004b92b0(iVar2);
      FUN_005b8230(iVar2);
    }
  }
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
