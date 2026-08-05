# Raw capture: FUN_0043bfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043bfb0` |
| **Canonical name** | `FUN_0043bfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0043bfb0(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint extraout_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009bcbb0;
  local_10 = ExceptionList;
  param_4 = (undefined4 *)*param_4;
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(int *)(param_1 + 0xc) - iVar1 >> 2;
  }
  if (param_3 != 0) {
    if (iVar1 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;
    }
    uVar4 = param_3;
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar5 < param_3) {
      ExceptionList = &local_10;
      iVar1 = FUN_004540b0();
      uVar4 = extraout_ECX;
    }
    if (iVar1 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;
    }
    if (uVar6 < iVar5 + uVar4) {
      if (0x3fffffff - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;
      }
      if (uVar6 < iVar5 + uVar4) {
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(param_1 + 8) - iVar1 >> 2;
        }
        uVar6 = iVar1 + uVar4;
      }
      pvVar2 = operator_new(uVar6 * 4);
      local_8 = 0;
      FUN_0044ea70(param_3);
      FUN_00436ef0(param_3);
      FUN_0044ea70(param_3);
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 2;
      }
      if (iVar1 == 0) {
        *(void **)(param_1 + 0xc) = (void *)((int)pvVar2 + uVar6 * 4);
        *(void **)(param_1 + 8) = (void *)((int)pvVar2 + (param_3 + iVar5) * 4);
        *(void **)(param_1 + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      for (; iVar1 != *(int *)(param_1 + 8); iVar1 = iVar1 + 4) {
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 4));
    }
    if ((uint)(*(int *)(param_1 + 8) - (int)param_2 >> 2) < uVar4) {
      FUN_0044ea70(param_3);
      local_8 = 2;
      FUN_00436ef0(param_3);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar4 * 4;
      puVar7 = (undefined4 *)(*(int *)(param_1 + 8) + uVar4 * -4);
      if (param_2 != puVar7) {
        do {
          if ((undefined4 **)param_2 != &param_4) {
            *param_2 = param_4;
          }
          param_2 = param_2 + 1;
        } while (param_2 != puVar7);
        ExceptionList = local_10;
        return;
      }
    }
    else {
      uVar3 = FUN_0044ea70(*(int *)(param_1 + 8) + uVar4 * -4);
      *(undefined4 *)(param_1 + 8) = uVar3;
      FUN_0043c710();
      puVar7 = param_2 + uVar4;
      for (; param_2 != puVar7; param_2 = param_2 + 1) {
        if ((undefined4 **)param_2 != &param_4) {
          *param_2 = param_4;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}
```
