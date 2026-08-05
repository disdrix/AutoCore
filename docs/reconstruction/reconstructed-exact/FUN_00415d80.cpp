// =============================================================================
// FUN_00415d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00415d80
// Address:   0x00415d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00415d80 @ 0x00415d80
// Stable ID: aa_00415d80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00415d80, FUN_00415f70.
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

void FUN_00415d80(void)

{
  uint uVar1;
  int *piVar2;
  uint in_EAX;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 8);
  if (uVar1 < in_EAX) {
    FUN_00415f70(unaff_ESI,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4),in_EAX - uVar1);
    return;
  }
  while( true ) {
    if (uVar1 <= in_EAX) {
      return;
    }
    piVar2 = (int *)(*(int **)(unaff_ESI + 4))[1];
    if (piVar2 != *(int **)(unaff_ESI + 4)) break;
    uVar1 = *(uint *)(unaff_ESI + 8);
  }
  *(int *)piVar2[1] = *piVar2;
  *(int *)(*piVar2 + 4) = piVar2[1];
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar2);
}
