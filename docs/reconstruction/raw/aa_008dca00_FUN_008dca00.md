# Raw capture: FUN_008dca00

| Field | Value |
|---|---|
| **Stable ID** | `aa_008dca00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008dca00` |
| **Canonical name** | `FUN_008dca00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008dca00(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 local_14 [4];
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b39cf;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_007ab7f0();
  puVar5 = local_14;
  piVar2 = (int *)(**(code **)(*param_1 + 0x120))(puVar5,1,0);
  iVar1 = piVar2[1];
  param_1[0x147] = *piVar2;
  param_1[0x148] = iVar1;
  pvVar3 = operator_new(0x488);
  uStack_10 = 0;
  if (pvVar3 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_007b5dd0(pvVar3,0);
  }
  uStack_10 = 0xffffffff;
  (**(code **)(*piVar2 + 0x28))("i_d_first_2d_wnd_minimize_location.xml");
  piVar4 = (int *)(**(code **)(*piVar2 + 0x120))(&stack0xffffffdc,1,0);
  iVar1 = piVar4[1];
  param_1[0x149] = *piVar4;
  param_1[0x14a] = iVar1;
  (**(code **)*piVar2)(1);
  if ((char)param_1[0x146] != '\0') {
    (**(code **)(*param_1 + 0x110))(param_1 + 0x149);
    ExceptionList = puVar5;
    return;
  }
  (**(code **)(*param_1 + 0x110))(param_1 + 0x147);
  ExceptionList = puVar5;
  return;
}
```
