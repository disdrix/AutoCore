// =============================================================================
// Named_EDIT_BOX_007933a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007933a0
// Address:   0x007933a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_EDIT_BOX_007933a0 @ 0x007933a0
// Stable ID: aa_007933a0
// Embedded strings (evidence for future rename):
//   - "SHOW_BG"
//   - "true"
//   - "BUTTON"
//   - "SCROLLBAR"
//   - "LABEL"
//   - "EDIT_BOX"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×6.
//  - Notable callees: SysFreeString×7, _wcsicmp×6, FUN_00792b50, FUN_00793130, FUN_00793200, FUN_007932d0, FUN_007933a0.
//  - Strings: "SHOW_BG"; "true"; "BUTTON"; "SCROLLBAR".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * String-driven rename evidence: "EDIT_BOX"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_EDIT_BOX_007933a0(int param_1,int *param_2,int param_3)



{

  int iVar1;

  void *unaff_EBX;

  void *unaff_ESI;

  wchar_t *unaff_EDI;

  wchar_t local_10 [2];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b801f;

  local_c = ExceptionList;

  local_10[0] = L'\0';

  local_10[1] = L'\0';

  local_4 = 0;

  if ((param_2 == (int *)0x0) || (param_3 == 0)) {

    ExceptionList = &local_c;

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  (**(code **)(*param_2 + 0x1c))(param_2);

  iVar1 = _wcsicmp(unaff_EDI,L"SHOW_BG");

  if (iVar1 == 0) {

    SysFreeString(unaff_EDI);

    (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe8);

    iVar1 = _wcsicmp(local_10,L"true");

    *(bool *)(param_1 + 0x495) = iVar1 == 0;

    SysFreeString(local_10);

    ExceptionList = unaff_EBX;

    return;

  }

  iVar1 = _wcsicmp(unaff_EDI,L"BUTTON");

  if (iVar1 == 0) {

    FUN_007932d0(param_2);

    SysFreeString(unaff_EDI);

    ExceptionList = unaff_ESI;

    return;

  }

  iVar1 = _wcsicmp(unaff_EDI,L"SCROLLBAR");

  if (iVar1 == 0) {

    FUN_00793200(param_2);

    SysFreeString(unaff_EDI);

    ExceptionList = unaff_ESI;

    return;

  }

  iVar1 = _wcsicmp(unaff_EDI,L"LABEL");

  if (iVar1 == 0) {

    FUN_00792b50(param_2);

    SysFreeString(unaff_EDI);

    ExceptionList = unaff_ESI;

    return;

  }

  iVar1 = _wcsicmp(unaff_EDI,L"EDIT_BOX");

  if (iVar1 == 0) {

    FUN_00793130(param_2);

  }

  SysFreeString(unaff_EDI);

  ExceptionList = unaff_ESI;

  return;

}
