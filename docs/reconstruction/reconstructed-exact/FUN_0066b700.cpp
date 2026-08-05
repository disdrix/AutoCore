// =============================================================================
// FUN_0066b700
// -----------------------------------------------------------------------------
// Stable ID: aa_0066b700
// Address:   0x0066b700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066b700 @ 0x0066b700
// Stable ID: aa_0066b700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0066b700.
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

void __thiscall FUN_0066b700(int *param_1,int param_2)



{

  param_1[8] = *(int *)(param_2 + 0x10);

  param_1[9] = *(int *)(param_2 + 0x14);

  param_1[10] = *(int *)(param_2 + 0x18);

  param_1[0xb] = *(int *)(param_2 + 0x1c);

  param_1[0xc] = *(int *)(param_2 + 0x40);

  param_1[0xd] = *(int *)(param_2 + 0x44);

  param_1[0xe] = *(int *)(param_2 + 0x48);

  param_1[0xf] = *(int *)(param_2 + 0x4c);

  param_1[0x10] = *(int *)(param_2 + 0x50);

  param_1[0x11] = *(int *)(param_2 + 0x54);

  param_1[0x12] = *(int *)(param_2 + 0x58);

  param_1[0x13] = *(int *)(param_2 + 0x5c);

  param_1[0x14] = *(int *)(param_2 + 0x20);

  param_1[0x15] = *(int *)(param_2 + 0x24);

  param_1[0x16] = *(int *)(param_2 + 0x28);

  param_1[0x17] = *(int *)(param_2 + 0x2c);

  param_1[0x18] = *(int *)(param_2 + 0x30);

  param_1[0x19] = *(int *)(param_2 + 0x34);

  param_1[0x1a] = *(int *)(param_2 + 0x38);

  param_1[0x1b] = *(int *)(param_2 + 0x3c);

  (**(code **)(*param_1 + 0x1c))(&param_2);

  return;

}
