# Raw capture: FUN_0096bab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096bab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0096bab0` |
| **Canonical name** | `FUN_0096bab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0096bab0(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  
  if (((((byte)*(undefined4 *)(param_1 + 0x2c) & 0xf) == 1) && (*(int *)(param_1 + 0x30) == 1)) &&
     (1 < *(uint *)(param_1 + 0x48))) {
    iVar3 = 0;
    if (unaff_EBX != 0) {
      iVar1 = *(int *)(param_1 + 0x1c);
      for (iVar2 = *(int *)(param_1 + 0x20);
          ((unaff_EBX < iVar1 || (unaff_EBX < iVar2)) && ((1 < iVar1 && (1 < iVar2))));
          iVar2 = iVar2 / 2) {
        iVar1 = iVar1 / 2;
        iVar3 = iVar3 + 1;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))(*(int **)(param_1 + 0x10),iVar3);
  }
  return;
}
```
