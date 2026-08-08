// =============================================================================
// RETIRED SCAFFOLD — R13-027 dual 2026-08-05
// Superseded by: CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.cpp
// Do not use as authoritative reconstruction.
// =============================================================================
// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720
// -----------------------------------------------------------------------------
// Stable ID: aa_004e9720
// Callee of CVOGSpawnPoint_CreateCreature (+1 other named callers)
// Address:   0x004e9720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGSpawnPoint_CreateCreature (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: ifÃ—7, doÃ—1, whileÃ—1, returnÃ—1.
//  - Notable callees: CONCAT31Ã—2, CVOGReaction_RandomUnitScalarÃ—2, FUN_004cd220, FUN_004e9720, FUN_004eacc0, FUN_0055ff20, FUN_00560020, FUN_005eb130.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGSpawnPoint_CreateCreature (+1 other named callers)
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



bool Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720(uint32_t /* width from decompiler */ param_1,float *param_2,float param_3,float param_4,float *param_5,

                 uint32_t /* width from decompiler */ param_6,char param_7,char param_8)



{

  ushort uVar1;

  ushort uVar2;

  bool bVar3;

  float fVar4;

  float fVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int *piVar8;

  bool bVar9;

  float10 fVar10;

  float fVar11;

  uint8_t auStack_1b0 [4];

  int iStack_1ac;

  uint32_t /* width from decompiler */ uStack_1a8;

  uint32_t /* width from decompiler */ *puStack_1a4;

  int iStack_19c;

  float fStack_158;

  float fStack_154;

  float fStack_150;

  float fStack_14c;

  undefined **ppuStack_148;

  uint8_t uStack_144;

  uint8_t *puStack_140;

  int iStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint8_t auStack_134 [264];

  void *pvStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a2612;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  iStack_1ac = (**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);

  *(uint16_t *)(iStack_1ac + 4) = 0x10;

  pvStack_1c = (void *)0x0;

  puVar6 = (uint32_t /* width from decompiler */ *)FUN_006c7fa0(param_4);

  pvStack_1c = (void *)0xffffffff;

  FUN_005eb8d0();

  fStack_158 = *param_2;

  fStack_154 = param_2[1];

  fStack_150 = param_2[2];

  fStack_14c = param_2[3];

  uStack_1a8 = param_6;

  pvStack_1c = (void *)0x1;

  puStack_1a4 = puVar6;

  iVar7 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x2c);

  *(uint16_t *)(iVar7 + 4) = 0xd0;

  uStack_24._0_1_ = 2;

  piVar8 = (int *)FUN_005eb790(auStack_1b0);

  *(short *)((int)puVar6 + 6) = *(short *)((int)puVar6 + 6) + -1;

  uStack_24._0_1_ = 1;

  if (*(short *)((int)puVar6 + 6) == 0) {

    (**(code **)*puVar6)(1);

  }

  FUN_0055ff20(piVar8);

  puStack_140 = auStack_134;

  ppuStack_148 = &PTR_FUN_009ccbb4;

  uStack_138 = 0x80000010;

  iStack_13c = 0;

  uStack_144 = 0;

  *param_5 = *param_2;

  param_5[1] = param_2[1];

  param_5[2] = param_2[2];

  param_5[3] = param_2[3];

  uStack_24 = CONCAT31(uStack_24._1_3_,3);

  param_5[1] = param_5[1] + param_4 + DAT_00a0f298;

  bVar3 = true;

  do {

    FUN_005eb130(param_5);

    (**(code **)(*piVar8 + 0x30))(&ppuStack_148);

    if (iStack_13c == 0) {

      param_7 = '\0';

      bVar3 = false;

    }

    else {

      iStack_13c = 0;

      uStack_144 = 0;

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      iVar7 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar7 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc) = 0;

      }

      fVar5 = g_flOne;

      fVar4 = _DAT_009cc4a8;

      uVar2 = *(ushort *)(*(int *)(iVar7 + 8) + *(int *)(iVar7 + 0xc) * 2);

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      *param_5 = *param_2;

      param_5[1] = param_2[1];

      param_5[2] = param_2[2];

      fVar11 = param_3 * DAT_00aaa664;

      param_5[3] = param_2[3];

      param_5[1] = param_5[1] + fVar11;

      fVar11 = param_3 * g_flZero;

      *param_5 = *param_5 + ((float)uVar2 * fVar4 - fVar5) * param_3;

      param_5[2] = ((float)uVar1 * fVar4 - fVar5) * param_3 + param_5[2];

      param_5[3] = param_5[3] + fVar11;

      fVar10 = (float10)FUN_004cd220(*param_5,param_5[2]);

      param_5[1] = (float)(fVar10 + (float10)param_4 + (float10)DAT_00a0f298);

    }

    bVar9 = param_7 != '\0';

    param_7 = param_7 + -1;

  } while (bVar9);

  if ((bVar3) && (param_8 == '\0')) {

    *param_5 = *param_2;

    param_5[1] = param_2[1];

    param_5[2] = param_2[2];

    param_5[3] = param_2[3];

  }

  FUN_00560020(piVar8);

  *(short *)((int)piVar8 + 6) = *(short *)((int)piVar8 + 6) + -1;

  if (*(short *)((int)piVar8 + 6) == 0) {

    (**(code **)*piVar8)(1);

  }

  uStack_24 = CONCAT31(uStack_24._1_3_,1);

  FUN_004eacc0();

  uStack_24 = 0xffffffff;

  if (-1 < iStack_19c) {

    (**(code **)(*DAT_00b05060 + 0x14))(puStack_1a4,iStack_19c * 8,0x12);

  }

  ExceptionList = pvStack_2c;

  return !bVar3;

}

