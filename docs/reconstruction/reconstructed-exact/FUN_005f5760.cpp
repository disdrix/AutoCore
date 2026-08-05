// =============================================================================
// FUN_005f5760
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5760
// Address:   0x005f5760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f5760 @ 0x005f5760
// Stable ID: aa_005f5760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005f5690, FUN_005f5760.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005f5760(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  short *psVar1;

  char cVar2;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009cd99c;

  param_1[2] = 0;

  cVar2 = *(char *)(param_2 + 8);

  param_1[3] = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[4] = 0xffffffff;

  param_1[7] = 0;

  param_1[9] = (int)cVar2;

  param_1[8] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0x80000000;

  param_1[0xb] = param_1;

  if (param_1[3] != 0) {

    psVar1 = (short *)(param_1[3] + 6);

    *psVar1 = *psVar1 + 1;

  }

  FUN_005f5690(param_2);

  return param_1;

}
