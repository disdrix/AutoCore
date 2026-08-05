# Raw capture: FUN_005ffdb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffdb0` |
| **Canonical name** | `FUN_005ffdb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ffdb0(int param_1,int param_2)

{
  FUN_005ffcf0(param_1,param_2);
  if (param_2 != 0) {
    *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | 0x80;
    return;
  }
  *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0x7f;
  return;
}
```
