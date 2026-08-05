// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bbe80
// -----------------------------------------------------------------------------
// Stable ID: aa_006bbe80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bbe80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×11, goto×3, return×2.
//  - Notable callees: ABS×4, rsqrtss×2, FUN_006bbe80.
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



float10 Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bbe80(int param_1,float *param_2,float *param_3,float *param_4,float *param_5)



{

  uint8_t auVar1 [16];

  float fVar2;

  float fVar3;

  float10 fVar4;

  float10 fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar14;

  float fVar15;

  uint8_t auVar11 [16];

  uint8_t auVar12 [16];

  uint8_t auVar13 [16];

  float fVar16;

  uint8_t auVar17 [16];

  uint8_t auVar18 [16];

  

  fVar16 = *param_2 - *param_4;

  fVar2 = param_2[1] - param_4[1];

  fVar3 = param_2[2] - param_4[2];

  fVar7 = fVar2 * fVar2;

  fVar8 = fVar3 * fVar3;

  auVar11._4_4_ = fVar7;

  auVar11._0_4_ = fVar7;

  auVar11._8_4_ = fVar7;

  auVar11._12_4_ = fVar7;

  auVar12._4_12_ = auVar11._4_12_;

  auVar12._0_4_ = fVar7 + fVar16 * fVar16;

  auVar13._4_4_ = fVar8;

  auVar13._0_4_ = fVar8 + auVar12._0_4_;

  auVar13._8_4_ = fVar8;

  auVar13._12_4_ = fVar8;

  auVar13 = rsqrtss(auVar12,auVar13);

  fVar7 = auVar13._0_4_;

  fVar6 = fVar7 * 0.5 * (3.0 - (fVar8 + auVar12._0_4_) * fVar7 * fVar7);

  fVar8 = *param_3;

  fVar9 = param_3[1];

  fVar14 = param_3[2];

  fVar7 = -(fVar14 * fVar6 * fVar3 + fVar9 * fVar6 * fVar2 + fVar8 * fVar6 * fVar16);

  fVar10 = (param_4[1] - param_5[1]) * fVar14 - (param_4[2] - param_5[2]) * fVar9;

  fVar14 = (param_4[2] - param_5[2]) * fVar8 - (*param_4 - *param_5) * fVar14;

  fVar15 = (*param_4 - *param_5) * fVar9 - (param_4[1] - param_5[1]) * fVar8;

  fVar8 = fVar14 * fVar14;

  fVar9 = fVar15 * fVar15;

  auVar17._4_4_ = fVar8;

  auVar17._0_4_ = fVar8;

  auVar17._8_4_ = fVar8;

  auVar17._12_4_ = fVar8;

  auVar18._4_12_ = auVar17._4_12_;

  auVar18._0_4_ = fVar8 + fVar10 * fVar10;

  auVar1._4_4_ = fVar9;

  auVar1._0_4_ = fVar9 + auVar18._0_4_;

  auVar1._8_4_ = fVar9;

  auVar1._12_4_ = fVar9;

  auVar13 = rsqrtss(auVar18,auVar1);

  fVar8 = auVar13._0_4_;

  fVar8 = fVar8 * 0.5 * (3.0 - (fVar9 + auVar18._0_4_) * fVar8 * fVar8);

  fVar16 = fVar8 * fVar15 * fVar6 * fVar3 +

           fVar8 * fVar14 * fVar6 * fVar2 + fVar8 * fVar10 * fVar6 * fVar16;

  if (fVar7 * fVar7 + fVar16 * fVar16 < *(float *)(param_1 + 8)) {

    return (float10)_DAT_00a0d168;

  }

  fVar2 = ABS(fVar7);

  if ((_DAT_00a110e4 <= fVar2) || (_DAT_00a0d164 <= ABS(fVar16))) {

    if (fVar2 <= ABS(fVar16)) {

      if ((_DAT_00a0d160 <= fVar16) || (_DAT_00a110e4 <= fVar2)) {

        fVar3 = g_flZero;

        if (fVar16 < DAT_00aaa640) {

          fVar3 = DAT_00aaa690;

        }

        fVar5 = (float10)fVar3 + (float10)fVar7 / (float10)fVar16;

      }

      else {

        fVar5 = (float10)DAT_00aaa690;

      }

      if (ABS(fVar5) < (float10)*(float *)(param_1 + 0x30)) goto LAB_006bc141;

      if ((fVar16 <= _DAT_00a110e4) || (_DAT_00a0d164 <= fVar2)) goto LAB_006bc172;

      fVar4 = (float10)DAT_00a0f6a4;

    }

    else {

      fVar5 = (float10)g_flLevelUpUiBase_Inferred - (float10)fVar16 / (float10)fVar7;

      if (DAT_00aaa640 <= fVar7) {

LAB_006bc172:

        fVar4 = (float10)g_flZero;

      }

      else {

        fVar4 = (float10)DAT_00aaa690;

      }

    }

    fVar4 = fVar4 + fVar5;

  }

  else {

    if (fVar16 < g_flZero) {

      fVar4 = (float10)DAT_00aaa690;

      goto LAB_006bc17a;

    }

LAB_006bc141:

    fVar4 = (float10)g_flZero;

  }

LAB_006bc17a:

  if (fVar4 < -(float10)*(float *)(param_1 + 0x30)) {

    fVar4 = fVar4 + (float10)DAT_00a0f6a4;

  }

  if ((float10)DAT_00a0f6a4 < fVar4) {

    fVar4 = (float10)g_flZero;

  }

  return fVar4;

}
