// =============================================================================
// FUN_00645890
// -----------------------------------------------------------------------------
// Stable ID: aa_00645890
// Address:   0x00645890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00645890 @ 0x00645890
// Stable ID: aa_00645890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ABS, FUN_00645890.
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

uint32_t /* width from decompiler */ __thiscall FUN_00645890(float *param_1,float param_2)



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

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  

  fVar14 = param_1[5] * param_1[10] - param_1[6] * param_1[9];

  fVar1 = *param_1;

  fVar2 = param_1[8];

  fVar3 = param_1[1];

  fVar15 = param_1[8] * param_1[6] - param_1[4] * param_1[10];

  fVar16 = param_1[4] * param_1[9] - param_1[5] * param_1[8];

  fVar4 = param_1[2];

  fVar5 = *param_1;

  fVar6 = param_1[1];

  fVar7 = *param_1;

  fVar8 = param_1[4];

  fVar9 = param_1[2];

  fVar10 = param_1[4];

  fVar11 = param_1[1];

  fVar12 = param_1[5];

  fVar13 = *param_1;

  fVar17 = *param_1 * fVar14 + fVar15 * param_1[1] + param_1[2] * fVar16;

  if (param_2 * param_2 * param_2 < ABS(fVar17)) {

    fVar17 = g_flOne / fVar17;

    *param_1 = fVar14 * fVar17;

    param_1[1] = (param_1[9] * param_1[2] - param_1[10] * param_1[1]) * fVar17;

    param_1[2] = (param_1[6] * fVar6 - param_1[2] * param_1[5]) * fVar17;

    param_1[3] = 0.0;

    param_1[4] = fVar15 * fVar17;

    param_1[5] = (param_1[10] * fVar1 - fVar4 * param_1[8]) * fVar17;

    param_1[6] = (fVar8 * fVar9 - param_1[6] * fVar7) * fVar17;

    param_1[7] = 0.0;

    param_1[8] = fVar16 * fVar17;

    param_1[9] = (fVar2 * fVar3 - param_1[9] * fVar5) * fVar17;

    param_1[10] = (fVar12 * fVar13 - fVar10 * fVar11) * fVar17;

    param_1[0xb] = 0.0;

    return 0;

  }

  return 1;

}
