# Annotated low-level: FUN_007edf30

| Field | Value |
|---|---|
| Stable ID | `aa_007edf30` |
| VA | `0x007edf30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007edf30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007ee2d9) */
/* WARNING: Removing unreachable block (ram,0x007ee265) */
/* WARNING: Removing unreachable block (ram,0x007ee23a) */
/* WARNING: Removing unreachable block (ram,0x007ee291) */
/* WARNING: Removing unreachable block (ram,0x007ee297) */
/* WARNING: Removing unreachable block (ram,0x007ee2df) */
/* WARNING: Removing unreachable block (ram,0x007ee2fa) */

int __thiscall FUN_007edf30(char *param_1,int *param_2)

{
  int iVar1;
  BSTR unaff_EBX;
  int iStack_70;
  undefined1 *puStack_6c;
  wchar_t awStack_68 [20];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_009b0e1c;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return -0x7fffbffc;
  }
  ExceptionList = &local_c;
  iVar1 = FUN_007e59d0();
  if (-1 < iVar1) {
    iVar1 = *param_2;
    if (DAT_00d1793c == '\0') {
      puStack_28 = &uStack_40;
      uStack_40 = 0;
      uStack_3c = 0;
      piStack_38 = (int *)0x0;
      uStack_34 = 0;
      iStack_30 = 0;
      uStack_2c = 0;
      uStack_20 = 0;
      uStack_24 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      local_c = (void *)0x0;
      FUN_004230d0();
      iVar1 = FUN_00422fb0(1);
      if (-1 < iVar1) {
        iVar1 = FUN_0041a810(&uStack_40,param_1 + 0x28,0,0,&DAT_00a140c8);
      }
      piStack_38 = &iStack_70;
      if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) ||
          (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) || (iStack_30 == 0)) {
        FUN_00423170();
        FUN_007a4480(1,"DBReader: %u against %s");
        local_c = (void *)0xffffffff;
        FUN_0041a3e0();
      }
      else {
        iVar1 = FUN_0041a9b0();
        if (iVar1 == 0) {
          *param_2 = iStack_70;
          param_2[1] = (int)puStack_6c;
          FUN_0041a990();
          FUN_00423170();
          local_c = (void *)0xffffffff;
          FUN_0041a3e0();
        }
        else {
          FUN_0041a990();
          FUN_00423170();
          FUN_007a4480(1,"DBReader: %u against %s");
          local_c = (void *)0xffffffff;
          FUN_0041a3e0();
        }
      }
    }
    else {
      FUN_00423670();
      local_c = (void *)0x1;
      _itow(iVar1,awStack_68,10);
      FUN_00422eb0();
      lstrlenW(L"\']");
      iVar1 = FUN_00422ee0();
      if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0();
      }
      puStack_6c = &stack0xffffff74;
      FUN_00419ca0();
      local_c._0_1_ = 2;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      local_c._0_1_ = 1;
      FUN_00419ed0();
      local_c = (void *)CONCAT31(local_c._1_3_,4);
      if (piStack_4 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      iVar1 = FUN_00419ff0();
      if (0 < iVar1) {
        if (piStack_4 == (int *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        (**(code **)(*piStack_4 + 0x1c))(piStack_4);
      }
      local_c = (void *)CONCAT31(local_c._1_3_,1);
      if (piStack_4 != (int *)0x0) {
        (**(code **)(*piStack_4 + 8))();
      }
      SysFreeString(unaff_EBX);
    }
    iVar1 = 0;
  }
  ExceptionList = pvStack_14;
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
