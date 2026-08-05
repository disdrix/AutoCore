// =============================================================================
// FUN_00604ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00604ca0
// Address:   0x00604ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00604ca0 @ 0x00604ca0
// Stable ID: aa_00604ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005081f0, FUN_00604ca0.
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

void __fastcall FUN_00604ca0(int *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[9];

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x1c))();

    piVar1[9] = 0;

    (**(code **)(*piVar1 + 0x18))(1,1);

    (**(code **)(*param_1 + 0x1c))();

    param_1[9] = 0;

  }

  FUN_005081f0();

  return;

}
