# Raw capture: FUN_0051ffd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ffd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051ffd0` |
| **Canonical name** | `FUN_0051ffd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0051ffd0(int param_1,int param_2)

{
  return *(undefined4 *)(param_1 + 0x664 + param_2 * 4);
}
```
