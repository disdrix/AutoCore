# Raw capture: FUN_0090fbd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090fbd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090fbd0` |
| **Canonical name** | `FUN_0090fbd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0090fbd0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(DAT_00d17944 + 0x170);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x2a8);
    *(undefined1 *)(iVar2 + 0x48) = 1;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x40);
    FUN_0076c4d0();
    (**(code **)(**(int **)(iVar2 + 8) + 4))(iVar1);
    FUN_00755f10(iVar1);
  }
  iVar1 = *(int *)(DAT_00d17944 + 0x184);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x2a8);
    *(undefined1 *)(iVar2 + 0x48) = 1;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x40);
    FUN_0076c4d0();
    (**(code **)(**(int **)(iVar2 + 8) + 4))(iVar1);
    FUN_00755f10(iVar1);
  }
  return;
}
```
