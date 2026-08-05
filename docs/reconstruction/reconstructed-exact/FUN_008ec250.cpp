// =============================================================================
// FUN_008ec250
// -----------------------------------------------------------------------------
// Stable ID: aa_008ec250
// Address:   0x008ec250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ec250 @ 0x008ec250
// Stable ID: aa_008ec250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008ec250.
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

void FUN_008ec250(int param_1)



{

  uint8_t local_8 [4];

  int iStack_4;

  

  if (*(int *)(param_1 + 0x5ac) != 0) {

    (**(code **)(**(int **)(param_1 + 0x5ac) + 0x140))(local_8,1);

    (**(code **)(**(int **)(iStack_4 + 0x5ac) + 0x118))(&stack0xffffffe8);

  }

  return;

}
