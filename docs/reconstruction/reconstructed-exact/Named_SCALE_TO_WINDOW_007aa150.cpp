// =============================================================================
// Named_SCALE_TO_WINDOW_007aa150
// -----------------------------------------------------------------------------
// Stable ID: aa_007aa150
// Address:   0x007aa150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_SCALE_TO_WINDOW_007aa150 @ 0x007aa150
// Stable ID: aa_007aa150
// Embedded strings (evidence for future rename):
//   - "NAME"
//   - "MOUSE_EVENTS"
//   - "true"
//   - "SCALE_TO_WINDOW"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×2.
//  - Notable callees: SysFreeString×6, wcscmp×4, CONCAT31, FUN_00403450, FUN_007aa150, _wcsicmp, free.
//  - Strings: "NAME"; "MOUSE_EVENTS"; "true"; "SCALE_TO_WINDOW".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "SCALE_TO_WINDOW"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_SCALE_TO_WINDOW_007aa150(uint32_t /* width from decompiler */ param_1,BSTR *param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  char *pcVar5;

  int *unaff_EBX;

  wchar_t *unaff_EBP;

  BSTR unaff_ESI;

  BSTR pOVar6;

  BSTR unaff_EDI;

  wchar_t *pwVar7;

  wchar_t *pwStack_1c0;

  BSTR *ppOStack_1b4;

  BSTR pOStack_1b0;

  int local_1a8;

  int *piStack_1a4;

  wchar_t awStack_1a0 [2];

  OLECHAR local_19c [58];

  char acStack_128 [4];

  char acStack_124 [4];

  uint8_t uStack_120;

  void *pvStack_20;

  int *piStack_1c;

  void *pvStack_14;

  int *piStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aba62;

  pvStack_c = ExceptionList;

  local_1a8 = 0;

  pOStack_1b0 = local_19c;

  local_4 = 0;

  ppOStack_1b4 = param_2;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_2 + 0x18))();

  if (piStack_1a4 != (int *)0x0) {

    pwStack_1c0 = awStack_1a0;

    (**(code **)(*piStack_1a4 + 0x20))(piStack_1a4);

    uStack_120 = 0;

    pOStack_1b0 = (BSTR)0x0;

    if (0 < local_1a8) {

      do {

        pOVar6 = pOStack_1b0;

        iVar2 = (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX,pOStack_1b0,&ppOStack_1b4);

        if (iVar2 == 0) {

          SysFreeString(unaff_ESI);

          unaff_ESI = (BSTR)0x0;

          (**(code **)(*ppOStack_1b4 + 0xe))(ppOStack_1b4,&stack0xfffffe48);

          if (*pwStack_1c0 != L'#') {

            iVar2 = wcscmp(pwStack_1c0,L"NAME");

            if (iVar2 == 0) {

              SysFreeString(pwStack_1c0);

              pwStack_1c0 = (wchar_t *)0x0;

              (**(code **)(*(int *)unaff_EDI + 0x68))(unaff_EDI,&pwStack_1c0);

              ppOStack_1b4 = &pOStack_1b0;

              pwVar7 = unaff_EBP;

              uVar3 = (*(code *)PTR_FUN_00af8c9c)();

              FUN_00403450(unaff_EBP,uVar3);

              piVar4 = unaff_EBX;

              do {

                iVar2 = *piVar4;

                (acStack_128 + -(int)unaff_EBX)[(int)piVar4] = (char)iVar2;

                piVar4 = (int *)((int)piVar4 + 1);

              } while ((char)iVar2 != '\0');

              unaff_EBP = pwVar7;

              if (unaff_EBX != &local_1a8) {

                free(unaff_EBX);

                unaff_EBP = pwVar7;

              }

            }

            else {

              iVar2 = wcscmp(pwStack_1c0,L"MOUSE_EVENTS");

              if (iVar2 == 0) {

                SysFreeString(pwStack_1c0);

                pwStack_1c0 = (wchar_t *)0x0;

                (**(code **)(*(int *)unaff_EDI + 0x68))(unaff_EDI,&pwStack_1c0);

                iVar2 = _wcsicmp(unaff_EBP,L"true");

                if (iVar2 == 0) {

                  (**(code **)(*piStack_1c + 0x2fc))(1);

                }

                else {

                  (**(code **)(*piStack_1c + 0x2fc))(0);

                }

              }

              else {

                iVar2 = wcscmp(pwStack_1c0,L"SCALE_TO_WINDOW");

                if (iVar2 == 0) {

                  SysFreeString(pwStack_1c0);

                  pwStack_1c0 = (wchar_t *)0x0;

                  (**(code **)(*(int *)unaff_EDI + 0x68))(unaff_EDI,&pwStack_1c0);

                  iVar2 = wcscmp(pwStack_1c0,L"true");

                  *(bool *)((int)pvStack_14 + 0xcf) = iVar2 == 0;

                }

              }

            }

          }

          (**(code **)(*(int *)unaff_EDI + 8))(unaff_EDI);

          pOVar6 = pOStack_1b0;

        }

        pOStack_1b0 = (BSTR)((int)pOVar6 + 1);

      } while ((int)pOStack_1b0 < local_1a8);

    }

    (**(code **)(*unaff_EBX + 8))(unaff_EBX);

    pcVar5 = acStack_124;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    ppOStack_1b4 = (BSTR *)(pcVar5 + -(int)(acStack_124 + 1));

    if (ppOStack_1b4 != (BSTR *)0x0) {

      (**(code **)(*piStack_10 + 0x50))

                (acStack_124,

                 CONCAT31((int3)((uint)(acStack_124 + 1) >> 8),

                          *(uint8_t *)((int)piStack_10 + 0xcf)),0);

    }

    SysFreeString(unaff_EDI);

    ExceptionList = pvStack_20;

    return;

  }

  SysFreeString(pOStack_1b0);

  ExceptionList = pvStack_14;

  return;

}
