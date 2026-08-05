# Raw capture: FUN_0066edb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0066edb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0066edb0` |
| **Canonical name** | `FUN_0066edb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_0066edb0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009e7ba8;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  param_1[1] = 0;
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
```
