# Annotated low-level: FUN_005cadd0

| Field | Value |
|---|---|
| Stable ID | `aa_005cadd0` |
| VA | `0x005cadd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cadd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_005cadd0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x80))();
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = FUN_005c9c50();
      iVar1 = *(int *)(iVar3 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) {
LAB_005cae68:
                    /* WARNING: Subroutine does not return */
        FUN_004ccf30();
      }
      *(undefined4 *)(iVar1 + uVar4 * 4) = *(undefined4 *)(param_2 + uVar4 * 4);
      iVar3 = FUN_005c9c50();
      iVar1 = *(int *)(iVar3 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) goto LAB_005cae68;
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x68))
                (*(undefined2 *)(iVar1 + uVar4 * 4),param_3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
