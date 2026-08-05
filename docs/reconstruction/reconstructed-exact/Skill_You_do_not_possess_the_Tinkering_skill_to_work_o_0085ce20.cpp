// READABILITY (auto CF):
//  - Body size: ~411 non-empty decompiler lines.
//  - Control keywords: if×29, for×14, goto×9, return×8, do×2, switch×2, while×1.
//  - Notable callees: FUN_007a6de0×5, FUN_00571010×4, FUN_007fd420×4, __RTDynamicCast×4, FUN_007a69d0×3, sprintf×2, Engineered, FUN_00513400.
//  - Strings: "Broken items cannot be further Reverse Engineered."; "You cannot Reverse Engineer crafting materials."; "Cannot be Reverse Engineered."; "Cannot be Reverse Engineered (No Recipe).".
//  - Return sites: 8.

// =============================================================================
// Skill_You_do_not_possess_the_Tinkering_skill_to_work_o_0085ce20
// -----------------------------------------------------------------------------
// Stable ID: aa_0085ce20
// Address:   0x0085ce20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "You do not possess the Tinkering skill to work on this object."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_You_do_not_possess_the_Tinkering_skill_to_work_o_0085ce20(char param_1)



{

  char cVar1;

  int *in_EAX;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  int *unaff_EBX;

  float10 fVar11;

  TypeDescriptor *pTVar12;

  TypeDescriptor *pTVar13;

  uint8_t *puVar14;

  uint8_t local_180 [8];

  float local_178 [2];

  uint8_t local_170 [2];

  uint32_t /* width from decompiler */ uStack_16e;

  char cStack_16a;

  char cStack_169;

  char local_168 [4];

  char local_164;

  uint8_t auStack_104 [20];

  char local_f0 [2];

  uint32_t /* width from decompiler */ local_ee [58];

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (DAT_00d1b9a8 == (int *)0x0) {

    return;

  }

  if (in_EAX == (int *)0x0) {

    return;

  }

  if (unaff_EBX == (int *)0x0) {

    return;

  }

  if (DAT_00d1d900 == 0) {

    fVar11 = (float10)FUN_0052e640(in_EAX);

    local_178[0] = (float)fVar11;

    _local_170 = _local_170 & 0xffff0000;

    puVar7 = (uint32_t /* width from decompiler */ *)(local_170 + 2);

    for (iVar8 = 0x1f; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    *(uint16_t *)puVar7 = 0;

    FUN_007a69d0();

    if ((param_1 == '\0') && (((uint)in_EAX[0x5f] >> 0x13 & 1) != 0)) {

      pcVar10 = "Broken items cannot be further Reverse Engineered.";

      puVar7 = (uint32_t /* width from decompiler */ *)local_170;

      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        puVar7 = puVar7 + 1;

      }

      *(uint16_t *)puVar7 = *(uint16_t *)pcVar10;

      *(char *)((int)puVar7 + 2) = pcVar10[2];

    }

    else if (*(int *)(in_EAX[0x2a] + 0x38) == 0x1a) {

      pcVar10 = "You cannot Reverse Engineer crafting materials.";

      puVar7 = (uint32_t /* width from decompiler */ *)local_170;

      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {

        *puVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        puVar7 = puVar7 + 1;

      }

    }

    else {

      cVar1 = FUN_00522950(in_EAX);

      if (cVar1 == '\0') {

        pcVar2 = (char *)FUN_007a6de0("Cannot be Reverse Engineered.",0xffffffff);

        pcVar10 = local_170;

        do {

          cVar1 = *pcVar2;

          *pcVar10 = cVar1;

          pcVar2 = pcVar2 + 1;

          pcVar10 = pcVar10 + 1;

        } while (cVar1 != '\0');

      }

      else {

        iVar8 = FUN_00599dd0();

        if (iVar8 < 1) {

          pcVar10 = "Cannot be Reverse Engineered (No Recipe).";

          puVar7 = (uint32_t /* width from decompiler */ *)local_170;

          for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {

            *puVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

            pcVar10 = pcVar10 + 4;

            puVar7 = puVar7 + 1;

          }

          *(uint16_t *)puVar7 = *(uint16_t *)pcVar10;

        }

        else if (((param_1 == '\0') && (iVar8 = (**(code **)(*in_EAX + 0x25c))(), 1 < iVar8)) &&

                (cVar1 = FUN_00513e70(), cVar1 != '\0')) {

          pcVar10 = 

          "Stacks cannot be Reverse Engineered, please split the stack into a single item first.";

          puVar7 = (uint32_t /* width from decompiler */ *)local_170;

          for (iVar8 = 0x15; iVar8 != 0; iVar8 = iVar8 + -1) {

            *puVar7 = *(uint32_t /* width from decompiler */ *)pcVar10;

            pcVar10 = pcVar10 + 4;

            puVar7 = puVar7 + 1;

          }

          *(uint16_t *)puVar7 = *(uint16_t *)pcVar10;

        }

        else if (local_178[0] <= g_flZero) {

          uVar4 = FUN_007a6de0("Reverse Engineering",0xffffffff);

          uVar5 = FUN_0052e1d0(in_EAX);

          uVar6 = FUN_007a6de0("Requires At Least",0xffffffff);

          sprintf(local_170,"%s %d %s",uVar6,uVar5,uVar4);

        }

        else if (*(char *)((int)unaff_EBX + 0xce) != '\0') {

          puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))(local_178,1);

          puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(&stack0xfffffe78,1,1);

          FUN_007fd420(*puVar3,puVar3[1],*puVar7,puVar7[1]);

        }

      }

    }

    (**(code **)(*unaff_EBX + 0x308))(local_170);

    goto LAB_0085d020;

  }

  if (DAT_00d1d900 == 5) {

    local_f0[0] = '\0';

    local_f0[1] = '\0';

    pcVar10 = local_f0 + 2;

    for (iVar8 = 0x38; iVar8 != 0; iVar8 = iVar8 + -1) {

      pcVar10[0] = '\0';

      pcVar10[1] = '\0';

      pcVar10[2] = '\0';

      pcVar10[3] = '\0';

      pcVar10 = pcVar10 + 4;

    }

    pcVar10[0] = '\0';

    pcVar10[1] = '\0';

    iVar8 = 0;

    if ((*(int *)(DAT_00d1b6d8 + 0x250) == 0) ||

       (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) == 0)) {

LAB_0085d0b8:

      if (*(int *)(DAT_00d1b6d8 + 0xcbc) != 0) {

        uVar6 = 0;

        pTVar13 = &CVOGGadget::RTTI_Type_Descriptor;

        pTVar12 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

        uVar5 = 0;

        uVar4 = FUN_00571010(DAT_00d1d940,DAT_00d1d944);

        iVar8 = __RTDynamicCast(uVar4,uVar5,pTVar12,pTVar13,uVar6);

      }

    }

    else {

      uVar6 = 0;

      pTVar13 = &CVOGGadget::RTTI_Type_Descriptor;

      pTVar12 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      uVar5 = 0;

      uVar4 = FUN_00571010(DAT_00d1d940,DAT_00d1d944);

      iVar8 = __RTDynamicCast(uVar4,uVar5,pTVar12,pTVar13,uVar6);

      if (iVar8 == 0) goto LAB_0085d0b8;

    }

    iVar8 = FUN_00513400(iVar8);

    if (iVar8 == 0) {

      if (*(char *)((int)unaff_EBX + 0xce) != '\0') {

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))(local_180,1);

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(local_180,1,1);

        FUN_007fd420(*puVar3,puVar3[1],*puVar7,puVar7[1]);

        (**(code **)(*unaff_EBX + 0x308))(auStack_104);

        goto LAB_0085d020;

      }

    }

    else {

      if (iVar8 == 1) {

        iVar8 = 7;

        pcVar2 = "No gadget slots are available.";

        pcVar10 = local_f0;

      }

      else {

        if (iVar8 == 2) {

          iVar8 = *unaff_EBX;

          pcVar10 = "This is the wrong type of gadget to use on this item.";

          pcVar2 = local_f0;

          for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {

            *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

            pcVar10 = pcVar10 + 4;

            pcVar2 = pcVar2 + 4;

          }

          *(uint16_t *)pcVar2 = *(uint16_t *)pcVar10;

          (**(code **)(iVar8 + 0x308))(local_f0);

          goto LAB_0085d020;

        }

        if (iVar8 != 3) {

          iVar8 = *unaff_EBX;

          pcVar10 = "You cannot use this gadget on this item.";

          pcVar2 = local_f0;

          for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {

            *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

            pcVar10 = pcVar10 + 4;

            pcVar2 = pcVar2 + 4;

          }

          *pcVar2 = *pcVar10;

          (**(code **)(iVar8 + 0x308))(local_f0);

          goto LAB_0085d020;

        }

        iVar8 = 0xe;

        pcVar2 = "That gadget is already on the item, no duplicates allowed.";

        pcVar10 = local_f0;

      }

      for (; iVar8 != 0; iVar8 = iVar8 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar2;

        pcVar2 = pcVar2 + 4;

        pcVar10 = pcVar10 + 4;

      }

      *(uint16_t *)pcVar10 = *(uint16_t *)pcVar2;

      pcVar10[2] = pcVar2[2];

    }

    (**(code **)(*unaff_EBX + 0x308))(local_f0);

  }

  else {

    if (DAT_00d1d900 != 4) {

      (**(code **)(*unaff_EBX + 0x308))(0);

      puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))(&stack0xfffffe7c,1);

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(&stack0xfffffe7c,1,1);

      FUN_007fd420(*puVar3,puVar3[1],*puVar7,puVar7[1]);

      return;

    }

    local_f0[0] = '\0';

    local_f0[1] = '\0';

    pcVar10 = local_f0 + 2;

    for (iVar8 = 0x38; iVar8 != 0; iVar8 = iVar8 + -1) {

      pcVar10[0] = '\0';

      pcVar10[1] = '\0';

      pcVar10[2] = '\0';

      pcVar10[3] = '\0';

      pcVar10 = pcVar10 + 4;

    }

    pcVar10[0] = '\0';

    pcVar10[1] = '\0';

    if ((*(int *)(DAT_00d1b6d8 + 0x250) == 0) ||

       (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x2b0) == 0)) {

LAB_0085d271:

      if (*(int *)(DAT_00d1b6d8 + 0xcbc) == 0) {

        return;

      }

      uVar6 = 0;

      pTVar13 = &CVOGTinkeringKit::RTTI_Type_Descriptor;

      pTVar12 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      uVar5 = 0;

      uVar4 = FUN_00571010(DAT_00d1d938,DAT_00d1d93c);

      iVar8 = __RTDynamicCast(uVar4,uVar5,pTVar12,pTVar13,uVar6);

      if (iVar8 == 0) {

        return;

      }

    }

    else {

      uVar6 = 0;

      pTVar13 = &CVOGTinkeringKit::RTTI_Type_Descriptor;

      pTVar12 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

      uVar5 = 0;

      uVar4 = FUN_00571010(DAT_00d1d938,DAT_00d1d93c);

      iVar8 = __RTDynamicCast(uVar4,uVar5,pTVar12,pTVar13,uVar6);

      if (iVar8 == 0) goto LAB_0085d271;

    }

    iVar9 = FUN_00513c10(DAT_00d1b6d8,iVar8);

    if (iVar9 == 4) {

      if (*(char *)((int)unaff_EBX + 0xce) != '\0') {

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))(local_180,1);

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(local_180,1,1);

        FUN_007fd420(*puVar3,puVar3[1],*puVar7,puVar7[1]);

        (**(code **)(*unaff_EBX + 0x308))(auStack_104);

        goto LAB_0085d020;

      }

      goto switchD_0085d36f_default;

    }

    if (((uint)in_EAX[0x5f] >> 0x13 & 1) != 0) {

      iVar8 = *unaff_EBX;

      pcVar10 = "You cannot use Tinkering Kits on Broken Items!";

      pcVar2 = local_f0;

      for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar2 = pcVar2 + 4;

      }

      *(uint16_t *)pcVar2 = *(uint16_t *)pcVar10;

      pcVar2[2] = pcVar10[2];

      (**(code **)(iVar8 + 0x308))(local_f0);

      goto LAB_0085d020;

    }

    switch(iVar9) {

    case 0:

      iVar8 = *unaff_EBX;

      pcVar10 = "The object has no available slots to open.";

      pcVar2 = local_f0;

      for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar2 = pcVar2 + 4;

      }

      *(uint16_t *)pcVar2 = *(uint16_t *)pcVar10;

      pcVar2[2] = pcVar10[2];

      (**(code **)(iVar8 + 0x308))(local_f0);

      break;

    case 1:

      iVar8 = *unaff_EBX;

      pcVar10 = "You do not possess the Tinkering skill to work on this object.";

      pcVar2 = local_f0;

      for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar2 = pcVar2 + 4;

      }

      *(uint16_t *)pcVar2 = *(uint16_t *)pcVar10;

      pcVar2[2] = pcVar10[2];

      (**(code **)(iVar8 + 0x308))(local_f0);

      break;

    case 2:

      iVar8 = *unaff_EBX;

      pcVar10 = "This Tinkering Kit is too primitive to use on this object.";

      pcVar2 = local_f0;

      for (iVar9 = 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar2 = pcVar2 + 4;

      }

      *(uint16_t *)pcVar2 = *(uint16_t *)pcVar10;

      pcVar2[2] = pcVar10[2];

      (**(code **)(iVar8 + 0x308))(local_f0);

      break;

    case 3:

      switch(*(uint32_t /* width from decompiler */ *)(iVar8 + 0xb4)) {

      case 10:

        local_170[0] = s_Power_Plants_00a64cc8[0];

        local_170[1] = s_Power_Plants_00a64cc8[1];

        uStack_16e._0_1_ = s_Power_Plants_00a64cc8[2];

        uStack_16e._1_1_ = s_Power_Plants_00a64cc8[3];

        uStack_16e._2_1_ = s_Power_Plants_00a64cc8[4];

        uStack_16e._3_1_ = s_Power_Plants_00a64cc8[5];

        cStack_16a = s_Power_Plants_00a64cc8[6];

        cStack_169 = s_Power_Plants_00a64cc8[7];

        local_168[0] = s_Power_Plants_00a64cc8[8];

        local_168[1] = s_Power_Plants_00a64cc8[9];

        local_168[2] = s_Power_Plants_00a64cc8[10];

        local_168[3] = s_Power_Plants_00a64cc8[0xb];

        local_164 = s_Power_Plants_00a64cc8[0xc];

        break;

      default:

        local_170[0] = s_Other_00a2da84[0];

        local_170[1] = s_Other_00a2da84[1];

        uStack_16e._0_1_ = s_Other_00a2da84[2];

        uStack_16e._1_1_ = s_Other_00a2da84[3];

        uStack_16e._2_1_ = s_Other_00a2da84[4];

        uStack_16e._3_1_ = s_Other_00a2da84[5];

        break;

      case 0xc:

        local_170[0] = s_Weapons_00a64cc0[0];

        local_170[1] = s_Weapons_00a64cc0[1];

        uStack_16e._0_1_ = s_Weapons_00a64cc0[2];

        uStack_16e._1_1_ = s_Weapons_00a64cc0[3];

        uStack_16e._2_1_ = s_Weapons_00a64cc0[4];

        uStack_16e._3_1_ = s_Weapons_00a64cc0[5];

        cStack_16a = s_Weapons_00a64cc0[6];

        cStack_169 = s_Weapons_00a64cc0[7];

        break;

      case 0xe:

        local_170[0] = s_Vehicles_00a64cb4[0];

        local_170[1] = s_Vehicles_00a64cb4[1];

        uStack_16e._0_1_ = s_Vehicles_00a64cb4[2];

        uStack_16e._1_1_ = s_Vehicles_00a64cb4[3];

        uStack_16e._2_1_ = s_Vehicles_00a64cb4[4];

        uStack_16e._3_1_ = s_Vehicles_00a64cb4[5];

        cStack_16a = s_Vehicles_00a64cb4[6];

        cStack_169 = s_Vehicles_00a64cb4[7];

        local_168[0] = s_Vehicles_00a64cb4[8];

        break;

      case 0x10:

        local_170[0] = s_Wheelsets_00a64ca8[0];

        local_170[1] = s_Wheelsets_00a64ca8[1];

        uStack_16e._0_1_ = s_Wheelsets_00a64ca8[2];

        uStack_16e._1_1_ = s_Wheelsets_00a64ca8[3];

        uStack_16e._2_1_ = s_Wheelsets_00a64ca8[4];

        uStack_16e._3_1_ = s_Wheelsets_00a64ca8[5];

        cStack_16a = s_Wheelsets_00a64ca8[6];

        cStack_169 = s_Wheelsets_00a64ca8[7];

        local_168[0] = s_Wheelsets_00a64ca8[8];

        local_168[1] = s_Wheelsets_00a64ca8[9];

        break;

      case 0x1c:

        local_170[0] = s_Armor_00a2e6a4[0];

        local_170[1] = s_Armor_00a2e6a4[1];

        uStack_16e._0_1_ = s_Armor_00a2e6a4[2];

        uStack_16e._1_1_ = s_Armor_00a2e6a4[3];

        uStack_16e._2_1_ = s_Armor_00a2e6a4[4];

        uStack_16e._3_1_ = s_Armor_00a2e6a4[5];

      }

      puVar14 = local_170;

      uVar4 = 0xffffffff;

      FUN_007a69d0(puVar14,0xffffffff);

      uVar4 = FUN_007a6de0(puVar14,uVar4);

      uVar5 = 0xffffffff;

      pcVar10 = "This Tinkering Kit can only be used on";

      FUN_007a69d0("This Tinkering Kit can only be used on",0xffffffff,uVar4);

      uVar4 = FUN_007a6de0(pcVar10,uVar5);

      sprintf(local_f0,"%s %s.",uVar4);

    default:

switchD_0085d36f_default:

      (**(code **)(*unaff_EBX + 0x308))(local_f0);

    }

  }

LAB_0085d020:

  puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00d1b9a8 + 0x120))(&stack0xfffffe7c,1,0);

  (**(code **)(*unaff_EBX + 0x314))(*puVar7,puVar7[1]);

  return;

}
