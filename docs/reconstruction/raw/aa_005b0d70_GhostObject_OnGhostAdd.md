# Raw capture: GhostObject_OnGhostAdd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0d70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0d70` |
| **Canonical name** | `GhostObject_OnGhostAdd` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall GhostObject_OnGhostAdd(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    (**(code **)(**(int **)(param_1 + 0x50) + 0x2b8))(param_1);
    return 1;
  }
  FUN_005a0b30(param_1,param_1 + 0x40);
  return 1;
}
```
