// =============================================================================
// FUN_00547920
// -----------------------------------------------------------------------------
// Stable ID: aa_00547920
// Address:   0x00547920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00547920 @ 0x00547920
// Stable ID: aa_00547920
// Embedded strings (evidence for future rename):
//   - "%s%S.xml"
//   - "䒋Ⱔႋ쒃倌勿謈⑄倐⋩\xffff쳿쳌쳌쳌ｪ뵨驃搀¡"
//   - "ڋ쒃㤐⑄༴钅\x04謀⑄贠⑌儜沉․ႋｐげ䒋ᰤ씻萏Ҥ"
//   - "䒋〤ࢋ쒃倌凿謈⑄謠倐勿謈⑄倐蛫䲍吤桑ಀ\x9dŪ䫨◅謀⑄謰茐ೄｐࡒ䒋․ࢋｐࡑ䒋ᰤႋｐࡒ䒋ဤ\xe950ｊ\xffff䲍吤桑౤\x9dŪ໨◅謀⑄謬茐ೄｐࡒ䒋ဤ\xe950Ｂ\xfff"
//   - "Mission lacking child nodes %s"
//   - "䒋․ࢋｐࡑ䒋ᰤႋｐࡒ䒋ဤ\xe950ｊ\xffff䲍吤桑౤\x9dŪ໨◅謀⑄謬茐ೄｐࡒ䒋ဤ\xe950Ｂ\xffff쳌쳌쳌櫌棿䎽\x9aꅤ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~278 non-empty decompiler lines.
//  - Control keywords: if×19, do×2, while×2, for×1, goto×1, return×1.
//  - Notable callees: _wcsicmp×10, FUN_00402d50×8, FUN_007a4480×5, SysFreeString×4, CONCAT31×2, FUN_007989b0×2, FUN_0040d230, FUN_00545f10.
//  - Strings: "%s%S.xml"; "䒋Ⱔႋ쒃倌勿謈⑄倐⋩\xffff쳿쳌쳌쳌ｪ뵨驃搀¡"; "ڋ쒃㤐⑄༴钅\x04謀⑄贠⑌儜沉․ႋｐげ䒋ᰤ씻萏Ҥ"; "Mission lacking child nodes %s".
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



void __fastcall FUN_00547920(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t *_Memory;

  int iVar2;

  uint8_t *puVar3;

  wchar_t *unaff_ESI;

  wchar_t *unaff_EDI;

  wchar_t *pwStack_5a0;

  wchar_t *pwStack_59c;

  int **ppiStack_598;

  BSTR bstrString;

  int ***pppiVar4;

  int *piVar5;

  BSTR local_574;

  int **ppiStack_570;

  BSTR pOStack_56c;

  int *piStack_568;

  int *local_564;

  BSTR local_560;

  uint8_t auStack_55c [4];

  int local_558;

  uint8_t auStack_540 [4];

  int local_53c;

  char local_530 [2];

  uint32_t /* width from decompiler */ local_52e [53];

  uint8_t *puStack_458;

  uint8_t auStack_454 [128];

  uint8_t *puStack_3d4;

  uint8_t auStack_3d0 [128];

  uint8_t *puStack_350;

  uint8_t auStack_34c [128];

  uint8_t *puStack_2cc;

  uint8_t auStack_2c8 [128];

  uint8_t *puStack_248;

  uint8_t auStack_244 [128];

  uint8_t *puStack_1c4;

  uint8_t auStack_1c0 [128];

  uint8_t *puStack_140;

  uint8_t auStack_13c [128];

  uint8_t *puStack_bc;

  uint8_t auStack_b8 [136];

  uint8_t uStack_30;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t uStack_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a43a5;

  local_c = ExceptionList;

  if ((char)param_1[0x5a] == '\0') {

    ExceptionList = &local_c;

    *(uint8_t *)(param_1 + 0x5a) = 1;

    FUN_00799940();

    local_530[0] = '\0';

    local_530[1] = '\0';

    puVar1 = local_52e;

    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    }

    *(uint16_t *)puVar1 = 0;

    local_4 = 0;

    ppiStack_598 = (int **)0x547998;

    _snprintf(local_530,0x104,"%s%S.xml");

    iVar2 = NDXml_OpenTaggedDocument();

    if (iVar2 == 0) {

      local_574 = (BSTR)0x0;

      local_4 = CONCAT31(local_4._1_3_,1);

      local_558 = 0;

      if (0 < local_53c) {

        do {

          local_564 = (int *)FUN_00799900();

          if (local_564 == (int *)0x0) {

            FUN_007a4480();

            break;

          }

          iVar2 = (**(code **)(*local_564 + 0x44))();

          if ((iVar2 != 0) || (piStack_568 == (int *)0x0)) {

            ppiStack_598 = (int **)0x1;

            pwStack_59c = L"䒋Ⱔႋ쒃倌勿謈⑄倐⋩\xffff쳿쳌쳌쳌ｪ뵨驃搀¡";

            FUN_007a4480();

            (**(code **)(*(int *)pOStack_56c + 8))();

            break;

          }

          ppiStack_598 = (int **)&DAT_009c9b2c;

          pwStack_59c = (wchar_t *)piStack_568;

          local_558 = -1;

          pwStack_5a0 = L"ڋ쒃㤐⑄༴钅\x04謀⑄贠⑌儜沉․ႋｐげ䒋ᰤ씻萏Ҥ";

          FUN_00799460();

          if (local_558 != *param_1) {

            ppiStack_598 = (int **)0x1;

            pwStack_59c = 

            L"䒋〤ࢋ쒃倌凿謈⑄謠倐勿謈⑄倐蛫䲍吤桑ಀ\x9dŪ䫨◅謀⑄謰茐ೄｐࡒ䒋․ࢋｐࡑ䒋ᰤႋｐࡒ䒋ဤ\xe950ｊ\xffff䲍吤桑౤\x9dŪ໨◅謀⑄謬茐ೄｐࡒ䒋ဤ\xe950Ｂ\xffff쳌쳌쳌櫌棿䎽\x9aꅤ"

            ;

            FUN_007a4480();

            (**(code **)(*piStack_568 + 8))();

            ppiStack_598 = (int **)0x547f1e;

            (*(code *)(*ppiStack_570)[2])();

            break;

          }

          pppiVar4 = &ppiStack_570;

          ppiStack_570 = (int **)0x0;

          ppiStack_598 = (int **)0x547a75;

          bstrString = pOStack_56c;

          (**(code **)(*(int *)pOStack_56c + 0x30))();

          if (unaff_ESI == (wchar_t *)0x0) {

            ppiStack_598 = (int **)auStack_540;

            pwStack_59c = L"Mission lacking child nodes %s";

            pwStack_5a0 = (wchar_t *)0x1;

            FUN_007a4480();

            ppiStack_598 = ppiStack_570;

            pwStack_59c = 

            L"䒋․ࢋｐࡑ䒋ᰤႋｐࡒ䒋ဤ\xe950ｊ\xffff䲍吤桑౤\x9dŪ໨◅謀⑄謬茐ೄｐࡒ䒋ဤ\xe950Ｂ\xffff쳌쳌쳌櫌棿䎽\x9aꅤ"

            ;

            (*(code *)(*ppiStack_570)[2])();

            pwStack_5a0 = 

            L"䒋ᰤႋｐࡒ䒋ဤ\xe950ｊ\xffff䲍吤桑౤\x9dŪ໨◅謀⑄謬茐ೄｐࡒ䒋ဤ\xe950Ｂ\xffff쳌쳌쳌櫌棿䎽\x9aꅤ"

            ;

            pwStack_59c = unaff_ESI;

            (**(code **)(_DAT_00000000 + 8))();

            pwStack_5a0 = unaff_EDI;

            (**(code **)(*(int *)unaff_EDI + 8))();

            break;

          }

          ppiStack_598 = &local_564;

          pwStack_5a0 = 

          L"沉ᐤ氹〤鲈耤\x05褀⑬༨뮎\x03謀⑄謜贐⑌儘䲋Ⱔ偑勿謜⑔刔ᗿ曤\x9c䒋ᠤ咍ᐤ襒⑬謘倈凿謜⑄倔쑨鴍＀菗ࣄ삅ṵ貋蠤\x05謀⑄儘咍堤偒캋䷨\xfff5\xe9ff̹"

          ;

          pwStack_59c = unaff_ESI;

          (**(code **)(*(int *)unaff_ESI + 0x20))();

          piVar5 = (int *)0x0;

          uStack_1c = 2;

          local_574 = (BSTR)0x0;

          if (0 < (int)pOStack_56c) {

            do {

              pwStack_5a0 = (wchar_t *)&stack0xfffffa7c;

              (**(code **)(*(int *)unaff_EDI + 0x1c))(unaff_EDI,local_574);

              SysFreeString(bstrString);

              bstrString = (BSTR)0x0;

              (*(code *)(*pppiVar4)[7])(pppiVar4,&stack0xfffffa6c);

              iVar2 = _wcsicmp(L"Objective",pwStack_59c);

              if (iVar2 == 0) {

                FUN_00547050(ppiStack_598,auStack_55c,uStack_28);

              }

              else {

                iVar2 = _wcsicmp(L"CoreMission",pwStack_59c);

                if (iVar2 == 0) {

                  unaff_ESI = (wchar_t *)0x0;

                  (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                  local_560 = pwStack_5a0;

                  FUN_007988e0(&local_560,&stack0xfffffa88,0,0);

                  *(uint8_t *)((int)param_1 + 0x169) = 0;

                  SysFreeString(pwStack_5a0);

                  pwStack_5a0 = (BSTR)0x0;

                }

                else {

                  iVar2 = _wcsicmp(L"Title",pwStack_59c);

                  if (iVar2 == 0) {

                    (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                    uStack_30 = 3;

                    FUN_00545f80(*puVar1);

                    puVar3 = auStack_34c;

                    _Memory = puStack_350;

                  }

                  else {

                    iVar2 = _wcsicmp(L"Internal",pwStack_59c);

                    if (iVar2 == 0) {

                      (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                      puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                      uStack_30 = 4;

                      FUN_00545f10(*puVar1);

                      puVar3 = auStack_b8;

                      _Memory = puStack_bc;

                    }

                    else {

                      iVar2 = _wcsicmp(L"Description",pwStack_59c);

                      if (iVar2 == 0) {

                        (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                        puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                        uStack_30 = 5;

                        FUN_00545ff0(*puVar1);

                        puVar3 = auStack_454;

                        _Memory = puStack_458;

                      }

                      else {

                        iVar2 = _wcsicmp(L"OneLineAccept",pwStack_59c);

                        if (iVar2 == 0) {

                          (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                          puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                          uStack_30 = 6;

                          FUN_00546060(*puVar1);

                          puVar3 = auStack_13c;

                          _Memory = puStack_140;

                        }

                        else {

                          iVar2 = _wcsicmp(L"OneLineReject",pwStack_59c);

                          if (iVar2 == 0) {

                            (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                            puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                            uStack_30 = 7;

                            FUN_005460d0(*puVar1);

                            puVar3 = auStack_244;

                            _Memory = puStack_248;

                          }

                          else {

                            iVar2 = _wcsicmp(L"NotCompleteText",pwStack_59c);

                            if (iVar2 == 0) {

                              (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                              puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                              uStack_30 = 8;

                              FUN_00546140(*puVar1);

                              puVar3 = auStack_3d0;

                              _Memory = puStack_3d4;

                            }

                            else {

                              iVar2 = _wcsicmp(L"CompleteText",pwStack_59c);

                              if (iVar2 == 0) {

                                (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                                puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                                uStack_30 = 9;

                                FUN_005461b0(*puVar1);

                                puVar3 = auStack_2c8;

                                _Memory = puStack_2cc;

                              }

                              else {

                                iVar2 = _wcsicmp(L"FailText",pwStack_59c);

                                if (iVar2 != 0) goto LAB_00547e41;

                                (*(code *)(*ppiStack_598)[0x1a])(ppiStack_598,&pwStack_5a0);

                                puVar1 = (uint32_t /* width from decompiler */ *)FUN_00402d50(pwStack_5a0);

                                uStack_30 = 10;

                                FUN_00546220(*puVar1);

                                puVar3 = auStack_1c0;

                                _Memory = puStack_1c4;

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                  uStack_30 = 2;

                  if (_Memory != puVar3) {

                    free(_Memory);

                  }

                  FUN_0040d230();

                }

              }

LAB_00547e41:

              (*(code *)(*ppiStack_598)[2])(ppiStack_598);

              local_574 = (BSTR)((int)local_574 + 1);

            } while ((int)local_574 < (int)pOStack_56c);

          }

          pwStack_5a0 = unaff_ESI;

          (**(code **)(*(int *)unaff_ESI + 8))();

          (**(code **)(*(int *)unaff_EDI + 8))(unaff_EDI);

          (**(code **)(*piVar5 + 8))(piVar5);

          local_4 = CONCAT31(local_4._1_3_,1);

          SysFreeString((BSTR)ppiStack_570);

          local_558 = local_558 + 1;

        } while (local_558 < local_53c);

      }

      SysFreeString(local_574);

      local_4 = 0xffffffff;

      FUN_007989b0();

    }

    else {

      FUN_007a4480();

      local_4 = 0xffffffff;

      FUN_007989b0();

    }

  }

  ExceptionList = local_c;

  return;

}
