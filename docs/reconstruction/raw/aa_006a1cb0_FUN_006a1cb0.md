# Raw capture: FUN_006a1cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a1cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a1cb0` |
| **Canonical name** | `FUN_006a1cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void * __thiscall FUN_006a1cb0(void *param_1,byte param_2)

{
  FUN_006a1bd0();
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
