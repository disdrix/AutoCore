// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×22, goto×7, return×3, for×2.
//  - Notable callees: FUN_00403430×4, CNDHash_LookupByKey×2, CVOGObject_EvalOfferableMissionInteractState×2, FUN_0040fb90×2, FUN_004d2e50×2, FUN_004d3ba0×2, CONCAT31, CVOGCharacter_HasCompletedMission.
//  - Return sites: 3.

// =============================================================================
// CVOGObject_EvalInteractStateFromChildren
// -----------------------------------------------------------------------------
// Stable ID: aa_004d7640
// Address:   0x004d7640  (autoassault.exe, image base 0x400000)
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
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* CVOGObject_EvalInteractStateFromChildren

   

   Aggregate interact state from child dialog/give-mission entries on an NPC object (type 0x12).

   Reaction-like child types:

     0x1e GiveMission: state 6 (new) or 7 (core) if not completed

     0x1f active objective: state 4

     0x25 deliver/use paths via helpers

   Picks highest priority state (complete=8 wins over lower). */



char CVOGObject_EvalInteractStateFromChildren

               (void *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  uint uVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *pvVar6;

  int iVar7;

  int unaff_EBP;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint8_t local_24 [4];

  void *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_18 [4];

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a219b;

  local_c = ExceptionList;

  if (*(int *)(*(int *)(param_2 + 0xa8) + 0x38) != 0x12) {

    return '\x01';

  }

  ExceptionList = &local_c;

  local_14 = FUN_0040fb90();

  local_10 = (uint32_t /* width from decompiler */ *)0x0;

  local_4 = 0;

  local_20 = (void *)FUN_0040fb90();

  local_1c = 0;

  local_4 = CONCAT31(local_4._1_3_,1);

  if (param_1 == (void *)0x0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1;

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(param_4 + 4) + 4) + 4 + param_4) + 0x130))

            (iVar7,1,local_18,local_24,0);

  if (unaff_EBP == 0) {

    FUN_00403430();

    FUN_00403430();

    ExceptionList = local_20;

    return '\0';

  }

  cVar4 = '\0';

  for (local_10 = (uint32_t /* width from decompiler */ *)*unaff_ESI; local_10 != unaff_ESI;

      local_10 = (uint32_t /* width from decompiler */ *)*local_10) {

    iVar7 = local_10[2];

    cVar3 = *(char *)(iVar7 + 0x1d1);

    if (cVar3 == '\x1e') {

      uVar1 = *(uint *)(iVar7 + 0x25c);

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_0053fff0();

      if ((void *)*puVar5 == (void *)0x0) {

        pvVar6 = (void *)0x0;

      }

      else {

        pvVar6 = CNDHash_LookupByKey((void *)*puVar5,uVar1);

      }

      bVar2 = false;

      if ((pvVar6 != (void *)0x0) && (*(short *)((int)pvVar6 + 0xac) == -1)) {

        bVar2 = true;

      }

      uVar1 = *(uint *)(iVar7 + 0x25c);

      for (iVar7 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0x540) + 0x10) +

                                    (*(uint *)(*(int *)((int)param_1 + 0x540) + 8) & uVar1) * 4) + 4

                           ); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0xc)) {

        if (uVar1 == *(uint *)(iVar7 + 0x10)) {

          if ((iVar7 != 0) && (*(int *)(iVar7 + 8) != 0)) goto LAB_004d7894;

          break;

        }

      }

      if ((!bVar2) && (bVar2 = CVOGCharacter_HasCompletedMission(param_1,uVar1), bVar2))

      goto LAB_004d7894;

      FUN_00547920(0);

      if (*(char *)((int)pvVar6 + 0x169) == '\0') {

        if ('\x05' < cVar4) goto LAB_004d7894;

        cVar4 = '\x06';

      }

      else {

        if ('\x06' < cVar4) goto LAB_004d7894;

        cVar4 = '\a';

      }

    }

    else {

      if (cVar3 != '%') {

        if (cVar3 == '\x1f') {

          pvVar6 = CNDHash_LookupByKey(*(void **)((int)param_1 + 0x548),*(uint *)(iVar7 + 0x25c));

          if ((pvVar6 == (void *)0x0) || ('\x03' < cVar4)) goto LAB_004d7894;

          cVar4 = '\x04';

        }

        else {

          if ('\x01' < cVar4) goto LAB_004d7894;

          cVar4 = '\x02';

        }

        goto LAB_004d7899;

      }

      cVar3 = FUN_004d3ba0(iVar7,param_1);

      if (cVar4 < cVar3) {

        cVar4 = FUN_004d3ba0(iVar7,param_1);

      }

      if (cVar4 < '\x06') {

        cVar3 = FUN_004d2e50(iVar7,param_1);

        if (cVar4 < cVar3) {

          cVar4 = FUN_004d2e50(iVar7,param_1);

        }

        pvVar6 = local_c;

        if ((cVar4 < '\x06') &&

           (cVar3 = CVOGObject_EvalOfferableMissionInteractState(local_c,param_1,&local_4),

           cVar4 < cVar3)) {

          cVar4 = CVOGObject_EvalOfferableMissionInteractState(pvVar6,param_1,&local_4);

        }

      }

LAB_004d7894:

      if (cVar4 == '\b') break;

    }

LAB_004d7899:

  }

  FUN_00403430();

  FUN_00403430();

  ExceptionList = local_20;

  return cVar4;

}
