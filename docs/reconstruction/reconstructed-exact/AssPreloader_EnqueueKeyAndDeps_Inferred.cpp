// =============================================================================
// AssPreloader_EnqueueKeyAndDeps_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009717a0
// Address:   0x009717a0–0x0097181c  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_009717a0
// System:    assPreloader / asset preload pipeline
// Dual:      W32-J 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX  = AssPreloader* this
//   stack = const int* key; RET 4; returns 0 (EAX).
//
// 1) Zero a local GuardedVector ring.
// 2) Push key onto local (FUN_0043d670 thiscall).
// 3) FUN_00744360(key, &local) with ECX = *(*(this+0x110)+0x64)
//    — expand dependency keys into local ring.
// 4) AssPreloader_EnqueueEligibleFromRing_Inferred(this, local)
//    — ESI=local, stack=this (W31-K FUN_00971640).
// 5) Clear/free local (FUN_005b2ba0).
// 6) return 0.
//
// Name is structural (_Inferred). Sibling multi-key loop is FUN_00971820.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                                const int* key /*stack*/);
extern "C" void FUN_00744360(const int* key /*stack*/, GuardedVectorHeader* out /*stack*/
                             /*ECX=dep host*/);
extern "C" void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack*/, GuardedVectorHeader* source /*ESI*/);
extern "C" void FUN_005b2ba0(void /*ECX=ring*/);

uint32_t AssPreloader_EnqueueKeyAndDeps_Inferred(
    void* self /*ECX; retail*/,
    const int* key /*stack; retail*/)
{
  GuardedVectorHeader local{};
  // pages/cap/begin/size zeroed (retail XOR EAX + four stores).

  GuardedVector_PushBack_Thiscall(&local, key);

  void* cache = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x110);
  void* dep_host = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(cache) + 0x64);
  // Retail: MOV ECX,dep_host before CALL.
  (void)dep_host;
  FUN_00744360(key, &local);

  AssPreloader_EnqueueEligibleFromRing_Inferred(self, &local);

  FUN_005b2ba0(); // ECX=&local
  return 0;
}
