# Raw capture: FUN_005fda50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fda50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fda50` |
| **Canonical name** | `FUN_005fda50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005fda50(int param_1)

{
  (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(undefined2 *)(param_1 + 4),10);
  return;
}
```
