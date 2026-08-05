// =============================================================================
// FUN_00651920
// -----------------------------------------------------------------------------
// Stable ID: aa_00651920
// Address:   0x00651920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00651920 @ 0x00651920
// Stable ID: aa_00651920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00651920.
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

void __fastcall FUN_00651920(uint32_t /* width from decompiler */ *param_1)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  *param_1 = &PTR_FUN_009e5378;

  param_1[2] = &PTR_LAB_009e5368;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  param_1[9] = 0;

  param_1[10] = 0x80000008;

  param_1[8] = param_1 + 0xb;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0x80000000;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0x3e88d677;

  param_1[0x1d] = 0x3f08d677;

  param_1[0x1e] = 0x3f4d41b3;

  param_1[0x1f] = 0x3f4d41b3;

  param_1[0x25] = 0;

  param_1[0x26] = 0x80000004;

  param_1[0x24] = param_1 + 0x27;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x2e] = 0;

  param_1[0x2f] = 0;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x3c] = 0;

  param_1[0x3d] = 0;

  return;

}
