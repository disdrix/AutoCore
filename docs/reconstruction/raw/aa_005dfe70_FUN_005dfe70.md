# Raw capture: FUN_005dfe70

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dfe70` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dfe70` |
| **Canonical name** | `FUN_005dfe70` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005dfe70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009dbbfc;
  if ((void *)param_1[0x65] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x65]);
  }
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  FUN_00518ec0();
  return;
}
```
