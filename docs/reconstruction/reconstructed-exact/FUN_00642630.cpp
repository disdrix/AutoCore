// =============================================================================
// FUN_00642630
// -----------------------------------------------------------------------------
// Stable ID: aa_00642630
// Address:   0x00642630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00642630 @ 0x00642630
// Stable ID: aa_00642630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00642630, FUN_006560f0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00642630(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e4378;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0x80000000;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0x80000000;

  param_1[9] = 0;

  *(uint8_t *)(param_1 + 10) = 0;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x15);

  *(uint16_t *)(iVar1 + 4) = 0x10;

  uVar2 = FUN_006560f0(param_1 + 2);

  param_1[5] = uVar2;

  return param_1;

}
