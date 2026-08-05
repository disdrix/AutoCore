// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_005a5970
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5970
// Callee of Skill_Skill_d_had_invalid_creature_d
// Address:   0x005a5970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005a5970, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d
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

void __thiscall Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_005a5970(int *param_1,float *param_2,float param_3,float param_4)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  float unaff_ESI;

  float unaff_EDI;

  float10 fVar5;

  float10 fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  

  uVar2 = (uint)(param_3 * (float)param_1[0xc]);

  uVar4 = param_1[3] - 2;

  if ((int)(((int)uVar2 < 1) - 1 & uVar2) < (int)uVar4) {

    uVar4 = ((int)uVar2 < 1) - 1 & uVar2;

  }

  uVar3 = (uint)(param_4 * (float)param_1[0xe]);

  uVar2 = param_1[4] - 2;

  if ((int)(((int)uVar3 < 1) - 1 & uVar3) < (int)uVar2) {

    uVar2 = ((int)uVar3 < 1) - 1 & uVar3;

  }

  fVar5 = (float10)(**(code **)(*param_1 + 0x30))(uVar4 + 1,uVar2);

  (**(code **)(*param_1 + 0x30))(uVar4,uVar2 + 1);

  if (((float)fVar5 - (float)(int)uVar2) + (fStack_2c - (float)(int)uVar4) <= g_flOne) {

    fVar5 = (float10)(**(code **)(*param_1 + 0x30))(uVar4,uVar2);

    fVar6 = (float10)unaff_EDI - fVar5;

    fVar5 = (float10)unaff_ESI - fVar5;

  }

  else {

    fVar5 = (float10)(**(code **)(*param_1 + 0x30))(uStack_24,uStack_28);

    fVar6 = fVar5 - (float10)unaff_ESI;

    fVar5 = fVar5 - (float10)unaff_EDI;

  }

  fVar7 = 0.0;

  fVar1 = (float)param_1[0xd];

  fVar9 = 0.0 - (float)fVar6 * (float)param_1[0xc];

  fVar10 = 0.0 - (float)fVar5 * (float)param_1[0xe];

  fVar8 = fVar10 * fVar10 + fVar9 * fVar9 + fVar1 * fVar1;

  if (fVar8 != 0.0) {

    fVar7 = g_flOne / SQRT(fVar8);

  }

  *param_2 = fVar7 * fVar9;

  param_2[1] = fVar7 * fVar1;

  param_2[2] = fVar7 * fVar10;

  param_2[3] = fVar7;

  return;

}
