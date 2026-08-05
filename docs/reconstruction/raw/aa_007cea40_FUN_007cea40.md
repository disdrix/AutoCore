# Raw capture: FUN_007cea40

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cea40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007cea40` |
| **Canonical name** | `FUN_007cea40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007cefed) */
/* WARNING: Removing unreachable block (ram,0x007cef6b) */
/* WARNING: Removing unreachable block (ram,0x007cee96) */
/* WARNING: Removing unreachable block (ram,0x007cee68) */
/* WARNING: Removing unreachable block (ram,0x007cee81) */
/* WARNING: Removing unreachable block (ram,0x007cee9c) */
/* WARNING: Removing unreachable block (ram,0x007ceecb) */
/* WARNING: Removing unreachable block (ram,0x007ceee0) */
/* WARNING: Removing unreachable block (ram,0x007ceee6) */
/* WARNING: Removing unreachable block (ram,0x007cef0f) */
/* WARNING: Removing unreachable block (ram,0x007cef24) */
/* WARNING: Removing unreachable block (ram,0x007cef2a) */
/* WARNING: Removing unreachable block (ram,0x007cef56) */
/* WARNING: Removing unreachable block (ram,0x007cef71) */
/* WARNING: Removing unreachable block (ram,0x007cef9d) */
/* WARNING: Removing unreachable block (ram,0x007cefb2) */
/* WARNING: Removing unreachable block (ram,0x007cefb8) */
/* WARNING: Removing unreachable block (ram,0x007cefd8) */
/* WARNING: Removing unreachable block (ram,0x007ceff3) */
/* WARNING: Removing unreachable block (ram,0x007cf01d) */
/* WARNING: Removing unreachable block (ram,0x007cf032) */
/* WARNING: Removing unreachable block (ram,0x007cf038) */

undefined4 __thiscall FUN_007cea40(char *param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  BSTR bstrString;
  ULONG UVar3;
  int *unaff_EBX;
  int *piVar4;
  int *piStack_7fc;
  IUnknown *local_7f8;
  int local_7f4;
  undefined4 local_7ec;
  undefined4 local_7e8;
  BSTR *local_7e4;
  undefined4 local_7e0;
  int local_7dc;
  undefined4 local_7d8;
  undefined4 *local_7d4;
  undefined4 local_7d0;
  undefined4 local_7cc;
  undefined4 local_7c8;
  undefined4 local_7c4;
  BSTR local_7c0;
  BSTR local_7bc;
  undefined4 local_7b8;
  undefined4 local_7b4;
  wchar_t local_7b0 [34];
  wchar_t local_76c [68];
  wchar_t local_6e4 [33];
  wchar_t local_6a2 [257];
  wchar_t local_4a0 [129];
  wchar_t local_39e [65];
  undefined4 local_31c;
  undefined4 local_318;
  wchar_t local_314 [130];
  wchar_t local_210 [256];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ae8ce;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    uVar1 = 0x80004004;
  }
  else {
    if (DAT_00d1793c == '\0') {
      local_7d4 = &local_7ec;
      local_7ec = 0;
      local_7e8 = 0;
      local_7e4 = (BSTR *)0x0;
      local_7e0 = 0;
      local_7dc = 0;
      local_7d8 = 0;
      local_7cc = 0;
      local_7d0 = 0;
      local_7c8 = 0;
      local_7c4 = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      iVar2 = FUN_0041a810(local_7d4,param_1 + 0x28,0);
      local_7e4 = &local_7c0;
      if ((((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) ||
            (iVar2 = FUN_004231d0(), iVar2 < 0)) ||
           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))) ||
          ((iVar2 = FUN_004231d0(), iVar2 < 0 ||
           ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iVar2 = FUN_004231d0(), iVar2 < 0)))))) ||
         (local_7dc == 0)) {
        FUN_00423170();
        FUN_007a4480();
        local_4 = 0xffffffff;
        FUN_0041a3e0();
      }
      else {
        iVar2 = FUN_0041c000();
        while (iVar2 == 0) {
          wcscpy(local_6e4,local_7b0);
          wcscpy(local_6a2,local_210);
          wcscpy(local_4a0,local_314);
          wcscpy(local_39e,local_76c);
          local_31c = local_7b8;
          local_318 = local_7b4;
          FUN_0041afe0();
          iVar2 = FUN_0041c000();
        }
        iVar2 = 0;
        if (*(int *)(param_3 + 4) != 0) {
          iVar2 = (*(int *)(param_3 + 8) - *(int *)(param_3 + 4)) / 0x3d4;
        }
        *param_2 = iVar2;
        if (local_7dc != 0) {
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
      bstrString = SysAllocString(L"//tAchievement/row");
      local_7bc = bstrString;
      if (bstrString == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_004048e0();
      }
      local_4 = 1;
      FUN_00419ca0();
      local_4._0_1_ = 2;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      local_4._0_1_ = 1;
      FUN_00419ed0();
      local_4 = CONCAT31(local_4._1_3_,4);
      if (local_7f8 == (IUnknown *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      UVar3 = (*local_7f8->lpVtbl[2].Release)(local_7f8);
      if ((int)UVar3 < 0) {
        _com_issue_errorex(UVar3,local_7f8,(_GUID *)&DAT_00a86118);
      }
      FUN_0041af70();
      local_7f4 = 0;
      piVar4 = unaff_EBX;
      if (0 < (int)local_7f8) {
        do {
          if (piStack_7fc == (int *)0x0) {
            _com_issue_error(-0x7fffbffd);
          }
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 8))();
          }
          (**(code **)(*piStack_7fc + 0x1c))();
          unaff_EBX = (int *)0x0;
          local_7f4 = local_7f4 + 1;
          bstrString = local_7c0;
          piVar4 = (int *)0x0;
        } while (local_7f4 < (int)local_7f8);
      }
      puStack_8._0_1_ = 3;
      if (unaff_EBX != (int *)0x0) {
        (**(code **)(*unaff_EBX + 8))();
      }
      puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
      if (piStack_7fc != (int *)0x0) {
        (**(code **)(*piStack_7fc + 8))();
      }
      SysFreeString(bstrString);
    }
    uVar1 = 0;
  }
  ExceptionList = pvStack_10;
  return uVar1;
}
```

---

## Live dual append (2026-07-29 OWN-ONLY)

- Structural dual: load tAchievement rows (elem 0x3d4) via `*[DAT_00b0469c]`; dual backend `DAT_00d1793c`.
- Parent sandwich enter `007e1d80` / load / leave `007b7df0`.
- Dual A/B: `reviews/A_aa_007cea40_DbReader_LoadTAchievementRows_Inferred.md` / `B_aa_*`.
