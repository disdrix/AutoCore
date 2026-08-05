// =============================================================================
// FUN_0053fae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053fae0
// Address:   0x0053fae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053fae0 @ 0x0053fae0
// Stable ID: aa_0053fae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0053fae0.
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

void __thiscall FUN_0053fae0(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  fVar1 = param_3[1];

  fVar2 = param_2[2];

  fVar5 = *param_3 * param_2[2] - param_3[2] * *param_2;

  fVar6 = *param_2 * param_3[1] - param_2[1] * *param_3;

  fVar3 = param_3[2];

  fVar4 = param_2[1];

  param_1[2] = fVar6;

  param_1[1] = fVar5;

  *param_1 = fVar3 * fVar4 - fVar1 * fVar2;

  param_1[3] = 0.0;

  fVar1 = param_2[3];

  *param_1 = *param_3 * fVar1 + *param_1;

  fVar5 = param_3[1] * fVar1 + fVar5;

  param_1[1] = fVar5;

  param_1[2] = param_3[2] * fVar1 + fVar6;

  param_1[3] = param_3[3] * fVar1;

  fVar1 = param_3[3];

  *param_1 = *param_2 * fVar1 + *param_1;

  param_1[1] = param_2[1] * fVar1 + fVar5;

  param_1[2] = fVar1 * param_2[2] + param_1[2];

  param_1[3] = fVar1 * param_2[3] + param_1[3];

  param_1[3] = param_3[3] * param_2[3] -

               (*param_2 * *param_3 + param_2[1] * param_3[1] + param_3[2] * param_2[2]);

  return;

}
