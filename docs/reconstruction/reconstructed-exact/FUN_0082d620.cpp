// =============================================================================
// FUN_0082d620
// -----------------------------------------------------------------------------
// Stable ID: aa_0082d620
// Address:   0x0082d620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082d620 @ 0x0082d620
// Stable ID: aa_0082d620
// Embedded strings (evidence for future rename):
//   - "BUTTON"
//   - "START"
//   - "SIZE"
//   - "SPACING"
//   - "SIZE_SEPARATOR"
//   - "EXPAND_DIR_1"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×13, return×2, goto×2, for×1, do×1, while×1.
//  - Notable callees: _wcsicmp×9, FUN_0040d230×3, SysFreeString×3, FUN_007a8b00×2, swscanf×2, FUN_007933a0, FUN_0082d620.
//  - Strings: "BUTTON"; "START"; "SIZE"; "SPACING".
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

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void __thiscall FUN_0082d620(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int *unaff_EBX;

  wchar_t *unaff_EBP;

  int unaff_ESI;

  wchar_t *unaff_EDI;

  int *piVar3;

  int *piVar4;

  wchar_t *_Str2;

  OLECHAR *bstrString;

  int local_20;

  int *local_1c;

  OLECHAR aOStack_18 [2];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8567;

  local_c = ExceptionList;

  local_20 = 0;

  local_4 = 0;

  local_1c = (int *)0x0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))();

  iVar1 = _wcsicmp(L"BUTTON",unaff_EBP);

  if (iVar1 == 0) {

    (**(code **)(*param_2 + 0x30))(param_2);

    if (local_1c != (int *)0x0) {

      bstrString = aOStack_18;

      (**(code **)(*local_1c + 0x20))(local_1c);

      iVar1 = 0;

      if (0 < local_20) {

        do {

          _Str2 = (wchar_t *)&stack0xffffffd8;

          (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,iVar1);

          SysFreeString(bstrString);

          bstrString = (OLECHAR *)0x0;

          (**(code **)(local_20 + 0x1c))(&local_20,&stack0xffffffc4);

          iVar2 = _wcsicmp(L"START",_Str2);

          if (iVar2 == 0) {

            piVar4 = param_1 + 0x141;

            piVar3 = param_1 + 0x140;

LAB_0082d787:

            FUN_007a8b00(bstrString,piVar3,piVar4,0);

          }

          else {

            iVar2 = _wcsicmp(L"SIZE",_Str2);

            if (iVar2 == 0) {

              piVar4 = param_1 + 0x143;

              piVar3 = param_1 + 0x142;

              goto LAB_0082d787;

            }

            iVar2 = _wcsicmp(L"SPACING",_Str2);

            if (iVar2 == 0) {

              piVar4 = param_1 + 0x145;

              piVar3 = param_1 + 0x144;

              goto LAB_0082d787;

            }

          }

          (**(code **)(*(int *)bstrString + 8))(bstrString);

          iVar1 = iVar1 + 1;

        } while (iVar1 < local_20);

      }

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

    }

  }

  else {

    iVar1 = _wcsicmp(L"SIZE_SEPARATOR",unaff_EBP);

    if (iVar1 == 0) {

      FUN_007a8b00(param_2,param_1 + 0x146,param_1 + 0x147);

    }

    else {

      iVar1 = _wcsicmp(L"EXPAND_DIR_1",unaff_EBP);

      if (iVar1 == 0) {

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2);

        iVar1 = swscanf(unaff_EDI,L"%d;%d",&stack0xffffffd4,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_ESI;

        }

        (**(code **)(*param_1 + 0x46c))(unaff_ESI);

      }

      else {

        iVar1 = _wcsicmp(L"STACK_DIR",unaff_EBP);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2);

          iVar1 = swscanf(unaff_EDI,L"%d;%d",&stack0xffffffd4,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - unaff_ESI;

          }

          (**(code **)(*param_1 + 0x474))(unaff_ESI);

        }

        else {

          iVar1 = _wcsicmp(L"UNI_BUTTONS",unaff_EBP);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2);

            iVar1 = _wcsicmp(L"true",unaff_EBP);

            *(bool *)(param_1 + 0x13f) = iVar1 == 0;

          }

          else {

            FUN_007933a0(param_2);

          }

        }

      }

    }

  }

  local_c = (void *)0xffffffff;

  SysFreeString(unaff_EBP);

  ExceptionList = pvStack_14;

  return;

}
