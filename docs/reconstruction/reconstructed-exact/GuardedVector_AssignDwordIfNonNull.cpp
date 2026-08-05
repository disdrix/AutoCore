// =============================================================================
// GuardedVector_AssignDwordIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d420
// Address:   0x0043d420–0x0043d430  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043d420
// System:    STL / guarded ring-deque element store
// Dual:      W32-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: stack (dst*, src*); plain RET (cdecl). 17 B body.
// Null-checked POD dword assign used by thiscall PushBack/PushFront (W31-I).
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

// Retail: cdecl; 2 stack formals; RET 0
void GuardedVector_AssignDwordIfNonNull(uint32_t* dst, const uint32_t* src)
{
  if (dst != nullptr) {
    *dst = *src;
  }
}
