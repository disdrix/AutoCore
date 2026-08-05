// =============================================================================
// FUN_00957180
// -----------------------------------------------------------------------------
// Stable ID: aa_00957180
// Address:   0x00957180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00957180 @ 0x00957180
// Stable ID: aa_00957180
// Embedded strings (evidence for future rename):
//   - "Skill %d: (%s)\n\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×2.
//  - Notable callees: CVOGReaction_ResolveSkillTargets, FUN_00552180, FUN_007fe5b0, FUN_00800c30, FUN_00957180, atoi, d:, sprintf.
//  - Strings: "Skill %d: (%s)\n\n".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_00957180(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *_Str;

  void *pSkillData;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint16_t local_a08;

  uint32_t /* width from decompiler */ local_a06 [127];

  char local_808 [2];

  uint32_t /* width from decompiler */ local_806 [512];

  

  _Str = strtok((char *)0x0,param_3);

  if (_Str != (char *)0x0) {

    pSkillData = (void *)atoi(_Str);

    if (-1 < (int)pSkillData) {

      puVar1 = CVOGReaction_ResolveSkillTargets(pSkillData,1);

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        FUN_007fe5b0(param_1,pSkillData,(int)pSkillData >> 0x1f);

        local_a08 = 0;

        puVar3 = local_a06;

        for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar3 = 0;

          puVar3 = puVar3 + 1;

        }

        *(uint16_t *)puVar3 = 0;

        local_808[0] = '\0';

        local_808[1] = '\0';

        puVar3 = local_806;

        for (iVar2 = 0x1ff; iVar2 != 0; iVar2 = iVar2 + -1) {

          *puVar3 = 0;

          puVar3 = puVar3 + 1;

        }

        *(uint16_t *)puVar3 = 0;

        sprintf(local_808,"Skill %d: (%s)\n\n",pSkillData,puVar1 + 0x61);

        FUN_00552180(&local_a08,local_808);

        FUN_00800c30(param_1,pSkillData,(int)pSkillData >> 0x1f,local_808,&DAT_00afdf0c);

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar1);

      }

    }

  }

  return 1;

}
