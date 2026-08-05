// =============================================================================
// FUN_0072a3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072a3e0
// Address:   0x0072a3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072a3e0 @ 0x0072a3e0
// Stable ID: aa_0072a3e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0072a3e0.
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

int FUN_0072a3e0(void)



{

  int in_EAX;

  int *piVar1;

  int unaff_ESI;

  

  piVar1 = *(int **)(in_EAX + 0x10);

  while( true ) {

    if (piVar1 == *(int **)(in_EAX + 0x14)) {

      return 0;

    }

    if (*(int *)(*piVar1 + 0x1c) == unaff_ESI) break;

    piVar1 = piVar1 + 1;

  }

  return *piVar1;

}
