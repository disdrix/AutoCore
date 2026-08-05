# Raw capture: FUN_0066ebe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0066ebe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0066ebe0` |
| **Canonical name** | `FUN_0066ebe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0066ebe0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0066f420();
    return;
  }
  return;
}
```
