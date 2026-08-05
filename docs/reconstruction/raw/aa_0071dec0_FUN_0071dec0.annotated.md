# Annotated low-level: FUN_0071dec0

| Field | Value |
|---|---|
| Stable ID | `aa_0071dec0` |
| VA | `0x0071dec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071dec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_0071dec0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_c [4];
  undefined4 local_8;
  undefined1 local_4 [4];
  
  uVar1 = param_2;
  if (*(int *)(param_2 + 0x4044) == 0) {
    FUN_00445170(&param_2);
  }
  else {
    FUN_007693e0(&param_2);
  }
  uVar2 = param_2 & 0xff;
  if (uVar2 != 0) {
    param_2 = param_1 + 0x10;
    do {
      if (*(int *)(uVar1 + 0x4044) == 0) {
        if ((*(int *)(uVar1 + 0x18) + 1 <= *(int *)(uVar1 + 0x20)) ||
           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&
            (0 < *(int *)(uVar1 + 0x20))))) {
          local_c[0] = *(undefined1 *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);
          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 1;
        }
      }
      else {
        FUN_007693e0(local_c);
      }
      if (*(int *)(uVar1 + 0x4044) == 0) {
        if ((*(int *)(uVar1 + 0x18) + 4 <= *(int *)(uVar1 + 0x20)) ||
           ((iVar3 = FUN_00435df0(*(int *)(uVar1 + 0x1c) + *(int *)(uVar1 + 0x18)), -1 < iVar3 &&
            (3 < *(int *)(uVar1 + 0x20))))) {
          local_8 = *(undefined4 *)(*(int *)(uVar1 + 0x18) + uVar1 + 0x2c);
          *(int *)(uVar1 + 0x18) = *(int *)(uVar1 + 0x18) + 4;
        }
      }
      else {
        FUN_007689e0(&local_8);
      }
      FUN_00718fd0(uVar1,local_4);
      FUN_00480ca0();
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
