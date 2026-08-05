// =============================================================================
// FUN_0043c4f0  (alias twin of GuardedVector_PushBackLocked)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c4f0
// Address:   0x0043c4f0–0x0043c54d  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-deque container
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W30-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named clean plate: GuardedVector_PushBackLocked.cpp

#include <cstdint>
#include <windows.h>

// Full header layout (ring + CS) — ring fields unused here except as base.
struct GuardedVectorHeader {
  uint32_t _pad00;
  void** pages;          // +0x04
  uint32_t capacity;     // +0x08
  uint32_t begin;        // +0x0c
  uint32_t size;         // +0x10
  CRITICAL_SECTION cs;   // +0x14 (24 bytes → through +0x2b)
  char lockEnable;       // +0x2c
};

// Unowned: sealed W29-B
extern "C" void FUN_0043c830(const uint32_t* value); // requires EAX=container

// Retail: EDI=container; stack value*; RET 4
// Decompiler shows only stack param; EDI recovered from body + sole caller.
extern "C" void FUN_0043c4f0(const uint32_t* value /*stack*/)
{
  // container in EDI (register formal; not in Ghidra signature)
  GuardedVectorHeader* container;
  __asm { mov container, edi }

  // SEH frame LAB_009be0c8 omitted in clean plate (behavior: Leave on unwind)

  if (container->lockEnable != 0) {
    EnterCriticalSection(&container->cs);
  }

  // Retail: mov eax, edi; push value; call FUN_0043c830
  __asm { mov eax, container }
  FUN_0043c830(value);

  if (container->lockEnable != 0) {
    LeaveCriticalSection(&container->cs);
  }
}
