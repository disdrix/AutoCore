# Raw capture: FUN_005ffff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffff0` |
| **Canonical name** | `FUN_005ffff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005ffff0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x80);
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x7c) + iVar3 * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(param_1);
    }
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x88) + iVar3 * 4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 8) + 8))(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x8c));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x98)) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x94) + iVar3 * 4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 8) + 8))(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x98));
  }
  return;
}
```
