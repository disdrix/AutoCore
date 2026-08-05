// =============================================================================
// FUN_0056a9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a9a0
// Address:   0x0056a9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a9a0 @ 0x0056a9a0
// Stable ID: aa_0056a9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGTacArc_UpdateMesh, FUN_0056a9a0.
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

void __thiscall FUN_0056a9a0(int param_1,float param_2)



{

  if (*(int *)(param_1 + 0xc0) != 0) {

    CVOGTacArc_UpdateMesh(param_2);

  }

  if (*(char *)(param_1 + 0xcb) != '\0') {

    *(float *)(param_1 + 0xd8) = param_2 + *(float *)(param_1 + 0xd8);

  }

  return;

}
