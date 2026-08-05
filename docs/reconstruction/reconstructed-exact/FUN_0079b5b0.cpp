// =============================================================================
// FUN_0079b5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079b5b0
// Address:   0x0079b5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079b5b0 @ 0x0079b5b0
// Stable ID: aa_0079b5b0
// Embedded strings (evidence for future rename):
//   - "IS_TRANSPARENT"
//   - "true"
//   - "TEXTURE_BASE_NAME"
//   - "DOWN_SIZE_RATIO"
//   - "%f;%f"
//   - "RADIO_FREQ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×18, return×8, goto×1.
//  - Notable callees: _wcsicmp×17, SysFreeString×10, FUN_0040d230×4, swscanf×2, CONCAT31, FUN_00402d50, FUN_0079b5b0, FUN_007a8f80.
//  - Strings: "IS_TRANSPARENT"; "true"; "TEXTURE_BASE_NAME"; "DOWN_SIZE_RATIO".
//  - Return sites: 8.

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



void __thiscall FUN_0079b5b0(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ unaff_ESI;

  wchar_t *local_9c;

  float local_98;

  int local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac364;

  local_c = ExceptionList;

  local_9c = (wchar_t *)0x0;

  local_4 = 0;

  local_98 = g_flOne;

  local_94 = -1;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2,&local_9c);

  iVar1 = _wcsicmp(local_9c,L"IS_TRANSPARENT");

  if (iVar1 == 0) {

    SysFreeString(local_9c);

    local_9c = (wchar_t *)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

    iVar1 = _wcsicmp(local_9c,L"true");

    *(bool *)(param_1 + 0x122) = iVar1 == 0;

    SysFreeString(local_9c);

    ExceptionList = local_c;

    return;

  }

  iVar1 = _wcsicmp(local_9c,L"TEXTURE_BASE_NAME");

  if (iVar1 == 0) {

    SysFreeString(local_9c);

    local_9c = (BSTR)0x0;

    (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00402d50(unaff_ESI);

    local_c = (void *)CONCAT31(local_c._1_3_,1);

    (**(code **)(*param_1 + 0x3ac))(*puVar2);

    if (puStack_90 != auStack_8c) {

      free(puStack_90);

      SysFreeString(local_9c);

      ExceptionList = local_c;

      return;

    }

  }

  else {

    iVar1 = _wcsicmp(local_9c,L"DOWN_SIZE_RATIO");

    if (iVar1 == 0) {

      FUN_0040d230();

      (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

      iVar1 = swscanf(local_9c,L"%f;%f",&local_98,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - local_98;

      }

      param_1[0x131] = (int)local_98;

      SysFreeString(local_9c);

      ExceptionList = local_c;

      return;

    }

    iVar1 = _wcsicmp(local_9c,L"RADIO_FREQ");

    if (iVar1 == 0) {

      FUN_0040d230();

      (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

      iVar1 = swscanf(local_9c,L"%d;%d",&local_94,0);

      if (iVar1 == 2) {

        _DAT_00000000 = (float)((int)_DAT_00000000 - local_94);

      }

      param_1[0x126] = local_94;

      SysFreeString(local_9c);

      ExceptionList = local_c;

      return;

    }

    iVar1 = _wcsicmp(local_9c,L"LOCK_COLORS");

    if (iVar1 == 0) {

      FUN_0040d230();

      (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

      iVar1 = _wcsicmp(local_9c,L"true");

      *(bool *)((int)param_1 + 0x489) = iVar1 == 0;

      SysFreeString(local_9c);

      ExceptionList = local_c;

      return;

    }

    iVar1 = _wcsicmp(local_9c,L"IS_TOGGLE");

    if (iVar1 == 0) {

      FUN_0040d230();

      (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

      iVar1 = _wcsicmp(local_9c,L"true");

      *(bool *)((int)param_1 + 0x48a) = iVar1 == 0;

      SysFreeString(local_9c);

      ExceptionList = local_c;

      return;

    }

    iVar1 = _wcsicmp(local_9c,L"BG_COLOR_OVER");

    if (iVar1 == 0) {

      param_1 = param_1 + 0x129;

    }

    else {

      iVar1 = _wcsicmp(local_9c,L"BG_COLOR_DOWN");

      if (iVar1 == 0) {

        param_1 = param_1 + 0x12a;

      }

      else {

        iVar1 = _wcsicmp(local_9c,L"BG_COLOR_ON");

        if (iVar1 == 0) {

          param_1 = param_1 + 299;

        }

        else {

          iVar1 = _wcsicmp(local_9c,L"BG_COLOR_DISABLED");

          if (iVar1 == 0) {

            param_1 = param_1 + 300;

          }

          else {

            iVar1 = _wcsicmp(local_9c,L"FG_COLOR_OVER");

            if (iVar1 == 0) {

              param_1 = param_1 + 0x12d;

            }

            else {

              iVar1 = _wcsicmp(local_9c,L"FG_COLOR_DOWN");

              if (iVar1 == 0) {

                param_1 = param_1 + 0x12e;

              }

              else {

                iVar1 = _wcsicmp(local_9c,L"FG_COLOR_ON");

                if (iVar1 == 0) {

                  param_1 = param_1 + 0x12f;

                }

                else {

                  iVar1 = _wcsicmp(local_9c,L"FG_COLOR_DISABLED");

                  if (iVar1 != 0) goto LAB_0079b966;

                  param_1 = param_1 + 0x130;

                }

              }

            }

          }

        }

      }

    }

    FUN_007a8f80(param_2,param_1);

  }

LAB_0079b966:

  SysFreeString(local_9c);

  ExceptionList = local_c;

  return;

}
