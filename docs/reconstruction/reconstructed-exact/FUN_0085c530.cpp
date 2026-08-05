// =============================================================================
// FUN_0085c530
// -----------------------------------------------------------------------------
// Stable ID: aa_0085c530
// Address:   0x0085c530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085c530 @ 0x0085c530
// Stable ID: aa_0085c530
// Embedded strings (evidence for future rename):
//   - "ZOOM_FACTOR"
//   - "%f;%f"
//   - "BLIP_LENGTH"
//   - "LABEL_OFFSET"
//   - "NUM_SLICES"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×16, return×1.
//  - Notable callees: _wcsicmp×10, FUN_007a8b00×5, SysFreeString×4, swscanf×4, FUN_0040d230×3, FUN_00402d50, FUN_007933a0, FUN_00857b90.
//  - Strings: "ZOOM_FACTOR"; "%f;%f"; "BLIP_LENGTH"; "LABEL_OFFSET".
//  - Return sites: 1.

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



void __thiscall FUN_0085c530(int param_1,int *param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  wchar_t *local_9c;

  float local_98;

  int local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b874e;

  local_c = ExceptionList;

  local_9c = (wchar_t *)0x0;

  local_4 = 0;

  local_94 = 0;

  local_98 = g_flOne;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

  }

  else {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_9c);

    iVar1 = _wcsicmp(L"ZOOM_FACTOR",local_9c);

    if (iVar1 == 0) {

      SysFreeString(local_9c);

      local_9c = (wchar_t *)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

      iVar1 = swscanf(local_9c,L"%f;%f",&local_98,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - local_98;

      }

      FUN_00857b90();

    }

    else {

      iVar1 = _wcsicmp(L"BLIP_LENGTH",local_9c);

      if (iVar1 == 0) {

        SysFreeString(local_9c);

        local_9c = (wchar_t *)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

        iVar1 = swscanf(local_9c,L"%f;%f",&local_98,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - local_98;

        }

        *(float *)(param_1 + 0x508) = local_98;

        *(float *)(param_1 + 0x50c) = local_98 / *(float *)(param_1 + 0x504);

      }

      else {

        iVar1 = _wcsicmp(L"LABEL_OFFSET",local_9c);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

          iVar1 = swscanf(local_9c,L"%f;%f",&local_98,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - local_98;

          }

          *(float *)(param_1 + 0x510) = (float)DAT_00d1e818 * local_98 * DAT_00aaa67c;

        }

        else {

          iVar1 = _wcsicmp(L"NUM_SLICES",local_9c);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

            iVar1 = swscanf(local_9c,L"%d;%d",&local_94,0);

            if (iVar1 == 2) {

              _DAT_00000000 = (float)((int)_DAT_00000000 - local_94);

            }

            FUN_00857d80(local_94);

          }

          else {

            iVar1 = _wcsicmp(L"TEXTURE_ICON_YOU",local_9c);

            if (iVar1 == 0) {

              FUN_0040d230();

              (**(code **)(*param_2 + 0x68))(param_2,&local_9c);

              puVar2 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_9c);

              local_4._0_1_ = 1;

              FUN_00858550(*puVar2);

              local_4 = (uint)local_4._1_3_ << 8;

              if (puStack_90 != auStack_8c) {

                free(puStack_90);

              }

            }

            else {

              iVar1 = _wcsicmp(L"SIZE_BUILDINGS",local_9c);

              if (iVar1 == 0) {

                FUN_007a8b00(param_2,param_1 + 0x540,param_1 + 0x544,0);

              }

              else {

                iVar1 = _wcsicmp(L"SIZE_CHARACTERS",local_9c);

                if (iVar1 == 0) {

                  FUN_007a8b00(param_2,param_1 + 0x548,param_1 + 0x54c,0);

                }

                else {

                  iVar1 = _wcsicmp(L"SIZE_CREATURES",local_9c);

                  if (iVar1 == 0) {

                    FUN_007a8b00(param_2,param_1 + 0x550,param_1 + 0x554,0);

                  }

                  else {

                    iVar1 = _wcsicmp(L"SIZE_VEHICLES",local_9c);

                    if (iVar1 == 0) {

                      FUN_007a8b00(param_2,param_1 + 0x558,param_1 + 0x55c,0);

                    }

                    else {

                      iVar1 = _wcsicmp(L"SIZE_WAYPOINTS",local_9c);

                      if (iVar1 == 0) {

                        FUN_007a8b00(param_2,param_1 + 0x560,param_1 + 0x564,0);

                      }

                      else {

                        FUN_007933a0(param_2,param_3);

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

    local_4 = 0xffffffff;

    SysFreeString(local_9c);

  }

  ExceptionList = local_c;

  return;

}
