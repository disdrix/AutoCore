// =============================================================================
// FUN_0067a7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067a7b0
// Address:   0x0067a7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067a7b0 @ 0x0067a7b0
// Stable ID: aa_0067a7b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00680c80×3, FUN_0067a7b0.
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

void FUN_0067a7b0(int param_1,int param_2,int param_3,int param_4)



{

  if ((param_2 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_2,1);

  }

  if ((param_3 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_3,1);

  }

  if ((param_4 != 0) && (1 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_4,2);

  }

  return;

}
