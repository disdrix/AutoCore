# Raw capture: FUN_004bc4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc4b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bc4b0` |
| **Canonical name** | `FUN_004bc4b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004bc4b0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009cb358;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  param_1[2] = 0;
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
