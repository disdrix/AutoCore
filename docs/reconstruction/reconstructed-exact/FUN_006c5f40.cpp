// =============================================================================
// FUN_006c5f40
// -----------------------------------------------------------------------------
// Stable ID: aa_006c5f40
// Address:   0x006c5f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c5f40 @ 0x006c5f40
// Stable ID: aa_006c5f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c5c80, FUN_006c5f40.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006c5f40(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  short *psVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  uVar2 = *param_2;

  *param_1 = &PTR_FUN_00a0d314;

  param_1[2] = uVar2;

  iVar3 = param_2[1];

  param_1[3] = iVar3;

  psVar1 = (short *)(iVar3 + 6);

  *psVar1 = *psVar1 + 1;

  *param_1 = &PTR_FUN_00a0d348;

  param_1[4] = param_2[2];

  FUN_006c5c80();

  return param_1;

}
