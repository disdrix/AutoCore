# Annotated low-level: FUN_004bae00

| Field | Value |
|---|---|
| Stable ID | `aa_004bae00` |
| VA | `0x004bae00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bae00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_004bae00(int param_1,char param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if ((*(char *)(param_1 + 0xd) != '\0') && (*(int *)(param_1 + 8) != 0)) {
      FUN_00402c40();
      uVar1 = FUN_004bc530(param_3);
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x1d) = 0;
      return uVar1;
    }
  }
  else if ((*(char *)(param_1 + 0xc) != '\0') && (*(int *)(param_1 + 4) != 0)) {
    FUN_00402c40();
    uVar1 = FUN_004bc530(param_3);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x1d) = 0;
    return uVar1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
