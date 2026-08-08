// =============================================================================
// FUN_00401480  (scaffold twin of StdPairKey_Less_HiSignedLoUnsigned_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401480
// Address:   0x00401480  (autoassault.exe, image base 0x400000)
// Body:      0x00401480 – 0x004014a5 exclusive (37 B / 0x25)
// System:    std 2-dword pair-key less-than
// Generated: 2026-08-04 WQ9G-B dual seal
// Exactness: Behavior-preserving; named clean is primary.
// =============================================================================

#include <cstdint>

// Prefer: StdPairKey_Less_HiSignedLoUnsigned_Inferred.cpp
extern "C" uint32_t __stdcall StdPairKey_Less_HiSignedLoUnsigned_Inferred(
    const uint32_t* a, const uint32_t* b);

extern "C" uint32_t __stdcall FUN_00401480(const uint32_t* param_1, const uint32_t* param_2)
{
    return StdPairKey_Less_HiSignedLoUnsigned_Inferred(param_1, param_2);
}
