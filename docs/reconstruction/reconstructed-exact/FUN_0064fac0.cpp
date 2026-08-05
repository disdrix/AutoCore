// =============================================================================
// FUN_0064fac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064fac0
// Address:   0x0064fac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064fac0 @ 0x0064fac0
// Stable ID: aa_0064fac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0064f920, FUN_0065e5f0, hkDefaultSteering_ctor.
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

uint32_t /* width from decompiler */ * __thiscall hkDefaultSteering_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_0065e5f0(param_2);

  *param_1 = &PTR_FUN_009e4ee4;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0x80000000;

  FUN_0064f920(param_2);

  return param_1;

}
