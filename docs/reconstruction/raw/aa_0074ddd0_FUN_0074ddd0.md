# Raw capture: FUN_0074ddd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ddd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074ddd0` |
| **Canonical name** | `FUN_0074ddd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0074ddd0(int *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined1 local_1c [4];
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b0917;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = (int)&PTR_FUN_00aa05cc;
  local_18 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  local_10 = 0;
  local_4 = 2;
  FUN_0074d530(local_1c);
  iVar1 = param_1[6];
  while (puVar3 = local_18, iVar1 != 0) {
    (**(code **)(*param_1 + 0x10))(*(undefined4 *)(*(int *)param_1[5] + 8));
    iVar1 = param_1[6];
  }
  for (; puVar3 != local_14; puVar3 = puVar3 + 1) {
    pvVar2 = (void *)*puVar3;
    if (pvVar2 != (void *)0x0) {
      FUN_0074ecf0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar2);
    }
  }
  for (puVar3 = *(undefined4 **)param_1[0xf]; puVar3 != (undefined4 *)param_1[0xf];
      puVar3 = (undefined4 *)*puVar3) {
    pvVar2 = (void *)puVar3[3];
    if (pvVar2 != (void *)0x0) {
      local_4._1_3_ = (undefined3)((uint)local_4 >> 8);
      local_4._0_1_ = 3;
      FUN_00734830(pvVar2);
      local_4 = CONCAT31(local_4._1_3_,2);
      if (*(void **)((int)pvVar2 + 0x2c) == (void *)0x0) {
        *(undefined4 *)((int)pvVar2 + 0x2c) = 0;
        *(undefined4 *)((int)pvVar2 + 0x30) = 0;
        *(undefined4 *)((int)pvVar2 + 0x34) = 0;
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar2);
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)((int)pvVar2 + 0x2c));
    }
  }
  if (local_18 != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(local_18);
  }
  if ((void *)param_1[0x12] != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0x12]);
  }
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  puVar3 = (undefined4 *)param_1[0xf];
  pvVar2 = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(param_1[0xf] + 4) = param_1[0xf];
  param_1[0x10] = 0;
  if (pvVar2 == (void *)param_1[0xf]) {
                    /* WARNING: Subroutine does not return */
    operator_delete((void *)param_1[0xf]);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvVar2);
}
```
