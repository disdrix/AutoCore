// READABILITY (auto CF):
//  - Body size: ~305 non-empty decompiler lines.
//  - Control keywords: if×30, return×21, goto×14, switch×1, do×1, while×1.
//  - Notable callees: ROUND×9, CNDHash_LookupByKey×5, FUN_005b0990×4, CVOGCharacter_HasCompletedMission×3, Value×3, FUN_00403430×2, CONCAT44, CVOGReaction_RandomUnitScalar.
//  - Return sites: 21.

// =============================================================================
// CVOGVariable_EvaluateComputed
// -----------------------------------------------------------------------------
// Stable ID: aa_005afd40
// Address:   0x005afd40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* CVOGVariable_EvaluateComputed - map logic variable by Type (var+0x40), Value (var+0x4c).

   Type 0: constant/flag (mutable VariableSet)

   Type 9: has completed mission Value

   Type 11: has active mission Value (char+0x540)

   Type 12: has active objective Value (char+0x548)

   Conditions: var[LeftId] OP var[RightId]. Server: LogicVariableStore + TriggerConditional.Check.

   On mission grant/complete, server re-evals volume + remote (scale<=2) triggers. */



uint32_t /* width from decompiler */ __thiscall

CVOGVariable_EvaluateComputed(int param_1,float param_2,float *param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  ushort uVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  RACE_ID_INFERRED RVar7;

  float fVar8;

  void *pvVar9;

  void *pvVar10;

  void *pvVar11;

  int iVar12;

  bool bVar13;

  uint8_t local_2c [4];

  uint8_t local_28 [4];

  float local_24;

  float local_20 [2];

  uint8_t auStack_18 [4];

  int *piStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  fVar8 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a66c8;

  local_c = ExceptionList;

  cVar4 = *(char *)((int)param_2 + 0x40);

  if (cVar4 == '\x05') {

    *param_3 = (float)*(int *)(*(int *)(param_1 + 0x34) + 0xf8);

    return 1;

  }

  if (cVar4 == '\b') {

    ExceptionList = &local_c;

    iVar12 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar12 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar12 + 0xc) = 0;

    }

    uVar3 = *(ushort *)(*(int *)(iVar12 + 8) + *(int *)(iVar12 + 0xc) * 2);

    *(int *)(iVar12 + 0xc) = *(int *)(iVar12 + 0xc) + 1;

    *param_3 = (float)uVar3 * *(float *)((int)fVar8 + 0x4c) * DAT_00aaa638;

    ExceptionList = local_c;

    return 1;

  }

  ExceptionList = &local_c;

  if ((cVar4 == '\x12') &&

     (fVar1 = *(float *)((int)param_2 + 0x4c), ExceptionList = &local_c, g_flZero < fVar1)) {

    fVar2 = (float)(int)ROUND(fVar1);

    local_20[0] = *(float *)(param_1 + 0x34);

    ExceptionList = &local_c;

    param_2 = fVar1;

    local_24 = fVar2;

    if ((local_20[0] != 0.0) &&

       (iVar12 = *(int *)((int)local_20[0] + 0x48), ExceptionList = &local_c, param_2 = fVar2,

       piVar5 = (int *)FUN_005b0990(local_28,&param_2), *piVar5 != iVar12)) {

      param_2 = fVar2;

      piVar5 = (int *)FUN_005b0990(local_2c,&param_2);

      *param_3 = (float)*(int *)(*piVar5 + 0x10);

      ExceptionList = local_c;

      return 1;

    }

  }

  piVar5 = param_4;

  if (param_4 == (int *)0x0) {

switchD_005afe1f_caseD_5:

    ExceptionList = local_c;

    return 0;

  }

  switch(*(uint8_t *)((int)fVar8 + 0x40)) {

  case 1:

    iVar12 = (**(code **)(*param_4 + 0x214))();

    if (((iVar12 != 0) && (*(int *)(iVar12 + 0x250) != 0)) &&

       (*(int *)(*(int *)(iVar12 + 0x250) + 0x2b0) != 0)) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      FUN_004023f0();

      uStack_4 = 0;

      FUN_00571fb0(local_24,auStack_18);

      if (iStack_10 == 0) {

        *param_3 = 0.0;

        FUN_00403430();

        ExceptionList = local_c;

        return 1;

      }

      piVar5 = (int *)*piStack_14;

      iVar12 = 0;

      if (piVar5 != piStack_14) {

        do {

          iVar6 = (**(code **)(*(int *)piVar5[2] + 0x25c))();

          piVar5 = (int *)*piVar5;

          iVar12 = iVar12 + iVar6;

        } while (piVar5 != piStack_14);

      }

      *param_3 = (float)iVar12;

      FUN_00403430();

      ExceptionList = local_c;

      return 1;

    }

    goto LAB_005b0358;

  case 2:

    RVar7 = Object_GetRootRaceId(param_4);

    *param_3 = (float)(int)RVar7;

    ExceptionList = local_c;

    return 1;

  case 3:

    iVar12 = (**(code **)(*param_4 + 0x214))();

    if (iVar12 != 0) {

      iVar12 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar12 + 4) + 4) + 4 + iVar12) + 0x27c))();

      fVar8 = (float)iVar12;

      goto LAB_005b003b;

    }

    goto LAB_005b0358;

  case 4:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 == 0) {

      ExceptionList = local_c;

      return 0;

    }

    fVar8 = (float)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar12 + 4) + 4) + 0xac + iVar12) +

                                     0x3c) + 0x531);

    goto LAB_005b003b;

  default:

    goto switchD_005afe1f_caseD_5;

  case 6:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 != 0) {

      *param_3 = (float)CONCAT44((*(int *)(iVar12 + 0x724) - *(int *)(iVar12 + 0x72c)) -

                                 (uint)(*(uint *)(iVar12 + 0x720) < *(uint *)(iVar12 + 0x728)),

                                 *(uint *)(iVar12 + 0x720) - *(uint *)(iVar12 + 0x728));

      ExceptionList = local_c;

      return 1;

    }

    ExceptionList = local_c;

    return 0;

  case 7:

    iVar12 = (**(code **)(*param_4 + 0x1ac))();

    fVar8 = g_flOne;

    if (iVar12 != 0) {

      iVar12 = (**(code **)(*piVar5 + 0x1b0))();

      local_20[0] = (float)iVar12;

      iVar12 = (**(code **)(*piVar5 + 0x1ac))();

      *param_3 = local_20[0] / (float)iVar12;

      ExceptionList = local_c;

      return 1;

    }

    goto LAB_005b003b;

  case 9:

    pvVar9 = (void *)(**(code **)(*param_4 + 0x210))(0);

    if (pvVar9 != (void *)0x0) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      cVar4 = CVOGCharacter_HasCompletedMission(pvVar9,(uint)local_24);

LAB_005b0155:

      bVar13 = cVar4 == '\0';

joined_r0x005b0336:

      if (!bVar13) {

        *param_3 = g_flOne;

        ExceptionList = local_c;

        return 1;

      }

    }

    break;

  case 10:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 != 0) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      cVar4 = FUN_0052c9d0(local_24);

      goto LAB_005b0155;

    }

    break;

  case 0xb:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 != 0) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      pvVar9 = CNDHash_LookupByKey(*(void **)(iVar12 + 0x540),(uint)local_24);

      bVar13 = pvVar9 == (void *)0x0;

      goto joined_r0x005b0336;

    }

    break;

  case 0xc:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 != 0) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      pvVar9 = CNDHash_LookupByKey(*(void **)(iVar12 + 0x548),(uint)local_24);

      bVar13 = pvVar9 == (void *)0x0;

      goto joined_r0x005b0336;

    }

    break;

  case 0xd:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    fVar8 = g_flOne;

    if (iVar12 != 0) goto LAB_005b003b;

LAB_005b0358:

    *param_3 = 0.0;

    ExceptionList = local_c;

    return 1;

  case 0xe:

    local_20[0] = *(float *)((int)fVar8 + 0x4c);

    local_24 = (float)(int)ROUND(local_20[0]);

    pvVar9 = (void *)(**(code **)(*param_4 + 0x210))(0);

    fVar8 = local_24;

    if (pvVar9 != (void *)0x0) {

      pvVar10 = CNDHash_LookupByKey(*(void **)((int)pvVar9 + 0x540),(uint)local_24);

      if ((pvVar10 == (void *)0x0) &&

         (bVar13 = CVOGCharacter_HasCompletedMission(pvVar9,(uint)fVar8), !bVar13)) {

        *param_3 = g_flOne;

        ExceptionList = local_c;

        return 1;

      }

      goto LAB_005b02b9;

    }

    break;

  case 0xf:

    local_20[0] = *(float *)((int)fVar8 + 0x4c);

    local_24 = (float)(int)ROUND(local_20[0]);

    iVar12 = FUN_0053fff0();

    fVar8 = local_24;

    if (*(void **)(iVar12 + 4) == (void *)0x0) {

      pvVar9 = (void *)0x0;

    }

    else {

      pvVar9 = CNDHash_LookupByKey(*(void **)(iVar12 + 4),(uint)local_24);

    }

    pvVar10 = (void *)(**(code **)(*piVar5 + 0x210))(0);

    if ((pvVar10 == (void *)0x0) || (pvVar9 == (void *)0x0)) goto LAB_005b0358;

    pvVar11 = CNDHash_LookupByKey(*(void **)((int)pvVar10 + 0x548),(uint)fVar8);

    if (pvVar11 == (void *)0x0) {

      bVar13 = CVOGCharacter_HasCompletedMission(pvVar10,**(uint **)((int)pvVar9 + 0x14c));

      goto joined_r0x005b0336;

    }

    break;

  case 0x10:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (iVar12 != 0) {

      local_20[0] = *(float *)((int)fVar8 + 0x4c);

      local_24 = (float)(int)ROUND(local_20[0]);

      cVar4 = FUN_00525ba0(local_24);

      goto LAB_005b0155;

    }

    break;

  case 0x11:

    iVar12 = (**(code **)(*param_4 + 0x28c))();

    *param_3 = (float)iVar12;

    ExceptionList = local_c;

    return 1;

  case 0x12:

    if (*(float *)((int)fVar8 + 0x4c) == DAT_00aaa668) {

      iVar12 = (**(code **)(*param_4 + 0x210))(0);

      if (iVar12 != 0) {

        *param_3 = (float)*(ushort *)(iVar12 + 0x60c);

        ExceptionList = local_c;

        return 1;

      }

    }

    else if ((*(float *)((int)fVar8 + 0x4c) == g_flZero) &&

            (iVar12 = (**(code **)(*param_4 + 0x210))(0), iVar12 != 0)) {

      fVar8 = (float)(**(code **)(*(int *)(*(int *)(*(int *)(iVar12 + 4) + 4) + 4 + iVar12) + 0x28c)

                     )();

      if ((*(int *)(param_1 + 0x34) != 0) &&

         (iVar12 = *(int *)(*(int *)(param_1 + 0x34) + 0x48), local_20[0] = fVar8,

         piVar5 = (int *)FUN_005b0990(&param_4,local_20), *piVar5 != iVar12)) {

        local_20[0] = fVar8;

        piVar5 = (int *)FUN_005b0990(&param_2,local_20);

        *param_3 = (float)*(int *)(*piVar5 + 0x10);

        ExceptionList = local_c;

        return 1;

      }

    }

LAB_005b02b9:

    *param_3 = 0.0;

    ExceptionList = local_c;

    return 1;

  case 0x13:

    iVar12 = (**(code **)(*param_4 + 0x210))(0);

    if (*(int *)(iVar12 + 0x250) != 0) {

      iVar12 = *(int *)(*(int *)(*(int *)(iVar12 + 0x250) + 8) + 0x3c);

      *param_3 = SQRT(*(float *)(iVar12 + 0x48) * *(float *)(iVar12 + 0x48) +

                      *(float *)(iVar12 + 0x44) * *(float *)(iVar12 + 0x44) +

                      *(float *)(iVar12 + 0x40) * *(float *)(iVar12 + 0x40));

      ExceptionList = local_c;

      return 1;

    }

    *param_3 = DAT_00aaa668;

    ExceptionList = local_c;

    return 1;

  }

  fVar8 = 0.0;

LAB_005b003b:

  *param_3 = fVar8;

  ExceptionList = local_c;

  return 1;

}
