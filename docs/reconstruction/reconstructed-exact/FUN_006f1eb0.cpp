// =============================================================================
// FUN_006f1eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1eb0
// Address:   0x006f1eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1eb0 @ 0x006f1eb0
// Stable ID: aa_006f1eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f39a0×4, FUN_006f1eb0.
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

void FUN_006f1eb0(int param_1)



{

  FUN_006f39a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  FUN_006f39a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  FUN_006f39a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  FUN_006f39a0(*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  return;

}
