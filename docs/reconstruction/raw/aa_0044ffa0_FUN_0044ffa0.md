# Raw capture: FUN_0044ffa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044ffa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044ffa0` |
| **Canonical name** | `FUN_0044ffa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0044ffa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_0044fdd0();
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  if (*(int *)(param_2 + 0x10) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 2;
  }
  FUN_0044fe70(0);
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      iVar2 = *(int *)(param_1 + 0x10);
      iVar1 = uVar4 * 4;
      uVar3 = (**(code **)(**(int **)(*(int *)(param_2 + 0x10) + iVar1) + 0xc))();
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar2 + iVar1) = uVar3;
    } while (uVar4 < uVar5);
  }
  return param_1;
}
```
