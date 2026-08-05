// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_00422a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00422a90
// Callee of Named_CalleeOf_Skill_IDSkillBattleMode1
// Address:   0x00422a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_IDSkillBattleMode1: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, goto×1, while×1, return×1.
//  - Notable callees: CONCAT22×2, CoTaskMemFree, FUN_00422a90, FUN_00422b80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_IDSkillBattleMode1
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_00422a90(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  short sVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int unaff_ESI;

  int iVar6;

  

  uVar5 = 0;

  if (*(int *)(unaff_ESI + 0xc) != 0) {

    iVar6 = 0;

    do {

      if ((*(int *)(unaff_ESI + 0x10) == 0) ||

         (*(char *)(*(int *)(unaff_ESI + 0x10) + uVar5) != '\x01')) {

        iVar3 = *(int *)(unaff_ESI + 0x14);

        sVar2 = *(short *)(iVar6 + 0x14 + iVar3);

        if ((sVar2 == 0xd) || (sVar2 == 9)) {

          if (*(int *)((*(int *)(*(int *)(unaff_ESI + 0x14) + 0x10 + iVar6) + 3 +

                        *(int *)(*(int *)(unaff_ESI + 0x14) + iVar6 + 4) & 0xfffffffcU) + 4 +

                      *(int *)(unaff_ESI + 8)) != 0) goto LAB_00422b6a;

          iVar3 = *(int *)(unaff_ESI + 0x14) + iVar6;

          uVar4 = CONCAT22((short)((uint)iVar3 >> 0x10),*(uint16_t *)(iVar3 + 0x14));

        }

        else {

          uVar4 = CONCAT22((short)((uint)iVar3 >> 0x10),*(uint16_t *)(iVar6 + iVar3 + 0x14));

        }

        FUN_00422b80(uVar4,param_1);

      }

      else if (((*(int *)((*(int *)(*(int *)(unaff_ESI + 0x14) + 0x10 + iVar6) + 3 +

                           *(int *)(*(int *)(unaff_ESI + 0x14) + iVar6 + 4) & 0xfffffffcU) + 4 +

                         *(int *)(unaff_ESI + 8)) != 3) &&

               (piVar1 = (int *)(*(int *)(iVar6 + 4 + *(int *)(unaff_ESI + 0x14)) +

                                *(int *)(unaff_ESI + 8)), piVar1 != (int *)0x0)) && (*piVar1 != 0))

      {

        CoTaskMemFree((LPVOID)*piVar1);

        *piVar1 = 0;

      }

LAB_00422b6a:

      uVar5 = uVar5 + 1;

      iVar6 = iVar6 + 0x30;

    } while (uVar5 < *(uint *)(unaff_ESI + 0xc));

  }

  return;

}
