// =============================================================================
// FUN_00624ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00624ab0
// Address:   0x00624ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00624ab0 @ 0x00624ab0
// Stable ID: aa_00624ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×13, return×5.
//  - Notable callees: CONCAT22×4, CVOGReaction_CastSkillOnTarget×4, FUN_00512150×2, FUN_00578270, FUN_00624ab0.
//  - Return sites: 5.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

FUN_00624ab0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  short sVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  float fVar5;

  

  if ((((param_1[6] != 0) && (*(char *)(*(int *)(param_1[6] + 0xa4) + 0x7e) != '\0')) &&

      ((char)param_1[8] == '\0')) &&

     ((*(char *)((int)param_1 + 0x6d2) != '\0' &&

      (fVar5 = (float)*(byte *)(param_1[0x1a8] + param_1[0x1b5] * 2) * _DAT_009e3088,

      (float)param_1[0x42] <= fVar5 && fVar5 != (float)param_1[0x42])))) {

    uVar2 = param_1[0x1b5] + 1;

    param_1[0x1b5] = uVar2;

    if (599 < uVar2) {

      param_1[0x1b5] = 0;

    }

    uVar3 = FUN_00578270();

    if ((void *)param_1[0x5d] != (void *)0x0) {

      puVar4 = CVOGReaction_ResolveSkillTargets

                         ((void *)param_1[0x5d],

                          CONCAT22(extraout_var,

                                   *(short *)((int)param_1 + 0x61a) + (short)param_1[0x66]));

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        CVOGReaction_CastSkillOnTarget(puVar4,uVar3,uVar3,0,0,&DAT_00d02b70,0,0xffffffff,0,0);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

    if ((void *)param_1[0x5e] != (void *)0x0) {

      puVar4 = CVOGReaction_ResolveSkillTargets

                         ((void *)param_1[0x5e],

                          CONCAT22(extraout_var_00,

                                   *(short *)((int)param_1 + 0x61a) + (short)param_1[0x66]));

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        CVOGReaction_CastSkillOnTarget(puVar4,uVar3,uVar3,0,0,&DAT_00d02b70,0,0xffffffff,0,0);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

    if ((void *)param_1[0x5f] != (void *)0x0) {

      puVar4 = CVOGReaction_ResolveSkillTargets

                         ((void *)param_1[0x5f],

                          CONCAT22(extraout_var,

                                   *(short *)((int)param_1 + 0x61a) + (short)param_1[0x66]));

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        CVOGReaction_CastSkillOnTarget(puVar4,uVar3,param_2,0,0,&DAT_00d02b70,0,0xffffffff,0,0);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

    if ((void *)param_1[0x60] != (void *)0x0) {

      puVar4 = CVOGReaction_ResolveSkillTargets

                         ((void *)param_1[0x60],

                          CONCAT22(extraout_var_00,

                                   *(short *)((int)param_1 + 0x61a) + (short)param_1[0x66]));

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        CVOGReaction_CastSkillOnTarget(puVar4,uVar3,param_2,0,0,&DAT_00d02b70,0,0xffffffff,0,0);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar4);

    }

    if ((float)param_1[0x61] != g_flZero) {

      *(uint8_t *)((int)param_1 + 0x6d2) = 0;

    }

    if (((short)param_1[0x1b4] != 0) &&

       (sVar1 = (short)param_1[0x1b4] + -1, *(short *)(param_1 + 0x1b4) = sVar1, sVar1 == 0)) {

      FUN_00512150(6,0,param_1[0x188],1);

      (**(code **)(*param_1 + 0x18))(1,1);

    }

    if ((char)param_1[8] == '\0') {

      FUN_00512150(5,(float)*(ushort *)(param_1 + 0x1b4),param_1[0x188],1);

    }

  }

  return param_4;

}
