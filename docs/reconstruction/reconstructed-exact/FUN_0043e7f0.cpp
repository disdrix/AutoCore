// =============================================================================
// FUN_0043e7f0  (twin of GuardedVector_PushBackLocked_Stride2_U32U8.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e7f0
// Address:   0x0043e7f0–0x0043e84d  (autoassault.exe, image base 0x400000)
// Dual:      W32-N 2026-07-29 — see GuardedVector_PushBackLocked_Stride2_U32U8.cpp.
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint8_t** pages;
  int32_t  capacity;
  int32_t  begin;
  int32_t  size;
  CRITICAL_SECTION cs;
  char lockEnable;
};

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
};

extern "C" void GuardedVector_PushBack_Stride2_U32U8(
    GuardedVectorHeader* container /*EAX*/,
    const PodU32U8* value /*stack*/);

// Retail: EDI=container; stack value*; RET 4
extern "C" void FUN_0043e7f0(const PodU32U8* value /*stack*/,
                             GuardedVectorHeader* container /*EDI*/)
{
  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }
  GuardedVector_PushBack_Stride2_U32U8(container, value);
  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
}
