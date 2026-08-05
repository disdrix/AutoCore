# Raw capture: FUN_007ec7e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ec7e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ec7e0` |
| **Canonical name** | `FUN_007ec7e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007ecdf8) */
/* WARNING: Removing unreachable block (ram,0x007ecd8c) */
/* WARNING: Removing unreachable block (ram,0x007ecd1e) */
/* WARNING: Removing unreachable block (ram,0x007eccb0) */
/* WARNING: Removing unreachable block (ram,0x007ecc3b) */
/* WARNING: Removing unreachable block (ram,0x007ecbf3) */
/* WARNING: Removing unreachable block (ram,0x007ecc15) */
/* WARNING: Removing unreachable block (ram,0x007ecc41) */
/* WARNING: Removing unreachable block (ram,0x007ecc79) */
/* WARNING: Removing unreachable block (ram,0x007ecc7f) */
/* WARNING: Removing unreachable block (ram,0x007eccb6) */
/* WARNING: Removing unreachable block (ram,0x007ecce7) */
/* WARNING: Removing unreachable block (ram,0x007ecced) */
/* WARNING: Removing unreachable block (ram,0x007ecd24) */
/* WARNING: Removing unreachable block (ram,0x007ecd55) */
/* WARNING: Removing unreachable block (ram,0x007ecd5b) */
/* WARNING: Removing unreachable block (ram,0x007ecd92) */
/* WARNING: Removing unreachable block (ram,0x007ecdc3) */
/* WARNING: Removing unreachable block (ram,0x007ecdc9) */
/* WARNING: Removing unreachable block (ram,0x007ecdfe) */
/* WARNING: Removing unreachable block (ram,0x007ece1a) */

int __thiscall FUN_007ec7e0(char *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uStack_90;
  undefined2 auStack_8c [2];
  int *piStack_88;
  undefined2 uStack_84;
  undefined2 uStack_80;
  int iStack_7c;
  undefined2 uStack_78;
  BSTR pOStack_74;
  undefined2 uStack_70;
  undefined2 uStack_6c;
  undefined2 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined2 *puStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 *puStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined2 uStack_38;
  wchar_t awStack_34 [20];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b0d3d;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    iVar1 = -0x7fffbffc;
  }
  else {
    ExceptionList = &local_c;
    iVar1 = FUN_007e59d0();
    if (-1 < iVar1) {
      iStack_7c = *param_2;
      if (DAT_00d1793c == '\0') {
        puStack_4c = &uStack_64;
        uStack_64 = 0;
        uStack_60 = 0;
        puStack_5c = (undefined2 *)0x0;
        uStack_58 = 0;
        iStack_54 = 0;
        uStack_50 = 0;
        uStack_44 = 0;
        uStack_48 = 0;
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_4 = 0;
        FUN_004230d0();
        iVar1 = FUN_00422fb0(1);
        if (-1 < iVar1) {
          iVar1 = FUN_0041a810(&uStack_64,param_1 + 0x28,0,0,&DAT_00a140c8);
        }
        puStack_5c = auStack_8c;
        if ((((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)) ||
              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)) ||
             ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||
              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)))) ||
            ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||
             ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||
              (iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0)))))) ||
           ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 ||
            ((iVar1 = FUN_004231d0(&uStack_64), iVar1 < 0 || (iStack_54 == 0)))))) {
          FUN_00423170();
          FUN_007a4480(1,"DBReader: %u against %s");
          uStack_4 = 0xffffffff;
          FUN_0041a3e0();
        }
        else {
          iVar1 = FUN_0041a9b0();
          if (iVar1 == 0) {
            *(undefined2 *)((int)param_4 + 6) = auStack_8c[0];
            *(undefined2 *)((int)param_4 + 10) = uStack_70;
            *(undefined2 *)(param_4 + 2) = uStack_68;
            *(undefined2 *)((int)param_4 + 0xe) = uStack_6c;
            *(undefined2 *)(param_4 + 3) = uStack_80;
            *(undefined2 *)(param_4 + 1) = uStack_78;
            *(undefined2 *)(param_4 + 4) = uStack_38;
            *param_4 = uStack_90;
            *(undefined2 *)((int)param_4 + 0x12) = uStack_84;
            FUN_0041a990();
            FUN_00423170();
          }
          else {
            FUN_0041a990();
            FUN_00423170();
            FUN_007a4480(1,"DBReader: %u against %s");
          }
          uStack_4 = 0xffffffff;
          FUN_0041a3e0();
        }
      }
      else {
        FUN_00423670();
        uStack_4 = 1;
        _itow(iStack_7c,awStack_34,10);
        FUN_00422eb0();
        lstrlenW(L"\']");
        iVar1 = FUN_00422ee0();
        if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
          FUN_004048e0();
        }
        FUN_00419ca0();
        uStack_4._0_1_ = 2;
        if (DAT_00d1e56c == 0) {
          _com_issue_error(-0x7fffbffd);
        }
        uStack_4._0_1_ = 1;
        FUN_00419ed0();
        uStack_4 = CONCAT31(uStack_4._1_3_,4);
        if (piStack_88 == (int *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        iVar1 = FUN_00419ff0();
        if (0 < iVar1) {
          if (piStack_88 == (int *)0x0) {
            _com_issue_error(-0x7fffbffd);
          }
          (**(code **)(*piStack_88 + 0x1c))(piStack_88);
        }
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        if (piStack_88 != (int *)0x0) {
          (**(code **)(*piStack_88 + 8))();
        }
        SysFreeString(pOStack_74);
      }
      iVar1 = 0;
    }
  }
  ExceptionList = local_c;
  return iVar1;
}
```
