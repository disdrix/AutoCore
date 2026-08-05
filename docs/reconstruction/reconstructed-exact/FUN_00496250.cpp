// =============================================================================
// FUN_00496250
// -----------------------------------------------------------------------------
// Stable ID: aa_00496250
// Address:   0x00496250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496250 @ 0x00496250
// Stable ID: aa_00496250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004506a0, FUN_00496250, FUN_004c55e0.
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

void FUN_00496250(int *param_1)



{

  int *piVar1;

  float10 fVar2;

  

  piVar1 = param_1;

  if (param_1 != (int *)0x0) {

    if (param_1[0xa1] != 0) {

      (**(code **)(*param_1 + 0x44))();

      param_1 = (int *)piVar1[0xa1];

      FUN_004506a0(&param_1);

      return;

    }

    fVar2 = (float10)FUN_004c55e0();

    if ((float10)g_flZero == fVar2) {

      (**(code **)(*piVar1 + 0x44))();

    }

  }

  return;

}
