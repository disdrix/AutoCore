# Raw capture: FUN_004eae80

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eae80` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eae80` |
| **Canonical name** | `FUN_004eae80` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004eae80(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x14)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0xc),*(int *)(param_1 + 0x14) * 8,0x12);
  }
  return;
}
```
