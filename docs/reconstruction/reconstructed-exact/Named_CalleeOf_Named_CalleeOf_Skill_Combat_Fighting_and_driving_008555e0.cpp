// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_008555e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008555e0
// Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
// Address:   0x008555e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0076df50×3, FUN_007afe80×2, FUN_0096d460×2, FUN_0040cf90, FUN_0040d1a0, FUN_0076f5f0, FUN_008555e0, fcos.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
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



void Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_008555e0(void)



{

  int in_EAX;

  int iVar1;

  int *piVar2;

  int iVar3;

  float10 fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ uVar6;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if (*(int *)(in_EAX + 0x298) != 0) {

    iVar1 = (**(code **)(**(int **)(in_EAX + 0x298) + 0xc))();

    fVar5 = *(float *)(iVar1 + 0x88) * *(float *)(iVar1 + 0x88) +

            *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x8c) +

            *(float *)(iVar1 + 0x80) * *(float *)(iVar1 + 0x80) +

            *(float *)(iVar1 + 0x84) * *(float *)(iVar1 + 0x84);

    if ((_DAT_00a240ec <= fVar5) || (fVar5 <= DAT_00aaa640)) {

      fVar5 = g_flOne / fVar5;

      fStack_10 = (0.0 - *(float *)(iVar1 + 0x80)) * fVar5;

      fStack_c = (0.0 - *(float *)(iVar1 + 0x84)) * fVar5;

      fStack_8 = (0.0 - *(float *)(iVar1 + 0x88)) * fVar5;

      fStack_4 = *(float *)(iVar1 + 0x8c) * fVar5;

    }

    fStack_2c = 0.0;

    fStack_28 = g_flOne;

    fStack_24 = 0.0;

    FUN_0076f5f0(&fStack_1c,&fStack_2c);

    fVar4 = (float10)fsin((float10)_DAT_00aaaa88);

    fStack_2c = (float)((float10)fStack_1c * fVar4);

    fStack_28 = (float)((float10)fStack_18 * fVar4);

    fStack_24 = (float)((float10)fStack_14 * fVar4);

    fVar4 = (float10)fcos((float10)_DAT_00aaaa88);

    fStack_20 = (float)fVar4;

    FUN_0076df50(&fStack_10,&fStack_10,&fStack_2c);

    iVar1 = (**(code **)(**(int **)(in_EAX + 0x298) + 0xc))();

    FUN_0076df50(&fStack_10,&fStack_10,iVar1 + 0x80);

    iVar1 = (**(code **)(**(int **)(in_EAX + 0x298) + 0x10))(3);

    FUN_0076df50(iVar1 + 0x80,iVar1 + 0x80,&fStack_14);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    if (*(int *)(in_EAX + 0x514) != 0) {

      piVar2 = (int *)FUN_0096d460(0x1f);

      iVar1 = (**(code **)(*piVar2 + 0xc))();

      iVar1 = iVar1 + 0x90;

      uVar6 = 3;

      (**(code **)(**(int **)(in_EAX + 0x514) + 0x10))(3,iVar1);

      FUN_0040cf90(uVar6);

      piVar2 = (int *)FUN_0096d460(0x1f);

      iVar3 = (**(code **)(*piVar2 + 0xc))();

      (**(code **)(**(int **)(in_EAX + 0x514) + 0x10))(3,iVar3 + 0x80);

      FUN_0040d1a0(iVar1);

    }

    FUN_007afe80(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x298),1);

    if (*(int *)(in_EAX + 0x514) != 0) {

      FUN_007afe80(*(int *)(in_EAX + 0x514),1);

    }

  }

  return;

}
