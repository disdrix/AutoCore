// =============================================================================
// GuardedVector_PushBackLocked
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c4f0
// Address:   0x0043c4f0–0x0043c54d  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-deque container
// Generated: 2026-07-23 scaffold as FUN_0043c4f0; dual A/B seal 2026-07-29 (W30-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Optional critical-section wrapper around GuardedVector_PushBack (0x0043c830).
 * - Retail ABI: EDI=container, stack=value*, RET 4. Void.
 * - Gate container+0x2c (char); CS at container+0x14.
 * - SEH frame present so Leave runs on exception unwind (handler LAB_009be0c8).
 * - Nested PushBack dual-sealed W29-B (EAX=container; page-map end write).
 * - Sole caller FUN_007b75b0: EDI = *DAT_00d1f058 + 0x58 (resolver list).
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

// Unowned: sealed W29-B — EAX=container, stack value*, RET 4
extern "C" void GuardedVector_PushBack(GuardedVectorHeader* container /*EAX*/,
                                       const uint32_t* value /*stack*/);

// Retail: EDI=container; stack value*; RET 4
extern "C" void GuardedVector_PushBackLocked(const uint32_t* value /*stack*/,
                                             GuardedVectorHeader* container /*EDI*/)
{
  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }

  // Retail: mov eax, edi; push value; call 0x0043c830
  GuardedVector_PushBack(container, value);

  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
}
