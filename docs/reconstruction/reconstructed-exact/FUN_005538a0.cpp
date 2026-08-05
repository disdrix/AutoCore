// =============================================================================
// FUN_005538a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005538a0
// Address:   0x005538a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005538a0 @ 0x005538a0
// Stable ID: aa_005538a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, goto×1, for×1.
//  - Notable callees: ROUND×4, CONCAT22×2, CONCAT31, Client_EnqueueCombatFloater_INFERRED, FUN_004c2f20, FUN_00553240, FUN_005538a0, FUN_0058ab60.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall

FUN_005538a0(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  bool bVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  uint16_t *puVar5;

  int *piVar6;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  bool bVar7;

  uint32_t /* width from decompiler */ uVar8;

  int aiStack_38 [4];

  int iStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  uint8_t uStack_e;

  uint32_t /* width from decompiler */ uStack_8;

  

  if ((param_3 == 0) || (*(int *)(param_3 + 0xe4e8) == 0)) {

    return 0;

  }

  piVar3 = (int *)CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)param_4[1] >> 8),*(uint8_t *)(param_4 + 2)),

                             *param_4,param_4[1]);

  if (param_2 != (int *)0x0) {

    (**(code **)(*param_2 + 0x238))

              (4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc),

               (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),

               (int)*(short *)(param_1 + 0x14),piVar3,0,0,0);

    iVar4 = (**(code **)(*param_2 + 0x214))();

    if (iVar4 != 0) {

      uVar8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc);

      (**(code **)(*param_2 + 0x214))(uVar8);

      FUN_004c2f20(uVar8);

    }

  }

  bVar1 = false;

  bVar7 = false;

  if ((*(int *)(param_1 + 0x5f0) != 0) && (piVar3 != (int *)0x0)) {

    if ((*(byte *)(param_1 + 0x624) & 1) == 0) {

      iVar4 = (**(code **)(**(int **)(param_1 + 0x5f0) + 0x2c))

                        (param_2,param_1,param_3,param_4,param_5,param_6);

      bVar7 = iVar4 == 0;

      if (bVar7) goto LAB_00553ad2;

    }

    else {

      puVar5 = (uint16_t *)FUN_0058ab60(param_6);

      cVar2 = FUN_00553240(param_2,piVar3,CONCAT22(extraout_var_00,*puVar5),0);

      if (cVar2 == '\0') {

        piVar6 = aiStack_38;

        for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

          *piVar6 = 0;

          piVar6 = piVar6 + 1;

        }

        piVar6 = param_2 + 0x58;

        if (param_2 == (int *)0x0) {

          piVar6 = &DAT_009d1ca8;

        }

        aiStack_38[0] = *piVar6;

        aiStack_38[1] = piVar6[1];

        aiStack_38[2] = piVar6[2];

        aiStack_38[3] = piVar6[3];

        iStack_28 = piVar3[0x58];

        iStack_24 = piVar3[0x59];

        iStack_20 = piVar3[0x5a];

        iStack_1c = piVar3[0x5b];

        uStack_e = 1;

        uStack_8 = 0;

        Client_EnqueueCombatFloater_INFERRED(aiStack_38);

        bVar1 = true;

        operator_delete__(puVar5);

      }

      else {

        iVar4 = (**(code **)(**(int **)(param_1 + 0x5f0) + 0x2c))

                          (param_2,param_1,param_3,param_4,param_5,param_6);

        bVar7 = iVar4 == 0;

        operator_delete__(puVar5);

      }

    }

  }

  if ((param_2 != (int *)0x0) &&

     (((iVar4 = (**(code **)(*param_2 + 0x210))(0), iVar4 == 0 ||

       (iVar4 = (**(code **)(*param_2 + 0x210))(0), *(int *)(iVar4 + 0x6b4) < 1)) &&

      (iVar4 = (**(code **)(*param_2 + 0x214))(), iVar4 != 0)))) {

    piVar6 = (int *)(**(code **)(*param_2 + 0x214))();

    (**(code **)(*piVar6 + 0xb0))(CONCAT22(extraout_var,*(uint16_t *)(param_1 + 8)));

  }

LAB_00553ad2:

  if ((bVar7) || (bVar1)) {

    if (param_2 != (int *)0x0) {

      (**(code **)(*param_2 + 0x238))

                (0xc,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc),

                 (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),

                 (int)*(short *)(param_1 + 0x14),piVar3,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);

    }

    return 0;

  }

  if (piVar3 != (int *)0x0) {

    if (param_2 != (int *)0x0) {

      (**(code **)(*param_2 + 0x238))

                (0xe,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc),

                 (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),

                 (int)*(short *)(param_1 + 0x14),piVar3,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);

    }

    if ((*(int *)(piVar3[0x2a] + 0x38) == 0xe) &&

       (cVar2 = (**(code **)(*piVar3 + 0x238))

                          (6,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc),

                           (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),

                           (int)*(short *)(param_1 + 0x14),param_2,

                           (int)ROUND(*(float *)(param_1 + 0x28)),0,0), cVar2 != '\0')) {

      return 1;

    }

    (**(code **)(*piVar3 + 0x238))

              (5,*(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc),

               (int)(short)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)),

               (int)*(short *)(param_1 + 0x14),param_2,(int)ROUND(*(float *)(param_1 + 0x28)),0,0);

  }

  return 1;

}
