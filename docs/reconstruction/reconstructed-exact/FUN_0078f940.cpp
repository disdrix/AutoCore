// =============================================================================
// FUN_0078f940
// -----------------------------------------------------------------------------
// Stable ID: aa_0078f940
// Address:   0x0078f940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078f940 @ 0x0078f940
// Stable ID: aa_0078f940
// Embedded strings (evidence for future rename):
//   - "FILE_WND_BG_TEXTURE"
//   - "FILE_BTN_SLIDER"
//   - "FILE_BTN_UP"
//   - "FILE_BTN_DOWN"
//   - "IS_HORIZONTAL"
//   - "true"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~158 non-empty decompiler lines.
//  - Control keywords: if×13, do×5, while×5, return×2, goto×2.
//  - Notable callees: _wcsicmp×9, FUN_0040d230×4, SysFreeString×4, FUN_00402d50×3, free×2, FUN_00403450, FUN_0078f940, FUN_007933a0.
//  - Strings: "FILE_WND_BG_TEXTURE"; "FILE_BTN_SLIDER"; "FILE_BTN_UP"; "FILE_BTN_DOWN".
//  - Return sites: 2.

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



void __thiscall FUN_0078f940(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  int *unaff_EBX;

  int iVar6;

  uint32_t /* width from decompiler */ unaff_ESI;

  int *piVar7;

  float fVar8;

  wchar_t *_Str1;

  int iStack_9c;

  int *piStack_98;

  char *pcStack_90;

  char acStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb47b;

  local_c = ExceptionList;

  iVar6 = 0;

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2);

  iVar2 = _wcsicmp((wchar_t *)0x0,L"FILE_WND_BG_TEXTURE");

  if (iVar2 == 0) {

    SysFreeString((BSTR)0x0);

    (**(code **)(*param_2 + 0x68))(param_2);

    *(uint8_t *)(param_1 + 0x530) = 0;

    (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(unaff_ESI);

    pcVar3 = pcStack_90;

    do {

      cVar1 = *pcVar3;

      pcVar3[(param_1 + 0x530) - (int)pcStack_90] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    if (pcStack_90 != acStack_8c) {

      free(pcStack_90);

    }

  }

  else {

    iVar2 = _wcsicmp((wchar_t *)0x0,L"FILE_BTN_SLIDER");

    if (iVar2 == 0) {

      SysFreeString((BSTR)0x0);

      (**(code **)(*param_2 + 0x68))(param_2);

      pcVar3 = (char *)(param_1 + 0x634);

      *pcVar3 = '\0';

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

      pcVar5 = (char *)*puVar4;

      do {

        cVar1 = *pcVar5;

        *pcVar3 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

    }

    else {

      iVar2 = _wcsicmp((wchar_t *)0x0,L"FILE_BTN_UP");

      if (iVar2 == 0) {

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2);

        pcVar3 = (char *)(param_1 + 0x738);

        *pcVar3 = '\0';

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

        pcVar5 = (char *)*puVar4;

        do {

          cVar1 = *pcVar5;

          *pcVar3 = cVar1;

          pcVar5 = pcVar5 + 1;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

      }

      else {

        iVar2 = _wcsicmp((wchar_t *)0x0,L"FILE_BTN_DOWN");

        if (iVar2 != 0) {

          iVar2 = _wcsicmp((wchar_t *)0x0,L"IS_HORIZONTAL");

          if (iVar2 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2);

            iVar6 = _wcsicmp((wchar_t *)0x0,L"true");

            *(bool *)(param_1 + 0x4fd) = iVar6 == 0;

          }

          else {

            iVar2 = _wcsicmp((wchar_t *)0x0,L"OFFSET");

            if (iVar2 == 0) {

              (**(code **)(*param_2 + 0x30))(param_2);

              if (piStack_98 != (int *)0x0) {

                (**(code **)(*piStack_98 + 0x20))();

                if (0 < iStack_9c) {

                  do {

                    _Str1 = (wchar_t *)&stack0xffffff5c;

                    (**(code **)(_DAT_00000000 + 0x1c))(0,iVar6);

                    FUN_0040d230();

                    (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,&stack0xffffff4c);

                    iVar2 = _wcsicmp(_Str1,L"SLIDER");

                    if (iVar2 == 0) {

                      piVar7 = (int *)(param_1 + 0x520);

                      iVar2 = param_1 + 0x524;

LAB_0078fc68:

                      FUN_007a8b00(piStack_98,piVar7,iVar2,0);

                      fVar8 = (float)piVar7[1] * (float)DAT_00d1e81c * DAT_00aaa678;

                      *piVar7 = (int)((float)*piVar7 * (float)DAT_00d1e818 * DAT_00aaa67c);

                      piVar7[1] = (int)fVar8;

                    }

                    else {

                      iVar2 = _wcsicmp(_Str1,L"USEABLE");

                      if (iVar2 == 0) {

                        piVar7 = (int *)(param_1 + 0x528);

                        iVar2 = param_1 + 0x52c;

                        goto LAB_0078fc68;

                      }

                    }

                    (**(code **)(*piStack_98 + 8))(piStack_98);

                    iVar6 = iVar6 + 1;

                  } while (iVar6 < iStack_9c);

                }

                (**(code **)(_DAT_00000000 + 8))(0);

              }

            }

            else {

              FUN_007933a0(param_2);

            }

          }

          goto LAB_0078fbc4;

        }

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2);

        pcVar3 = (char *)(param_1 + 0x83c);

        *pcVar3 = '\0';

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

        pcVar5 = (char *)*puVar4;

        do {

          cVar1 = *pcVar5;

          *pcVar3 = cVar1;

          pcVar5 = pcVar5 + 1;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

      }

    }

    if (pcStack_90 != acStack_8c) {

      free(pcStack_90);

    }

  }

LAB_0078fbc4:

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
