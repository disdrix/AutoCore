// =============================================================================
// FUN_0095d6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d6c0
// Address:   0x0095d6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d6c0 @ 0x0095d6c0
// Stable ID: aa_0095d6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, while×1.
//  - Notable callees: FUN_00456780×2, FUN_0095d6c0.
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

uint32_t /* width from decompiler */ __fastcall FUN_0095d6c0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int unaff_ESI;

  

  piVar1 = *(int **)(param_2 + 8);

  piVar2 = *(int **)(param_2 + 4);

  while( true ) {

    if (piVar2 == piVar1) {

      return 0;

    }

    if (*piVar2 == unaff_ESI) break;

    piVar2 = piVar2 + 1;

  }

  if (piVar2 == piVar1) {

    return 0;

  }

  *piVar2 = piVar1[-1];

  if (*(int *)(param_2 + 4) != 0) {

    FUN_00456780(0);

    return 1;

  }

  FUN_00456780(0);

  return 1;

}
