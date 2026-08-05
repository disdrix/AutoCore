// =============================================================================
// FUN_006f71e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f71e0
// Address:   0x006f71e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f71e0 @ 0x006f71e0
// Stable ID: aa_006f71e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006f71e0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_006f71e0(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  fVar4 = *param_3 - *param_2;

  fVar5 = param_3[1] - param_2[1];

  fVar6 = param_3[2] - param_2[2];

  fVar1 = param_3[3];

  fVar2 = param_2[3];

  fVar7 = fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6;

  fVar3 = -(fVar4 * (*param_2 - *param_1) +

           fVar5 * (param_2[1] - param_1[1]) + fVar6 * (param_2[2] - param_1[2]));

  if (fVar3 < g_flZero != (fVar3 == g_flZero)) {

    *param_4 = *param_2;

    param_4[1] = param_2[1];

    param_4[2] = param_2[2];

    param_4[3] = param_2[3];

    return 8;

  }

  if (fVar7 <= fVar3) {

    *param_4 = fVar4 + *param_2;

    param_4[1] = fVar5 + param_2[1];

    param_4[2] = fVar6 + param_2[2];

    param_4[3] = (fVar1 - fVar2) + param_2[3];

    return 4;

  }

  fVar3 = fVar3 / fVar7;

  *param_4 = *param_2;

  param_4[1] = param_2[1];

  param_4[2] = param_2[2];

  param_4[3] = param_2[3];

  *param_4 = fVar4 * fVar3 + *param_4;

  param_4[1] = fVar5 * fVar3 + param_4[1];

  param_4[2] = fVar6 * fVar3 + param_4[2];

  param_4[3] = (fVar1 - fVar2) * fVar3 + param_4[3];

  return 0;

}
