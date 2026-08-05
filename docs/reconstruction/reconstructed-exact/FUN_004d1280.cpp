// =============================================================================
// FUN_004d1280
// -----------------------------------------------------------------------------
// Stable ID: aa_004d1280
// Address:   0x004d1280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d1280 @ 0x004d1280
// Stable ID: aa_004d1280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: SQRT×4, FUN_005a58c0×3, FUN_004d1280.
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

float10 __thiscall FUN_004d1280(int param_1,float *param_2,float *param_3)



{

  float10 fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float local_3c;

  

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    local_3c = 0.0;

  }

  else {

    fVar1 = (float10)FUN_005a58c0(*param_2,param_2[2]);

    local_3c = (float)fVar1;

  }

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    fVar6 = 0.0;

  }

  else {

    fVar1 = (float10)FUN_005a58c0(*param_2 + g_flOne,param_2[2]);

    fVar6 = (float)fVar1;

  }

  fVar6 = fVar6 - local_3c;

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    fVar9 = 0.0;

  }

  else {

    fVar1 = (float10)FUN_005a58c0(*param_2,param_2[2] + g_flOne);

    fVar9 = (float)fVar1;

  }

  fVar9 = fVar9 - local_3c;

  fVar2 = fVar6 * fVar6 + g_flOne;

  if (fVar2 == 0.0) {

    fVar2 = 0.0;

  }

  else {

    fVar2 = g_flOne / SQRT(fVar2);

  }

  fVar6 = fVar6 * fVar2;

  fVar3 = fVar2 * 0.0;

  fVar4 = fVar9 * fVar9 + g_flOne;

  if (fVar4 == 0.0) {

    fVar4 = 0.0;

  }

  else {

    fVar4 = g_flOne / SQRT(fVar4);

  }

  fVar7 = fVar9 * fVar4 * fVar3 - fVar4 * fVar6;

  fVar5 = fVar4 * fVar2 - fVar3 * fVar4 * 0.0;

  fVar9 = fVar6 * fVar4 * 0.0 - fVar9 * fVar4 * fVar2;

  fVar4 = fVar9 * fVar9 + fVar5 * fVar5 + fVar7 * fVar7;

  if (fVar4 == 0.0) {

    fVar4 = 0.0;

  }

  else {

    fVar4 = g_flOne / SQRT(fVar4);

  }

  fVar9 = fVar9 * fVar4;

  fVar5 = fVar4 * fVar5;

  fVar4 = fVar4 * fVar7;

  fVar7 = fVar9 * fVar6 - fVar5 * fVar3;

  fVar8 = fVar4 * fVar3 - fVar9 * fVar2;

  fVar10 = fVar5 * fVar2 - fVar6 * fVar4;

  fVar11 = fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7;

  if (fVar11 == 0.0) {

    fVar11 = 0.0;

  }

  else {

    fVar11 = g_flOne / SQRT(fVar11);

  }

  param_3[1] = fVar4;

  param_3[3] = 0.0;

  param_3[2] = fVar11 * fVar7;

  *param_3 = fVar2;

  param_3[6] = fVar11 * fVar8;

  param_3[4] = fVar6;

  param_3[5] = fVar5;

  param_3[7] = 0.0;

  param_3[8] = fVar3;

  param_3[9] = fVar9;

  param_3[10] = fVar11 * fVar10;

  param_3[0xb] = 0.0;

  return (float10)local_3c;

}
