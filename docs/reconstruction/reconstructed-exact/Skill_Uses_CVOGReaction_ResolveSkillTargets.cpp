// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CVOGReaction_ResolveSkillTargets, FUN_004d1b80, FUN_005242d0, FUN_005b3ad0, ROUND.
//  - Return sites: 3.

// =============================================================================
// Skill_Uses_CVOGReaction_ResolveSkillTargets
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "CVOGReaction_ResolveSkillTargets"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004d1b80 clean capture (not modernized).
//
// Address:  0x004d1b80  (autoassault.exe, image base 0x400000)
// Stable:   aa_004d1b80
// Stable ID: aa_004d1b80
// System:   skills-abilities
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004d1b80_*.md
//           Original Ghidra symbol: FUN_004d1b80
//
// Exactness: Body mirrors reconstructed-exact/FUN_004d1b80*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Skill_Uses_CVOGReaction_ResolveSkillTargets
// -----------------------------------------------------------------------------
// Stable ID: aa_004d1b80
// Address:   0x004d1b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "CVOGReaction_ResolveSkillTargets"
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



uint32_t /* width from decompiler */ __thiscall Skill_Uses_CVOGReaction_ResolveSkillTargets(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  float10 extraout_ST0;

  uint8_t local_20 [28];

  

  if (*(int *)(param_1 + 0xe4fc) != 0) {

    uVar3 = FUN_005242d0(local_20);

    FUN_005b3ad0(uVar3);

    fVar2 = (float)extraout_ST0;

    if (g_flZero < fVar2) {

      if (g_flOne <= fVar2) {

        iVar5 = 0x12;

      }

      else {

        iVar5 = (int)ROUND(fVar2 * _DAT_009cc518);

      }

      puVar4 = CVOGReaction_ResolveSkillTargets(DAT_009d95ac,iVar5);

      iVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x19c))();

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x164 + iVar5);

      _DAT_00b03820 = *puVar1;

      _DAT_00b03824 = puVar1[1];

      _DAT_00b03828 = puVar1[2];

      _DAT_00b0382c = puVar1[3];

      _DAT_00b03830 = DAT_009cbf68;

      _DAT_00b03834 = DAT_009cbf6c;

      _DAT_00b0383c = DAT_009cbf74;

      _DAT_00b03838 = DAT_009cbf70;

      CVOGReaction_CastSkillOnTarget

                (puVar4,*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2,0,0,&DAT_00b03820,

                 &DAT_00b03800,0,0xffffffff,0,0);

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(puVar4);

      }

      return 1;

    }

  }

  return 0;

}
