# Raw capture: FUN_0044edb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044edb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044edb0` |
| **Canonical name** | `FUN_0044edb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0044edb0(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int *local_24;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009be798;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffd0;
  ExceptionList = &local_10;
  FUN_0040aef0(&local_24);
  local_20 = *(undefined2 *)(param_1 + 4);
  local_1e = *(undefined2 *)(param_1 + 6);
  iVar5 = 0;
  local_8 = 0;
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_2 + 0xc) - iVar2 >> 3;
  }
  if (param_4 != 0) {
    if (iVar2 != 0) {
      iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;
    }
    if (0x1fffffffU - iVar5 < param_4) {
      uVar1 = FUN_004540b0();
      iVar2 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;
    }
    if (uVar1 < iVar5 + param_4) {
      if (0x1fffffff - (uVar1 >> 1) < uVar1) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;
      }
      if (uVar1 < iVar5 + param_4) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_2 + 8) - iVar2 >> 3;
        }
        uVar1 = iVar2 + param_4;
      }
      local_18 = uVar1 * 8;
      pvVar3 = operator_new(local_18);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_0044f1f0(param_3,pvVar3,param_3);
      FUN_0044f120(iVar2,param_3);
      FUN_0044f1f0(*(undefined4 *)(param_2 + 8),iVar2 + param_4 * 8,param_3);
      local_8 = 0;
      iVar2 = *(int *)(param_2 + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_2 + 8) - iVar2 >> 3;
      }
      if (iVar2 != 0) {
        FUN_004247c0();
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)(param_2 + 4));
      }
      *(uint *)(param_2 + 0xc) = local_18 + (int)pvVar3;
      *(void **)(param_2 + 8) = (void *)((int)pvVar3 + (param_4 + iVar5) * 8);
      *(void **)(param_2 + 4) = pvVar3;
    }
    else {
      local_1c = *(int *)(param_2 + 8);
      local_18 = param_4 * 8;
      if ((uint)(local_1c - param_3 >> 3) < param_4) {
        FUN_0044f1f0(local_1c,local_18 + param_3,param_3);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0044f120(*(undefined4 *)(param_2 + 8),param_3);
        local_8 = 0;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + local_18;
        FUN_0044f060(*(int *)(param_2 + 8) - local_18);
      }
      else {
        uVar4 = FUN_0044f1f0(local_1c,local_1c,param_3);
        *(undefined4 *)(param_2 + 8) = uVar4;
        FUN_0044f0c0(param_3,param_3);
        FUN_0044f060(local_18 + param_3);
      }
    }
  }
  local_8 = 0xffffffff;
  if ((local_24 != (int *)0x0) && (local_24[1] = local_24[1] + -1, local_24[1] == 0)) {
    (**(code **)(*local_24 + 8))();
  }
  ExceptionList = local_10;
  return;
}
```
