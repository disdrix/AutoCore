// =============================================================================
// FUN_0064e510
// -----------------------------------------------------------------------------
// Stable ID: aa_0064e510
// Address:   0x0064e510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064e510 @ 0x0064e510
// Stable ID: aa_0064e510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0064df10, FUN_0065e070, hkDefaultSuspension_ctor.
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

uint32_t /* width from decompiler */ * __thiscall hkDefaultSuspension_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_0065e070(param_2);

  *param_1 = &PTR_FUN_009e4c00;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0x80000000;

  param_1[0x16] = 0x80000000;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x19] = 0x80000000;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  FUN_0064df10(param_2);

  return param_1;

}
