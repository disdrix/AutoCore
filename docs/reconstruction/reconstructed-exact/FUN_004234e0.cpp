// =============================================================================
// FUN_004234e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004234e0
// Address:   0x004234e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004234e0 @ 0x004234e0
// Stable ID: aa_004234e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00423580×2, MultiByteToWideChar×2, FUN_004234e0, SysAllocStringLen, SysFreeString.
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

BSTR FUN_004234e0(LPCSTR param_1,int param_2)



{

  UINT CodePage;

  UINT cchWideChar;

  BSTR lpWideCharStr;

  UINT UVar1;

  

  if ((param_1 != (LPCSTR)0x0) && (param_2 != 0)) {

    CodePage = (*(code *)PTR_FUN_00af8c9c)();

    cchWideChar = MultiByteToWideChar(CodePage,0,param_1,param_2,(LPWSTR)0x0,0);

    UVar1 = cchWideChar;

    if (param_2 == -1) {

      UVar1 = cchWideChar - 1;

    }

    lpWideCharStr = SysAllocStringLen((OLECHAR *)0x0,UVar1);

    if (lpWideCharStr != (BSTR)0x0) {

      UVar1 = MultiByteToWideChar(CodePage,0,param_1,param_2,lpWideCharStr,cchWideChar);

      if (UVar1 != cchWideChar) {

        SysFreeString(lpWideCharStr);

        FUN_00423580();

        return (BSTR)0x0;

      }

    }

    FUN_00423580();

    return lpWideCharStr;

  }

  return (BSTR)0x0;

}
