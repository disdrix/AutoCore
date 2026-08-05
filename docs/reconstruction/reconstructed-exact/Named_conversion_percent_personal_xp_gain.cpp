// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005781b0×2, FUN_00578190, FUN_0061c7c0.
//  - Strings: "conversion_percent] (personal xp gain %%)\n"; "op_scalar_1] (convoy xp gain %%)\n".
//  - Return sites: 1.

// =============================================================================
// Named_conversion_percent_personal_xp_gain
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c7c0
// Address:   0x0061c7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "conversion_percent] (personal xp gain %%)
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_conversion_percent_personal_xp_gain(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(float *)(param_1 + 0xe0) != g_flZero) {

    FUN_005781b0(param_3,param_2,"conversion_percent] (personal xp gain %%)\n",1);

  }

  if (*(float *)(param_1 + 0x160) != g_flZero) {

    FUN_005781b0(param_3,param_2,"op_scalar_1] (convoy xp gain %%)\n",1);

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
