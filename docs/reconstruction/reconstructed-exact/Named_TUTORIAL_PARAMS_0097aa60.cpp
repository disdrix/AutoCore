// =============================================================================
// Named_TUTORIAL_PARAMS_0097aa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0097aa60
// Address:   0x0097aa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_TUTORIAL_PARAMS_0097aa60 @ 0x0097aa60
// Stable ID: aa_0097aa60
// Embedded strings (evidence for future rename):
//   - "TUTORIAL_PARAMS"
//   - "줳尹␤䲉㠤踏ʮ"
//   - "LIFESPAN"
//   - "%f;%f"
//   - "TEXT_ANCHOR"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×15, return×2, do×1, goto×1, while×1.
//  - Notable callees: _wcsicmp×10, SysFreeString×5, swscanf×3, FUN_0040d230×2, FUN_007933a0, FUN_007a8b00, FUN_0097aa60.
//  - Strings: "TUTORIAL_PARAMS"; "줳尹␤䲉㠤踏ʮ"; "LIFESPAN"; "%f;%f".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "TUTORIAL_PARAMS"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_TUTORIAL_PARAMS_0097aa60(int param_1,int *param_2,int param_3)



{

  int iVar1;

  wchar_t *unaff_EBX;

  wchar_t *unaff_ESI;

  int *piVar2;

  float fVar3;

  wchar_t *pwStack_48;

  int *piVar4;

  OLECHAR *bstrString;

  uint32_t /* width from decompiler */ *puStack_38;

  uint32_t /* width from decompiler */ local_24;

  int *piStack_20;

  OLECHAR aOStack_18 [2];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8579;

  local_c = ExceptionList;

  local_24 = 0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    puStack_38 = (uint32_t /* width from decompiler */ *)0x97ae18;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  puStack_38 = &local_24;

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))();

  pwStack_48 = (wchar_t *)0x97aabd;

  iVar1 = _wcsicmp(L"TUTORIAL_PARAMS",unaff_ESI);

  if (iVar1 == 0) {

    pwStack_48 = (wchar_t *)0x97aad3;

    (**(code **)(*param_2 + 0x30))();

    if (piStack_20 != (int *)0x0) {

      bstrString = aOStack_18;

      pwStack_48 = L"줳尹␤䲉㠤踏ʮ";

      piVar4 = piStack_20;

      (**(code **)(*piStack_20 + 0x20))();

      local_c = (void *)0x0;

      if (0 < (int)piStack_20) {

        do {

          pwStack_48 = (wchar_t *)&stack0xffffffd0;

          (**(code **)(*(int *)unaff_EBX + 0x1c))(unaff_EBX,local_c);

          SysFreeString(bstrString);

          bstrString = (OLECHAR *)0x0;

          (**(code **)(*param_2 + 0x1c))(param_2,&stack0xffffffc0);

          iVar1 = _wcsicmp(L"LIFESPAN",pwStack_48);

          if (iVar1 == 0) {

            SysFreeString(pwStack_48);

            pwStack_48 = (wchar_t *)0x0;

            (**(code **)(*piVar4 + 0x68))(piVar4,&pwStack_48);

            iVar1 = swscanf(pwStack_48,L"%f;%f",&stack0xffffffc0,0);

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - (float)bstrString;

            }

            *(OLECHAR **)(param_1 + 0x530) = bstrString;

          }

          else {

            iVar1 = _wcsicmp(L"TEXT_ANCHOR",pwStack_48);

            if (iVar1 == 0) {

              SysFreeString(pwStack_48);

              pwStack_48 = (wchar_t *)0x0;

              (**(code **)(*piVar4 + 0x68))(piVar4,&pwStack_48);

              iVar1 = swscanf(pwStack_48,L"%d;%d",&puStack_38,0);

              if (iVar1 == 2) {

                _DAT_00000000 = (float)((int)_DAT_00000000 - (int)puStack_38);

              }

              *(uint32_t /* width from decompiler */ **)(param_1 + 0x538) = puStack_38;

            }

            else {

              iVar1 = _wcsicmp(L"HIGHLIGHT_SIZE",pwStack_48);

              if (iVar1 == 0) {

                piVar2 = (int *)(param_1 + 0x524);

                iVar1 = param_1 + 0x528;

              }

              else {

                iVar1 = _wcsicmp(L"SOURCE_POINT",pwStack_48);

                if (iVar1 == 0) {

                  piVar2 = (int *)(param_1 + 0x504);

                  iVar1 = param_1 + 0x508;

                }

                else {

                  iVar1 = _wcsicmp(L"SOURCE_OFFSET",pwStack_48);

                  if (iVar1 == 0) {

                    piVar2 = (int *)(param_1 + 0x50c);

                    iVar1 = param_1 + 0x510;

                  }

                  else {

                    iVar1 = _wcsicmp(L"BEND_OFFSET",pwStack_48);

                    if (iVar1 != 0) {

                      iVar1 = _wcsicmp(L"TRANSITION_TIME",pwStack_48);

                      if (iVar1 == 0) {

                        FUN_0040d230();

                        (**(code **)(*piVar4 + 0x68))(piVar4,&pwStack_48);

                        iVar1 = swscanf(pwStack_48,L"%f;%f",&stack0xffffffc0,0);

                        if (iVar1 == 2) {

                          _DAT_00000000 = _DAT_00000000 - (float)bstrString;

                        }

                        *(OLECHAR **)(param_1 + 0x534) = bstrString;

                      }

                      else {

                        iVar1 = _wcsicmp(L"SIMPLE",pwStack_48);

                        if (iVar1 == 0) {

                          FUN_0040d230();

                          (**(code **)(*piVar4 + 0x68))(piVar4,&pwStack_48);

                          iVar1 = _wcsicmp(L"true",pwStack_48);

                          *(bool *)(param_1 + 0x540) = iVar1 == 0;

                        }

                      }

                      goto LAB_0097adaf;

                    }

                    piVar2 = (int *)(param_1 + 0x514);

                    iVar1 = param_1 + 0x518;

                  }

                }

              }

              FUN_007a8b00(piVar4,piVar2,iVar1,0);

              fVar3 = (float)piVar2[1] * (float)DAT_00d1e81c * DAT_00aaa678;

              *piVar2 = (int)((float)*piVar2 * (float)DAT_00d1e818 * DAT_00aaa67c);

              piVar2[1] = (int)fVar3;

            }

          }

LAB_0097adaf:

          (**(code **)(*piVar4 + 8))(piVar4);

          local_c = (void *)((int)local_c + 1);

        } while ((int)local_c < (int)piStack_20);

      }

      pwStack_48 = unaff_EBX;

      (**(code **)(*(int *)unaff_EBX + 8))();

    }

  }

  else {

    pwStack_48 = 

    L"䓇〤\xffff\xffff䒋ဤ\xe950ﳥ\xffff䓇Ⱔ\xffff\xffff䲋తｑ\xe415鱦謀⑌弤孞襤\r";

    FUN_007933a0();

  }

  local_c = (void *)0xffffffff;

  SysFreeString(unaff_ESI);

  ExceptionList = pvStack_14;

  return;

}
