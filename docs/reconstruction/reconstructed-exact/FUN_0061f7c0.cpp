// =============================================================================
// FUN_0061f7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061f7c0
// Address:   0x0061f7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061f7c0 @ 0x0061f7c0
// Stable ID: aa_0061f7c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: CONCAT22×2, CVOGReaction_CastSkillOnTarget×2, FUN_005134e0, FUN_00578270, FUN_0061f7c0.
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

void __fastcall FUN_0061f7c0(int *param_1)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar5;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  piVar2 = (int *)FUN_00578270();

  if (piVar2 != (int *)0x0) {

    iVar3 = (**(code **)(*piVar2 + 0x19c))();

    if (iVar3 != 0) {

      (**(code **)(*piVar2 + 0x19c))();

      cVar1 = FUN_005134e0();

      if (cVar1 != '\0') {

        return;

      }

    }

    (**(code **)(*param_1 + 0x50))();

    if (param_1[6] != 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)param_1[6] + 0x1a0))();

      uStack_20 = *puVar4;

      uStack_1c = puVar4[1];

      uStack_18 = puVar4[2];

      uStack_14 = puVar4[3];

      uVar5 = extraout_var;

      if (((void *)param_1[0x5d] != (void *)0x0) &&

         (puVar4 = CVOGReaction_ResolveSkillTargets

                             ((void *)param_1[0x5d],

                              CONCAT22(extraout_var,

                                       *(short *)((int)param_1 + 0x61a) + (short)param_1[0x66])),

         uVar5 = extraout_var_00, puVar4 != (uint32_t /* width from decompiler */ *)0x0)) {

        CVOGReaction_CastSkillOnTarget(puVar4,piVar2,0,0,0,&uStack_20,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar4);

      }

      if (((void *)param_1[0x5e] != (void *)0x0) &&

         (puVar4 = CVOGReaction_ResolveSkillTargets

                             ((void *)param_1[0x5e],

                              CONCAT22(uVar5,*(short *)((int)param_1 + 0x61a) + (short)param_1[0x66]

                                      )), puVar4 != (uint32_t /* width from decompiler */ *)0x0)) {

        CVOGReaction_CastSkillOnTarget(puVar4,piVar2,0,0,0,&uStack_20,0,0xffffffff,0,0);

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar4);

      }

    }

  }

  return;

}
