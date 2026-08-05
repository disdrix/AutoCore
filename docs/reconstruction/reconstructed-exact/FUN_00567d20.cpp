// =============================================================================
// FUN_00567d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00567d20
// Address:   0x00567d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00567d20 @ 0x00567d20
// Stable ID: aa_00567d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: SQRT×2, FUN_00567d20.
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

void __thiscall FUN_00567d20(float *param_1,float *param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  float fVar4;

  float fVar5;

  int local_c [3];

  

  fVar4 = param_2[5] + *param_2 + param_2[10];

  if (g_flZero < fVar4) {

    fVar4 = SQRT(fVar4 + g_flOne);

    fVar5 = DAT_00a0f298 / fVar4;

    fVar4 = fVar4 * DAT_00a0f298;

    *param_1 = (param_2[6] - param_2[9]) * fVar5;

    param_1[1] = (param_2[8] - param_2[2]) * fVar5;

    param_1[2] = (param_2[1] - param_2[4]) * fVar5;

    param_1[3] = fVar4;

    return;

  }

  local_c[0] = 1;

  local_c[1] = 2;

  local_c[2] = 0;

  uVar3 = (uint)(*param_2 <= param_2[5] && param_2[5] != *param_2);

  if (param_2[uVar3 * 5] <= param_2[10] && param_2[10] != param_2[uVar3 * 5]) {

    uVar3 = 2;

  }

  iVar1 = local_c[uVar3];

  iVar2 = local_c[iVar1];

  fVar4 = SQRT((param_2[uVar3 * 5] - (param_2[iVar2 * 5] + param_2[iVar1 * 5])) + g_flOne);

  fVar5 = DAT_00a0f298 / fVar4;

  param_1[uVar3] = fVar4 * DAT_00a0f298;

  param_1[3] = (param_2[iVar2 + iVar1 * 4] - param_2[iVar1 + iVar2 * 4]) * fVar5;

  param_1[iVar1] = (param_2[uVar3 + iVar1 * 4] + param_2[iVar1 + uVar3 * 4]) * fVar5;

  param_1[iVar2] = (param_2[uVar3 + iVar2 * 4] + param_2[iVar2 + uVar3 * 4]) * fVar5;

  return;

}
