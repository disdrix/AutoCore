// =============================================================================
// FUN_00427530
// -----------------------------------------------------------------------------
// Stable ID: aa_00427530
// Address:   0x00427530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00427530 @ 0x00427530
// Stable ID: aa_00427530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004048c0, FUN_004048e0, FUN_00427530, MultiByteToWideChar, lstrlenA, malloc.
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

void FUN_00427530(UINT param_1)



{

  int iVar1;

  void *pvVar2;

  LPCSTR unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (unaff_EBX == (LPCSTR)0x0) {

    *unaff_EDI = 0;

    return;

  }

  iVar1 = lstrlenA(unaff_EBX);

  iVar1 = iVar1 + 1;

  if (0x400 < iVar1) {

    pvVar2 = malloc(iVar1 * 2);

    *unaff_EDI = pvVar2;

    if (pvVar2 == (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

  }

  iVar1 = MultiByteToWideChar(param_1,0,unaff_EBX,iVar1,(LPWSTR)*unaff_EDI,iVar1);

  if (iVar1 == 0) {

    FUN_004048c0();

  }

  return;

}
