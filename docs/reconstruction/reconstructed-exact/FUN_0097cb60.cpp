// =============================================================================
// FUN_0097cb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0097cb60
// Address:   0x0097cb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097cb60 @ 0x0097cb60
// Stable ID: aa_0097cb60
// Embedded strings (evidence for future rename):
//   - "NUM_SLICES"
//   - "%d;%d"
//   - "TOTAL_ANGLE"
//   - "%f;%f"
//   - "START_ANGLE"
//   - "CIRCLE_ALIGNMENT"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×11, return×2.
//  - Notable callees: _wcsicmp×6, SysFreeString×4, swscanf×4, FUN_0040d230×3, FUN_00863c30, FUN_0097cb60.
//  - Strings: "NUM_SLICES"; "%d;%d"; "TOTAL_ANGLE"; "%f;%f".
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



void __thiscall FUN_0097cb60(int param_1,int *param_2,int param_3)



{

  int iVar1;

  float unaff_EBX;

  BSTR unaff_EBP;

  uint32_t /* width from decompiler */ unaff_retaddr;

  int local_18;

  void *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac57e;

  local_c = ExceptionList;

  local_18 = 0;

  local_4 = 0;

  local_10 = 0;

  local_14 = (void *)g_flOne;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_18);

    iVar1 = _wcsicmp(L"NUM_SLICES",unaff_EBP);

    if (iVar1 == 0) {

      SysFreeString(unaff_EBP);

      unaff_EBP = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

      iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&local_18,0);

      if (iVar1 == 2) {

        _DAT_00000000 = (float)((int)_DAT_00000000 - local_18);

      }

      *(int *)(param_1 + 0x4b4) = local_18;

      if (local_18 < 1) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0xf;

      }

    }

    else {

      iVar1 = _wcsicmp(L"TOTAL_ANGLE",unaff_EBP);

      if (iVar1 == 0) {

        SysFreeString(unaff_EBP);

        unaff_EBP = (BSTR)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

        iVar1 = swscanf((wchar_t *)0x0,L"%f;%f",&stack0xffffffe4,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_EBX;

        }

        *(float *)(param_1 + 0x4a8) = unaff_EBX;

      }

      else {

        iVar1 = _wcsicmp(L"START_ANGLE",unaff_EBP);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

          iVar1 = swscanf(unaff_EBP,L"%f;%f",&stack0xffffffe4,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - unaff_EBX;

          }

          *(float *)(param_1 + 0x4ac) = unaff_EBX;

        }

        else {

          iVar1 = _wcsicmp(L"CIRCLE_ALIGNMENT",unaff_EBP);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

            iVar1 = swscanf(unaff_EBP,L"%d;%d",&local_18,0);

            if (iVar1 == 2) {

              _DAT_00000000 = (float)((int)_DAT_00000000 - local_18);

            }

            *(int *)(param_1 + 0x4b8) = local_18;

          }

          else {

            iVar1 = _wcsicmp(L"TEXTURE_IS_SEGMENT",unaff_EBP);

            if (iVar1 == 0) {

              FUN_0040d230();

              (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

              iVar1 = _wcsicmp(L"true",unaff_EBP);

              *(bool *)(param_1 + 0x4b0) = iVar1 == 0;

            }

            else {

              FUN_00863c30(param_2,unaff_retaddr);

            }

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_EBP);

    ExceptionList = local_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
