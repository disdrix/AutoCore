// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×15, goto×4, return×2, for×1, do×1, while×1.
//  - Notable callees: _wcsicmp×9, SysFreeString×5, swscanf×3, FUN_0040d230×2, FUN_007933a0, FUN_007a8b00, FUN_0083d4c0.
//  - Strings: "NUM_SKILLS_1"; "%d;%d"; "NUM_SKILLS_2"; "NUM_SKILLS_3".
//  - Return sites: 2.

// =============================================================================
// Skill_NUM_SKILLS_1_0083d4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083d4c0
// Address:   0x0083d4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "NUM_SKILLS_1"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe0 : 0x0083d71c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

/* WARNING: Exceeded maximum restarts with more pending */



void __thiscall Skill_NUM_SKILLS_1_0083d4c0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int *unaff_EBP;

  BSTR unaff_ESI;

  int *piVar2;

  float fVar3;

  wchar_t *_Str2;

  OLECHAR *bstrString;

  int local_20;

  int *local_1c;

  OLECHAR aOStack_18 [2];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8615;

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

  iVar1 = _wcsicmp(L"NUM_SKILLS_1",unaff_ESI);

  if (iVar1 == 0) {

    SysFreeString(unaff_ESI);

    (**(code **)(*param_2 + 0x68))(param_2);

    iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffdc);

    if (iVar1 == 2) {

      _DAT_00000000 = _DAT_00000000 - (int)unaff_EBP;

    }

    *(int **)(param_1 + 0x4fc) = unaff_EBP;

    unaff_ESI = (BSTR)0x0;

  }

  else {

    iVar1 = _wcsicmp(L"NUM_SKILLS_2",unaff_ESI);

    if (iVar1 == 0) {

      SysFreeString(unaff_ESI);

      (**(code **)(*param_2 + 0x68))(param_2);

      iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffdc);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - (int)unaff_EBP;

      }

      *(int **)(param_1 + 0x500) = unaff_EBP;

      unaff_ESI = (BSTR)0x0;

    }

    else {

      iVar1 = _wcsicmp(L"NUM_SKILLS_3",unaff_ESI);

      if (iVar1 == 0) {

        FUN_0040d230();

        (**(code **)(*param_2 + 0x68))(param_2);

        iVar1 = swscanf(unaff_ESI,L"%d;%d",&stack0xffffffdc);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - (int)unaff_EBP;

        }

        *(int **)(param_1 + 0x504) = unaff_EBP;

      }

      else {

        iVar1 = _wcsicmp(L"SKILL_WINDOW",unaff_ESI);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x30))(param_2);

          if (local_1c != (int *)0x0) {

            bstrString = aOStack_18;

            (**(code **)(*local_1c + 0x20))(local_1c);

            local_c = (void *)0x0;

            if (0 < local_20) {

              do {

                _Str2 = (wchar_t *)&stack0xffffffd8;

                (**(code **)(*unaff_EBP + 0x1c))(unaff_EBP,local_c);

                SysFreeString(bstrString);

                bstrString = (OLECHAR *)0x0;

                (**(code **)(local_20 + 0x1c))(&local_20,&stack0xffffffc4);

                iVar1 = _wcsicmp(L"START_1",_Str2);

                if (iVar1 == 0) {

                  piVar2 = (int *)(param_1 + 0x508);

                  iVar1 = param_1 + 0x50c;

LAB_0083d7c8:

                  FUN_007a8b00(bstrString,piVar2,iVar1,0);

                  fVar3 = (float)piVar2[1] * (float)DAT_00d1e81c * DAT_00aaa678;

                  *piVar2 = (int)((float)*piVar2 * (float)DAT_00d1e818 * DAT_00aaa67c);

                  piVar2[1] = (int)fVar3;

                }

                else {

                  iVar1 = _wcsicmp(L"START_2",_Str2);

                  if (iVar1 == 0) {

                    piVar2 = (int *)(param_1 + 0x510);

                    iVar1 = param_1 + 0x514;

                    goto LAB_0083d7c8;

                  }

                  iVar1 = _wcsicmp(L"START_3",_Str2);

                  if (iVar1 == 0) {

                    piVar2 = (int *)(param_1 + 0x518);

                    iVar1 = param_1 + 0x51c;

                    goto LAB_0083d7c8;

                  }

                  iVar1 = _wcsicmp(L"SIZE",_Str2);

                  if (iVar1 == 0) {

                    piVar2 = (int *)(param_1 + 0x520);

                    iVar1 = param_1 + 0x524;

                    goto LAB_0083d7c8;

                  }

                  iVar1 = _wcsicmp(L"SPACING",_Str2);

                  if (iVar1 == 0) {

                    piVar2 = (int *)(param_1 + 0x528);

                    iVar1 = param_1 + 0x52c;

                    goto LAB_0083d7c8;

                  }

                }

                (**(code **)(*(int *)bstrString + 8))(bstrString);

                local_c = (void *)((int)local_c + 1);

              } while ((int)local_c < local_20);

            }

            (**(code **)(*unaff_EBP + 8))(unaff_EBP);

          }

        }

        else {

          FUN_007933a0(param_2);

        }

      }

    }

  }

  local_c = (void *)0xffffffff;

  SysFreeString(unaff_ESI);

  ExceptionList = pvStack_14;

  return;

}
