// =============================================================================
// FUN_004501d0 — twin of AnimEventVec_InsertN_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004501d0
// Address:   0x004501d0
// Wave:      W34-O OWN-ONLY dual
// =============================================================================

#include <cstdint>

extern "C" void __stdcall AnimEventVec_InsertN_Inferred(
    void *vec, void *where, uint32_t count, void *value);

extern "C" void FUN_004501d0(void *vec, void *where, uint32_t count, void *value)
{
  AnimEventVec_InsertN_Inferred(vec, where, count, value);
}
