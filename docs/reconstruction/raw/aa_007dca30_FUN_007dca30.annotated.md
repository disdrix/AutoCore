# Annotated low-level: FUN_007dca30

| Field | Value |
|---|---|
| Stable ID | `aa_007dca30` |
| VA | `0x007dca30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007dca30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007dd533) */
/* WARNING: Removing unreachable block (ram,0x007dd4c1) */
/* WARNING: Removing unreachable block (ram,0x007dd44f) */
/* WARNING: Removing unreachable block (ram,0x007dd3d9) */
/* WARNING: Removing unreachable block (ram,0x007dd367) */
/* WARNING: Removing unreachable block (ram,0x007dd2f3) */
/* WARNING: Removing unreachable block (ram,0x007dd287) */
/* WARNING: Removing unreachable block (ram,0x007dd216) */
/* WARNING: Removing unreachable block (ram,0x007dd1aa) */
/* WARNING: Removing unreachable block (ram,0x007dd13e) */
/* WARNING: Removing unreachable block (ram,0x007dd0da) */
/* WARNING: Removing unreachable block (ram,0x007dd0e0) */
/* WARNING: Removing unreachable block (ram,0x007dd0ea) */
/* WARNING: Removing unreachable block (ram,0x007dd0f6) */
/* WARNING: Removing unreachable block (ram,0x007dd0fc) */
/* WARNING: Removing unreachable block (ram,0x007dd118) */
/* WARNING: Removing unreachable block (ram,0x007dd144) */
/* WARNING: Removing unreachable block (ram,0x007dd174) */
/* WARNING: Removing unreachable block (ram,0x007dd17a) */
/* WARNING: Removing unreachable block (ram,0x007dd1b0) */
/* WARNING: Removing unreachable block (ram,0x007dd1e0) */
/* WARNING: Removing unreachable block (ram,0x007dd1e6) */
/* WARNING: Removing unreachable block (ram,0x007dd21c) */
/* WARNING: Removing unreachable block (ram,0x007dd24c) */
/* WARNING: Removing unreachable block (ram,0x007dd252) */
/* WARNING: Removing unreachable block (ram,0x007dd28d) */
/* WARNING: Removing unreachable block (ram,0x007dd2ba) */
/* WARNING: Removing unreachable block (ram,0x007dd2c0) */
/* WARNING: Removing unreachable block (ram,0x007dd2f9) */
/* WARNING: Removing unreachable block (ram,0x007dd32e) */
/* WARNING: Removing unreachable block (ram,0x007dd334) */
/* WARNING: Removing unreachable block (ram,0x007dd36d) */
/* WARNING: Removing unreachable block (ram,0x007dd3a0) */
/* WARNING: Removing unreachable block (ram,0x007dd3a6) */
/* WARNING: Removing unreachable block (ram,0x007dd3df) */
/* WARNING: Removing unreachable block (ram,0x007dd414) */
/* WARNING: Removing unreachable block (ram,0x007dd41a) */
/* WARNING: Removing unreachable block (ram,0x007dd455) */
/* WARNING: Removing unreachable block (ram,0x007dd488) */
/* WARNING: Removing unreachable block (ram,0x007dd48e) */
/* WARNING: Removing unreachable block (ram,0x007dd4c7) */
/* WARNING: Removing unreachable block (ram,0x007dd4fa) */
/* WARNING: Removing unreachable block (ram,0x007dd500) */
/* WARNING: Removing unreachable block (ram,0x007dd539) */
/* WARNING: Removing unreachable block (ram,0x007dd574) */
/* WARNING: Removing unreachable block (ram,0x007dd57a) */

undefined4 __thiscall FUN_007dca30(int param_1,char *param_2,int param_3)

{
  BSTR bstrString;
  int iVar1;
  wchar_t *lpString;
  IUnknown *This;
  ULONG UVar2;
  int *unaff_EBX;
  undefined1 *local_1bc;
  undefined4 local_1b8;
  undefined4 *local_1b4;
  undefined4 local_1b0;
  int local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 *local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  IUnknown *local_190;
  IUnknown *local_18c;
  short sStack_188;
  BSTR local_180;
  short sStack_17c;
  short sStack_178;
  short sStack_174;
  short sStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  wchar_t local_13c [18];
  wchar_t awStack_118 [66];
  wchar_t awStack_94 [66];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009aeda3;
  local_c = ExceptionList;
  if (DAT_00d1793c == '\0') {
    if (*param_2 == '\0') {
      ExceptionList = pvStack_10;
      return 0x80004004;
    }
    local_1a0 = &local_1b8;
    local_1b8 = 0;
    local_1b4 = (undefined4 *)0x0;
    local_1b0 = 0;
    local_1ac = 0;
    local_1a8 = 0;
    local_1a4 = 0;
    local_198 = 0;
    local_19c = 0;
    local_194 = 0;
    local_190 = (IUnknown *)0x0;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_004230d0();
    iVar1 = FUN_00422fb0();
    if (-1 < iVar1) {
      iVar1 = FUN_0041a810(&local_1bc,param_2 + 0x28,0,0);
    }
    local_1b4 = &uStack_16c;
    if (((((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
           (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
          (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
           ((iVar1 = FUN_004231d0(), iVar1 < 0 ||
            ((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)))))))) ||
         ((iVar1 = FUN_004231d0(), iVar1 < 0 ||
          (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
           (iVar1 = FUN_004231d0(), iVar1 < 0)))))) ||
        (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
         (((iVar1 = FUN_004231d0(), iVar1 < 0 ||
           ((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)))) ||
          (iVar1 = FUN_004231d0(), iVar1 < 0)))))) ||
       ((((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||
         (iVar1 = FUN_004231d0(), iVar1 < 0)) || (local_1ac == 0)))) {
      FUN_00423170();
      FUN_007a4480(1);
      puStack_8 = (undefined1 *)0xffffffff;
      FUN_0041a3e0();
    }
    else {
      iVar1 = FUN_0041a9b0();
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 4) = uStack_16c;
        *(undefined4 *)(param_1 + 8) = uStack_168;
        *(int *)(param_1 + 0x10) = (int)sStack_174;
        *(undefined4 *)(param_1 + 0xc) = uStack_148;
        *(int *)(param_1 + 0x14) = (int)(short)local_180;
        *(int *)(param_1 + 0x18) = (int)sStack_17c;
        wcscpy((wchar_t *)(param_1 + 0x1c),awStack_118);
        *(undefined4 *)(param_1 + 0xa8) = uStack_15c;
        *(undefined4 *)(param_1 + 0xa4) = uStack_144;
        *(undefined4 *)(param_1 + 0x138) = uStack_150;
        *(int *)(param_1 + 0xa0) = (int)sStack_188;
        *(undefined4 *)(param_1 + 0xac) = uStack_14c;
        *(undefined4 *)(param_1 + 0x13c) = uStack_154;
        *(undefined4 *)(param_1 + 0xb0) = uStack_164;
        wcscpy((wchar_t *)(param_1 + 0xb4),awStack_94);
        *(undefined4 *)(param_1 + 0x140) = uStack_160;
        *(undefined4 *)(param_1 + 0x144) = uStack_158;
        *(uint *)(param_1 + 0x148) = (uint)(sStack_170 == -1);
        *(uint *)(param_1 + 0x14c) = (uint)(sStack_178 == -1);
        *(uint *)(param_1 + 0x150) = (uint)((short)local_18c == -1);
        FUN_0041a990();
        FUN_00423170();
        puStack_8 = (undefined1 *)0xffffffff;
        FUN_0041a3e0();
      }
      else {
        FUN_0041a990();
        FUN_00423170();
        FUN_007a4480(1);
        puStack_8 = (undefined1 *)0xffffffff;
        FUN_0041a3e0();
      }
    }
  }
  else {
    ExceptionList = &local_c;
    local_180 = SysAllocString(L"//tContinentObject/row[@IDContinentObject=\'");
    if (local_180 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_4 = 1;
    lpString = _itow(param_3,local_13c,10);
    lstrlenW(lpString);
    iVar1 = FUN_00422ee0();
    if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    lstrlenW(L"\']");
    iVar1 = FUN_00422ee0();
    bstrString = local_180;
    if (iVar1 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_1bc = &stack0xfffffe2c;
    FUN_00419ca0();
    local_4._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_4._0_1_ = 1;
    FUN_00419ed0();
    local_4 = CONCAT31(local_4._1_3_,4);
    This = local_18c;
    if (local_18c == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
      This = local_18c;
    }
    local_1bc = (undefined1 *)0x0;
    UVar2 = (*This->lpVtbl[2].Release)(This);
    if ((int)UVar2 < 0) {
      _com_issue_errorex(UVar2,This,(_GUID *)&DAT_00a86118);
    }
    puStack_8._0_1_ = 3;
    if (unaff_EBX != (int *)0x0) {
      (**(code **)(*unaff_EBX + 8))();
    }
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
    if (local_190 != (IUnknown *)0x0) {
      (*local_190->lpVtbl->Release)(local_190);
    }
    SysFreeString(bstrString);
  }
  ExceptionList = pvStack_10;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
