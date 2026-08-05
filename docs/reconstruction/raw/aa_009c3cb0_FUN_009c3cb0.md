# Raw capture: FUN_009c3cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009c3cb0` |
| **Canonical name** | `FUN_009c3cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_009c3cb0(void)

{
  if (DAT_00b04e34 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(DAT_00b04e34);
  }
  DAT_00b04e34 = (void *)0x0;
  DAT_00b04e38 = 0;
  DAT_00b04e3c = 0;
  return;
}
```
