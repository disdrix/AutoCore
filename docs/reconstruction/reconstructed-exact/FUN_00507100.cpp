// =============================================================================
// FUN_00507100
// -----------------------------------------------------------------------------
// Stable ID: aa_00507100
// Address:   0x00507100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00507100 @ 0x00507100
// Stable ID: aa_00507100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00507100, FUN_0055ead0.
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

void __fastcall FUN_00507100(int param_1)



{

  if (((*(int *)(param_1 + 8) != 0) && (*(char *)(*(int *)(param_1 + 0x44) + 0x29) != '\0')) &&

     (*(int *)(*(int *)(param_1 + 0x44) + 0x24) != -1)) {

    FUN_0055ead0(param_1);

  }

  return;

}
