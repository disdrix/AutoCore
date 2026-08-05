// =============================================================================
// FUN_004b4ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4ba0
// Address:   0x004b4ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4ba0 @ 0x004b4ba0
// Stable ID: aa_004b4ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004b4ba0.
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

void __fastcall FUN_004b4ba0(int param_1)



{

  int *piVar1;

  

  if (*(int *)(param_1 + 4) != 0) {

    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0xd8))(0);

    (**(code **)(*piVar1 + 0x24))(0);

    (**(code **)(*piVar1 + 0x1c))(0x3f000000);

    (**(code **)(*piVar1 + 0x14))(0x3f000000);

  }

  return;

}
