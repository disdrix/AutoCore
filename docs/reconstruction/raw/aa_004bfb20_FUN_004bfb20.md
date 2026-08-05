# Raw capture: FUN_004bfb20

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfb20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfb20` |
| **Canonical name** | `FUN_004bfb20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004bfb20(int param_1,int param_2)

{
  if (param_2 == 9) {
    return *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x54) +
           *(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x30) +
           *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0xc);
  }
  return *(int *)(param_1 + (param_2 * 3 + 3) * 4);
}
```
