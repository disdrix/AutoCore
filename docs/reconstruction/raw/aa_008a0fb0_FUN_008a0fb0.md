# Raw capture: FUN_008a0fb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0fb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008a0fb0` |
| **Canonical name** | `FUN_008a0fb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008a0fb0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x50c) + param_2 < 0) {
    FUN_008a0ed0();
    return;
  }
  FUN_008a0ed0();
  return;
}
```
