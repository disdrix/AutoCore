// =============================================================================
// FUN_0043d420 / GuardedVector_AssignDwordIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d420
// Address:   0x0043d420–0x0043d430  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-deque element store
// Dual:      W32-F 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin clean: GuardedVector_AssignDwordIfNonNull.cpp

#include <cstdint>

void FUN_0043d420(uint32_t* param_1, const uint32_t* param_2)
{
  if (param_1 != nullptr) {
    *param_1 = *param_2;
  }
}
