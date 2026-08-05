// =============================================================================
// FUN_007647c0  (twin of Host_RegisterObjectAndAccumulateBounds)
// -----------------------------------------------------------------------------
// Stable ID: aa_007647c0
// Address:   0x007647c0–0x0076482d exclusive (109 B)
// Wave:      W36-L OWN-ONLY 2026-07-29
// =============================================================================

#include <cstdint>

extern "C" void Host_RegisterObjectAndAccumulateBounds(void* host, void* obj);

extern "C" void FUN_007647c0(void* host /*ECX*/, void* obj /*stack0*/)
{
    Host_RegisterObjectAndAccumulateBounds(host, obj);
}
