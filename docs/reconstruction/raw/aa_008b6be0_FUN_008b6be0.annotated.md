# Annotated low-level: FUN_008b6be0

| Field | Value |
|---|---|
| Stable ID | `aa_008b6be0` |
| VA | `0x008b6be0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008b6be0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008b6be0(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = DAT_00d1ad2c;
  iVar6 = 0;
  if (0 < *(int *)(in_EAX + 0x520)) {
    do {
      iVar1 = *(int *)(iVar3 + 8);
      if (iVar1 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(iVar3 + 0xc) - iVar1 >> 2;
      }
      uVar5 = *(int *)(in_EAX + 0x52c) + iVar6;
      if (uVar5 < uVar4) {
        if (((param_1 & param_2) == 0xffffffff) ||
           ((iVar2 = *(int *)(iVar1 + uVar5 * 4), *(uint *)(iVar2 + 0x1f0) == param_1 &&
            (*(uint *)(iVar2 + 500) == param_2)))) {
          FUN_008b6590(iVar6,*(undefined4 *)(iVar1 + uVar5 * 4));
        }
      }
      else {
        if (*(int *)(*(int *)(in_EAX + 0x53c) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x53c) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x540) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x540) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x544) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x544) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x54c) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x54c) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x550) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x550) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x554) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x554) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x55c) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x55c) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x548) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x548) + iVar6 * 4) + 4))(0);
        }
        if (*(int *)(*(int *)(in_EAX + 0x558) + iVar6 * 4) != 0) {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x558) + iVar6 * 4) + 4))(0);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(in_EAX + 0x520));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
