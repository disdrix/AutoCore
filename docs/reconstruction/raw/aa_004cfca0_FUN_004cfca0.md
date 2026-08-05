# Raw capture: FUN_004cfca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cfca0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cfca0` |
| **Canonical name** | `FUN_004cfca0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cfca0(int param_1)

{
  int *piVar1;
  void *pvVar2;
  CVOGHBBase *pAction;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1f4b;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(param_1 + 0x78);
  ExceptionList = &pvStack_c;
  if (piVar1 != (int *)0x0) {
    if (*(int *)(param_1 + 0xe4ec) == 0) {
      ExceptionList = &pvStack_c;
      (**(code **)*piVar1)(1);
    }
    else {
      ExceptionList = &pvStack_c;
      (**(code **)(*piVar1 + 0x18))(1);
    }
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  if (*(int *)(param_1 + 0xe894) != 0) {
    FUN_0048e9e0();
  }
  pvVar2 = operator_new(0x1d8);
  uStack_4 = 0;
  if (pvVar2 == (void *)0x0) {
    pAction = (CVOGHBBase *)0x0;
  }
  else {
    pAction = (CVOGHBBase *)FUN_00558b20(param_1);
  }
  uStack_4 = 0xffffffff;
  *(CVOGHBBase **)(param_1 + 0x78) = pAction;
  if (*(void **)(param_1 + 0xe4ec) != (void *)0x0) {
    CVOGHBList_Enqueue(*(void **)(param_1 + 0xe4ec),pAction);
    CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + 0x78));
  }
  ExceptionList = pvStack_c;
  return;
}
```
