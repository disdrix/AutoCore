// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×13, while×3, return×2, do×1, goto×1.
//  - Notable callees: SysFreeString×10, _wcsicmp×8, _wtol×5, wcstok×4, FUN_004073a0×2, _wtoi×2, FUN_0040d230, FUN_006127a0.
//  - Strings: "쒃贄⑌儜嶉譀嘆僿謰⑄㬜痃༨ា桒ᦐ\x9eŪ￨ᤏ茀ೄ幟孝䲋․襤\r"; "ContinentCBID"; "CBID"; "TEMPLATEID".
//  - Return sites: 2.

// =============================================================================
// Mission_Mission_killaggregate_objective_requirement_lack
// -----------------------------------------------------------------------------
// Stable ID: aa_00613400
// Address:   0x00613400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "!!!Mission - killaggregate objective requirement lacking child nodes slot:%d
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

void __thiscall Mission_Mission_killaggregate_objective_requirement_lack(int param_1,BSTR param_2)



{

  wchar_t **ppwVar1;

  int iVar2;

  wchar_t *pwVar3;

  long lVar4;

  int *unaff_EBX;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ **_Str2;

  int *piVar5;

  wchar_t **ppwStack_50;

  BSTR pOStack_4c;

  uint32_t /* width from decompiler */ *puStack_40;

  int iVar6;

  void *pvStack_2c;

  wchar_t *pwStack_28;

  int local_24;

  BSTR pOStack_1c;

  uint32_t /* width from decompiler */ local_14 [2];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a85bd;

  pvStack_c = ExceptionList;

  puStack_40 = local_14;

  ExceptionList = &pvStack_c;

  local_24 = param_1;

  (**(code **)(*(int *)param_2 + 0x44))();

  ppwStack_50 = (wchar_t **)0x9d929c;

  pOStack_4c = (BSTR)(param_1 + 8);

  FUN_00799820(pOStack_1c);

  if (*(void **)(param_1 + 0x40) != (void *)0x0) {

    pOStack_4c = 

    L"쒃贄⑌儜嶉譀嘆僿謰⑄㬜痃༨ា桒ᦐ\x9eŪ￨ᤏ茀ೄ幟孝䲋․襤\r";

    operator_delete__(*(void **)(param_1 + 0x40));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  pOStack_4c = param_2;

  ppwStack_50 = (wchar_t **)0x613469;

  (**(code **)(*(int *)param_2 + 0x30))();

  if (unaff_EBX == (int *)0x0) {

    ppwStack_50 = (wchar_t **)(uint)*(byte *)(param_1 + 8);

    FUN_007a4480(1,"!!!Mission - killaggregate objective requirement lacking child nodes slot:%d\n")

    ;

    ExceptionList = pOStack_1c;

    return;

  }

  ppwStack_50 = &pwStack_28;

  piVar5 = unaff_EBX;

  (**(code **)(*unaff_EBX + 0x20))();

  local_14[0] = 0;

  pOStack_1c = (BSTR)0x1;

  iVar6 = 0;

  if (0 < (int)unaff_EBX) {

    do {

      _Str2 = &puStack_40;

      (**(code **)(*unaff_ESI + 0x1c))(unaff_ESI,iVar6);

      SysFreeString((BSTR)ppwStack_50);

      ppwStack_50 = (wchar_t **)0x0;

      (**(code **)(*(int *)pOStack_4c + 0x1c))(pOStack_4c,&ppwStack_50);

      iVar2 = _wcsicmp(L"ContinentCBID",(wchar_t *)_Str2);

      if (iVar2 == 0) {

        (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

        pwVar3 = (wchar_t *)_wtol(pwStack_28);

        ppwStack_50[0x11] = pwVar3;

        SysFreeString(pwStack_28);

        pwStack_28 = (wchar_t *)0x0;

      }

      else {

        iVar2 = _wcsicmp(L"CBID",(wchar_t *)_Str2);

        if (iVar2 == 0) {

          (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

          pwVar3 = wcstok(pwStack_28,L"|");

          SysFreeString(pwStack_28);

          ppwVar1 = ppwStack_50;

          pwStack_28 = (wchar_t *)0x0;

          while (pwVar3 != (wchar_t *)0x0) {

            iVar2 = _wtoi(pwVar3);

            pwVar3 = ppwVar1[5];

            if ((pwVar3 == (wchar_t *)0x0) ||

               ((uint)((int)ppwVar1[7] - (int)pwVar3 >> 2) <=

                (uint)((int)ppwVar1[6] - (int)pwVar3 >> 2))) {

              FUN_004073a0(ppwVar1[6],1,&stack0xffffffc4);

            }

            else {

              pwVar3 = ppwVar1[6];

              *(int *)pwVar3 = iVar2;

              ppwVar1[6] = pwVar3 + 2;

            }

            pwVar3 = wcstok((wchar_t *)0x0,L"|");

          }

        }

        else {

          iVar2 = _wcsicmp(L"TEMPLATEID",(wchar_t *)_Str2);

          if (iVar2 == 0) {

            (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

            pwVar3 = wcstok(pwStack_28,L"|");

            SysFreeString(pwStack_28);

            ppwVar1 = ppwStack_50;

            pwStack_28 = (wchar_t *)0x0;

            while (pwVar3 != (wchar_t *)0x0) {

              iVar2 = _wtoi(pwVar3);

              pwVar3 = ppwVar1[9];

              if ((pwVar3 == (wchar_t *)0x0) ||

                 ((uint)((int)ppwVar1[0xb] - (int)pwVar3 >> 2) <=

                  (uint)((int)ppwVar1[10] - (int)pwVar3 >> 2))) {

                FUN_004073a0(ppwVar1[10],1,&stack0xffffffc4);

              }

              else {

                pwVar3 = ppwVar1[10];

                *(int *)pwVar3 = iVar2;

                ppwVar1[10] = pwVar3 + 2;

              }

              pwVar3 = wcstok((wchar_t *)0x0,L"|");

            }

          }

          else {

            iVar2 = _wcsicmp(L"NumToKill",(wchar_t *)_Str2);

            if (iVar2 == 0) {

              (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

              pwVar3 = (wchar_t *)_wtol(pwStack_28);

              ppwStack_50[0xc] = pwVar3;

              SysFreeString(pwStack_28);

              pwStack_28 = (wchar_t *)0x0;

            }

            else {

              iVar2 = _wcsicmp(L"NegativeKill",(wchar_t *)_Str2);

              if (iVar2 == 0) {

                (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

                lVar4 = _wtol(pwStack_28);

                *(bool *)(ppwStack_50 + 0xd) = lVar4 != 0;

                SysFreeString(pwStack_28);

                pwStack_28 = (wchar_t *)0x0;

              }

              else {

                iVar2 = _wcsicmp(L"TargetIsFaction",(wchar_t *)_Str2);

                if (iVar2 == 0) {

                  (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

                  lVar4 = _wtol(pwStack_28);

                  *(bool *)(ppwStack_50 + 0xf) = lVar4 != 0;

                  SysFreeString(pwStack_28);

                  pwStack_28 = (wchar_t *)0x0;

                }

                else {

                  iVar2 = _wcsicmp(L"AllowedType",(wchar_t *)_Str2);

                  if (iVar2 == 0) {

                    (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

                    pwVar3 = (wchar_t *)_wtol(pwStack_28);

                    ppwStack_50[0xe] = pwVar3;

                  }

                  else {

                    iVar2 = _wcsicmp(L"ShortDescription",(wchar_t *)_Str2);

                    if (iVar2 != 0) goto LAB_00613818;

                    (**(code **)(*piVar5 + 0x68))(piVar5,&pwStack_28);

                    FUN_006127a0(pwStack_28);

                  }

                  FUN_0040d230();

                }

              }

            }

          }

        }

      }

LAB_00613818:

      (**(code **)(*piVar5 + 8))(piVar5);

      SysFreeString((BSTR)0x0);

      iVar6 = iVar6 + 1;

    } while (iVar6 < (int)unaff_EBX);

  }

  (**(code **)(*unaff_ESI + 8))(unaff_ESI);

  (**(code **)(*unaff_EBX + 8))(unaff_EBX);

  SysFreeString(pOStack_1c);

  SysFreeString(pOStack_4c);

  ExceptionList = pvStack_2c;

  return;

}
