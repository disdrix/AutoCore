// =============================================================================
// FUN_00404b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00404b30
// Address:   0x00404b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404b30 @ 0x00404b30
// Stable ID: aa_00404b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004048c0, FUN_004048e0, FUN_00404b30, MultiByteToWideChar, lstrlenA, malloc.
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

void __thiscall FUN_00404b30(uint32_t /* width from decompiler */ *param_1,LPCSTR param_2,UINT param_3)



{

  int iVar1;

  void *pvVar2;

  

  if (param_2 == (LPCSTR)0x0) {

    *param_1 = 0;

    return;

  }

  iVar1 = lstrlenA(param_2);

  iVar1 = iVar1 + 1;

  if (0x80 < iVar1) {

    pvVar2 = malloc(iVar1 * 2);

    *param_1 = pvVar2;

    if (pvVar2 == (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

  }

  iVar1 = MultiByteToWideChar(param_3,0,param_2,iVar1,(LPWSTR)*param_1,iVar1);

  if (iVar1 == 0) {

    FUN_004048c0();

  }

  return;

}
