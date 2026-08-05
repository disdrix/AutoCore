// =============================================================================
// FUN_0074d470
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d470
// Address:   0x0074d470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074d470 @ 0x0074d470
// Stable ID: aa_0074d470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0044a5b0, FUN_0044a670, FUN_0074d470.
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

void __fastcall FUN_0074d470(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x10) == 0) {

    return;

  }

  iVar1 = FUN_0044a5b0(*(int *)(param_1 + 0x10) + 0x98);

  if (iVar1 == 0) {

    FUN_0044a670(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  }

  return;

}
