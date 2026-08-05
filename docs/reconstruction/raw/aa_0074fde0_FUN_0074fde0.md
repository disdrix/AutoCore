# Raw capture: FUN_0074fde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074fde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074fde0` |
| **Canonical name** | `FUN_0074fde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0074fde0(undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ada5f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00a9fa78;
  param_1[1] = &PTR_LAB_00a9fa68;
  local_4 = 3;
  if (DAT_00d1f61c != 0) {
    FUN_0073d9b0(param_1);
  }
  FUN_0074f4d0();
  local_4 = CONCAT31(local_4._1_3_,2);
  _eh_vector_destructor_iterator_(param_1 + 0xf,0x10,0x19,FUN_00691630);
  FUN_00445a90();
  param_1[1] = &PTR_LAB_009d45f0;
  *param_1 = &PTR_LAB_00a9a9bc;
  ExceptionList = local_c;
  return;
}
```
