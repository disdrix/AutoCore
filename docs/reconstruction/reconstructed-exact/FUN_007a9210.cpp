// =============================================================================
// FUN_007a9210
// -----------------------------------------------------------------------------
// Stable ID: aa_007a9210
// Address:   0x007a9210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a9210 @ 0x007a9210
// Stable ID: aa_007a9210
// Embedded strings (evidence for future rename):
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×1, while×1.
//  - Notable callees: SysFreeString×7, swscanf×4, wcscmp×4, FUN_007a9210.
//  - Strings: "%f;%f".
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



void FUN_007a9210(int *param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int *unaff_EBX;

  int *unaff_EDI;

  uint8_t *puStack_44;

  int iStack_28;

  wchar_t *pwStack_20;

  int *piStack_1c;

  BSTR pOStack_18;

  void *local_14;

  void *local_c;

  uint8_t *puStack_8;

  BSTR local_4;

  

  puStack_8 = &LAB_009ab99b;

  local_c = ExceptionList;

  if (param_2 != 0) {

    local_4 = (BSTR)0x0;

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x30))();

    piVar1 = piStack_1c;

    if (piStack_1c == (int *)0x0) {

      SysFreeString(local_4);

      ExceptionList = local_14;

      return;

    }

    (**(code **)(*piStack_1c + 0x20))();

    iStack_28 = 0;

    if (0 < (int)pwStack_20) {

      do {

        puStack_44 = &stack0xffffffd4;

        (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,iStack_28);

        SysFreeString(pOStack_18);

        pOStack_18 = (BSTR)0x0;

        (**(code **)(*piVar1 + 0x1c))(piVar1,&pOStack_18);

        iVar2 = wcscmp(pwStack_20,L"R");

        if (iVar2 == 0) {

          SysFreeString(pwStack_20);

          pwStack_20 = (wchar_t *)0x0;

          (**(code **)(*unaff_EDI + 0x68))(unaff_EDI,&pwStack_20);

          iVar2 = swscanf(pwStack_20,L"%f;%f",&puStack_44,0);

          if (iVar2 == 2) {

            _DAT_00000000 = _DAT_00000000 - (float)puStack_44;

          }

          *piStack_1c = (int)puStack_44;

        }

        else {

          iVar2 = wcscmp(pwStack_20,L"G");

          if (iVar2 == 0) {

            SysFreeString(pwStack_20);

            pwStack_20 = (wchar_t *)0x0;

            (**(code **)(*unaff_EDI + 0x68))(unaff_EDI,&pwStack_20);

            iVar2 = swscanf(pwStack_20,L"%f;%f",&puStack_44,0);

            if (iVar2 == 2) {

              _DAT_00000000 = _DAT_00000000 - (float)puStack_44;

            }

            piStack_1c[1] = (int)puStack_44;

          }

          else {

            iVar2 = wcscmp(pwStack_20,L"B");

            if (iVar2 == 0) {

              SysFreeString(pwStack_20);

              pwStack_20 = (wchar_t *)0x0;

              (**(code **)(*unaff_EDI + 0x68))(unaff_EDI,&pwStack_20);

              iVar2 = swscanf(pwStack_20,L"%f;%f",&puStack_44,0);

              if (iVar2 == 2) {

                _DAT_00000000 = _DAT_00000000 - (float)puStack_44;

              }

              piStack_1c[2] = (int)puStack_44;

            }

            else {

              iVar2 = wcscmp(pwStack_20,L"A");

              if (iVar2 == 0) {

                SysFreeString(pwStack_20);

                pwStack_20 = (wchar_t *)0x0;

                (**(code **)(*unaff_EDI + 0x68))(unaff_EDI,&pwStack_20);

                iVar2 = swscanf(pwStack_20,L"%f;%f",&puStack_44,0);

                if (iVar2 == 2) {

                  _DAT_00000000 = _DAT_00000000 - (float)puStack_44;

                }

                piStack_1c[3] = (int)puStack_44;

              }

            }

          }

        }

        (**(code **)(*unaff_EDI + 8))(unaff_EDI);

        iStack_28 = iStack_28 + 1;

      } while (iStack_28 < (int)pwStack_20);

    }

    (**(code **)(*unaff_EBX + 8))();

    SysFreeString((BSTR)0x0);

  }

  ExceptionList = local_c;

  return;

}
