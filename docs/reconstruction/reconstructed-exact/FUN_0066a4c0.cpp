// =============================================================================
// FUN_0066a4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066a4c0
// Address:   0x0066a4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066a4c0 @ 0x0066a4c0
// Stable ID: aa_0066a4c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0066a4c0, SQRT.
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

void __thiscall FUN_0066a4c0(int *param_1,uint32_t /* width from decompiler */ param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fStack_28;

  float fStack_24;

  float local_20 [7];

  

  (**(code **)(*param_1 + 0x1c))(param_2,local_20);

  fVar2 = DAT_009e7920;

  fVar1 = fStack_28 * 0.0;

  fVar3 = local_20[0] * 0.0;

  fVar4 = fStack_24 * 0.0;

  param_3[3] = 0.0;

  if (fVar2 <= fVar1 + fStack_24 + fVar3) {

    *param_3 = fVar4 - fVar3;

    param_3[1] = local_20[0] - fVar1;

    param_3[2] = fVar1 - fStack_24;

  }

  else {

    *param_3 = fVar4 - local_20[0];

    param_3[1] = fVar3 - fVar1;

    param_3[2] = fStack_28 - fVar4;

  }

  fVar2 = *param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2];

  if (fVar2 == 0.0) {

    fVar2 = 0.0;

  }

  else {

    fVar2 = g_flOne / SQRT(fVar2);

  }

  *param_3 = *param_3 * fVar2;

  param_3[1] = param_3[1] * fVar2;

  param_3[2] = param_3[2] * fVar2;

  param_3[3] = fVar2 * 0.0;

  return;

}
