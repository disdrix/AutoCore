// =============================================================================
// FUN_0061c090
// -----------------------------------------------------------------------------
// Stable ID: aa_0061c090
// Address:   0x0061c090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061c090 @ 0x0061c090
// Stable ID: aa_0061c090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×13, goto×3, while×2, do×1, return×1.
//  - Notable callees: __RTDynamicCast×4, CONCAT31, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00589b80, FUN_0058ab60, FUN_0058c850, FUN_00618180.
//  - Return sites: 1.

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

uint8_t

FUN_0061c090(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  char cVar2;

  bool bVar3;

  uint8_t uVar4;

  int iVar5;

  char cVar6;

  void *pvVar7;

  int iVar8;

  int iVar9;

  void *pvVar10;

  CVOGHBBase *pAction;

  int local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a875b;

  pvStack_c = ExceptionList;

  bVar3 = true;

  local_1c = 0;

  uVar4 = 0;

  ExceptionList = &pvStack_c;

  pvVar7 = (void *)FUN_0058ab60(param_6);

  if (((*(uint *)(param_2 + 0x624) & 1) != 0) &&

     ((*(uint *)(param_2 + 0x18) == 0 || (*(uint *)(param_2 + 0x18) < 2)))) {

    local_1c = 1;

    if (((*(uint *)(param_2 + 0x624) & 1) != 0) &&

       (iVar8 = FUN_0058c850(param_1,param_4,param_2,param_3,pvVar7,0), iVar8 != 0)) {

      uVar4 = 1;

    }

    if (*(int *)(param_2 + 0x624) == 1) {

      bVar3 = false;

    }

  }

  local_20 = 0;

  cVar2 = '\0';

  do {

    while( true ) {

      iVar8 = cVar2 * 0x10;

      puVar1 = (uint32_t /* width from decompiler */ *)(iVar8 + param_4);

      if (((*(int *)(iVar8 + param_4) == -1) && (puVar1[1] == -1)) &&

         (*(char *)(puVar1 + 2) == '\0')) {

        if (pvVar7 != (void *)0x0) {

          operator_delete__(pvVar7);

        }

        ExceptionList = pvStack_c;

        return uVar4;

      }

      cVar6 = FUN_00589b80(*(uint32_t /* width from decompiler */ *)(param_2 + 0xe4),*(uint16_t *)((int)pvVar7 + cVar2 * 2))

      ;

      if ((cVar6 == '\0') &&

         (iVar8 = CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)puVar1[1] >> 8),*(uint8_t *)(puVar1 + 2)),

                             *puVar1,puVar1[1]), iVar8 != 0)) break;

LAB_0061c2e2:

      cVar2 = cVar2 + '\x01';

    }

    iVar9 = __RTDynamicCast(iVar8,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGCreature::RTTI_Type_Descriptor,0);

    if (iVar9 == 0) {

      iVar9 = __RTDynamicCast(iVar8,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                              &CVOGVehicle::RTTI_Type_Descriptor,0);

      iVar5 = local_20;

      if (iVar9 != 0) {

        iVar9 = __RTDynamicCast(iVar8,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGVehicle::RTTI_Type_Descriptor,0);

        iVar9 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 0xb0 + iVar9),0,

                                &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGCreature::RTTI_Type_Descriptor,0);

        if (iVar9 != 0) goto LAB_0061c20d;

      }

    }

    else {

LAB_0061c20d:

      iVar5 = iVar9;

      if (local_20 != 0) {

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 4) + 4 + iVar9) + 0x238))

                  (2,*(uint32_t /* width from decompiler */ *)(param_2 + 0x5fc),

                   (int)(short)(*(short *)(param_2 + 0x5f6) + *(short *)(param_2 + 0x174)),0,

                   *(int *)(*(int *)(local_20 + 4) + 4) + 4 + local_20,0,0,0);

      }

    }

    local_20 = iVar5;

    if (!bVar3) goto LAB_0061c2e2;

    pvVar10 = operator_new(0x6d0);

    pAction = (CVOGHBBase *)0x0;

    uStack_4 = 0;

    if (pvVar10 != (void *)0x0) {

      pAction = (CVOGHBBase *)

                FUN_00618180(param_1,param_2,param_3,iVar8,param_5,param_6,local_1c,0x3f800000);

    }

    uStack_4 = 0xffffffff;

    if (pAction->pOwnerObject == (void *)0x0) {

      (**(code **)pAction->pVTable)(1);

      goto LAB_0061c2e2;

    }

    CVOGHBList_Enqueue(*(void **)(param_3 + 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

    cVar2 = cVar2 + '\x01';

    uVar4 = 1;

  } while( true );

}
