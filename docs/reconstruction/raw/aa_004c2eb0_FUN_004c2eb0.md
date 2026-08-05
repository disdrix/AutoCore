# Raw capture: FUN_004c2eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c2eb0` |
| **Canonical name** | `FUN_004c2eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c2eb0(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(((float)param_1 - DAT_00aaa6c4) * _DAT_009cb8dc);
  return uVar1 & ((int)uVar1 < 0) - 1;
}
```
