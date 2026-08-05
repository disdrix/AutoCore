# Raw capture: FUN_008b6be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b6be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008b6be0` |
| **Canonical name** | `FUN_008b6be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
