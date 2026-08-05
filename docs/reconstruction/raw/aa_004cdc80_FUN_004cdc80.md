# Raw capture: FUN_004cdc80

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdc80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cdc80` |
| **Canonical name** | `FUN_004cdc80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cdc80(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004bb1c0(0,*(undefined4 *)(param_1 + 0xe7d8),*(undefined4 *)(param_1 + 0xe7dc));
  if (iVar1 != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x114))(param_2);
  }
  return;
}
```
