// =============================================================================
// FUN_005ffdb0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffdb0
// Address:   0x005ffdb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ffdb0 @ 0x005ffdb0
// Stable ID: aa_005ffdb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005ffcf0, FUN_005ffdb0.
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

void __thiscall FUN_005ffdb0(int param_1,int param_2)



{

  FUN_005ffcf0(param_1,param_2);

  if (param_2 != 0) {

    *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | 0x80;

    return;

  }

  *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0x7f;

  return;

}
