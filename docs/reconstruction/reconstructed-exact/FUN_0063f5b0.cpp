// =============================================================================
// FUN_0063f5b0  (alias → EmptyBase_Ctor_ReturnThis_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f5b0
// Address:   0x0063f5b0–0x0063f5bb  (autoassault.exe, image base 0x400000)
// System:    object / POD base construction
// Generated: 2026-07-29 W25-L (twin of named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical: reconstructed-exact/EmptyBase_Ctor_ReturnThis_Inferred.cpp

#include <cstdint>

extern "C" void* FUN_005edf20(void* p);

// Ghidra-faithful surface.
uint32_t __fastcall FUN_0063f5b0(uint32_t param_1)
{
  FUN_005edf20(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)));
  return param_1;
}
