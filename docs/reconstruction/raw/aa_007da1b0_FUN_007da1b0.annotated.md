# Annotated low-level: FUN_007da1b0

| Field | Value |
|---|---|
| Stable ID | `aa_007da1b0` |
| VA | `0x007da1b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007da1b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_007da1b0(char *param_1,int *param_2)

{
  IUnknown *This;
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  LPVOID pvVar4;
  int *piVar5;
  undefined4 *puVar6;
  ULONG UVar7;
  BSTR pOVar8;
  undefined4 uVar9;
  IUnknown *unaff_EBX;
  int *unaff_ESI;
  IUnknown *This_00;
  int *unaff_retaddr;
  IUnknown *local_5c;
  undefined1 *local_54;
  BSTR local_50;
  BSTR local_4c;
  undefined1 *local_48;
  int *local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 **local_30;
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
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aebdc;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return 0x80004004;
  }
  ExceptionList = &local_c;
  piVar2 = (int *)FUN_0040fb90();
  local_3c = 0;
  local_4 = 0;
  local_40 = piVar2;
  if (DAT_00d1793c == '\0') {
    local_20 = &local_38;
    local_38 = 0;
    local_34 = 0;
    local_30 = (undefined1 **)0x0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = 0;
    local_1c = 0;
    local_14 = 0;
    local_10 = 0;
    local_4 = 1;
    iVar3 = FUN_0041a810(local_20,param_1 + 0x28,0);
    local_30 = &local_54;
    if (((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) || (local_28 == 0)) {
      FUN_00423170();
      FUN_007a4480();
      local_4 = local_4 & 0xffffff00;
      piVar2 = (int *)0x7da2c5;
      FUN_0041a3e0();
      FUN_00415e90();
    }
    else {
      iVar3 = FUN_0041c000();
      while (iVar3 == 0) {
        iVar3 = FUN_00418700();
        FUN_00404840();
        piVar2[1] = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
        iVar3 = FUN_0041c000();
        piVar2 = local_40;
      }
      if (local_28 != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      *param_2 = local_3c;
      pvVar4 = CoTaskMemAlloc(local_3c * 4);
      param_2[1] = (int)pvVar4;
      piVar5 = (int *)*piVar2;
      if (piVar5 != piVar2) {
        iVar3 = 0;
        do {
          *(int *)(iVar3 + param_2[1]) = piVar5[2];
          piVar5 = (int *)*piVar5;
          iVar3 = iVar3 + 4;
        } while (piVar5 != piVar2);
      }
      local_4 = local_4 & 0xffffff00;
      piVar2 = (int *)0x7da395;
      FUN_0041a3e0();
      FUN_00415e90();
    }
  }
  else {
    local_4c = SysAllocString(L"//vGeneratableCreatures/row");
    if (local_4c == (BSTR)0x0) {
LAB_007da3bb:
                    /* WARNING: Subroutine does not return */
      FUN_004048e0(0x8007000e);
    }
    local_5c = (IUnknown *)0x0;
    local_48 = &stack0xffffff90;
    local_4._0_1_ = 4;
    FUN_00419ca0();
    local_4._0_1_ = 5;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4 = CONCAT31(local_4._1_3_,4);
    puVar6 = (undefined4 *)FUN_00419ed0();
    This = (IUnknown *)*puVar6;
    This_00 = (IUnknown *)0x0;
    if (This != (IUnknown *)0x0) {
      (*This->lpVtbl->AddRef)(This);
      This_00 = This;
    }
    if (local_50 != (BSTR)0x0) {
      (**(code **)(*(int *)local_50 + 8))();
    }
    if (This_00 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_50 = (BSTR)0x0;
    UVar7 = (*This_00->lpVtbl[2].Release)(This_00);
    if ((int)UVar7 < 0) {
      _com_issue_errorex(UVar7,This_00,(_GUID *)&DAT_00a86118);
    }
    *unaff_retaddr = (int)local_54;
    pvVar4 = CoTaskMemAlloc((int)local_54 * 4);
    unaff_retaddr[1] = (int)pvVar4;
    iVar3 = 0;
    if (0 < *unaff_retaddr) {
      do {
        if (unaff_EBX != (IUnknown *)0x0) {
          (*unaff_EBX->lpVtbl->Release)(unaff_EBX);
        }
        (*This_00->lpVtbl[2].AddRef)(This_00);
        if (unaff_ESI != (int *)0x0) {
          local_54 = &stack0xffffff84;
          pOVar8 = SysAllocString(L"IDCloneBase");
          if (pOVar8 == (BSTR)0x0) goto LAB_007da3bb;
          local_54 = &stack0xffffff88;
          puVar1 = &stack0xffffff88;
          if (unaff_ESI != (int *)0x0) {
            (**(code **)(*unaff_ESI + 4))(unaff_ESI);
            puVar1 = local_54;
          }
          local_54 = puVar1;
          uVar9 = FUN_007b8a60();
          *(undefined4 *)(unaff_retaddr[1] + iVar3 * 4) = uVar9;
          This_00 = local_5c;
        }
        unaff_EBX = (IUnknown *)0x0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *unaff_retaddr);
    }
    puStack_8._0_1_ = 3;
    if (unaff_EBX != (IUnknown *)0x0) {
      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
    (*This_00->lpVtbl->Release)(This_00);
    SysFreeString(local_50);
    piVar5 = (int *)*piVar2;
    *piVar2 = (int)piVar2;
    piVar2[1] = (int)piVar2;
    if (piVar5 != piVar2) {
                    /* WARNING: Subroutine does not return */
      operator_delete(piVar5);
    }
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar2);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
