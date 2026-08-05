# Raw capture: FUN_005b2df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2df0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b2df0` |
| **Canonical name** | `FUN_005b2df0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005b2df0(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009a67a0;
  local_10 = ExceptionList;
  local_20 = *param_4;
  local_1c = param_4[1];
  iVar3 = *(int *)(param_1 + 4);
  local_18 = param_4[2];
  local_14 = &stack0xffffffd4;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(param_1 + 0xc) - iVar3) / 0xc;
  }
  if (param_3 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = &stack0xffffffd4;
    if (0x15555555U - iVar2 < param_3) {
      ExceptionList = &local_10;
      FUN_005b2a00();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(param_1 + 8) - iVar3) / 0xc;
    }
    if (uVar6 < iVar2 + param_3) {
      if (0x15555555 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0xc;
      }
      if (uVar6 < iVar3 + param_3) {
        iVar3 = FUN_00480c80();
        uVar6 = iVar3 + param_3;
      }
      pvVar4 = operator_new(uVar6 * 0xc);
      local_8 = 0;
      iVar3 = FUN_0057fb80(*(undefined4 *)(param_1 + 4),param_2,pvVar4,param_1,param_2);
      FUN_00538710(iVar3,param_3,&local_20,param_1,param_2);
      FUN_0057fb80(param_2,*(undefined4 *)(param_1 + 8),iVar3 + param_3 * 0xc,param_1,param_2);
      iVar3 = 0;
      if (*(int *)(param_1 + 4) != 0) {
        iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
      }
      if (*(void **)(param_1 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)(param_1 + 4));
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);
      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0xc);
      *(void **)(param_1 + 4) = pvVar4;
      ExceptionList = local_10;
      return;
    }
    iVar3 = *(int *)(param_1 + 8);
    if ((uint)((iVar3 - param_2) / 0xc) < param_3) {
      iVar2 = param_3 * 0xc;
      FUN_0057fb80(param_2,iVar3,iVar2 + param_2,param_1,iVar2);
      local_8 = 2;
      FUN_00539e90(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0xc,&local_20
                  );
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar2;
      FUN_00537860(param_2,*(int *)(param_1 + 8) + param_3 * -0xc,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_3 * -0xc;
    uVar5 = FUN_0057fb80(iVar2,iVar3,iVar3,param_1,iVar2);
    *(undefined4 *)(param_1 + 8) = uVar5;
    FUN_00456080(param_2,iVar2,iVar3,iVar2);
    FUN_00537860(param_2,param_3 * 0xc + param_2,&local_20);
  }
  ExceptionList = local_10;
  return;
}
```
