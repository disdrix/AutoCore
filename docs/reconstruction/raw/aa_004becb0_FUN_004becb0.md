# Raw capture: FUN_004becb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004becb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004becb0` |
| **Canonical name** | `FUN_004becb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int * __thiscall FUN_004becb0(int *param_1,int param_2,char param_3)

{
  int iVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_009a18ea;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[4] = (int)&PTR_LAB_009cb5cc;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = (int)&PTR_LAB_009cb5cc;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  local_4 = 1;
  uStack_3 = 0;
  FUN_00764030();
  local_4 = 2;
  FUN_00764030();
  local_4 = 3;
  FUN_00764030();
  local_4 = 4;
  FUN_0074ba00();
  local_4 = 5;
  FUN_0074ba00();
  local_4 = 6;
  FUN_0074ba00();
  local_4 = 7;
  FUN_00972cc0();
  param_1[0x15f] = 0;
  param_1[0x160] = 0;
  param_1[0x161] = 0;
  param_1[0x163] = 0;
  param_1[0x164] = 0;
  param_1[0x165] = 0;
  local_4 = 9;
  if (param_3 == '\0') {
    param_1[3] = param_2;
    *(undefined1 *)(param_1 + 0x15c) = 0;
    *(undefined1 *)(param_1 + 0x15d) = 0;
    *(undefined1 *)((int)param_1 + 0x571) = 1;
    *(undefined1 *)(param_1 + 0x169) = 0;
    FUN_00410420(0,0);
    FUN_00410420(0,0);
    *(undefined1 *)((int)param_1 + 0x5c5) = 0;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[0x172] = 0;
    param_1[0x173] = 0;
    if (*(int *)(param_2 + 0x14) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 2;
    }
    *(bool *)((int)param_1 + 0x572) = iVar1 != 0;
    *(undefined1 *)((int)param_1 + 0x573) = 1;
    param_1[2] = DAT_00b03738;
    *(undefined1 *)(param_1 + 0x171) = 0;
    *(undefined1 *)(param_1 + 0x174) = 0;
    param_1[0x16d] = 0;
    param_1[0x16e] = 0;
    param_1[0x16f] = 0;
    if (DAT_00b0373c == 0) {
      pvVar2 = operator_new(0x5e0);
      _local_4 = CONCAT31(uStack_3,10);
      if (pvVar2 == (void *)0x0) {
        DAT_00b03730 = (int *)0x0;
      }
      else {
        DAT_00b03730 = (int *)FUN_004becb0(0,1);
      }
      *DAT_00b03730 = (int)DAT_00b03730;
      DAT_00b03730[1] = (int)DAT_00b03730;
    }
    DAT_00b0373c = DAT_00b0373c + 1;
    DAT_00b03734 = DAT_00b03734 + 1;
    *param_1 = *DAT_00b03730;
    param_1[1] = (int)DAT_00b03730;
    *(int **)(*DAT_00b03730 + 4) = param_1;
    *DAT_00b03730 = (int)param_1;
  }
  ExceptionList = local_c;
  return param_1;
}
```
