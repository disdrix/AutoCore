// =============================================================================
// Named_DIRECTIONAL_LIGHT_00910e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00910e00
// Address:   0x00910e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_DIRECTIONAL_LIGHT_00910e00 @ 0x00910e00
// Stable ID: aa_00910e00
// Embedded strings (evidence for future rename):
//   - "DIRECTIONAL_LIGHT"
//   - "HEADING"
//   - "DIFFUSE"
//   - "AMBIENT"
//   - "SPECULAR"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, do×1, goto×1, while×1.
//  - Notable callees: SysFreeString×5, _wcsicmp×5, FUN_007933a0, FUN_007a88b0, FUN_007a9210, FUN_00910e00.
//  - Strings: "DIRECTIONAL_LIGHT"; "HEADING"; "DIFFUSE"; "AMBIENT".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * String-driven rename evidence: "DIRECTIONAL_LIGHT"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_DIRECTIONAL_LIGHT_00910e00(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  OLECHAR *pOVar3;

  int *unaff_EBX;

  int *unaff_EBP;

  BSTR unaff_ESI;

  BSTR unaff_EDI;

  OLECHAR **_Str2;

  OLECHAR *bstrString;

  void **bstrString_00;

  OLECHAR *pOStack_34;

  OLECHAR local_20 [2];

  void *apvStack_1c [2];

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bacac;

  local_c = ExceptionList;

  local_20[0] = L'\0';

  local_20[1] = L'\0';

  local_4 = 0;

  if ((param_1 == (int *)0x0) || (param_2 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  pOStack_34 = local_20;

  ExceptionList = &local_c;

  (**(code **)(*param_1 + 0x1c))();

  iVar1 = _wcsicmp(L"DIRECTIONAL_LIGHT",unaff_ESI);

  if (iVar1 != 0) {

    FUN_007933a0();

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = pvStack_14;

    return;

  }

  bstrString_00 = apvStack_1c;

  (**(code **)(*param_1 + 0x30))();

  if (unaff_EBX == (int *)0x0) {

    pvStack_14 = (void *)0xffffffff;

    SysFreeString(unaff_EDI);

    ExceptionList = apvStack_1c[0];

    return;

  }

  bstrString = local_20;

  (**(code **)(*unaff_EBX + 0x20))();

  iVar1 = 0;

  if (0 < (int)unaff_ESI) {

    do {

      _Str2 = &pOStack_34;

      (**(code **)(*unaff_EBP + 0x1c))(unaff_EBP,iVar1);

      SysFreeString(bstrString);

      bstrString = (OLECHAR *)0x0;

      (**(code **)(*param_1 + 0x1c))(param_1,&stack0xffffffbc);

      iVar2 = _wcsicmp(L"HEADING",(wchar_t *)_Str2);

      if (iVar2 == 0) {

        FUN_007a88b0(unaff_EBX,bstrString + 0x2d0,bstrString + 0x2d2,bstrString + 0x2d4);

      }

      else {

        iVar2 = _wcsicmp(L"DIFFUSE",(wchar_t *)_Str2);

        if (iVar2 == 0) {

          pOVar3 = bstrString + 0x2be;

        }

        else {

          iVar2 = _wcsicmp(L"AMBIENT",(wchar_t *)_Str2);

          if (iVar2 == 0) {

            pOVar3 = bstrString + 0x2b6;

          }

          else {

            iVar2 = _wcsicmp(L"SPECULAR",(wchar_t *)_Str2);

            if (iVar2 != 0) goto LAB_00910f87;

            pOVar3 = bstrString + 0x2c6;

          }

        }

        FUN_007a9210(unaff_EBX,pOVar3);

      }

LAB_00910f87:

      (**(code **)(*unaff_EBX + 8))(unaff_EBX);

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)unaff_ESI);

  }

  (**(code **)(*unaff_EBP + 8))(unaff_EBP);

  local_20[0] = L'\xffff';

  local_20[1] = L'\xffff';

  SysFreeString((BSTR)bstrString_00);

  ExceptionList = unaff_ESI;

  return;

}
