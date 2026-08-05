# Raw capture: FUN_0042ade0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ade0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042ade0` |
| **Canonical name** | `FUN_0042ade0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_0042ade0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_00a9b1d0;
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 8) = param_1[2];
  }
  if (param_1[2] == 0) {
    DAT_00d17998 = param_1[1];
  }
  else {
    *(undefined4 *)(param_1[2] + 4) = param_1[1];
  }
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
