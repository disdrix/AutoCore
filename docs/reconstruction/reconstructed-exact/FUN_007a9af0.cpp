// =============================================================================
// FUN_007a9af0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a9af0
// Address:   0x007a9af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a9af0 @ 0x007a9af0
// Stable ID: aa_007a9af0
// Embedded strings (evidence for future rename):
//   - "EFFECT"
//   - "%d;%d"
//   - "SPEED"
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, for×1, do×1, while×1.
//  - Notable callees: SysFreeString×5, swscanf×2, wcscmp×2, FUN_007a9af0.
//  - Strings: "EFFECT"; "%d;%d"; "SPEED"; "%f;%f".
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

/* WARNING: Restarted to delay deadcode elimination for space: stack */



void FUN_007a9af0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int *unaff_EBP;

  int unaff_EDI;

  BSTR unaff_retaddr;

  int *piStack_38;

  int *piStack_34;

  int iStack_2c;

  int *piStack_20;

  wchar_t *pwStack_1c;

  int local_18;

  BSTR apOStack_14 [2];

  BSTR pOStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aba3b;

  pOStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pOStack_c;

  (**(code **)(*param_2 + 0x30))();

  if (piStack_20 != (int *)0x0) {

    piStack_34 = &local_18;

    piStack_38 = piStack_20;

    (**(code **)(*piStack_20 + 0x20))();

    iStack_2c = 0;

    if (0 < (int)piStack_20) {

      do {

        (**(code **)(local_18 + 0x1c))(&local_18,iStack_2c);

        SysFreeString(apOStack_14[0]);

        apOStack_14[0] = (BSTR)0x0;

        (**(code **)(*unaff_EBP + 0x1c))(unaff_EBP,apOStack_14);

        iVar1 = wcscmp(pwStack_1c,L"EFFECT");

        if (iVar1 == 0) {

          SysFreeString(pwStack_1c);

          pwStack_1c = (wchar_t *)0x0;

          (**(code **)(unaff_EDI + 0x68))(&stack0xffffffd0,&pwStack_1c);

          iVar1 = swscanf(pwStack_1c,L"%d;%d",&piStack_38,0);

          if (iVar1 == 2) {

            _DAT_00000000 = (float)((int)_DAT_00000000 - (int)piStack_38);

          }

          if ((-1 < (int)piStack_38) && ((int)piStack_38 < 3)) {

            piStack_20[0xaf] = (int)piStack_38;

          }

        }

        else {

          iVar1 = wcscmp(pwStack_1c,L"SPEED");

          if (iVar1 == 0) {

            SysFreeString(pwStack_1c);

            pwStack_1c = (wchar_t *)0x0;

            (**(code **)(unaff_EDI + 0x68))(&stack0xffffffd0,&pwStack_1c);

            iVar1 = swscanf(pwStack_1c,L"%f;%f",piStack_20 + 0xb0,0);

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - (float)piStack_20[0xb0];

            }

          }

        }

        (**(code **)(unaff_EDI + 8))(&stack0xffffffd0);

        iStack_2c = iStack_2c + 1;

      } while (iStack_2c < (int)piStack_20);

    }

    (**(code **)(local_18 + 8))(&local_18);

    SysFreeString(pOStack_c);

    ExceptionList = piStack_20;

    return;

  }

  piStack_34 = (int *)0x7a9b35;

  SysFreeString(unaff_retaddr);

  ExceptionList = apOStack_14[0];

  return;

}
