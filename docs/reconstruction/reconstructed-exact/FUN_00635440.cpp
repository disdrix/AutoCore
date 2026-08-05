// =============================================================================
// FUN_00635440
// -----------------------------------------------------------------------------
// Stable ID: aa_00635440
// Address:   0x00635440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635440 @ 0x00635440
// Stable ID: aa_00635440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00635440, FUN_00651b10, FUN_00651b60.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00635440(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  short *psVar1;

  int iVar2;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  *param_1 = &PTR_FUN_009e390c;

  param_1[2] = &PTR_LAB_009e38fc;

  iVar2 = *(int *)(param_2 + 0x14);

  param_1[8] = iVar2;

  psVar1 = (short *)(iVar2 + 6);

  *psVar1 = *psVar1 + 1;

  FUN_00651b10(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0xc));

  FUN_00651b60(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0x10));

  param_1[6] = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  param_1[9] = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  return param_1;

}
