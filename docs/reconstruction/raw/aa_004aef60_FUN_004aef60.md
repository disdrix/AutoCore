# Raw capture: FUN_004aef60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aef60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aef60` |
| **Canonical name** | `FUN_004aef60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004aef60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004aef60(*(undefined4 *)((int)param_1 + 8));
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return;
}
```
