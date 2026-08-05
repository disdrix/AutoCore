// =============================================================================
// FUN_007fba30
// -----------------------------------------------------------------------------
// Stable ID: aa_007fba30
// Address:   0x007fba30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fba30 @ 0x007fba30
// Stable ID: aa_007fba30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007fba30.
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

uint32_t /* width from decompiler */ FUN_007fba30(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x30b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30b0) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x30b0) + 0xd0))();

      if (cVar1 != '\0') {

        return 1;

      }

    }

  }

  return 0;

}
