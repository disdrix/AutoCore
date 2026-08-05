// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: CONCAT22, CVOGHBBase_AttachOwnerObject, FUN_00578430, FUN_007a4480.
//  - Strings: "Skill does not exist %d".
//  - Return sites: 2.

// =============================================================================
// Skill_Skill_does_not_exist_d_00578430
// -----------------------------------------------------------------------------
// Stable ID: aa_00578430
// Address:   0x00578430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Skill does not exist %d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_Skill_does_not_exist_d_00578430(int *param_1,int param_2,void *param_3)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  param_1[7] = 1;

  CVOGHBBase_AttachOwnerObject(param_1,param_3);

  param_1[0x19e] = *(int *)(param_2 + 0x10);

  param_1[0x19f] = *(int *)(param_2 + 0x14);

  param_1[0x1a0] = *(int *)(param_2 + 0x18);

  param_1[0x1a1] = *(int *)(param_2 + 0x1c);

  param_1[4] = (int)*(short *)(param_2 + 0x22);

  param_1[0x1a2] = *(int *)((int)param_3 + 0xa4);

  param_1[0x196] = *(int *)(param_2 + 0x28);

  param_1[0x197] = *(int *)(param_2 + 0x2c);

  param_1[0x198] = *(int *)(param_2 + 0x30);

  param_1[0x199] = *(int *)(param_2 + 0x34);

  piVar1 = CVOGReaction_ResolveSkillTargets

                     ((void *)(uint)*(ushort *)(param_2 + 0xc),

                      CONCAT22((short)((uint)(param_1 + 0x196) >> 0x10),

                               *(uint16_t *)(param_2 + 0xe)));

  if (piVar1 == (int *)0x0) {

    FUN_007a4480(1,"Skill does not exist %d",*(uint16_t *)(param_2 + 0xc));

    (**(code **)(*param_1 + 0x18))(1,1);

    return;

  }

  piVar3 = piVar1;

  piVar4 = param_1 + 9;

  for (iVar2 = 0x18c; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar4 = *piVar3;

    piVar3 = piVar3 + 1;

    piVar4 = piVar4 + 1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar1);

}
