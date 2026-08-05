// =============================================================================
// FUN_00641340
// -----------------------------------------------------------------------------
// Stable ID: aa_00641340
// Address:   0x00641340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641340 @ 0x00641340
// Stable ID: aa_00641340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00641340.
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

void __thiscall

FUN_00641340(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  short *psVar1;

  

  param_1[4] = param_3;

  param_1[5] = param_4;

  param_1[6] = param_5;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e40b8;

  param_1[2] = 0;

  param_1[3] = param_2;

  if (param_2 != 0) {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  }

  if (param_1[4] != 0) {

    psVar1 = (short *)(param_1[4] + 6);

    *psVar1 = *psVar1 + 1;

  }

  if (param_1[6] != 0) {

    psVar1 = (short *)(param_1[6] + 6);

    *psVar1 = *psVar1 + 1;

  }

  return;

}
