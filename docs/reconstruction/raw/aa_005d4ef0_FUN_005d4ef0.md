# Raw capture: FUN_005d4ef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4ef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d4ef0` |
| **Canonical name** | `FUN_005d4ef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005d4ef0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  FUN_00513f70(param_2);
  if (*(int *)(param_1 + -0x24) == 1) {
    iVar2 = *(int *)(param_1 + -0xdc);
    if ((*(uint *)(*(int *)(iVar2 + 4) + 0xa0 + param_1) >> 3 & 1) != 0) goto LAB_005d4f67;
    uVar4 = 1;
  }
  else {
    if ((*(int *)(param_1 + -0x24) != 2) ||
       (iVar2 = *(int *)(param_1 + -0xdc),
       (*(uint *)(*(int *)(iVar2 + 4) + 0xa0 + param_1) >> 3 & 1) == 0)) goto LAB_005d4f67;
    uVar4 = 0;
  }
  (**(code **)(*(int *)(*(int *)(iVar2 + 4) + -0xdc + param_1) + 0x1b4))(uVar4);
LAB_005d4f67:
  *(undefined4 *)(param_1 + -0x24) = 0;
  if (*(int *)(param_1 + -0x20) != 0) {
    if (*(int *)(param_1 + -0xd8) != 0) {
      *(int *)(*(int *)(param_1 + -0xd8) + 0x28) = *(int *)(param_1 + -0x20);
    }
    if (*(int *)(param_1 + -0xd4) != 0) {
      for (uVar3 = 0; uVar1 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x4c))(), uVar3 < uVar1;
          uVar3 = uVar3 + 1) {
        iVar2 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x50))();
        (**(code **)(**(int **)(iVar2 + uVar3 * 4) + 8))(4);
      }
    }
    *(undefined4 *)(param_1 + -0x20) = 0;
  }
  return;
}
```
