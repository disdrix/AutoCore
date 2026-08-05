// READABILITY (auto CF):
//  - Body size: ~344 non-empty decompiler lines.
//  - Control keywords: if×34, while×9, goto×7, return×6, do×3, for×1.
//  - Notable callees: CNDHash_LookupByKey×7, FUN_0053fff0×7, FUN_00411900×6, FUN_004e54a0×5, CVOGCharacter_CheckMissionRequirements×4, CONCAT31×3, CVOGCharacter_HasCompletedMission×3, FUN_00402c40×3.
//  - Return sites: 6.

// =============================================================================
// Mission_Uses_CVOGCharacter_CheckMissionRequirements
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "CVOGCharacter_CheckMissionRequirements"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004d5c10 clean capture (not modernized).
//
// Address:  0x004d5c10  (autoassault.exe, image base 0x400000)
// Stable:   aa_004d5c10
// Stable ID: aa_004d5c10
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004d5c10_*.md
//           Original Ghidra symbol: FUN_004d5c10
//
// Exactness: Body mirrors reconstructed-exact/FUN_004d5c10*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_CVOGCharacter_CheckMissionRequirements
// -----------------------------------------------------------------------------
// Stable ID: aa_004d5c10
// Address:   0x004d5c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "CVOGCharacter_CheckMissionRequirements"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_Uses_CVOGCharacter_CheckMissionRequirements(TFID_16 *param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  short sVar1;

  short sVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  char cVar5;

  bool bVar6;

  int iVar7;

  int *piVar8;

  void *pvVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int *piVar11;

  uint *puVar12;

  int iVar13;

  TFID_16 *pTVar14;

  uint *puVar15;

  int iVar16;

  uint uVar17;

  uint32_t /* width from decompiler */ *puVar18;

  int *unaff_EDI;

  int local_44;

  uint auStack_40 [2];

  uint8_t local_38 [4];

  int *local_34;

  int local_30;

  void *pvStack_28;

  uint32_t /* width from decompiler */ *puStack_24;

  int iStack_20;

  uint32_t /* width from decompiler */ *puStack_18;

  int iStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pTVar14 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2118;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar7 = CVOGReaction_ResolveObjectTarget(0,param_1[1].dwCoidLo,param_1[1].dwCoidHi);

  local_44 = iVar7;

  local_34 = (int *)FUN_0040fb90();

  local_30 = 0;

  local_4 = 0;

  piVar8 = Object_ResolveFromTFID(pTVar14);

  if ((piVar8 != (int *)0x0) &&

     (piVar8 = (int *)(**(code **)(*piVar8 + 0x210))(0), piVar8 != (int *)0x0)) {

    FUN_0052d8b0(0,0xffffffff);

    if ((iVar7 != 0) && (*(int *)(*(int *)(iVar7 + 0xa8) + 0x38) == 0x3a)) {

      if ((*(int *)(iVar7 + 0x1d8) != 0) &&

         (param_1 = (TFID_16 *)(*(int *)(iVar7 + 0x1dc) - *(int *)(iVar7 + 0x1d8) >> 3),

         param_1 != (TFID_16 *)0x0)) {

        puVar10 = (uint32_t /* width from decompiler */ *)FUN_004e25d0(0);

        piVar11 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar10,puVar10[1]);

        if ((piVar11 != (int *)0x0) &&

           (((**(code **)(*piVar11 + 0x124))(local_38), local_30 != 0 &&

            (*(int *)((*(int **)(*local_34 + 8))[0x2a] + 0x38) == 0x12)))) {

          iVar7 = (**(code **)(**(int **)(*local_34 + 8) + 0x1d8))();

          *param_2 = iVar7;

        }

      }

      param_1 = (TFID_16 *)0x0;

      if (*param_2 != 0) {

        FUN_00402c40();

        auStack_40[0] = 0;

        puVar12 = (uint *)FUN_00411900(auStack_40);

        param_1 = (TFID_16 *)puVar12;

        piVar11 = param_2;

        while (param_2 = piVar11, puVar12 != (uint *)0x0) {

          uVar17 = *puVar12;

          iVar7 = *(int *)(*(int *)(*(int *)(piVar8[0x14c] + 0x10) +

                                   (*(uint *)(piVar8[0x14c] + 8) & uVar17) * 4) + 4);

          if (iVar7 == 0) {

LAB_004d5e32:

            iVar7 = 0;

          }

          else {

            do {

              if (uVar17 == *(uint *)(iVar7 + 0x10)) {

                if (iVar7 == 0) goto LAB_004d5e32;

                iVar7 = *(int *)(iVar7 + 8);

                goto LAB_004d5e39;

              }

              iVar7 = *(int *)(iVar7 + 0xc);

            } while (iVar7 != 0);

            iVar7 = 0;

          }

LAB_004d5e39:

          if (((iVar7 != 0) &&

              (iVar16 = *piVar11 + *(int *)(*(int *)(*piVar11 + 4) + 4),

              *(int *)(iVar7 + 0x20) == *(int *)(*(int *)(iVar16 + 0xac) + 0x34))) &&

             (*(int *)(iVar7 + 0x24) == *(int *)(*(int *)(iVar16 + 0xa8) + 0xfc))) {

            FUN_0052c700(uVar17,iVar7);

            uVar17 = *puVar12;

            cVar5 = FUN_0052b420(puVar12,*piVar11);

            param_1 = (TFID_16 *)CONCAT31(param_1._1_3_,cVar5 == '\0');

            iVar7 = FUN_0052dac0(uVar17,1);

            *(uint8_t *)(iVar7 + 0x2c) = param_1._0_1_;

          }

          puVar12 = (uint *)FUN_00411900(auStack_40);

          piVar11 = param_2;

        }

        *(uint8_t *)(piVar8[0x150] + 0x1d) = 0;

      }

      iVar7 = local_44;

      param_1 = (TFID_16 *)0x0;

      pvStack_28 = (void *)0x0;

      puStack_24 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_20 = 0;

      puStack_18 = (uint32_t /* width from decompiler */ *)0x0;

      iStack_14 = 0;

      uStack_10 = 0;

      local_4 = CONCAT31(local_4._1_3_,2);

      if ((*(int *)(local_44 + 0x234) == 0) ||

         (auStack_40[0] = *(int *)(local_44 + 0x238) - *(int *)(local_44 + 0x234) >> 2,

         auStack_40[0] == 0)) {

        pTVar14 = param_1;

        if ((*(int *)(local_44 + 0x244) != 0) &&

           (auStack_40[0] = *(int *)(local_44 + 0x248) - *(int *)(local_44 + 0x244) >> 2,

           auStack_40[0] != 0)) {

          auStack_40[0] = 0;

          while ((*(int *)(local_44 + 0x244) != 0 &&

                 (auStack_40[0] <

                  (uint)(*(int *)(local_44 + 0x248) - *(int *)(local_44 + 0x244) >> 2)))) {

            iVar7 = *(int *)(local_44 + 0x244);

            iVar16 = auStack_40[0] * 4;

            pvVar9 = CNDHash_LookupByKey((void *)piVar8[0x150],*(uint *)(iVar7 + iVar16));

            if (pvVar9 == (void *)0x0) {

              bVar6 = CVOGCharacter_HasCompletedMission(piVar8,*(uint *)(iVar7 + iVar16));

              if (bVar6) {

                pTVar14 = CNDHash_LookupByKey((void *)piVar8[0x14e],

                                              *(uint *)(*(int *)(local_44 + 0x244) + iVar16));

                sVar1._0_1_ = pTVar14[10].bPad3;

                sVar1._1_1_ = pTVar14[10].bPad4;

                param_1 = pTVar14;

                if ((sVar1 == -1) &&

                   (iVar7 = CVOGCharacter_CheckMissionRequirements(pTVar14,piVar8,unaff_EDI),

                   iVar7 == 0)) {

                  FUN_004e54a0(&param_1);

                }

                goto LAB_004d62b6;

              }

              uVar17 = *(uint *)(*(int *)(local_44 + 0x244) + iVar16);

              puVar10 = (uint32_t /* width from decompiler */ *)FUN_0053fff0();

              if ((void *)*puVar10 == (void *)0x0) {

                auStack_40[0] = auStack_40[0] + 1;

                pTVar14 = (TFID_16 *)0x0;

                param_1 = (TFID_16 *)0x0;

              }

              else {

                pTVar14 = CNDHash_LookupByKey((void *)*puVar10,uVar17);

                param_1 = pTVar14;

                if ((pTVar14 == (TFID_16 *)0x0) ||

                   (iVar7 = CVOGCharacter_CheckMissionRequirements(pTVar14,piVar8,unaff_EDI),

                   iVar7 != 0)) goto LAB_004d62b6;

                FUN_004e54a0(&param_1);

                auStack_40[0] = auStack_40[0] + 1;

              }

            }

            else {

LAB_004d62b6:

              auStack_40[0] = auStack_40[0] + 1;

            }

          }

        }

      }

      else {

        iVar16 = 0;

        FUN_00402c40();

        local_44 = 0;

        iVar13 = FUN_00411900(&local_44);

        while (iVar13 != 0) {

          if ((*(short *)(iVar13 + 0xac) != 0) && (iVar16 = iVar16 + 1, 7 < iVar16)) {

            *(uint8_t *)(piVar8[0x150] + 0x1d) = 0;

            FUN_00691630();

            FUN_00691630();

            goto LAB_004d6150;

          }

          iVar13 = FUN_00411900(&local_44);

        }

        *(uint8_t *)(piVar8[0x150] + 0x1d) = 0;

        FUN_0053fff0();

        FUN_00402c40();

        local_44 = 0;

        FUN_0053fff0();

        pTVar14 = (TFID_16 *)FUN_00411900(&local_44);

        while (param_1 = pTVar14, pTVar14 != (TFID_16 *)0x0) {

          puVar12 = *(uint **)(iVar7 + 0x238);

          puVar15 = *(uint **)(iVar7 + 0x234);

          if (puVar15 != puVar12) {

            do {

              if (*puVar15 == (uint)*(byte *)((int)&pTVar14[8].dwCoidHi + 2)) break;

              puVar15 = puVar15 + 1;

            } while (puVar15 != puVar12);

            if (((puVar15 != puVar12) &&

                (pvVar9 = CNDHash_LookupByKey((void *)piVar8[0x150],pTVar14->dwCoidLo),

                pvVar9 == (void *)0x0)) &&

               (iVar16 = CVOGCharacter_CheckMissionRequirements(pTVar14,piVar8,unaff_EDI),

               iVar16 == 0)) {

              bVar6 = CVOGCharacter_HasCompletedMission(piVar8,pTVar14->dwCoidLo);

              if (!bVar6) {

                FUN_004e54a0(&param_1);

              }

              FUN_004e54a0(&param_1);

            }

          }

          FUN_0053fff0();

          pTVar14 = (TFID_16 *)FUN_00411900(&local_44);

        }

        piVar11 = (int *)FUN_0053fff0();

        *(uint8_t *)(*piVar11 + 0x1d) = 0;

        pTVar14 = (TFID_16 *)0x0;

      }

      if ((pTVar14 == (TFID_16 *)0x0) && (iVar7 = *param_2, iVar7 != 0)) {

        uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 0xac + iVar7) + 0x34);

        FUN_0053fff0();

        puVar10 = (uint32_t /* width from decompiler */ *)FUN_004e26d0(uVar3);

        FUN_00508770();

        auStack_40[0] = 0;

        iVar7 = FUN_004e1830(auStack_40,&param_1);

        piVar11 = param_2;

        pTVar14 = param_1;

        while ((param_1 = pTVar14, iVar7 == 0 && (pTVar14 != (TFID_16 *)0x0))) {

          iVar7._0_1_ = pTVar14[0xf].bPad3;

          iVar7._1_1_ = pTVar14[0xf].bPad4;

          iVar7._2_1_ = pTVar14[0xf].bPad5;

          iVar7._3_1_ = pTVar14[0xf].bPad6;

          if (((iVar7 == *(int *)(*(int *)(*(int *)(*(int *)(*piVar11 + 4) + 4) + 0xa8 + *piVar11) +

                                 0xfc)) &&

              ((pvVar9 = CNDHash_LookupByKey((void *)piVar8[0x150],pTVar14->dwCoidLo),

               pvVar9 == (void *)0x0 &&

               (iVar7 = CVOGCharacter_CheckMissionRequirements(pTVar14,piVar8,unaff_EDI), iVar7 == 0

               )))) && ((bVar6 = CVOGCharacter_HasCompletedMission(piVar8,pTVar14->dwCoidLo), !bVar6

                        || (sVar2._0_1_ = pTVar14[10].bPad3, sVar2._1_1_ = pTVar14[10].bPad4,

                           sVar2 == -1)))) {

            FUN_004e54a0(&param_1);

          }

          iVar7 = FUN_004e1830(auStack_40,&param_1);

          pTVar14 = param_1;

        }

        if (*(char *)(puVar10 + 10) != '\0') {

          *(uint8_t *)(puVar10 + 10) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar10 + 1));

        }

        FUN_0053fff0();

        (**(code **)*puVar10)(1);

      }

      puVar10 = puStack_18;

      uVar17 = 0;

      puVar18 = puStack_18;

      while ((puVar10 != (uint32_t /* width from decompiler */ *)0x0 && (uVar17 < (uint)(iStack_14 - (int)puVar10 >> 2)))) {

        if ((pvStack_28 == (void *)0x0) ||

           ((uint)(iStack_20 - (int)pvStack_28 >> 2) <=

            (uint)((int)puStack_24 - (int)pvStack_28 >> 2))) {

          FUN_004e39d0(puStack_24,1,puVar18);

          uVar17 = uVar17 + 1;

          puVar18 = puVar18 + 1;

        }

        else {

          *puStack_24 = *puVar18;

          puStack_24 = puStack_24 + 1;

          uVar17 = uVar17 + 1;

          puVar18 = puVar18 + 1;

        }

      }

      FUN_004e4b10(0,0);

      uVar3 = param_3;

      uVar17 = 0;

      do {

        if ((pvStack_28 == (void *)0x0) ||

           ((uint)((int)puStack_24 - (int)pvStack_28 >> 2) <= uVar17)) {

          if (puStack_18 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(puStack_18);

          }

          if (pvStack_28 == (void *)0x0) {

            piVar8 = (int *)*local_34;

            *local_34 = (int)local_34;

            local_34[1] = (int)local_34;

            local_30 = 0;

            if (piVar8 == local_34) {

                    /* WARNING: Subroutine does not return */

              operator_delete(local_34);

            }

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar8);

          }

                    /* WARNING: Subroutine does not return */

          operator_delete(pvStack_28);

        }

        puVar12 = *(uint **)((int)pvStack_28 + uVar17 * 4);

        uVar4 = *puVar12;

        for (iVar7 = *(int *)(*(int *)(*(int *)(piVar8[0x150] + 0x10) +

                                      (*(uint *)(piVar8[0x150] + 8) & uVar4) * 4) + 4); iVar7 != 0;

            iVar7 = *(int *)(iVar7 + 0xc)) {

          if (uVar4 == *(uint *)(iVar7 + 0x10)) {

            if ((iVar7 != 0) && (*(int *)(iVar7 + 8) != 0)) goto LAB_004d6441;

            break;

          }

        }

        if (*param_2 != 0) {

          iVar7 = FUN_0052dac0(uVar4,1);

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0x20) =

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(*param_2 + 4) + 4) + 0xac + *param_2) + 0x34);

          *(uint32_t /* width from decompiler */ *)(iVar7 + 0x24) =

               *(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(*param_2 + 4) + 4) + 0xa8 + *param_2) + 0xfc);

          *(uint *)(iVar7 + 0x28) = *puVar12;

        }

        FUN_004d08c0(puVar12,piVar8,uVar3);

LAB_004d6441:

        uVar17 = uVar17 + 1;

      } while( true );

    }

    uVar17._0_1_ = pTVar14[1].bGlobal;

    uVar17._1_1_ = pTVar14[1].bPad0;

    uVar17._2_1_ = pTVar14[1].bPad1;

    uVar17._3_1_ = pTVar14[1].bPad2;

    pvVar9 = CNDHash_LookupByKey((void *)piVar8[0x152],uVar17);

    if (pvVar9 != (void *)0x0) {

      puVar12 = *(uint **)((int)pvVar9 + 0x14c);

      if (puVar12 == (uint *)0x0) goto LAB_004d6150;

      pvVar9 = CNDHash_LookupByKey((void *)piVar8[0x14c],*puVar12);

      FUN_004cf100(puVar12,piVar8,pvVar9);

      piVar8 = Object_ResolveFromTFID(pTVar14 + 2);

      iVar7 = (**(code **)(*piVar8 + 0x1d8))();

      *param_2 = iVar7;

      uVar17 = *puVar12;

      cVar5 = FUN_0052b420(puVar12,iVar7);

      param_2 = (int *)CONCAT31(param_2._1_3_,cVar5 == '\0');

      iVar7 = FUN_0052dac0(uVar17,1);

      *(uint8_t *)(iVar7 + 0x2c) = param_2._0_1_;

    }

    FUN_00403430();

    ExceptionList = pvStack_c;

    return;

  }

LAB_004d6150:

  FUN_00403430();

  ExceptionList = pvStack_c;

  return;

}
