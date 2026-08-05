// =============================================================================
// FUN_005b7e40
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7e40
// Address:   0x005b7e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b7e40 @ 0x005b7e40
// Stable ID: aa_005b7e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00410420×2, FUN_005b7e40.
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

uint32_t /* width from decompiler */ __thiscall FUN_005b7e40(int param_1,int param_2)



{

  int *piVar1;

  

  piVar1 = *(int **)(param_1 + 4);

  while( true ) {

    if (piVar1 == *(int **)(param_1 + 8)) {

      return 0;

    }

    if (*piVar1 == param_2) break;

    piVar1 = piVar1 + 1;

  }

  *piVar1 = (*(int **)(param_1 + 8))[-1];

  if (*(int *)(param_1 + 4) == 0) {

    FUN_00410420(0xffffffff,0);

    return 1;

  }

  FUN_00410420((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) + -1,0);

  return 1;

}
