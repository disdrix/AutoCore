// =============================================================================
// FUN_0052c780  (leave-FUN — no product name)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c780
// Address:   0x0052c780 – 0x0052c854  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W18-I OWN dual A/B seal
// Exactness: Behavior-preserving; byte-sealed clear-walk + lock. Not modernization.
// Naming:    leave FUN_*; reject Named_VOG_DEBUG_STOP_* (assert string only).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE (behavioral)
// Entity-side skill cast-state teardown:
//   clear this+0x6bb; secondary vcall +0x40(1);
//   lazy-get busy block via FUN_005169c0(sec) then FUN_005b2ba0(block) drain;
//   traversal-locked walk of skill hash at sec+0x74 → Skill_SetIsCastingFlag(skill, 0);
//   clear this+0x1fc; tail FUN_004c81f0(this).

#include <cstdint>

extern void* __fastcall FUN_005169c0(void* sec /* ECX */);
extern void  __fastcall FUN_005b2ba0(void* block /* ECX */);
extern void  __thiscall Skill_SetIsCastingFlag(void* skill, char bIsCasting /* stack; RET 4 */);
extern void  __fastcall FUN_004c81f0(void* entity /* ECX */);
extern void  FUN_007a4480(int level, const char* msg);

void __fastcall FUN_0052c780(int param_1 /* this in ECX */)
{
  auto* self = reinterpret_cast<uint8_t*>(param_1);

  self[0x6bb] = 0;

  // Secondary-base adjustor (MSVC): adj = *(*(this+4)+4); sec = this+adj+4
  int* p4 = *reinterpret_cast<int**>(self + 4);
  int adj = p4[1];
  auto* sec = self + adj + 4;
  auto** vtbl = *reinterpret_cast<void***>(sec);
  // push 1; call vtbl[+0x40]
  using VFn = void(__thiscall*)(void*, int);
  reinterpret_cast<VFn>(vtbl[0x40 / 4])(sec, 1);

  void* block = FUN_005169c0(sec);
  FUN_005b2ba0(block);

  // hash object*
  auto* hash = *reinterpret_cast<uint8_t**>(
      reinterpret_cast<char*>(param_1) + *reinterpret_cast<int*>(*reinterpret_cast<int**>(param_1 + 4) + 1) + 0x74);
  // Prefer recompute each iter as decompile does:
  // hash = *( *( *(this+4)+4 ) + this + 0x74 )

  auto get_hash = [&]() -> uint8_t* {
    int a = *reinterpret_cast<int*>(*reinterpret_cast<int**>(param_1 + 4) + 1);
    return *reinterpret_cast<uint8_t**>(reinterpret_cast<char*>(param_1) + a + 0x74);
  };

  hash = get_hash();
  if (hash[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  hash[0x1d] = 1;

  uint8_t* node = nullptr;
  for (;;) {
    hash = get_hash();
    if (hash[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (node == nullptr) {
      node = *reinterpret_cast<uint8_t**>(hash + 0x14);
    } else {
      node = *reinterpret_cast<uint8_t**>(node + 0x14);
    }
    void* skill = (node == nullptr) ? nullptr : *reinterpret_cast<void**>(node + 8);
    if (skill == nullptr)
      break;
    Skill_SetIsCastingFlag(skill, 0); // push 0; NOT push 1
  }

  get_hash()[0x1d] = 0;
  *reinterpret_cast<uint32_t*>(self + 0x1fc) = 0;
  FUN_004c81f0(self);
}
