// =============================================================================
// GuardedVector_PushBackLocked_Stride2_U32U8
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e7f0
// Address:   0x0043e7f0–0x0043e84d  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e7f0
// System:    STL / guarded ring-deque container (locked push wrapper)
// Dual:      W32-N 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EDI = container; stdcall 1 stack formal (const PodU32U8* value);
//             RET 0x4. Bit-twin of GuardedVector_PushBackLocked (W30-D / 0043c4f0)
//             with nested body = GuardedVector_PushBack_Stride2_U32U8 (W31-J).
// Optional CS at +0x14 gated by +0x2c; SEH LAB_009be0c8 around nested push.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint8_t** pages;     // +0x04
  int32_t  capacity;   // +0x08
  int32_t  begin;      // +0x0c
  int32_t  size;       // +0x10
  CRITICAL_SECTION cs; // +0x14  (24 bytes → through +0x2b)
  char lockEnable;     // +0x2c
};

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
};

// Unowned: sealed W31-J — EAX=container, stack value*, RET 4
extern "C" void GuardedVector_PushBack_Stride2_U32U8(
    GuardedVectorHeader* container /*EAX*/,
    const PodU32U8* value /*stack*/);

// Retail: EDI=container; stack value*; RET 4
extern "C" void GuardedVector_PushBackLocked_Stride2_U32U8(
    const PodU32U8* value /*stack*/,
    GuardedVectorHeader* container /*EDI*/)
{
  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }

  // Retail: mov eax, edi; push value; call 0x0043e9e0
  GuardedVector_PushBack_Stride2_U32U8(container, value);

  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
}
