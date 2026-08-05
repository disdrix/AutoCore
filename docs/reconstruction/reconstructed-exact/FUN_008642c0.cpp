// =============================================================================
// FUN_008642c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008642c0
// Address:   0x008642c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008642c0 @ 0x008642c0
// Stable ID: aa_008642c0
// Embedded strings (evidence for future rename):
//   - "SPEED"
//   - "%f;%f"
//   - "SIZE_STRIP_Y"
//   - "OFFSET_RIGHT_Y"
//   - "DELAY"
//   - "PIXEL_LINES_FREQUENCY"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×17, return×2.
//  - Notable callees: _wcsicmp×11, FUN_0040d230×7, swscanf×7, SysFreeString×4, FUN_008642c0.
//  - Strings: "SPEED"; "%f;%f"; "SIZE_STRIP_Y"; "OFFSET_RIGHT_Y".
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



void __thiscall FUN_008642c0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  float unaff_EBX;

  BSTR unaff_EBP;

  int local_18;

  void *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009abc7a;

  local_c = ExceptionList;

  local_18 = 0;

  local_4 = 0;

  local_10 = 0;

  local_14 = (void *)g_flOne;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_18);

    iVar1 = _wcsicmp(L"SPEED",unaff_EBP);

    if (iVar1 == 0) {

      SysFreeString(unaff_EBP);

      unaff_EBP = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

      iVar1 = swscanf((wchar_t *)0x0,L"%f;%f",&stack0xffffffe4,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - unaff_EBX;

      }

      *(float *)(param_1 + 0x4a8) = (float)DAT_00d1e81c * unaff_EBX * DAT_00aaa678;

    }

    else {

      iVar1 = _wcsicmp(L"SIZE_STRIP_Y",unaff_EBP);

      if (iVar1 == 0) {

        SysFreeString(unaff_EBP);

        unaff_EBP = (BSTR)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

        iVar1 = swscanf((wchar_t *)0x0,L"%f;%f",&stack0xffffffe4,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_EBX;

        }

        *(float *)(param_1 + 0x4b0) = (float)DAT_00d1e81c * unaff_EBX * DAT_00aaa678;

      }

      else {

        iVar1 = _wcsicmp(L"OFFSET_RIGHT_Y",unaff_EBP);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

          iVar1 = swscanf(unaff_EBP,L"%f;%f",&stack0xffffffe4,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - unaff_EBX;

          }

          *(float *)(param_1 + 0x4b4) = (float)DAT_00d1e81c * unaff_EBX * DAT_00aaa678;

        }

        else {

          iVar1 = _wcsicmp(L"DELAY",unaff_EBP);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

            iVar1 = swscanf(unaff_EBP,L"%f;%f",&stack0xffffffe4,0);

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - unaff_EBX;

            }

            *(float *)(param_1 + 0x4a4) = (float)DAT_00d1e81c * unaff_EBX * DAT_00aaa678;

          }

          else {

            iVar1 = _wcsicmp(L"PIXEL_LINES_FREQUENCY",unaff_EBP);

            if (iVar1 == 0) {

              FUN_0040d230();

              (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

              iVar1 = swscanf(unaff_EBP,L"%d;%d",&local_18,0);

              if (iVar1 == 2) {

                _DAT_00000000 = (float)((int)_DAT_00000000 - local_18);

              }

              *(int *)(param_1 + 0x48c) = local_18;

            }

            else {

              iVar1 = _wcsicmp(L"MORPH_FREQUENCY",unaff_EBP);

              if (iVar1 == 0) {

                FUN_0040d230();

                (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

                iVar1 = swscanf(unaff_EBP,L"%d;%d",&local_18,0);

                if (iVar1 == 2) {

                  _DAT_00000000 = (float)((int)_DAT_00000000 - local_18);

                }

                *(int *)(param_1 + 0x490) = local_18;

              }

              else {

                iVar1 = _wcsicmp(L"MORPH_SPEED",unaff_EBP);

                if (iVar1 == 0) {

                  FUN_0040d230();

                  (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

                  iVar1 = swscanf(unaff_EBP,L"%f;%f",&stack0xffffffe4,0);

                  if (iVar1 == 2) {

                    _DAT_00000000 = _DAT_00000000 - unaff_EBX;

                  }

                  *(float *)(param_1 + 0x4b8) = (float)DAT_00d1e81c * unaff_EBX * DAT_00aaa678;

                }

                else {

                  iVar1 = _wcsicmp(L"IS_CIRCLE",unaff_EBP);

                  if (iVar1 == 0) {

                    FUN_0040d230();

                    (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

                    iVar1 = _wcsicmp(L"true",unaff_EBP);

                    *(bool *)(param_1 + 0x488) = iVar1 == 0;

                  }

                  else {

                    iVar1 = _wcsicmp(L"DRAW_BAND",unaff_EBP);

                    if (iVar1 == 0) {

                      FUN_0040d230();

                      (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe0);

                      iVar1 = _wcsicmp(L"true",unaff_EBP);

                      *(bool *)(param_1 + 0x489) = iVar1 == 0;

                    }

                  }

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
