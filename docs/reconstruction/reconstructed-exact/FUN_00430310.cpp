// =============================================================================
// FUN_00430310 — scaffold twin of StringVec_InsertOne
// -----------------------------------------------------------------------------
// Stable ID: aa_00430310
// Address:   0x00430310 (autoassault.exe base 0x400000)
// Prefer:    StringVec_InsertOne.cpp
// Generated: 2026-07-29 W32-A (forwards to named clean)
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void* pad0;
  uint8_t* begin;
  uint8_t* end;
};

extern "C" void __thiscall StringVec_InsertOne(StringVecShell* self,
                                               uint8_t** out_iterator,
                                               uint8_t* pos,
                                               const void* value_string);

extern "C" void __thiscall FUN_00430310(StringVecShell* self,
                                        uint8_t** out_iterator,
                                        uint8_t* pos,
                                        const void* value_string)
{
  StringVec_InsertOne(self, out_iterator, pos, value_string);
}
