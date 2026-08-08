// =============================================================================
// FUN_0051b550  (scaffold twin → see Object_LoadCloneBaseSkillTrio_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b550
// Address:   0x0051b550  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-J dual seal
// Exactness: Behavior-preserving; clean named twin is authoritative for ports.
// =============================================================================

void __thiscall Object_CreateOrRecreateSkillHash_Inferred(void *owner, unsigned char log2);
void __thiscall Skill_EnsureLoadedInTree(void *owner, int skillId, unsigned short rank);

void __fastcall FUN_0051b550(int *param_1)
{
  int iVar1;
  unsigned char bVar2;

  Object_CreateOrRecreateSkillHash_Inferred(param_1, 1);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3bc);
  bVar2 = (**(unsigned char (**)(void))(*param_1 + 0x264))();
  Skill_EnsureLoadedInTree(param_1, iVar1, (unsigned short)bVar2);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c0);
  bVar2 = (**(unsigned char (**)(void))(*param_1 + 0x268))();
  Skill_EnsureLoadedInTree(param_1, iVar1, (unsigned short)bVar2);

  iVar1 = *(int *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3c4);
  bVar2 = (**(unsigned char (**)(void))(*param_1 + 0x26c))();
  Skill_EnsureLoadedInTree(param_1, iVar1, (unsigned short)bVar2);
}
