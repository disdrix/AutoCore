// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_0089c820
// -----------------------------------------------------------------------------
// Stable ID: aa_0089c820
// Address:   0x0089c820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_0089c820 @ 0x0089c820
// Stable ID: aa_0089c820
// Embedded strings (evidence for future rename):
//   - "Refining"
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~310 non-empty decompiler lines.
//  - Control keywords: if×35, return×19, goto×5, switch×1, for×1, do×1, while×1.
//  - Notable callees: FUN_0089c330×7, FUN_0089b090×3, CNDHash_LookupByKey×2, CVOGReaction_GiveItemByCbid×2, FUN_007a6de0×2, FUN_007fcc10×2, FUN_0089bf50×2, FUN_00402d50.
//  - Strings: "Refining"; "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 19.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_0089c820 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_AllocateNewObjectFromCbidFailed_0089c820(int param_1,int param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  void *pvVar6;

  char *pcVar7;

  int iVar8;

  uint uVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  int iVar13;

  int *piVar14;

  longlong lVar15;

  uint32_t /* width from decompiler */ uVar16;

  int aiStack_1c0 [2];

  uint32_t /* width from decompiler */ uStack_1b8;

  void *pvStack_1b4;

  uint8_t *puStack_19c;

  uint8_t auStack_198 [128];

  char acStack_118 [2];

  uint32_t /* width from decompiler */ auStack_116 [55];

  void *pvStack_38;

  uint8_t uStack_19;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  iVar5 = DAT_00d1b6d8;

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b5f2c;

  local_14 = ExceptionList;

  if (((0x9c50 < param_3) && (param_3 < 0x9c56)) &&

     (iVar8 = *(int *)(param_1 + -0x26b78 + param_3 * 4), iVar8 != -1)) {

    if (param_2 == 5) {

      if (*(int *)(param_1 + -0x26bb4 + param_3 * 4) == 0) {

        return 1;

      }

      ExceptionList = &local_14;

      piVar2 = (int *)CVOGReaction_GiveItemByCbid(iVar8);

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 8))(*(uint32_t /* width from decompiler */ *)(param_1 + -0x26b78 + param_3 * 4),DAT_00d1b644);

        puVar3 = (uint32_t /* width from decompiler */ *)

                 (**(code **)(**(int **)(param_1 + -0x26bb4 + param_3 * 4) + 0x140))(aiStack_1c0,1);

        piVar14 = *(int **)(param_1 + -0x26bb4 + param_3 * 4);

        puVar4 = (uint32_t /* width from decompiler */ *)&stack0xfffffe2c;

        goto LAB_0089c922;

      }

      goto LAB_0089c988;

    }

    if (param_2 == 6) {

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      if (DAT_00d1d8dc != (int *)0x0) {

        ExceptionList = &local_14;

        (**(code **)(*DAT_00d1d8dc + 4))();

      }

      ExceptionList = local_14;

      return 1;

    }

  }

  ExceptionList = &local_14;

  switch(param_3) {

  case 40000:

    ExceptionList = &local_14;

    if (param_2 == 8) {

      ExceptionList = &local_14;

      FUN_007fca10();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c42:

    ExceptionList = &local_14;

    if ((((param_2 == 8) && (ExceptionList = &local_14, DAT_00d1b6d8 != 0)) &&

        (ExceptionList = &local_14,

        pvStack_1b4 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),

                                          *(uint *)(param_1 + 0x5ec)), pvStack_1b4 != (void *)0x0))

       && (aiStack_1c0[0] = *(int *)((int)pvStack_1b4 + 0x3c), aiStack_1c0[0] != 0)) {

      iVar8 = *(int *)(param_1 + 0x524);

      if (iVar8 < 1) {

        iVar8 = 1;

      }

      uVar9 = iVar8 * *(int *)(aiStack_1c0[0] + 0x4c4);

      iVar13 = (int)uVar9 >> 0x1f;

      iVar8 = (*(int *)(iVar5 + 0x724) - *(int *)(iVar5 + 0x72c)) -

              (uint)(*(uint *)(iVar5 + 0x720) < *(uint *)(iVar5 + 0x728));

      if ((iVar8 <= iVar13) &&

         ((iVar8 < iVar13 || (*(uint *)(iVar5 + 0x720) - *(uint *)(iVar5 + 0x728) < uVar9)))) {

        ExceptionList = local_14;

        return 0;

      }

      acStack_118[0] = '\0';

      acStack_118[1] = '\0';

      puVar4 = auStack_116;

      for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      *(uint16_t *)puVar4 = 0;

      FUN_007a69d0();

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50();

      uStack_c = 0;

      pcVar10 = (char *)FUN_007a6de0(*puVar4);

      pcVar7 = acStack_118;

      do {

        cVar1 = *pcVar10;

        *pcVar7 = cVar1;

        pcVar10 = pcVar10 + 1;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

      uStack_c = 0xffffffff;

      if (puStack_19c != auStack_198) {

        free(puStack_19c);

      }

      pvVar6 = (void *)((float)(*(int *)(aiStack_1c0[0] + 0x4c4) * *(int *)(param_1 + 0x524)) *

                       DAT_00a0f718);

      uStack_19 = 0;

      pvStack_1b4 = (void *)g_flOne;

      if (g_flOne <= (float)pvVar6) {

        pvStack_1b4 = pvVar6;

      }

      uStack_1b8 = 0xff;

      aiStack_1c0[0] = 0;

      uVar12 = DAT_00afdef4;

      iVar5 = aiStack_1c0[0];

      uVar16 = uStack_1b8;

      uVar11 = FUN_007a6de0("Refining",0xffffffff);

      FUN_007fb690(0,pvStack_1b4,acStack_118,uVar11,uVar12,iVar5,uVar16);

    }

    break;

  case 0x9c43:

    ExceptionList = &local_14;

    if ((param_2 == 8) && (ExceptionList = &local_14, 1 < *(int *)(param_1 + 0x524))) {

      ExceptionList = &local_14;

      *(int *)(param_1 + 0x524) = *(int *)(param_1 + 0x524) + -1;

      FUN_0089c330();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c44:

    ExceptionList = &local_14;

    if ((param_2 == 8) && (ExceptionList = &local_14, *(int *)(param_1 + 0x524) < 9999)) {

      ExceptionList = &local_14;

      *(int *)(param_1 + 0x524) = *(int *)(param_1 + 0x524) + 1;

      FUN_0089c330();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c45:

    if (param_2 == 8) {

      if (*(int *)(param_1 + 0x524) < 9999) {

        aiStack_1c0[0] = 0;

        ExceptionList = &local_14;

        pvVar6 = CNDHash_LookupByKey(*(void **)(DAT_00d1b570 + 0xf10),*(uint *)(param_1 + 0x5ec));

        if (pvVar6 != (void *)0x0) {

          FUN_00522060(pvVar6,aiStack_1c0,*(uint8_t *)(param_1 + 0x528));

          *(int *)(param_1 + 0x524) = aiStack_1c0[0];

          FUN_0089c330();

        }

        ExceptionList = local_14;

        return 1;

      }

LAB_0089ccca:

      iVar5 = 1;

      ExceptionList = &local_14;

      if (1 < *(int *)(param_1 + 0x524)) goto LAB_0089cd04;

    }

  case 0x9c47:

LAB_0089ccd7:

    ExceptionList = &local_14;

    if ((*(int **)(param_1 + 0x608) != (int *)0x0) &&

       ((param_2 == 0 || (ExceptionList = &local_14, param_2 == 2)))) {

      ExceptionList = &local_14;

      pcVar7 = (char *)(**(code **)(**(int **)(param_1 + 0x608) + 0x1dc))();

      iVar5 = atoi(pcVar7);

LAB_0089cd04:

      *(int *)(param_1 + 0x524) = iVar5;

      FUN_0089c330();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c46:

    if (param_2 == 8) goto LAB_0089ccca;

    goto LAB_0089ccd7;

  case 0x9c48:

    ExceptionList = &local_14;

    if ((param_2 == 0x1a) && (ExceptionList = &local_14, *(int *)(param_1 + 0x534) != -1)) {

      ExceptionList = &local_14;

      iVar5 = (**(code **)(**(int **)(param_1 + 0x604) + 0x464))();

      iVar5 = iVar5 - *(int *)(param_1 + 0x534);

      if (*(int *)(param_1 + 0x52c) == iVar5) {

        ExceptionList = local_14;

        return 1;

      }

      *(int *)(param_1 + 0x52c) = iVar5;

      *(bool *)(param_1 + 0x538) = iVar5 == 5;

      FUN_0089c6c0();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c49:

    ExceptionList = &local_14;

    if ((param_2 == 7) && (ExceptionList = &local_14, *(int **)(param_1 + 0x568) != (int *)0x0)) {

      ExceptionList = &local_14;

      lVar15 = (**(code **)(**(int **)(param_1 + 0x568) + 0x44c))();

      if ((lVar15 != -1) && (*(int **)(param_1 + 0x56c) != (int *)0x0)) {

        (**(code **)(**(int **)(param_1 + 0x56c) + 0x448))(0xffffffff);

      }

      FUN_0089b090();

      FUN_0089c330();

      FUN_0089bf50();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c4a:

    ExceptionList = &local_14;

    if ((param_2 == 7) && (ExceptionList = &local_14, *(int **)(param_1 + 0x56c) != (int *)0x0)) {

      ExceptionList = &local_14;

      lVar15 = (**(code **)(**(int **)(param_1 + 0x56c) + 0x44c))();

      if ((lVar15 != -1) && (*(int **)(param_1 + 0x568) != (int *)0x0)) {

        (**(code **)(**(int **)(param_1 + 0x568) + 0x448))(0xffffffff);

      }

      FUN_0089b090();

      FUN_0089c330();

      FUN_0089bf50();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c4b:

    ExceptionList = &local_14;

    if (param_2 == 0x1a) {

      ExceptionList = &local_14;

      FUN_007fcc10();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c4c:

    ExceptionList = &local_14;

    if (param_2 == 0x1a) {

      ExceptionList = &local_14;

      FUN_007fcc10();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c4d:

  case 0x9c4e:

    ExceptionList = &local_14;

    if (param_2 == 8) {

      ExceptionList = &local_14;

      FUN_0089b090();

      FUN_0089c330();

      ExceptionList = local_14;

      return 1;

    }

    break;

  case 0x9c50:

    ExceptionList = &local_14;

    if ((*(int *)(param_1 + 0x5e0) != 0) &&

       (ExceptionList = &local_14, *(int *)(param_1 + 0x5ec) != -1)) {

      if (param_2 == 5) {

        ExceptionList = &local_14;

        piVar2 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_1 + 0x5ec));

        if (piVar2 != (int *)0x0) {

          (**(code **)(*piVar2 + 8))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec),DAT_00d1b644);

          puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(param_1 + 0x5e0) + 0x140))(&uStack_1b8,1);

          piVar14 = *(int **)(param_1 + 0x5e0);

          puVar4 = &uStack_1b8;

LAB_0089c922:

          puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar14 + 0x120))(puVar4,1,1);

          FUN_007fd420(*puVar4,puVar4[1],*puVar3,puVar3[1]);

          if (DAT_00d1d8dc != (int *)0x0) {

            DAT_00d1d8dc[0x146] = 0;

          }

          (**(code **)*piVar2)(1);

          ExceptionList = pvStack_38;

          return 1;

        }

LAB_0089c988:

        FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer");

        ExceptionList = local_14;

        return 1;

      }

      ExceptionList = &local_14;

      if (param_2 == 6) {

        DAT_00d1d8f4 = 1;

        DAT_00d1d8f5 = 0;

        if (DAT_00d1d8dc != (int *)0x0) {

          ExceptionList = &local_14;

          (**(code **)(*DAT_00d1d8dc + 4))();

        }

        ExceptionList = local_14;

        return 1;

      }

    }

  }

  uVar12 = FUN_0087b500(param_2);

  ExceptionList = local_14;

  return uVar12;

}
