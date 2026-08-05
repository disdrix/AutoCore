# Raw capture: FUN_009c4cf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c4cf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c4cf0` |
| **Canonical name** | `FUN_009c4cf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009c4cf0(void)

{
  _DAT_00d03644 = &PTR_FUN_009d81e8;
  if ((DAT_00d03649 & 0x80) != 0) {
    DAT_00d03649 = DAT_00d03649 & 0x7f;
    FUN_005ffdb0(0);
  }
  _DAT_00d03644 = &PTR_LAB_009cc290;
  return;
}
```
