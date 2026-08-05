// =============================================================================
// Inv_ITEM_REWARD_WINDOWS_00854380
// -----------------------------------------------------------------------------
// Stable ID: aa_00854380
// Address:   0x00854380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_ITEM_REWARD_WINDOWS_00854380 @ 0x00854380
// Stable ID: aa_00854380
// Embedded strings (evidence for future rename):
//   - "ITEM_REWARD_WINDOWS"
//   - "Ｓ氹␤踏Ý"
//   - "NUM_COLUMNS"
//   - "%d;%d"
//   - "SPACING"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×1, while×1.
//  - Notable callees: SysFreeString×6, wcscmp×3, FUN_007933a0, FUN_007a8b00, FUN_00854380, swscanf.
//  - Strings: "ITEM_REWARD_WINDOWS"; "Ｓ氹␤踏Ý"; "NUM_COLUMNS"; "%d;%d".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * String-driven rename evidence: "ITEM_REWARD_WINDOWS"
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



void Inv_ITEM_REWARD_WINDOWS_00854380(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  BSTR unaff_EBX;

  int *unaff_EBP;

  BSTR unaff_ESI;

  int *unaff_EDI;

  wchar_t *pwStack_50;

  int *piStack_4c;

  OLECHAR *bstrString;

  OLECHAR *bstrString_00;

  OLECHAR local_20 [2];

  void *pvStack_1c;

  void *local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b8688;

  local_c = ExceptionList;

  local_4 = 0;

  local_20[0] = L'\0';

  local_20[1] = L'\0';

  if ((param_1 == (int *)0x0) || (param_2 == 0)) {

    local_4 = 0xffffffff;

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_1 + 0x1c))();

  iVar1 = wcscmp(L"ITEM_REWARD_WINDOWS",unaff_ESI);

  if (iVar1 != 0) {

    FUN_007933a0();

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = local_14;

    return;

  }

  bstrString_00 = local_20;

  (**(code **)(*param_1 + 0x30))();

  if (unaff_EBP == (int *)0x0) {

    local_14 = (void *)0xffffffff;

    piStack_4c = (int *)0x854414;

    SysFreeString(unaff_EBX);

    ExceptionList = pvStack_1c;

    return;

  }

  bstrString = local_20;

  pwStack_50 = L"Ｓ氹␤踏Ý";

  piStack_4c = unaff_EBP;

  (**(code **)(*unaff_EBP + 0x20))();

  iVar1 = 0;

  if (0 < (int)unaff_EBP) {

    do {

      pwStack_50 = (wchar_t *)&stack0xffffffcc;

      (**(code **)(*unaff_EDI + 0x1c))(unaff_EDI,iVar1);

      SysFreeString(bstrString);

      bstrString = (OLECHAR *)0x0;

      (**(code **)(*(int *)bstrString_00 + 0x1c))(bstrString_00,&stack0xffffffb8);

      iVar2 = wcscmp(L"NUM_COLUMNS",pwStack_50);

      if (iVar2 == 0) {

        SysFreeString(pwStack_50);

        pwStack_50 = (wchar_t *)0x0;

        (**(code **)(*param_1 + 0x68))(param_1,&pwStack_50);

        iVar2 = swscanf(pwStack_50,L"%d;%d",&piStack_4c,0);

        if (iVar2 == 2) {

          _DAT_00000000 = _DAT_00000000 - (int)piStack_4c;

        }

        *(int **)(bstrString_00 + 0x2b4) = piStack_4c;

      }

      else {

        iVar2 = wcscmp(L"SPACING",pwStack_50);

        if (iVar2 == 0) {

          FUN_007a8b00(bstrString,bstrString_00 + 0x2b0,bstrString_00 + 0x2b2,0);

        }

      }

      (**(code **)(*(int *)bstrString + 8))(bstrString);

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)unaff_EBP);

  }

  (**(code **)(*unaff_EDI + 8))();

  local_20[0] = L'\xffff';

  local_20[1] = L'\xffff';

  SysFreeString(bstrString_00);

  ExceptionList = unaff_EBP;

  return;

}
