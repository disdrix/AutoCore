// =============================================================================
// FUN_00662230
// -----------------------------------------------------------------------------
// Stable ID: aa_00662230
// Address:   0x00662230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662230 @ 0x00662230
// Stable ID: aa_00662230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~6 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066dd10×2, FUN_00662230.
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

void __thiscall FUN_00662230(int param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_0066dd10(param_1 + 0x40,param_1 + 0x60,0x3e800000,0xffff0000,param_2);

  FUN_0066dd10(param_1 + 0x50,param_1 + 0x90,0x3e800000,0xffffffff,param_2);

  return;

}
