# Raw capture: FUN_008ac8b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac8b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ac8b0` |
| **Canonical name** | `FUN_008ac8b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x008acc24) */
/* WARNING: Removing unreachable block (ram,0x008acc3b) */
/* WARNING: Removing unreachable block (ram,0x008acc40) */
/* WARNING: Removing unreachable block (ram,0x008acc91) */
/* WARNING: Removing unreachable block (ram,0x008acca4) */
/* WARNING: Removing unreachable block (ram,0x008accba) */
/* WARNING: Removing unreachable block (ram,0x008acccd) */
/* WARNING: Removing unreachable block (ram,0x008acc7b) */
/* WARNING: Removing unreachable block (ram,0x008acce1) */
/* WARNING: Removing unreachable block (ram,0x008acce6) */
/* WARNING: Removing unreachable block (ram,0x008accfd) */
/* WARNING: Removing unreachable block (ram,0x008ace67) */
/* WARNING: Removing unreachable block (ram,0x008ace7e) */
/* WARNING: Removing unreachable block (ram,0x008ace80) */
/* WARNING: Removing unreachable block (ram,0x008aced1) */
/* WARNING: Removing unreachable block (ram,0x008acee4) */
/* WARNING: Removing unreachable block (ram,0x008acefa) */
/* WARNING: Removing unreachable block (ram,0x008acf0d) */
/* WARNING: Removing unreachable block (ram,0x008acebb) */
/* WARNING: Removing unreachable block (ram,0x008acf21) */
/* WARNING: Removing unreachable block (ram,0x008acf26) */
/* WARNING: Removing unreachable block (ram,0x008acf3d) */
/* WARNING: Removing unreachable block (ram,0x008acd47) */
/* WARNING: Removing unreachable block (ram,0x008acd5e) */
/* WARNING: Removing unreachable block (ram,0x008acd60) */
/* WARNING: Removing unreachable block (ram,0x008acdb1) */
/* WARNING: Removing unreachable block (ram,0x008acdc4) */
/* WARNING: Removing unreachable block (ram,0x008acdda) */
/* WARNING: Removing unreachable block (ram,0x008acded) */
/* WARNING: Removing unreachable block (ram,0x008acd9b) */
/* WARNING: Removing unreachable block (ram,0x008ace01) */
/* WARNING: Removing unreachable block (ram,0x008ace06) */
/* WARNING: Removing unreachable block (ram,0x008ace1d) */
/* WARNING: Removing unreachable block (ram,0x008ac959) */
/* WARNING: Removing unreachable block (ram,0x008ac970) */
/* WARNING: Removing unreachable block (ram,0x008ac9ca) */
/* WARNING: Removing unreachable block (ram,0x008ac9dd) */
/* WARNING: Removing unreachable block (ram,0x008ac9eb) */
/* WARNING: Removing unreachable block (ram,0x008ac9fe) */
/* WARNING: Removing unreachable block (ram,0x008aca14) */
/* WARNING: Removing unreachable block (ram,0x008aca27) */
/* WARNING: Removing unreachable block (ram,0x008aca3d) */
/* WARNING: Removing unreachable block (ram,0x008aca50) */
/* WARNING: Removing unreachable block (ram,0x008aca5c) */
/* WARNING: Removing unreachable block (ram,0x008ac9b1) */
/* WARNING: Removing unreachable block (ram,0x008aca64) */
/* WARNING: Removing unreachable block (ram,0x008aca69) */
/* WARNING: Removing unreachable block (ram,0x008aca80) */
/* WARNING: Removing unreachable block (ram,0x008acf87) */
/* WARNING: Removing unreachable block (ram,0x008acf9e) */
/* WARNING: Removing unreachable block (ram,0x008acfa0) */
/* WARNING: Removing unreachable block (ram,0x008acff1) */
/* WARNING: Removing unreachable block (ram,0x008ad004) */
/* WARNING: Removing unreachable block (ram,0x008ad01a) */
/* WARNING: Removing unreachable block (ram,0x008ad02d) */
/* WARNING: Removing unreachable block (ram,0x008acfdb) */
/* WARNING: Removing unreachable block (ram,0x008ad041) */
/* WARNING: Removing unreachable block (ram,0x008ad046) */
/* WARNING: Removing unreachable block (ram,0x008ad05d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_008ac8b0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  BSTR unaff_ESI;
  int iStack_18;
  void *pvStack_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b99a5;
  local_c = ExceptionList;
  local_4 = 0;
  local_10 = 0;
  if ((param_2 != (int *)0x0) && (param_3 != 0)) {
    ExceptionList = &local_c;
    (**(code **)(*param_2 + 0x1c))();
    iVar1 = wcscmp(L"RESPONSE_WINDOW",unaff_ESI);
    if (iVar1 == 0) {
      (**(code **)(*param_2 + 0x30))(param_2);
    }
    else {
      iVar1 = wcscmp(L"NUM_RESPONSES",unaff_ESI);
      if (iVar1 == 0) {
        SysFreeString(unaff_ESI);
        (**(code **)(*param_2 + 0x68))(param_2);
        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&iStack_18);
        if (iVar1 == 2) {
          _DAT_00000000 = _DAT_00000000 - iStack_18;
        }
        FUN_008ac890();
        unaff_ESI = (BSTR)0x0;
      }
      else {
        iVar1 = wcscmp(L"NUM_ITEM_COLUMNS",unaff_ESI);
        if (iVar1 == 0) {
          FUN_0040d230();
          (**(code **)(*param_2 + 0x68))(param_2);
          iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);
          if (iVar1 == 2) {
            _DAT_00000000 = _DAT_00000000 - iStack_18;
          }
          *(int *)(param_1 + 0x63c) = iStack_18;
        }
        else {
          iVar1 = wcscmp(L"NUM_RESPONSE_COLUMNS",unaff_ESI);
          if (iVar1 == 0) {
            FUN_0040d230();
            (**(code **)(*param_2 + 0x68))(param_2);
            iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);
            if (iVar1 == 2) {
              _DAT_00000000 = _DAT_00000000 - iStack_18;
            }
            *(int *)(param_1 + 0x640) = iStack_18;
          }
          else {
            iVar1 = wcscmp(L"ITEM_BTN",unaff_ESI);
            if (iVar1 == 0) {
              (**(code **)(*param_2 + 0x30))(param_2);
            }
            else {
              iVar1 = wcscmp(L"ITEM_WINDOW",unaff_ESI);
              if (iVar1 == 0) {
                (**(code **)(*param_2 + 0x30))(param_2);
              }
              else {
                iVar1 = wcscmp(L"ITEM_WINDOW_BG",unaff_ESI);
                if (iVar1 == 0) {
                  (**(code **)(*param_2 + 0x30))(param_2);
                }
                else {
                  iVar1 = wcscmp(L"ITEM_TEXT",unaff_ESI);
                  if (iVar1 == 0) {
                    (**(code **)(*param_2 + 0x30))(param_2);
                  }
                  else {
                    FUN_007933a0(param_2);
                  }
                }
              }
            }
          }
        }
      }
    }
    local_c = (void *)0xffffffff;
    SysFreeString(unaff_ESI);
    ExceptionList = pvStack_14;
    return;
  }
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  SysFreeString((BSTR)0x0);
  ExceptionList = local_c;
  return;
}
```
