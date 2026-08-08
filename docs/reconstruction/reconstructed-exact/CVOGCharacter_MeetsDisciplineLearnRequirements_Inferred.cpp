// =============================================================================
// CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred  (aka FUN_0052b140)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b140
// Address:   0x0052b140  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R13-036 OWN-ONLY 2026-08-05 (dual start 2686)
// Parent:    0x0052b040 DisciplineDefMap_TryCopyPayloadById_Inferred
// Exactness: Behavior-preserving rewrite of decompiler + asm-sealed CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================
//
// PURPOSE:
//   Character-side bool gate: does this CVOGCharacter meet the requirements to
//   learn the Discipline identified by disciplineId?
//   1) Exact-find DisciplineDef on map @ 0x00b045b0; miss → false.
//   2) Copy 0x1FC from node+0x10 to stack.
//   3) Nested vtbl +0x27c level >= signed short def+0x26.
//   4) OR of five alternate prereq slots (id @ +0x08+4i, thr @ +0x1C+2i):
//      id != -1 && TryCopyPayloadById(id) && GetResourceBalanceByType(id) >= thr.
//   5) If all five ids == -1 (and level OK) → true.
//
// ABI (asm-sealed):
//   bool __thiscall CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(
//       void *character /* ECX */, int disciplineId /* stack0 */);
//   - RET 4; return bool in AL
//
// DOMAIN EVIDENCE (callers; not dualled here):
//   FUN_00931cf0 — "You do not meet the requirements to learn this Discipline"
//   FUN_0052d180 — fail → code 4
//   FUN_0084d220 — "Requires Minimum Level of" / "Requires: "
//
// ODD BEHAVIOR PRESERVED:
//   Prereq slots are OR alternatives (any one unlocks), not AND-all.
// =============================================================================

#include <stdint.h>

// Map exact-find: thiscall(map, out, key); used with ECX = 0x00b045b0.
extern "C" void *__thiscall FUN_00538ab0(void *mapHeader, void *outNodeSlot, int *pKey);
extern "C" uint8_t __cdecl DisciplineDefMap_TryCopyPayloadById_Inferred(int id, void *out0x1FC);
extern "C" int __thiscall CVOGCharacter_GetResourceBalanceByType(void *self, int resourceTypeId);

extern "C" void *DAT_00b045b4;
static void *const g_DisciplineDefMapHeader = (void *)0x00b045b0;

// DisciplineDef payload fields used by this unit (offsets from node+0x10).
struct DisciplineDefLearnFields_Inferred {
  uint32_t _pad0[2];     // +0x00
  int32_t prereqId[5];   // +0x08 .. +0x18
  int16_t prereqThr[5];  // +0x1C .. +0x24
  int16_t minLevel;      // +0x26
  uint8_t _rest[0x1FC - 0x28];
};

static int Character_CallVtbl27c_Inferred(void *character)
{
  int mid = *(int *)((char *)character + 4);
  int base = *(int *)(mid + 4);
  int *obj = (int *)(base + 4 + (uintptr_t)character);
  int *vtbl = (int *)*obj;
  auto fn = (int(__thiscall *)(void *))vtbl[0x27c / 4];
  return fn(obj);
}

extern "C" uint8_t __thiscall CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(
    void *character,
    int disciplineId)
{
  void *outItSlot;
  void *nodeSlot = &outItSlot;
  int key = disciplineId;
  void **pNode;
  DisciplineDefLearnFields_Inferred def;
  uint8_t scratch[0x1FC];
  int level;
  int i;

  pNode = (void **)FUN_00538ab0(g_DisciplineDefMapHeader, nodeSlot, &key);
  {
    uint8_t *node = (uint8_t *)*pNode;
    if (node == (uint8_t *)DAT_00b045b4) {
      return 0;
    }
    {
      uint32_t *src = (uint32_t *)(node + 0x10);
      uint32_t *dst = (uint32_t *)&def;
      int n = 0x7f;
      while (n != 0) {
        *dst = *src;
        ++src;
        ++dst;
        --n;
      }
    }
  }

  level = Character_CallVtbl27c_Inferred(character);
  if ((int)def.minLevel > level) {
    return 0;
  }

  for (i = 0; i < 5; ++i) {
    int id = def.prereqId[i];
    int bal;
    if (id == -1) {
      continue;
    }
    if (DisciplineDefMap_TryCopyPayloadById_Inferred(id, scratch) == 0) {
      continue;
    }
    bal = CVOGCharacter_GetResourceBalanceByType(character, id);
    if (bal >= (int)def.prereqThr[i]) {
      return 1;
    }
  }

  if (def.prereqId[0] == -1 && def.prereqId[1] == -1 && def.prereqId[2] == -1
      && def.prereqId[3] == -1 && def.prereqId[4] == -1) {
    return 1;
  }
  return 0;
}

// Ghidra twin export name
extern "C" uint8_t __thiscall FUN_0052b140(void *param_1, int param_2)
{
  return CVOGCharacter_MeetsDisciplineLearnRequirements_Inferred(param_1, param_2);
}
