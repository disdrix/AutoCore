# Raw capture: CVOGTacArc_dtor_helper

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632900` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00632900` |
| **Canonical name** | `CVOGTacArc_dtor_helper` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall CVOGTacArc_dtor_helper(undefined4 *param_1)

{
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009a8bc1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_CVOGTacArc_vdtor_009e3538;
  local_4 = 2;
  if ((void *)param_1[0xb] != (void *)0x0) {
    operator_delete__((void *)param_1[0xb]);
  }
  param_1[0xb] = 0;
  if ((undefined4 *)param_1[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[6])(1);
  }
  param_1[6] = 0;
  local_4._0_1_ = 1;
  FUN_0096f510();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0096efd0();
  local_4 = 0xffffffff;
  FUN_0096efd0();
  ExceptionList = pvStack_c;
  return;
}
```
