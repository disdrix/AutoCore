# Raw capture: FUN_005c9cc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c9cc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c9cc0` |
| **Canonical name** | `FUN_005c9cc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005c9cc0(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a6f80;
  local_10 = ExceptionList;
  iVar6 = *(int *)(param_1 + 4);
  param_4 = (undefined4 *)*param_4;
  if (iVar6 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) - iVar6 >> 2;
  }
  uVar8 = CONCAT44(iVar6,iVar2);
  if (param_3 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;
    }
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar6 < param_3) {
      ExceptionList = &local_10;
      uVar8 = FUN_005c85b0();
    }
    iVar6 = (int)((ulonglong)uVar8 >> 0x20);
    uVar3 = (uint)uVar8;
    if (iVar6 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;
    }
    if (uVar3 < iVar2 + param_3) {
      if (0x3fffffff - (uVar3 >> 1) < uVar3) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 + (uVar3 >> 1);
      }
      if (iVar6 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;
      }
      if (uVar3 < iVar2 + param_3) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;
        }
        uVar3 = iVar6 + param_3;
      }
      pvVar4 = operator_new(uVar3 * 4);
      local_8 = 0;
      iVar6 = FUN_004935b0(*(undefined4 *)(param_1 + 4),param_2,pvVar4,param_1,param_2);
      FUN_005c96c0(iVar6,param_3,&param_4,param_1,param_2);
      FUN_004935b0(param_2,*(undefined4 *)(param_1 + 8),iVar6 + param_3 * 4,param_1,param_2);
      pvVar1 = *(void **)(param_1 + 4);
      if (pvVar1 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;
      }
      if (pvVar1 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(pvVar1);
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar4);
      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar6) * 4);
      *(void **)(param_1 + 4) = pvVar4;
      ExceptionList = local_10;
      return;
    }
    iVar2 = *(int *)(param_1 + 8);
    iVar6 = param_3 * 4;
    if ((uint)(iVar2 - param_2 >> 2) < param_3) {
      FUN_004935b0(param_2,iVar2,iVar6 + param_2,param_1,iVar6);
      local_8 = 2;
      FUN_004a7640(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 2),&param_4);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar6;
      FUN_005739b0(param_2,*(int *)(param_1 + 8) + param_3 * -4,&param_4);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar2 + param_3 * -4;
    uVar5 = FUN_004935b0(iVar7,iVar2,iVar2,param_1,iVar6);
    *(undefined4 *)(param_1 + 8) = uVar5;
    FUN_004a69c0(param_2,iVar7,iVar2);
    FUN_005739b0(param_2,iVar6 + param_2,&param_4);
  }
  ExceptionList = local_10;
  return;
}
```
