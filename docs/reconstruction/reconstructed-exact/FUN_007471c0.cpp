// =============================================================================
// FUN_007471c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007471c0
// Address:   0x007471c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007471c0 @ 0x007471c0
// Stable ID: aa_007471c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00445fa0, FUN_0044cc30, FUN_00746910, FUN_007471c0.
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

void __thiscall FUN_007471c0(int param_1,uint param_2)



{

  int iVar1;

  

  FUN_00445fa0(*(int *)(param_1 + 8) + -8,param_2);

  param_2 = param_2 & 0xffffff00;

  iVar1 = *(int *)(param_1 + 8) + -8;

  FUN_0044cc30(*(int *)(param_1 + 4),iVar1,iVar1 - *(int *)(param_1 + 4) >> 3,param_2);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  FUN_00746910();

  return;

}
