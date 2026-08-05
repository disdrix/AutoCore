# Raw capture: FUN_008dbf50

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dbf50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008dbf50` |
| **Canonical name** | `FUN_008dbf50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008dbf50(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (*(int *)(param_1 + 0x57c) == 0) {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (0x31 < param_2) {
    return;
  }
  if (param_2 == 0x30) {
    if (DAT_00d1b6d8 == 0) goto LAB_008dc00d;
    pcVar2 = "Human Advantages" +
             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                              DAT_00d1b6d8) + 0x3c) + 0x532) * 0x1e;
  }
  else if (param_2 == 0x31) {
    if (DAT_00d1b6d8 == 0) goto LAB_008dc00d;
    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) + 0x3c
                    );
    pcVar2 = "Defense Grid" +
             ((uint)*(byte *)(iVar1 + 0x531) + (uint)*(byte *)(iVar1 + 0x532) * 4) * 0x1e;
  }
  else {
    pcVar2 = "Controls" + param_2 * 0x1e;
  }
  (**(code **)(**(int **)(param_1 + 0x57c) + 0x1d8))(pcVar2,1,1);
LAB_008dc00d:
  (**(code **)(**(int **)(param_1 + 0x57c) + 0x34c))();
  return;
}
```
