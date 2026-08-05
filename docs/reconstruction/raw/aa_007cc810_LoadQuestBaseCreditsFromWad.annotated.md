# Annotated low-level: LoadQuestBaseCreditsFromWad

| Field | Value |
|---|---|
| Stable ID | `aa_007cc810` |
| VA | `0x007cc810` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007cc810`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Removing unreachable block (ram,0x007ccb04) */
/* WARNING: Removing unreachable block (ram,0x007cca93) */
/* WARNING: Removing unreachable block (ram,0x007ccaaf) */
/* WARNING: Removing unreachable block (ram,0x007ccac4) */
/* WARNING: Removing unreachable block (ram,0x007ccaca) */
/* WARNING: Removing unreachable block (ram,0x007ccaef) */
/* WARNING: Removing unreachable block (ram,0x007ccb0a) */
/* WARNING: Removing unreachable block (ram,0x007ccb65) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LoadQuestBaseCreditsFromWad — parse //tQuestBaseCredits/row from wad.xml.
   Columns: IDTargetLevel, intBaseCredits.
   Retail samples: L1=3, L2=10, L5=34, L9=97. */

undefined4 __fastcall LoadQuestBaseCreditsFromWad(int param_1)

{
  int iVar1;
  BSTR bstrString;
  ULONG UVar2;
  IUnknown *pIStack_74;
  IUnknown *local_6c;
  int local_64;
  undefined1 *local_60;
  BSTR local_5c;
  BSTR local_58;
  undefined4 local_44;
  undefined4 local_40;
  int *local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009ae727;
  local_14 = ExceptionList;
  if (DAT_00d1793c == '\0') {
    local_2c = &local_44;
    local_44 = 0;
    local_40 = 0;
    local_3c = (int *)0x0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_24 = 0;
    local_28 = 0;
    local_20 = 0;
    local_1c = 0;
    local_c = 0;
    ExceptionList = &local_14;
    iVar1 = FUN_0041a810(local_2c,param_1 + 0x28,0,0);
    local_3c = &local_64;
    if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (iVar1 = FUN_004231d0(), iVar1 < 0)
        ) || (local_34 == 0)) {
      FUN_00423170();
      FUN_007a4480(1);
      local_c = 0xffffffff;
      FUN_0041a3e0();
    }
    else {
      iVar1 = FUN_0041c000();
      while (iVar1 == 0) {
        FUN_0040ed60();
        iVar1 = FUN_0041c000();
      }
      if (local_34 != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      local_c = 0xffffffff;
      FUN_0041a3e0();
    }
  }
  else {
    ExceptionList = &local_14;
    bstrString = SysAllocString(L"//tQuestBaseCredits/row");
    local_58 = bstrString;
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_60 = &stack0xffffff7c;
    local_c = 1;
    FUN_00419ca0();
    local_c._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_c._0_1_ = 1;
    FUN_00419ed0();
    local_c = CONCAT31(local_c._1_3_,4);
    if (local_6c == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar2 = (*local_6c->lpVtbl[2].Release)(local_6c);
    if ((int)UVar2 < 0) {
      _com_issue_errorex(UVar2,local_6c,(_GUID *)&DAT_00a86118);
    }
    local_64 = 0;
    if (0 < (int)local_6c) {
      do {
        iVar1 = local_64;
        _com_issue_error(-0x7fffbffd);
        if (pIStack_74 != (IUnknown *)0x0) {
          (*pIStack_74->lpVtbl->Release)(pIStack_74);
        }
        pIStack_74 = (IUnknown *)0x0;
        (**(code **)(_DAT_00000000 + 0x1c))(0);
        local_64 = iVar1 + 1;
        bstrString = local_5c;
      } while (local_64 < (int)local_6c);
    }
    puStack_10._0_1_ = 3;
    if (pIStack_74 != (IUnknown *)0x0) {
      (*pIStack_74->lpVtbl->Release)(pIStack_74);
    }
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    SysFreeString(bstrString);
  }
  ExceptionList = pvStack_18;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
