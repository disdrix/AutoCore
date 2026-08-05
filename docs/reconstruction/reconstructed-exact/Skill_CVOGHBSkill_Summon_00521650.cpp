// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: CVOGReaction_CastSkillOnTarget, FUN_005172d0, FUN_00521650, Skill_EnsureLoadedInTree, Skill_LookupActiveCastBinding, __RTtypeid, strstr, type_info::name.
//  - Strings: "CVOGHBSkill_Summon".
//  - Return sites: 3.

// =============================================================================
// Skill_CVOGHBSkill_Summon_00521650
// -----------------------------------------------------------------------------
// Stable ID: aa_00521650
// Address:   0x00521650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "CVOGHBSkill_Summon"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Skill_CVOGHBSkill_Summon_00521650(int param_1)



{

  uint *extraout_EAX;

  int iVar1;

  int iVar2;

  type_info *this;

  char *pcVar3;

  char *_SubStr;

  uint8_t local_10 [16];

  

  iVar2 = *(int *)(param_1 + 0x250);

  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x270) != 0)) &&

     (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 0x270) + 4) + 4) + 0xac

                                        + *(int *)(iVar2 + 0x270)) + 0x3c) + 0x3bc), iVar2 != -1)) {

    Skill_LookupActiveCastBinding(local_10,iVar2);

    if (((*extraout_EAX & extraout_EAX[1]) == 0xffffffff) && ((char)extraout_EAX[2] == '\0')) {

      if ((float)*(int *)(param_1 + 0x608) + *(float *)(param_1 + 0x600) < (float)_DAT_00af22b0) {

        return 0;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x600) = 0;

    }

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x234))

                      (iVar2);

    if (iVar1 == 0) {

      Skill_EnsureLoadedInTree((void *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1),iVar2,1);

    }

    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x234))

                      (iVar2);

    iVar1 = Skill_LocalCastValidate

                      ((void *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1),(void *)0x0,

                       (char)iVar2,(void *)0x0);

    if (iVar1 == 0) {

      iVar1 = *(int *)(param_1 + 0x250);

      if ((*(char *)(iVar1 + 0x108) != '\0') &&

         (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xb0 + iVar1) != 0)) {

        FUN_005172d0(0);

        *(uint8_t *)(*(int *)(param_1 + 0x250) + 0x108) = 0;

      }

      if (*(int *)(iVar2 + 0x5f0) != 0) {

        this = (type_info *)__RTtypeid(*(int *)(iVar2 + 0x5f0));

        _SubStr = "CVOGHBSkill_Summon";

        pcVar3 = type_info::name(this);

        pcVar3 = strstr(pcVar3,_SubStr);

        if (pcVar3 != (char *)0x0) {

          *(uint8_t *)(param_1 + 0x6bb) = 1;

        }

      }

      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1 + 4;

      CVOGReaction_CastSkillOnTarget(iVar2,iVar1,iVar1,1,0,&DAT_00b045a0,0,0xffffffff,0,0);

      *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 1;

      return 1;

    }

  }

  return 0;

}
