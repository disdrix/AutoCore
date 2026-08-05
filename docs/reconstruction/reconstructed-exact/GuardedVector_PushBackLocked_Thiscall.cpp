// =============================================================================
// GuardedVector_PushBackLocked_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e4b0
// Address:   0x0043e4b0–0x0043e50d  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-deque container
// Generated: 2026-07-23 scaffold as FUN_0043e4b0; dual A/B seal 2026-07-29 (W32-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Optional critical-section wrapper around GuardedVector_PushBack_Thiscall (0x0043d670).
 * - Retail ABI: EDI=container, stack=value*, RET 4. Void.
 * - Gate container+0x2c (char); CS at container+0x14.
 * - SEH frame present so Leave runs on exception unwind (handler LAB_009be0c8).
 * - Nested PushBack_Thiscall dual-sealed W31-I (ECX=container; page-map end write).
 * - Bit-twin of W30-D GuardedVector_PushBackLocked (0x0043c4f0) which nests EAX PushBack.
 * - Sole known caller FUN_00971640 @ 0x009716cd (AssPreloader enqueue path).
 */

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  // +0x00 pad / vtable-ish
  // +0x04 pages / slots
  // +0x08 capacity
  // +0x0c begin
  // +0x10 size
  CRITICAL_SECTION cs; // +0x14  (24 bytes → through +0x2b)
  char lockEnable;     // +0x2c
};

// Unowned: sealed W31-I — ECX=container, stack value*, RET 4
extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                                const uint32_t* value /*stack*/);

// Retail: EDI=container; stack value*; RET 4
extern "C" void GuardedVector_PushBackLocked_Thiscall(const uint32_t* value /*stack*/,
                                                      GuardedVectorHeader* container /*EDI*/)
{
  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }

  // Retail: mov ecx, edi; push value; call 0x0043d670
  GuardedVector_PushBack_Thiscall(container, value);

  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
}
