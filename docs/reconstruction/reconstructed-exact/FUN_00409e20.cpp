// =============================================================================
// FUN_00409e20  (scaffold twin of StdVector_ConstructN_Elem0x10_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409e20
// Address:   0x00409e20  (autoassault.exe, image base 0x400000)
// Body:      0x00409e20–0x00409e82 inclusive (99 B / 0x63)
// System:    util / container (elem stride 0x10)
// Generated: 2026-08-05 MEGA-044 dual seal
// Exactness: Behavior-preserving rewrite. Not bit-for-bit (DEFERRED).
// Dual A/B: accept-with-gaps. Named clean: StdVector_ConstructN_Elem0x10_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void StdVector_ConstructN_Elem0x10_Inferred(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count);

// Ghidra symbol — forwards to named reconstruction.
extern "C" void FUN_00409e20(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count)
{
  StdVector_ConstructN_Elem0x10_Inferred(value, dest, count);
}
