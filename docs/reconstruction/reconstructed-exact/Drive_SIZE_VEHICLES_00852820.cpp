// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×14, return×1.
//  - Notable callees: _wcsicmp×9, FUN_007a8b00×5, SysFreeString×4, swscanf×3, FUN_0040d230×2, FUN_00402d50, FUN_007933a0, FUN_0084fd60.
//  - Strings: "ZOOM_FACTOR"; "%f;%f"; "BLIP_LENGTH"; "LABEL_OFFSET".
//  - Return sites: 1.

// =============================================================================
// Drive_SIZE_VEHICLES_00852820
// -----------------------------------------------------------------------------
// Stable ID: aa_00852820
// Address:   0x00852820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "SIZE_VEHICLES"
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



void __thiscall Drive_SIZE_VEHICLES_00852820(int param_1,int *param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  wchar_t *local_98;

  float local_94;

  uint8_t *puStack_90;

  uint8_t auStack_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009b8676;

  local_c = ExceptionList;

  local_98 = (wchar_t *)0x0;

  local_4 = 0;

  local_94 = g_flOne;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

  }

  else {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_98);

    iVar1 = _wcsicmp(L"ZOOM_FACTOR",local_98);

    if (iVar1 == 0) {

      SysFreeString(local_98);

      local_98 = (wchar_t *)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&local_98);

      iVar1 = swscanf(local_98,L"%f;%f",&local_94,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - local_94;

      }

      FUN_0084fd60();

    }

    else {

      iVar1 = _wcsicmp(L"BLIP_LENGTH",local_98);

      if (iVar1 == 0) {

        SysFreeString(local_98);

        local_98 = (wchar_t *)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&local_98);

        iVar1 = swscanf(local_98,L"%f;%f",&local_94,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - local_94;

        }

        *(float *)(param_1 + 0x508) = local_94;

        *(float *)(param_1 + 0x50c) = local_94 / *(float *)(param_1 + 0x504);

      }

      else {

        iVar1 = _wcsicmp(L"LABEL_OFFSET",local_98);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2,&local_98);

          iVar1 = swscanf(local_98,L"%f;%f",&local_94,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - local_94;

          }

          *(float *)(param_1 + 0x510) = (float)DAT_00d1e818 * local_94 * DAT_00aaa67c;

        }

        else {

          iVar1 = _wcsicmp(L"TEXTURE_ICON_YOU",local_98);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2,&local_98);

            puVar2 = (uint32_t /* width from decompiler */ *)FUN_00402d50(local_98);

            local_4._0_1_ = 1;

            FUN_008509e0(*puVar2);

            local_4 = (uint)local_4._1_3_ << 8;

            if (puStack_90 != auStack_8c) {

              free(puStack_90);

            }

          }

          else {

            iVar1 = _wcsicmp(L"SIZE_BUILDINGS",local_98);

            if (iVar1 == 0) {

              FUN_007a8b00(param_2,param_1 + 0x540,param_1 + 0x544,0);

            }

            else {

              iVar1 = _wcsicmp(L"SIZE_CHARACTERS",local_98);

              if (iVar1 == 0) {

                FUN_007a8b00(param_2,param_1 + 0x548,param_1 + 0x54c,0);

              }

              else {

                iVar1 = _wcsicmp(L"SIZE_CREATURES",local_98);

                if (iVar1 == 0) {

                  FUN_007a8b00(param_2,param_1 + 0x550,param_1 + 0x554,0);

                }

                else {

                  iVar1 = _wcsicmp(L"SIZE_VEHICLES",local_98);

                  if (iVar1 == 0) {

                    FUN_007a8b00(param_2,param_1 + 0x558,param_1 + 0x55c,0);

                  }

                  else {

                    iVar1 = _wcsicmp(L"SIZE_WAYPOINTS",local_98);

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

    local_4 = 0xffffffff;

    SysFreeString(local_98);

  }

  ExceptionList = local_c;

  return;

}
