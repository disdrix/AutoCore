# Raw capture: FUN_006c9ab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c9ab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c9ab0` |
| **Canonical name** | `FUN_006c9ab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006c9ab0(int param_1)

{
  if (param_1 != 0) {
    FUN_006ce600();
    *(undefined4 *)(param_1 + 0x10) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x14) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x18) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}
```
