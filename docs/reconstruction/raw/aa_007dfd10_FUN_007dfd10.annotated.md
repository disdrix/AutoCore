# Annotated low-level: FUN_007dfd10

| Field | Value |
|---|---|
| Stable ID | `aa_007dfd10` |
| VA | `0x007dfd10` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007dfd10`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_007dfd10(char *param_1,int param_2,int *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  BSTR pOVar4;
  wchar_t *lpString;
  ULONG UVar5;
  uint uVar6;
  undefined2 unaff_BX;
  undefined2 unaff_BP;
  undefined4 unaff_ESI;
  BSTR pOStack_80;
  int *piStack_7c;
  IUnknown *pIStack_78;
  IUnknown *local_6c;
  wchar_t local_60 [14];
  undefined1 auStack_44 [8];
  undefined1 *puStack_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aef72;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    ExceptionList = local_18;
    return 0x80004004;
  }
  if (DAT_00d1793c == '\0') {
    local_20 = &local_38;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = (void *)0x0;
    local_1c = 0;
    local_14 = 0;
    local_10 = 0;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_004230d0();
    iVar3 = FUN_00422fb0(1);
    if (-1 < iVar3) {
      iVar3 = FUN_0041a810(auStack_44,param_1 + 0x28,0,0,&DAT_00a140c8);
    }
    puStack_3c = &stack0xffffff76;
    if ((((iVar3 < 0) || (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||
        (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||
       (((iVar3 = FUN_004231d0(auStack_44), iVar3 < 0 ||
         (iVar3 = FUN_004231d0(auStack_44), iVar3 < 0)) ||
        ((iVar3 = FUN_004231d0(auStack_44), iVar3 < 0 || (local_34 == 0)))))) {
      FUN_00423170();
      FUN_007a4480(1,"DBReader: %u against %s");
    }
    else {
      iVar3 = FUN_0041a9b0();
      if (iVar3 != 0) {
        FUN_0041a990();
        FUN_00423170();
        FUN_007a4480(1,"DBReader: %u against %s");
        local_10 = 0xffffffff;
        FUN_0041a3e0();
        ExceptionList = local_18;
        return 0;
      }
      *(undefined2 *)((int)param_3 + 6) = unaff_BP;
      *(char *)((int)param_3 + 9) = (char)((uint)unaff_ESI >> 0x10);
      uVar6 = (int)(short)pOStack_80 >> 0x1f;
      iVar3 = ((int)(short)pOStack_80 ^ uVar6) - uVar6;
      *(char *)((int)param_3 + 10) = (char)((uint)unaff_ESI >> 0x18);
      *param_3 = iVar3;
      *(char *)(param_3 + 2) = (char)iVar3;
      *(undefined2 *)(param_3 + 1) = unaff_BX;
      FUN_0041a990();
      FUN_00423170();
    }
    local_10 = 0xffffffff;
    FUN_0041a3e0();
  }
  else {
    ExceptionList = &local_c;
    pOVar4 = SysAllocString(L"//tCharacter/row[@IDCloneBase=\'");
    if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_4 = 1;
    lpString = _itow(param_2,local_60,10);
    lstrlenW(lpString);
    iVar3 = FUN_00422ee0();
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    lstrlenW(L"\']");
    iVar3 = FUN_00422ee0();
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    FUN_00419ca0();
    local_4._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4._0_1_ = 1;
    FUN_00419ed0();
    local_4 = CONCAT31(local_4._1_3_,4);
    if (local_6c == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar5 = (*local_6c->lpVtbl[2].Release)(local_6c);
    if ((int)UVar5 < 0) {
      _com_issue_errorex(UVar5,local_6c,(_GUID *)&DAT_00a86118);
    }
    if (0 < param_2) {
      _com_issue_error(-0x7fffbffd);
      if (pOVar4 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar4 + 8))();
      }
      (**(code **)(_DAT_00000000 + 0x1c))((IUnknown *)0x0);
      if (piStack_7c != (int *)0x0) {
        FUN_00423670();
        if (piStack_7c != (int *)0x0) {
          (**(code **)(*piStack_7c + 4))(piStack_7c);
        }
        uVar1 = FUN_007b8a60();
        *(undefined1 *)((int)param_3 + 10) = uVar1;
        FUN_00423670();
        if (piStack_7c != (int *)0x0) {
          (**(code **)(*piStack_7c + 4))(piStack_7c);
        }
        uVar1 = FUN_007b8a60();
        *(undefined1 *)((int)param_3 + 9) = uVar1;
        FUN_00423670();
        if (piStack_7c != (int *)0x0) {
          (**(code **)(*piStack_7c + 4))(piStack_7c);
        }
        uVar2 = FUN_007b8a60();
        *(undefined2 *)((int)param_3 + 6) = uVar2;
        FUN_00423670();
        if (piStack_7c != (int *)0x0) {
          (**(code **)(*piStack_7c + 4))(piStack_7c);
        }
        uVar2 = FUN_007b8a60();
        *(undefined2 *)(param_3 + 1) = uVar2;
        FUN_00423670();
        if (piStack_7c != (int *)0x0) {
          (**(code **)(*piStack_7c + 4))(piStack_7c);
        }
        iVar3 = FUN_007b8910();
        *param_3 = iVar3;
        *(bool *)(param_3 + 2) = iVar3 != 0;
      }
    }
    local_10._0_1_ = 3;
    if (piStack_7c != (int *)0x0) {
      (**(code **)(*piStack_7c + 8))();
    }
    local_10 = CONCAT31(local_10._1_3_,1);
    if (pIStack_78 != (IUnknown *)0x0) {
      (*pIStack_78->lpVtbl->Release)(pIStack_78);
    }
    SysFreeString(pOStack_80);
  }
  ExceptionList = local_18;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
