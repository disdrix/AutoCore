// =============================================================================
// FUN_0054cac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cac0
// Address:   0x0054cac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054cac0 @ 0x0054cac0
// Stable ID: aa_0054cac0
// Embedded strings (evidence for future rename):
//   - "conversion_percent] (item converts to %% sell value)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0054cac0, FUN_00578190, FUN_005781b0.
//  - Strings: "conversion_percent] (item converts to %% sell value)\n".
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

void FUN_0054cac0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(float *)(param_1 + 0xe0) != g_flZero) {

    FUN_005781b0(param_3,param_2,"conversion_percent] (item converts to %% sell value)\n",1);

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
