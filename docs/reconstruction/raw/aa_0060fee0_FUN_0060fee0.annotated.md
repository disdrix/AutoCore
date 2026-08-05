# Annotated low-level: FUN_0060fee0

| Field | Value |
|---|---|
| Stable ID | `aa_0060fee0` |
| VA | `0x0060fee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060fee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0060fee0(int *param_1)

{
  wchar_t **ppwVar1;
  int iVar2;
  wchar_t *pwVar3;
  long lVar4;
  int *unaff_EBX;
  BSTR unaff_EBP;
  int *piVar5;
  int *unaff_EDI;
  int **_Str2;
  int *piVar6;
  wchar_t **ppwStack_50;
  int *piStack_40;
  undefined4 *puStack_3c;
  void *pvStack_2c;
  wchar_t *apwStack_28 [3];
  wchar_t **ppwStack_1c;
  undefined4 local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a8482;
  pvStack_c = ExceptionList;
  puStack_3c = local_14;
  piStack_40 = param_1;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_1 + 0x44))();
  ppwStack_50 = ppwStack_1c;
  FUN_00799820();
  (**(code **)(*param_1 + 0x30))();
  if (unaff_EBX == (int *)0x0) {
    ppwStack_50 = (wchar_t **)0x9e0c44;
    FUN_007a4480(1);
    ExceptionList = ppwStack_1c;
    return;
  }
  ppwStack_50 = apwStack_28;
  piVar6 = unaff_EBX;
  (**(code **)(*unaff_EBX + 0x20))();
  local_14[0] = 0;
  piVar5 = (int *)0x0;
  ppwStack_1c = (wchar_t **)0x1;
  if (0 < (int)unaff_EBX) {
    do {
      _Str2 = &piStack_40;
      (**(code **)(*unaff_EDI + 0x1c))(unaff_EDI,piVar5);
      SysFreeString((BSTR)ppwStack_50);
      ppwStack_50 = (wchar_t **)0x0;
      (**(code **)(*(int *)unaff_EBP + 0x1c))(unaff_EBP,&ppwStack_50);
      iVar2 = _wcsicmp(L"IDs",(wchar_t *)_Str2);
      if (iVar2 == 0) {
        (**(code **)(*piVar6 + 0x68))(piVar6,apwStack_28);
        pwVar3 = wcstok(apwStack_28[0],L"|");
        SysFreeString(apwStack_28[0]);
        ppwVar1 = ppwStack_50;
        apwStack_28[0] = (wchar_t *)0x0;
        while (pwVar3 != (wchar_t *)0x0) {
          puStack_3c = (undefined4 *)_wtoi(pwVar3);
          pwVar3 = ppwVar1[5];
          if ((pwVar3 == (wchar_t *)0x0) ||
             ((uint)((int)ppwVar1[7] - (int)pwVar3 >> 2) <=
              (uint)((int)ppwVar1[6] - (int)pwVar3 >> 2))) {
            FUN_004073a0(ppwVar1[6],1,&puStack_3c);
          }
          else {
            pwVar3 = ppwVar1[6];
            *(undefined4 **)pwVar3 = puStack_3c;
            ppwVar1[6] = pwVar3 + 2;
          }
          pwVar3 = wcstok((wchar_t *)0x0,L"|");
          piVar5 = param_1;
        }
      }
      else {
        iVar2 = _wcsicmp(L"CountNeeded",(wchar_t *)_Str2);
        if (iVar2 == 0) {
          (**(code **)(*piVar6 + 0x68))(piVar6,apwStack_28);
          pwVar3 = (wchar_t *)_wtol(apwStack_28[0]);
          ppwStack_50[8] = pwVar3;
        }
        else {
          iVar2 = _wcsicmp(L"IDsAreMedals",(wchar_t *)_Str2);
          if (iVar2 != 0) goto LAB_00610118;
          (**(code **)(*piVar6 + 0x68))(piVar6,apwStack_28);
          lVar4 = _wtol(apwStack_28[0]);
          *(bool *)(ppwStack_50 + 9) = lVar4 != 0;
        }
        SysFreeString(apwStack_28[0]);
        apwStack_28[0] = (wchar_t *)0x0;
      }
LAB_00610118:
      (**(code **)(*piVar6 + 8))(piVar6);
      piVar5 = (int *)((int)piVar5 + 1);
    } while ((int)piVar5 < (int)unaff_EBX);
  }
  if (((puStack_3c[5] == 0) ||
      (apwStack_28[0] = (wchar_t *)((int)(puStack_3c[6] - puStack_3c[5]) >> 2),
      apwStack_28[0] == (wchar_t *)0x0)) && (puStack_3c[8] == 0)) {
    FUN_007a4480(1,"!!!Mission - mission requirement did not find any IDs\n");
  }
  (**(code **)(*unaff_EDI + 8))(unaff_EDI);
  (**(code **)(*unaff_EBX + 8))(unaff_EBX);
  SysFreeString((BSTR)ppwStack_1c);
  SysFreeString(unaff_EBP);
  ExceptionList = pvStack_2c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
