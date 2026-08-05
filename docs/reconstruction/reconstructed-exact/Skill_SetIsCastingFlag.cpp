// =============================================================================
// Skill_SetIsCastingFlag
// -----------------------------------------------------------------------------
// Stable ID: aa_005502d0
// Address:   0x005502d0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual seal: 2026-07-29 (Ghidra decompile + read_memory body/callers)
// Exactness: Behavior-preserving rewrite of machine CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (SEALED High — reviews/a_005502d0.md):
 * - __thiscall: ECX = skill runtime; one stack arg char bIsCasting; RET 4.
 * - Always writes skill+0x628 (uint8) = bIsCasting.
 * - If true: skill+0x170 = 0.0f (movss); skill+0x178 = g_dwClientTickMs (DAT_00b041cc).
 * - If false: does NOT clear +0x170 / +0x178.
 * - Callers: CVOGHBOKToCastAgain_OnStart(1), _OnEnd(0), FUN_0052c780 bulk clear(0).
 * - Decompiler 3-arg / void* flag shape is wrong; discarded.
 */

extern "C" unsigned int g_dwClientTickMs; // DAT_00b041cc

/* Skill_SetIsCastingFlag(thisSkill, bIsCasting)
   skill+0x628 is-casting flag; true stamps +0x170=0.f and +0x178=tick. */

void __thiscall Skill_SetIsCastingFlag(void *thisSkill, char bIsCasting)
{
  *(char *)((int)thisSkill + 0x628) = bIsCasting;
  if (bIsCasting != '\0') {
    *(float *)((int)thisSkill + 0x170) = 0.0f;
    *(unsigned int *)((int)thisSkill + 0x178) = g_dwClientTickMs;
  }
  return;
}
