# Raw capture: FUN_0044dba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044dba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044dba0` |
| **Canonical name** | `FUN_0044dba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044dba0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_0044dba0(*(undefined4 *)((int)param_1 + 8));
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return;
}
```
