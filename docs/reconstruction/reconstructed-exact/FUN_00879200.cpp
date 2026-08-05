// =============================================================================
// FUN_00879200
// -----------------------------------------------------------------------------
// Stable ID: aa_00879200
// Address:   0x00879200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00879200 @ 0x00879200
// Stable ID: aa_00879200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00879200.
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

uint32_t /* width from decompiler */ FUN_00879200(void)



{

  int iVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x598) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x598) + 0x464))();

    if (iVar1 != *(int *)(unaff_ESI + 0x54c)) {

      if (iVar1 == *(int *)(unaff_ESI + 0x550)) {

        return 0;

      }

      if (iVar1 == *(int *)(unaff_ESI + 0x554)) {

        return 1;

      }

    }

  }

  return 0xffffffff;

}
