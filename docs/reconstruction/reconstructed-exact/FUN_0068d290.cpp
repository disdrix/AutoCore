// =============================================================================
// FUN_0068d290
// -----------------------------------------------------------------------------
// Stable ID: aa_0068d290
// Address:   0x0068d290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068d290 @ 0x0068d290
// Stable ID: aa_0068d290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0068d0b0, FUN_0068d290.
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

int __thiscall FUN_0068d290(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_0068d0b0(param_2,param_3,param_4,param_1,param_4);

  return param_3 * 0x10 + param_2;

}
