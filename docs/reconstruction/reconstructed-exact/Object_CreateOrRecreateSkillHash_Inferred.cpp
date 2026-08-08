// =============================================================================
// Object_CreateOrRecreateSkillHash_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00518e30
// Address:   0x00518e30  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-08-04 WQ9R-J dual seal (clean reconstructed-exact)
// Exactness: Behavior-preserving rewrite of decompiler control flow + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Create owner skill-tree CNDHash at this+0x70, or recreate an existing one
//   at a new power-of-two size (log2 in BL/stack). sizeof hash object = 0x34.
//   Existing path calls skill-family recreate (FUN_004cbdc0) on the hash*.
//   Missing path: operator_new(0x34) + FUN_0051dd60(log2) ctor → store at +0x70.
//
// ABI
//   __thiscall; ECX = owner*; stack arg = log2 (byte width, dword push); void;
//   ret 4. Body 0x00518e30–0x00518ebe exclusive (142 B). SEH LAB_009a3627.
//
// CALLERS
//   Object_LoadCloneBaseSkillTrio_Inferred (push 1); orphan CODE 0x0052a2c5 (push 4).
// =============================================================================

void *__cdecl operator_new(unsigned int size);
// Skill-family CNDHash helpers (not dualled this wave; string/layout sealed)
void __thiscall FUN_004cbdc0(void *hash, unsigned char log2);      // recreate
void *__thiscall FUN_0051dd60(void *hashMem, unsigned char log2); // ctor → this

void __thiscall Object_CreateOrRecreateSkillHash_Inferred(void *owner, unsigned char log2)
{
  // SEH frame installed (LAB_009a3627) — omitted in clean CF

  void *hash = *(void **)((char *)owner + 0x70);
  if (hash != 0) {
    // ECX = hash (not owner)
    FUN_004cbdc0(hash, log2);
    return; // ret 4
  }

  void *block = operator_new(0x34);
  if (block != 0) {
    *(void **)((char *)owner + 0x70) = FUN_0051dd60(block, log2);
  } else {
    *(void **)((char *)owner + 0x70) = 0;
  }
  // ret 4
}
