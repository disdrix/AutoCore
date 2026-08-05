// =============================================================================
// FUN_0044c210
// -----------------------------------------------------------------------------
// Stable ID: aa_0044c210
// Address:   0x0044c210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044c210 @ 0x0044c210
// Stable ID: aa_0044c210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_0044c210, _aligned_malloc.
//  - Return sites: 1.

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

void FUN_0044c210(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *unaff_EDI;

  int *local_4;

  

  if (((int *)*unaff_EDI == (int *)0x0) || (*(int *)*unaff_EDI == 0)) {

    piVar1 = _aligned_malloc(0x8000,0x10);

    local_4 = piVar1;

    CVOGReaction_FailMissionNotify(&local_4);

    *unaff_EDI = (int)piVar1;

    iVar3 = 0x3ff;

    piVar2 = piVar1;

    do {

      iVar3 = iVar3 + -1;

      *piVar2 = (int)(piVar2 + 8);

      piVar2 = piVar2 + 8;

    } while (iVar3 != 0);

    piVar1[0x1ff8] = 0;

  }

  *unaff_EDI = *(int *)*unaff_EDI;

  return;

}
