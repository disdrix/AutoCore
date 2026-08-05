// =============================================================================
// FUN_007a8b00
// -----------------------------------------------------------------------------
// Stable ID: aa_007a8b00
// Address:   0x007a8b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a8b00 @ 0x007a8b00
// Stable ID: aa_007a8b00
// Embedded strings (evidence for future rename):
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, for×1, do×1, goto×1, while×1.
//  - Notable callees: SysFreeString×6, swscanf×3, wcscmp×3, FUN_007a8b00.
//  - Strings: "%d;%d".
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



void FUN_007a8b00(int *param_1)



{

  int iVar1;

  BSTR pOVar2;

  int *unaff_EBX;

  int iVar3;

  wchar_t *unaff_EDI;

  int **ppiVar4;

  int *piStack_28;

  BSTR *ppOStack_24;

  int *piStack_1c;

  BSTR pOStack_18;

  BSTR local_14;

  BSTR pOStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  BSTR local_4;

  

  puStack_8 = &LAB_009ab965;

  pvStack_c = ExceptionList;

  ppOStack_24 = &local_14;

  local_4 = (BSTR)0x0;

  piStack_28 = param_1;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x30))();

  if (piStack_1c == (int *)0x0) {

    SysFreeString(local_4);

    ExceptionList = local_14;

    return;

  }

  (**(code **)(*piStack_1c + 0x20))();

  iVar3 = 0;

  if (0 < (int)unaff_EDI) {

    do {

      ppiVar4 = &piStack_28;

      (**(code **)(*ppOStack_24 + 0xe))(ppOStack_24,iVar3);

      SysFreeString(pOStack_18);

      pOStack_18 = (BSTR)0x0;

      (*pcRam0000001c)(&pOStack_18,&pOStack_18);

      iVar1 = wcscmp(unaff_EDI,L"X");

      if (iVar1 == 0) {

        if (piStack_1c != (int *)0x0) {

          SysFreeString(unaff_EDI);

          unaff_EDI = (wchar_t *)0x0;

          (**(code **)(*unaff_EBX + 0x68))(unaff_EBX,&stack0xffffffe0);

          iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffc0,0);

          if (iVar1 == 2) {

            _DAT_00000000 = _DAT_00000000 - (int)ppiVar4;

          }

          *piStack_1c = (int)ppiVar4;

        }

      }

      else {

        iVar1 = wcscmp(unaff_EDI,L"Y");

        if (iVar1 == 0) {

          if (pOStack_18 != (BSTR)0x0) {

            SysFreeString(unaff_EDI);

            (**(code **)(*unaff_EBX + 0x68))(unaff_EBX,&stack0xffffffe0);

            iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffc0,0);

            pOVar2 = pOStack_18;

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - (int)ppiVar4;

            }

LAB_007a8cee:

            unaff_EDI = (wchar_t *)0x0;

            *(int ***)pOVar2 = ppiVar4;

          }

        }

        else {

          iVar1 = wcscmp(unaff_EDI,L"Z");

          if ((iVar1 == 0) && (local_14 != (BSTR)0x0)) {

            SysFreeString(unaff_EDI);

            (**(code **)(*unaff_EBX + 0x68))(unaff_EBX,&stack0xffffffe0);

            iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffc0,0);

            pOVar2 = local_14;

            if (iVar1 == 2) {

              _DAT_00000000 = _DAT_00000000 - (int)ppiVar4;

            }

            goto LAB_007a8cee;

          }

        }

      }

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

      iVar3 = iVar3 + 1;

    } while (iVar3 < (int)unaff_EDI);

  }

  (**(code **)(*ppOStack_24 + 4))();

  SysFreeString(pOStack_10);

  ExceptionList = unaff_EDI;

  return;

}
