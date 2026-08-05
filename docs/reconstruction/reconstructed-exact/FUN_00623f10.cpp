// =============================================================================
// FUN_00623f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00623f10
// Address:   0x00623f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00623f10 @ 0x00623f10
// Stable ID: aa_00623f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, goto×2, do×1, while×1.
//  - Notable callees: CONCAT22×4, CVOGReaction_CastSkillOnTarget×4, CONCAT31, CONCAT44, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00618180, FUN_00623f10.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __fastcall

FUN_00623f10(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4,int param_5,int param_6,

            uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  char cVar1;

  int iVar2;

  bool bVar3;

  int *piVar4;

  CVOGHBBase *pAction;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint32_t /* width from decompiler */ extraout_EDX;

  uint32_t /* width from decompiler */ extraout_EDX_00;

  uint32_t /* width from decompiler */ extraout_EDX_01;

  uint64_t uVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8a6b;

  pvStack_c = ExceptionList;

  cVar1 = '\0';

  bVar3 = false;

  ExceptionList = &pvStack_c;

LAB_00623f40:

  do {

    piVar4 = (int *)(cVar1 * 0x10 + param_6);

    if (((*piVar4 == -1) && (piVar4[1] == -1)) && ((char)piVar4[2] == '\0')) {

      if (!bVar3) {

        ExceptionList = pvStack_c;

        return 0;

      }

      if (*(void **)(param_4 + 0x150) != (void *)0x0) {

        puVar5 = CVOGReaction_ResolveSkillTargets

                           (*(void **)(param_4 + 0x150),

                            CONCAT22((short)((uint)param_6 >> 0x10),

                                     *(short *)(param_4 + 0x5f6) + *(short *)(param_4 + 0x174)));

        CVOGReaction_CastSkillOnTarget(puVar5,param_3,param_3,0,0,&DAT_00d02b60,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar5);

      }

      if (*(void **)(param_4 + 0x154) != (void *)0x0) {

        puVar5 = CVOGReaction_ResolveSkillTargets

                           (*(void **)(param_4 + 0x154),

                            CONCAT22((short)((uint)param_2 >> 0x10),

                                     *(short *)(param_4 + 0x5f6) + *(short *)(param_4 + 0x174)));

        CVOGReaction_CastSkillOnTarget(puVar5,param_3,param_3,0,0,&DAT_00d02b60,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar5);

      }

      ExceptionList = pvStack_c;

      return 1;

    }

    uVar7 = CVOGReaction_ResolveObjectTarget

                      (CONCAT31((int3)((uint)piVar4 >> 8),(char)piVar4[2]),*piVar4,piVar4[1]);

    param_2 = (uint32_t /* width from decompiler */)((ulonglong)uVar7 >> 0x20);

    piVar4 = (int *)uVar7;

    if (piVar4 != (int *)0x0) {

      pAction = operator_new(0x6d0);

      local_4 = 0;

      if (pAction == (CVOGHBBase *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        FUN_00618180(param_3,param_4,param_5,piVar4,param_7,param_8,0,0x3f800000);

        pAction->pVTable = &PTR_FUN_009d1914;

      }

      local_4 = 0xffffffff;

      if (pAction->pOwnerObject == (void *)0x0) {

        (**(code **)pAction->pVTable)(1);

        param_2 = extraout_EDX_01;

      }

      else {

        CVOGHBList_Enqueue(*(void **)(param_5 + 0xe4ec),pAction);

        CVOGHBBase_Start(pAction);

        bVar3 = true;

        if (*(void **)(param_4 + 0x158) != (void *)0x0) {

          puVar5 = CVOGReaction_ResolveSkillTargets

                             (*(void **)(param_4 + 0x158),

                              CONCAT22(extraout_var_00,

                                       *(short *)(param_4 + 0x5f6) + *(short *)(param_4 + 0x174)));

          CVOGReaction_CastSkillOnTarget(puVar5,param_3,piVar4,0,0,&DAT_00d02b60,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar5);

        }

        if (*(void **)(param_4 + 0x15c) != (void *)0x0) {

          puVar5 = CVOGReaction_ResolveSkillTargets

                             (*(void **)(param_4 + 0x15c),

                              CONCAT22(extraout_var,

                                       *(short *)(param_4 + 0x5f6) + *(short *)(param_4 + 0x174)));

          CVOGReaction_CastSkillOnTarget(puVar5,param_3,piVar4,0,0,&DAT_00d02b60,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar5);

        }

        if (param_3 != (int *)0x0) {

          uVar7 = (**(code **)(*param_3 + 0x19c))();

          iVar6 = (int)uVar7;

          if (iVar6 != 0) {

            iVar2 = *(int *)(*(int *)(iVar6 + 4) + 4);

            uVar7 = CONCAT44(iVar2,iVar2 + 4 + iVar6);

          }

          param_2 = (uint32_t /* width from decompiler */)((ulonglong)uVar7 >> 0x20);

          if ((int *)uVar7 == piVar4) goto LAB_0062412b;

        }

        (**(code **)(*piVar4 + 0x238))

                  (0x14,*(uint32_t /* width from decompiler */ *)(param_4 + 0x5fc),

                   (int)(short)(*(short *)(param_4 + 0x174) + *(short *)(param_4 + 0x5f6)),

                   (int)*(short *)(param_4 + 0x14),param_3,0,0,0);

        param_2 = extraout_EDX;

        if (param_3 != (int *)0x0) {

          (**(code **)(*param_3 + 0x238))

                    (0x15,*(uint32_t /* width from decompiler */ *)(param_4 + 0x5fc),

                     (int)(short)(*(short *)(param_4 + 0x174) + *(short *)(param_4 + 0x5f6)),

                     (int)*(short *)(param_4 + 0x14),piVar4,0,0,0);

          cVar1 = cVar1 + '\x01';

          bVar3 = true;

          param_2 = extraout_EDX_00;

          goto LAB_00623f40;

        }

      }

    }

LAB_0062412b:

    cVar1 = cVar1 + '\x01';

  } while( true );

}
