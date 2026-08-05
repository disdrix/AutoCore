// =============================================================================
// FUN_00431aa0  (scaffold twin → StdVector_DestroyRange_BasicString)
// -----------------------------------------------------------------------------
// Stable ID: aa_00431aa0
// Address:   0x00431aa0  (autoassault.exe, image base 0x400000)
// Wave:      W33-H OWN-ONLY dual 2026-07-29
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t bytes[0x1c];
};

extern "C" void __thiscall basic_string_dtor(BasicString_0x1c* self);

extern "C" void FUN_00431aa0(BasicString_0x1c* first, BasicString_0x1c* last)
{
  for (; first != last; first = reinterpret_cast<BasicString_0x1c*>(
           reinterpret_cast<uint8_t*>(first) + 0x1c)) {
    basic_string_dtor(first);
  }
}
