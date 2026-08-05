# Raw capture: FUN_005dab30

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dab30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dab30` |
| **Canonical name** | `FUN_005dab30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005dab30(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_005da0a0(*(undefined4 *)(param_1 + 0x14),param_1 + 0x1c,*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 0xc));
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return;
}
```
