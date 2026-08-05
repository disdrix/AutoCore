// =============================================================================
// FUN_00431ae0 — scaffold twin of StringVec_Tidy
// -----------------------------------------------------------------------------
// Stable ID: aa_00431ae0
// Address:   0x00431ae0 (autoassault.exe base 0x400000)
// Prefer:    StringVec_Tidy.cpp
// Generated: 2026-07-29 W33-D (forwards to named clean)
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

extern "C" void __fastcall StringVec_Tidy(StringVecShell* self);

extern "C" void __fastcall FUN_00431ae0(StringVecShell* self)
{
  StringVec_Tidy(self);
}
