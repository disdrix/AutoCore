// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×8, while×2, for×2, return×2.
//  - Notable callees: FUN_004022a0×2, CONCAT22, CVOGReaction_ResolveObjectTarget, FUN_004294f0, FUN_006070e0, FUN_007a4480, LeaveCriticalSection, Skill_ValidateTargetForSkill.
//  - Strings: "Invalid outpost skill cast for skill %d, map: %s".
//  - Return sites: 2.

// =============================================================================
// Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_006070e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006070e0
// Address:   0x006070e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Invalid outpost skill cast for skill %d, map: %s"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_006070e0(int param_1,int param_2)



{

  int *pSkill;

  uint32_t /* width from decompiler */ *this;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int local_65c;

  uint local_658;

  uint local_654;

  int *local_650;

  uint32_t /* width from decompiler */ uStack_64c;

  int local_648;

  int iStack_644;

  int aiStack_640 [400];

  

  if ((-1 < param_2) && (param_2 < 4)) {

    iVar2 = param_1 + param_2 * 0x48;

    local_658 = 0;

    local_65c = 0;

    local_648 = iVar2;

    while ((iVar4 = *(int *)(iVar2 + 0xd4), iVar4 != 0 &&

           (local_658 < (uint)(*(int *)(iVar2 + 0xd8) - iVar4 >> 4)))) {

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar4 + local_65c);

      if ((*(char *)(puVar3 + 3) != '\0') ||

         (*(float *)(param_1 + 0x24c) <= (float)puVar3[2] &&

          (float)puVar3[2] != *(float *)(param_1 + 0x24c))) {

        local_658 = local_658 + 1;

        local_65c = local_65c + 0x10;

      }

      else {

        this = CVOGReaction_ResolveSkillTargets

                         ((void *)*puVar3,

                          CONCAT22((short)((uint)iVar4 >> 0x10),(short)*(char *)(puVar3 + 1)));

        if (this != (uint32_t /* width from decompiler */ *)0x0) {

          iVar4 = 0;

          for (local_654 = 0;

              (iVar1 = *(int *)(iVar2 + 0xb4), iVar1 != 0 &&

              (local_654 < (uint)(*(int *)(iVar2 + 0xb8) - iVar1 >> 3))); local_654 = local_654 + 1)

          {

            puVar3 = (uint32_t /* width from decompiler */ *)(iVar1 + local_654 * 8);

            local_650 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar3,puVar3[1]);

            if ((local_650 != (int *)0x0) &&

               (iVar1 = (**(code **)(*local_650 + 0x1ec))(), iVar1 != 0)) {

              uStack_64c = 0;

              iStack_644 = iVar1 + 0xb4;

              FUN_004294f0();

              iVar2 = FUN_004022a0(&uStack_64c,&local_650);

              iVar1 = iVar1 + 0xb4;

              pSkill = local_650;

              while (local_650 = pSkill, iVar2 == 0) {

                iVar2 = (**(code **)(*pSkill + 0x1d8))();

                iVar5 = iVar4;

                if (((iVar2 == 0) ||

                    (iVar2 = (**(code **)(*pSkill + 0x1d8))(), *(int *)(iVar2 + 0x250) == 0)) &&

                   (iVar2 = Skill_ValidateTargetForSkill(this,pSkill,(void *)0x0),

                   (char)iVar2 != '\0')) {

                  aiStack_640[iVar4 * 4] = pSkill[0x58];

                  aiStack_640[iVar4 * 4 + 1] = pSkill[0x59];

                  aiStack_640[iVar4 * 4 + 2] = pSkill[0x5a];

                  iVar5 = iVar4 + 1;

                  aiStack_640[iVar4 * 4 + 3] = pSkill[0x5b];

                  if (0x62 < iVar5) {

                    aiStack_640[iVar5 * 4] = DAT_009de7d8;

                    aiStack_640[iVar5 * 4 + 1] = DAT_009de7dc;

                    aiStack_640[iVar5 * 4 + 2] = DAT_009de7e0;

                    aiStack_640[iVar5 * 4 + 3] = DAT_009de7e4;

                    CVOGReaction_CastSkillOnTarget

                              (this,*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4,0,0,

                               aiStack_640,&DAT_00d029d0,0,0xffffffff,0,0);

                    iVar5 = 0;

                  }

                }

                iVar2 = FUN_004022a0(&uStack_64c,&local_650);

                iVar1 = iStack_644;

                iVar4 = iVar5;

                pSkill = local_650;

              }

              iVar2 = local_648;

              if (*(char *)(iVar1 + 0x28) != '\0') {

                *(uint8_t *)(iVar1 + 0x28) = 0;

                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));

                iVar2 = local_648;

              }

            }

          }

          if (0 < iVar4) {

            aiStack_640[iVar4 * 4] = DAT_009de7d8;

            aiStack_640[iVar4 * 4 + 1] = DAT_009de7dc;

            aiStack_640[iVar4 * 4 + 2] = DAT_009de7e0;

            aiStack_640[iVar4 * 4 + 3] = DAT_009de7e4;

            CVOGReaction_CastSkillOnTarget

                      (this,*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4,0,0,aiStack_640,

                       &DAT_00d029d0,0,0xffffffff,0,0);

          }

                    /* WARNING: Subroutine does not return */

          operator_delete(this);

        }

        FUN_007a4480(1,"Invalid outpost skill cast for skill %d, map: %s",*puVar3,

                     *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xb4);

        local_658 = local_658 + 1;

        local_65c = local_65c + 0x10;

      }

    }

  }

  return;

}
