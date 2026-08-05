// =============================================================================
// Named_READ_ONLY_007942b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007942b0
// Address:   0x007942b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_READ_ONLY_007942b0 @ 0x007942b0
// Stable ID: aa_007942b0
// Embedded strings (evidence for future rename):
//   - "READ_ONLY"
//   - "true"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: SysFreeString×4, _wcsicmp×2, FUN_00794090, FUN_007942b0.
//  - Strings: "READ_ONLY"; "true".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * String-driven rename evidence: "READ_ONLY"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_READ_ONLY_007942b0(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  void *unaff_EBX;

  wchar_t *unaff_EBP;

  BSTR unaff_ESI;

  void *unaff_EDI;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab917;

  local_c = ExceptionList;

  local_10 = 0;

  local_4 = 0;

  if ((param_2 != (int *)0x0) && (param_3 != 0)) {

    ExceptionList = &local_c;

    (**(code **)(*param_2 + 0x1c))(param_2,&local_10);

    iVar1 = _wcsicmp(L"READ_ONLY",unaff_ESI);

    if (iVar1 == 0) {

      SysFreeString(unaff_ESI);

      unaff_ESI = (BSTR)0x0;

      (**(code **)(*param_2 + 0x68))(param_2,&stack0xffffffe8);

      iVar1 = _wcsicmp(L"true",unaff_EBP);

      if (iVar1 == 0) {

        FUN_00794090();

        SysFreeString(unaff_EBP);

        ExceptionList = unaff_EDI;

        return;

      }

      *(uint8_t *)((int)param_1 + 0x489) = 0;

      piVar2 = (int *)(**(code **)(*param_1 + 0x170))(3);

      param_1[0x8b] = *piVar2;

    }

    SysFreeString(unaff_ESI);

    ExceptionList = unaff_EBX;

    return;

  }

  ExceptionList = &local_c;

  SysFreeString((BSTR)0x0);

  ExceptionList = local_c;

  return;

}
