// =============================================================================
// FUN_006f7340
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7340
// Address:   0x006f7340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7340 @ 0x006f7340
// Stable ID: aa_006f7340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006f7340, SQRT.
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

void FUN_006f7340(float *param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  

  fVar3 = *param_1 - param_1[4];

  fVar6 = param_1[1] - param_1[5];

  fVar4 = param_1[2] - param_1[6];

  fVar1 = param_1[8] - param_1[4];

  fVar2 = param_1[9] - param_1[5];

  fVar10 = param_1[10] - param_1[6];

  fVar7 = fVar3 * fVar3 + fVar6 * fVar6 + fVar4 * fVar4;

  fVar9 = fVar1 * fVar1 + fVar2 * fVar2 + fVar10 * fVar10;

  fVar5 = fVar1 * fVar3 + fVar2 * fVar6 + fVar10 * fVar4;

  fVar8 = g_flOne / (fVar9 * fVar7 - fVar5 * fVar5);

  *param_2 = fVar8 * fVar7;

  param_2[1] = fVar8 * fVar9;

  param_2[2] = fVar8 * fVar5;

  fVar5 = fVar10 * fVar6 - fVar2 * fVar4;

  fVar4 = fVar4 * fVar1 - fVar10 * fVar3;

  fVar1 = fVar2 * fVar3 - fVar6 * fVar1;

  param_2[3] = g_flOne / SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar1 * fVar1);

  return;

}
