// =============================================================================
// FUN_0066c080
// -----------------------------------------------------------------------------
// Stable ID: aa_0066c080
// Address:   0x0066c080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066c080 @ 0x0066c080
// Stable ID: aa_0066c080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651bb0, FUN_0066c080.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0066c080(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  FUN_00651bb0(param_2);

  *param_1 = &PTR_FUN_009e79b8;

  param_1[2] = &PTR_LAB_009e77b4;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[8] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  param_1[9] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

  param_1[0xb] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  param_1[0xc] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

  param_1[0xd] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  param_1[0xe] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  param_1[0xf] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

  return param_1;

}
