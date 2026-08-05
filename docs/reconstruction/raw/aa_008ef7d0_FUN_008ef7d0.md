# Raw capture: FUN_008ef7d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ef7d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ef7d0` |
| **Canonical name** | `FUN_008ef7d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008ef7d0(int *param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int *piVar4;
  undefined1 auStack_1c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b7522;
  local_c = ExceptionList;
  piVar4 = (int *)0x0;
  if (param_1 == (int *)0x0) {
    return;
  }
  if ((float)param_1[0x2b] == 0.0) {
    return;
  }
  if ((float)param_1[0x2c] == 0.0) {
    return;
  }
  ExceptionList = &local_c;
  iVar1 = _wcsnicmp((wchar_t *)(param_1 + 7),L"sec_",4);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return;
  }
  pvVar2 = operator_new(0x4cc);
  local_4 = 0;
  if (pvVar2 != (void *)0x0) {
    piVar4 = (int *)FUN_0079c860();
  }
  local_4 = 0xffffffff;
  (**(code **)(*param_2 + 0xa8))();
  uVar3 = param_1[3];
  if ((param_1[6] != 0) && (DAT_00d1b6d8 != 0)) {
    uVar3 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +
                                             DAT_00d1b6d8) + 0x3c) + 0x532);
  }
  param_2._0_1_ = (char)pvVar2;
  if ((char)param_2 == '\0') {
    (**(code **)(*piVar4 + 0x28))();
    goto LAB_008ef906;
  }
  if ((char)param_2 != '\x01') {
    if (uVar3 == 2) {
      (**(code **)(*piVar4 + 0x28))();
      goto LAB_008ef906;
    }
    if ((uVar3 != 1) && (uVar3 == 0)) {
      (**(code **)(*piVar4 + 0x28))();
      goto LAB_008ef906;
    }
  }
  (**(code **)(*piVar4 + 0x28))();
LAB_008ef906:
  piVar4[0x8d] = param_1[0x2b];
  piVar4[0x8f] = param_1[0x2c];
  FUN_008ec080(auStack_1c,param_1[0x2b],param_1[0x2c]);
  (**(code **)(*piVar4 + 0x140))(auStack_1c,1);
  (**(code **)(*piVar4 + 0x140))(&stack0xffffffdc,1);
  (**(code **)(*piVar4 + 0x118))(&stack0xffffffcc);
  (**(code **)(*piVar4 + 0x74))(*param_1 + 0x9c45);
  (**(code **)(*piVar4 + 0x308))(0);
  FUN_007a70f0();
  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);
  FUN_0040e230();
  ExceptionList = local_c;
  return;
}
```
