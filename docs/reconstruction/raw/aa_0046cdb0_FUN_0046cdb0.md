# Raw capture: FUN_0046cdb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046cdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0046cdb0` |
| **Canonical name** | `FUN_0046cdb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0046cdb0(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  puStack_8 = &LAB_009be318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00aa6d9c;
  local_4 = 0;
  pvVar1 = (void *)param_1[1];
  if (pvVar1 != (void *)0x0) {
    FUN_00448ed0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  param_1[1] = 0;
  *param_1 = &PTR_LAB_00a9a9bc;
  ExceptionList = pvVar2;
  return;
}
```
