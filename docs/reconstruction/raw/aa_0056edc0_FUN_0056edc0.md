# Raw capture: FUN_0056edc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056edc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0056edc0` |
| **Canonical name** | `FUN_0056edc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_0056edc0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009d2fbc;
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(param_1[1]);
  }
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
