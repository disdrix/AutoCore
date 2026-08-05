// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00585e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00585e00
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics
// Address:   0x00585e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004e88e0×2, Client_SendLogicUiPacket, FUN_00404bd0, FUN_0040cf90, FUN_005130e0, FUN_00516c40, FUN_0051aed0, FUN_00585e00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGCreature_SetupGraphics
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



float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00585e00(int param_1,char param_2)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  float10 fVar7;

  float10 fVar8;

  float fVar9;

  uint32_t /* width from decompiler */ uVar10;

  float fStack_198;

  float fStack_190;

  float fStack_18c;

  float fStack_188;

  uint32_t /* width from decompiler */ uStack_184;

  float fStack_180;

  uint32_t /* width from decompiler */ uStack_17c;

  uint32_t /* width from decompiler */ uStack_178;

  uint32_t /* width from decompiler */ uStack_174;

  uint32_t /* width from decompiler */ uStack_170;

  uint32_t /* width from decompiler */ uStack_16c;

  uint8_t auStack_15c [4];

  uint8_t auStack_158 [8];

  uint8_t auStack_150 [12];

  uint32_t /* width from decompiler */ uStack_144;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  

  if ((*(int *)(param_1 + 8) != 0) && (cVar2 = FUN_005130e0(1), cVar2 != '\0')) {

    iVar3 = (**(code **)(**(int **)(param_1 + 8) + 0x48))();

    fVar9 = g_flLevelUpUiBase_Inferred / (*(float *)(iVar3 + 0xc) * g_flLevelUpUiBase_Inferred);

    fStack_190 = fVar9 * DAT_00a0f298;

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xb8))(fVar9);

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

    uStack_184 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x84 + param_1);

    iVar3 = iVar3 + 0x84 + param_1;

    uStack_17c = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

    fStack_180 = *(float *)(iVar3 + 4) + fVar9;

    uStack_178 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

    pfVar4 = (float *)FUN_004e88e0(auStack_158,&uStack_184);

    fStack_190 = *pfVar4;

    fStack_18c = pfVar4[1];

    fStack_188 = pfVar4[2];

    uVar10 = 3;

    (**(code **)(**(int **)(param_1 + 8) + 0x10))(3,&fStack_190);

    FUN_0040cf90(uVar10);

    if (param_2 == '\0') {

      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

      if (((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + 0xe8a0), piVar1 != (int *)0x0)) &&

         (iVar3 = (**(code **)(*piVar1 + 0x1dc))(), *(int *)(iVar3 + 0x250) != 0)) {

        puVar5 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1a0))();

        uStack_178 = *puVar5;

        uStack_174 = puVar5[1];

        uStack_170 = puVar5[2];

        uStack_16c = puVar5[3];

        FUN_004e88e0(auStack_15c,&uStack_178);

        fVar7 = (float10)FUN_00404bd0(auStack_15c);

        fVar8 = (float10)DAT_00a0f524;

        uVar10 = FUN_00516c40(iVar3);

        FUN_0051aed0(fVar7 < fVar8,uVar10);

      }

      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

      iVar6 = iVar3 + param_1;

      if (*(int *)(iVar3 + 0xa8 + param_1) != 0) {

        uStack_128 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164);

        uStack_124 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168);

        uStack_120 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x16c);

        uStack_11c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x170);

        uStack_134 = 0x1f;

        uStack_144 = _DAT_009da8a4;

        Client_SendLogicUiPacket(auStack_150);

      }

    }

    return (float10)fStack_198;

  }

  return (float10)g_flZero;

}
