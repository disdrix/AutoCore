// =============================================================================
// FUN_008a2040
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2040
// Address:   0x008a2040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2040 @ 0x008a2040
// Stable ID: aa_008a2040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_008a2040.
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

uint32_t /* width from decompiler */ FUN_008a2040(void)



{

  int iVar1;

  int unaff_ESI;

  int iVar2;

  

  iVar2 = 0;

  while( true ) {

    if (*(int *)(unaff_ESI + 0x5a4) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(unaff_ESI + 0x5a8) - *(int *)(unaff_ESI + 0x5a4) >> 2;

    }

    if (iVar1 <= iVar2) break;

    if (*(int *)(*(int *)(unaff_ESI + 0x5a4) + iVar2 * 4) != 0) {

      iVar1 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x5a4) + iVar2 * 4) + 0x78))();

      if (iVar1 == *(int *)(unaff_ESI + 0x518)) {

        return *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x5a4) + iVar2 * 4);

      }

    }

    iVar2 = iVar2 + 1;

  }

  return 0;

}
