// =============================================================================
// FUN_009694e0 — scaffold twin of BasicString_CopyEnsureTrailingDirSep
// -----------------------------------------------------------------------------
// Stable ID: aa_009694e0
// Address:   0x009694e0 (autoassault.exe base 0x400000)
// Prefer:    BasicString_CopyEnsureTrailingDirSep.cpp
// Generated: 2026-07-29 W32-A (forwards to named clean)
// =============================================================================

#include <cstdint>

struct MsvcBasicString { uint8_t raw[0x1c]; };

extern "C" MsvcBasicString* BasicString_CopyEnsureTrailingDirSep(
    MsvcBasicString* out, const MsvcBasicString* src);

extern "C" MsvcBasicString* FUN_009694e0(MsvcBasicString* out,
                                         const MsvcBasicString* src)
{
  return BasicString_CopyEnsureTrailingDirSep(out, src);
}
