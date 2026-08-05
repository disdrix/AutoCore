// =============================================================================
// FUN_006c7190
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7190
// Address:   0x006c7190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c7190 @ 0x006c7190
// Stable ID: aa_006c7190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ABS×12, FUN_006c7190.
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

void FUN_006c7190(float *param_1,float *param_2,float param_3,float *param_4)



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

  float fVar11;

  float fVar12;

  float fVar13;

  

  fVar1 = *param_2;

  fVar2 = param_2[1];

  fVar12 = param_2[2];

  fVar3 = param_1[1];

  fVar4 = param_1[2];

  fVar5 = param_1[3];

  fVar6 = param_1[5];

  fVar7 = param_1[6];

  fVar8 = param_1[7];

  fVar9 = param_1[9];

  fVar10 = param_1[10];

  fVar11 = param_1[0xb];

  fVar13 = ABS(fVar12 * param_1[8]) + param_3 + ABS(fVar2 * param_1[4]) + ABS(fVar1 * *param_1);

  param_4[4] = fVar13;

  param_4[5] = ABS(fVar12 * fVar9) + param_3 + ABS(fVar2 * fVar6) + ABS(fVar1 * fVar3);

  param_4[6] = ABS(fVar12 * fVar10) + param_3 + ABS(fVar2 * fVar7) + ABS(fVar1 * fVar4);

  param_4[7] = ABS(fVar12 * fVar11) + param_3 + ABS(fVar2 * fVar8) + ABS(fVar1 * fVar5);

  *param_4 = -fVar13;

  param_4[1] = -param_4[5];

  param_4[2] = -param_4[6];

  param_4[3] = -param_4[7];

  param_4[4] = param_4[4] + param_1[0xc];

  param_4[5] = param_1[0xd] + param_4[5];

  param_4[6] = param_1[0xe] + param_4[6];

  param_4[7] = param_1[0xf] + param_4[7];

  *param_4 = *param_4 + param_1[0xc];

  param_4[1] = param_1[0xd] + param_4[1];

  param_4[2] = param_1[0xe] + param_4[2];

  param_4[3] = param_1[0xf] + param_4[3];

  return;

}
