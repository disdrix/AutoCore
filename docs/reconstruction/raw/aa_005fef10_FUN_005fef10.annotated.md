# Annotated low-level: FUN_005fef10

| Field | Value |
|---|---|
| Stable ID | `aa_005fef10` |
| VA | `0x005fef10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fef10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall FUN_005fef10(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_004ce940();
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) +
                           0x3c) + 0x3ac);
  uVar5 = 0;
  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0x60))
                    ();
  if (iVar3 != 0) {
    do {
      uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) +
                          0x5c))(uVar5);
      iVar3 = FUN_00508b10(uVar2);
      if (iVar3 == 0) {
        iVar3 = *(int *)(*(int *)(param_1 + -0xdc) + 4);
        uVar2 = (**(code **)(*(int *)(iVar3 + param_1 + -0xdc) + 0x5c))
                          (uVar5,*(undefined4 *)(*(int *)(iVar3 + -0x34 + param_1) + 0x34),
                           *(undefined4 *)(iVar3 + param_1 + 0x84),
                           *(undefined4 *)(iVar3 + 0x88 + param_1));
        FUN_007a4480(1,"Armor modifier %d does not exist for item %d %I64d",uVar2);
      }
      uVar5 = uVar5 + 1;
      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) +
                          0x60))();
    } while (uVar5 < uVar4);
  }
  return (float10)iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
