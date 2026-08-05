// =============================================================================
// FUN_004330c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004330c0
// Address:   0x004330c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004330c0 @ 0x004330c0
// Stable ID: aa_004330c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004330c0, ROUND, floor.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004330c0(int param_1)



{

  int unaff_ESI;

  double dVar1;

  

  if (param_1 < 1) {

    param_1 = 0x60;

  }

  *(int *)(unaff_ESI + 0x164) = param_1;

  dVar1 = floor((double)param_1 * _DAT_00aaa648 + _DAT_00aaa5e0);

  *(int *)(unaff_ESI + 0x20) = (int)ROUND(dVar1);

  return;

}
