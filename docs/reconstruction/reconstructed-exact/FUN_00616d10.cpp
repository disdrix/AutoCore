// =============================================================================
// FUN_00616d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00616d10
// Address:   0x00616d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00616d10 @ 0x00616d10
// Stable ID: aa_00616d10
// Embedded strings (evidence for future rename):
//   - "max_hp"
//   - "num_targets"
//   - "summon_count"
//   - "ls1."
//   - "ls2."
//   - "ls3."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×23, goto×8, return×6.
//  - Notable callees: strncmp×10, CONCAT22×4, FUN_004f1e20×2, FUN_00552950×2, CONCAT31, FUN_00404d70, FUN_004eb010, FUN_005781a0.
//  - Strings: "max_hp"; "num_targets"; "summon_count"; "ls1.".
//  - Return sites: 6.

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

int FUN_00616d10(int param_1,char *param_2,char *param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  void *pvVar6;

  uint16_t extraout_var;

  uint16_t uVar8;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  uint16_t extraout_var_02;

  uint16_t extraout_var_03;

  uint16_t extraout_var_04;

  char *pcVar7;

  uint uVar9;

  uint16_t extraout_var_05;

  char *unaff_ESI;

  int iStack_c;

  int aiStack_8 [2];

  

  pcVar7 = param_2;

  if ((param_2 == (char *)0x0) || (cVar1 = *param_2, cVar1 == '\0')) {

    return 0;

  }

  param_2 = (char *)0x0;

  iVar2 = tolower((int)cVar1);

  if (iVar2 == 0x6d) {

    iVar2 = strncmp(pcVar7,"max_hp",6);

    if (iVar2 == 0) {

      uVar9 = (uint)*(float *)(param_1 + 0x4c);

      goto LAB_00616d75;

    }

  }

  else if (iVar2 == 0x6e) {

    iVar2 = strncmp(pcVar7,"num_targets",0xb);

    if (iVar2 == 0) {

      uVar9 = (uint)*(byte *)(param_1 + 0xde);

      goto LAB_00616d75;

    }

  }

  else if ((iVar2 == 0x73) && (iVar2 = strncmp(pcVar7,"summon_count",0xc), iVar2 == 0)) {

    uVar9 = (uint)*(byte *)(param_1 + 0xda);

LAB_00616d75:

    sprintf(param_3,"%d",uVar9);

    return 1;

  }

  iVar2 = param_1;

  cVar1 = *pcVar7;

  if ((cVar1 == 'l') && (pcVar7[1] == 's')) {

    iVar3 = strncmp(pcVar7,"ls1.",4);

    if (iVar3 == 0) {

      pvVar6 = *(void **)(iVar2 + 0x150);

      uVar8 = extraout_var;

    }

    else {

      iVar3 = strncmp(pcVar7,"ls2.",4);

      if (iVar3 == 0) {

        pvVar6 = *(void **)(iVar2 + 0x154);

        uVar8 = extraout_var_00;

      }

      else {

        iVar3 = strncmp(pcVar7,"ls3.",4);

        if (iVar3 == 0) {

          pvVar6 = *(void **)(iVar2 + 0x158);

          uVar8 = extraout_var_01;

        }

        else {

          iVar3 = strncmp(pcVar7,"ls4.",4);

          if (iVar3 != 0) goto LAB_00617084;

          pvVar6 = *(void **)(iVar2 + 0x15c);

          uVar8 = extraout_var_02;

        }

      }

    }

    puVar4 = CVOGReaction_ResolveSkillTargets

                       (pvVar6,CONCAT22(uVar8,*(short *)(iVar2 + 0x5f6) + *(short *)(iVar2 + 0x174))

                       );

    if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

      param_2 = (char *)FUN_00552950(pcVar7 + 4,param_3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

    goto LAB_00617084;

  }

  if ((((cVar1 != 'c') || (pcVar7[1] != 's')) && ((cVar1 != 'm' || (pcVar7[1] != 's')))) ||

     (iVar3 = FUN_00404d70(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14c)), iVar3 == 0)) goto LAB_00617084;

  FUN_004f1e20(0,1);

  FUN_004f1e20(0,1);

  iVar5 = strncmp(pcVar7,"cs1.",4);

  if (iVar5 == 0) {

    pvVar6 = *(void **)(*(int *)(iVar3 + 0x3c) + 0x3bc);

    uVar8 = extraout_var_03;

LAB_00616f5e:

    puVar4 = CVOGReaction_ResolveSkillTargets

                       (pvVar6,CONCAT22(uVar8,*(short *)(iVar2 + 0x5f6) + *(short *)(iVar2 + 0x174))

                       );

    if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

      pcVar7 = pcVar7 + 4;

LAB_00617061:

      param_2 = (char *)FUN_00552950(pcVar7,param_3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

  }

  else {

    iVar5 = strncmp(pcVar7,"cs2.",4);

    if (iVar5 == 0) {

      puVar4 = CVOGReaction_ResolveSkillTargets

                         (*(void **)(*(int *)(iVar3 + 0x3c) + 0x3c0),

                          CONCAT22(extraout_var_05,

                                   *(short *)(iVar2 + 0x5f6) + *(short *)(iVar2 + 0x174)));

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        pcVar7 = pcVar7 + 4;

        goto LAB_00617061;

      }

    }

    else {

      iVar5 = strncmp(pcVar7,"cs3.",4);

      if (iVar5 == 0) {

        pvVar6 = *(void **)(*(int *)(iVar3 + 0x3c) + 0x3c4);

        uVar8 = extraout_var_04;

        goto LAB_00616f5e;

      }

      if (*pcVar7 == 'm') {

        iStack_c = 0;

        iVar5 = sscanf(pcVar7,"ms%d.",&iStack_c);

        if (iVar5 != 0) {

          iStack_c = iStack_c + -1;

          iVar3 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c),0,

                                  &nsCloneStructs::SCloneBaseObject::RTTI_Type_Descriptor,

                                  &nsCloneStructs::SCloneBaseCreature::RTTI_Type_Descriptor,0);

          if (iVar3 != 0) {

            param_1 = CONCAT31(param_1._1_3_,2);

            Map_LowerBoundFindByCharKey((void *)(iVar3 + 0x51c),aiStack_8,&param_1,unaff_ESI);

            iVar5 = iStack_c;

            if ((((aiStack_8[0] != *(int *)(iVar3 + 0x520)) && (-1 < iStack_c)) &&

                (iVar3 = SkillSet_GetEntryCount((void *)(aiStack_8[0] + 0x10)), iVar5 < iVar3)) &&

               (puVar4 = CVOGReaction_ResolveSkillTargets

                                   (*(void **)(*(int *)(aiStack_8[0] + 0x14) + iVar5 * 0x18),

                                    CONCAT22((short)((uint)(iVar5 * 3) >> 0x10),

                                             *(short *)(iVar2 + 0x5f6) + *(short *)(iVar2 + 0x174)))

               , puVar4 != (uint32_t /* width from decompiler */ *)0x0)) {

              pcVar7 = pcVar7 + (8 < iStack_c) + 4;

              goto LAB_00617061;

            }

          }

        }

      }

    }

  }

  FUN_004eb010();

  if (param_2 != (char *)0x0) {

    return (int)param_2;

  }

LAB_00617084:

  iVar2 = FUN_005781a0(iVar2,pcVar7,param_3);

  return iVar2;

}
