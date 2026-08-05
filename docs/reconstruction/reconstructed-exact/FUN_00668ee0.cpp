// =============================================================================
// FUN_00668ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00668ee0
// Address:   0x00668ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00668ee0 @ 0x00668ee0
// Stable ID: aa_00668ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651bb0, FUN_00668d30, FUN_00668ee0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00668ee0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_00651bb0(param_2);

  *param_1 = &PTR_FUN_009e78f4;

  param_1[2] = &PTR_LAB_009e78e4;

  param_1[0x39] = 0;

  param_1[0x3a] = 0;

  param_1[0x3b] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  param_1[0x3e] = 0;

  param_1[0x3f] = 0;

  param_1[0x40] = 0;

  param_1[0x41] = 0;

  param_1[0x42] = 0;

  param_1[0x43] = 0;

  param_1[0x44] = 0;

  param_1[0x45] = 0;

  param_1[0x46] = 0;

  FUN_00668d30(param_2);

  return param_1;

}
