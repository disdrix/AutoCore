// =============================================================================
// Named_CalleeOf_Skill_You_have_not_yet_unlocked_your_skill_in_00894590
// -----------------------------------------------------------------------------
// Stable ID: aa_00894590
// Callee of Skill_You_have_not_yet_unlocked_your_skill_in
// Address:   0x00894590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_have_not_yet_unlocked_your_skill_in: skill/cast helper. Evidence string: "Broken items using this discipline can be repaired at Control Shops\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Broken items using this discipline can be repaired at Control Shops\n"
//   - "Broken items using this discipline can be repaired at Fabrication Plants\n"
//   - "Broken items using this discipline can be repaired at Reactors\n"
//   - "Base Level Requirement of"
//   - "Requires prerequisite of"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~195 non-empty decompiler lines.
//  - Control keywords: if×23, return×4, do×2, while×2.
//  - Notable callees: FUN_007a6de0×11, sprintf×6, FUN_00402d50×5, FUN_0052ada0×5, FUN_0052b040×5, free×5, FUN_00797d70, FUN_007a69d0.
//  - Strings: "Base Level Requirement of"; "%s %d\n"; "Requires prerequisite of"; "%s %d %s %s\n".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Skill_You_have_not_yet_unlocked_your_skill_in
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

void __fastcall Named_CalleeOf_Skill_You_have_not_yet_unlocked_your_skill_in_00894590(int param_1,int param_2)



{

  int *piVar1;

  void *pvVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  char *pcVar9;

  uint8_t auStack_474 [16];

  uint8_t auStack_464 [8];

  uint8_t *puStack_45c;

  uint8_t auStack_458 [128];

  char acStack_3d8 [4];

  char acStack_3d4 [252];

  char acStack_2d8 [200];

  uint8_t auStack_210 [42];

  uint8_t auStack_1e6 [474];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b03ae;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007a69d0();

  if (*(int *)(param_2 + 0x554) == 0) {

    ExceptionList = local_c;

    return;

  }

  if (param_1 != 0) {

    (**(code **)(**(int **)(param_2 + 0x554) + 0x268))();

    (**(code **)(**(int **)(param_2 + 0x554) + 0x1b0))(3);

    if (*(int *)(param_1 + 0x1f8) != 0) {

      iVar5 = **(int **)(param_2 + 0x554);

      uVar4 = FUN_007a6de0("Broken items using this discipline can be repaired at Control Shops\n",

                           0xffffffff);

      (**(code **)(iVar5 + 0x250))(uVar4);

    }

    if (*(int *)(param_1 + 0x1f0) != 0) {

      iVar5 = **(int **)(param_2 + 0x554);

      uVar4 = FUN_007a6de0("Broken items using this discipline can be repaired at Fabrication Plants\n"

                           ,0xffffffff);

      (**(code **)(iVar5 + 0x250))(uVar4);

    }

    if (*(int *)(param_1 + 500) != 0) {

      iVar5 = **(int **)(param_2 + 0x554);

      uVar4 = FUN_007a6de0("Broken items using this discipline can be repaired at Reactors\n",

                           0xffffffff);

      (**(code **)(iVar5 + 0x250))(uVar4);

    }

    if (1 < *(short *)(param_1 + 0x26)) {

      iVar5 = (int)*(short *)(param_1 + 0x26);

      uVar4 = FUN_007a6de0("Base Level Requirement of",0xffffffff);

      sprintf(acStack_3d4,"%s %d\n",uVar4,iVar5);

      (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d4);

    }

    (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(&DAT_00a15104);

    pcVar6 = (char *)FUN_007a6de0("Requires prerequisite of",0xffffffff);

    pcVar9 = acStack_2d8;

    do {

      cVar3 = *pcVar6;

      *pcVar9 = cVar3;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    } while (cVar3 != '\0');

    pcVar6 = (char *)FUN_007a6de0(&DAT_00a28b50,0xffffffff);

    pcVar9 = &stack0xfffffb84;

    do {

      cVar3 = *pcVar6;

      *pcVar9 = cVar3;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    } while (cVar3 != '\0');

    if (((-1 < *(int *)(param_1 + 8)) && (0 < *(short *)(param_1 + 0x1c))) &&

       (cVar3 = FUN_0052b040(*(int *)(param_1 + 8),auStack_210), cVar3 != '\0')) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1e6);

      local_c = (void *)0x0;

      uVar4 = FUN_007a6de0(*puVar7,0xffffffff);

      sprintf(acStack_3d8,"%s %d %s %s\n",acStack_2d8,(int)*(short *)(param_1 + 0x1c),

              &stack0xfffffb84,uVar4);

      local_c = (void *)0xffffffff;

      if (puStack_45c != auStack_458) {

        free(puStack_45c);

      }

      if ((DAT_00d1b6d8 == 0) ||

         (iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(param_1 + 8)), *(short *)(param_1 + 0x1c) <= iVar5))

      {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d8);

      }

      else {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x224))(acStack_3d8,0xffff2020);

      }

    }

    if (((-1 < *(int *)(param_1 + 0xc)) && (0 < *(short *)(param_1 + 0x1e))) &&

       (cVar3 = FUN_0052b040(*(int *)(param_1 + 0xc),auStack_210), cVar3 != '\0')) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1e6);

      local_c = (void *)0x1;

      uVar4 = FUN_007a6de0(*puVar7,0xffffffff);

      sprintf(acStack_3d8,"%s %d %s %s\n",acStack_2d8,(int)*(short *)(param_1 + 0x1e),

              &stack0xfffffb84,uVar4);

      local_c = (void *)0xffffffff;

      if (puStack_45c != auStack_458) {

        free(puStack_45c);

      }

      if ((DAT_00d1b6d8 == 0) ||

         (iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc)), *(short *)(param_1 + 0x1e) <= iVar5)

         ) {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d8);

      }

      else {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x224))(acStack_3d8,0xffff2020);

      }

    }

    if (((-1 < *(int *)(param_1 + 0x10)) && (0 < *(short *)(param_1 + 0x20))) &&

       (cVar3 = FUN_0052b040(*(int *)(param_1 + 0x10),auStack_210), cVar3 != '\0')) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1e6);

      local_c = (void *)0x2;

      uVar4 = FUN_007a6de0(*puVar7,0xffffffff);

      sprintf(acStack_3d8,"%s %d %s %s\n",acStack_2d8,(int)*(short *)(param_1 + 0x20),

              &stack0xfffffb84,uVar4);

      local_c = (void *)0xffffffff;

      if (puStack_45c != auStack_458) {

        free(puStack_45c);

      }

      if ((DAT_00d1b6d8 == 0) ||

         (iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10)), *(short *)(param_1 + 0x20) <= iVar5

         )) {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d8);

      }

      else {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x224))(acStack_3d8,0xffff2020);

      }

    }

    if (((-1 < *(int *)(param_1 + 0x14)) && (0 < *(short *)(param_1 + 0x22))) &&

       (cVar3 = FUN_0052b040(*(int *)(param_1 + 0x14),auStack_210), cVar3 != '\0')) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1e6);

      local_c = (void *)0x3;

      uVar4 = FUN_007a6de0(*puVar7,0xffffffff);

      sprintf(acStack_3d8,"%s %d %s %s\n",acStack_2d8,(int)*(short *)(param_1 + 0x22),

              &stack0xfffffb84,uVar4);

      local_c = (void *)0xffffffff;

      if (puStack_45c != auStack_458) {

        free(puStack_45c);

      }

      if ((DAT_00d1b6d8 == 0) ||

         (iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14)), *(short *)(param_1 + 0x22) <= iVar5

         )) {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d8);

      }

      else {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x224))(acStack_3d8,0xffff2020);

      }

    }

    if (((-1 < *(int *)(param_1 + 0x18)) && (0 < *(short *)(param_1 + 0x24))) &&

       (cVar3 = FUN_0052b040(*(int *)(param_1 + 0x18),auStack_210), cVar3 != '\0')) {

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_1e6);

      local_c = (void *)0x4;

      uVar4 = FUN_007a6de0(*puVar7,0xffffffff);

      sprintf(acStack_3d8,"%s %d %s %s\n",acStack_2d8,(int)*(short *)(param_1 + 0x24),

              &stack0xfffffb84,uVar4);

      local_c = (void *)0xffffffff;

      if (puStack_45c != auStack_458) {

        free(puStack_45c);

      }

      if ((DAT_00d1b6d8 == 0) ||

         (iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18)), *(short *)(param_1 + 0x24) <= iVar5

         )) {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x250))(acStack_3d8);

      }

      else {

        (**(code **)(**(int **)(param_2 + 0x554) + 0x224))(acStack_3d8,0xffff2020);

      }

    }

    piVar1 = *(int **)(param_2 + 0x554);

    iVar5 = (**(code **)(*piVar1 + 0x140))(auStack_464,1);

    iVar8 = (**(code **)(*piVar1 + 0x204))(auStack_474);

    if (*(int *)(iVar5 + 4) < *(int *)(iVar8 + 4)) {

      pvVar2 = *(void **)(*(int *)(param_2 + 0x554) + 0x28c);

      if (pvVar2 != (void *)0x0) {

        FUN_00797d70(pvVar2);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x554) + 0x28c) = 0;

      (**(code **)(**(int **)(param_2 + 0x554) + 0x1b0))(8);

    }

    ExceptionList = local_c;

    return;

  }

  ExceptionList = local_c;

  return;

}
