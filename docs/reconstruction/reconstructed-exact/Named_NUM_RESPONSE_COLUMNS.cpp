// READABILITY (auto CF):
//  - Body size: ~156 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: block×59, wcscmp×8, SysFreeString×3, swscanf×3, FUN_0040d230×2, FUN_007933a0, FUN_008ac890, FUN_008ac8b0.
//  - Strings: "RESPONSE_WINDOW"; "NUM_RESPONSES"; "%d;%d"; "NUM_ITEM_COLUMNS".
//  - Return sites: 2.

// =============================================================================
// Named_NUM_RESPONSE_COLUMNS
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac8b0
// Address:   0x008ac8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "NUM_RESPONSE_COLUMNS"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x008acc24) */

/* WARNING: Removing unreachable block (ram,0x008acc3b) */

/* WARNING: Removing unreachable block (ram,0x008acc40) */

/* WARNING: Removing unreachable block (ram,0x008acc91) */

/* WARNING: Removing unreachable block (ram,0x008acca4) */

/* WARNING: Removing unreachable block (ram,0x008accba) */

/* WARNING: Removing unreachable block (ram,0x008acccd) */

/* WARNING: Removing unreachable block (ram,0x008acc7b) */

/* WARNING: Removing unreachable block (ram,0x008acce1) */

/* WARNING: Removing unreachable block (ram,0x008acce6) */

/* WARNING: Removing unreachable block (ram,0x008accfd) */

/* WARNING: Removing unreachable block (ram,0x008ace67) */

/* WARNING: Removing unreachable block (ram,0x008ace7e) */

/* WARNING: Removing unreachable block (ram,0x008ace80) */

/* WARNING: Removing unreachable block (ram,0x008aced1) */

/* WARNING: Removing unreachable block (ram,0x008acee4) */

/* WARNING: Removing unreachable block (ram,0x008acefa) */

/* WARNING: Removing unreachable block (ram,0x008acf0d) */

/* WARNING: Removing unreachable block (ram,0x008acebb) */

/* WARNING: Removing unreachable block (ram,0x008acf21) */

/* WARNING: Removing unreachable block (ram,0x008acf26) */

/* WARNING: Removing unreachable block (ram,0x008acf3d) */

/* WARNING: Removing unreachable block (ram,0x008acd47) */

/* WARNING: Removing unreachable block (ram,0x008acd5e) */

/* WARNING: Removing unreachable block (ram,0x008acd60) */

/* WARNING: Removing unreachable block (ram,0x008acdb1) */

/* WARNING: Removing unreachable block (ram,0x008acdc4) */

/* WARNING: Removing unreachable block (ram,0x008acdda) */

/* WARNING: Removing unreachable block (ram,0x008acded) */

/* WARNING: Removing unreachable block (ram,0x008acd9b) */

/* WARNING: Removing unreachable block (ram,0x008ace01) */

/* WARNING: Removing unreachable block (ram,0x008ace06) */

/* WARNING: Removing unreachable block (ram,0x008ace1d) */

/* WARNING: Removing unreachable block (ram,0x008ac959) */

/* WARNING: Removing unreachable block (ram,0x008ac970) */

/* WARNING: Removing unreachable block (ram,0x008ac9ca) */

/* WARNING: Removing unreachable block (ram,0x008ac9dd) */

/* WARNING: Removing unreachable block (ram,0x008ac9eb) */

/* WARNING: Removing unreachable block (ram,0x008ac9fe) */

/* WARNING: Removing unreachable block (ram,0x008aca14) */

/* WARNING: Removing unreachable block (ram,0x008aca27) */

/* WARNING: Removing unreachable block (ram,0x008aca3d) */

/* WARNING: Removing unreachable block (ram,0x008aca50) */

/* WARNING: Removing unreachable block (ram,0x008aca5c) */

/* WARNING: Removing unreachable block (ram,0x008ac9b1) */

/* WARNING: Removing unreachable block (ram,0x008aca64) */

/* WARNING: Removing unreachable block (ram,0x008aca69) */

/* WARNING: Removing unreachable block (ram,0x008aca80) */

/* WARNING: Removing unreachable block (ram,0x008acf87) */

/* WARNING: Removing unreachable block (ram,0x008acf9e) */

/* WARNING: Removing unreachable block (ram,0x008acfa0) */

/* WARNING: Removing unreachable block (ram,0x008acff1) */

/* WARNING: Removing unreachable block (ram,0x008ad004) */

/* WARNING: Removing unreachable block (ram,0x008ad01a) */

/* WARNING: Removing unreachable block (ram,0x008ad02d) */

/* WARNING: Removing unreachable block (ram,0x008acfdb) */

/* WARNING: Removing unreachable block (ram,0x008ad041) */

/* WARNING: Removing unreachable block (ram,0x008ad046) */

/* WARNING: Removing unreachable block (ram,0x008ad05d) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_NUM_RESPONSE_COLUMNS(int param_1,int *param_2,int param_3)



{

  int iVar1;

  BSTR unaff_ESI;

  int iStack_18;

  void *pvStack_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b99a5;

  local_c = ExceptionList;

  local_4 = 0;

  local_10 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))();

    iVar1 = wcscmp(L"RESPONSE_WINDOW",unaff_ESI);

    if (iVar1 == 0) {

      (**(code **)(*param_2 + 0x30))(param_2);

    }

    else {

      iVar1 = wcscmp(L"NUM_RESPONSES",unaff_ESI);

      if (iVar1 == 0) {

        SysFreeString(unaff_ESI);

        (**(code **)(*param_2 + 0x68))(param_2);

        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&iStack_18);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - iStack_18;

        }

        FUN_008ac890();

        unaff_ESI = (BSTR)0x0;

      }

      else {

        iVar1 = wcscmp(L"NUM_ITEM_COLUMNS",unaff_ESI);

        if (iVar1 == 0) {

          FUN_0040d230();

          (**(code **)(*param_2 + 0x68))(param_2);

          iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - iStack_18;

          }

          *(int *)(param_1 + 0x63c) = iStack_18;

        }

        else {

          iVar1 = wcscmp(L"NUM_RESPONSE_COLUMNS",unaff_ESI);

          if (iVar1 == 0) {

            FUN_0040d230();

            (**(code **)(*param_2 + 0x68))(param_2);

            iVar1 = swscanf(unaff_ESI,L"%d;%d",&iStack_18);

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - iStack_18;

            }

            *(int *)(param_1 + 0x640) = iStack_18;

          }

          else {

            iVar1 = wcscmp(L"ITEM_BTN",unaff_ESI);

            if (iVar1 == 0) {

              (**(code **)(*param_2 + 0x30))(param_2);

            }

            else {

              iVar1 = wcscmp(L"ITEM_WINDOW",unaff_ESI);

              if (iVar1 == 0) {

                (**(code **)(*param_2 + 0x30))(param_2);

              }

              else {

                iVar1 = wcscmp(L"ITEM_WINDOW_BG",unaff_ESI);

                if (iVar1 == 0) {

                  (**(code **)(*param_2 + 0x30))(param_2);

                }

                else {

                  iVar1 = wcscmp(L"ITEM_TEXT",unaff_ESI);

                  if (iVar1 == 0) {

                    (**(code **)(*param_2 + 0x30))(param_2);

                  }

                  else {

                    FUN_007933a0(param_2);

                  }

                }

              }

            }

          }

        }

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = pvStack_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
