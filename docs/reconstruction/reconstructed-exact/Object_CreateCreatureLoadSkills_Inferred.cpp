// =============================================================================
// Object_CreateCreatureLoadSkills_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8f00
// Address:   0x004c8f00–0x004c9113  (autoassault.exe @ 0x400000; 532 B / 0x214)
// System:    skills-abilities / creature create + skill-bank load
// Dual A/B:  2026-08-04 WQ9E-H
// Exactness: Behavior-preserving. Decompile CF sealed against disasm + strings.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   MI virtual: factory-create object from source embedded CBID, cast to
//   CVOGCreature, copy selected fields, recreate dest skill hash at log2=2,
//   traverse-lock source skill hash and Skill_EnsureLoadedInTree each skill.
//
// ABI
//   __thiscall; ECX = source this (MI-adjusted); no stack args; plain RET;
//   returns creature primary* (MI +4 form) or nullptr.
//
// Callers (vtable thunks)
//   0x004cd003 JMP
//   0x0053bd99 SUB ECX,0x8a0; JMP
//
// Nested (not dualled this wave)
//   Object_CreateFromEmbeddedCbid_Inferred (0x0051b230)
//   SkillCNDHash_Recreate_Inferred (0x004cbdc0) — second CODE site, imm log2=2
//   Skill_EnsureLoadedInTree (0x0051a980)
//   FUN_004c4070 / FUN_004c41c0 accuracy helpers
//
// Rejected aliases
//   Mission_CVOGClonedObjectBase_RTTI_Type_Descriptor
//   Named_VOG_DEBUG_STOP_004c8f00
// =============================================================================

#include <cstdint>

extern void *__thiscall Object_CreateFromEmbeddedCbid_Inferred(void *self);
extern void *__cdecl __RTDynamicCast(void *obj /*, ... RTTI args via stack */);
extern void __thiscall SkillCNDHash_Recreate_Inferred(void *hash, uint8_t log2);
extern void __thiscall Skill_EnsureLoadedInTree(void *destPrimary, int skillKey, int16_t skillLevel);
extern uint16_t __thiscall FUN_004c4070(void *srcBand);
extern uint16_t __thiscall FUN_004c41c0(void *srcBand);
extern void FUN_007a4480(int level, const char *msg);

// void* __thiscall Object_CreateCreatureLoadSkills_Inferred(void *sourceThis)
void *__thiscall Object_CreateCreatureLoadSkills_Inferred(int sourceThis)
{
  // Factory on cloned-object MI subobject at source-0x4fc, then cast to CVOGCreature
  void *created = Object_CreateFromEmbeddedCbid_Inferred(
      reinterpret_cast<void *>(sourceThis - 0x4fc));
  // Image: PUSH created; CALL __RTDynamicCast with RTTI ClonedObjectBase→Creature
  int creature = reinterpret_cast<int>(__RTDynamicCast(created));
  int walkNode = 0;

  if (creature == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    return nullptr;
  }

  // Source primary MI base (source-0x4fc band)
  int srcPrimary = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(sourceThis - 0x4fc) + 4 + (sourceThis - 0x4fc));
  // vtbl+0x27c → clamp to >=1 → creature+0x150
  int v = (**(int (**)())(*reinterpret_cast<int *>(srcPrimary) + 0x27c))();
  if (v < 2)
    v = 1;
  *reinterpret_cast<int *>(creature + 0x150) = v;

  // Copy pair of source→dest vtbl methods (0x244→0x248, 0x23c→0x240)
  int destPrimaryV = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(creature + 4) + 4 + creature);
  int tmp = (**(int (**)())(*reinterpret_cast<int *>(srcPrimary) + 0x244))();
  (**(void (**)(int))(destPrimaryV + 0x248))(tmp);
  destPrimaryV = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(creature + 4) + 4 + creature);
  tmp = (**(int (**)())(*reinterpret_cast<int *>(srcPrimary) + 0x23c))();
  (**(void (**)(int))(destPrimaryV + 0x240))(tmp);

  *reinterpret_cast<uint32_t *>(creature + 0x128) =
      *reinterpret_cast<uint32_t *>(sourceThis - 0x3d8);

  int srcBand = sourceThis - 0x500; // LEA EBP,[EDI-0x500]
  *reinterpret_cast<uint16_t *>(creature + 0x13e) =
      FUN_004c4070(reinterpret_cast<void *>(srcBand));
  *reinterpret_cast<uint16_t *>(creature + 0x142) =
      FUN_004c41c0(reinterpret_cast<void *>(srcBand));
  *reinterpret_cast<uint8_t *>(creature + 0x100) =
      *reinterpret_cast<uint8_t *>(sourceThis - 0x400);
  if (*reinterpret_cast<char *>(sourceThis - 0x1f5) != 0)
    *reinterpret_cast<uint8_t *>(creature + 0x30b) = 1;

  // Dest skill hash @ owner+0x70; recreate with fixed log2=2
  {
    int mi = *reinterpret_cast<int *>(creature + 4);
    int adj = *reinterpret_cast<int *>(mi + 4);
    void *destHash = *reinterpret_cast<void **>(adj + creature + 0x74); // primary+0x70
    SkillCNDHash_Recreate_Inferred(destHash, 2);
  }

  // Source skill hash @ +0x70 of source primary
  int srcHash = *reinterpret_cast<int *>(
      *reinterpret_cast<int *>(*reinterpret_cast<int *>(sourceThis - 0x4fc) + 4) +
      (sourceThis - 0x48c));
  if (*reinterpret_cast<char *>(srcHash + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<uint8_t *>(srcHash + 0x1d) = 1;

  for (;;) {
    srcHash = *reinterpret_cast<int *>(
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(sourceThis - 0x4fc) + 4) +
        (sourceThis - 0x48c));
    if (*reinterpret_cast<char *>(srcHash + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (walkNode == 0)
      walkNode = *reinterpret_cast<int *>(srcHash + 0x14); // ordered head
    else
      walkNode = *reinterpret_cast<int *>(walkNode + 0x14); // next

    int skillObj = (walkNode == 0) ? 0 : *reinterpret_cast<int *>(walkNode + 8);
    if (skillObj == 0)
      break;

    int destPrimary = *reinterpret_cast<int *>(creature + 4);
    destPrimary = *reinterpret_cast<int *>(destPrimary + 4) + 4 + creature;
    Skill_EnsureLoadedInTree(
        reinterpret_cast<void *>(destPrimary),
        *reinterpret_cast<int *>(skillObj + 0x5fc),
        *reinterpret_cast<int16_t *>(skillObj + 0x5f6));
  }

  *reinterpret_cast<uint8_t *>(
      *reinterpret_cast<int *>(
          *reinterpret_cast<int *>(*reinterpret_cast<int *>(sourceThis - 0x4fc) + 4) +
          (sourceThis - 0x48c)) +
      0x1d) = 0;

  {
    int mi = *reinterpret_cast<int *>(creature + 4);
    int adj = *reinterpret_cast<int *>(mi + 4);
    return reinterpret_cast<void *>(adj + creature + 4);
  }
}
