// =============================================================================
// FUN_00581190
// -----------------------------------------------------------------------------
// Stable ID: aa_00581190
// Address:   0x00581190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581190 @ 0x00581190
// Stable ID: aa_00581190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00581190.
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

void __thiscall FUN_00581190(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009cd99c;

  param_1[2] = 0;

  param_1[3] = param_2;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[4] = 0xffffffff;

  param_1[9] = param_3;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0x80000000;

  param_1[0xb] = param_1;

  if (param_2 != 0) {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  }

  return;

}
