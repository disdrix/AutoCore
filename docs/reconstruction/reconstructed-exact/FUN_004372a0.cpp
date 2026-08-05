// =============================================================================
// FUN_004372a0 — twin of Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004372a0
// Address:   0x004372a0  (autoassault.exe, image base 0x400000)
// Generated: 2026-08-04 W38-E dual A/B (redirect twin)
// See:       Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.cpp
// =============================================================================

#include <cstdint>

// Prefer the named clean unit. This twin preserves the Ghidra symbol for
// inventory / redirect links only.

extern "C" uint32_t Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred(
    void** out_slot,
    void* reader);

extern "C" uint32_t FUN_004372a0(void** out_slot /*EDI*/, void* reader /*stack*/)
{
  return Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred(out_slot, reader);
}
