# Raw capture: FUN_009c3ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c3ad0` |
| **Canonical name** | `FUN_009c3ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009c3ad0(void)

{
  if (DAT_00b046d8 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(DAT_00b046d8);
  }
  DAT_00b046d8 = (void *)0x0;
  DAT_00b046dc = 0;
  _DAT_00b046e0 = 0;
  return;
}
```
