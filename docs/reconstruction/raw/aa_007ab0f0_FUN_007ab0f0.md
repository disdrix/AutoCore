# Raw capture: FUN_007ab0f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ab0f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ab0f0` |
| **Canonical name** | `FUN_007ab0f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007ab0f0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  undefined1 **unaff_EDI;
  undefined1 *local_90;
  undefined1 local_8c [124];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009aba77;
  local_c = ExceptionList;
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if ((void *)unaff_ESI[0xa2] != (void *)0x0) {
      ExceptionList = &local_c;
      operator_delete__((void *)unaff_ESI[0xa2]);
    }
    unaff_ESI[0xa2] = 0;
    ExceptionList = local_c;
    return;
  }
  local_90 = local_8c;
  ExceptionList = &local_c;
  uVar2 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00403450(iVar1,uVar2);
  uStack_4 = 0;
  (**(code **)(*unaff_ESI + 0x308))(local_90);
  if (unaff_EDI != &local_90) {
    free(unaff_EDI);
  }
  ExceptionList = pvStack_10;
  return;
}
```
