# Raw capture: FUN_004c0db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0db0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c0db0` |
| **Canonical name** | `FUN_004c0db0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004c0db0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc0) == 0) {
    return 0;
  }
  FUN_004148e0(param_1 + 0x8c);
  if (*(int *)(*(int *)(param_1 + 0xb0) + 0x20) != 0) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x30) + 8);
    if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {
      iVar1 = FUN_00972e50();
    }
    FUN_00493550("v3Right",iVar1);
    FUN_00493550(&DAT_009cb684,iVar1 + 0x10);
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x30) + 8);
    if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {
      iVar1 = FUN_00972e50();
    }
    FUN_00493550("v3Right",iVar1);
    FUN_00493550(&DAT_009cb684,iVar1 + 0x10);
  }
  (**(code **)(**(int **)(param_1 + 0xac) + 0x3c))(param_2);
  return 1;
}
```
