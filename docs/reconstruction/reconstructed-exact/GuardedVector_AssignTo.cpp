// =============================================================================
// GuardedVector_AssignTo
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c5f0
// Address:   0x0043c5f0–0x0043c650  (autoassault.exe, image base 0x400000)
// System:    STL / guarded container
// Generated: 2026-07-23 scaffold as FUN_0043c5f0; dual A/B seal 2026-07-29 (W25-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Optional critical-section wrapper around FUN_0043c730 (container assign).
 * - Retail ABI: ECX=source, stack=dest*, RET 4. Void.
 * - Gate source+0x2c (char); CS at source+0x14.
 * - SEH frame present so Leave runs on exception unwind (handler LAB_009be0c8).
 * - Nested assign body not owned in this unit.
 * - Callers include NDResourceCache_LookupOrCreate factory-list snapshot.
 */

#include <cstdint>
#include <windows.h>

struct GuardedVector {
  // +0x00..+0x13: vector-like payload (see FUN_0043c730)
  // void* begin; // +0x0c (probable)
  // uint32_t size_or_end; // +0x10 (probable)
  CRITICAL_SECTION cs; // +0x14  (24 bytes → through +0x2b)
  char lockEnable;     // +0x2c
};

// External (not owned): register ABI EAX=src, EDI=dst
extern "C" void FUN_0043c730(void);

// Clean explicit signature. Retail: ECX=source, stack dest, RET 4.
void GuardedVector_AssignTo(GuardedVector* source /*ECX*/, void* dest /*stack*/)
{
  if (source->lockEnable != 0) {
    EnterCriticalSection(&source->cs);
  }

  // Retail: mov eax, source; mov edi, dest; call FUN_0043c730
  // FUN_0043c730 reads EAX/EDI — not re-modeled here.
  (void)dest;
  FUN_0043c730();

  if (source->lockEnable != 0) {
    LeaveCriticalSection(&source->cs);
  }
}
