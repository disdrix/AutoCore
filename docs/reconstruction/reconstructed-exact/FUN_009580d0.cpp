// =============================================================================
// FUN_009580d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009580d0
// Address:   0x009580d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009580d0 @ 0x009580d0
// Stable ID: aa_009580d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: FUN_007fc840, FUN_00802170, FUN_009580d0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __fastcall FUN_009580d0(int param_1)



{

  char cVar1;

  

  if ((*(int *)(param_1 + 0xe98) != 0) && (0 < *(int *)(*(int *)(param_1 + 0xe98) + 0x6b4))) {

    *(bool *)(param_1 + 0xaa) = *(char *)(param_1 + 0xaa) == '\0';

    if ((*(int **)(param_1 + 0x1158) == (int *)0x0) ||

       (cVar1 = (**(code **)(**(int **)(param_1 + 0x1158) + 0xd0))(), cVar1 == '\0')) {

      if (*(char *)(param_1 + 0xaa) == '\0') {

        return 0;

      }

    }

    else if (*(char *)(param_1 + 0xaa) == '\0') {

      FUN_007fc840();

      return 0;

    }

    cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(param_1 + 0xe98)) + 0x198))();

    if (cVar1 != '\0') {

      FUN_00802170();

    }

    return 0;

  }

  return 1;

}
