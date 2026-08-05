// =============================================================================
// FUN_00416510 — twin alias of StdString_OperatorPlus_Char
// -----------------------------------------------------------------------------
// Stable ID: aa_00416510
// Address:   0x00416510–0x00416589 (122 B / 0x7A)
// Generated: 2026-07-29 W34-C (replaces 2026-07-23 scaffold)
// Canonical clean: StdString_OperatorPlus_Char.cpp
// =============================================================================

#include <cstdint>

struct MsvcBasicString {
  uint8_t raw[0x1c];
};

extern "C" MsvcBasicString* StdString_OperatorPlus_Char(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    char rhs);

extern "C" MsvcBasicString* FUN_00416510(MsvcBasicString* out,
                                         const MsvcBasicString* lhs,
                                         char rhs)
{
  return StdString_OperatorPlus_Char(out, lhs, rhs);
}
