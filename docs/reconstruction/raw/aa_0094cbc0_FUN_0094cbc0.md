# Raw capture: FUN_0094cbc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094cbc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094cbc0` |
| **Canonical name** | `FUN_0094cbc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0094cbc0(char param_1)

{
  if (param_1 != '\0') {
    _param_1 = 0x8012;
    FUN_008073b0(4,&param_1);
    return;
  }
  _param_1 = 0x8014;
  FUN_008073b0(4,&param_1);
  return;
}
```
