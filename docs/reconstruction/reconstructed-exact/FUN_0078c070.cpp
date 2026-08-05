// =============================================================================
// FUN_0078c070
// -----------------------------------------------------------------------------
// Stable ID: aa_0078c070
// Address:   0x0078c070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078c070 @ 0x0078c070
// Stable ID: aa_0078c070
// Embedded strings (evidence for future rename):
//   - "UPDATE_INTERVAL"
//   - "%d;%d"
//   - "CLEAR_COLOR"
//   - "LIGHT_DIRECTION"
//   - "HEMI_LIGHT"
//   - "COLOR_TOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×1, while×1.
//  - Notable callees: _wcsicmp×6, SysFreeString×4, FUN_007a8f80×3, FUN_0078c070, FUN_007a88b0, swscanf.
//  - Strings: "UPDATE_INTERVAL"; "%d;%d"; "CLEAR_COLOR"; "LIGHT_DIRECTION".
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



void __thiscall FUN_0078c070(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int iVar2;

  float unaff_EBX;

  wchar_t *unaff_EBP;

  float fVar3;

  float fVar4;

  float fVar5;

  int *unaff_retaddr;

  void **_Str1;

  float *bstrString;

  float local_38;

  float local_34;

  int *piStack_20;

  int *piStack_18;

  void *pvStack_14;

  void *local_c;

  int *piStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piStack_8 = (int *)&LAB_009ac2ea;

  local_c = ExceptionList;

  local_4 = 0;

  local_34 = 0.0;

  local_38 = -NAN;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = _wcsicmp(unaff_EBP,L"UPDATE_INTERVAL");

    if (iVar1 == 0) {

      SysFreeString(unaff_EBP);

      unaff_EBP = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))();

      swscanf((wchar_t *)0x0,L"%d;%d");

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x48c) = 0;

      if (*(int *)(param_1 + 0x2a4) != 0) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2a4) + 0x180) = 0;

      }

    }

    else {

      iVar1 = _wcsicmp(unaff_EBP,L"CLEAR_COLOR");

      if (iVar1 == 0) {

        FUN_007a8f80();

        *(uint8_t *)(param_1 + 0x4a0) = 1;

      }

      else {

        iVar1 = _wcsicmp(unaff_EBP,L"LIGHT_DIRECTION");

        if (iVar1 == 0) {

          FUN_007a88b0(param_2,param_1 + 0x490);

        }

        else {

          iVar1 = _wcsicmp(unaff_EBP,L"HEMI_LIGHT");

          if (iVar1 == 0) {

            *(uint8_t *)(param_1 + 0x4a1) = 1;

            (**(code **)(*param_2 + 0x30))();

            if (unaff_retaddr != (int *)0x0) {

              bstrString = &local_38;

              (**(code **)(*unaff_retaddr + 0x20))();

              iVar1 = 0;

              if (0 < (int)unaff_EBX) {

                do {

                  _Str1 = &local_c;

                  (**(code **)(*piStack_8 + 0x1c))(piStack_8,iVar1);

                  SysFreeString((BSTR)bstrString);

                  bstrString = (float *)0x0;

                  (**(code **)(*piStack_18 + 0x1c))(piStack_18,&stack0xffffffa8);

                  iVar2 = _wcsicmp((wchar_t *)_Str1,L"COLOR_TOP");

                  if (iVar2 == 0) {

                    FUN_007a8f80(piStack_20,&stack0xffffffa4);

                    fVar5 = DAT_00b017e8;

                    fVar3 = (float)((uint)unaff_retaddr >> 8 & 0xff) * DAT_00b017e8;

                    fVar4 = (float)((uint)unaff_retaddr & 0xff) * DAT_00b017e8;

                    *(float *)(param_1 + 0x4d8) =

                         (float)((uint)unaff_retaddr >> 0x10 & 0xff) * DAT_00b017e8;

                    *(float *)(param_1 + 0x4dc) = fVar3;

                    unaff_EBP = (wchar_t *)((float)((uint)unaff_retaddr >> 0x18) * fVar5);

                    *(float *)(param_1 + 0x4e0) = fVar4;

                    *(wchar_t **)(param_1 + 0x4e4) = unaff_EBP;

                  }

                  else {

                    iVar2 = _wcsicmp((wchar_t *)_Str1,L"COLOR_BOTTOM");

                    if (iVar2 == 0) {

                      FUN_007a8f80(piStack_20,&stack0xffffffa4);

                      local_34 = DAT_00b017e8;

                      unaff_EBX = (float)((uint)unaff_retaddr >> 0x10 & 0xff) * DAT_00b017e8;

                      fVar5 = (float)((uint)unaff_retaddr >> 8 & 0xff) * DAT_00b017e8;

                      local_38 = (float)((uint)unaff_retaddr & 0xff) * DAT_00b017e8;

                      *(float *)(param_1 + 0x4e8) = unaff_EBX;

                      *(float *)(param_1 + 0x4ec) = fVar5;

                      local_34 = (float)((uint)unaff_retaddr >> 0x18) * local_34;

                      *(float *)(param_1 + 0x4f0) = local_38;

                      *(float *)(param_1 + 0x4f4) = local_34;

                    }

                  }

                  (**(code **)(*piStack_20 + 8))(piStack_20);

                  iVar1 = iVar1 + 1;

                } while (iVar1 < (int)unaff_EBX);

              }

              (**(code **)(*piStack_8 + 8))(piStack_8);

            }

          }

        }

      }

    }

    SysFreeString(unaff_EBP);

    ExceptionList = pvStack_14;

    return;

  }

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
