// =============================================================================
// FUN_00627170
// -----------------------------------------------------------------------------
// Stable ID: aa_00627170
// Address:   0x00627170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00627170 @ 0x00627170
// Stable ID: aa_00627170
// Embedded strings (evidence for future rename):
//   - "Skill %d applied to incorrect target %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~216 non-empty decompiler lines.
//  - Control keywords: if×26, goto×8, while×5, return×2, switch×1, do×1, for×1.
//  - Notable callees: FUN_00411900×6, Map_LowerBoundFindByIntKey×5, CONCAT22×4, FUN_005535c0×4, FUN_00627b20×4, FUN_00402c40×3, FUN_004022a0×2, Client_SendLogicUiPacket.
//  - Strings: "Skill %d applied to incorrect target %d".
//  - Return sites: 2.

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

void __thiscall

FUN_00627170(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint param_4,int param_5,char param_6)



{

  uint16_t uVar1;

  byte bVar2;

  int iVar3;

  char cVar4;

  int iVar5;

  int *extraout_EAX;

  int *extraout_EAX_00;

  int *extraout_EAX_01;

  int iVar6;

  int *extraout_EAX_02;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int *piVar9;

  int *extraout_EAX_03;

  int *piVar10;

  int iVar11;

  int unaff_EBX;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ local_160;

  int iStack_15c;

  char cStack_158;

  int iStack_154;

  int iStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  char cStack_148;

  int iStack_144;

  int local_140;

  uint8_t auStack_13c [4];

  uint8_t auStack_138 [28];

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  

  local_160 = 0;

  local_140 = param_1;

  iVar5 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

  if (iVar5 == 0) {

    FUN_007a4480(1,"Skill %d applied to incorrect target %d",*(uint32_t /* width from decompiler */ *)(param_1 + 0x620),

                 *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x18) + 0xa8) + 0x34));

    return;

  }

  switch(param_3) {

  case 0:

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x234))(param_4);

    if (iVar6 != 0) {

      if (param_6 == '\0') {

        iStack_15c = *(int *)(iVar6 + 0x5fc);

        Map_LowerBoundFindByIntKey((void *)(param_1 + 0x6c0),&iStack_144,&iStack_15c,unaff_ESI);

        if (*extraout_EAX == *(int *)(param_1 + 0x6c4)) goto switchD_006271d7_default;

      }

      uVar1 = *(uint16_t *)(iVar6 + 0x174);

      uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1dc))();

      cVar4 = FUN_005535c0(CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1) + param_2,uVar7);

      if (cVar4 != '\0') {

        iStack_15c = *(int *)(iVar6 + 0x5fc);

        cStack_158 = param_6;

        FUN_00627b20(&uStack_14c,&iStack_15c);

      }

    }

    goto switchD_006271d7_default;

  case 1:

    FUN_00402c40();

    iVar6 = FUN_00411900(&local_160);

    while (iVar6 != 0) {

      if (*(byte *)(iVar6 + 0x5f8) == param_4) {

        if (param_6 == '\0') {

          iStack_15c = *(int *)(iVar6 + 0x5fc);

          Map_LowerBoundFindByIntKey((void *)(param_1 + 0x6c0),&iStack_150,&iStack_15c,unaff_ESI);

          if (*extraout_EAX_00 == *(int *)(param_1 + 0x6c4)) goto LAB_00627372;

        }

        uVar1 = *(uint16_t *)(iVar6 + 0x174);

        uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1dc))();

        unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1) + param_2;

        cVar4 = FUN_005535c0(unaff_EBX,uVar7);

        if (cVar4 != '\0') {

          uStack_14c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x5fc);

          cStack_148 = param_6;

          FUN_00627b20(&iStack_15c,&uStack_14c);

        }

      }

LAB_00627372:

      iVar6 = FUN_00411900(&local_160);

    }

    break;

  case 2:

    FUN_00402c40();

    iVar6 = FUN_00411900(&local_160);

    while (iVar6 != 0) {

      if (param_5 == 0) {

        bVar2 = *(byte *)(iVar6 + 0x624) & 2;

LAB_006273e7:

        if (bVar2 != 0) {

          if (param_6 == '\0') {

            iStack_15c = *(int *)(iVar6 + 0x5fc);

            Map_LowerBoundFindByIntKey((void *)(param_1 + 0x6c0),&iStack_154,&iStack_15c,unaff_ESI);

            if (*extraout_EAX_01 == *(int *)(param_1 + 0x6c4)) goto LAB_0062747b;

          }

          uVar1 = *(uint16_t *)(iVar6 + 0x174);

          uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1dc))();

          unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1) + param_2;

          cVar4 = FUN_005535c0(unaff_EBX,uVar7);

          if (cVar4 != '\0') {

            uStack_14c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x5fc);

            cStack_148 = param_6;

            FUN_00627b20(&iStack_15c,&uStack_14c);

          }

        }

      }

      else if (param_5 == 1) {

        bVar2 = *(byte *)(iVar6 + 0x624) & 1;

        goto LAB_006273e7;

      }

LAB_0062747b:

      iVar6 = FUN_00411900(&local_160);

    }

    break;

  case 3:

    FUN_00402c40();

    iVar6 = FUN_00411900(&local_160);

    while (iVar6 != 0) {

      if (param_6 == '\0') {

        iStack_15c = *(int *)(iVar6 + 0x5fc);

        Map_LowerBoundFindByIntKey((void *)(param_1 + 0x6c0),auStack_13c,&iStack_15c,unaff_ESI);

        if (*extraout_EAX_02 != *(int *)(param_1 + 0x6c4)) goto LAB_00627503;

      }

      else {

LAB_00627503:

        uVar1 = *(uint16_t *)(iVar6 + 0x174);

        uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x1dc))();

        unaff_EBX = CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1) + param_2;

        cVar4 = FUN_005535c0(unaff_EBX,uVar7);

        if (cVar4 != '\0') {

          uStack_14c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x5fc);

          cStack_148 = param_6;

          FUN_00627b20(&iStack_15c,&uStack_14c);

        }

      }

      iVar6 = FUN_00411900(&local_160);

    }

    break;

  default:

    goto switchD_006271d7_default;

  }

  *(uint8_t *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x74 + iVar5) + 0x1d) = 0;

switchD_006271d7_default:

  iStack_15c = 0;

  do {

    iVar6 = iStack_15c;

    if (iStack_15c == 0) {

      iVar11 = *(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xb4 + iVar5);

LAB_006275d1:

      iStack_154 = iVar11;

      if (iVar11 != 0) {

        local_160 = 0;

        iStack_150 = 0;

        FUN_004294f0();

        iVar8 = FUN_004022a0(&local_160,&iStack_150);

        iVar3 = iStack_15c;

        while (iStack_15c = iVar3, iVar8 == 0) {

          if ((((iStack_150 != 0) && (*(int *)(iStack_150 + 0x1c) == 1)) &&

              (piVar9 = (int *)__RTDynamicCast(iStack_150,0,&CVOGHBBase::RTTI_Type_Descriptor,

                                               &CVOGHBSkillBase::RTTI_Type_Descriptor,0),

              piVar9 != (int *)0x0)) && ((*(byte *)((int)piVar9 + 0x639) & 1) != 0)) {

            iVar6 = piVar9[0x188];

            iStack_144 = iVar6;

            Map_LowerBoundFindByIntKey((void *)(param_1 + 0x6c0),auStack_13c,&iStack_144,unaff_ESI);

            iVar11 = iStack_154;

            if ((*extraout_EAX_03 != *(int *)(param_1 + 0x6c4)) &&

               (piVar10 = (int *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5

                                                      ) + 0x234))(iVar6), iVar11 = iStack_154,

               piVar10 != (int *)0x0)) {

              (**(code **)(*piVar9 + 0x14))();

              iVar6 = *piVar9;

              piVar9 = piVar9 + 9;

              for (iVar11 = 0x18c; iVar11 != 0; iVar11 = iVar11 + -1) {

                *piVar9 = *piVar10;

                piVar10 = piVar10 + 1;

                piVar9 = piVar9 + 1;

              }

              (**(code **)(iVar6 + 4))();

              iVar11 = iStack_154;

              param_1 = local_140;

            }

          }

          iVar8 = FUN_004022a0(&local_160,&iStack_150);

          iVar3 = iStack_15c;

          iVar6 = iStack_15c;

        }

        iStack_15c = iVar6;

        if (*(char *)(iVar11 + 0x28) != '\0') {

          *(uint8_t *)(iVar11 + 0x28) = 0;

          iStack_15c = iVar3;

          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar11 + 4));

          iStack_15c = iVar6;

        }

      }

    }

    else if ((iStack_15c == 1) && (iVar11 = *(int *)(iVar5 + 0x250), iVar11 != 0)) {

      iVar11 = *(int *)(*(int *)(*(int *)(iVar11 + 4) + 4) + 0xb4 + iVar11);

      goto LAB_006275d1;

    }

    iStack_15c = iStack_15c + 1;

    if (1 < iStack_15c) {

      if (*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xa8 + iVar5) != 0) {

        iVar6 = *(int *)(*(int *)(iVar5 + 4) + 4);

        uStack_118 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164 + iVar5);

        uStack_114 = *(uint32_t /* width from decompiler */ *)(iVar6 + iVar5 + 0x168);

        uStack_11c = 0x2c;

        Client_SendLogicUiPacket(auStack_138);

      }

      return;

    }

  } while( true );

}
