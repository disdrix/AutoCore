# Annotated low-level: FUN_008f8de0

| Field | Value |
|---|---|
| Stable ID | `aa_008f8de0` |
| VA | `0x008f8de0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008f8de0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f8de0(int *param_1,int param_2)

{
  int iVar1;
  int unaff_EBX;
  BSTR unaff_EBP;
  int local_18;
  void *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ba925;
  local_c = ExceptionList;
  local_18 = 0;
  local_4 = 0;
  local_14 = (void *)0x0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    ExceptionList = &local_c;
    (**(code **)(*param_1 + 0x1c))(param_1,&local_18);
    iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_TOP",unaff_EBP);
    if (iVar1 == 0) {
      SysFreeString(unaff_EBP);
      unaff_EBP = (BSTR)0x0;
      (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
      iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffe4,0);
      if (iVar1 == 2) {
        _DAT_00000000 = _DAT_00000000 - unaff_EBX;
      }
      *(int *)(local_18 + 0x510) = unaff_EBX;
    }
    else {
      iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_MIDDLE",unaff_EBP);
      if (iVar1 == 0) {
        SysFreeString(unaff_EBP);
        unaff_EBP = (BSTR)0x0;
        (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffe4,0);
        if (iVar1 == 2) {
          _DAT_00000000 = _DAT_00000000 - unaff_EBX;
        }
        *(int *)(local_18 + 0x514) = unaff_EBX;
      }
      else {
        iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_BOTTOM",unaff_EBP);
        if (iVar1 == 0) {
          FUN_0040d230();
          (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
          iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);
          if (iVar1 == 2) {
            _DAT_00000000 = _DAT_00000000 - unaff_EBX;
          }
          *(int *)(local_18 + 0x518) = unaff_EBX;
        }
        else {
          iVar1 = _wcsicmp(L"CHAT_RECT_BUFFER",unaff_EBP);
          if (iVar1 == 0) {
            FUN_0040d230();
            (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
            iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);
            if (iVar1 == 2) {
              _DAT_00000000 = _DAT_00000000 - unaff_EBX;
            }
            *(int *)(local_18 + 0x51c) = unaff_EBX;
          }
          else {
            iVar1 = _wcsicmp(L"DIVIDER_LIMIT_TOP",unaff_EBP);
            if (iVar1 == 0) {
              FUN_0040d230();
              (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
              iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);
              if (iVar1 == 2) {
                _DAT_00000000 = _DAT_00000000 - unaff_EBX;
              }
              *(int *)(local_18 + 0x520) = unaff_EBX;
            }
            else {
              iVar1 = _wcsicmp(L"DIVIDER_LIMIT_BOTTOM",unaff_EBP);
              if (iVar1 == 0) {
                FUN_0040d230();
                (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
                iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);
                if (iVar1 == 2) {
                  _DAT_00000000 = _DAT_00000000 - unaff_EBX;
                }
                *(int *)(local_18 + 0x524) = unaff_EBX;
              }
              else {
                iVar1 = _wcsicmp(L"DIVIDER_DEFAULT_OFFSET",unaff_EBP);
                if (iVar1 == 0) {
                  FUN_0040d230();
                  (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);
                  iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);
                  if (iVar1 == 2) {
                    _DAT_00000000 = _DAT_00000000 - unaff_EBX;
                  }
                  *(int *)(local_18 + 0x528) = unaff_EBX;
                }
                else {
                  FUN_007933a0(param_1,param_2);
                }
              }
            }
          }
        }
      }
    }
    local_c = (void *)0xffffffff;
    SysFreeString(unaff_EBP);
    ExceptionList = local_14;
    return;
  }
  local_4 = 0xffffffff;
  ExceptionList = &local_c;
  SysFreeString((BSTR)0x0);
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
