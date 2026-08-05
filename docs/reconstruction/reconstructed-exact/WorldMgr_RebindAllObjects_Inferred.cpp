// =============================================================================
// WorldMgr_RebindAllObjects_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00561370
// Address:   0x00561370  (autoassault.exe, image base 0x400000)
// System:    world / phys manager rebind
// Generated: 2026-07-29 W27-P from live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   After a manager profile/settings swap (caller FUN_00562530 when flag≠0),
//   rebind every object in two island/group lists (unbind → bind → set host+0x28),
//   then run FUN_0055f7a0(obj, 1) on the extra list at manager+0x120.
//
// ABI:
//   void __thiscall WorldMgr_RebindAllObjects_Inferred(Manager* this);
//   ECX = this; 0 stack args; bare ret.
//   Body: 0x00561370–0x0056144a exclusive (218 B).
//
// CALLEES (sealed duals where noted):
//   FUN_0055fbf0 WorldObj_UnbindLinks_Inferred (W26-D)
//   FUN_0055fa40 WorldObj_BindLinks_Inferred   (W26-E)
//   FUN_0055f7a0 (not OWN; manager + obj* + char)
//

#include <cstdint>

// External callees (Ghidra names retained)
extern "C" void __thiscall FUN_0055fbf0(void* manager, void* obj);
extern "C" void __thiscall FUN_0055fa40(void* manager, void* obj);
extern "C" void __thiscall FUN_0055f7a0(void* manager, void* obj, char flag);

struct IslandBodyVec {
  void** data;   // island+0x3c
  int32_t count; // island+0x40
};

// Island pointer values are full objects; body vector lives at +0x3c.
// Manager vectors: (data*, count) pairs at +8/+0xc, +0x14/+0x18, +0x120/+0x124.

extern "C" void __thiscall WorldMgr_RebindAllObjects_Inferred(void* manager)
{
  auto* const m = reinterpret_cast<uint8_t*>(manager);

  // Pass A: islands at manager+8 / count+0xc
  {
    void** islands = *reinterpret_cast<void***>(m + 0x08);
    int32_t nIslands = *reinterpret_cast<int32_t*>(m + 0x0c);
    for (int32_t i = 0; i < nIslands; ++i) {
      auto* island = reinterpret_cast<uint8_t*>(islands[i]);
      void** bodies = *reinterpret_cast<void***>(island + 0x3c);
      int32_t nBodies = *reinterpret_cast<int32_t*>(island + 0x40);
      for (int32_t bi = 0; bi < nBodies; ++bi) {
        void* body = bodies[bi];
        FUN_0055fbf0(manager, body);
        FUN_0055fa40(manager, body);
        auto* host = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(body) + 0x44);
        host[0x28] = 1;
      }
    }
  }

  // Pass B: islands at manager+0x14 / count+0x18
  {
    void** islands = *reinterpret_cast<void***>(m + 0x14);
    int32_t nIslands = *reinterpret_cast<int32_t*>(m + 0x18);
    for (int32_t i = 0; i < nIslands; ++i) {
      auto* island = reinterpret_cast<uint8_t*>(islands[i]);
      void** bodies = *reinterpret_cast<void***>(island + 0x3c);
      int32_t nBodies = *reinterpret_cast<int32_t*>(island + 0x40);
      for (int32_t bi = 0; bi < nBodies; ++bi) {
        void* body = bodies[bi];
        FUN_0055fbf0(manager, body);
        FUN_0055fa40(manager, body);
        auto* host = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(body) + 0x44);
        host[0x28] = 1;
      }
    }
  }

  // Pass C: extras at manager+0x120 / count+0x124
  {
    void** extras = *reinterpret_cast<void***>(m + 0x120);
    int32_t nExtras = *reinterpret_cast<int32_t*>(m + 0x124);
    for (int32_t i = 0; i < nExtras; ++i) {
      FUN_0055f7a0(manager, extras[i], 1);
    }
  }
}

// Ghidra export alias
extern "C" void __thiscall FUN_00561370(void* manager)
{
  WorldMgr_RebindAllObjects_Inferred(manager);
}
