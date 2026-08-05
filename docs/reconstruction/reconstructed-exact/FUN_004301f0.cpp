// =============================================================================
// FUN_004301f0 — scaffold twin of StringVec_PushBack
// -----------------------------------------------------------------------------
// Stable ID: aa_004301f0
// Address:   0x004301f0 (autoassault.exe base 0x400000)
// Prefer:    StringVec_PushBack.cpp
// Generated: 2026-07-29 W33-D (forwards to named clean)
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

extern "C" void __thiscall StringVec_PushBack(StringVecShell* self,
                                              const void* value_string);

extern "C" void __thiscall FUN_004301f0(StringVecShell* self,
                                        const void* value_string)
{
  StringVec_PushBack(self, value_string);
}
