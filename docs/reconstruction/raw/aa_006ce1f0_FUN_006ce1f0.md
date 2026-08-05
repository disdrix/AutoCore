# Raw capture: FUN_006ce1f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ce1f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ce1f0` |
| **Canonical name** | `FUN_006ce1f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ce1f0(int param_1)

{
  if (param_1 != 0) {
    FUN_0066dcf0();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}
```
