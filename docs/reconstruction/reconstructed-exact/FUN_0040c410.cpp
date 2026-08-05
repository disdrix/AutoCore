// =============================================================================
// FUN_0040c410
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c410
// Address:   0x0040c410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c410 @ 0x0040c410
// Stable ID: aa_0040c410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040c410.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040c410; evidence only — no invented semantics):
//  - Entry: `void FUN_0040c410(undefined4 *param_1)`.
//  - Writes: *param_1 = &PTR_LAB_00a2f52c; param_1[1] = fVar1; *param_1 = &PTR_LAB_00a2f538.
//  - Returns (1 site(s)): `void`.
//  - Assign `param_1 = &PTR_LAB_00a2f52c`.
//  - Assign `param_1 = &PTR_LAB_00a2f538`.




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

void FUN_0040c410(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  

  fVar1 = g_flOne;

  *param_1 = &PTR_LAB_00a2f52c;

  param_1[1] = fVar1;

  *param_1 = &PTR_LAB_00a2f538;

  param_1[4] = param_1 + 8;

  param_1[5] = 0;

  param_1[6] = 0x80000008;

  param_1[0xd] = fVar1;

  param_1[0x10] = 0;

  param_1[0x19] = fVar1;

  param_1[0x1c] = 0;

  param_1[0x25] = fVar1;

  param_1[0x28] = 0;

  param_1[0x31] = fVar1;

  param_1[0x34] = 0;

  param_1[0x3d] = fVar1;

  param_1[0x40] = 0;

  param_1[0x49] = fVar1;

  param_1[0x4c] = 0;

  param_1[0x55] = fVar1;

  param_1[0x58] = 0;

  param_1[0x61] = fVar1;

  param_1[100] = 0;

  param_1[5] = 0;

  param_1[1] = fVar1;

  return;

}
