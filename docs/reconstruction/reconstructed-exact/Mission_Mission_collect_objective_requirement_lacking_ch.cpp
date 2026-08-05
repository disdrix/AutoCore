// READABILITY (auto CF):
//  - Body size: ~218 non-empty decompiler lines.
//  - Control keywords: if×17, return×2, do×1, goto×1, while×1.
//  - Notable callees: _wcsicmp×13, _wtol×12, SysFreeString×11, FUN_0040d230×4, FUN_007a4480×2, FUN_00611a00, FUN_00799820, _wtof.
//  - Strings: "slot"; "ContinentCBID"; "CBID"; "TargetIsTemplateVehicle".
//  - Return sites: 2.

// =============================================================================
// Mission_Mission_collect_objective_requirement_lacking_ch
// -----------------------------------------------------------------------------
// Stable ID: aa_00611a00
// Address:   0x00611a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "!!!Mission - collect objective requirement lacking child nodes slot:%d
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Mission_collect_objective_requirement_lacking_ch(int param_1,BSTR param_2)



{

  int iVar1;

  long lVar2;

  wchar_t *unaff_EBX;

  int *unaff_EBP;

  int *unaff_ESI;

  double dVar3;

  uint8_t **_Str2;

  wchar_t *pwVar4;

  BSTR pOStack_48;

  BSTR pOStack_44;

  uint8_t *puStack_40;

  BSTR pOStack_3c;

  uint8_t *puStack_38;

  int iVar5;

  OLECHAR aOStack_24 [2];

  uint8_t auStack_20 [4];

  BSTR pOStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t local_10 [4];

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &DAT_009a8530;

  pvStack_c = ExceptionList;

  puStack_38 = local_10;

  pOStack_3c = param_2;

  puStack_40 = (uint8_t *)0x611a2d;

  ExceptionList = &pvStack_c;

  (**(code **)(*(int *)param_2 + 0x44))();

  puStack_40 = (uint8_t *)0xa;

  pOStack_48 = L"slot";

  pOStack_44 = (BSTR)(param_1 + 8);

  FUN_00799820(uStack_18);

  puStack_40 = auStack_20;

  pOStack_44 = param_2;

  pOStack_48 = (BSTR)0x611a50;

  (**(code **)(*(int *)param_2 + 0x30))();

  if (unaff_EBX == (wchar_t *)0x0) {

    pOStack_48 = (BSTR)(uint)*(byte *)(param_1 + 8);

    FUN_007a4480(1,"!!!Mission - collect objective requirement lacking child nodes slot:%d\n");

    ExceptionList = pOStack_1c;

    return;

  }

  pOStack_48 = aOStack_24;

  pwVar4 = unaff_EBX;

  (**(code **)(*(int *)unaff_EBX + 0x20))();

  pOStack_3c = (BSTR)0x0;

  uStack_14 = 0;

  *(uint8_t *)(param_1 + 0x1a) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

  pOStack_1c = (BSTR)0x1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint8_t *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x19) = 0;

  iVar5 = 0;

  if (0 < (int)unaff_EBP) {

    do {

      _Str2 = &puStack_38;

      (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI,iVar5);

      SysFreeString(pOStack_48);

      pOStack_48 = (OLECHAR *)0x0;

      (**(code **)(*(int *)pOStack_44 + 0x1c))(pOStack_44,&pOStack_48);

      iVar1 = _wcsicmp(L"ContinentCBID",(wchar_t *)_Str2);

      if (iVar1 == 0) {

        (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

        lVar2 = _wtol(unaff_EBX);

        *(long *)(param_1 + 100) = lVar2;

        SysFreeString(unaff_EBX);

        unaff_EBX = (wchar_t *)0x0;

      }

      else {

        iVar1 = _wcsicmp(L"CBID",(wchar_t *)_Str2);

        if (iVar1 == 0) {

          (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

          lVar2 = _wtol(unaff_EBX);

          *(long *)(param_1 + 0x10) = lVar2;

          SysFreeString(unaff_EBX);

          unaff_EBX = (wchar_t *)0x0;

        }

        else {

          iVar1 = _wcsicmp(L"TargetIsTemplateVehicle",(wchar_t *)_Str2);

          if (iVar1 == 0) {

            (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

            lVar2 = _wtol(unaff_EBX);

            *(bool *)(param_1 + 0x1a) = lVar2 != 0;

            SysFreeString(unaff_EBX);

            unaff_EBX = (wchar_t *)0x0;

          }

          else {

            iVar1 = _wcsicmp(L"TargetIsPlayer",(wchar_t *)_Str2);

            if (iVar1 == 0) {

              (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

              lVar2 = _wtol(unaff_EBX);

              *(bool *)(param_1 + 0x19) = lVar2 != 0;

              SysFreeString(unaff_EBX);

              unaff_EBX = (wchar_t *)0x0;

            }

            else {

              iVar1 = _wcsicmp(L"NumToCollect",(wchar_t *)_Str2);

              if (iVar1 == 0) {

                (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                lVar2 = _wtol(unaff_EBX);

                *(long *)(param_1 + 0x14) = lVar2;

                SysFreeString(unaff_EBX);

                unaff_EBX = (wchar_t *)0x0;

              }

              else {

                iVar1 = _wcsicmp(L"OptionalTargetCBID",(wchar_t *)_Str2);

                if (iVar1 == 0) {

                  if (*(int *)(param_1 + 0x1c) < 10) {

                    (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                    lVar2 = _wtol(unaff_EBX);

                    *(long *)(param_1 + 0x20 + *(int *)(param_1 + 0x1c) * 4) = lVar2;

                    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;

                    SysFreeString(unaff_EBX);

                    unaff_EBX = (wchar_t *)0x0;

                  }

                }

                else {

                  iVar1 = _wcsicmp(L"OptionalDropPercent",(wchar_t *)_Str2);

                  if (iVar1 == 0) {

                    (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                    dVar3 = _wtof(unaff_EBX);

                    *(float *)(param_1 + 0x48) = (float)dVar3;

                    SysFreeString(unaff_EBX);

                    unaff_EBX = (wchar_t *)0x0;

                  }

                  else {

                    iVar1 = _wcsicmp(L"TakeAllItems",(wchar_t *)_Str2);

                    if (iVar1 == 0) {

                      (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                      lVar2 = _wtol(unaff_EBX);

                      *(bool *)(param_1 + 0x18) = lVar2 == 1;

                      SysFreeString(unaff_EBX);

                      unaff_EBX = (wchar_t *)0x0;

                    }

                    else {

                      iVar1 = _wcsicmp(L"GiveToAllConvoyMembers",(wchar_t *)_Str2);

                      if (iVar1 == 0) {

                        (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                        lVar2 = _wtol(unaff_EBX);

                        *(bool *)(param_1 + 0x4c) = lVar2 == 1;

                        FUN_0040d230();

                      }

                      else {

                        iVar1 = _wcsicmp(L"AllowedType",(wchar_t *)_Str2);

                        if (iVar1 == 0) {

                          (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                          lVar2 = _wtol(unaff_EBX);

                          *(long *)(param_1 + 0x50) = lVar2;

                          FUN_0040d230();

                        }

                        else {

                          iVar1 = _wcsicmp(L"AllowedClass",(wchar_t *)_Str2);

                          if (iVar1 == 0) {

                            (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                            lVar2 = _wtol(unaff_EBX);

                            *(long *)(param_1 + 0x54) = lVar2;

                            FUN_0040d230();

                          }

                          else {

                            iVar1 = _wcsicmp(L"RequireLevelMin",(wchar_t *)_Str2);

                            if (iVar1 == 0) {

                              (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                              lVar2 = _wtol(unaff_EBX);

                              *(long *)(param_1 + 0x5c) = lVar2;

                            }

                            else {

                              iVar1 = _wcsicmp(L"RequireLevelMax",(wchar_t *)_Str2);

                              if (iVar1 != 0) goto LAB_00611e94;

                              (**(code **)(*(int *)pwVar4 + 0x68))(pwVar4,&stack0xffffffd8);

                              lVar2 = _wtol(unaff_EBX);

                              *(long *)(param_1 + 0x60) = lVar2;

                            }

                            FUN_0040d230();

                            *(uint8_t *)(param_1 + 0x58) = 1;

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

LAB_00611e94:

      (**(code **)(*(int *)pwVar4 + 8))(pwVar4);

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)unaff_EBP);

  }

  if ((*(int *)(param_1 + 0x10) == -1) && (*(char *)(param_1 + 0x19) == '\0')) {

    FUN_007a4480(1,"!!!Mission - collect objective did not find an item to collect: %S\n",

                 *(int *)(*(int *)(param_1 + 4) + 0x14c) + 4);

  }

  (**(code **)(*unaff_ESI + 8))(unaff_ESI);

  (**(code **)(*unaff_EBP + 8))(unaff_EBP);

  SysFreeString(pOStack_1c);

  SysFreeString(pOStack_44);

  ExceptionList = unaff_EBP;

  return;

}
