// =============================================================================
// FUN_006225f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006225f0
// Address:   0x006225f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006225f0 @ 0x006225f0
// Stable ID: aa_006225f0
// Embedded strings (evidence for future rename):
//   - "ls1."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CONCAT22, FUN_00552950, FUN_005781a0, FUN_006225f0, strncmp.
//  - Strings: "ls1.".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_006225f0(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint16_t extraout_var;

  

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    if (*param_2 == 'l') {

      iVar1 = strncmp(param_2,"ls1.",4);

      if (iVar1 == 0) {

        puVar2 = CVOGReaction_ResolveSkillTargets

                           (*(void **)(param_1 + 0x150),

                            CONCAT22(extraout_var,

                                     *(short *)(param_1 + 0x5f6) + *(short *)(param_1 + 0x174)));

        if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00552950(param_2 + 4,param_3);

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar2);

        }

      }

    }

    uVar3 = FUN_005781a0(param_1,param_2,param_3);

    return uVar3;

  }

  return 0;

}
