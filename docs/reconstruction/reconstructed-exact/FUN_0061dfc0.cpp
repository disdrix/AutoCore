// =============================================================================
// FUN_0061dfc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061dfc0
// Address:   0x0061dfc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061dfc0 @ 0x0061dfc0
// Stable ID: aa_0061dfc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, do×1, goto×1, while×1.
//  - Notable callees: __RTDynamicCast×4, CONCAT22, CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00589b80, FUN_0058ab60, FUN_00618180.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */

FUN_0061dfc0(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  void *pvVar5;

  CVOGHBBase *pAction;

  int iVar6;

  int iVar7;

  int *piVar8;

  char local_15;

  int local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a881b;

  local_c = ExceptionList;

  local_14 = 0;

  ExceptionList = &local_c;

  pvVar2 = (void *)FUN_0058ab60(param_6);

  local_15 = '\0';

  iVar6 = 0;

  do {

    piVar8 = (int *)(param_4 + local_15 * 0x10);

    if (((*piVar8 == -1) && (piVar8[1] == -1)) && ((char)piVar8[2] == '\0')) {

      if (pvVar2 != (void *)0x0) {

        operator_delete__(pvVar2);

      }

      if (local_14 == 0) {

        ExceptionList = local_c;

        return 0;

      }

      pvVar5 = operator_new(0x6d0);

      local_4 = 0;

      if (pvVar5 == (void *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        pAction = (CVOGHBBase *)

                  FUN_00618180(param_1,param_2,param_3,param_1,param_5,param_6,0,(float)local_14);

      }

      local_4 = 0xffffffff;

      if (pAction->pOwnerObject == (void *)0x0) {

        (**(code **)pAction->pVTable)(1);

        ExceptionList = pvVar2;

        return 1;

      }

      CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

      ExceptionList = local_c;

      return 1;

    }

    cVar1 = FUN_00589b80(*(uint32_t /* width from decompiler */ *)(param_2 + 0xe4),

                         CONCAT22(local_15 >> 7,*(uint16_t *)((int)pvVar2 + local_15 * 2)));

    iVar7 = iVar6;

    if (cVar1 == '\0') {

      local_14 = local_14 + 1;

      iVar3 = CVOGReaction_ResolveObjectTarget

                        (CONCAT31((int3)((uint)piVar8[1] >> 8),(char)piVar8[2]),*piVar8,piVar8[1]);

      if (iVar3 != 0) {

        iVar4 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGCreature::RTTI_Type_Descriptor,0);

        if (iVar4 == 0) {

          iVar4 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                  &CVOGVehicle::RTTI_Type_Descriptor,0);

          if (iVar4 != 0) {

            iVar3 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGVehicle::RTTI_Type_Descriptor,0);

            iVar4 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)

                                     (*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb0 + iVar3),0,

                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGCreature::RTTI_Type_Descriptor,0);

            if (iVar4 != 0) goto LAB_0061e0e5;

          }

        }

        else {

LAB_0061e0e5:

          iVar7 = iVar4;

          if (iVar6 != 0) {

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x238))

                      (2,*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                       (int)(short)(*(short *)(param_2 + 0x5f6) + *(short *)(param_2 + 0x174)),0,

                       *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6,0,0,0);

          }

        }

      }

    }

    local_15 = local_15 + '\x01';

    iVar6 = iVar7;

  } while( true );

}
