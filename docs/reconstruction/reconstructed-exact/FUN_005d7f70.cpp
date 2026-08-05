// =============================================================================
// FUN_005d7f70
// -----------------------------------------------------------------------------
// Stable ID: aa_005d7f70
// Address:   0x005d7f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d7f70 @ 0x005d7f70
// Stable ID: aa_005d7f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~178 non-empty decompiler lines.
//  - Control keywords: if×29, return×13, goto×4.
//  - Notable callees: FUN_005cc980×3, FUN_005cedf0×3, NPC_TryCastSkillFromSet×3, AI_CheckSlotTimerReady×2, CVOGReaction_RandomUnitScalar×2, FUN_00540890×2, FUN_005cebd0×2, FUN_00404e00.
//  - Return sites: 13.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_005d7f70(int *param_1)



{

  ushort uVar1;

  float fVar2;

  int *piVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint unaff_EDI;

  int **ppiVar11;

  uint32_t /* width from decompiler */ uVar12;

  float *pfVar13;

  uint8_t uStack_9;

  float local_8;

  int *local_4;

  

  local_8 = *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1[0x19] + 4) + 4) + 0xac +

                                        param_1[0x19]) + 0x3c) + 0x4dc);

  pfVar13 = &local_8;

  ppiVar11 = &local_4;

  FUN_00540890(0);

  FUN_004cbd50(ppiVar11,pfVar13);

  iVar5 = FUN_00540890(0);

  piVar3 = local_4;

  if (local_4 == *(int **)(iVar5 + 4)) {

    return;

  }

  *(uint8_t *)(param_1[0x19] + 0x279) = 0;

  if (*(char *)(param_1[0x19] + 0x26c) == '\0') {

    *(uint8_t *)(param_1 + 0x2d) = 0;

    NPC_TryCastSkillFromSet(param_1,0);

    uVar6 = AI_CheckSlotTimerReady(param_1,(void *)0x0,unaff_EDI);

    if ((char)uVar6 != '\0') {

      (**(code **)(*param_1 + 0x1c))();

    }

    if (*(int *)(param_1[6] + 0xa0) != 0) {

      (**(code **)(*param_1 + 0x2c))(2);

    }

    if (*(char *)(param_1[0x19] + 0x305) != '\0') {

      return;

    }

    FUN_005cedf0();

    if ((char)param_1[0x18] == '\0') {

      cVar4 = FUN_005cc980();

      if (cVar4 != '\0') {

        return;

      }

      cVar4 = FUN_005cebd0(0);

      if (cVar4 != '\0') {

        return;

      }

      iVar5 = param_1[0x19];

      if ((*(char *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xa8 + iVar5) + 0x7e) != '\0') &&

         (*(char *)(iVar5 + 0x279) == '\0')) {

        puVar9 = (uint32_t /* width from decompiler */ *)FUN_0053e0b0();

        puVar10 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[6] + 0x1a0))();

        *puVar9 = *puVar10;

        puVar9[1] = puVar10[1];

        puVar9[2] = puVar10[2];

        puVar9[3] = puVar10[3];

        *(uint8_t *)(param_1[0x19] + 0x279) = 1;

      }

      iVar5 = *param_1;

      uVar12 = (**(code **)(*(int *)param_1[6] + 0x1a0))(0);

      (**(code **)(iVar5 + 0x4c))(uVar12);

      return;

    }

    goto LAB_005d8136;

  }

  if (*(char *)(param_1[0x19] + 0x26c) != '\x01') {

    NPC_TryCastSkillFromSet(param_1,2);

    uVar6 = AI_CheckSlotTimerReady(param_1,(void *)0x0,unaff_EDI);

    if ((char)uVar6 == '\0') {

      if (*(int *)(param_1[6] + 0xa0) == 0) {

        uVar12 = 0;

LAB_005d8112:

        (**(code **)(*param_1 + 0x2c))(uVar12);

      }

    }

    else {

      piVar8 = (int *)param_1[6];

      local_4 = piVar8;

      iVar5 = (**(code **)(*piVar8 + 0x1b0))();

      local_4 = (int *)(float)iVar5;

      iVar5 = (**(code **)(*piVar8 + 0x1ac))();

      local_8 = (float)local_4 / (float)iVar5;

      iVar5 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar5 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

      *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

      if (((float)uVar1 * DAT_00aaa638 < (float)piVar3[9]) && (local_8 <= (float)piVar3[10])) {

        FUN_00638cd0(piVar3[0xb]);

      }

      if ((*(int *)(param_1[0x19] + 8) != 0) &&

         (pcVar7 = (char *)FUN_00404e00(&uStack_9), *pcVar7 != '\0')) {

        iVar5 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar5 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

        }

        uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

        *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

        if (((float)uVar1 * DAT_00aaa638 < (float)piVar3[8] / (float)(*(byte *)(param_1 + 0x2d) + 1)

            ) && (local_8 <= (float)piVar3[7])) {

          uVar12 = 1;

          goto LAB_005d8112;

        }

      }

    }

    if (*(char *)(param_1[0x19] + 0x305) != '\0') {

      return;

    }

    FUN_005cedf0();

    if ((char)param_1[0x18] == '\0') {

      cVar4 = FUN_005cc980();

      if (cVar4 != '\0') {

        return;

      }

      cVar4 = FUN_005cebd0(0);

      if (cVar4 != '\0') {

        return;

      }

      if (*(int *)(param_1[6] + 0xa0) == 0) {

        return;

      }

      FUN_005cf560();

      return;

    }

    goto LAB_005d8136;

  }

  if (param_1[0x2c] == 0) {

    *(char *)(param_1 + 0x2d) = (char)param_1[0x2d] + '\x01';

    param_1[0x2c] = g_dwClientTickMs;

  }

  NPC_TryCastSkillFromSet(param_1,1);

  piVar8 = (int *)(g_dwClientTickMs - param_1[0x2c]);

  fVar2 = (float)(int)piVar8;

  if ((int)piVar8 < 0) {

    fVar2 = fVar2 + _DAT_00aaa5dc;

  }

  pfVar13 = (float *)(local_4 + 5);

  local_4 = piVar8;

  if (*pfVar13 < fVar2) {

LAB_005d8203:

    param_1[0x2c] = 0;

    if (*(int *)(param_1[6] + 0xa0) == 0) {

      (**(code **)(*param_1 + 0x2c))(0);

    }

    else {

      (**(code **)(*param_1 + 0x2c))(2);

    }

  }

  else {

    piVar8 = (int *)param_1[6];

    local_4 = piVar8;

    iVar5 = (**(code **)(*piVar8 + 0x1b0))();

    local_4 = (int *)(float)iVar5;

    iVar5 = (**(code **)(*piVar8 + 0x1ac))();

    if ((float)piVar3[6] <= (float)local_4 / (float)iVar5) goto LAB_005d8203;

  }

  FUN_005cedf0();

  if ((char)param_1[0x18] == '\0') {

    cVar4 = FUN_005cc980();

    if (cVar4 != '\0') {

      return;

    }

    FUN_005ccbd0();

    return;

  }

LAB_005d8136:

  FUN_005cc450();

  return;

}
