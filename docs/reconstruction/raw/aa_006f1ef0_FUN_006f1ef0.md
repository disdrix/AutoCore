# Raw capture: FUN_006f1ef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006f1ef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006f1ef0` |
| **Canonical name** | `FUN_006f1ef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006f1ef0(uint param_1)

{
  if (param_1 < 0x100) {
    FUN_006f3a00(9,param_1);
    return;
  }
  if (param_1 < 0x10000) {
    FUN_006f3a60(10,param_1);
    return;
  }
  FUN_006f3c40(0xb,param_1);
  return;
}
```
