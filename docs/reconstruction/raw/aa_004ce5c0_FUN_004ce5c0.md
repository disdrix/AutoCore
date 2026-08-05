# Raw capture: FUN_004ce5c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ce5c0` |
| **Canonical name** | `FUN_004ce5c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __thiscall FUN_004ce5c0(int param_1,int param_2)

{
  if (param_2 == 0) {
    return false;
  }
  if (*(char *)(param_1 + 0xf5) != '\0') {
    return true;
  }
  return *(char *)(param_1 + 0x7e) != '\0';
}
```
