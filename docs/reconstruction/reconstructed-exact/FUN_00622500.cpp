// =============================================================================
// FUN_00622500
// -----------------------------------------------------------------------------
// Stable ID: aa_00622500
// Address:   0x00622500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00622500 @ 0x00622500
// Stable ID: aa_00622500
// Embedded strings (evidence for future rename):
//   - "(Following Skill is OnKill)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, for×2, return×2.
//  - Notable callees: FUN_00552180, FUN_00578190, FUN_00622500.
//  - Strings: "(Following Skill is OnKill)\n".
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

void FUN_00622500(int param_1,char *param_2,int param_3)



{

  char cVar1;

  void *pSkillData;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t local_20c [4];

  char local_208 [2];

  uint32_t /* width from decompiler */ uStack_206;

  

  pSkillData = *(void **)(param_1 + 0x150);

  if (pSkillData != (void *)0x0) {

    local_208[0] = '\0';

    local_208[1] = '\0';

    puVar3 = &uStack_206;

    for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    *(uint16_t *)puVar3 = 0;

    puVar3 = CVOGReaction_ResolveSkillTargets

                       (pSkillData,

                        (uint)(ushort)(*(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)));

    local_20c = (uint8_t  [4])puVar3;

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      pcVar6 = (char *)(param_3 + -1);

      do {

        pcVar5 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = "(Following Skill is OnKill)\n";

      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

        *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar6 = pcVar6 + 4;

      }

      *pcVar6 = *pcVar5;

      iVar4 = -(int)param_2;

      do {

        cVar1 = *param_2;

        param_2[(int)(local_208 + iVar4)] = cVar1;

        param_2 = param_2 + 1;

      } while (cVar1 != '\0');

      puVar2 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

      do {

        puVar7 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      } while (*(char *)((int)puVar7 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar7 + 1) = DAT_009e1d68;

      *(uint8_t *)((int)puVar7 + 5) = DAT_009e1d6c;

      FUN_00552180(local_208,param_3);

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar3);

    }

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
