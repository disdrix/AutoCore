// =============================================================================
// Vehicle_EquipFromCreate
// -----------------------------------------------------------------------------
// Stable ID: aa_00504480
// Address:   0x00504480  (autoassault.exe, image base 0x400000)
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
 */

/* Vehicle_EquipFromCreate (0x00504480)

   Nested hardpoint equip during CreateVehicle (0x201D). Wheel CBID at packet+0x45c;

   GiveItemByCbid then Vehicle_SetWheelset. Also weapons/armor nests.

   See PATH_A_DEBUGGER.md, OWNER_WHEEL_RACE_RE.md. Imported from AutoCore decompile dump 2026-07-11.

    */



void __thiscall

Vehicle_EquipFromCreate

          (void *param_1,int param_2,int param_3,char param_4,uint32_t /* or float bits */ param_5,char param_6)



{

  int iVar1;

  uint32_t /* or float bits */ uVar2;

  void *pvVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  uint32_t /* or float bits */ unaff_retaddr;

  void **ppvVar8;

  char cVar9;

  bool bKeepPreviousAttached;

  uint32_t /* or float bits */ uVar10;

  uint32_t /* or float bits */ *puStack_4;

  

  piVar7 = (int *)0x0;

  if (*(char *)((int)param_1 + 0x2ac) == '\0') {

    if ((*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) == 0) ||

       (piVar7 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x4e8)), piVar7 == (int *)0x0)) {

      piVar7 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_2 + 0x45c));

      if (piVar7 != (int *)0x0) {

        iVar1 = (**(code **)(*piVar7 + 0x1f0))();

        if (iVar1 != 0) {

          (**(code **)(*piVar7 + 8))

                    (*(uint32_t /* or float bits */ *)(param_2 + 0x45c),

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,1);

          iVar1 = (**(code **)(*piVar7 + 0x1f0))();

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))

                    (param_2 + 0x458,param_3,

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,unaff_retaddr,0,1,0);

          if (param_4 == '\0') {

            iVar1 = (**(code **)(*piVar7 + 0x1f0))();

            *(uint8_t *)(iVar1 + 0xcc) = 1;

          }

        }

        goto LAB_00504569;

      }

    }

    else {

LAB_00504569:

      iVar1 = (**(code **)(*piVar7 + 0x1f0))();

      if (iVar1 != 0) {

        uVar2 = (**(code **)(*piVar7 + 0x1f0))();

        Vehicle_SetWheelset(uVar2);

        goto LAB_005045a1;

      }

    }

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*(uint32_t /* or float bits */ *)(param_2 + 0x45c));

  }

LAB_005045a1:

  if (param_3 != 2) {

    return;

  }

  if (*(int *)(param_2 + 0x5b4) != -1) {

    if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) != 0) {

      piVar7 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x640));

    }

    if (piVar7 == (int *)0x0) {

      piVar7 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_2 + 0x5b4));

      if (piVar7 != (int *)0x0) {

        iVar1 = (**(code **)(*piVar7 + 0x1f8))();

        if (iVar1 != 0) {

          (**(code **)(*piVar7 + 8))

                    (*(uint32_t /* or float bits */ *)(param_2 + 0x5b4),

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,1);

          iVar1 = (**(code **)(*piVar7 + 0x1f8))();

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))

                    (param_2 + 0x5b0,2,

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,unaff_retaddr,0,0,0);

        }

        goto LAB_0050466a;

      }

    }

    else {

LAB_0050466a:

      iVar1 = (**(code **)(*piVar7 + 0x1f8))();

      if (iVar1 != 0) {

        cVar9 = '\0';

        pvVar3 = (void *)(**(code **)(*piVar7 + 0x1f8))();

        Vehicle_SetEquippedArmor(param_1,pvVar3,cVar9);

        goto LAB_005046a4;

      }

    }

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*(uint32_t /* or float bits */ *)(param_2 + 0x5b4));

  }

LAB_005046a4:

  puStack_4 = (uint32_t /* or float bits */ *)((int)param_1 + 0x630);

  param_3 = 0;

  piVar6 = (int *)(param_2 + 0x894);

  do {

    if (*piVar6 != -1) {

      if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) != 0) {

        piVar7 = Object_ResolveFromTFID((TFID_16 *)(piVar6 + 0x23));

      }

      if (piVar7 == (int *)0x0) {

        piVar7 = (int *)CVOGReaction_GiveItemByCbid(*piVar6);

        if (piVar7 != (int *)0x0) {

          iVar1 = (**(code **)(*piVar7 + 0x1e0))();

          if (iVar1 != 0) {

            (**(code **)(*piVar7 + 8))

                      (*piVar6,*(uint32_t /* or float bits */ *)

                                (*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1),1);

            iVar1 = (**(code **)(*piVar7 + 0x1e0))();

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))

                      (piVar6 + -1,2,

                       *(uint32_t /* or float bits */ *)

                        (*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1),

                       unaff_retaddr,param_2,param_3,0);

          }

          goto LAB_0050477a;

        }

      }

      else {

LAB_0050477a:

        iVar1 = (**(code **)(*piVar7 + 0x1e0))();

        if (iVar1 != 0) {

          if (param_6 == '\0') {

            uVar10 = 0;

            iVar1 = param_3;

            uVar2 = (**(code **)(*piVar7 + 0x1e0))(param_3,0);

            Vehicle_AttachWeapon(uVar2,iVar1,uVar10);

            piVar5 = (int *)(**(code **)(*piVar7 + 0x1e0))();

            (**(code **)(*piVar5 + 0x18))(0);

          }

          else {

            if (*(int *)(*(int *)((int)param_1 + 0x260) + param_3 * 4) != 0) {

              FUN_00569d50();

            }

            uVar2 = (**(code **)(*piVar7 + 0x1e0))();

            *(uint32_t /* or float bits */ *)(*(int *)((int)param_1 + 0x260) + param_3 * 4) = uVar2;

            iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 4);

            iVar4 = (**(code **)(*piVar7 + 0x1e0))();

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x158))

                      (iVar1 + 4 + (int)param_1);

            iVar4 = (**(code **)(*piVar7 + 0x1e0))();

            iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

            *puStack_4 = *(uint32_t /* or float bits */ *)(iVar1 + 0x164 + iVar4);

            puStack_4[1] = *(uint32_t /* or float bits */ *)(iVar1 + 0x168 + iVar4);

          }

          goto LAB_00504851;

        }

      }

      FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*piVar6);

    }

LAB_00504851:

    puStack_4 = puStack_4 + 2;

    param_3 = param_3 + 1;

    piVar6 = piVar6 + 0x62;

  } while (param_3 < 3);

  if (*(int *)(param_2 + 0x30c) != -1) {

    if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) != 0) {

      piVar7 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x398));

    }

    if (piVar7 == (int *)0x0) {

      piVar7 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_2 + 0x30c));

      if (piVar7 != (int *)0x0) {

        iVar1 = (**(code **)(*piVar7 + 500))();

        if (iVar1 != 0) {

          (**(code **)(*piVar7 + 8))

                    (*(uint32_t /* or float bits */ *)(param_2 + 0x30c),

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,1);

          iVar1 = (**(code **)(*piVar7 + 500))();

          (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))

                    (param_2 + 0x308,2,

                     *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1)

                     ,unaff_retaddr,0,0,0);

        }

        goto LAB_00504930;

      }

    }

    else {

LAB_00504930:

      iVar1 = (**(code **)(*piVar7 + 500))();

      if (iVar1 != 0) {

        bKeepPreviousAttached = false;

        ppvVar8 = (void **)0x0;

        pvVar3 = (void *)(**(code **)(*piVar7 + 500))();

        Vehicle_EquipPowerPlant(param_1,pvVar3,ppvVar8,bKeepPreviousAttached);

        goto LAB_0050496c;

      }

    }

    FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*(uint32_t /* or float bits */ *)(param_2 + 0x30c));

  }

LAB_0050496c:

  if (*(int *)(param_2 + 0x234) == -1) {

    return;

  }

  if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1) != 0) {

    piVar7 = Object_ResolveFromTFID((TFID_16 *)(param_2 + 0x2c0));

  }

  if (piVar7 == (int *)0x0) {

    piVar7 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_2 + 0x234));

    if (piVar7 == (int *)0x0) goto LAB_00504a8c;

    iVar1 = __RTDynamicCast(piVar7,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0);

    if (iVar1 != 0) {

      (**(code **)(*piVar7 + 8))

                (*(uint32_t /* or float bits */ *)(param_2 + 0x234),

                 *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1),1);

      iVar1 = __RTDynamicCast(piVar7,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xc4))

                (param_2 + 0x230,2,

                 *(uint32_t /* or float bits */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1),

                 unaff_retaddr,0,0,0);

    }

  }

  iVar1 = __RTDynamicCast(piVar7,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                          &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor,0);

  if (iVar1 != 0) {

    cVar9 = '\0';

    ppvVar8 = (void **)0x0;

    pvVar3 = (void *)__RTDynamicCast(piVar7,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                     &CVOGSimpleObject<class_CVOGGraphicsBase>::RTTI_Type_Descriptor

                                     ,0);

    Vehicle_SetEquippedRaceItem(param_1,pvVar3,ppvVar8,cVar9);

    return;

  }

LAB_00504a8c:

  FUN_007a4480(0,"allocatenewobjectfromcbid failed %d",*(uint32_t /* or float bits */ *)(param_2 + 0x234));

  return;

}
