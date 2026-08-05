# Raw capture: NDUIWindow_ApplyXmlNodeAttributes

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b1ec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b1ec0` |
| **Canonical name** | `NDUIWindow_ApplyXmlNodeAttributes` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* NDUIWindow_ApplyXmlNodeAttributes
   
   Walk MSXML attribute list on a window node. Handles NAME, WINDOW_ID, GAME_ID,
   INCLUDE (recursive load), TOOLTIP, TEXT_ALIGN, TEXT_FONT, MOVEABLE, STICKY, etc.
   INCLUDE calls virtual +0x3a4 to load nested interface files. */

void __thiscall
NDUIWindow_ApplyXmlNodeAttributes(int *param_1,BSTR param_2,char *param_3,int param_4)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  BSTR pOVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int *unaff_ESI;
  code *pcVar9;
  BSTR *ppOVar10;
  wchar_t *_Str1;
  undefined4 uStack_178;
  BSTR *ppOStack_174;
  BSTR pOStack_170;
  OLECHAR *bstrString;
  BSTR local_158 [2];
  int iStack_150;
  int *piStack_14c;
  undefined1 auStack_148 [3];
  undefined1 local_145;
  int *piStack_144;
  BSTR *ppOStack_140;
  BSTR pOStack_13c;
  BSTR apOStack_138 [2];
  OLECHAR aOStack_130 [2];
  int local_12c;
  BSTR pOStack_128;
  BSTR apOStack_11c [28];
  undefined1 *puStack_ac;
  undefined1 auStack_a8 [120];
  undefined1 uStack_30;
  undefined1 uStack_28;
  uint uStack_20;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009b1cff;
  pvStack_c = ExceptionList;
  local_158[0] = (BSTR)0x0;
  local_4 = 0;
  local_145 = 0;
  ExceptionList = &pvStack_c;
  if (param_4 == 0) {
    ExceptionList = &pvStack_c;
    if ((void *)param_1[0x9d] != (void *)0x0) {
      pOStack_170 = L"쒃謄粆\x02㬀觃璞\x02琀倉\xede8쵸菿ӄ蚋ʀ";
      ExceptionList = &pvStack_c;
      operator_delete__((void *)param_1[0x9d]);
    }
    param_1[0x9d] = 0;
    if ((void *)param_1[0x9f] != (void *)0x0) {
      pOStack_170 = L"쒃謄肆\x02㬀觃粞\x02琀倉퓨쵸菿ӄ蚋ʈ";
      operator_delete__((void *)param_1[0x9f]);
    }
    param_1[0x9f] = 0;
    if ((void *)param_1[0xa0] != (void *)0x0) {
      pOStack_170 = L"쒃謄袆\x02㬀觃肞\x02琀倉믨쵸菿ӄ쀳줳꺍Ơ";
      operator_delete__((void *)param_1[0xa0]);
    }
    param_1[0xa0] = 0;
    if ((void *)param_1[0xa2] != (void *)0x0) {
      pOStack_170 = L"쒃㌄㏀跉ꂮ\x01褀E䶉㌄角ࡕ麉ʈ";
      operator_delete__((void *)param_1[0xa2]);
    }
    param_1[0x68] = 0;
    param_1[0x69] = 0;
    param_1[0x6a] = 0;
    param_1[0xa2] = 0;
    *(undefined1 *)((int)param_1 + 0xd6) = 0;
    param_1[0x54] = 0;
    param_1[0x55] = 0;
    param_1[0x6b] = 0;
    param_1[0x6c] = 0;
    param_1[0x6d] = 0;
    *(undefined1 *)((int)param_1 + 0x1c9) = 0;
    *(undefined1 *)((int)param_1 + 0x1ca) = 0;
    param_1[0x70] = DAT_00d1e818;
    param_1[0x71] = DAT_00d1e81c;
    piVar6 = param_1 + 0x117;
    iVar8 = 0xb;
    do {
      if ((void *)*piVar6 != (void *)0x0) {
        pOStack_170 = (BSTR)0x7b1fdc;
        operator_delete__((void *)*piVar6);
      }
      *piVar6 = 0;
      piVar6 = piVar6 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    param_1[0x75] = 0;
    param_1[0x73] = 0;
    fVar1 = g_flOne;
    *(undefined1 *)(param_1 + 0x72) = 0;
    param_1[0x76] = (int)fVar1;
    param_1[0x74] = (int)fVar1;
  }
  if (param_2 == (BSTR)0x0) {
LAB_007b2f5b:
    if (param_4 == 0) {
      (**(code **)(*param_1 + 0x10c))();
      pOStack_170 = (BSTR)0x1;
      ppOStack_174 = apOStack_11c;
      uStack_178 = L"鰹瀤\x01謀褐梖\x01謀р蚉Ŭ";
      piVar6 = (int *)(**(code **)(*param_1 + 0x120))();
      param_1[0x5a] = *piVar6;
      param_1[0x5b] = piVar6[1];
      if (param_3 != (char *)0x0) {
        pcVar7 = param_3;
        do {
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        if ((void *)param_1[0xa1] != (void *)0x0) {
          pOStack_170 = L"쒃茄Ǉ襗蒞\x02\xe800校ￍ貋琤\x01茀ӄ蚉ʄ";
          operator_delete__((void *)param_1[0xa1]);
        }
        param_1[0xa1] = 0;
        pOStack_170 = L"貋琤\x01茀ӄ蚉ʄ";
        pcVar7 = operator_new__((uint)(pcVar7 + (1 - (int)(param_3 + 1))));
        param_1[0xa1] = (int)pcVar7;
        do {
          cVar2 = *param_3;
          *pcVar7 = cVar2;
          param_3 = param_3 + 1;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
      }
    }
  }
  else {
    pOStack_170 = param_2;
    local_12c = 0;
    ppOStack_174 = (BSTR *)0x7b2039;
    iVar8 = (**(code **)(*(int *)param_2 + 0x44))();
    if ((iVar8 == 0) && (local_12c != 0)) {
      pOStack_170 = param_2;
      apOStack_138[0] = (BSTR)0x0;
      ppOStack_174 = (BSTR *)0x7b205b;
      (**(code **)(*(int *)param_2 + 0x30))();
      if (apOStack_138[0] != (BSTR)0x0) {
        bstrString = aOStack_130;
        pOStack_170 = apOStack_138[0];
        ppOStack_174 = (BSTR *)0x7b2092;
        (**(code **)(*(int *)apOStack_138[0] + 0x20))();
        pOStack_128 = (BSTR)0x0;
        pcVar9 = swscanf_exref;
        if (0 < (int)apOStack_138[0]) {
          do {
            ppOVar10 = ppOStack_140;
            ppOStack_174 = local_158;
            uStack_178 = pOStack_128;
            (**(code **)(*ppOStack_140 + 0xe))();
            SysFreeString(bstrString);
            _Str1 = (wchar_t *)&stack0xfffffe94;
            bstrString = (OLECHAR *)0x0;
            (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI);
            if (ppOStack_174 == (BSTR *)0x0) {
              (**(code **)(*(int *)bstrString + 8))(bstrString);
            }
            else {
              if (*(short *)ppOStack_174 != 0x23) {
                iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TOOLTIP");
                if (iVar8 == 0) {
                  SysFreeString((BSTR)ppOStack_174);
                  ppOStack_174 = (BSTR *)0x0;
                  (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                  FUN_007ab0f0(&ppOStack_174);
                }
                else {
                  iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TOOLTIP_STYLE");
                  if (iVar8 == 0) {
                    SysFreeString((BSTR)ppOStack_174);
                    ppOStack_174 = (BSTR *)0x0;
                    iStack_150 = 0;
                    (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                    iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",local_158,0);
                    if (iVar8 == 2) {
                      _DAT_00000000 = (float)((int)_DAT_00000000 - iStack_150);
                    }
                    param_1[0x48] = iStack_150;
                  }
                  else {
                    iVar3 = wcscmp((wchar_t *)ppOStack_174,L"INCLUDE");
                    iVar8 = DAT_00d1794c;
                    if (iVar3 == 0) {
                      FUN_0040d230();
                      (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                      puVar4 = (undefined4 *)FUN_00402d50(ppOVar10);
                      uStack_28 = 1;
                      (**(code **)(*param_1 + 0x3a4))(*puVar4,uStack_20);
                      uStack_30 = 0;
                      if (ppOStack_140 != &pOStack_13c) {
                        free(ppOStack_140);
                      }
                      (**(code **)(*unaff_ESI + 0x20))(unaff_ESI,&stack0xfffffea4);
                      pcVar9 = swscanf_exref;
                      DAT_00d1794c = iVar8;
                    }
                    else {
                      iVar8 = wcscmp((wchar_t *)ppOStack_174,L"NAME");
                      if (iVar8 == 0) {
                        FUN_0040d230();
                        (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                        puVar4 = (undefined4 *)FUN_00402d50(ppOVar10);
                        uStack_28 = 2;
                        (**(code **)(*param_1 + 0x6c))(*puVar4);
                        uStack_20 = uStack_20 & 0xffffff00;
                        if (puStack_ac != auStack_a8) {
                          free(puStack_ac);
                        }
                      }
                      else {
                        iVar8 = wcscmp((wchar_t *)ppOStack_174,L"WINDOW_ID");
                        if (iVar8 == 0) {
                          pOStack_170 = (BSTR)0x0;
                          FUN_0040d230();
                          (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                          iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,0);
                          if (iVar8 == 2) {
                            _DAT_00000000 = (float)((int)_DAT_00000000 - (int)uStack_178);
                          }
                          (**(code **)(*param_1 + 0x74))(uStack_178);
                        }
                        else {
                          iVar8 = wcscmp((wchar_t *)ppOStack_174,L"GAME_ID");
                          if (iVar8 == 0) {
                            pOStack_170 = (BSTR)0x0;
                            FUN_0040d230();
                            (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                            iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,0);
                            if (iVar8 == 2) {
                              _DAT_00000000 = (float)((int)_DAT_00000000 - (int)uStack_178);
                            }
                            (**(code **)(*param_1 + 0x7c))(uStack_178);
                          }
                          else {
                            iVar8 = wcscmp((wchar_t *)ppOStack_174,L"IGNORES_MOUSE");
                            if (iVar8 == 0) {
                              FUN_0040d230();
                              (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                              iVar8 = wcscmp((wchar_t *)ppOVar10,L"true");
                              if (iVar8 == 0) {
                                (**(code **)(*param_1 + 0x300))(1);
                              }
                              else {
                                (**(code **)(*param_1 + 0x300))(0);
                              }
                            }
                            else {
                              iVar8 = wcscmp((wchar_t *)ppOStack_174,L"WORD_WRAP");
                              if (iVar8 == 0) {
                                FUN_0040d230();
                                (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174);
                                iVar8 = wcscmp((wchar_t *)ppOVar10,L"true");
                                if (iVar8 == 0) {
                                  (**(code **)(*param_1 + 0x1c4))(1);
                                }
                                else {
                                  (**(code **)(*param_1 + 0x1c4))(0);
                                }
                              }
                              else {
                                iVar8 = wcscmp((wchar_t *)ppOStack_174,L"MOVEABLE");
                                if (iVar8 == 0) {
                                  FUN_0040d230();
                                  (**(code **)(*(int *)bstrString + 0x68))(bstrString,&ppOStack_174)
                                  ;
                                  iVar8 = wcscmp((wchar_t *)ppOStack_174,L"true");
                                  *(bool *)((int)param_1 + 0xc5) = iVar8 == 0;
                                }
                                else {
                                  iVar8 = wcscmp((wchar_t *)ppOStack_174,L"CAN_BE_MOVEABLE");
                                  if (iVar8 == 0) {
                                    FUN_0040d230();
                                    (**(code **)(*(int *)bstrString + 0x68))
                                              (bstrString,&ppOStack_174);
                                    iVar8 = wcscmp((wchar_t *)ppOStack_174,L"true");
                                    *(bool *)((int)param_1 + 0xc6) = iVar8 == 0;
                                  }
                                  else {
                                    iVar8 = wcscmp((wchar_t *)ppOStack_174,L"STICKY");
                                    if (iVar8 == 0) {
                                      FUN_0040d230();
                                      (**(code **)(*(int *)bstrString + 0x68))
                                                (bstrString,&ppOStack_174);
                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,L"true");
                                      *(bool *)(param_1 + 0x31) = iVar8 == 0;
                                    }
                                    else {
                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,L"HYPERLINK_ROLLOVERS")
                                      ;
                                      if (iVar8 == 0) {
                                        FUN_0040d230();
                                        (**(code **)(*(int *)bstrString + 0x68))
                                                  (bstrString,&ppOStack_174);
                                        iVar8 = wcscmp((wchar_t *)ppOStack_174,L"true");
                                        *(bool *)((int)param_1 + 0xda) = iVar8 == 0;
                                      }
                                      else {
                                        iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TEXT_ALIGN");
                                        if (iVar8 == 0) {
                                          FUN_0040d230();
                                          (**(code **)(*(int *)bstrString + 0x68))
                                                    (bstrString,&ppOStack_174);
                                          iVar8 = wcscmp((wchar_t *)ppOVar10,L"left");
                                          if (iVar8 == 0) {
                                            (**(code **)(*param_1 + 0x1e4))(0);
                                          }
                                          else {
                                            iVar8 = wcscmp((wchar_t *)ppOVar10,L"center");
                                            if (iVar8 == 0) {
                                              (**(code **)(*param_1 + 0x1e4))(1);
                                            }
                                            else {
                                              iVar8 = wcscmp((wchar_t *)ppOVar10,L"right");
                                              if (iVar8 == 0) {
                                                (**(code **)(*param_1 + 0x1e4))(2);
                                              }
                                              else {
                                                iVar8 = wcscmp((wchar_t *)ppOVar10,L"justify");
                                                if (iVar8 == 0) {
                                                  (**(code **)(*param_1 + 0x1e4))(3);
                                                }
                                                else {
                                                  uStack_178 = (BSTR)0x0;
                                                  iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,0)
                                                  ;
                                                  if (iVar8 == 2) {
                                                    _DAT_00000000 =
                                                         (float)((int)_DAT_00000000 -
                                                                (int)pOStack_170);
                                                  }
                                                  if ((-1 < (int)pOStack_170) &&
                                                     ((int)pOStack_170 < 4)) {
                                                    (**(code **)(*param_1 + 0x1e4))(pOStack_170);
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                        else {
                                          iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TEXT_FONT");
                                          if (iVar8 == 0) {
                                            pOStack_170 = (BSTR)0x0;
                                            local_158[0] = (BSTR)0x0;
                                            iVar8 = (**(code **)(*(int *)bstrString + 0x44))
                                                              (bstrString,&pOStack_170);
                                            if ((iVar8 == 0) && (pOStack_170 != (BSTR)0x0)) {
                                              cVar2 = FUN_00799460(pOStack_170,L"FONT",local_158,10)
                                              ;
                                              if ((cVar2 != '\0') &&
                                                 ((-1 < (int)local_158[0] &&
                                                  ((int)local_158[0] < 0xe)))) {
                                                (**(code **)(*param_1 + 0x1b0))(local_158[0]);
                                              }
                                              (**(code **)(*(int *)pOStack_170 + 8))(pOStack_170);
                                            }
                                          }
                                          else {
                                            iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TEXT_SCALE");
                                            if (iVar8 == 0) {
                                              ppOStack_140 = (BSTR *)0x0;
                                              FUN_0040d230();
                                              (**(code **)(*(int *)bstrString + 0x68))
                                                        (bstrString,&ppOStack_174);
                                              iVar8 = (*pcVar9)(ppOVar10,L"%f;%f",auStack_148,0);
                                              if (iVar8 == 2) {
                                                _DAT_00000000 = _DAT_00000000 - (float)ppOStack_140;
                                              }
                                              param_1[0x4c] = (int)ppOStack_140;
                                            }
                                            else {
                                              iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                             L"MAX_TEXT_LENGTH");
                                              if (iVar8 == 0) {
                                                pOStack_170 = (BSTR)0x0;
                                                FUN_0040d230();
                                                (**(code **)(*(int *)bstrString + 0x68))
                                                          (bstrString,&ppOStack_174);
                                                iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,0);
                                                if (iVar8 == 2) {
                                                  _DAT_00000000 =
                                                       (float)((int)_DAT_00000000 - (int)uStack_178)
                                                  ;
                                                }
                                                (**(code **)(*param_1 + 0x1d0))(uStack_178);
                                              }
                                              else {
                                                iVar8 = wcscmp((wchar_t *)ppOStack_174,L"TRANSITION"
                                                              );
                                                if (iVar8 == 0) {
                                                  if ((char)((uint)unaff_ESI >> 0x18) == '\0') {
                                                    param_1[0x3d] = 0;
                                                  }
                                                  unaff_ESI = (int *)CONCAT13(1,(int3)unaff_ESI);
                                                  pOStack_170 = (BSTR)0x0;
                                                  FUN_0040d230();
                                                  (**(code **)(*(int *)bstrString + 0x68))
                                                            (bstrString,&ppOStack_174);
                                                  iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,0)
                                                  ;
                                                  if (iVar8 == 2) {
                                                    _DAT_00000000 =
                                                         (float)((int)_DAT_00000000 -
                                                                (int)uStack_178);
                                                  }
                                                  (**(code **)(*param_1 + 0xec))(uStack_178,1);
                                                }
                                                else {
                                                  iVar8 = wcscmp((wchar_t *)ppOStack_174,L"UNITS");
                                                  if (iVar8 == 0) {
                                                    pOStack_170 = (BSTR)0x0;
                                                    FUN_0040d230();
                                                    (**(code **)(*(int *)bstrString + 0x68))
                                                              (bstrString,&ppOStack_174);
                                                    iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",&uStack_178,
                                                                      0);
                                                    if (iVar8 == 2) {
                                                      _DAT_00000000 =
                                                           (float)((int)_DAT_00000000 -
                                                                  (int)pOStack_170);
                                                    }
                                                    if (pOStack_170 == (BSTR)0x0) {
                                                      *(undefined1 *)((int)param_1 + 0xd6) = 0;
                                                      *(undefined1 *)((int)param_1 + 0x1c9) = 0;
                                                      *(undefined1 *)((int)param_1 + 0x1ca) = 0;
                                                    }
                                                    else if (pOStack_170 == (BSTR)0x1) {
                                                      *(undefined1 *)((int)param_1 + 0xd6) = 1;
                                                      *(undefined1 *)((int)param_1 + 0x1c9) = 0;
                                                      *(undefined1 *)((int)param_1 + 0x1ca) = 0;
                                                    }
                                                    else if (pOStack_170 == (BSTR)0x2) {
                                                      *(undefined1 *)((int)param_1 + 0xd6) = 0;
                                                      *(undefined1 *)((int)param_1 + 0x1c9) = 1;
                                                      *(undefined1 *)((int)param_1 + 0x1ca) = 0;
                                                    }
                                                    else if (pOStack_170 == (BSTR)0x3) {
                                                      *(undefined1 *)((int)param_1 + 0xd6) = 0;
                                                      *(undefined1 *)((int)param_1 + 0x1c9) = 1;
                                                      *(undefined1 *)((int)param_1 + 0x1ca) = 1;
                                                    }
                                                  }
                                                  else {
                                                    iVar8 = wcscmp((wchar_t *)ppOStack_174,L"BORDER"
                                                                  );
                                                    if (iVar8 == 0) {
                                                      FUN_0040d230();
                                                      (**(code **)(*(int *)bstrString + 0x68))
                                                                (bstrString,&ppOStack_174);
                                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,L"true"
                                                                    );
                                                      *(bool *)(param_1 + 0x77) = iVar8 == 0;
                                                    }
                                                    else {
                                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                     L"BORDER_THICKNESS");
                                                      if (iVar8 == 0) {
                                                        pOStack_170 = (BSTR)0x0;
                                                        FUN_0040d230();
                                                        (**(code **)(*(int *)bstrString + 0x68))
                                                                  (bstrString,&ppOStack_174);
                                                        iVar8 = (*pcVar9)(ppOVar10,L"%d;%d",
                                                                          &uStack_178,0);
                                                        if (iVar8 == 2) {
                                                          _DAT_00000000 =
                                                               (float)((int)_DAT_00000000 -
                                                                      (int)pOStack_170);
                                                        }
                                                        param_1[0x78] = (int)pOStack_170;
                                                      }
                                                      else {
                                                        iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                       L"BORDER_COLOR");
                                                        if (iVar8 == 0) {
                                                          FUN_007a8f80(bstrString,param_1 + 0x79);
                                                        }
                                                        else {
                                                          iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                         L"ANCHOR");
                                                          if (iVar8 == 0) {
                                                            FUN_007a8b00(bstrString,param_1 + 0x6c,
                                                                         param_1 + 0x6d,0);
                                                          }
                                                          else {
                                                            iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                           L"TEXT_PADDING");
                                                            if (iVar8 == 0) {
                                                              FUN_007a8b00(bstrString,param_1 + 0x6e
                                                                           ,param_1 + 0x6f,0);
                                                            }
                                                            else {
                                                              iVar8 = wcscmp((wchar_t *)ppOStack_174
                                                                             ,L"POSITION");
                                                              if (iVar8 == 0) {
                                                                FUN_007a9cc0(param_1,bstrString);
                                                              }
                                                              else {
                                                                iVar8 = wcscmp((wchar_t *)
                                                                               ppOStack_174,L"GEO");
                                                                if (iVar8 == 0) {
                                                                  FUN_007ac940(param_1);
                                                                }
                                                                else {
                                                                  iVar8 = wcscmp((wchar_t *)
                                                                                 ppOStack_174,
                                                                                 L"TEXT");
                                                                  if (iVar8 == 0) {
                                                                    (**(code **)(*param_1 + 0x268))
                                                                              ();
                                                                    if ((DAT_00d1794c != 0) &&
                                                                       (*(int *)(DAT_00d1794c + 4)
                                                                        != 0)) {
                                                                      (**(code **)(**(int **)(
                                                  DAT_00d1794c + 4) + 0x120))
                                                            (*(int **)(DAT_00d1794c + 4),0xffffffff)
                                                  ;
                                                  }
                                                  FUN_007add10(bstrString,uStack_14,1);
                                                  if ((DAT_00d1794c != 0) &&
                                                     (*(int *)(DAT_00d1794c + 4) != 0)) {
                                                    (**(code **)(**(int **)(DAT_00d1794c + 4) +
                                                                0x120))(*(int **)(DAT_00d1794c + 4),
                                                                        0);
                                                  }
                                                  }
                                                  else {
                                                    iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                   L"TEXTURE");
                                                    if (iVar8 == 0) {
                                                      FUN_007aa150(param_1,bstrString);
                                                    }
                                                    else {
                                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                     L"WINDOW_DEFINITION");
                                                      if (iVar8 == 0) {
                                                        FUN_007b1220(param_1,bstrString);
                                                      }
                                                      else {
                                                        iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                       L"BG_COLOR");
                                                        if (iVar8 == 0) {
                                                          FUN_007ac5d0(param_1,bstrString,0);
                                                        }
                                                        else {
                                                          iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                         L"FG_COLOR");
                                                          if (iVar8 == 0) {
                                                            FUN_007ac5d0(param_1,bstrString,1);
                                                          }
                                                          else {
                                                            iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                           L"TRIM_COLOR");
                                                            if (iVar8 == 0) {
                                                              pOStack_170 = (BSTR)0x0;
                                                              uStack_20._0_1_ = 3;
                                                              (**(code **)(*(int *)bstrString + 0x30
                                                                          ))(bstrString,&piStack_144
                                                                            );
                                                              if (piStack_144 == (int *)0x0) {
                                                                uStack_20 = (uint)uStack_20._1_3_ <<
                                                                            8;
                                                                SysFreeString(pOStack_170);
                                                              }
                                                              else {
                                                                ppOVar10 = apOStack_138;
                                                                (**(code **)(*piStack_144 + 0x20))
                                                                          (piStack_144,ppOVar10);
                                                                iVar8 = 0;
                                                                if (0 < (int)ppOStack_140) {
                                                                  do {
                                                                    iVar3 = (**(code **)(*
                                                  piStack_14c + 0x1c))
                                                            (piStack_14c,iVar8,&stack0xfffffe9c);
                                                  if (iVar3 == 0) {
                                                    SysFreeString(uStack_178);
                                                    uStack_178 = (BSTR)0x0;
                                                    (**(code **)(*unaff_ESI + 0x1c))
                                                              (unaff_ESI,&uStack_178);
                                                    if (*_Str1 != L'#') {
                                                      iVar3 = wcscmp(_Str1,L"R");
                                                      if (iVar3 == 0) {
                                                        SysFreeString(_Str1);
                                                        _Str1 = (wchar_t *)0x0;
                                                        (**(code **)(*(int *)bstrString + 0x68))
                                                                  (bstrString,&stack0xfffffe80);
                                                        iVar3 = (*pcVar9)(ppOVar10,L"%d;%d",
                                                                          &uStack_178,0);
                                                        if (iVar3 == 2) {
                                                          _DAT_00000000 =
                                                               (float)((int)_DAT_00000000 -
                                                                      (int)pOStack_170);
                                                        }
                                                        if ((int)pOStack_170 < 0) {
                                                          uStack_178._0_3_ =
                                                               CONCAT12(DAT_00d1e7d2,
                                                                        (undefined2)uStack_178);
                                                        }
                                                        else {
                                                          uStack_178._0_3_ =
                                                               CONCAT12((char)pOStack_170,
                                                                        (undefined2)uStack_178);
                                                        }
                                                      }
                                                      else {
                                                        iVar3 = wcscmp(_Str1,L"G");
                                                        if (iVar3 == 0) {
                                                          SysFreeString(_Str1);
                                                          _Str1 = (wchar_t *)0x0;
                                                          (**(code **)(*(int *)bstrString + 0x68))
                                                                    (bstrString,&stack0xfffffe80);
                                                          iVar3 = (*pcVar9)(ppOVar10,L"%d;%d",
                                                                            &uStack_178,0);
                                                          if (iVar3 == 2) {
                                                            _DAT_00000000 =
                                                                 (float)((int)_DAT_00000000 -
                                                                        (int)pOStack_170);
                                                          }
                                                          if ((int)pOStack_170 < 0) {
                                                            uStack_178._0_2_ =
                                                                 CONCAT11(DAT_00d1e7d1,
                                                                          (undefined1)uStack_178);
                                                          }
                                                          else {
                                                            uStack_178._0_2_ =
                                                                 CONCAT11((char)pOStack_170,
                                                                          (undefined1)uStack_178);
                                                          }
                                                        }
                                                        else {
                                                          iVar3 = wcscmp(_Str1,L"B");
                                                          if (iVar3 == 0) {
                                                            SysFreeString(_Str1);
                                                            _Str1 = (wchar_t *)0x0;
                                                            (**(code **)(*(int *)bstrString + 0x68))
                                                                      (bstrString,&stack0xfffffe80);
                                                            iVar3 = (*pcVar9)(ppOVar10,L"%d;%d",
                                                                              &uStack_178,0);
                                                            if (iVar3 == 2) {
                                                              _DAT_00000000 =
                                                                   (float)((int)_DAT_00000000 -
                                                                          (int)pOStack_170);
                                                            }
                                                            if ((int)pOStack_170 < 0) {
                                                              uStack_178 = (BSTR)CONCAT31(uStack_178
                                                                                          ._1_3_,
                                                  DAT_00d1e7d0);
                                                  }
                                                  else {
                                                    uStack_178 = (BSTR)CONCAT31(uStack_178._1_3_,
                                                                                (char)pOStack_170);
                                                  }
                                                  }
                                                  else {
                                                    iVar3 = wcscmp(_Str1,L"A");
                                                    if (iVar3 == 0) {
                                                      SysFreeString(_Str1);
                                                      _Str1 = (wchar_t *)0x0;
                                                      (**(code **)(*(int *)bstrString + 0x68))
                                                                (bstrString,&stack0xfffffe80);
                                                      iVar3 = (*pcVar9)(ppOVar10,L"%d;%d",
                                                                        &uStack_178,0);
                                                      if (iVar3 == 2) {
                                                        _DAT_00000000 =
                                                             (float)((int)_DAT_00000000 -
                                                                    (int)pOStack_170);
                                                      }
                                                      pOVar5 = pOStack_170;
                                                      if ((int)pOStack_170 < 0) {
                                                        pOVar5 = (BSTR)(uint)DAT_00d1e7d3;
                                                      }
                                                      uStack_178 = (BSTR)CONCAT13((char)pOVar5,
                                                                                  (undefined3)
                                                                                  uStack_178);
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  (**(code **)(*(int *)bstrString + 8))(bstrString);
                                                  }
                                                  iVar8 = iVar8 + 1;
                                                  } while (iVar8 < (int)ppOStack_140);
                                                  }
                                                  (**(code **)(*piStack_14c + 8))(piStack_14c);
                                                  (**(code **)(*param_1 + 0x15c))(2,&ppOStack_174);
                                                  uStack_20 = (uint)uStack_20._1_3_ << 8;
                                                  SysFreeString(pOStack_170);
                                                  }
                                                  }
                                                  else {
                                                    iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                   L"TEXT_TRANSITION");
                                                    if (iVar8 == 0) {
                                                      FUN_007a9af0(param_1,bstrString);
                                                    }
                                                    else {
                                                      iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                     L"SUB_TEXTURE");
                                                      if (iVar8 == 0) {
                                                        FUN_007ad9c0();
                                                      }
                                                      else {
                                                        iVar8 = wcscmp((wchar_t *)ppOStack_174,
                                                                       L"SOUND");
                                                        if (iVar8 == 0) {
                                                          FUN_007a94d0(bstrString,uStack_14);
                                                        }
                                                        else {
                                                          (**(code **)(*param_1 + 0x3a8))
                                                                    (bstrString,uStack_14);
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
                      }
                    }
                  }
                }
              }
              (**(code **)(*(int *)bstrString + 8))(bstrString);
            }
            pOStack_128 = (BSTR)((int)pOStack_128 + 1);
          } while ((int)pOStack_128 < (int)apOStack_138[0]);
        }
        ppOStack_174 = ppOStack_140;
        uStack_178 = L"䒋㰤ႋｐࡒ鰹琤\x01琀譀⑄倐쫩";
        (**(code **)(*ppOStack_140 + 4))();
        uStack_178 = apOStack_138[0];
        (**(code **)(*(int *)apOStack_138[0] + 8))();
        goto LAB_007b2f5b;
      }
      ppOStack_174 = apOStack_11c;
      pOStack_170 = L"Interface lacking child nodes %s";
      uStack_178 = L"橐栃᨟";
      uStack_178 = (BSTR)FUN_0076cec0();
    }
    else {
      ppOStack_174 = apOStack_11c;
      pOStack_170 = L"Interface file no attribs %s";
      uStack_178 = L"橐栃ᨕ";
      uStack_178 = (BSTR)FUN_0076cec0();
    }
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDUIWindow.cpp");
  }
  pOStack_170 = L"貋尤\x01开嵞摛ඉ";
  SysFreeString(local_158[0]);
  ExceptionList = pvStack_c;
  return;
}
```
