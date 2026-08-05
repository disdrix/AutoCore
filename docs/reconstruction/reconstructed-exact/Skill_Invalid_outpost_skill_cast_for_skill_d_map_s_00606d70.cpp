// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2, while×1.
//  - Notable callees: CONCAT22, CVOGReaction_ResolveObjectTarget, FUN_00606d70, FUN_007a4480, Skill_ValidateTargetForSkill.
//  - Strings: "Invalid outpost skill cast for skill %d, map: %s".
//  - Return sites: 2.

// =============================================================================
// Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_00606d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00606d70
// Address:   0x00606d70  (autoassault.exe, image base 0x400000)
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

void __thiscall Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_00606d70(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *this;

  void *pSkill;

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int local_650;

  uint local_648;

  uint32_t /* width from decompiler */ local_640 [400];

  

  if ((((-1 < param_2) && (param_2 < 4)) && (*(int *)(param_1 + 0x228) != 0)) &&

     (*(int *)(param_1 + 0x22c) - *(int *)(param_1 + 0x228) >> 3 != 0)) {

    iVar4 = param_1 + param_2 * 0x48;

    local_648 = 0;

    local_650 = 0;

    while ((iVar5 = *(int *)(iVar4 + 0xd4), iVar5 != 0 &&

           (local_648 < (uint)(*(int *)(iVar4 + 0xd8) - iVar5 >> 4)))) {

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar5 + local_650);

      if (*(char *)(puVar3 + 3) == '\0') {

        local_648 = local_648 + 1;

        local_650 = local_650 + 0x10;

      }

      else {

        this = CVOGReaction_ResolveSkillTargets

                         ((void *)*puVar3,

                          CONCAT22((short)((uint)iVar5 >> 0x10),(ushort)*(byte *)(puVar3 + 1)));

        if (this != (uint32_t /* width from decompiler */ *)0x0) {

          iVar4 = 0;

          for (uVar2 = 0;

              (iVar5 = *(int *)(param_1 + 0x228), iVar5 != 0 &&

              (uVar2 < (uint)(*(int *)(param_1 + 0x22c) - iVar5 >> 3))); uVar2 = uVar2 + 1) {

            puVar3 = (uint32_t /* width from decompiler */ *)(iVar5 + uVar2 * 8);

            pSkill = (void *)CVOGReaction_ResolveObjectTarget(1,*puVar3,puVar3[1]);

            iVar5 = iVar4;

            if ((pSkill != (void *)0x0) &&

               (iVar1 = Skill_ValidateTargetForSkill(this,pSkill,(void *)0x0), (char)iVar1 != '\0'))

            {

              local_640[iVar4 * 4] = *(uint32_t /* width from decompiler */ *)((int)pSkill + 0x160);

              local_640[iVar4 * 4 + 1] = *(uint32_t /* width from decompiler */ *)((int)pSkill + 0x164);

              local_640[iVar4 * 4 + 2] = *(uint32_t /* width from decompiler */ *)((int)pSkill + 0x168);

              iVar5 = iVar4 + 1;

              local_640[iVar4 * 4 + 3] = *(uint32_t /* width from decompiler */ *)((int)pSkill + 0x16c);

              if (0x62 < iVar5) {

                local_640[iVar5 * 4] = DAT_009de7d8;

                local_640[iVar5 * 4 + 1] = DAT_009de7dc;

                local_640[iVar5 * 4 + 2] = DAT_009de7e0;

                local_640[iVar5 * 4 + 3] = DAT_009de7e4;

                CVOGReaction_CastSkillOnTarget

                          (this,*(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4,0,0,local_640,

                           &DAT_00d029d0,0,0xffffffff,0,0);

                iVar5 = 0;

              }

            }

            iVar4 = iVar5;

          }

          if (0 < iVar4) {

            local_640[iVar4 * 4] = DAT_009de7d8;

            local_640[iVar4 * 4 + 1] = DAT_009de7dc;

            local_640[iVar4 * 4 + 2] = DAT_009de7e0;

            local_640[iVar4 * 4 + 3] = DAT_009de7e4;

            if (param_1 == 0) {

              param_1 = 0;

            }

            else {

              param_1 = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;

            }

            CVOGReaction_CastSkillOnTarget

                      (this,param_1,0,0,local_640,&DAT_00d029d0,0,0xffffffff,0,0);

          }

                    /* WARNING: Subroutine does not return */

          operator_delete(this);

        }

        FUN_007a4480(1,"Invalid outpost skill cast for skill %d, map: %s",*puVar3,

                     *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xb4);

        local_648 = local_648 + 1;

        local_650 = local_650 + 0x10;

      }

    }

  }

  return;

}
