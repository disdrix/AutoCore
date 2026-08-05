// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00508a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00508a00
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00508a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, ABS, FUN_00508a00, FUN_007a4170.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
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

float10 Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_00508a00(float param_1,uint32_t /* width from decompiler */ param_2,char param_3,float param_4)



{

  ushort uVar1;

  float fVar2;

  int iVar3;

  float10 fVar4;

  

  if (param_4 == g_flZero) {

    CVOGReaction_RandomUnitScalar(param_2);

    fVar4 = (float10)FUN_007a4170(param_2);

    param_1 = (float)(fVar4 * (float10)param_1);

  }

  else {

    param_1 = param_1 * param_4;

  }

  iVar3 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar3 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

  }

  fVar2 = DAT_00a0f298;

  uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

  if (((float)uVar1 * DAT_00aaa638 < fVar2) && (param_3 != '\0')) {

    param_1 = param_1 * DAT_00aaa668;

  }

  if (ABS(param_1) < DAT_00a0f718) {

    param_1 = 0.0;

  }

  return (float10)param_1;

}
