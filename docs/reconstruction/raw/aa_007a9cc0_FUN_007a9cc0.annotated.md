# Annotated low-level: FUN_007a9cc0

| Field | Value |
|---|---|
| Stable ID | `aa_007a9cc0` |
| VA | `0x007a9cc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a9cc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a9cc0(undefined4 param_1,int *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  int *unaff_EBX;
  int *unaff_ESI;
  BSTR unaff_retaddr;
  int **ppiStack_44;
  int *piStack_2c;
  BSTR *ppOStack_28;
  void *pvStack_20;
  wchar_t *apwStack_1c [2];
  BSTR local_14 [2];
  BSTR pOStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009aba4d;
  pOStack_c = ExceptionList;
  ppOStack_28 = local_14;
  local_4 = 0;
  piStack_2c = param_2;
  ExceptionList = &pOStack_c;
  (**(code **)(*param_2 + 0x30))();
  pwVar1 = apwStack_1c[0];
  if (apwStack_1c[0] == (wchar_t *)0x0) {
    SysFreeString(unaff_retaddr);
    ExceptionList = local_14[0];
    return;
  }
  (**(code **)(*(int *)apwStack_1c[0] + 0x20))();
  ppOStack_28 = (BSTR *)0x0;
  if (0 < (int)pvStack_20) {
    do {
      ppiStack_44 = &piStack_2c;
      (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,ppOStack_28);
      SysFreeString(local_14[0]);
      local_14[0] = (BSTR)0x0;
      (**(code **)(*(int *)pwVar1 + 0x1c))(pwVar1,local_14);
      if (*apwStack_1c[0] != L'#') {
        iVar2 = wcscmp(apwStack_1c[0],L"X");
        if (iVar2 == 0) {
LAB_007a9d90:
          SysFreeString(apwStack_1c[0]);
          apwStack_1c[0] = (wchar_t *)0x0;
          (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
          iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
          if (iVar2 == 2) {
            _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
          }
          *(int ***)((int)pvStack_20 + 0x1a0) = ppiStack_44;
        }
        else {
          iVar2 = wcscmp(apwStack_1c[0],L"Y");
          if (iVar2 == 0) {
            SysFreeString(apwStack_1c[0]);
            apwStack_1c[0] = (wchar_t *)0x0;
LAB_007a9e05:
            (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
            iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
            if (iVar2 == 2) {
              _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
            }
            *(int ***)((int)pvStack_20 + 0x1a4) = ppiStack_44;
          }
          else {
            iVar2 = wcscmp(apwStack_1c[0],L"WIDTH");
            if (iVar2 == 0) {
              SysFreeString(apwStack_1c[0]);
              apwStack_1c[0] = (wchar_t *)0x0;
              (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
              iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
              if (iVar2 == 2) {
                _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
              }
              *(int *)((int)pvStack_20 + 0x1a8) =
                   *(int *)((int)pvStack_20 + 0x1a0) + (int)ppiStack_44;
            }
            else {
              iVar2 = wcscmp(apwStack_1c[0],L"HEIGHT");
              if (iVar2 == 0) {
                SysFreeString(apwStack_1c[0]);
                apwStack_1c[0] = (wchar_t *)0x0;
                (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
                iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
                if (iVar2 == 2) {
                  _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
                }
                *(int *)((int)pvStack_20 + 0x1ac) =
                     *(int *)((int)pvStack_20 + 0x1a4) + (int)ppiStack_44;
              }
              else {
                iVar2 = wcscmp(apwStack_1c[0],L"LEFT");
                if (iVar2 == 0) goto LAB_007a9d90;
                iVar2 = wcscmp(apwStack_1c[0],L"RIGHT");
                if (iVar2 == 0) {
                  FUN_0040d230();
                  (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
                  iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
                  if (iVar2 == 2) {
                    _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
                  }
                  *(int ***)((int)pvStack_20 + 0x1a8) = ppiStack_44;
                }
                else {
                  iVar2 = wcscmp(apwStack_1c[0],L"TOP");
                  if (iVar2 == 0) {
                    FUN_0040d230();
                    goto LAB_007a9e05;
                  }
                  iVar2 = wcscmp(apwStack_1c[0],L"BOTTOM");
                  if (iVar2 == 0) {
                    FUN_0040d230();
                    (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
                    iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
                    if (iVar2 == 2) {
                      _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
                    }
                    *(int ***)((int)pvStack_20 + 0x1ac) = ppiStack_44;
                  }
                  else {
                    iVar2 = wcscmp(apwStack_1c[0],L"START_X");
                    if (iVar2 == 0) {
                      FUN_0040d230();
                      (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
                      iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
                      if (iVar2 == 2) {
                        _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
                      }
                      *(int ***)((int)pvStack_20 + 0x158) = ppiStack_44;
                    }
                    else {
                      iVar2 = wcscmp(apwStack_1c[0],L"START_Y");
                      if (iVar2 == 0) {
                        FUN_0040d230();
                        (**(code **)(*unaff_ESI + 0x68))(unaff_ESI,apwStack_1c);
                        iVar2 = swscanf(apwStack_1c[0],L"%d;%d",&ppiStack_44,0);
                        if (iVar2 == 2) {
                          _DAT_00000000 = _DAT_00000000 - (int)ppiStack_44;
                        }
                        *(int ***)((int)pvStack_20 + 0x15c) = ppiStack_44;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      (**(code **)(*unaff_ESI + 8))(unaff_ESI);
      ppOStack_28 = (BSTR *)((int)ppOStack_28 + 1);
    } while ((int)ppOStack_28 < (int)pvStack_20);
  }
  (**(code **)(*unaff_EBX + 8))();
  ppiStack_44 = (int **)0x7aa133;
  SysFreeString(pOStack_c);
  ExceptionList = pvStack_20;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
