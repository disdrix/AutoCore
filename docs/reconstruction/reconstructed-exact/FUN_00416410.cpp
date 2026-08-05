// =============================================================================
// FUN_00416410 — scaffold twin of StdString_OperatorPlus_String
// -----------------------------------------------------------------------------
// Stable ID: aa_00416410
// Address:   0x00416410 (autoassault.exe base 0x400000)
// Prefer:    StdString_OperatorPlus_String.cpp
// Generated: 2026-07-29 W33-F (forwards to named clean)
// =============================================================================

#include <cstdint>

struct MsvcBasicString { uint8_t raw[0x1c]; };

extern "C" MsvcBasicString* StdString_OperatorPlus_String(
    MsvcBasicString* out, const MsvcBasicString* lhs, const MsvcBasicString* rhs);

extern "C" MsvcBasicString* FUN_00416410(MsvcBasicString* out,
                                         const MsvcBasicString* lhs,
                                         const MsvcBasicString* rhs)
{
  return StdString_OperatorPlus_String(out, lhs, rhs);
}
