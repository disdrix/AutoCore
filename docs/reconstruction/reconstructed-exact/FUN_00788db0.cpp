// =============================================================================
// FUN_00788db0  →  MemZero_DestSize_ReturnOne_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00788db0
// Address:   0x00788db0  (autoassault.exe, image base 0x400000)
// Wave:      W37-O OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// See MemZero_DestSize_ReturnOne_Inferred.cpp for named implementation.
// cdecl; dest*, size; bare RET; returns 1. Leaf REP STOS zero-fill.

extern "C" uint32_t __cdecl MemZero_DestSize_ReturnOne_Inferred(void* dest, int size);

extern "C" uint32_t __cdecl FUN_00788db0(void* dest, int size)
{
  return MemZero_DestSize_ReturnOne_Inferred(dest, size);
}
