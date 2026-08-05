// =============================================================================
// FUN_0043b500
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b500
// Address:   0x0043b500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043b500 @ 0x0043b500
// Stable ID: aa_0043b500
// Embedded strings (evidence for future rename):
//   - "%+#.8g"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043b500, FUN_00767160.
//  - Strings: "%+#.8g".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0043b500(uint32_t /* width from decompiler */ *param_1,float *param_2)



{

  uint uVar1;

  

  if (param_1[7] == 0) {

    param_2 = (float *)*param_2;

    uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&param_2,4);

    param_1[1] = param_1[1] | uVar1;

    return param_1[1];

  }

  uVar1 = FUN_00767160("%+#.8g",(double)*param_2);

  param_1[1] = param_1[1] | uVar1;

  param_1[8] = 0;

  uVar1 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

  param_1[1] = param_1[1] | uVar1;

  return param_1[1];

}
