// =============================================================================
// FUN_00818000
// -----------------------------------------------------------------------------
// Stable ID: aa_00818000
// Address:   0x00818000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00818000 @ 0x00818000
// Stable ID: aa_00818000
// Embedded strings (evidence for future rename):
//   - "咋ဤ桒절§ᗿ斀\x9c쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ"
//   - "쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ"
//   - "OPTIONS"
//   - "䒋ᰤ쌻萏ؘ"
//   - "尹․岉ᠤ踏ך"
//   - "START"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~299 non-empty decompiler lines.
//  - Control keywords: if×19, do×10, while×10, goto×3, return×1.
//  - Notable callees: _wcsicmp×14, FUN_0040d230×10, FUN_00402d50×9, SysFreeString×2, FUN_007933a0, FUN_007a8b00, FUN_00818000, free.
//  - Strings: "咋ဤ桒절§ᗿ斀\x9c쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ"; "쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ"; "OPTIONS"; "䒋ᰤ쌻萏ؘ".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00818000(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t *_Memory;

  char *pcVar4;

  uint8_t *puVar5;

  char *pcVar6;

  uint8_t *unaff_EBP;

  int *unaff_EDI;

  int *piVar7;

  float fVar8;

  wchar_t *pwStack_4e0;

  OLECHAR *bstrString;

  BSTR local_4c4;

  wchar_t *pwStack_4c0;

  int iStack_4bc;

  int *piStack_4b8;

  OLECHAR aOStack_4b4 [54];

  uint8_t *puStack_448;

  uint8_t auStack_444 [128];

  uint8_t *puStack_3c4;

  uint8_t auStack_3c0 [128];

  uint8_t *puStack_340;

  uint8_t auStack_33c [128];

  uint8_t *puStack_2bc;

  uint8_t auStack_2b8 [128];

  uint8_t *puStack_238;

  uint8_t auStack_234 [128];

  uint8_t *puStack_1b4;

  uint8_t auStack_1b0 [128];

  uint8_t *puStack_130;

  uint8_t auStack_12c [128];

  uint8_t *puStack_ac;

  uint8_t auStack_a8 [136];

  uint8_t uStack_20;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8191;

  pvStack_c = ExceptionList;

  local_4c4 = (BSTR)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  if ((param_2 != (int *)0x0) && (ExceptionList = &pvStack_c, param_3 != 0)) {

    pwStack_4e0 = L"咋ဤ桒절§ᗿ斀\x9c쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ";

    ExceptionList = &pvStack_c;

    (**(code **)(*param_2 + 0x1c))();

    pwStack_4e0 = L"쒃蔈࿀⚅\x06謀贇⑌儜ｗぐ䒋ᰤ쌻萏ؘ";

    iVar2 = _wcsicmp(L"OPTIONS",(wchar_t *)0x0);

    if (iVar2 == 0) {

      pwStack_4e0 = L"䒋ᰤ쌻萏ؘ";

      (**(code **)(*param_2 + 0x30))();

      if (piStack_4b8 != (int *)0x0) {

        bstrString = aOStack_4b4;

        pwStack_4e0 = L"尹․岉ᠤ踏ך";

        (**(code **)(*piStack_4b8 + 0x20))();

        local_4c4 = (BSTR)0x0;

        if (0 < iStack_4bc) {

          do {

            pwStack_4e0 = (wchar_t *)&stack0xfffffb38;

            (**(code **)(*(int *)pwStack_4c0 + 0x1c))(pwStack_4c0,local_4c4);

            SysFreeString(bstrString);

            bstrString = (OLECHAR *)0x0;

            (**(code **)(*unaff_EDI + 0x1c))(unaff_EDI,&stack0xfffffb28);

            iVar2 = _wcsicmp(L"START",pwStack_4e0);

            if (iVar2 == 0) {

              piVar7 = (int *)(param_1 + 0x524);

              iVar2 = param_1 + 0x528;

LAB_00818107:

              FUN_007a8b00(piStack_4b8,piVar7,iVar2,0);

              fVar8 = (float)piVar7[1] * (float)DAT_00d1e81c * DAT_00aaa678;

              *piVar7 = (int)((float)*piVar7 * (float)DAT_00d1e818 * DAT_00aaa67c);

              piVar7[1] = (int)fVar8;

            }

            else {

              iVar2 = _wcsicmp(L"SPACING",pwStack_4e0);

              if (iVar2 == 0) {

                piVar7 = (int *)(param_1 + 0x52c);

                iVar2 = param_1 + 0x530;

                goto LAB_00818107;

              }

              iVar2 = _wcsicmp(L"DIVIDER_OFFSET",pwStack_4e0);

              if (iVar2 == 0) {

                *(uint8_t *)(param_1 + 0x544) = 1;

                piVar7 = (int *)(param_1 + 0x534);

                iVar2 = param_1 + 0x538;

                goto LAB_00818107;

              }

              iVar2 = _wcsicmp(L"NUM_OPTIONS_VISIBLE",pwStack_4e0);

              if (iVar2 == 0) {

                FUN_0040d230();

                (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                iVar2 = swscanf(pwStack_4e0,L"%d;%d",(int *)(param_1 + 0x540),0);

                if (iVar2 == 2) {

                  _DAT_00000000 = _DAT_00000000 - *(int *)(param_1 + 0x540);

                }

              }

              else {

                iVar2 = _wcsicmp(L"FILE_STRING_TOGGLES",pwStack_4e0);

                if (iVar2 == 0) {

                  FUN_0040d230();

                  (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                  pcVar6 = (char *)(param_1 + 0x54c);

                  *pcVar6 = '\0';

                  puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                  pcVar4 = (char *)*puVar3;

                  do {

                    cVar1 = *pcVar4;

                    *pcVar6 = cVar1;

                    pcVar4 = pcVar4 + 1;

                    pcVar6 = pcVar6 + 1;

                  } while (cVar1 != '\0');

                  puVar5 = auStack_234;

                  _Memory = puStack_238;

                }

                else {

                  iVar2 = _wcsicmp(L"FILE_CHECK_TOGGLES",pwStack_4e0);

                  if (iVar2 == 0) {

                    FUN_0040d230();

                    (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                    pcVar6 = (char *)(param_1 + 0x650);

                    *pcVar6 = '\0';

                    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                    pcVar4 = (char *)*puVar3;

                    do {

                      cVar1 = *pcVar4;

                      *pcVar6 = cVar1;

                      pcVar4 = pcVar4 + 1;

                      pcVar6 = pcVar6 + 1;

                    } while (cVar1 != '\0');

                    puVar5 = &stack0xfffffb38;

                    _Memory = unaff_EBP;

                  }

                  else {

                    iVar2 = _wcsicmp(L"FILE_RADIO_TOGGLES",pwStack_4e0);

                    if (iVar2 == 0) {

                      FUN_0040d230();

                      (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                      pcVar6 = (char *)(param_1 + 0x754);

                      *pcVar6 = '\0';

                      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                      pcVar4 = (char *)*puVar3;

                      do {

                        cVar1 = *pcVar4;

                        *pcVar6 = cVar1;

                        pcVar4 = pcVar4 + 1;

                        pcVar6 = pcVar6 + 1;

                      } while (cVar1 != '\0');

                      puVar5 = auStack_33c;

                      _Memory = puStack_340;

                    }

                    else {

                      iVar2 = _wcsicmp(L"FILE_HORIZONTAL_SLIDER",pwStack_4e0);

                      if (iVar2 == 0) {

                        FUN_0040d230();

                        (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                        pcVar6 = (char *)(param_1 + 0x858);

                        *pcVar6 = '\0';

                        puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                        pcVar4 = (char *)*puVar3;

                        do {

                          cVar1 = *pcVar4;

                          *pcVar6 = cVar1;

                          pcVar4 = pcVar4 + 1;

                          pcVar6 = pcVar6 + 1;

                        } while (cVar1 != '\0');

                        puVar5 = auStack_12c;

                        _Memory = puStack_130;

                      }

                      else {

                        iVar2 = _wcsicmp(L"FILE_COMBO_BOX",pwStack_4e0);

                        if (iVar2 == 0) {

                          FUN_0040d230();

                          (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                          pcVar6 = (char *)(param_1 + 0x95c);

                          *pcVar6 = '\0';

                          puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                          pcVar4 = (char *)*puVar3;

                          do {

                            cVar1 = *pcVar4;

                            *pcVar6 = cVar1;

                            pcVar4 = pcVar4 + 1;

                            pcVar6 = pcVar6 + 1;

                          } while (cVar1 != '\0');

                          puVar5 = auStack_444;

                          _Memory = puStack_448;

                        }

                        else {

                          iVar2 = _wcsicmp(L"FILE_KEY_CONFIG",pwStack_4e0);

                          if (iVar2 == 0) {

                            FUN_0040d230();

                            (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                            pcVar6 = (char *)(param_1 + 0xa60);

                            *pcVar6 = '\0';

                            puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                            pcVar4 = (char *)*puVar3;

                            do {

                              cVar1 = *pcVar4;

                              *pcVar6 = cVar1;

                              pcVar4 = pcVar4 + 1;

                              pcVar6 = pcVar6 + 1;

                            } while (cVar1 != '\0');

                            puVar5 = auStack_3c0;

                            _Memory = puStack_3c4;

                          }

                          else {

                            iVar2 = _wcsicmp(L"FILE_SCROLL_BAR",pwStack_4e0);

                            if (iVar2 == 0) {

                              *(uint8_t *)(param_1 + 0x544) = 1;

                              FUN_0040d230();

                              (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                              pcVar6 = (char *)(param_1 + 0xb64);

                              *pcVar6 = '\0';

                              puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                              pcVar4 = (char *)*puVar3;

                              do {

                                cVar1 = *pcVar4;

                                *pcVar6 = cVar1;

                                pcVar4 = pcVar4 + 1;

                                pcVar6 = pcVar6 + 1;

                              } while (cVar1 != '\0');

                              puVar5 = auStack_2b8;

                              _Memory = puStack_2bc;

                            }

                            else {

                              iVar2 = _wcsicmp(L"FILE_DIVIDER",pwStack_4e0);

                              if (iVar2 == 0) {

                                *(uint8_t *)(param_1 + 0x544) = 1;

                                FUN_0040d230();

                                (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                                pcVar6 = (char *)(param_1 + 0xc68);

                                *pcVar6 = '\0';

                                puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                                pcVar4 = (char *)*puVar3;

                                do {

                                  cVar1 = *pcVar4;

                                  *pcVar6 = cVar1;

                                  pcVar4 = pcVar4 + 1;

                                  pcVar6 = pcVar6 + 1;

                                } while (cVar1 != '\0');

                                puVar5 = auStack_1b0;

                                _Memory = puStack_1b4;

                              }

                              else {

                                iVar2 = _wcsicmp(L"FILE_DIVIDER_ALT",pwStack_4e0);

                                if (iVar2 != 0) goto LAB_0081865d;

                                *(uint8_t *)(param_1 + 0x544) = 1;

                                FUN_0040d230();

                                (**(code **)(*piStack_4b8 + 0x68))(piStack_4b8,&pwStack_4e0);

                                pcVar6 = (char *)(param_1 + 0xd6c);

                                *pcVar6 = '\0';

                                puVar3 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_4e0);

                                pcVar4 = (char *)*puVar3;

                                do {

                                  cVar1 = *pcVar4;

                                  *pcVar6 = cVar1;

                                  pcVar4 = pcVar4 + 1;

                                  pcVar6 = pcVar6 + 1;

                                } while (cVar1 != '\0');

                                puVar5 = auStack_a8;

                                _Memory = puStack_ac;

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

                uStack_20 = 0;

                if (_Memory != puVar5) {

                  free(_Memory);

                }

              }

            }

LAB_0081865d:

            (**(code **)(*piStack_4b8 + 8))(piStack_4b8);

            local_4c4 = (BSTR)((int)local_4c4 + 1);

          } while ((int)local_4c4 < iStack_4bc);

        }

        pwStack_4e0 = pwStack_4c0;

        (**(code **)(*(int *)pwStack_4c0 + 8))();

      }

    }

    else {

      pwStack_4e0 = 

      L"蓇퀤\x04＀\xffff诿⑔刐ძ蓇퀤\x04＀\xffff诿⑄倐ᗿ曤\x9c貋젤\x04开嵞摛ඉ"

      ;

      FUN_007933a0();

    }

  }

  local_4 = 0xffffffff;

  SysFreeString(local_4c4);

  ExceptionList = pvStack_c;

  return;

}
