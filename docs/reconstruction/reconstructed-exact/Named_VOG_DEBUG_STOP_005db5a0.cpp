// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×23, return×14, goto×4, while×3, do×2, switch×1.
//  - Notable callees: FUN_004d0250×6, __RTDynamicCast×3, FUN_0040aff0×2, FUN_004bb070×2, TFID_EqualsObjectId×2, FUN_004ba740, FUN_005db5a0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 14.

// =============================================================================
// Named_VOG_DEBUG_STOP_005db5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005db5a0
// Address:   0x005db5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_005db5a0(int param_1,int *param_2)



{

  char cVar1;

  RACE_ID_INFERRED RVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  void *pvVar7;

  bool bVar8;

  uint8_t *puVar9;

  uint32_t /* width from decompiler */ *pB;

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [16];

  uint8_t auStack_10 [16];

  

  if (param_2 == (int *)0x0) {

    return;

  }

  if (*(char *)(param_1 + 0xde) == '\0') {

    return;

  }

  *(uint *)(param_1 + 0x194) = g_dwClientTickMs;

  if (*(char *)(param_1 + 0x160) == '\0') {

    return;

  }

  if ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x181 + param_1) & 0x20) == 0) {

    return;

  }

  cVar1 = (**(code **)(*param_2 + 0x198))();

  if (cVar1 != '\0') {

    return;

  }

  switch(*(uint8_t *)(param_1 + 0xdc)) {

  case 0:

    iVar4 = (**(code **)(*param_2 + 0x210))(0);

    if (iVar4 != 0) {

LAB_005db706:

      FUN_004d0250(param_1,param_2);

      return;

    }

    if (*(int *)(param_2[0x2a] + 0x38) == 0x12) {

      pB = &DAT_009db5b0;

      puVar9 = auStack_30;

      __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                      &CVOGCreature::RTTI_Type_Descriptor,0,puVar9);

      pvVar7 = (void *)FUN_004ba740(puVar9);

      iVar4 = TFID_NotEquals(pvVar7,pB);

      if ((char)iVar4 != '\0') {

LAB_005db673:

        FUN_004d0250(param_1,param_2);

        return;

      }

    }

    break;

  case 1:

    bVar8 = *(int *)(param_2[0x2a] + 0x38) == 0x12;

    goto LAB_005db69a;

  case 2:

    bVar8 = *(int *)(param_2[0x2a] + 0x38) == 0xe;

LAB_005db69a:

    if (bVar8) {

      FUN_004d0250(param_1,param_2);

      return;

    }

    break;

  case 3:

    iVar4 = (**(code **)(*param_2 + 0x214))();

    if ((iVar4 != 0) &&

       (iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1),

       RVar2 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4)),

       RVar2 != *(RACE_ID_INFERRED *)(iVar3 + 0xf8))) goto LAB_005db706;

    break;

  case 4:

    pvVar7 = *(void **)(param_1 + 0x128);

    if (pvVar7 != *(void **)(param_1 + 300)) {

      do {

        if (*(int *)(param_2[0x2a] + 0x38) == 0xe) {

          iVar4 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGVehicle::RTTI_Type_Descriptor,0);

          iVar4 = *(int *)(iVar4 + 0x280);

LAB_005db768:

          if ((iVar4 != 0) &&

             (iVar4 = TFID_EqualsObjectId((void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x164 + iVar4

                                                  ),pvVar7), (char)iVar4 != '\0')) {

            FUN_004d0250(param_1,param_2);

          }

        }

        else {

          if (*(int *)(param_2[0x2a] + 0x38) == 0x12) {

            iVar4 = __RTDynamicCast(param_2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGCreature::RTTI_Type_Descriptor,0);

            iVar4 = *(int *)(iVar4 + 600);

            goto LAB_005db768;

          }

          iVar4 = TFID_EqualsObjectId(pvVar7,param_2 + 0x58);

          if ((char)iVar4 != '\0') goto LAB_005db673;

        }

        pvVar7 = (void *)((int)pvVar7 + 0x10);

        if (pvVar7 == *(void **)(param_1 + 300)) {

          return;

        }

      } while( true );

    }

    break;

  case 5:

    iVar4 = (**(code **)(*param_2 + 0x214))();

    if (iVar4 != 0) {

      uVar5 = FUN_0040aff0(auStack_20);

      iVar4 = FUN_004bb070(uVar5);

      if ((iVar4 != 0) && (piVar6 = *(int **)(param_1 + 0x128), piVar6 != *(int **)(param_1 + 300)))

      {

        do {

          iVar3 = (**(code **)(*param_2 + 0x1d4))();

          if (iVar3 != 0) {

            iVar3 = (**(code **)(*param_2 + 0x1d4))();

            if ((*(int *)(iVar3 + 0x14c) == *piVar6) &&

               (*(int *)(iVar3 + 0x14c) >> 0x1f == piVar6[1])) {

              FUN_004d0250(param_1,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

              return;

            }

          }

          piVar6 = piVar6 + 4;

        } while (piVar6 != *(int **)(param_1 + 300));

      }

    }

    break;

  case 6:

    iVar4 = (**(code **)(*param_2 + 0x214))();

    if (iVar4 != 0) {

      uVar5 = FUN_0040aff0(auStack_10);

      iVar4 = FUN_004bb070(uVar5);

      if ((iVar4 != 0) && (piVar6 = *(int **)(param_1 + 0x128), piVar6 != *(int **)(param_1 + 300)))

      {

        while ((*(int *)(param_2[0x2a] + 0x34) != *piVar6 ||

               (*(int *)(param_2[0x2a] + 0x34) >> 0x1f != piVar6[1]))) {

          piVar6 = piVar6 + 4;

          if (piVar6 == *(int **)(param_1 + 300)) {

            return;

          }

        }

        FUN_004d0250(param_1,*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4);

        return;

      }

    }

    break;

  default:

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return;

  }

  return;

}
