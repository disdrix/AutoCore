// =============================================================================
// FUN_00635120
// -----------------------------------------------------------------------------
// Stable ID: aa_00635120
// Address:   0x00635120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635120 @ 0x00635120
// Stable ID: aa_00635120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00635120, FUN_00651b10, FUN_00651b60.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00635120(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  short *psVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = &PTR_LAB_009e3a68;

  param_1[5] = 0;

  param_1[4] = 0;

  param_1[3] = 0;

  param_1[6] = 0;

  *param_1 = &PTR_FUN_009e38d0;

  param_1[2] = &PTR_LAB_009e38c0;

  iVar2 = *(int *)(param_2 + 0x1c);

  param_1[8] = iVar2;

  psVar1 = (short *)(iVar2 + 6);

  *psVar1 = *psVar1 + 1;

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

  param_1[0xc] = 0;

  param_1[9] = uVar3;

  FUN_00651b10(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0xc));

  FUN_00651b60(*(uint32_t /* width from decompiler */ *)(param_1[8] + 0x10));

  param_1[6] = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  *(uint8_t *)(param_1 + 0xb) = *(uint8_t *)(param_2 + 0xc);

  param_1[10] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint8_t *)((int)param_1 + 0x2d) = *(uint8_t *)(param_2 + 0x14);

  return param_1;

}
