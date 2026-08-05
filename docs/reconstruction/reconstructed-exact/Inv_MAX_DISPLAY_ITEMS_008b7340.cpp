// =============================================================================
// Inv_MAX_DISPLAY_ITEMS_008b7340
// -----------------------------------------------------------------------------
// Stable ID: aa_008b7340
// Address:   0x008b7340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_MAX_DISPLAY_ITEMS_008b7340 @ 0x008b7340
// Stable ID: aa_008b7340
// Embedded strings (evidence for future rename):
//   - "LIST_SPACING"
//   - "MAX_DISPLAY_ITEMS"
//   - "%d;%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: SysFreeString×3, _wcsicmp×2, FUN_007933a0, FUN_007a8b00, FUN_008b7340, swscanf.
//  - Strings: "LIST_SPACING"; "MAX_DISPLAY_ITEMS"; "%d;%d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * String-driven rename evidence: "MAX_DISPLAY_ITEMS"
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



void __thiscall Inv_MAX_DISPLAY_ITEMS_008b7340(int param_1,int *param_2,int param_3)



{

  int iVar1;

  int unaff_EBX;

  BSTR unaff_ESI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  void *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b9bdb;

  local_c = ExceptionList;

  local_14 = (void *)0x0;

  local_4 = 0;

  local_10 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_14);

    iVar1 = _wcsicmp(L"LIST_SPACING",unaff_ESI);

    if (iVar1 == 0) {

      FUN_007a8b00(param_2,param_1 + 0x518,param_1 + 0x51c,0);

    }

    else {

      iVar1 = _wcsicmp(L"MAX_DISPLAY_ITEMS",unaff_ESI);

      if (iVar1 == 0) {

        SysFreeString(unaff_ESI);

        unaff_ESI = (BSTR)0x0;

        (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe4);

        iVar1 = swscanf((wchar_t *)0x0,L"%d;%d",&stack0xffffffe8,0);

        if (iVar1 == 2) {

          _DAT_00000000 = _DAT_00000000 - unaff_EBX;

        }

        *(int *)(param_1 + 0x520) = unaff_EBX;

      }

      else {

        FUN_007933a0(param_2,unaff_retaddr);

      }

    }

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_ESI);

    ExceptionList = local_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
