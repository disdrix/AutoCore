# Raw capture: FUN_005d3aa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d3aa0` |
| **Canonical name** | `FUN_005d3aa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __thiscall FUN_005d3aa0(void *param_1,byte param_2)

{
  FUN_005d3a80();
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
