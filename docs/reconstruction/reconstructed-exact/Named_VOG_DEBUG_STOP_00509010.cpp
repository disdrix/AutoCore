// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×17, return×4, for×2, goto×1, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_004f1e20×2, Object_GetRootRaceId×2, CNDHash_LookupByKey, CONCAT22, CVOGReaction_GiveItemByCbid, CVOGReaction_RandomUnitScalar, FUN_00402d10.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_00509010
// -----------------------------------------------------------------------------
// Stable ID: aa_00509010
// Address:   0x00509010  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00509010(int *param_1,RACE_ID_INFERRED param_2)



{

  ushort uVar1;

  void *pvVar2;

  int iVar3;

  int *pObject;

  RACE_ID_INFERRED RVar4;

  int *piVar5;

  int iVar6;

  uint16_t in_FPUControlWord;

  float10 fVar7;

  uint key;

  int *piStack_c;

  int local_8;

  int iStack_4;

  

  iVar3 = param_1[0x2a];

  local_8 = 0;

  if (iVar3 == 0) {

    return 0;

  }

  piVar5 = *(int **)(iVar3 + 0x3c);

  if (piVar5 == (int *)0x0) {

    FUN_004f1e20(0,1);

    piVar5 = *(int **)(iVar3 + 0x3c);

    if (piVar5 == (int *)0x0) {

      return 0;

    }

  }

  iStack_4 = (**(code **)(*piVar5 + 0xc))();

  key = *(uint *)(param_1[0x29] + 0xfc);

  pvVar2 = (void *)FUN_00541a80();

  pvVar2 = CNDHash_LookupByKey(pvVar2,key);

  if ((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x14c) == 0)) {

    return 0;

  }

  if (*(int *)(param_1[0x2a] + 0x38) == 0xe) {

    iVar3 = (**(code **)(*param_1 + 0x1d4))();

  }

  else {

    if (*(int *)(param_1[0x2a] + 0x38) != 0x12) {

      if (pvVar2 != (void *)0x0) {

        fVar7 = (float10)FUN_0040f520(((float)*(int *)((int)pvVar2 + 0x13c) +

                                      (float)*(int *)((int)pvVar2 + 0x138)) * DAT_00a0f298);

        piStack_c = (int *)CONCAT22(piStack_c._2_2_,in_FPUControlWord);

        local_8 = (int)ROUND(fVar7);

      }

      goto LAB_0050910c;

    }

    iVar3 = (**(code **)(*param_1 + 0x1d8))();

  }

  local_8 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x27c))();

LAB_0050910c:

  iVar3 = *(int *)(DAT_00b041d4 + 0xf14);

  iVar6 = 0;

  if (*(char *)(iVar3 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar3 + 0x1d) = 1;

  while( true ) {

    iVar3 = *(int *)(DAT_00b041d4 + 0xf14);

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar6 == 0) {

      iVar6 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar6 = *(int *)(iVar6 + 0x14);

    }

    if (iVar6 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar6 + 8);

    }

    if (iVar3 == 0) break;

    if (*(int *)(iVar3 + 0x3c) == 0) {

      FUN_004f1e20(0,1);

    }

    piVar5 = *(int **)(iVar3 + 0x3c);

    if ((((piVar5 != (int *)0x0) && (piVar5[0x137] <= local_8)) && (local_8 <= piVar5[0x138])) &&

       ((iVar3 = (**(code **)(*piVar5 + 0xc))(), iVar3 == iStack_4 &&

        (iVar3 = (**(code **)(*piVar5 + 0xc))(), iVar3 != -1)))) {

      iVar3 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar3 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

      if (((float)uVar1 * DAT_00aaa638 <= (float)piVar5[0x139] * DAT_00aaa664) &&

         (pObject = (int *)CVOGReaction_GiveItemByCbid(piVar5[1]), piStack_c = pObject,

         pObject != (int *)0x0)) {

        (**(code **)(*pObject + 8))(piVar5[1],param_1[0x29],0);

        RVar4 = Object_GetRootRaceId(pObject);

        if ((RVar4 == param_2) ||

           (RVar4 = Object_GetRootRaceId(pObject), RVar4 == ~RACE_HUMAN_INFERRED)) {

          FUN_00402d10(&piStack_c);

        }

        else {

          (**(code **)*pObject)(1);

        }

      }

    }

  }

  *(uint8_t *)(*(int *)(DAT_00b041d4 + 0xf14) + 0x1d) = 0;

  return 1;

}
