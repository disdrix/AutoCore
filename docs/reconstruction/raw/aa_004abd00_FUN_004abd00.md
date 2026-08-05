# Raw capture: FUN_004abd00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004abd00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004abd00` |
| **Canonical name** | `FUN_004abd00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004abd00(int param_1)

{
  void *pvVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a12f5;
  pvStack_c = ExceptionList;
  pvVar1 = *(void **)(param_1 + 0x394);
  if (pvVar1 != (void *)0x0) {
    ExceptionList = &pvStack_c;
    FUN_0096f510();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  ExceptionList = &pvStack_c;
  *(undefined4 *)(param_1 + 0x394) = 0;
  if (*(undefined4 **)(param_1 + 0x390) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x390))(1);
  }
  *(undefined4 *)(param_1 + 0x390) = 0;
  if (DAT_00b03e64 != '\0') {
    FUN_004aac50();
  }
  pvVar1 = operator_new(0x14c);
  uStack_4 = 0;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00764030();
  }
  *(int *)(param_1 + 0x390) = iVar2;
  *(undefined1 *)(iVar2 + 0x139) = 1;
  ExceptionList = pvStack_c;
  return;
}
```
