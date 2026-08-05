# Raw capture: LoadQuestCreditsLookupFromWad

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc470` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007cc470` |
| **Canonical name** | `LoadQuestCreditsLookupFromWad` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007cc777) */
/* WARNING: Removing unreachable block (ram,0x007cc704) */
/* WARNING: Removing unreachable block (ram,0x007cc722) */
/* WARNING: Removing unreachable block (ram,0x007cc737) */
/* WARNING: Removing unreachable block (ram,0x007cc73d) */
/* WARNING: Removing unreachable block (ram,0x007cc762) */
/* WARNING: Removing unreachable block (ram,0x007cc77d) */
/* WARNING: Removing unreachable block (ram,0x007cc7e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* LoadQuestCreditsLookupFromWad — parse //tQuestCreditsLookup/row from wad.xml.
   Columns: IDQuestCreditsIndex, rlLevelCredits.
   Retail index 0→0, 1→0.2 … 5→1.0 … 10→2.0. */

undefined4 __fastcall LoadQuestCreditsLookupFromWad(int param_1)

{
  int iVar1;
  BSTR bstrString;
  ULONG UVar2;
  IUnknown *unaff_EBX;
  IUnknown *This;
  IUnknown *local_70;
  int local_68 [3];
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
  puStack_10 = &LAB_009ae6f3;
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
    local_3c = local_68;
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
        FUN_0041b1e0();
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
    bstrString = SysAllocString(L"//tQuestCreditsLookup/row");
    local_58 = bstrString;
    if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    local_5c = (BSTR)&stack0xffffff7c;
    local_c = 1;
    FUN_00419ca0();
    local_c._0_1_ = 2;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    local_c._0_1_ = 1;
    FUN_00419ed0();
    local_c = CONCAT31(local_c._1_3_,4);
    if (local_70 == (IUnknown *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    UVar2 = (*local_70->lpVtbl[2].Release)(local_70);
    if ((int)UVar2 < 0) {
      _com_issue_errorex(UVar2,local_70,(_GUID *)&DAT_00a86118);
    }
    local_68[0] = 0;
    This = unaff_EBX;
    if (0 < (int)local_70) {
      do {
        iVar1 = local_68[0];
        _com_issue_error(-0x7fffbffd);
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
        This = (IUnknown *)0x0;
        (**(code **)(_DAT_00000000 + 0x1c))(0);
        unaff_EBX = (IUnknown *)0x0;
        local_68[0] = iVar1 + 1;
        bstrString = local_5c;
      } while (local_68[0] < (int)local_70);
    }
    puStack_10._0_1_ = 3;
    if (unaff_EBX != (IUnknown *)0x0) {
      (*unaff_EBX->lpVtbl->Release)(unaff_EBX);
    }
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    SysFreeString(bstrString);
  }
  ExceptionList = pvStack_18;
  return 0;
}
```
