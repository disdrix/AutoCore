// =============================================================================
// Named_SCROLLBAR_OFFSET_MIDDLE_008f8de0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8de0
// Address:   0x008f8de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_SCROLLBAR_OFFSET_MIDDLE_008f8de0 @ 0x008f8de0
// Stable ID: aa_008f8de0
// Embedded strings (evidence for future rename):
//   - "SCROLLBAR_OFFSET_TOP"
//   - "%d;%d"
//   - "SCROLLBAR_OFFSET_MIDDLE"
//   - "SCROLLBAR_OFFSET_BOTTOM"
//   - "CHAT_RECT_BUFFER"
//   - "DIVIDER_LIMIT_TOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: _wcsicmp×7, swscanf×7, FUN_0040d230×5, SysFreeString×4, FUN_007933a0, FUN_008f8de0.
//  - Strings: "SCROLLBAR_OFFSET_TOP"; "%d;%d"; "SCROLLBAR_OFFSET_MIDDLE"; "SCROLLBAR_OFFSET_BOTTOM".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "SCROLLBAR_OFFSET_MIDDLE"
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



void Named_SCROLLBAR_OFFSET_MIDDLE_008f8de0(int *param_1,int param_2)



{

  int iVar1;

  int unaff_EBX;

  BSTR unaff_EBP;

  int local_18;

  void *local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ba925;

  local_c = ExceptionList;

  local_18 = 0;

  local_4 = 0;

  local_14 = (void *)0x0;

  if ((param_1 != (int *)0x0) && (param_2 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x1c))(param_1,&local_18);

    iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_TOP",unaff_EBP);

    if (iVar1 == 0) {

      SysFreeString(unaff_EBP);

      unaff_EBP = (BSTR)0x0;

      (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

      iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffe4,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - unaff_EBX;

      }

      *(int *)(local_18 + 0x510) = unaff_EBX;

    }

    else {

      iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_MIDDLE",unaff_EBP);

      if (iVar1 == 0) {

        SysFreeString(unaff_EBP);

        unaff_EBP = (BSTR)0x0;

        (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffe4,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_EBX;

        }

        *(int *)(local_18 + 0x514) = unaff_EBX;

      }

      else {

        iVar1 = _wcsicmp(L"SCROLLBAR_OFFSET_BOTTOM",unaff_EBP);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

          iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - unaff_EBX;

          }

          *(int *)(local_18 + 0x518) = unaff_EBX;

        }

        else {

          iVar1 = _wcsicmp(L"CHAT_RECT_BUFFER",unaff_EBP);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

            iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - unaff_EBX;

            }

            *(int *)(local_18 + 0x51c) = unaff_EBX;

          }

          else {

            iVar1 = _wcsicmp(L"DIVIDER_LIMIT_TOP",unaff_EBP);

            if (iVar1 == 0) {

              FUN_0040d230();

              (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

              iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);

              if (iVar1 == 2) {

                _DAT_00000000 = _DAT_00000000 - unaff_EBX;

              }

              *(int *)(local_18 + 0x520) = unaff_EBX;

            }

            else {

              iVar1 = _wcsicmp(L"DIVIDER_LIMIT_BOTTOM",unaff_EBP);

              if (iVar1 == 0) {

                FUN_0040d230();

                (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

                iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);

                if (iVar1 == 2) {

                  _DAT_00000000 = _DAT_00000000 - unaff_EBX;

                }

                *(int *)(local_18 + 0x524) = unaff_EBX;

              }

              else {

                iVar1 = _wcsicmp(L"DIVIDER_DEFAULT_OFFSET",unaff_EBP);

                if (iVar1 == 0) {

                  FUN_0040d230();

                  (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

                  iVar1 = swscanf(unaff_EBP,L"%d;%d",&stack0xffffffe4,0);

                  if (iVar1 == 2) {

                    _DAT_00000000 = _DAT_00000000 - unaff_EBX;

                  }

                  *(int *)(local_18 + 0x528) = unaff_EBX;

                }

                else {

                  FUN_007933a0(param_1,param_2);

                }

              }

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
