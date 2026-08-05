// =============================================================================
// FUN_00873070
// -----------------------------------------------------------------------------
// Stable ID: aa_00873070
// Address:   0x00873070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00873070 @ 0x00873070
// Stable ID: aa_00873070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: atoi×4, __allmul×3, FUN_00873070.
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

longlong FUN_00873070(void)



{

  int iVar1;

  char *pcVar2;

  int unaff_ESI;

  longlong lVar3;

  longlong lVar4;

  

  lVar3 = 0;

  if (*(int *)(unaff_ESI + 0x6a0) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x6a0) + 0x1dc))();

    lVar3 = 0;

    if (iVar1 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x6a0) + 0x1dc))();

      iVar1 = atoi(pcVar2);

      lVar3 = __allmul(iVar1,iVar1 >> 0x1f,1000000000,0);

    }

  }

  if (*(int *)(unaff_ESI + 0x6a4) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x6a4) + 0x1dc))();

    if (iVar1 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x6a4) + 0x1dc))();

      iVar1 = atoi(pcVar2);

      lVar4 = __allmul(iVar1,iVar1 >> 0x1f,1000000,0);

      lVar3 = lVar4 + lVar3;

    }

  }

  if (*(int *)(unaff_ESI + 0x6a8) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x6a8) + 0x1dc))();

    if (iVar1 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x6a8) + 0x1dc))();

      iVar1 = atoi(pcVar2);

      lVar4 = __allmul(iVar1,iVar1 >> 0x1f,1000,0);

      lVar3 = lVar4 + lVar3;

    }

  }

  if (*(int *)(unaff_ESI + 0x6ac) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x6ac) + 0x1dc))();

    if (iVar1 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x6ac) + 0x1dc))();

      iVar1 = atoi(pcVar2);

      lVar3 = lVar3 + iVar1;

    }

  }

  return lVar3;

}
