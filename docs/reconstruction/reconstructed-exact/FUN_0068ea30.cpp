// =============================================================================
// FUN_0068ea30
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ea30
// Address:   0x0068ea30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068ea30 @ 0x0068ea30
// Stable ID: aa_0068ea30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0068ea30.
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

void __thiscall FUN_0068ea30(float *param_1,float *param_2,float *param_3)



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

  

  fVar1 = param_3[8];

  fVar2 = param_1[2];

  fVar3 = param_3[2];

  fVar4 = *param_1;

  fVar5 = param_3[5];

  fVar6 = param_1[1];

  fVar7 = param_3[7];

  fVar8 = param_1[2];

  fVar9 = param_3[1];

  fVar10 = *param_1;

  fVar11 = param_3[4];

  fVar12 = param_1[1];

  *param_2 = *param_3 * *param_1 + param_3[3] * param_1[1] + param_3[6] * param_1[2];

  param_2[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;

  param_2[2] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;

  return;

}
