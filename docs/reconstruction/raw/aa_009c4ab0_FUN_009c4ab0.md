# Raw capture: FUN_009c4ab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c4ab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c4ab0` |
| **Canonical name** | `FUN_009c4ab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009c4ab0(void)

{
  _DAT_00d03490 = &PTR_FUN_009d81e8;
  if ((DAT_00d03495 & 0x80) != 0) {
    DAT_00d03495 = DAT_00d03495 & 0x7f;
    FUN_005ffdb0(0);
  }
  _DAT_00d03490 = &PTR_LAB_009cc290;
  return;
}
```
