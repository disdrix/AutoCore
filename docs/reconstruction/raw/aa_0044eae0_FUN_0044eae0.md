# Raw capture: FUN_0044eae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044eae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044eae0` |
| **Canonical name** | `FUN_0044eae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044eae0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009bd3c8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_009838a0(param_1 + 2);
  *param_1 = &PTR_FUN_00a9f568;
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_LAB_00a2c238;
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar1);
  }
  ExceptionList = unaff_ESI;
  return;
}
```
