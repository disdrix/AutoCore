# Raw capture: FUN_007cd9a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cd9a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007cd9a0` |
| **Canonical name** | `FUN_007cd9a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007ce0c5) */
/* WARNING: Removing unreachable block (ram,0x007ce055) */
/* WARNING: Removing unreachable block (ram,0x007cdfe5) */
/* WARNING: Removing unreachable block (ram,0x007cdf75) */
/* WARNING: Removing unreachable block (ram,0x007cdf05) */
/* WARNING: Removing unreachable block (ram,0x007cde96) */
/* WARNING: Removing unreachable block (ram,0x007cde21) */
/* WARNING: Removing unreachable block (ram,0x007cddd9) */
/* WARNING: Removing unreachable block (ram,0x007cddfb) */
/* WARNING: Removing unreachable block (ram,0x007cde27) */
/* WARNING: Removing unreachable block (ram,0x007cde5f) */
/* WARNING: Removing unreachable block (ram,0x007cde65) */
/* WARNING: Removing unreachable block (ram,0x007cde9c) */
/* WARNING: Removing unreachable block (ram,0x007cdecd) */
/* WARNING: Removing unreachable block (ram,0x007cded3) */
/* WARNING: Removing unreachable block (ram,0x007cdf0b) */
/* WARNING: Removing unreachable block (ram,0x007cdf3d) */
/* WARNING: Removing unreachable block (ram,0x007cdf43) */
/* WARNING: Removing unreachable block (ram,0x007cdf7b) */
/* WARNING: Removing unreachable block (ram,0x007cdfad) */
/* WARNING: Removing unreachable block (ram,0x007cdfb3) */
/* WARNING: Removing unreachable block (ram,0x007cdfeb) */
/* WARNING: Removing unreachable block (ram,0x007ce01d) */
/* WARNING: Removing unreachable block (ram,0x007ce023) */
/* WARNING: Removing unreachable block (ram,0x007ce05b) */
/* WARNING: Removing unreachable block (ram,0x007ce08d) */
/* WARNING: Removing unreachable block (ram,0x007ce093) */
/* WARNING: Removing unreachable block (ram,0x007ce0cb) */
/* WARNING: Removing unreachable block (ram,0x007ce0e8) */

undefined4 __thiscall FUN_007cd9a0(char *param_1,undefined4 *param_2)

{
  int iVar1;
  BSTR bstrString;
  undefined2 local_7c;
  undefined2 local_78;
  int *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  BSTR local_40;
  undefined1 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ae7fd;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return 0x80004004;
  }
  if (DAT_00d1793c == '\0') {
    local_20 = &local_38;
    local_38 = 0;
    local_34 = 0;
    local_30 = (undefined4 *)0x0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = 0;
    local_1c = 0;
    local_14 = 0;
    local_10 = 0;
    local_4 = 0;
    ExceptionList = &local_c;
    iVar1 = FUN_0041a810(local_20,param_1 + 0x28,0,0,&DAT_00a140c8);
    local_30 = &local_6c;
    if (((((iVar1 < 0) || (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||
         (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||
        (((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
          (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||
         ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
          ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)))))))) ||
       ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
        (((((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
            (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||
           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)) ||
          ((iVar1 = FUN_004231d0(&local_38), iVar1 < 0 ||
           (iVar1 = FUN_004231d0(&local_38), iVar1 < 0)))) || (local_28 == 0)))))) {
      FUN_00423170();
      FUN_007a4480(1,"DBReader: %u against %s");
      local_4 = 0xffffffff;
      FUN_0041a3e0();
    }
    else {
      iVar1 = FUN_0041c000();
      if (iVar1 == 0) {
        *param_2 = local_6c;
        param_2[2] = local_68;
        param_2[3] = local_64;
        param_2[4] = local_60;
        param_2[5] = local_5c;
        param_2[6] = local_58;
        param_2[7] = local_54;
        param_2[8] = local_50;
        param_2[9] = local_4c;
        param_2[10] = local_48;
        *(undefined2 *)(param_2 + 1) = local_7c;
        *(undefined2 *)((int)param_2 + 6) = local_78;
        param_2[0xb] = local_44;
      }
      if (local_28 != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      local_4 = 0xffffffff;
      FUN_0041a3e0();
    }
  }
  else {
    ExceptionList = &local_c;
    bstrString = SysAllocString(L"//tLootConfig/row");
    local_40 = bstrString;
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_3c = &stack0xffffff70;
    local_4 = 1;
    FUN_00419ca0();
    local_4._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4._0_1_ = 1;
    FUN_00419ed0();
    local_4._0_1_ = 4;
    if (local_70 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    (**(code **)(*local_70 + 0x1c))(local_70);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (local_70 != (int *)0x0) {
      (**(code **)(*local_70 + 8))();
    }
    SysFreeString(bstrString);
  }
  ExceptionList = local_c;
  return 0;
}
```
