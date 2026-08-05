# Raw capture: FUN_0069ead0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0069ead0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0069ead0` |
| **Canonical name** | `FUN_0069ead0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0069ead0(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_70 [20];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_5c [64];
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009aaf18;
  local_10 = ExceptionList;
  local_14 = &stack0xffffff84;
  ExceptionList = &local_10;
  local_18 = param_1;
  FUN_00697390(param_4);
  iVar2 = *(int *)(param_1 + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(param_1 + 0xc) - iVar2) / 0x54;
  }
  if (param_3 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;
    }
    if (0x30c30c3U - iVar1 < param_3) {
      FUN_00697280();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(param_1 + 8) - iVar2) / 0x54;
    }
    if (uVar5 < iVar1 + param_3) {
      if (0x30c30c3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(param_1 + 8) - iVar2) / 0x54;
      }
      if (uVar5 < iVar2 + param_3) {
        iVar2 = FUN_00686050();
        uVar5 = iVar2 + param_3;
      }
      pvVar3 = operator_new(uVar5 * 0x54);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00697d80(*(undefined4 *)(param_1 + 4),param_2,pvVar3,param_1,param_2);
      FUN_0069e9b0(iVar2,param_3,local_70,param_1,param_2);
      FUN_00697d80(param_2,*(undefined4 *)(param_1 + 8),iVar2 + param_3 * 0x54,param_1,param_2);
      local_8 = 0;
      iVar2 = 0;
      if (*(int *)(param_1 + 4) != 0) {
        iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x54;
      }
      if (*(int *)(param_1 + 4) != 0) {
        FUN_00698950(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)(param_1 + 4));
      }
      *(void **)(param_1 + 0xc) = (void *)(uVar5 * 0x54 + (int)pvVar3);
      *(void **)(param_1 + 8) = (void *)((param_3 + iVar2) * 0x54 + (int)pvVar3);
      *(void **)(param_1 + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(param_1 + 8);
      if ((uint)((iVar2 - param_2) / 0x54) < param_3) {
        FUN_00697d80(param_2,iVar2,param_3 * 0x54 + param_2,param_1,param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0069eaa0(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2) / 0x54,
                     local_70);
        iVar2 = *(int *)(param_1 + 8) + param_3 * 0x54;
        *(int *)(param_1 + 8) = iVar2;
        local_8 = 0;
        FUN_0069e940(param_2,iVar2 + param_3 * -0x54,local_70);
      }
      else {
        iVar1 = iVar2 + param_3 * -0x54;
        uVar4 = FUN_00697d80(iVar1,iVar2,iVar2,param_1,iVar1);
        *(undefined4 *)(param_1 + 8) = uVar4;
        FUN_0069e970(param_2,iVar1,iVar2,iVar1);
        FUN_0069e940(param_2,param_3 * 0x54 + param_2,local_70);
      }
    }
  }
  local_8 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_5c);
  ExceptionList = local_10;
  return;
}
```
