# Annotated low-level: FUN_007edb20

| Field | Value |
|---|---|
| Stable ID | `aa_007edb20` |
| VA | `0x007edb20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007edb20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007edca1) */
/* WARNING: Removing unreachable block (ram,0x007edcf1) */
/* WARNING: Removing unreachable block (ram,0x007edcb0) */

int __thiscall FUN_007edb20(char *param_1,int *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int *unaff_EBP;
  BSTR pOStack_70;
  wchar_t awStack_68 [20];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_14;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_009b0de8;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return -0x7fffbffc;
  }
  ExceptionList = &local_c;
  iVar2 = FUN_007e59d0();
  if (-1 < iVar2) {
    iVar2 = *param_2;
    if (DAT_00d1793c == '\0') {
      uStack_40 = 0;
      uStack_3c = 0;
      local_c = (void *)0x0;
      FUN_004230d0();
      iVar2 = FUN_00422fb0(1);
      if (-1 < iVar2) {
        iVar2 = FUN_0041a810(&uStack_40,param_1 + 0x28,0,0,&DAT_00a140c8);
      }
      if ((-1 < iVar2) && (iVar2 = FUN_004231d0(&uStack_40), -1 < iVar2)) {
        FUN_004231d0(&uStack_40);
      }
      FUN_00423170();
      FUN_007a4480(1,"DBReader: %u against %s");
      local_c = (void *)0xffffffff;
      FUN_0041a3e0();
    }
    else {
      FUN_00423670();
      local_c = (void *)0x1;
      _itow(iVar2,awStack_68,10);
      FUN_00422eb0();
      lstrlenW(L"\']");
      iVar2 = FUN_00422ee0();
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0();
      }
      FUN_00419ca0();
      local_c._0_1_ = 2;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      local_c._0_1_ = 1;
      FUN_00419ed0();
      piStack_4 = (int *)0x0;
      local_c = (void *)CONCAT31(local_c._1_3_,4);
      if (unaff_EBP == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      iVar2 = FUN_00419ff0();
      if (0 < iVar2) {
        if (unaff_EBP == (int *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        if (piStack_4 != (int *)0x0) {
          (**(code **)(*piStack_4 + 8))();
        }
        piStack_4 = (int *)0x0;
        (**(code **)(*unaff_EBP + 0x1c))(unaff_EBP);
        if (piStack_4 != (int *)0x0) {
          FUN_00423670();
          if (piStack_4 != (int *)0x0) {
            (**(code **)(*piStack_4 + 4))(piStack_4);
          }
          uVar1 = FUN_007b8a60();
          *(undefined2 *)param_2 = uVar1;
          FUN_00423670();
          if (piStack_4 != (int *)0x0) {
            (**(code **)(*piStack_4 + 4))(piStack_4);
          }
          iVar2 = FUN_007b8a60();
          param_2[1] = iVar2;
        }
      }
      local_c._0_1_ = 3;
      if (piStack_4 != (int *)0x0) {
        (**(code **)(*piStack_4 + 8))();
      }
      local_c = (void *)CONCAT31(local_c._1_3_,1);
      if (unaff_EBP != (int *)0x0) {
        (**(code **)(*unaff_EBP + 8))();
      }
      SysFreeString(pOStack_70);
    }
    iVar2 = 0;
  }
  ExceptionList = pvStack_14;
  return iVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
