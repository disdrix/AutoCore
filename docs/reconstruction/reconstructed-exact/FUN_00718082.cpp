// =============================================================================
// FUN_00718082
// -----------------------------------------------------------------------------
// Stable ID: aa_00718082
// Address:   0x00718082  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718082 @ 0x00718082
// Stable ID: aa_00718082
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00718082, WideCharToMultiByte, _com_issue_error.
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

uint32_t /* width from decompiler */ FUN_00718082(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_EBP;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

  if (*(int *)(unaff_EBP + -0x14) == 0) {

    _com_issue_error(-0x7ff8fff2);

    uVar1 = 0;

  }

  else {

    iVar2 = WideCharToMultiByte(0,0,*(LPCWSTR *)(unaff_EBP + 8),*(int *)(unaff_EBP + -0x1c),

                                *(LPSTR *)(unaff_EBP + -0x14),*(int *)(unaff_EBP + -0x18),

                                (LPCSTR)0x0,(LPBOOL)0x0);

    if (iVar2 == 0) {

      *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x24) = *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x14);

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(unaff_EBP + -0x24));

    }

    uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x14);

  }

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return uVar1;

}
