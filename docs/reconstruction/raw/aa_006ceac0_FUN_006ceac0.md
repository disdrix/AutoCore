# Raw capture: FUN_006ceac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ceac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ceac0` |
| **Canonical name** | `FUN_006ceac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ceac0(int param_1)

{
  if (param_1 != 0) {
    FUN_006ceae0();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}
```
