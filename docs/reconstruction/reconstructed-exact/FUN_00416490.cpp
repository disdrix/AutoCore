// =============================================================================
// FUN_00416490 — scaffold twin of StdString_OperatorPlus_Cstr
// -----------------------------------------------------------------------------
// Stable ID: aa_00416490
// Address:   0x00416490 (autoassault.exe base 0x400000)
// Prefer:    StdString_OperatorPlus_Cstr.cpp
// Generated: 2026-07-29 W33-F (forwards to named clean)
// =============================================================================

#include <cstdint>

struct MsvcBasicString { uint8_t raw[0x1c]; };

extern "C" MsvcBasicString* StdString_OperatorPlus_Cstr(
    MsvcBasicString* out, const MsvcBasicString* lhs, const char* rhs);

extern "C" MsvcBasicString* FUN_00416490(MsvcBasicString* out,
                                         const MsvcBasicString* lhs,
                                         const char* rhs)
{
  return StdString_OperatorPlus_Cstr(out, lhs, rhs);
}
