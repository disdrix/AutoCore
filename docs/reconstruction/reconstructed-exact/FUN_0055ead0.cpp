// =============================================================================
// FUN_0055ead0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ead0
// Address:   0x0055ead0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ead0 @ 0x0055ead0
// Stable ID: aa_0055ead0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055ead0, FUN_005b3370.
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

void __thiscall FUN_0055ead0(int param_1,int param_2)



{

  if (*(uint *)(param_1 + 0x10c) == (*(uint *)(param_1 + 0x110) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x108),4);

  }

  *(int *)(*(int *)(param_1 + 0x108) + *(int *)(param_1 + 0x10c) * 4) = param_2;

  *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;

  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  return;

}
