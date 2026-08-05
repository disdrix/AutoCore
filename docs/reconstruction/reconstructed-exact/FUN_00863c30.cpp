// =============================================================================
// FUN_00863c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00863c30
// Address:   0x00863c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00863c30 @ 0x00863c30
// Stable ID: aa_00863c30
// Embedded strings (evidence for future rename):
//   - "SPEED"
//   - "%f;%f"
//   - "PERCENT_FULL"
//   - "SCALE"
//   - "CAN_DECREASE"
//   - "true"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: _wcsicmp×5, SysFreeString×4, swscanf×2, FUN_0040d230, FUN_007a88b0, FUN_00863c30.
//  - Strings: "SPEED"; "%f;%f"; "PERCENT_FULL"; "SCALE".
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



void __thiscall FUN_00863c30(int *param_1,int *param_2,int param_3)



{

  float fVar1;

  int iVar2;

  BSTR unaff_EBP;

  float unaff_ESI;

  wchar_t *unaff_EDI;

  void *local_14;

  float local_10;

  void *local_c;

  uint8_t *puStack_8;

  float local_4;

  

  puStack_8 = &LAB_009abc68;

  local_c = ExceptionList;

  local_14 = (void *)0x0;

  local_4 = 0.0;

  local_10 = g_flOne;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_14);

    iVar2 = _wcsicmp(L"SPEED",unaff_EBP);

    if (iVar2 == 0) {

      SysFreeString(unaff_EBP);

      unaff_EBP = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe4);

      iVar2 = swscanf(unaff_EDI,L"%f;%f",&stack0xffffffe0,0);

      if (iVar2 == 2) {

        _DAT_00000000 = _DAT_00000000 - unaff_ESI;

      }

      local_c = (void *)((float)DAT_00d1e81c * unaff_ESI * DAT_00aaa678);

      (**(code **)(*param_1 + 0x3b4))(local_c);

    }

    else {

      iVar2 = _wcsicmp(L"PERCENT_FULL",unaff_EBP);

      if (iVar2 == 0) {

        SysFreeString(unaff_EBP);

        unaff_EBP = (BSTR)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe4);

        iVar2 = swscanf(unaff_EDI,L"%f;%f",&stack0xffffffe0,0);

        if (iVar2 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_ESI;

        }

        (**(code **)(*param_1 + 0x3b0))(unaff_ESI);

      }

      else {

        iVar2 = _wcsicmp(L"SCALE",unaff_EBP);

        fVar1 = DAT_00aaa6b0;

        if (iVar2 == 0) {

          local_4 = DAT_00aaa6b0;

          FUN_007a88b0(param_2,&stack0xffffffe8,&local_4,0);

          if (fVar1 != DAT_00aaa6b0) {

            (**(code **)(*param_1 + 0x3b8))(fVar1);

          }

          if (local_4 != DAT_00aaa6b0) {

            (**(code **)(*param_1 + 0x3bc))(local_4);

          }

        }

        else {

          iVar2 = _wcsicmp(L"CAN_DECREASE",unaff_EBP);

          if (iVar2 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe4);

            iVar2 = _wcsicmp(L"true",unaff_EBP);

            *(bool *)(param_1 + 0x129) = iVar2 == 0;

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_EBP);

    ExceptionList = local_14;

    return;

  }

  local_4 = -NAN;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
