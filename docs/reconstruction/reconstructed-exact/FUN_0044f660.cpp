// =============================================================================
// FUN_0044f660  — twin of Object_GetFieldAtPlus8_Inferred (aa_0044f660)
// -----------------------------------------------------------------------------
// Address:   0x0044f660  (autoassault.exe, image base 0x400000)
// Wave:      R10-027 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named unit: Object_GetFieldAtPlus8_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t __fastcall Object_GetFieldAtPlus8_Inferred(void* self);

// Ghidra name alias — identical body to named reconstruction.
extern "C" uint32_t __fastcall FUN_0044f660(void* self)
{
  return Object_GetFieldAtPlus8_Inferred(self);
}
