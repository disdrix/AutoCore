// =============================================================================
// FUN_00643270
// -----------------------------------------------------------------------------
// Stable ID: aa_00643270
// Address:   0x00643270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00643270 @ 0x00643270
// Stable ID: aa_00643270
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00643270.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00643270(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  short *psVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  param_1[2] = param_2;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e4464;

  *(uint8_t *)(param_1 + 6) = 1;

  if (param_1[2] != 0) {

    psVar1 = (short *)(param_1[2] + 6);

    *psVar1 = *psVar1 + 1;

  }

  uVar2 = (**(code **)(*DAT_00b05060 + 8))(0x40,param_3,0x15);

  param_1[5] = param_3;

  param_1[3] = uVar2;

  param_1[4] = 0;

  return param_1;

}
