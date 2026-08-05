# Raw capture: CVOGObjectiveRequirement_UseItem_SerializeXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d800` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0060d800` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_SerializeXml` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall CVOGObjectiveRequirement_UseItem_SerializeXml(int param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  wchar_t *unaff_EBX;
  int *unaff_EBP;
  int *unaff_ESI;
  int *piVar5;
  BSTR *ppOStack_264;
  OLECHAR *bstrString;
  OLECHAR *pOStack_248;
  BSTR bstrString_00;
  int *piStack_238;
  OLECHAR aOStack_234 [10];
  OLECHAR local_220 [46];
  undefined1 *puStack_1c4;
  undefined1 auStack_1c0 [128];
  undefined1 *puStack_140;
  undefined1 auStack_13c [128];
  undefined1 *puStack_bc;
  undefined1 auStack_b8 [136];
  undefined1 uStack_30;
  void *pvStack_1c;
  void *pvStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a83d2;
  pvStack_c = ExceptionList;
  pOStack_248 = local_220;
  ExceptionList = &pvStack_c;
  (**(code **)(*param_2 + 0x44))();
  FUN_00799820();
  (**(code **)(*param_2 + 0x30))();
  if (piStack_238 == (int *)0x0) {
    ppOStack_264 = (BSTR *)0x60d870;
    FUN_007a4480();
  }
  else {
    bstrString = aOStack_234;
    (**(code **)(*piStack_238 + 0x20))();
    pvStack_1c = (void *)0x1;
    bstrString_00 = (BSTR)0x0;
    if (0 < (int)unaff_EBP) {
      do {
        ppOStack_264 = &pOStack_248;
        piVar5 = unaff_ESI;
        (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI,bstrString_00);
        SysFreeString(bstrString);
        bstrString = (OLECHAR *)0x0;
        (**(code **)(*param_2 + 0x1c))(param_2,&stack0xfffffda8);
        iVar1 = _wcsicmp(L"PrimaryCOID",unaff_EBX);
        if (iVar1 == 0) {
          (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
          lVar2 = _wtol((wchar_t *)ppOStack_264);
          *(long *)(param_1 + 0x10) = lVar2;
          *(long *)(param_1 + 0x14) = lVar2 >> 0x1f;
          if (lVar2 == 0) {
            *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
            *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
          }
          SysFreeString((BSTR)ppOStack_264);
          ppOStack_264 = (OLECHAR **)0x0;
        }
        else {
          iVar1 = _wcsicmp(L"PrimaryCBID",unaff_EBX);
          if (iVar1 == 0) {
            (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
            lVar2 = _wtol((wchar_t *)ppOStack_264);
            *(long *)(param_1 + 0x18) = lVar2;
            if (lVar2 == 0) {
              *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
            }
            SysFreeString((BSTR)ppOStack_264);
            ppOStack_264 = (OLECHAR **)0x0;
          }
          else {
            iVar1 = _wcsicmp(L"PrimaryDestroy",unaff_EBX);
            if (iVar1 == 0) {
              (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
              lVar2 = _wtol((wchar_t *)ppOStack_264);
              *(bool *)(param_1 + 0x1c) = lVar2 == 1;
              SysFreeString((BSTR)ppOStack_264);
              ppOStack_264 = (OLECHAR **)0x0;
            }
            else {
              iVar1 = _wcsicmp(L"PrimaryInWorld",unaff_EBX);
              if (iVar1 == 0) {
                (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                lVar2 = _wtol((wchar_t *)ppOStack_264);
                *(bool *)(param_1 + 0x1d) = lVar2 == 1;
                SysFreeString((BSTR)ppOStack_264);
                ppOStack_264 = (OLECHAR **)0x0;
              }
              else {
                iVar1 = _wcsicmp(L"PrimaryUseText",unaff_EBX);
                if (iVar1 == 0) {
                  (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                  uVar3 = (*(code *)PTR_FUN_00af8c9c)();
                  FUN_00403450(piVar5,uVar3);
                  uStack_30 = 2;
                  FUN_0060d2e0(pOStack_248);
                  uStack_30 = 1;
                  if (pOStack_248 != (OLECHAR *)&stack0xfffffdbc) {
                    free(pOStack_248);
                  }
                  SysFreeString((BSTR)ppOStack_264);
                  ppOStack_264 = (OLECHAR **)0x0;
                }
                else {
                  iVar1 = _wcsicmp(L"PrimaryGiveAtStart",unaff_EBX);
                  if (iVar1 == 0) {
                    (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                    lVar2 = _wtol((wchar_t *)ppOStack_264);
                    *(bool *)(param_1 + 0x24) = lVar2 == 1;
                    SysFreeString((BSTR)ppOStack_264);
                    ppOStack_264 = (OLECHAR **)0x0;
                  }
                  else {
                    iVar1 = _wcsicmp(L"PrimaryMultipleUse",unaff_EBX);
                    if (iVar1 == 0) {
                      (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                      lVar2 = _wtol((wchar_t *)ppOStack_264);
                      *(bool *)(param_1 + 0x25) = lVar2 == 1;
                    }
                    else {
                      iVar1 = _wcsicmp(L"PrimaryExplode",unaff_EBX);
                      if (iVar1 == 0) {
                        (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                        lVar2 = _wtol((wchar_t *)ppOStack_264);
                        *(bool *)(param_1 + 0x26) = lVar2 == 1;
                      }
                      else {
                        iVar1 = _wcsicmp(L"PrimaryCompletedItem",unaff_EBX);
                        if (iVar1 == 0) {
                          (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                          lVar2 = _wtol((wchar_t *)ppOStack_264);
                          *(long *)(param_1 + 0x28) = lVar2;
                        }
                        else {
                          iVar1 = _wcsicmp(L"SecondaryCBID",unaff_EBX);
                          if (iVar1 == 0) {
                            (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                            lVar2 = _wtol((wchar_t *)ppOStack_264);
                            *(long *)(param_1 + 0x2c) = lVar2;
                          }
                          else {
                            iVar1 = _wcsicmp(L"SecondaryDestroy",unaff_EBX);
                            if (iVar1 == 0) {
                              (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                              lVar2 = _wtol((wchar_t *)ppOStack_264);
                              *(bool *)(param_1 + 0x30) = lVar2 == 1;
                            }
                            else {
                              iVar1 = _wcsicmp(L"SecondaryGiveAtStart",unaff_EBX);
                              if (iVar1 == 0) {
                                (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                                lVar2 = _wtol((wchar_t *)ppOStack_264);
                                *(bool *)(param_1 + 0x31) = lVar2 == 1;
                              }
                              else {
                                iVar1 = _wcsicmp(L"SecondaryMultipleUse",unaff_EBX);
                                if (iVar1 == 0) {
                                  (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                                  lVar2 = _wtol((wchar_t *)ppOStack_264);
                                  *(bool *)(param_1 + 0x32) = lVar2 == 1;
                                }
                                else {
                                  iVar1 = _wcsicmp(L"ProgressTime",unaff_EBX);
                                  if (iVar1 == 0) {
                                    (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                                    lVar2 = _wtol((wchar_t *)ppOStack_264);
                                    *(long *)(param_1 + 0x34) = lVar2;
                                  }
                                  else {
                                    iVar1 = _wcsicmp(L"ProgressText",unaff_EBX);
                                    if (iVar1 == 0) {
                                      (**(code **)(*piStack_238 + 0x68))(piStack_238,&ppOStack_264);
                                      puVar4 = (undefined4 *)FUN_00402d50(ppOStack_264);
                                      uStack_30 = 3;
                                      FUN_0060d340(*puVar4);
                                      uStack_30 = 1;
                                      if (puStack_1c4 != auStack_1c0) {
                                        free(puStack_1c4);
                                      }
                                    }
                                    else {
                                      iVar1 = _wcsicmp(L"ProgressInterruptable",unaff_EBX);
                                      if (iVar1 == 0) {
                                        (**(code **)(*piStack_238 + 0x68))
                                                  (piStack_238,&ppOStack_264);
                                        lVar2 = _wtol((wchar_t *)ppOStack_264);
                                        *(bool *)(param_1 + 0x3c) = lVar2 == 1;
                                      }
                                      else {
                                        iVar1 = _wcsicmp(L"ProgressInterruptText",unaff_EBX);
                                        if (iVar1 == 0) {
                                          (**(code **)(*piStack_238 + 0x68))
                                                    (piStack_238,&ppOStack_264);
                                          puVar4 = (undefined4 *)FUN_00402d50(ppOStack_264);
                                          uStack_30 = 4;
                                          FUN_0060d3a0(*puVar4);
                                          uStack_30 = 1;
                                          if (puStack_140 != auStack_13c) {
                                            free(puStack_140);
                                          }
                                        }
                                        else {
                                          iVar1 = _wcsicmp(L"CompleteText",unaff_EBX);
                                          if (iVar1 == 0) {
                                            (**(code **)(*piStack_238 + 0x68))
                                                      (piStack_238,&ppOStack_264);
                                            puVar4 = (undefined4 *)FUN_00402d50(ppOStack_264);
                                            uStack_30 = 5;
                                            FUN_0060d400(*puVar4);
                                            uStack_30 = 1;
                                            if (puStack_bc != auStack_b8) {
                                              free(puStack_bc);
                                            }
                                          }
                                          else {
                                            iVar1 = _wcsicmp(L"CompleteItem",unaff_EBX);
                                            if (iVar1 == 0) {
                                              (**(code **)(*piStack_238 + 0x68))
                                                        (piStack_238,&ppOStack_264);
                                              lVar2 = _wtol((wchar_t *)ppOStack_264);
                                              *(long *)(param_1 + 0x48) = lVar2;
                                            }
                                            else {
                                              iVar1 = _wcsicmp(L"CompletedMission",unaff_EBX);
                                              if (iVar1 == 0) {
                                                (**(code **)(*piStack_238 + 0x68))
                                                          (piStack_238,&ppOStack_264);
                                                lVar2 = _wtol((wchar_t *)ppOStack_264);
                                                *(long *)(param_1 + 0x4c) = lVar2;
                                              }
                                              else {
                                                iVar1 = _wcsicmp(L"RepeatCount",unaff_EBX);
                                                if (iVar1 == 0) {
                                                  (**(code **)(*piStack_238 + 0x68))
                                                            (piStack_238,&ppOStack_264);
                                                  lVar2 = _wtol((wchar_t *)ppOStack_264);
                                                  *(long *)(param_1 + 0x50) = lVar2;
                                                }
                                                else {
                                                  iVar1 = _wcsicmp(L"ContinentID",unaff_EBX);
                                                  if (iVar1 != 0) goto LAB_0060def2;
                                                  (**(code **)(*piStack_238 + 0x68))
                                                            (piStack_238,&ppOStack_264);
                                                  lVar2 = _wtol((wchar_t *)ppOStack_264);
                                                  *(long *)(param_1 + 0x54) = lVar2;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    FUN_0040d230();
                  }
                }
              }
            }
          }
        }
LAB_0060def2:
        (**(code **)(*piStack_238 + 8))(piStack_238);
        bstrString_00 = (BSTR)((int)bstrString_00 + 1);
      } while ((int)bstrString_00 < (int)unaff_EBP);
    }
    ppOStack_264 = (BSTR *)0x60df1e;
    (**(code **)(*unaff_ESI + 8))();
    (**(code **)(*unaff_EBP + 8))();
    if (*(int *)(param_1 + 0x20) == 0) {
      FUN_0060d2e0();
    }
    SysFreeString(pOStack_248);
    SysFreeString(bstrString_00);
  }
  ExceptionList = pvStack_1c;
  return;
}
```
