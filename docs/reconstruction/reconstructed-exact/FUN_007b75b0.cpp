// =============================================================================
// FUN_007b75b0  (alias twin of AssManager_InitPrecompileAndResolvers_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_007b75b0
// Address:   0x007b75b0–0x007b7b6d  (autoassault.exe, image base 0x400000)
// System:    assets / assManager / NDAssetManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W30-D)
// Exactness: Behavior-preserving stage model. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Named clean plate: AssManager_InitPrecompileAndResolvers_Inferred.cpp

#include <cstdint>

// Retail ABI: stdcall 2 formals (self*, char mode); RET 8.
// Full stage model and string evidence live in the named plate.

extern "C" void AssManager_InitPrecompileAndResolvers_Inferred(void* self, char mode);

extern "C" void FUN_007b75b0(void* self /*stack*/, char mode /*stack*/)
{
  AssManager_InitPrecompileAndResolvers_Inferred(self, mode);
}
