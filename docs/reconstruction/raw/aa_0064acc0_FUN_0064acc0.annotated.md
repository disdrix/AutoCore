# Annotated low-level: FUN_0064acc0

| Field | Value |
|---|---|
| Stable ID | `aa_0064acc0` |
| VA | `0x0064acc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064acc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0064acc0(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 6);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  iVar5 = *(int *)(param_2 + 0x10);
  piVar1 = (int *)(param_1 + 0xc);
  if ((int)(*(uint *)(param_1 + 0x14) & 0x7fffffff) < iVar5) {
    iVar5 = *(int *)(param_1 + 0x10);
    puVar3 = (undefined4 *)*piVar1;
    if (0 < iVar5) {
      do {
        (**(code **)*puVar3)(0);
        puVar3 = puVar3 + 7;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar5 = *(int *)(param_2 + 0x10);
    uVar2 = *(uint *)(param_1 + 0x14) & 0x7fffffff;
    if ((int)uVar2 < iVar5) {
      iVar4 = uVar2 * 2;
      if (iVar4 <= iVar5) {
        iVar4 = iVar5;
      }
      FUN_005b3300(piVar1,iVar4,0x1c);
    }
    *(int *)(param_1 + 0x10) = iVar5;
    iVar5 = *piVar1;
    iVar4 = 0;
    if (0 < *(int *)(param_2 + 0x10)) {
      iVar6 = 0;
      do {
        if (iVar5 != 0) {
          FUN_0064ab50(*(int *)(param_2 + 0xc) + iVar6);
        }
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 0x1c;
        iVar5 = iVar5 + 0x1c;
      } while (iVar4 < *(int *)(param_2 + 0x10));
      return param_1;
    }
  }
  else {
    iVar4 = 0;
    if (*(int *)(param_1 + 0x10) < iVar5) {
      if (0 < *(int *)(param_1 + 0x10)) {
        iVar5 = 0;
        do {
          FUN_0064a880(*(int *)(param_2 + 0xc) + iVar5);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x1c;
        } while (iVar4 < *(int *)(param_1 + 0x10));
      }
      if (iVar4 < *(int *)(param_2 + 0x10)) {
        iVar5 = iVar4 * 0x1c;
        iVar6 = *piVar1 + iVar5;
        do {
          if (iVar6 != 0) {
            FUN_0064ab50(*(int *)(param_2 + 0xc) + iVar5);
          }
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x1c;
          iVar6 = iVar6 + 0x1c;
        } while (iVar4 < *(int *)(param_2 + 0x10));
        return param_1;
      }
    }
    else {
      if (0 < iVar5) {
        iVar5 = 0;
        do {
          FUN_0064a880(*(int *)(param_2 + 0xc) + iVar5);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x1c;
        } while (iVar4 < *(int *)(param_2 + 0x10));
      }
      if (iVar4 < *(int *)(param_1 + 0x10)) {
        iVar5 = iVar4 * 0x1c;
        do {
          (*(code *)**(undefined4 **)(*piVar1 + iVar5))(0);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x1c;
        } while (iVar4 < *(int *)(param_1 + 0x10));
      }
    }
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
