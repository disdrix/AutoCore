// =============================================================================
// Named_PARTICLE_BUFFER_SIZE_0097b000
// -----------------------------------------------------------------------------
// Stable ID: aa_0097b000
// Address:   0x0097b000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_PARTICLE_BUFFER_SIZE_0097b000 @ 0x0097b000
// Stable ID: aa_0097b000
// Embedded strings (evidence for future rename):
//   - "ADD_EFFECT"
//   - "CAMERA"
//   - "POSITION"
//   - "ORIENTATION"
//   - "PARTICLE_BUFFER_SIZE"
//   - "NORMAL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~196 non-empty decompiler lines.
//  - Control keywords: if×20, do×3, while×3, goto×1, return×1.
//  - Notable callees: _wcsicmp×9, SysFreeString×6, swscanf×4, FUN_0040d230×3, FUN_00402d50, FUN_00414a20, FUN_0078c070, FUN_007a88b0.
//  - Strings: "ADD_EFFECT"; "CAMERA"; "POSITION"; "ORIENTATION".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * String-driven rename evidence: "PARTICLE_BUFFER_SIZE"
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



void Named_PARTICLE_BUFFER_SIZE_0097b000(int *param_1,int param_2)



{

  char cVar1;

  int iVar2;

  UINT UVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  char *pcVar8;

  int unaff_EBX;

  int *unaff_EDI;

  int iVar9;

  wchar_t **ppwStack_c8;

  int *piVar10;

  OLECHAR *pOVar11;

  wchar_t *local_ac [2];

  wchar_t **ppwStack_a4;

  int local_a0;

  int *piStack_9c;

  OLECHAR aOStack_98 [2];

  char *pcStack_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009ac56c;

  local_c = ExceptionList;

  local_ac[0] = (wchar_t *)0x0;

  local_4 = 0;

  if ((param_1 == (int *)0x0) || (param_2 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

  }

  else {

    ppwStack_c8 = (wchar_t **)0x97b059;

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x1c))();

    ppwStack_c8 = (wchar_t **)0x97b06b;

    iVar2 = _wcsicmp(L"ADD_EFFECT",local_ac[0]);

    if (iVar2 == 0) {

      SysFreeString(local_ac[0]);

      local_ac[0] = (BSTR)0x0;

      ppwStack_c8 = (wchar_t **)0x97b090;

      (**(code **)(*param_1 + 0x68))();

      if ((local_ac[0] != (BSTR)0x0) && (*local_ac[0] != L'\0')) {

        UVar3 = SysStringLen(local_ac[0]);

        pcVar4 = operator_new__(UVar3 + 1);

        pcStack_94 = pcVar4;

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

        pcVar8 = (char *)*puVar5;

        do {

          cVar1 = *pcVar8;

          *pcVar4 = cVar1;

          pcVar8 = pcVar8 + 1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        local_4 = local_4 & 0xffffff00;

        if (puStack_90 != auStack_8c) {

          free(puStack_90);

        }

        FUN_00414a20();

      }

    }

    else {

      ppwStack_c8 = (wchar_t **)0x97b134;

      iVar2 = _wcsicmp(L"CAMERA",local_ac[0]);

      if (iVar2 == 0) {

        ppwStack_c8 = (wchar_t **)0x97b14a;

        (**(code **)(*param_1 + 0x30))();

        if (piStack_9c != (int *)0x0) {

          pOVar11 = aOStack_98;

          ppwStack_c8 = (wchar_t **)0x97b18e;

          (**(code **)(*piStack_9c + 0x20))();

          iVar2 = 0;

          if (0 < local_a0) {

            do {

              ppwStack_c8 = local_ac;

              (**(code **)(*ppwStack_a4 + 0xe))(ppwStack_a4,iVar2);

              SysFreeString(pOVar11);

              pOVar11 = (OLECHAR *)0x0;

              (**(code **)(*unaff_EDI + 0x1c))(unaff_EDI,&stack0xffffff40);

              iVar6 = _wcsicmp(L"POSITION",(wchar_t *)ppwStack_c8);

              if (iVar6 == 0) {

                iVar6 = unaff_EBX + 0x524;

                iVar9 = unaff_EBX + 0x520;

                iVar7 = unaff_EBX + 0x51c;

LAB_0097b230:

                FUN_007a88b0(pOVar11,iVar7,iVar9,iVar6);

              }

              else {

                iVar6 = _wcsicmp(L"ORIENTATION",(wchar_t *)ppwStack_c8);

                if (iVar6 == 0) {

                  iVar6 = unaff_EBX + 0x530;

                  iVar9 = unaff_EBX + 0x52c;

                  iVar7 = unaff_EBX + 0x528;

                  goto LAB_0097b230;

                }

              }

              (**(code **)(*(int *)pOVar11 + 8))(pOVar11);

              iVar2 = iVar2 + 1;

            } while (iVar2 < local_a0);

          }

          ppwStack_c8 = ppwStack_a4;

          (**(code **)(*ppwStack_a4 + 4))();

        }

      }

      else {

        ppwStack_c8 = (wchar_t **)0x97b277;

        iVar2 = _wcsicmp(L"PARTICLE_BUFFER_SIZE",local_ac[0]);

        if (iVar2 == 0) {

          ppwStack_c8 = (wchar_t **)0x97b28d;

          (**(code **)(*param_1 + 0x30))();

          if (piStack_9c != (int *)0x0) {

            pOVar11 = aOStack_98;

            ppwStack_c8 = (wchar_t **)0x97b2a4;

            piVar10 = piStack_9c;

            (**(code **)(*piStack_9c + 0x20))();

            piStack_9c = (int *)0x0;

            if (0 < local_a0) {

              do {

                ppwStack_c8 = local_ac;

                (**(code **)(*ppwStack_a4 + 0xe))(ppwStack_a4,piStack_9c);

                SysFreeString(pOVar11);

                pOVar11 = (OLECHAR *)0x0;

                (**(code **)(*unaff_EDI + 0x1c))(unaff_EDI,&stack0xffffff40);

                iVar2 = _wcsicmp(L"NORMAL",(wchar_t *)ppwStack_c8);

                if (iVar2 == 0) {

                  SysFreeString((BSTR)ppwStack_c8);

                  ppwStack_c8 = (wchar_t **)0x0;

                  (**(code **)(*(int *)pOVar11 + 0x68))(pOVar11,&ppwStack_c8);

                  iVar2 = swscanf((wchar_t *)ppwStack_c8,L"%d;%d",&stack0xffffff3c,0);

                  if (iVar2 == 2) {

                    _DAT_00000000 = _DAT_00000000 - (int)piVar10;

                  }

                  *(int **)(unaff_EBX + 0x534) = piVar10;

                }

                else {

                  iVar2 = _wcsicmp(L"BRIGHT",(wchar_t *)ppwStack_c8);

                  if (iVar2 == 0) {

                    FUN_0040d230();

                    (**(code **)(*(int *)pOVar11 + 0x68))(pOVar11,&ppwStack_c8);

                    iVar2 = swscanf((wchar_t *)ppwStack_c8,L"%d;%d",&stack0xffffff3c,0);

                    if (iVar2 == 2) {

                      _DAT_00000000 = _DAT_00000000 - (int)piVar10;

                    }

                    *(int **)(unaff_EBX + 0x538) = piVar10;

                  }

                  else {

                    iVar2 = _wcsicmp(L"TERRAIN",(wchar_t *)ppwStack_c8);

                    if (iVar2 == 0) {

                      FUN_0040d230();

                      (**(code **)(*(int *)pOVar11 + 0x68))(pOVar11,&ppwStack_c8);

                      iVar2 = swscanf((wchar_t *)ppwStack_c8,L"%d;%d",&stack0xffffff3c,0);

                      if (iVar2 == 2) {

                        _DAT_00000000 = _DAT_00000000 - (int)piVar10;

                      }

                      *(int **)(unaff_EBX + 0x53c) = piVar10;

                    }

                    else {

                      iVar2 = _wcsicmp(L"DISTORT",(wchar_t *)ppwStack_c8);

                      if (iVar2 == 0) {

                        FUN_0040d230();

                        (**(code **)(*(int *)pOVar11 + 0x68))(pOVar11,&ppwStack_c8);

                        iVar2 = swscanf((wchar_t *)ppwStack_c8,L"%d;%d",&stack0xffffff3c,0);

                        if (iVar2 == 2) {

                          _DAT_00000000 = _DAT_00000000 - (int)piVar10;

                        }

                        *(int **)(unaff_EBX + 0x540) = piVar10;

                      }

                    }

                  }

                }

                (**(code **)(*(int *)pOVar11 + 8))(pOVar11);

                piStack_9c = (int *)((int)piStack_9c + 1);

              } while ((int)piStack_9c < local_a0);

            }

            ppwStack_c8 = ppwStack_a4;

            (**(code **)(*ppwStack_a4 + 4))();

          }

        }

        else {

          ppwStack_c8 = (wchar_t **)0x97b4d2;

          FUN_0078c070();

        }

      }

    }

    local_4 = 0xffffffff;

    SysFreeString(local_ac[0]);

  }

  ExceptionList = local_c;

  return;

}
