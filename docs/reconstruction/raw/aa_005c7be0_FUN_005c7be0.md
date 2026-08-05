# Raw capture: FUN_005c7be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c7be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c7be0` |
| **Canonical name** | `FUN_005c7be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005c7be0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a6e71;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_009d9fe8;
  FUN_0076cf00("~CLoadNode");
  pvVar1 = (void *)param_1[0x16];
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005b2ba0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  iVar2 = param_1[4];
  param_1[0x16] = 0;
  if (iVar2 == 0) {
    iVar2 = FUN_004baf50(param_1 + 6);
    if (iVar2 == 0) goto LAB_005c7c55;
  }
  *(undefined1 *)(iVar2 + 0xf) = 0;
LAB_005c7c55:
  if ((code *)param_1[0x1c] != (code *)0x0) {
    (*(code *)param_1[0x1c])(*(undefined1 *)((int)param_1 + 0x53));
  }
  if ((code *)param_1[0x1e] != (code *)0x0) {
    (*(code *)param_1[0x1e])(*(undefined1 *)((int)param_1 + 0x53),param_1[0x1d]);
  }
  if ((undefined4 *)param_1[0x1b] != (undefined4 *)0x0) {
    pvVar1 = *(void **)param_1[0x1b];
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)param_1[0x1b] = 0;
    if ((void *)param_1[0x1b] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete((void *)param_1[0x1b]);
    }
    param_1[0x1b] = 0;
  }
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return;
}
```
