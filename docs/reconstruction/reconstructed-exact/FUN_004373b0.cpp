// =============================================================================
// FUN_004373b0 — twin of Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004373b0
// Address:   0x004373b0  (autoassault.exe, image base 0x400000)
// Generated: 2026-08-04 W38-E dual A/B (redirect twin)
// See:       Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" uint32_t Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred(
    void* host,
    void* reader);

extern "C" uint32_t FUN_004373b0(void* host /*EBX*/, void* reader /*stack*/)
{
  return Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred(host, reader);
}
