// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bba50
// -----------------------------------------------------------------------------
// Stable ID: aa_006bba50
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bba50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: rsqrtss×2, FUN_006bba50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bba50(float *param_1,float *param_2,float *param_3)



{

  uint8_t auVar1 [16];

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  uint8_t auVar9 [16];

  uint8_t auVar10 [16];

  uint8_t auVar11 [16];

  uint8_t auVar12 [16];

  uint8_t auVar13 [16];

  

  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {

    *param_3 = 0.0;

    param_3[1] = -1.0;

    param_3[2] = 0.0;

    param_3[3] = 0.0;

    return;

  }

  fVar2 = *param_1 - *param_2;

  fVar4 = param_1[1] - param_2[1];

  fVar7 = param_1[2] - param_2[2];

  fVar3 = fVar4 * fVar4;

  fVar6 = fVar7 * fVar7;

  auVar9._4_4_ = fVar3;

  auVar9._0_4_ = fVar3;

  auVar9._8_4_ = fVar3;

  auVar9._12_4_ = fVar3;

  auVar10._4_12_ = auVar9._4_12_;

  auVar10._0_4_ = fVar3 + fVar2 * fVar2;

  auVar11._4_4_ = fVar6;

  auVar11._0_4_ = fVar6 + auVar10._0_4_;

  auVar11._8_4_ = fVar6;

  auVar11._12_4_ = fVar6;

  auVar11 = rsqrtss(auVar10,auVar11);

  fVar3 = auVar11._0_4_;

  fVar3 = fVar3 * 0.5 * (3.0 - (fVar6 + auVar10._0_4_) * fVar3 * fVar3);

  fVar2 = fVar3 * fVar2;

  fVar4 = fVar3 * fVar4;

  fVar7 = fVar3 * fVar7;

  fVar3 = fVar3 * (param_1[3] - param_2[3]);

  fVar6 = fVar4 * 0.0 - fVar7 * 1.0;

  fVar5 = fVar7 * 0.0 - fVar2 * 0.0;

  fVar8 = fVar2 * 1.0 - fVar4 * 0.0;

  *param_3 = fVar6;

  param_3[1] = fVar5;

  param_3[2] = fVar8;

  param_3[3] = fVar3 * 0.0 - fVar3 * 0.0;

  if (fVar8 * fVar8 + fVar5 * fVar5 + fVar6 * fVar6 < _DAT_00a0d150) {

    *param_3 = fVar4 * 1.0 - fVar7 * 0.0;

    param_3[1] = fVar7 * 0.0 - fVar2 * 1.0;

    param_3[2] = fVar2 * 0.0 - fVar4 * 0.0;

    param_3[3] = fVar3 * 0.0 - fVar3 * 0.0;

  }

  fVar2 = *param_3;

  fVar4 = param_3[1];

  fVar7 = param_3[2];

  fVar3 = fVar4 * fVar4;

  fVar6 = fVar7 * fVar7;

  auVar12._4_4_ = fVar3;

  auVar12._0_4_ = fVar3;

  auVar12._8_4_ = fVar3;

  auVar12._12_4_ = fVar3;

  auVar13._4_12_ = auVar12._4_12_;

  auVar13._0_4_ = fVar3 + fVar2 * fVar2;

  auVar1._4_4_ = fVar6;

  auVar1._0_4_ = fVar6 + auVar13._0_4_;

  auVar1._8_4_ = fVar6;

  auVar1._12_4_ = fVar6;

  auVar11 = rsqrtss(auVar13,auVar1);

  fVar3 = auVar11._0_4_;

  fVar3 = fVar3 * 0.5 * (3.0 - (fVar6 + auVar13._0_4_) * fVar3 * fVar3);

  *param_3 = fVar3 * fVar2;

  param_3[1] = fVar3 * fVar4;

  param_3[2] = fVar3 * fVar7;

  param_3[3] = fVar3 * param_3[3];

  return;

}
