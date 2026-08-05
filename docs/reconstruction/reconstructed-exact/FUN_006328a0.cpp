// =============================================================================
// FUN_006328a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006328a0
// Address:   0x006328a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006328a0 @ 0x006328a0
// Stable ID: aa_006328a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005081f0, FUN_006328a0.
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

void __fastcall FUN_006328a0(int param_1)



{

  int *piVar1;

  

  if (*(int **)(param_1 + 0x18) != (int *)0x0) {

    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x18) + 0x1ec))();

    if (piVar1 != (int *)0x0) {

      *(uint8_t *)(piVar1 + 0x2c) = 0;

      (**(code **)(*piVar1 + 0x44))();

    }

  }

  FUN_005081f0();

  return;

}
