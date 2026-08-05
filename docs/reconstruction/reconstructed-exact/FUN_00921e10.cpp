// =============================================================================
// FUN_00921e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00921e10
// Address:   0x00921e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00921e10 @ 0x00921e10
// Stable ID: aa_00921e10
// Embedded strings (evidence for future rename):
//   - "CAM_MAX_DIST"
//   - "%f;%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: SysFreeString×4, FUN_00910e00, FUN_00921e10, _wcsicmp, swscanf.
//  - Strings: "CAM_MAX_DIST"; "%f;%f".
//  - Return sites: 3.

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



void FUN_00921e10(int *param_1,int param_2)



{

  int iVar1;

  float unaff_EBP;

  void *unaff_ESI;

  BSTR unaff_EDI;

  wchar_t local_18 [2];

  void *local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bad09;

  local_c = ExceptionList;

  local_18[0] = L'\0';

  local_18[1] = L'\0';

  local_4 = 0;

  local_14 = (void *)g_flOne;

  if ((param_1 != (int *)0x0) && (param_2 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x1c))(param_1);

    iVar1 = _wcsicmp(L"CAM_MAX_DIST",unaff_EDI);

    if (iVar1 == 0) {

      SysFreeString(unaff_EDI);

      (**(code **)(*param_1 + 0x68))(param_1,&stack0xffffffe0);

      iVar1 = swscanf(local_18,L"%f;%f",&stack0xffffffdc,0);

      if (iVar1 == 2) {

        _DAT_00000000 = _DAT_00000000 - unaff_EBP;

      }

      local_14 = (void *)0xffffffff;

      fRam00000cd8 = unaff_EBP;

      SysFreeString(local_18);

      ExceptionList = unaff_ESI;

      return;

    }

    FUN_00910e00(param_1,param_2);

    local_c = (void *)0xffffffff;

    SysFreeString(unaff_EDI);

    ExceptionList = local_14;

    return;

  }

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
