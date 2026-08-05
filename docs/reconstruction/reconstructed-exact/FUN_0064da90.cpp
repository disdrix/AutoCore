// =============================================================================
// FUN_0064da90
// -----------------------------------------------------------------------------
// Stable ID: aa_0064da90
// Address:   0x0064da90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064da90 @ 0x0064da90
// Stable ID: aa_0064da90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0065d880, hkDefaultAerodynamics_ctor.
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

uint32_t /* width from decompiler */ * __thiscall hkDefaultAerodynamics_ctor(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  FUN_0065d880(param_2);

  *param_1 = &PTR_FUN_009e4b20;

  param_1[0xc] = *param_2;

  param_1[0xd] = param_2[1];

  param_1[0xe] = param_2[2];

  param_1[0xf] = param_2[3];

  param_1[0x10] = param_2[4];

  param_1[0x11] = param_2[5];

  param_1[0x12] = param_2[6];

  param_1[0x13] = param_2[7];

  return param_1;

}
