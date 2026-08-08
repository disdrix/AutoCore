// =============================================================================
// Object_LoadCloneBaseSkillTrio_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b550
// Address:   0x0051b550  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-J dual seal (clean reconstructed-exact)
// Exactness: Behavior-preserving rewrite of decompiler control flow + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Virtual/shared method: (re)create owner skill CNDHash at this+0x70 with
//   log2=1, then ensure three clonebase default skills are present in the tree.
//   Skill ids from cloneBase+0x3BC/0x3C0/0x3C4; ranks from vtbl+0x264/0x268/0x26c.
//
// ABI
//   __thiscall / __fastcall; ECX = owner*; no stack formals; void; bare RET.
//   Body 0x0051b550–0x0051b5d0 exclusive (128 B). Epilogue: pop edi; pop esi; ret.
//
// CALLERS
//   FUN_004c8a60 bulk skill loadout (first call); many class vtables (DATA xrefs).
// =============================================================================

// Forward decls (sealed duals / this wave)
void __thiscall Object_CreateOrRecreateSkillHash_Inferred(void *owner, unsigned char log2);
void __thiscall Skill_EnsureLoadedInTree(void *owner, int skillId, unsigned short rank);

void __thiscall Object_LoadCloneBaseSkillTrio_Inferred(void *thisOwner)
{
  Object_CreateOrRecreateSkillHash_Inferred(thisOwner, /*log2*/ 1);

  // host @ this+0xA8 → +0x3C → clonebase template
  void *host = *(void **)((char *)thisOwner + 0xA8);
  char *cloneBase = *(char **)((char *)host + 0x3C);
  int *vtbl = *(int **)thisOwner;

  int skill0 = *(int *)(cloneBase + 0x3BC);
  unsigned char rank0 =
      ((unsigned char(__thiscall *)(void *))vtbl[0x264 / 4])(thisOwner);
  Skill_EnsureLoadedInTree(thisOwner, skill0, (unsigned short)rank0);

  int skill1 = *(int *)(cloneBase + 0x3C0);
  unsigned char rank1 =
      ((unsigned char(__thiscall *)(void *))vtbl[0x268 / 4])(thisOwner);
  Skill_EnsureLoadedInTree(thisOwner, skill1, (unsigned short)rank1);

  int skill2 = *(int *)(cloneBase + 0x3C4);
  unsigned char rank2 =
      ((unsigned char(__thiscall *)(void *))vtbl[0x26C / 4])(thisOwner);
  Skill_EnsureLoadedInTree(thisOwner, skill2, (unsigned short)rank2);
}
