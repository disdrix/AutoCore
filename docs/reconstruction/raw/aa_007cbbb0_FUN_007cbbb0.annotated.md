# Annotated low-level: FUN_007cbbb0

| Field | Value |
|---|---|
| Stable ID | `aa_007cbbb0` |
| VA | `0x007cbbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007cbbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007cc025) */
/* WARNING: Removing unreachable block (ram,0x007cbfa7) */
/* WARNING: Removing unreachable block (ram,0x007cbf2c) */
/* WARNING: Removing unreachable block (ram,0x007cbeff) */
/* WARNING: Removing unreachable block (ram,0x007cbf17) */
/* WARNING: Removing unreachable block (ram,0x007cbf32) */
/* WARNING: Removing unreachable block (ram,0x007cbf53) */
/* WARNING: Removing unreachable block (ram,0x007cbf68) */
/* WARNING: Removing unreachable block (ram,0x007cbf6e) */
/* WARNING: Removing unreachable block (ram,0x007cbf92) */
/* WARNING: Removing unreachable block (ram,0x007cbfad) */
/* WARNING: Removing unreachable block (ram,0x007cbfd1) */
/* WARNING: Removing unreachable block (ram,0x007cbfe6) */
/* WARNING: Removing unreachable block (ram,0x007cbfec) */
/* WARNING: Removing unreachable block (ram,0x007cc010) */
/* WARNING: Removing unreachable block (ram,0x007cc02b) */
/* WARNING: Removing unreachable block (ram,0x007cc09d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_007cbbb0(int param_1)

{
  uint uVar1;
  int iVar2;
  ULONG UVar3;
  IUnknown *unaff_EBX;
  IUnknown *This;
  IUnknown *local_80;
  int local_7c [4];
  undefined4 local_6c;
  int local_68;
  BSTR local_64;
  BSTR local_60;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ae68b;
  local_c = ExceptionList;
  local_7c[0] = 0;
  local_7c[2] = 0;
  local_7c[3] = 0;
  local_6c = 0;
  local_68 = 0;
  if (DAT_00d1793c == '\0') {
    local_20 = &local_38;
    local_38 = 0;
    local_34 = 0;
    local_30 = (int *)0x0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_18 = 0;
    local_1c = 0;
    local_14 = 0;
    local_10 = (void *)0x0;
    local_4 = 0;
    ExceptionList = &local_c;
    iVar2 = FUN_0041a810(local_20,param_1 + 0x28,0,0);
    local_30 = local_7c;
    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0)
        ) || (((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||
              ((iVar2 = FUN_004231d0(), iVar2 < 0 || (local_28 == 0)))))) {
      FUN_00423170();
      FUN_007a4480(1);
      local_4 = 0xffffffff;
      FUN_0041a3e0();
    }
    else {
      iVar2 = FUN_0041c000();
      while (iVar2 == 0) {
        local_50 = CONCAT22((undefined2)local_6c,(short)local_7c[3]);
        uVar1 = (uint)local_4c >> 0x10;
        local_4c = CONCAT22((short)uVar1,(undefined2)local_68);
        local_3c = local_4c;
        local_48 = local_7c[0];
        local_44 = local_7c[2];
        local_40 = local_50;
        FUN_0041b2a0();
        iVar2 = FUN_0041c000();
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
    local_60 = SysAllocString(L"//tExperienceLevel/row");
    if (local_60 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_64 = (BSTR)&stack0xffffff68;
    local_4 = 1;
    FUN_00419ca0();
    local_4._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4._0_1_ = 1;
    FUN_00419ed0();
    local_4 = CONCAT31(local_4._1_3_,4);
    if (local_80 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_7c[1] = 0;
    UVar3 = (*local_80->lpVtbl[2].Release)(local_80);
    if ((int)UVar3 < 0) {
      _com_issue_errorex(UVar3,local_80,(_GUID *)&DAT_00a86118);
    }
    local_68 = 0;
    This = unaff_EBX;
    if (0 < local_7c[0]) {
      do {
        iVar2 = local_68;
        _com_issue_error(-0x7fffbffd);
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
        This = (IUnknown *)0x0;
        (**(code **)(_DAT_00000000 + 0x1c))(0);
        unaff_EBX = (IUnknown *)0x0;
        local_68 = iVar2 + 1;
      } while (local_68 < local_7c[0]);
    }
    puStack_8._0_1_ = 3;
    if (unaff_EBX != (IUnknown *)0x0) {
      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
    SysFreeString(local_64);
  }
  ExceptionList = local_10;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
