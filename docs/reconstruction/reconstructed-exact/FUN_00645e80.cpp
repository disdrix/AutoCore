// =============================================================================
// FUN_00645e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00645e80
// Address:   0x00645e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00645e80 @ 0x00645e80
// Stable ID: aa_00645e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00645c90, FUN_00645e80.
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

void __thiscall FUN_00645e80(float *param_1,uint32_t /* width from decompiler */ param_2)



{

  float *extraout_EDX;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  

  FUN_00645c90(param_1,param_2);

  *param_1 = extraout_EDX[8] * local_38 + extraout_EDX[4] * local_3c + *extraout_EDX * local_40;

  param_1[1] = extraout_EDX[9] * local_38 + extraout_EDX[5] * local_3c + local_40 * extraout_EDX[1];

  param_1[2] = extraout_EDX[10] * local_38 + extraout_EDX[6] * local_3c + local_40 * extraout_EDX[2]

  ;

  param_1[3] = 0.0;

  param_1[4] = extraout_EDX[8] * local_28 + extraout_EDX[4] * local_2c + *extraout_EDX * local_30;

  param_1[5] = extraout_EDX[9] * local_28 + extraout_EDX[5] * local_2c + local_30 * extraout_EDX[1];

  param_1[6] = extraout_EDX[10] * local_28 + extraout_EDX[6] * local_2c + local_30 * extraout_EDX[2]

  ;

  param_1[7] = 0.0;

  param_1[8] = extraout_EDX[8] * local_18 + extraout_EDX[4] * local_1c + *extraout_EDX * local_20;

  param_1[9] = extraout_EDX[9] * local_18 + extraout_EDX[5] * local_1c + local_20 * extraout_EDX[1];

  param_1[10] = extraout_EDX[10] * local_18 + extraout_EDX[6] * local_1c +

                local_20 * extraout_EDX[2];

  param_1[0xb] = 0.0;

  return;

}
